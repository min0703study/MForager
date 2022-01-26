#pragma once
#include "FrameImage.h"
#include "Renderer.h"
#include "SingletonBase.h"

class ImageManager : public SingletonBase<ImageManager>
{
private:
	typedef map<string, Image*> mapImageList;
	typedef map<string, Image*>::iterator mapImageIter;
private:
	mapImageList _mImageList;
	Renderer* _renderer;
public:
	HRESULT init(void);
	void release(void);

	Image* findImage(string strKey);

	Image* addImage(string strKey, int width, int height, bool isTranse = false);
	Image* addFileImage(string strKey, const char * fileName, int width, int height, bool isTranse = false);
	Image* addFrameImage(string strKey, const char * fileName, int width, int height, int frameXCount, int frameYCount, bool isTranse = true);
	Image* addAlphaImage(string strKey, const char * fileName, int width, int height);

	void frameRender(string strKey, HDC hdc, POINTF position);
	void frameRender(string strKey, HDC hdc, POINT position);
	void loopRender(string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY);
	void alphaRender(string strKey, HDC hdc, BYTE alpha);
	
	void nextFrame(string strKey);
	void setCurrentFrame(string strKey, int x, int y);

	bool deleteImage(string strKey);
	bool deleteAll();

	void render(string strKey, HDC hdc, int destX = 0, int destY = 0, bool isCenter = false);

	ImageManager();
	~ImageManager();
};

