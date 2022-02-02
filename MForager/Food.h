#pragma once
#include "ItemBase.h"

class Food: public ItemBase
{
private:
	typedef ITEM::FOOD::TYPE TYPE;
	TYPE _type;
	int _energy;
public:
	Food(PointF pt, TYPE type);
	int setIdForType(TYPE type);
	int getEnergy() { return _energy; };
};

