#include "Stdafx.h"
#include "Tree.h"

vector<ItemBase*> Tree::getDropItem()
{
	vector<ItemBase*> _dropItem;
	switch (_type) {
		case NOMAL:
			//_dropItem.push_back(new Wood(_absPt));
			//_dropItem.push_back(new Wood(_absPt));
			break;
	}

	return _dropItem;
}

Tree::Tree(POINTF hitPt, TYPE type): CollectionBase(hitPt, 1, 2),  _type(type)
{
	switch (type) {
	case NOMAL:
		setAnimationImageAuto(CollectAnimation::State::stop, "TREE", RES_TREE_NORMAL_STOP_1_PATH, 1, 1);
		_animation->init(_absPt, CollectAnimation::State::stop);
		_hitGage = NOMAL_TREE_HIT_GAGE;
		_maxHitGage = NOMAL_TREE_HIT_GAGE;
		break;
	}

}
