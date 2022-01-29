#include "Stdafx.h"
#include "Stone.h"

Stone::Stone(POINTF pt, TYPE type): ItemBase(pt, TILE_SIZE, TILE_SIZE), _type(type)
{
	initAnimation();
	switch (type)
	{
	case STONE:
		setStopImage((int)ItemAnimation::State::stop, RES_STONE_NORMAL_STOP_PATH);
		break;
	case IRON_ORE:
		setStopImage((int)ItemAnimation::State::stop, RES_IRON_ORE_STOP_PATH);
		break;
	}
}

void Stone::initAnimation()
{
	_animation = new ItemAnimation();
	_bAnimation = _animation;
}
