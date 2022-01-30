#pragma once
#include "UI.h"
#include "Inventory.h"

class Industrial: public UI
{
public:
	string name;
	string explantion;
	
	virtual bool makeConditionCheck(Inventory* _inventory);
};

