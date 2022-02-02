#pragma once
#include "CollectionBase.h"
#include "Wood.h"

#define NOMAL_TREE_HIT_GAGE		20

class Tree : public CollectionBase
{
private:
	typedef COLLECT::TREE::TYPE TYPE;
public:
	Tree(PointF hitPt, TYPE type = TYPE::NOMAL);
	TYPE _type;
	virtual vector<ItemBase*> getDropItem();
};
