#pragma once
#include "CollectionBase.h"
#include "Stone.h"
#define NOMAL_ROCK_HIT_GAGE			20
#define IRON_ROCK_HIT_GAGE			20


class Rock: public CollectionBase
{
private:
	typedef COLLECT::ROCK::TYPE TYPE;
public:
	TYPE _type;
	virtual vector<ItemBase*> getDropItem();
	
	Rock(PointF hitPt, TYPE type);
};

