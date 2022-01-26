#include "Stdafx.h"
#include "ImageManager.h"

ImageManager::ImageManager()
{}

ImageManager::~ImageManager()
{}

HRESULT ImageManager::init(void)
{
	_renderer = new Renderer;
	return S_OK;
}

void ImageManager::release(void)
{
	this->deleteAll();
}


Image* ImageManager::addImage(string strKey, int width, int height, bool isTranse)
{
	Image* img = findImage(strKey);

	if (img) return img;

	img = new Image;

	if (FAILED(img->init(width, height)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	_mImageList.insert(make_pair(strKey, img));

	return img;
}

Image * ImageManager::addFileImage(string strKey, const char * fileName, int width, int height, bool isTranse)
{
	Image* img = findImage(strKey);

	if (img) return img;

	img = new Image;

	if (FAILED(img->initFile(fileName, width, height, isTranse)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	_mImageList.insert(make_pair(strKey, img));

	return img;
}

Image* ImageManager::addFrameImage(string strKey, const char * fileName, int width, int height, int frameXCount, int frameYCount, bool isTranse)
{
	FrameImage* img = (FrameImage*)findImage(strKey);

	if (img) return img;

	img = new FrameImage;

	if (FAILED(img->initFile(fileName, width, height, frameXCount, frameYCount, isTranse)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	_mImageList.insert(make_pair(strKey, img));

	return img;
}

/*
Image* ImageManager::addAlphaImage(string strKey, const char * fileName, int width, int height)
{
	AlphaImage* img = (AlphaImage*)findImage(strKey);

	if (img) return img;

	img = new AlphaImage;

	if (FAILED(img->init(fileName, width, height, false)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	_mImageList.insert(make_pair(strKey, img));

	return img;
}
*/
Image* ImageManager::findImage(string strKey)
{
	auto key = _mImageList.find(strKey);
	if (key != _mImageList.end())
	{
		return key->second;
	}

	return nullptr;
}

bool ImageManager::deleteImage(string strKey)
{
	auto key = _mImageList.find(strKey);

	if (key != _mImageList.end())
	{
		key->second->release();
		SAFE_DELETE(key->second);
		_mImageList.erase(key);

		return true;
	}
	return false;
}

bool ImageManager::deleteAll()
{
	auto iter = _mImageList.begin();
	for (; iter != _mImageList.end();)
	{
		if (iter->second != NULL)
		{
			iter->second->release();
			SAFE_DELETE(iter->second);
			iter = _mImageList.erase(iter);
		}
		else {
			++iter;
		}
	}
	_mImageList.clear();
	return true;
}

void ImageManager::render(string strKey, HDC hdc, int destX, int destY, bool isCenter)
{
	Image* img = findImage(strKey);
	if (img)  _renderer->renderPt(hdc, img, { destX, destY }, isCenter);
}


void ImageManager::frameRender(string strKey, HDC hdc, POINTF position)
{
	FrameImage* img = (FrameImage*)findImage(strKey);
	if (img) _renderer->renderFrame(hdc, img, position);
}

void ImageManager::frameRender(string strKey, HDC hdc, POINT position)
{
	this->frameRender(strKey, hdc, POINTF(position));
}

void ImageManager::nextFrame(string strKey)
{
	FrameImage* img = (FrameImage*)findImage(strKey);
	if (img) img->nextFrame();
}

void ImageManager::setCurrentFrame(string strKey, int x, int y)
{
	FrameImage* img = (FrameImage*)findImage(strKey);
	if (img) img->setCurrentFrame(x, y);
}

void ImageManager::loopRender(string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY)
{
	Image* img = findImage(strKey);
	if (img) _renderer->renderLoop(hdc, img, drawArea, offsetX, offsetY);
}

/*
void ImageManager::alphaRender(string strKey, HDC hdc, BYTE alpha)
{
	AlphaImage* img = (AlphaImage*)findImage(strKey);
	if (img) _renderer->renderAlpha(hdc, img, alpha);
}
*/