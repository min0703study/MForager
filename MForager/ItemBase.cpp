#include "Stdafx.h"
#include "ItemBase.h"

ItemBase::ItemBase(int _itemId, PointF pt, int width, int height):
	UI(pt, width, height, new ItemAnimation), 
	_ItemId(_itemId) {

}