#include "Stdafx.h"
#include "Wood.h"

Wood::Wood(PointF pt) : ItemBase (
	setIdForType(TYPE::WOOD),
	pt, 
	ITEM::WOOD::UI_INFO::X_SIZE,
	ITEM::WOOD::UI_INFO::Y_SIZE)
{
	_animation->mapping((int)ItemAnimation::State::stop, RES::WOOD_NORMAL_STOP);
	_animation->init((int)ItemAnimation::State::stop);
}

inline int Wood::setIdForType(TYPE type) {
	switch (type)
	{
	case TYPE::WOOD:
			return (int)ID::WOOD_ID;
	}
	return -1;
}