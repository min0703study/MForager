#pragma once
#include "FrameImage.h"
#include "AlphaImage.h"
#include "Renderer.h"
#include "SingletonBase.h"

class ImageManager : public SingletonBase<ImageManager>
{
private:
	typedef map<int, ImageBase*> mapImageList;
	typedef map<int, ImageBase*>::iterator mapImageIter;
private:
	mapImageList _mImageList;
	Renderer* _renderer;
	ImageBase* findImage(int strKey);
public:
	HRESULT init(void);
	void release(void);

	//이미지 등록
	ImageBase* addImage(int key, int width, int height);
	ImageBase* addFileImage(int key, const char * fileName, int width, int height, bool isTranse = false);
	ImageBase* addFrameImage(int key, const char * fileName, int width, int height, int frameXCount, int frameYCount, bool isTranse = true);
	ImageBase* addAlphaImage(int key, const char * fileName, int width, int height);

	void addtImage(int key, int width, int height);
	void addtFileImage(int key, const char * fileName, int width, int height, bool isTranse = false);
	void addtFrameImage(int key, const char * fileName, int width, int height, int frameXCount, int frameYCount, bool isTranse = true);
	void addtAlphaImage(int key, const char * fileName, int width, int height);

	//이미지 로드
	void loadImage(HDC hdc);

	void frameRender(int key, HDC hdc, PointF position);
	void alphaRender(int key, HDC hdc, BYTE alpha);

	void nextFrame(int key);
	void setCurrentFrame(int intKey, int x, int y);

	IMAGE_TYPE getType(int intKey);

	bool deleteImage(int key);
	bool deleteAll();

	void render(int key, HDC hdc, PointF position);
	void render(int key, HDC hdc, int destX, int destY, bool isCenter);
	void alphaRender(int key, HDC hdc, PointF pt, BYTE alpha, bool isCenterPt);
	void render(int key, HDC hdc, int destX = 0, int destY = 0, bool isCenter = false);

	ImageManager();
	~ImageManager();
};

