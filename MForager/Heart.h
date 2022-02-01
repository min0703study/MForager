#pragma once
#include "UI.h"
#include "HeartAnimation.h"

class Heart : public UI
{
public:
	Heart(PointF pt, int width, int height)
		:UI(pt, width, height, new HeartAnimation) {
		_isShowing = true;

		_animation->setAnimationImage((int)HeartAnimation::State::live, "H_LIVE", RES_HEART_PATH, TILE_SIZE * 0.7, TILE_SIZE * 0.7, 1, 1);
		_animation->setAnimationImage((int)HeartAnimation::State::blank, "H_BLANK", RES_HEART_BLANK_PATH, TILE_SIZE * 0.7, TILE_SIZE * 0.7, 1, 1);

		_animation->init((int)HeartAnimation::State::live);
	};

	void initAnimation() override;
};

