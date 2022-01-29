#include "Stdafx.h"
#include "Heart.h"

void Heart::initAnimation()
{
	_animation = new HeartAnimation;
	_bAnimation = _animation;

	_animation->setAnimationImage(HeartAnimation::State::live, "H_LIVE", RES_HEART_PATH, TILE_SIZE * 0.7, TILE_SIZE * 0.7, 1, 1);
	_animation->setAnimationImage(HeartAnimation::State::blank, "H_BLANK", RES_HEART_BLANK_PATH, TILE_SIZE * 0.7, TILE_SIZE * 0.7, 1, 1);
	
	_animation->setState(HeartAnimation::State::live);
}
