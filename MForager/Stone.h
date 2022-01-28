#pragma once
#include "ItemBase.h"


class Stone: public ItemBase
{
public:
	Stone(POINTF pt, int width, int height);
	int getId() override { return 1; }
};

