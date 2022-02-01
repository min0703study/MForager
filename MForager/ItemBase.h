#pragma once
#include "ItemAnimation.h"
#include "UI.h"
class ItemBase: public UI
{
public:
	int _ItemId;
	ItemBase(int _itemId, PointF pt, int widht, int height);

	int getId() { return _ItemId; };

	bool _isIngredient;
	bool _isRaw;

};