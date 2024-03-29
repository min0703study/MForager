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

ImageBase * ImageManager::addFileImage(int intKey, const char * fileName, int width, int height, bool isTranse)
{
	return addFileImage(to_string(intKey), fileName, width, height, isTranse);
}

ImageBase * ImageManager::addFileImage(string strKey, const char * fileName, int width, int height, bool isTranse)
{
	ImageBase* img = findImage(strKey);

	if (img) return img;

	img = new ImageBase;

	if (FAILED(img->initFile(fileName, width, height, isTranse)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	_mImageList.insert(make_pair(strKey, img));

	return img;
}

ImageBase* ImageManager::addFrameImage(string strKey, const char * fileName, int width, int height, int frameXCount, int frameYCount, bool isTranse)
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

ImageBase * ImageManager::addFrameImage(int intKey, const char * fileName, int width, int height, int frameXCount, int frameYCount, bool isTranse)
{
	return addFrameImage(to_string(intKey), fileName, width, height, frameXCount, frameYCount, isTranse);
}


ImageBase* ImageManager::addAlphaImage(string strKey, const char * fileName, int width, int height)
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

ImageBase * ImageManager::addAlphaImage(int intKey, const char * fileName, int width, int height)
{
	return addAlphaImage(to_string(intKey), fileName, width, height);
}

ImageBase * ImageManager::addImage(string strKey, int width, int height)
{
	{
		ImageBase* img = findImage(strKey);

		if (img) return img;

		img = new ImageBase;

		if (FAILED(img->init(width, height)))
		{
			SAFE_DELETE(img);
			return NULL;
		}

		_mImageList.insert(make_pair(strKey, img));

		return img;
	}
}

ImageBase* ImageManager::findImage(string strKey)
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

void ImageManager::render(string strKey, HDC hdc, POINTF position)
{
	
	ImageBase* img = findImage(strKey);
	if (img) {
		switch (img->_type)
		{
			case FRAME:
				_renderer->renderFrame(hdc, (FrameImage*)img, position);
				break;
			case DEFAULT:
				_renderer->renderPtf(hdc, img, position);
				break;
		}
	}
}


void ImageManager::render(string strKey, HDC hdc, PointF position)
{

	ImageBase* img = findImage(strKey);
	if (img) {
		switch (img->_type)
		{
		case FRAME:
			_renderer->renderFrame(hdc, (FrameImage*)img, {position.X, position.Y});
			break;
		case DEFAULT:
			_renderer->renderPtf(hdc, img, { position.X, position.Y });
			break;
		}
	}
}


void ImageManager::render(string strKey, HDC hdc, int destX, int destY, bool isCenter)
{
	ImageBase* img = findImage(strKey);
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

void ImageManager::alphaRender(string strKey, HDC hdc, PointF pt, BYTE alpha, bool isCenterPt)
{
	AlphaImage* img = (AlphaImage*)findImage(strKey);

	if (img) {
		if (isCenterPt) {
			pt.X = pt.X - img->_width / 2;
			pt.X = pt.X - img->_height / 2;
		}
		_renderer->renderAlpha(hdc, img, { pt.X, pt.Y }, alpha);
	}
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

IMAGE_TYPE ImageManager::getType(string strKey)
{
	ImageBase* img = findImage(strKey);
	if (img) {
		return img->_type;
	}
	return ERR;
}

void ImageManager::loopRender(string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY)
{
	ImageBase* img = findImage(strKey);
	if (img) _renderer->renderLoop(hdc, img, drawArea, offsetX, offsetY);
}


void ImageManager::alphaRender(string strKey, HDC hdc, BYTE alpha)
{
	AlphaImage* img = (AlphaImage*)findImage(strKey);
	if (img) _renderer->renderAlpha(hdc, img, alpha);
}

void ImageManager::alphaRender(string strKey, HDC hdc, POINTF pt, BYTE alpha)
{
	AlphaImage* img = (AlphaImage*)findImage(strKey);
	if (img) _renderer->renderAlpha(hdc, img, pt, alpha);
}

