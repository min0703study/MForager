#pragma once
#include "PlayerManager.h"
class MenuManager
{
	
public:
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
};

