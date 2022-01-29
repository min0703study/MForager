#pragma once
#include "UI.h"

class Industrial: public UI
{
public:
	string name;
	string explantion;
	
	virtual bool makeConditionCheck();
};

