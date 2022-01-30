#include "Stdafx.h"
#include "Stone.h"

Stone::Stone(POINTF pt, TYPE type): ItemBase(setIdForType(type), pt, TILE_SIZE, TILE_SIZE), _type(type)
{
	initAnimation();
	switch (type)
	{
	case STONE:
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

inline int Stone::setIdForType(TYPE type)
{
	switch (type)
	{
	case STONE:
		return STONE_ID;
	case IRON_ORE:
		return IRON_ORE_ID;
	}
}
