#include "Stdafx.h"
#include "ItemBase.h"

ItemBase::ItemBase(int _itemId, PointF pt, int width, int height):
	Bundlable(_itemId, pt, width, height, new ItemAnimation)
	{}