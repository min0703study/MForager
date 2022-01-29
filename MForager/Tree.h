#pragma once
#include "CollectionBase.h"
#include "Wood.h"

#define NOMAL_TREE_HIT_GAGE		20

class Tree : public CollectionBase
{
public:
	enum TYPE {
		NOMAL
	};

	TYPE _type;
	virtual vector<ItemBase*> getDropItem();
	Tree(POINTF hitPt, TYPE type = NOMAL);
};
