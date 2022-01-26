#include "Stdafx.h"
#include "Stone.h"

Stone::Stone(POINTF pt)
{
	_animation = new ItemAnimation();
	_animation->setAnimationImage(ItemAnimation::State::stop, "STONE_1", RES_STONE_NORMAL_STOP_PATH, 50, 50, 1, 1);
	_animation->init(pt, ItemAnimation::State::stop);

	_currentPt = pt;
}
