#pragma once
#include "ItemAnimation.h"
class ItemBase
{
public:
	ItemAnimation* _animation;

	POINTF _currentPt;
	RECT _currentRc;
};

