#pragma once
#include "UI.h"
#include "SimpleAnimation.h"

class SelectPtBox: public UI
{
public:
	SelectPtBox(PointF pt, int width, int height) 
		:UI(pt, width, height, new SimpleAnimation) {
		setIsShowing(false);
		_animation->mapping((int)SimpleAnimation::State::oneMove, RES::SELECT_BOX);
	};
};

