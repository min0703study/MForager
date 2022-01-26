#pragma once
#include "Stone.h"

class ItemManager
{
public:
	struct DropItem {
		const int _dropSpeed = 2;

		ItemBase* _dropItem;
		
		RECT _currentRc;

		POINTF _startPt;
		POINTF _endPt;

		float _gravity;
		int _dropDirection;

		bool _isEndDrop;

		DropItem(ItemBase* dropItem, POINTF startPt, POINTF endPt, int dropDirection) :
			_dropItem(dropItem), 
			_startPt(startPt),
			_gravity(0.0),
			_endPt(endPt),
			_dropDirection(dropDirection),
			_isEndDrop(false) {};
	};

	vector<DropItem*> _dropItems;
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	void createDropItem(vector<ItemBase*> _dropItem);
};

