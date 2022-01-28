#include "Stdafx.h"
#include "Stone.h"

Stone::Stone(POINTF pt, int width, int height): ItemBase(pt, width, height)
{
	_animation = new ItemAnimation();
	_bAnimation = _animation;
	_animation->setAnimationImage(ItemAnimation::State::stop, "STONE_1", RES_STONE_NORMAL_STOP_PATH, width, height, 1, 1);
	_animation->init(pt, ItemAnimation::State::stop);

}
