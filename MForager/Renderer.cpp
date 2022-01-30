#include "Stdafx.h"
#include "Renderer.h"

void Renderer::render(HDC& hdc,
	HDC& hMemDC,
	int startX,
	int startY,
	int cutSizeX,
	int cutSizeY,
	int renderX,
	int renderY,
	int renderSizeX,
	int renderSizeY,
	bool isTrans) {
	if (isTrans)
	{
		GdiTransparentBlt(
			hdc,			//이미지 출력할 위치의 
			startX,
			startY,
			cutSizeX,
			cutSizeY,
			hMemDC,
			renderX,
			renderY,
			renderSizeX,
			renderSizeY,
			TRANCE_COLOR);
	}
	else {
		BitBlt(
			hdc,			//이미지 출력할 위치의 핸들
			startX,			//이미지를 출력할 위치
			startY,			//이미지를 출력할 위치
			cutSizeX,		//원본 이미지 넓이
			cutSizeY,		//원본 이미지 높이
			hMemDC,			//이미지 핸들
			renderX,		//가져올 이미지 시작 위치
			renderY,		//가져올 이미지 시작 위치
			SRCCOPY);
	}
}

void Renderer::renderPtf(HDC hdc, ImageBase* img, POINTF pt, bool ptIsCenter)
{
	if (ptIsCenter) {
		pt.x = pt.x - img->_width / 2;
		pt.y = pt.y - img->_height / 2;
	}

	if (img->_isTrans)
	{
		GdiTransparentBlt(hdc, 
			pt.x, 
			pt.y, 
			img->_width, 
			img->_height, 
			img->_hMemDC, 
			0, 0,
			img->_width,
			img->_height,
			img->_transColor);
	}
	else {
		BitBlt(hdc, pt.x, pt.y, img->_width, img->_height, img->_hMemDC, 0, 0, SRCCOPY);
	}

}

void Renderer::renderPt(HDC hdc, ImageBase * img, POINT pt, bool ptIsCenter)
{
	this->renderPtf(hdc, img, pt, ptIsCenter);
}

void Renderer::renderFrame(HDC hdc, FrameImage* img, POINTF pt)
{
	if (img->_isTrans)
	{
		GdiTransparentBlt(hdc,
			pt.x, pt.y,
			img->_frameWidth,
			img->_frameHeight,
			img->_hMemDC,
			img->_frameWidth * img->_currentFrameX,
			img->_frameHeight * img->_currentFrameY,
			img->_frameWidth, //잘라낼 비트맵 내부에서의 좌표 
			img->_frameHeight, //잘라낼 비트맵 내부에서의 좌표
			img->_transColor);
	}
	else {
		BitBlt(hdc,
			pt.x, pt.y,
			img->_frameWidth,
			img->_frameHeight,
			img->_hMemDC,
			img->_frameWidth * img->_currentFrameX,
			img->_frameHeight * img->_currentFrameY,
			SRCCOPY);
	}
}

void Renderer::renderLoop(HDC hdc, ImageBase* img, const LPRECT drawArea, int offsetX, int offsetY)
{
	if (offsetX < 0) offsetX = img->_width + (offsetX % img->_width);
	if (offsetY < 0) offsetY = img->_height + (offsetY % img->_height);

	//그려지는 영역 셋팅
	RECT rcSour;

	int sourWidth;
	int sourHeight;

	//그려지는 DC 영역 (화면 크기)
	RECT rcDest;

	//그려야 할 전체 영역
	int drawAreaX = drawArea->left;
	int drawAreaY = drawArea->top;
	int drawAreaW = drawArea->right - drawArea->left;
	int drawAreaH = drawArea->bottom - drawArea->top;

	//세로 루프 영역
	for (int y = 0; y < drawAreaH; y += sourHeight)
	{
		//소스 영역의 높이 계산
		rcSour.top = (y + offsetY) % img->_height;
		rcSour.bottom = img->_height;
		sourHeight = rcSour.bottom - rcSour.top;

		//소스 영역이 그리는 화면을 넘어갔다면 (화면밖으로 나갔을 때)
		if (y + sourHeight > drawAreaH)
		{
			//넘어간 그림의 값만큼 올려주겠다.
			rcSour.bottom -= (y + sourHeight) - drawAreaH;
			sourHeight = rcSour.bottom - rcSour.top;
		}

		// 그려지는 영역
		rcDest.top = y + drawAreaY;
		rcDest.bottom = rcDest.top + sourHeight;

		for (int x = 0; x < drawAreaW; x += sourWidth) {
			rcSour.left = (x + offsetX) % img->_width;
			rcSour.right = img->_width;
			sourWidth = rcSour.right - rcSour.left;

			if (x + sourWidth > drawAreaW) {
				rcSour.right -= (x + sourWidth) - drawAreaW;
				sourWidth = rcSour.right - rcSour.left;
			}

			rcDest.left = x + drawAreaX;
			rcDest.right = rcDest.left + sourWidth;

			render(hdc, img->_hMemDC, rcDest.left, rcDest.top, sourWidth, sourHeight, rcSour.left, rcSour.top, sourWidth, sourHeight, false);
		}
	}
}


void Renderer::renderAlpha(HDC hdc, AlphaImage* img, POINTF pt, BYTE alpha)
{
	img->_blendFunc.SourceConstantAlpha = alpha;
	
	AlphaBlend(
		hdc,
		pt.x, pt.y,
		img->_width,
		img->_height,
		img->_hMemDC,
		0, 0,
		img->_width,
		img->_height,
		img->_blendFunc
	);
}

void Renderer::renderAlpha(HDC hdc, AlphaImage * img, BYTE alpha)
{
	renderAlpha(hdc, img, { 0,0 }, alpha);
}

