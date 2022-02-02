#include "Stdafx.h"
#include "BerryBush.h"


BerryBush::BerryBush(PointF hitPt, TYPE type) : CollectionBase(hitPt, 1, 1), _type(type)
{
	using namespace COLLECT::BERRY_BUSH::DEFAULT_VALUE;
	switch (type) {
	case TYPE::NOMAL:
		_animation->mapping((int)CollectAnimation::State::stop, RES::BERRY_BUSH_STOP);
		_animation->init((int)CollectAnimation::State::stop);
		break;
	}
}

vector<ItemBase*> BerryBush::getDropItem()
{
	vector<ItemBase*> _dropItem;
	switch (_type) {
	case TYPE::NOMAL:
		_dropItem.push_back(new Food(*getAPt(), ITEM::FOOD::TYPE::BERRY));
		_dropItem.push_back(new Food(*getAPt(), ITEM::FOOD::TYPE::BERRY));
		break;
	}

	return _dropItem;
}
