#pragma once
#include "UI.h"
class ProgressBar: public UI
{
private:
	LPDRECT _valueRect[2];

	float _bgWidth;
	float _bgHeight;

	float _valueWidth;
	float _valueHeight;

	float _maxValue;
	float _currentValue;

	COLORREF _topColor; //top
	COLORREF _bottomColor; //bottom

public:
	ProgressBar(PointF* startPt, float _bgWidth, float _bgHeight, int maxValue, int currentValue, COLORREF _topColor, COLORREF _bottomColor);
	~ProgressBar();

	void setValue(int value);
	void setValueRelRect();

	virtual void play(HDC hdc) override;

	void initAnimation() {};

};