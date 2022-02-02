#pragma once
#include "Furanace.h"
#include "UIManager.h"
#include "PlayerManager.h"
#include "ItemManager.h"

class IndustrialManager
{
private:
	Furanace* _furanace;
	bool isOpen;
public:
	PlayerManager* _playerManager;
	UIManager* _uiManager;
	ItemManager* _itemManager;

	HRESULT init();
	void update();
	void render(HDC hdc);
	void release();


	void clickEvent(POINT & pt, bool isClickDown);
};

