#include "Stdafx.h"
#include "Wood.h"

Wood::Wood(POINTF pt, int width, int height) : ItemBase(pt, width, height)
{
	initAnimation();
}

void Wood::initAnimation()
{
	_animation = new ItemAnimation();
	_animation->setAnimationImage(ItemAnimation::State::stop, "WOOD_STOP", RES_WOOD_NORMAL_STOP_PATH, _width, _height, 1, 1);
	_animation->init(_absPt, ItemAnimation::State::stop);
	_bAnimation = _animation;
}
