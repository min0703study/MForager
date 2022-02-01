#include "Stdafx.h"
#include "Wood.h"

Wood::Wood(PointF pt, int width, int height) : ItemBase(
	setIdForType(WOOD),
	pt, 
	width, 
	height)
{
	initAnimation();
}

void Wood::initAnimation()
{
	_animation->setAnimationImage((int)ItemAnimation::State::stop, "WOOD_STOP", RES_WOOD_NORMAL_STOP_PATH, getWidth(), getHeight(), 1, 1);
	_animation->init((int)ItemAnimation::State::stop);

}

inline int Wood::setIdForType(TYPE type) {
	switch (type)
	{
		case WOOD:
			return (int)WOOD_ID;
	}
	return -1;
}