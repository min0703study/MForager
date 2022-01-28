#include "Stdafx.h"
#include "Rock.h"

Rock::Rock(TYPE type, POINT pt) : _type(type), CollectionBase(pt,100, 1, 1)
{
	_animation = new CollectAnimation();
	_bAnimation = _animation;

	switch (type) {
	case ROCK:
		_hitGage = 100;
		_animation->setAnimationImage(CollectAnimation::State::stop,"ROCK_1", RES_ROCK_NORMAL_STOP_PATH, 70, 70, 1, 1);
		_animation->init(pt, CollectAnimation::State::stop);
		break;
	case COAL:
		break;
	case IRON:
		break;
	case GOLD:
		break;
	}
}