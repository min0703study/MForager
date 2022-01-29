#pragma once

class Renderer
{
private:
	void render(HDC& hdc,
		HDC& hMemDC,
		int startX,
		int startY,
		int cutSizeX,
		int cutSizeY,
		int rederX,
		int renderY,
		int renderSizeX,
		int renderSizeY,
		bool isTrans);
public:
	void renderPtf(HDC hdc, Image* img, POINTF pt, bool ptIsCenter = false);
	void renderPt(HDC hdc, Image* img, POINT pt, bool ptIsCenter = false);
	void renderLoop(HDC hdc, Image* img, const LPRECT drawArea, int offsetX, int offsetY);
	void renderAlpha(HDC hdc, AlphaImage * img, POINTF pt, BYTE alpha);
	void renderAlpha(HDC hdc, AlphaImage * img, BYTE alpha);
	void renderFrame(HDC hdc, FrameImage* fImg, POINTF pt);
};

