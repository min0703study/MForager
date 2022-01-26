#pragma once
#include "Player.h"
#include "PlayerAnimation.h"
#include "CollectionBase.h"
#include "ProgressBar.h"

#define DEFUALT_PLAYER_HP		100
#define DEFULAT_PLAYER_POWER	10
#define DEFAULT_LIFE_COUNT		3

class PlayerManager
{
public:
	Player* _player;
	ProgressBar* _hpGage;

	HRESULT init();
	void update();
	void release();

	void render(HDC hdc);
	void actionCollect(CollectionBase* collect);
};

