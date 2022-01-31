#pragma once
#include "CollectionBase.h"

#define NOMAL_ROCK_HIT_GAGE			20
#define IRON_ROCK_HIT_GAGE			20

using namespace COLLECT::ROCK;

class Rock: public CollectionBase
{
public:
	TYPE _type;
	virtual vector<ItemBase*> getDropItem();
	
	Rock(PointF hitPt, TYPE type);
};

