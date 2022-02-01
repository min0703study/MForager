#pragma once
#include "ItemBase.h"

using namespace ITEM::STONE;

class Stone: public ItemBase
{
public:
	TYPE _type;
	Stone(PointF pt, TYPE type);

	inline int setIdForType(TYPE type);
};

