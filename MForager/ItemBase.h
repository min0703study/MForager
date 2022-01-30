#pragma once
#include "ItemAnimation.h"
#include "UI.h"
class ItemBase: public UI
{
public:
	int _ItemId;

	ItemAnimation* _animation;
	ItemBase(int _itemId, POINTF pt, int widht, int height);

	void initAnimation() override;
	int getId() { return _ItemId; };

	bool _isIngredient;
	bool _isRaw;

};