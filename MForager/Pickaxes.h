#pragma once
#include "UI.h"
#include "PickaxesAnimation.h"

class Pickaxes: public UI
{
private:
	PickaxesAnimation* _animation;
	PointF* _playerAbsPt;

public:
	Pickaxes(PointF* plyaerAbsPt, float _width, float _height) : UI(*plyaerAbsPt, _width, _height), _playerAbsPt(plyaerAbsPt) {
		_animation = new PickaxesAnimation;
		_bAnimation = _animation;

		_animation->setImage(PickaxesAnimation::State::action, RES::PICKAXES_NORMAL, _width, _height);
		_animation->init(PickaxesAnimation::State::action);
	};

	void play(HDC hdc);
};

