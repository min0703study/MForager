#pragma once
#include "ItemAnimation.h"
#include "UI.h"
class ItemBase: public UI
{
public:
	int _ItemId;

	ItemAnimation* _animation;
	ItemBase(POINTF pt, int widht, int height);

	virtual int getId() { return 0; };
};

