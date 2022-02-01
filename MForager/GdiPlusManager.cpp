#include "Stdafx.h"
#include "GdiPlusManager.h"

void GdiPlusManager::init(HDC hdc)
{
	_graphics = new Graphics(hdc);
}

Image* GdiPlusManager::addImage(int intKey, const string fileName, bool isTranse)
{
	Gdiplus::Image* img = findImage(intKey);
	if (img) return img;

	img = new Gdiplus::Image(wstring(fileName.begin(), fileName.end()).c_str());

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

void GdiPlusManager::render(int intKey, UIPOS* uiPos)
{
	Gdiplus::Image* img = findImage(intKey);
	if (!img) return ;

	ImageAttributes imageAtt;

	imageAtt.SetColorKey(
		Color(255, 0, 255),
		Color(255, 0, 255),
		ColorAdjustTypeDefault
	);

	_graphics->DrawImage(img, 
		uiPos->getRectF(), 
		(INT)uiPos->_pt->X, (INT)uiPos->_pt->Y, uiPos->_width, uiPos->_height,
		UnitPixel,
		&imageAtt);
}


Image * GdiPlusManager::rotate(int intKey, UIPOS* uiPos, int angle)
{
	Gdiplus::Image* img = findImage(intKey);
	if (SAFE_NULL_CHECK(img)) return img;;

	ImageAttributes imageAtt;

	imageAtt.SetColorKey(
		Color(255, 0, 255),
		Color(255, 0, 255),
		ColorAdjustTypeDefault
	);
	Gdiplus::RectF rc = *uiPos->getRectF().Clone();
	rc.X -= 17;
	rc.Y += 10;
	_graphics->DrawImage(img,
		rc,
		0, 0, 79, 79,
		UnitPixel,
		&imageAtt);

	Gdiplus::Matrix matrix;
	matrix.RotateAt(angle, {rc.GetRight(),rc.GetBottom() });
	_graphics->SetTransform(&matrix);
	
	return nullptr;
}

void GdiPlusManager::release()
{
	delete _graphics;
}
