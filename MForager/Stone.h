#pragma once
#include "ItemBase.h"

class Stone: public ItemBase
{
public:
	enum TYPE {
		STONE,
		COAL,
		IRON_ORE,
		GOLD_ORE
	};
	TYPE _type;
	Stone(POINTF pt, TYPE type);
	int getId() override { return 1; }

	void initAnimation() override;
};

