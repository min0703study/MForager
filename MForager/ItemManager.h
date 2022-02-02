#pragma once
#include "Stone.h"
class PlayerManager;
class UIManager;

class ItemManager
{
public:
	UIManager* _uiManager;
	PlayerManager* _playerManager;

	struct DropItem {
		const int _dropSpeed = 2;
		RECT _dropRc;

		ItemBase* _dropItem;
		POINTF _endPt;

		float _gravity;
		int _dropDirection;

		bool _isEndDrop;
		bool _isDropToPlayer;

		DropItem(ItemBase* dropItem, POINTF endPt, int dropDirection) :
			_dropItem(dropItem),
			_gravity(0.0),
			_endPt(endPt),
			_dropDirection(dropDirection),
			_isEndDrop(false),
			_isDropToPlayer(false)
		{};
	};

	vector<DropItem*> _dropItems;

	HRESULT init();
	void release();
	void update();

	void createDropItem(vector<ItemBase*> _dropItem);
	void createDropItem(ItemBase * dropItems);
	void CollisionCheckForDropItem(RECT& RRc);

};

