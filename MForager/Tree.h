#pragma once
#include "CollectionBase.h"
//#include "Wood.h"

#define NOMAL_TREE_HIT_GAGE		20
using namespace COLLECT::TREE;

class Tree : public CollectionBase
{
public:
	TYPE _type;
	virtual vector<ItemBase*> getDropItem();
	Tree(PointF hitPt, TYPE type = NOMAL);
};
