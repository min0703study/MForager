#pragma once
#include "ItemAnimation.h"
#include "Bundlable.h"
class ItemBase: public Bundlable
{
public:

	ItemBase(int _itemId, PointF pt, int widht, int height);

	int getId() { return _ItemId; };

	bool _isIngredient;
	bool _isRaw;

};