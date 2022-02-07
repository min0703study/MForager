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

ImageBase * ImageManager::addFileImage(int key, const char * fileName, int width, int height, bool isTranse)
{
	ImageBase* img = findImage(key);
	if (img) return img;

	img = new ImageBase;

	if (FAILED(img->initFile(fileName, width, height, isTranse)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	_mImageList.insert(make_pair(key, img));

	return img;
}

ImageBase* ImageManager::addFrameImage(int key, const char * fileName, int width, int height, int frameXCount, int frameYCount, bool isTranse)
{
	FrameImage* img = (FrameImage*)findImage(key);
	if (img) return img;

	img = new FrameImage;
	if (FAILED(img->initFile(fileName, width, height, frameXCount, frameYCount, isTranse)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	_mImageList.insert(make_pair(key, img));

	return img;
}


ImageBase* ImageManager::addAlphaImage(int key, const char * fileName, int width, int height)
{
	AlphaImage* img = (AlphaImage*)findImage(key);
	if (img) return img;

	img = new AlphaImage;

	if (FAILED(img->init(fileName, width, height, false)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	_mImageList.insert(make_pair(key, img));

	return img;
}

void ImageManager::addtImage(int key, int width, int height)
{
	ImageBase* img = findImage(key);
	if (img) return ;

	img = new ImageBase;
	img->_imageInfo = new IMAGE_INFO(width, height);
	img->_isLoadSuccess = false;
}

void ImageManager::addtFileImage(int key, const char * fileName, int width, int height, bool isTranse)
{
	ImageBase* img = findImage(key);
	if (img) return;

	img = new ImageBase;
	img->_isLoadSuccess = false;
}

void ImageManager::addtFrameImage(int key, const char * fileName, int width, int height, int frameXCount, int frameYCount, bool isTranse)
{
}

void ImageManager::addtAlphaImage(int key, const char * fileName, int width, int height)
{
}


void ImageManager::loadImage(HDC hdc)
{
	for (mapImageIter iter = _mImageList.begin(); iter != _mImageList.end();)
	{
		switch (iter->second->_type)
		{
		case FRAME:
			break;
		case NORMAL_FILE;
		default:
			break;
		}
	}
}

ImageBase* ImageManager::addImage(int intKey, int width, int height)
{
	{
		ImageBase* img = findImage(intKey);
		if (SAFE_NULL_CHECK(img)) return img;

		img = new ImageBase;
		if (FAILED(img->init(width, height)))
		{
			SAFE_DELETE(img);
			return NULL;
		}

		_mImageList.insert(make_pair(intKey, img));
		return img;
	}
}

ImageBase* ImageManager::findImage(int key)
{
	auto findImage = _mImageList.find(key);

	if (findImage != _mImageList.end()) 
		return findImage->second;

	return nullptr;
}

bool ImageManager::deleteImage(int key)
{
	auto findImage = _mImageList.find(key);

	if (findImage != _mImageList.end())
	{
		findImage->second->release();
		SAFE_DELETE(findImage->second);
		_mImageList.erase(key);

		return true;
	}
	return false;
}

bool ImageManager::deleteAll()
{
	auto iter = _mImageList.begin();
	for (iter = _mImageList.begin(); iter != _mImageList.end();)
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

void ImageManager::render(int key, HDC hdc, PointF position)
{

	ImageBase* img = findImage(key);

	if (img) {
		switch (img->_type)
		{
		case FRAME:
			_renderer->renderFrame(hdc, (FrameImage*)img, {position.X, position.Y});
			break;
		case NORMAL_FILE:
			_renderer->renderPtf(hdc, img, { position.X, position.Y });
			break;
		}
	}
}

void ImageManager::render(int key, HDC hdc, int destX, int destY, bool isCenter)
{
	ImageBase* img = findImage(key);
	if (img)  _renderer->renderPt(hdc, img, { destX, destY }, isCenter);
}

void ImageManager::alphaRender(int key, HDC hdc, PointF pt, BYTE alpha, bool isCenterPt)
{
	AlphaImage* img = (AlphaImage*)findImage(key);

	if (img) {
		if (isCenterPt) {
			pt.X = pt.X - img->_width / 2;
			pt.X = pt.X - img->_height / 2;
		}
		_renderer->renderAlpha(hdc, img, { pt.X, pt.Y }, alpha);
	}
}

void ImageManager::nextFrame(int key)
{
	FrameImage* img = (FrameImage*)findImage(key);
	if (img) img->nextFrame();
}

void ImageManager::setCurrentFrame(int key, int x, int y)
{
	FrameImage* img = (FrameImage*)findImage(key);
	if (img) img->setCurrentFrame(x, y);
}

IMAGE_TYPE ImageManager::getType(int key)
{
	ImageBase* img = findImage(key);
	if (img) {
		return img->_type;
	}
	return ERR;
}


void ImageManager::alphaRender(int key, HDC hdc, BYTE alpha)
{
	AlphaImage* img = (AlphaImage*)findImage(key);
	if (img) _renderer->renderAlpha(hdc, img, alpha);
}
