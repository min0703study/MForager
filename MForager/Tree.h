#pragma once
#include "CollectionBase.h"

class Tree: public CollectionBase
{
public:
	enum TYPE {
		NORMAL
	};

	Tree(TYPE type, POINT pt);
	~Tree() {};
};

