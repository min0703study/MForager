#include "Stdafx.h"
#include "ProgressBar.h"

ProgressBar::ProgressBar(POINTF startPt, float bgWidth, float bgHeight, int maxValue, int currentValue, COLORREF top, COLORREF bottom)
	:UI(startPt, bgWidth, bgHeight)
	, _bgWidth(bgWidth)
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

	initAnimation();
}


ProgressBar::ProgressBar(float bgWidth, float bgHeight, COLORREF top, COLORREF bottom)
	:UI({0,0}, _bgWidth, _bgHeight)
	, _bgWidth(bgWidth)
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

		POINTF valueStartPt = { _startPt.x + (_bgWidth * 0.1f),  _startPt.y + (_bgHeight * 0.2f) };

		_valueRect[0] = RectMake(valueStartPt, _valueWidth, _valueHeight / 2);
		_valueRect[1] = RectMake(POINTF{ valueStartPt.x, valueStartPt.y + _valueHeight / 2 }, _valueWidth, _valueHeight / 2);

		//���� ǥ���ϴ� progress bar�� ����
		for (RECT& rc : _valueRect) {
			float a = (_currentValue / _maxValue);
			rc.right = rc.left + _valueWidth * (_currentValue / _maxValue);
		}
	}
}

void ProgressBar::setValueRelRect() {
	POINTF valueStartPt = { _bgRect.left + (_bgWidth * 0.1f),  _bgRect.top + (_bgHeight * 0.2f) };

	_valueRect[0] = RectMake(valueStartPt, _valueWidth, _valueHeight / 2);
	_valueRect[1] = RectMake(POINTF{ valueStartPt.x, valueStartPt.y + _valueHeight / 2 }, _valueWidth, _valueHeight / 2);

	for (RECT& rc : _valueRect) {
		float a = (_currentValue / _maxValue);
		rc.right = rc.left + _valueWidth * (_currentValue / _maxValue);
	}
}

void ProgressBar::play(HDC hdc, POINTF cameraPt)
{
	_bgRect = getRRect(cameraPt);
	setValueRelRect();
	this->play(hdc);
}

void ProgressBar::play(HDC hdc) {
	HBRUSH hBBrush = CreateSolidBrush(BLACK);
	RectangleMake(hdc, _bgRect);
	FillRect(hdc, &_bgRect, hBBrush);
	DeleteObject(hBBrush);

	HBRUSH hWBrush = CreateSolidBrush(WHITE);
	FrameRect(hdc, &_bgRect, hWBrush);
	DeleteObject(hWBrush);

	HBRUSH hTBrush = CreateSolidBrush(_topColor);
	RectangleMake(hdc, _valueRect[0]);
	FillRect(hdc, &_valueRect[0], hTBrush);
	DeleteObject(hTBrush);

	HBRUSH hBTBrush = CreateSolidBrush(_bottomColor);
	RectangleMake(hdc, _valueRect[1]);
	FillRect(hdc, &_valueRect[1], hBTBrush);
	DeleteObject(hBTBrush);
}
