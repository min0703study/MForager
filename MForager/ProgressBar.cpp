#include "Stdafx.h"
#include "ProgressBar.h"

ProgressBar::ProgressBar(PointF absPt, float bgWidth, float bgHeight, int maxValue, int currentValue, COLORREF top, COLORREF bottom)
	:UI(absPt, bgWidth, bgHeight, nullptr)
	, _bgWidth(bgWidth)
	, _bgHeight(bgHeight)
	, _maxValue(maxValue)
	, _currentValue(currentValue)
	, _topColor(top)
	, _bottomColor(bottom)
{
	int valueHeight = bgHeight / 2.0f;
	_valueRect[0] = new SRECT(+5, +5, -5, -valueHeight);
	_valueRect[1] = new SRECT(+5, +valueHeight, -5, -5);
}

ProgressBar::~ProgressBar()
{
}

void ProgressBar::setValue(int maxValue, int value)
{
	if (_maxValue != maxValue) {
		_maxValue = maxValue;
	}
}


void ProgressBar::setValue(int value)
{
	if (_currentValue != value) {
		_currentValue = value;
	}
}

void ProgressBar::play(HDC hdc) {
	HBRUSH hBBrush = CreateSolidBrush(BLACK);
	RECT bgRc = getRRc();

	RectangleMake(hdc, bgRc);
	FillRect(hdc, &bgRc, hBBrush);
	DeleteObject(hBBrush);

	HBRUSH hWBrush = CreateSolidBrush(WHITE);
	FrameRect(hdc, &bgRc, hWBrush);
	DeleteObject(hWBrush);

	HBRUSH hTBrush = CreateSolidBrush(_topColor);
	RECT value1 = _valueRect[0]->getRect(getRRc());
	value1.right = value1.left + _valueRect[0]->getWidth(getRRc()) * (_currentValue / _maxValue);
	RectangleMake(hdc, value1);
	FillRect(hdc, &value1, hTBrush);
	DeleteObject(hTBrush);

	HBRUSH hBtBrush = CreateSolidBrush(_bottomColor);
	RECT value2 = _valueRect[1]->getRect(getRRc());
	value2.right = value2.left + _valueRect[1]->getWidth(getRRc()) * (_currentValue / _maxValue);
	RectangleMake(hdc, value2);
	FillRect(hdc, &value2, hBtBrush);
	DeleteObject(hBtBrush);
}

void ProgressBar::playFixed(HDC hdc) {
	HBRUSH hBBrush = CreateSolidBrush(BLACK);
	RECT bgRc = *getARc();

	RectangleMake(hdc, bgRc);
	FillRect(hdc, &bgRc, hBBrush);
	DeleteObject(hBBrush);

	HBRUSH hWBrush = CreateSolidBrush(WHITE);
	FrameRect(hdc, &bgRc, hWBrush);
	DeleteObject(hWBrush);

	HBRUSH hTBrush = CreateSolidBrush(_topColor);
	RECT value1 = _valueRect[0]->getRect(bgRc);
	value1.right = value1.left + _valueRect[0]->getWidth(bgRc) * (_currentValue / _maxValue);
	RectangleMake(hdc, value1);
	FillRect(hdc, &value1, hTBrush);
	DeleteObject(hTBrush);

	HBRUSH hBtBrush = CreateSolidBrush(_bottomColor);
	RECT value2 = _valueRect[1]->getRect(bgRc);
	value2.right = value2.left + _valueRect[1]->getWidth(bgRc) * (_currentValue / _maxValue);
	RectangleMake(hdc, value2);
	FillRect(hdc, &value2, hBtBrush);
	DeleteObject(hBtBrush);
}
