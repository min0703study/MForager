#pragma once
#include "UI.h"

class Bundlable: public UI
{
public:
	int _ItemId;
	
	Bundlable(int _itemId, PointF* pt, int width, int height, AnimationBase* animation) :
		UI(pt, width, height, animation),
		_ItemId(_itemId)
	{

	}

	Bundlable(int _itemId, PointF pt, int width, int height, AnimationBase* animation): 
		UI(pt, width, height, animation), 
		_ItemId(_itemId)
	{

	}
};

