#include "Stdafx.h"
#include "Tree.h"

Tree::Tree(PointF hitPt, TYPE type): CollectionBase(hitPt, 1, 2),  _type(type)
{
	using namespace COLLECT::TREE::DEFAULT_VALUE;
	switch (type) {
	case TYPE::NOMAL:
		setAnimationImageAuto(CollectAnimation::State::stop, "TREE", RES_TREE_NORMAL_STOP_1_PATH, 1, 1);
		_animation->init((int)CollectAnimation::State::stop);
		_hitGage = TREE_HIT_GAGE;
		_maxHitGage = TREE_HIT_GAGE;
		break;
	}

}

vector<ItemBase*> Tree::getDropItem()
{
	vector<ItemBase*> _dropItem;
	switch (_type) {
	case TYPE::NOMAL:
			_dropItem.push_back(new Wood(*getAPt()));
			_dropItem.push_back(new Wood(*getAPt()));
			break;
	}

	return _dropItem;
}
