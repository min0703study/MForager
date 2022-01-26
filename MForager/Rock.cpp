#include "Stdafx.h"
#include "Rock.h"

Rock::Rock(TYPE type, POINT pt) : _type(type), CollectionBase(pt,100, 1, 1)
{
	_animation = new CollectAnimation();
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
	_currentRc = RectMake(pt, TILE_SIZE * 1, TILE_SIZE* 1);
}
/*
vector<ItemBase*> Rock::dropItem()
{
	vector<ItemBase*> itemVector;

	int randomCount = RND->getFromIntTo(1, 3);
	itemVector.reserve(randomCount);
	
	for (int i = 0; i < randomCount; i++) {
		itemVector.push_back(Stone());
	}

	return itemVector;
}
*/
