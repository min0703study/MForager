#pragma once
#include "CollectionBase.h"
#include "Food.h"

class BerryBush: public CollectionBase
{
private:
	typedef COLLECT::BERRY_BUSH::TYPE TYPE;
public:
	TYPE _type;
	virtual vector<ItemBase*> getDropItem();

	BerryBush(PointF hitPt, TYPE type);
};
