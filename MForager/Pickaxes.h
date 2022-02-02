#pragma once
#include "UI.h"
#include "Bundlable.h"
#include "PickaxesAnimation.h"

class Pickaxes: public Bundlable
{
private:
	float _currentAngle;
	int i;
	bool flag;
	int _direction;
public:

	Pickaxes(PointF* plyaerAbsPt, float _width, float _height) : Bundlable(700, plyaerAbsPt, _width, _height, new PickaxesAnimation)
	{
		_direction = 1;
		i = -1;
		_currentAngle = 0.0f;
	};

	void play(HDC hdc);

	void changeDirect() { 
		_direction *= -1; 
		GDIPLUSMANAGER->flipeX((int)RES::PICKAXES_NORMAL);
	}

	void startAction() {
		_currentAngle = 0.0f;
		_animation->chageState((int)PickaxesAnimation::State::action);
	}

	void stopAction() {
		_currentAngle = 0.0f;
		_animation->chageState((int)PickaxesAnimation::State::stop);
	}
};

