#pragma once
#include "ItemBase.h"

class Food: public ItemBase
{
public:
	enum TYPE {
		Berry = 3,
		Citrus
	};

	Food(POINTF pt, TYPE type);
private:
	TYPE _type;
	int _energy;
};

