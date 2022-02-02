#include "Stdafx.h"
#include "Stone.h"

Stone::Stone(PointF pt, TYPE type): 
	ItemBase(setIdForType(type), pt, TILE_SIZE, TILE_SIZE), 
	_type(type)
{
	switch (type)
	{
	case STONE:
		_animation->mapping((int)ItemAnimation::State::stop, RES::STONE_NORMAL_STOP);
		break;
	case IRON_ORE:
		_animation->mapping((int)ItemAnimation::State::stop, RES::IRON_ORE_STOP);
		break;
	case COAL :
		_animation->mapping((int)ItemAnimation::State::stop, RES::COAL_STOP);
		break;
	}
	_animation->init((int)ItemAnimation::State::stop);
}

inline int Stone::setIdForType(TYPE type)
{
	switch (type)
	{
	case STONE:
		return STONE_ID;
	case IRON_ORE:
		return IRON_ORE_ID;
	case COAL:
		return COAL_ID;
	}
}
