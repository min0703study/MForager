#pragma once
#include "PlayerManager.h"
#include "InventoryBox.h"
#include "Food.h"

#define INVENTROY_COUNT 16

using namespace MENU;

class MenuManager
{
public:
	vector<InventoryBox*> _itemBoxList;
	LPRECT _frameRect;
	enum MenuType {
		M_INVENTORY
	};

	PlayerManager* _playerManager;
	
	bool _isOpenMenu;
	MenuType _curMenu;

	HRESULT init();

	void release(void);
	void render(HDC hdc);
	void update();

	void mouseClickEvent(POINT& currentPoint, bool isClickDown);
};

