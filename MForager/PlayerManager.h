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
#define DEFAULT_ACTION_TIME		20
#include "Toolbar.h"

class PlayerManager
{
private:
	typedef PlayerAnimation::AniState AniState;
	
	enum ACTION_TYPE {
		STOP,
		WALK,
		ACTION,
	};

public:
	Player* _player;
	bool _isActionIng;
	int _actionTime;
#if DEVELOP_MODE
	//develop
	LPRECT _playerClickableRc;
	LPRECT _playerMoveRc;
#endif
	ItemManager* _itemManager;
	MapManager* _mapManager;
	CollectionManager* _collectionManager;

	UIManager* _uiManager;

	ACTION_TYPE _curActType;
	ProgressBar* _hpGage;
	ProgressBar* _expGage;
	Heart* _heart[3];
	vector<Toolbar*> _toolbars;
	Pickaxes* _pickaxes;

	Inventory* _inventory;
	
	void addInventoryItem(ItemBase* item);

	HRESULT init();
	void update();
	void move(int addX, int addY, MOVE_DIRECTION mDirection);
	void release();

	void actionCollect();
	void stopAction();
	bool ptIsClickable(POINT pt);

	RECT getPlayerRelRect();
	RECT getPlayerAbsRect();
	PointF getPlayerRelPt();

	void addExp();
	int getMaxEtcPointOfLevel(int level);
	void setState(ACTION_TYPE act, bool isStart);

	void changeDirection();
	void changeAnimation();

	int getHp() { return _player->_currentHp; }
	int getLifeCount() { return _player->_lifeCount; }

	int eatFood(int energe);

	Inventory* getInventory() {return _inventory;}
};

