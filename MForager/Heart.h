#pragma once
#include "FixedUI.h"
#include "HeartAnimation.h"

class Heart : public FixedUI
{
public:
	Heart(PointF pt, int width, int height)
		:FixedUI(pt, width, height, new HeartAnimation) {
		_isShowing = true;

		_animation->mapping((int)HeartAnimation::State::live, RES_KEY::HEART);
		_animation->mapping((int)HeartAnimation::State::blank,RES_KEY::HEART_BLANK);

		_animation->init((int)HeartAnimation::State::live);
	};
};

