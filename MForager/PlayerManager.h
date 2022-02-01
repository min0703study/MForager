#pragma once
#include "Player.h"
#include "PlayerAnimation.h"
#include "ProgressBar.h"
#include "Inventory.h"
#include "Heart.h"
#include "Pickaxes.h"

class ItemManager;
class MapManager;
class CameraManager;
class UIManager;
class CollectionManager;

#define DEFUALT_PLAYER_HP		100
#define DEFULAT_PLAYER_POWER	10
#define DEFAULT_LIFE_COUNT		3

using namespace PLAYER;

class PlayerManager
{

private:
	enum ACTION_TYPE {
		STOP,
		WALK,
		ACTION,
	};
public:
	ItemManager* _itemManager;
	MapManager* _mapManager;
	CollectionManager* _collectionManager;

	UIManager* _uiManager;

	Player* _player;

	ACTION_TYPE _curActType;
	ProgressBar* _hpGage;
	Heart* _heart[3];
	Pickaxes* _pickaxes;

	Inventory* _inventory;
	
	void addInventoryItem(ItemBase* item);

	HRESULT init();
	void update();
	void move(int addX, int addY, MOVE_DIRECTION mDirection);
	void release();

	void actionCollect();
	void stopAction();
	bool ptIsClickable(POINTF pt);

	RECT getPlayerRelRect();
	RECT getPlayerAbsRect();
	PointF getPlayerRelPt();

	void setState(ACTION_TYPE act, BOOL isStart);
	void changeDirection();
	void changeAnimation();

	int getHp() { return _player->_currentHp; }
	int getLifeCount() { return _player->_lifeCount; }
};

