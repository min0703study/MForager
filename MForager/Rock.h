#pragma once
#include "CollectionBase.h"
#include "Stone.h"

#define ROCK_X_SIZE TILE_SIZE
#define ROCK_Y_SIZE TILE_SIZE
#define NOMAL_ROCK_HIT_GAGE			20
#define IRON_ROCK_HIT_GAGE			20

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
	virtual vector<ItemBase*> getDropItem();
	
	Rock(POINTF hitPt, TYPE type);
};

