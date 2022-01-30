#pragma once
#include "UI.h"

class Industrial: public UI
{
public:
	struct INGREDIENT {
		int _playerLevel;
		int _itemId;
		int _count;
	};

	string name;
	string explantion;
	INGREDIENT Ingredients;
	
	virtual bool makeConditionCheck();
};

