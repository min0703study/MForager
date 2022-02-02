#include "Stdafx.h"
#include "Rock.h"

Rock::Rock(PointF hitPt, TYPE type) : CollectionBase(hitPt, 1, 1),  _type(type)
{
	using namespace COLLECT::ROCK::DEFAULT_VALUE;

	switch (type) {
		case TYPE::ROCK:
			if (RND->getFlag()) {
				setStopImage((int)CollectAnimation::State::stop ,RES_ROCK_NORMAL_STOP_1_PATH);
			} else {
				setStopImage((int)CollectAnimation::State::stop, RES_ROCK_NORMAL_STOP_2_PATH);
			}

			_hitGage = ROCK_HIT_GAGE;
			_maxHitGage = ROCK_HIT_GAGE;

			break;
		case TYPE::COAL:
			break;
		case TYPE::IRON:
			if (RND->getFlag()) {
				setStopImage((int)CollectAnimation::State::stop, RES_ROCK_IRON_STOP_1_PATH);
			}
			else {
				setStopImage((int)CollectAnimation::State::stop, RES_ROCK_IRON_STOP_2_PATH);
			}

			_hitGage = IRON_HIT_GAGE;
			_maxHitGage = IRON_HIT_GAGE;
			break;
		case TYPE::GOLD:
			break;
	}

	_animation->init((int)CollectAnimation::State::stop);
}


vector<ItemBase*> Rock::getDropItem()
{
	vector<ItemBase*> _dropItem;
	switch (_type) {
	case TYPE::ROCK:
		_dropItem.push_back(new Stone(*getAPt(), ITEM::STONE::STONE));
		_dropItem.push_back(new Stone(*getAPt(), ITEM::STONE::STONE));
		break;
	case TYPE::COAL:
		break;
	case TYPE::IRON:
		_dropItem.push_back(new Stone(*getAPt(), ITEM::STONE::IRON_ORE));
		_dropItem.push_back(new Stone(*getAPt(), ITEM::STONE::IRON_ORE));
		break;
	case TYPE::GOLD:
		break;
	}

	return _dropItem;
}
