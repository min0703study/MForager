#pragma once
#include "Player.h"
#include "PlayerAnimation.h"
#include "ProgressBar.h"
#include "Inventory.h"

class ItemManager;
class MapManager;
class CameraManager;
class UIManager;
class CollectionManager;

#define DEFUALT_PLAYER_HP		100
#define DEFULAT_PLAYER_POWER	10
#define DEFAULT_LIFE_COUNT		3

class PlayerManager
{
private:
	void moveKeyCheck();
public:
	ItemManager* _itemManager;
	MapManager* _mapManager;
	CameraManager* _cameraManager;
	CollectionManager* _collectionManager;

	UIManager* _uiManager;

	Player* _player;
	ProgressBar* _hpGage;
	Inventory* _inventory;
	
	void addInventoryItem(ItemBase* item);

	HRESULT init();
	void update();
	void move(float addValue, bool isX);
	void release();

	void render(HDC hdc);
	void actionCollect();
	bool ptIsClickable(POINTF pt);
	RECT getPlayerRelRect();
};

