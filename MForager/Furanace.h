#pragma once
#include "Industrial.h"
#include "Stone.h"

using namespace INDUSTRIAL::CRAFTING;

class Furanace: public Industrial
{
public:
	vector<INDUSTRIAL::CRAFTING::INGEDIENTS*> _list;
	int _makeTime;
	bool _isMaking;
	ItemBase* _makeItem;
public:
	Furanace(PointF pt, float width, float height): Industrial(pt, width, height) {
		_animation->mapping((int)SimpleAnimation::State::oneMove, FURANACE_STOP);
		_animation->init((int)SimpleAnimation::State::oneMove);
	}
	//virtual bool makeConditionCheck(Inventory* _inventory);
	bool makeConditionCheck(int makeItemId, Inventory * inventory);

	ItemBase * overMaking();

	RECT getPlayerCheckRect() {
		return RECT({ getRRc().left, getRRc().bottom, getRRc().right, getRRc().bottom + 70});
	}
};

