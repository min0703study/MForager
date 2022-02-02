#include "Stdafx.h"
#include "GdiPlusManager.h"

void GdiPlusManager::init(HDC hdc)
{
	fontFamily = new FontFamily(L"Leferi Base Type Bold");
	//_graphics = new Graphics(hdc);
	centerFormat.SetAlignment(StringAlignmentCenter);
}

Image* GdiPlusManager::addImage(int intKey, const string fileName, bool isTranse)
{
	Gdiplus::Image* img = findImage(intKey);
	if (img) return img;

	img = new Gdiplus::Image(wstring(fileName.begin(), fileName.end()).c_str());
	_mImageList.insert(make_pair(intKey, img));
}


void GdiPlusManager::flipeX(int intKey)
{
	Gdiplus::Image* img = findImage(intKey);
	if (!img) return;
	img->RotateFlip(RotateNoneFlipX);
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
void GdiPlusManager::render(HDC hdc, int intKey, RectF rcf)
{
	Gdiplus::Image* img = findImage(intKey);
	if (!img) return;
	Graphics gh(hdc);
	ImageAttributes imageAtt;

	imageAtt.SetColorKey(
		Color(255, 0, 255),
		Color(255, 0, 255),
		ColorAdjustTypeDefault
	);

	gh.DrawImage(img,
		rcf,
		0, 0, img->GetWidth(), img->GetHeight(),
		UnitPixel,
		&imageAtt);
}
void GdiPlusManager::render(HDC hdc, int intKey, UIPOS* uiPos)
{
	Gdiplus::Image* img = findImage(intKey);
	if (!img) return ;
	Graphics gh(hdc);
	ImageAttributes imageAtt;

	imageAtt.SetColorKey(
		Color(255, 0, 255),
		Color(255, 0, 255),
		ColorAdjustTypeDefault
	);

	
	gh.DrawImage(img,
		uiPos->getRectF(), 
		0, 0, img->GetWidth(), img->GetHeight(),
		UnitPixel,
		&imageAtt);
}

void GdiPlusManager::render(HDC hdc, int intKey, PointF pt, SizeF sizeF)
{
	Gdiplus::Image* img = findImage(intKey);
	if (!img) return;
	Graphics gh(hdc);
	ImageAttributes imageAtt;

	imageAtt.SetColorKey(
		Color(255, 0, 255),
		Color(255, 0, 255),
		ColorAdjustTypeDefault
	);

	
	gh.DrawImage(img,
		RectF(pt, sizeF),
		0, 0, img->GetWidth(), img->GetHeight(),
		UnitPixel,
		&imageAtt);
}
Image * GdiPlusManager::rotate(HDC hdc, int intKey, RectF rcf, int angle, bool isRight)
{
	Gdiplus::Image* img = findImage(intKey);
	if (SAFE_NULL_CHECK(img)) return img;;

	Graphics gh(hdc);
	ImageAttributes imageAtt;

	imageAtt.SetColorKey(
		Color(255, 0, 255),
		Color(255, 0, 255),
		ColorAdjustTypeDefault
	);



	Gdiplus::Matrix matrix;
	if (isRight) {
		matrix.RotateAt(angle, { rcf.GetRight(),rcf.GetBottom() });
	}
	else {
		matrix.RotateAt(-angle, { rcf.GetLeft(),rcf.GetBottom() });
	}
	
	gh.SetTransform(&matrix);
	gh.DrawImage(img,
		rcf,
		0, 0, img->GetWidth(), img->GetHeight(),
		UnitPixel,
		&imageAtt);
	return nullptr;
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
	/*
	_graphics-d>DrawImage(img,
		rc,
		0, 0, img->GetWidth(), img->GetHeight(),
		UnitPixel,
		&imageAtt);

		*/
	Gdiplus::Matrix matrix;
	//matrix.RotateAt(-angle, {rc.GetRight(),rc.GetBottom() });
	//matrix.Invert();
	/*
	_graphics->SetTransform(&matrix);
	*/
	return nullptr;
}

void GdiPlusManager::release()
{
	//delete _graphics;
}

void GdiPlusManager::drawTextCenter(HDC hdc, std::wstring message, RectF baseRc, int size, Color color)
{
	Graphics gh(hdc);
	Font        font(fontFamily, size, FontStyleRegular, UnitPixel);
	SolidBrush  solidBrush(color);
	gh.DrawString(message.c_str() , -1, &font, baseRc, &centerFormat, &solidBrush);
}

void GdiPlusManager::drawTextCenter(HDC hdc, std::wstring message, RECT baseRc, int size, Color color)
{
	Graphics gh(hdc);
	Font        font(fontFamily, size, FontStyleRegular, UnitPixel);
	SolidBrush  solidBrush(color);
	gh.DrawString(message.c_str(), -1, &font, RectF((REAL) baseRc .left, (REAL)baseRc.top,(REAL)baseRc .right - baseRc.left, (REAL)baseRc.bottom - baseRc.top), &centerFormat, &solidBrush);
}


void GdiPlusManager::drawText(HDC hdc, std::wstring message, PointF ptF, int size, Color color)
{
	Graphics gh(hdc);
	Font        font(fontFamily, size, FontStyleRegular, UnitPixel);
	SolidBrush  solidBrush(color);
	gh.DrawString(message.c_str(), -1, &font, ptF, &solidBrush);
}

void GdiPlusManager::DrawRectangle(HDC hdc, int x, int y, int width, int height)
{
	Graphics gh(hdc);
	Color C2(70, 0, 0, 0);
	SolidBrush B2(C2);
	gh.FillRectangle(&B2, x, y, width, height);
}


void GdiPlusManager::DrawRectangle(HDC hdc, PointF pt, int width, int height)
{
	Graphics gh(hdc);
	Color C2(70, 0, 0, 0);
	SolidBrush B2(C2);
	gh.FillRectangle(&B2, (INT)pt.X, (INT)pt.Y, (INT)width, (INT)height);
}
