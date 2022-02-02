#include "Stdafx.h"
#include "Food.h"

Food::Food(PointF pt, TYPE type):
	ItemBase(setIdForType(type),
		pt, 
		TILE_SIZE, 
		TILE_SIZE)
{
	switch (type)
	{
	case TYPE::BERRY:
		_animation->mapping((int)ItemAnimation::State::stop, BERRY_STOP);
		_energy = 5;
		break;
	case TYPE::CIR:
		_animation->mapping((int)ItemAnimation::State::stop, CITRUS_STOP);
		_energy = 5;
		break;
	}
	_animation->init((int)ItemAnimation::State::stop);
}

inline int Food::setIdForType(TYPE type)
{
	using namespace ITEM::FOOD;
	switch (type)
	{
	case TYPE::BERRY:
		return BERRY_ID;
	case TYPE::CIR:
		return BERRY_ID;
	}
}
