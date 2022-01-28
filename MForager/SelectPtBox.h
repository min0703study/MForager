#pragma once
#include "UI.h"
#include "SimpleAnimation.h"

class SelectPtBox: public UI
{
public:
	SimpleAnimation* _animation;

	SelectPtBox(POINTF pt, int width, int height) :UI(pt, width, height) {
		setIsShowing(false);
		_animation = new SimpleAnimation;
		_bAnimation = _animation;
	};
};

