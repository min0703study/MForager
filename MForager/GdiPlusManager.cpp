#include "Stdafx.h"
#include "GdiPlusManager.h"

void GdiPlusManager::init(HDC hdc)
{
	_graphics = new Graphics(hdc);
}


Image* GdiPlusManager::addImage(int intKey, const string fileName, int width, int height, bool isTranse)
{
	Gdiplus::Image* img = findImage(intKey);
	if (img) return img;

	img = new Gdiplus::Image(wstring(fileName.begin(), fileName.end()).c_str());
	/*
	if (FAILED(img->initFile(fileName, width, height, isTranse)))
	{
		SAFE_DELETE(img);
		return NULL;
	}
	*/
	_mImageList.insert(make_pair(intKey, img));
}

Image* GdiPlusManager::findImage(int intKey)
{
	auto key = _mImageList.find(intKey);
	if (key != _mImageList.end())
	{
		return key->second;
	}

	return nullptr;
}

Image * GdiPlusManager::rotate(int intKey, PointF centerPt, int angle)
{
	Gdiplus::Image* img = findImage(intKey);
	if (SAFE_NULL_CHECK(img)) return img;

	//_graphics->TranslateTransform(100.0f, 100.0f);
	//Gdiplus::Matrix* mx = new Gdiplus::Matrix(1.0f, 0.0f, 0.0f, 1.0f, 50, 50);
	_graphics->DrawImage(img, centerPt.X , centerPt.Y, 100.0f, 100.0f);
	Gdiplus::Matrix* mx = new Gdiplus::Matrix();
	mx->RotateAt(angle, centerPt);
	_graphics->SetTransform(mx);
	//mx->TransformPoints({0,0});
	return nullptr;
}

void GdiPlusManager::release()
{
	delete _graphics;
}
