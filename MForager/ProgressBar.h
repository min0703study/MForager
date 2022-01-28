#pragma once
#include "UI.h"
class ProgressBar: public UI
{
private:
	RECT _bgRect;
	RECT _valueRect[2];

	POINTF _startPt;

	float _bgWidth;
	float _bgHeight;

	float _valueWidth;
	float _valueHeight;

	float _maxValue;
	float _currentValue;

	COLORREF _topColor; //top
	COLORREF _bottomColor; //bottom

public:
	ProgressBar(POINTF startPt, float _bgWidth, float _bgHeight, int maxValue, int currentValue, COLORREF _topColor, COLORREF _bottomColor);
	ProgressBar(float bgWidth, float bgHeight, COLORREF top, COLORREF bottom);
	~ProgressBar();

	void setValue(int value);
	void setValueRelRect();
	void setValue(POINTF startPt, int maxValue, int currentValue);
	void render(HDC hdc);

	virtual void play(HDC hdc, POINTF cameraPt);
};