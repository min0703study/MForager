#pragma once
#include "FrameImage.h"
#include "AlphaImage.h"
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
	Image* findImage(string strKey);
public:
	HRESULT init(void);
	void release(void);

	Image * addImage(int strKey, int width, int height);
	Image * addImage(string strKey, int width, int height);


	Image* addFileImage(string strKey, const char * fileName, int width, int height, bool isTranse = false);
	Image* addFileImage(int intKey, const char * fileName, int width, int height, bool isTranse = false);
	Image* addFrameImage(string strKey, const char * fileName, int width, int height, int frameXCount, int frameYCount, bool isTranse = true);
	Image* addFrameImage(int intKey, const char * fileName, int width, int height, int frameXCount, int frameYCount, bool isTranse = true);
	Image* addAlphaImage(string strKey, const char * fileName, int width, int height);
	Image* addAlphaImage(int intKey, const char * fileName, int width, int height);

	void frameRender(string strKey, HDC hdc, POINTF position);
	void frameRender(string strKey, HDC hdc, POINT position);
	void loopRender(string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY);
	void alphaRender(string strKey, HDC hdc, BYTE alpha);
	void alphaRender(string strKey,HDC hdc, POINTF pt, BYTE alpha);

	void frameRender(int intKey, HDC hdc, POINTF position) { return frameRender(to_string(intKey), hdc, position); };
	void frameRender(int intKey, HDC hdc, POINT position) { return frameRender(to_string(intKey), hdc, position); };
	void alphaRender(int intKey, HDC hdc, BYTE alpha) { return alphaRender(to_string(intKey), hdc, alpha); };
	void alphaRender(int intKey, HDC hdc, POINTF pt, BYTE alpha) { return alphaRender(to_string(intKey), hdc,pt, alpha); };
	
	void nextFrame(string strKey);
	void nextFrame(int intKey) { nextFrame(to_string(intKey)); };
	void setCurrentFrame(string strKey, int x, int y);
	void setCurrentFrame(int intKey, int x, int y) { setCurrentFrame(to_string(intKey), x, y); };;

	IMAGE_TYPE getType(string strKey);
	IMAGE_TYPE getType(int intKey) { getType(to_string(intKey)); };;

	bool deleteImage(string strKey);
	bool deleteAll();

	void render(string strKey, HDC hdc, POINTF position);

	void render(string strKey, HDC hdc, int destX = 0, int destY = 0, bool isCenter = false);

	ImageManager();
	~ImageManager();
};

