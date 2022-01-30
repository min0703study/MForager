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
			hdc,			//�̹��� ����� ��ġ�� 
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
			hdc,			//�̹��� ����� ��ġ�� �ڵ�
			startX,			//�̹����� ����� ��ġ
			startY,			//�̹����� ����� ��ġ
			cutSizeX,		//���� �̹��� ����
			cutSizeY,		//���� �̹��� ����
			hMemDC,			//�̹��� �ڵ�
			renderX,		//������ �̹��� ���� ��ġ
			renderY,		//������ �̹��� ���� ��ġ
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
			img->_frameWidth, //�߶� ��Ʈ�� ���ο����� ��ǥ 
			img->_frameHeight, //�߶� ��Ʈ�� ���ο����� ��ǥ
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

	//�׷����� ���� ����
	RECT rcSour;

	int sourWidth;
	int sourHeight;

	//�׷����� DC ���� (ȭ�� ũ��)
	RECT rcDest;

	//�׷��� �� ��ü ����
	int drawAreaX = drawArea->left;
	int drawAreaY = drawArea->top;
	int drawAreaW = drawArea->right - drawArea->left;
	int drawAreaH = drawArea->bottom - drawArea->top;

	//���� ���� ����
	for (int y = 0; y < drawAreaH; y += sourHeight)
	{
		//�ҽ� ������ ���� ���
		rcSour.top = (y + offsetY) % img->_height;
		rcSour.bottom = img->_height;
		sourHeight = rcSour.bottom - rcSour.top;

		//�ҽ� ������ �׸��� ȭ���� �Ѿ�ٸ� (ȭ������� ������ ��)
		if (y + sourHeight > drawAreaH)
		{
			//�Ѿ �׸��� ����ŭ �÷��ְڴ�.
			rcSour.bottom -= (y + sourHeight) - drawAreaH;
			sourHeight = rcSour.bottom - rcSour.top;
		}

		// �׷����� ����
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

