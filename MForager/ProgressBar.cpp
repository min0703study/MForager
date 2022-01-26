#include "Stdafx.h"
#include "ProgressBar.h"

ProgressBar::ProgressBar(POINTF startPt, float bgWidth, float bgHeight, int maxValue, int currentValue, COLORREF top, COLORREF bottom)
	:_bgWidth(bgWidth)
	, _bgHeight(bgHeight)
	, _valueWidth(bgWidth * 0.8)
	, _valueHeight(bgHeight * 0.6)
	, _startPt(startPt)
	, _maxValue(maxValue)
	, _currentValue(currentValue)
	, _topColor(top)
	, _bottomColor(bottom)
	, _bgRect(RectMake(startPt, bgWidth, bgHeight))
{

	POINTF valueStartPt = { startPt.x + (_bgWidth * 0.1f),  startPt.y + (_bgHeight * 0.2f) };

	_valueRect[0] = RectMake(valueStartPt, _valueWidth, _valueHeight / 2);
	_valueRect[1] = RectMake(POINTF{ valueStartPt.x, valueStartPt.y + _valueHeight / 2 }, _valueWidth, _valueHeight / 2);
}


ProgressBar::ProgressBar(float bgWidth, float bgHeight, COLORREF top, COLORREF bottom)
	:_bgWidth(bgWidth)
	, _bgHeight(bgHeight)
	, _valueWidth(bgWidth * 0.8)
	, _valueHeight(bgHeight * 0.6)
	, _topColor(top)
	, _bottomColor(bottom)
{}

ProgressBar::~ProgressBar()
{
}

void ProgressBar::setValue(int value)
{
	if (_currentValue != value) {
		_currentValue = value;

		//값을 표시하는 progress bar을 조절
		for (RECT& rc : _valueRect) {
			float a = (_currentValue / _maxValue);
			rc.right = rc.left + _valueWidth * (_currentValue / _maxValue);
		}
	}
}

void ProgressBar::setValue(POINTF startPt, int maxValue, int currentValue)
{
	_startPt = startPt;
	_currentValue = currentValue;
	_maxValue = maxValue;

	_bgRect = RectMakeF(startPt, _bgWidth, _bgHeight);
	POINTF valueStartPt = { startPt.x + (_bgWidth * 0.1f),  startPt.y + (_bgHeight * 0.2f) };

	_valueRect[0] = RectMakeF(valueStartPt, _valueWidth, _valueHeight / 2);
	_valueRect[1] = RectMakeF(POINTF{ valueStartPt.x, valueStartPt.y + _valueHeight / 2 }, _valueWidth, _valueHeight / 2);

	//값을 표시하는 progress bar을 조절
	for (RECT& rc : _valueRect) {
		float a = (_currentValue / _maxValue);
		rc.right = rc.left + _valueWidth * (_currentValue / _maxValue);
	}
}

void ProgressBar::render(HDC hdc)
{
	HBRUSH hBrush = CreateSolidBrush(BLACK);
	RectangleMake(hdc, _bgRect);
	FillRect(hdc, &_bgRect, hBrush);
	hBrush = CreateSolidBrush(WHITE);
	FrameRect(hdc, &_bgRect, hBrush);

	hBrush = CreateSolidBrush(_topColor);
	RectangleMake(hdc, _valueRect[0]);
	FillRect(hdc, &_valueRect[0], hBrush);

	hBrush = CreateSolidBrush(_bottomColor);
	RectangleMake(hdc, _valueRect[1]);
	FillRect(hdc, &_valueRect[1], hBrush);

	DeleteObject(hBrush);
}
