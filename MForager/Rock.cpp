#include "Stdafx.h"
#include "Rock.h"


Rock::Rock(POINTF hitPt, TYPE type) : CollectionBase(hitPt, 1, 1),  _type(type)
{
	switch (type) {
		case ROCK:
			if (RND->getFlag()) {
				setStopImage((int)CollectAnimation::State::stop ,RES_ROCK_NORMAL_STOP_1_PATH);
			} else {
				setStopImage((int)CollectAnimation::State::stop, RES_ROCK_NORMAL_STOP_2_PATH);
			}

			_hitGage = NOMAL_ROCK_HIT_GAGE;
			_maxHitGage = NOMAL_ROCK_HIT_GAGE;

			break;
		case COAL:
			break;
		case IRON:
			if (RND->getFlag()) {
				setStopImage((int)CollectAnimation::State::stop, RES_ROCK_IRON_STOP_1_PATH);
			}
			else {
				setStopImage((int)CollectAnimation::State::stop, RES_ROCK_IRON_STOP_2_PATH);
			}

			_hitGage = IRON_ROCK_HIT_GAGE;
			_maxHitGage = IRON_ROCK_HIT_GAGE;
			break;
		case GOLD:
			break;
	}

	_animation->init(_absPt, CollectAnimation::State::stop);
}


vector<ItemBase*> Rock::getDropItem()
{
	vector<ItemBase*> _dropItem;
	switch (_type) {
	case ROCK:
		//_dropItem.push_back(new Stone(_absPt, ITEM::STONE::STONE));
		//_dropItem.push_back(new Stone(_absPt, ITEM::STONE::STONE));
		break;
	case COAL:
		break;
	case IRON:
		//_dropItem.push_back(new Stone(_absPt, ITEM::STONE::IRON_ORE));
		//_dropItem.push_back(new Stone(_absPt, ITEM::STONE::IRON_ORE));
		break;
	case GOLD:
		break;
	}

	return _dropItem;
}
