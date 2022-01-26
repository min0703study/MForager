#pragma once
#include "CollectionBase.h"
#include "Stone.h"

class Rock: public CollectionBase
{
public:
	enum TYPE {
		ROCK,
		COAL,
		IRON,
		GOLD
	};

	TYPE _type;

	Rock(TYPE type, POINT point);
};

