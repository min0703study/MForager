#pragma once
#include "SingletonBase.h"

class GdiPlusManager: public SingletonBase<GdiPlusManager>
{
private:
	typedef map<int, Image*> mapImageList;
	typedef map<int, Image*>::iterator mapImageIter;

	//Graphics* _graphics;
	mapImageList _mImageList;

	FontFamily*  fontFamily;
	StringFormat centerFormat;

public:
	void init(HDC hdc);
	Image* addImage(int intKey, const string fileName, bool isTranse = true);
	void flipeX(int intKey);
	Image * findImage(int intKey);

	void render(HDC hdc, int intKey, RectF rcf);

	void render(HDC hdc, int intKey, UIPOS * uiPos);
	void render(HDC hdc, int intKey, PointF pt, SizeF sizeF);

	Image * rotate(HDC hdc, int intKey, RectF rcf, int angle, bool isRight);
	Image * rotate(int intKey, UIPOS * uiPos, int angle);
	void release();
	void drawTextCenter(HDC hdc, std::wstring message, RectF baseRc, int size, Color color);
	void drawTextCenter(HDC hdc, std::wstring message, RECT baseRc, int size, Color color);
	void drawText(HDC hdc, std::wstring message, PointF ptF, int size, Color color);

	void DrawRectangle(HDC hdc, int x, int y, int width, int height);
	void DrawRectangle(HDC hdc, PointF pt, int width, int height);
};

