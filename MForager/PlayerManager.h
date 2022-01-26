#pragma once
#include "Player.h"
#include "PlayerAnimation.h"
#include "CollectionBase.h"
#include "ProgressBar.h"

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

