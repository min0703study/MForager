#pragma once
#include "Industrial.h"

using namespace INDUSTRIAL::CRAFTING;

class Furanace: public Industrial
{
	virtual bool makeConditionCheck(Inventory* _inventory);
	bool makeConditionCheck(int makeItemId, Inventory * inventory);
};

