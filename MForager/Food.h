#pragma once
#include "ItemBase.h"

class Food: public ItemBase
{
public:
	enum TYPE {
		Berry = 3,
		Citrus
	};

	Food(PointF pt, TYPE type);
private:
	TYPE _type;
	int _energy;
};

