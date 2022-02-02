#pragma once
#include "UI.h"
#include "Inventory.h"
#include "SimpleAnimation.h"
class Industrial: public UI
{
public:
	string name;
	string explantion;
	

	Industrial(PointF pt, int width, int height) : UI(pt, width, height, new SimpleAnimation) {

	};
	virtual bool makeConditionCheck(Inventory* _inventory);
};

