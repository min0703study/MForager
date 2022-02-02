#pragma once
#include "UI.h"
class ProgressBar: public UI
{
private:
	SRECT* _valueRect[2];

	float _bgWidth;
	float _bgHeight;

	float _valueWidth;
	float _valueHeight;

	float _maxValue;
	float _currentValue;

	COLORREF _topColor; //top
	COLORREF _bottomColor; //bottom

public:
	ProgressBar(PointF startPt, float _bgWidth, float _bgHeight, int maxValue, int currentValue, COLORREF _topColor, COLORREF _bottomColor);
	~ProgressBar();

	void setValue(int maxValue, int value);

	void setValue(int value);

	virtual void play(HDC hdc) override;
	virtual void playFixed(HDC hdc) override;

	void initAnimation() {};

};