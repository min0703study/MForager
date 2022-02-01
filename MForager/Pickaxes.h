#pragma once
#include "UI.h"
#include "PickaxesAnimation.h"

class Pickaxes: public UI
{
private:
	float _currentAngle;
	int i;
	bool flag;
public:
	Pickaxes(PointF* plyaerAbsPt, float _width, float _height) : UI(plyaerAbsPt, _width, _height, new PickaxesAnimation) 
	{
		i = -1;
		_currentAngle = 0.0f;
	};

	void play(HDC hdc);
};

