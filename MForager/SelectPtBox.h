#pragma once
#include "UI.h"
#include "SimpleAnimation.h"

class SelectPtBox: public UI
{
public:
	SimpleAnimation* _animation;

	SelectPtBox(PointF pt, int width, int height) :UI(pt, width, height) {
		setIsShowing(false);
		initAnimation();
	};

	void initAnimation() {
		_animation = new SimpleAnimation;
		_bAnimation = _animation;
	}
};

