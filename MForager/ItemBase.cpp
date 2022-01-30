#include "Stdafx.h"
#include "ItemBase.h"

ItemBase::ItemBase(int _itemId, POINTF pt, int width, int height): 
	UI(pt, width, height), 
	_ItemId(_itemId) {
	initAnimation();
}

void ItemBase::initAnimation()
{
	_animation = new ItemAnimation;
	_bAnimation = _animation;
}
