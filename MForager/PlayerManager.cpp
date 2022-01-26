#include "Stdafx.h"
#include "PlayerManager.h"
#include "ProgressBar.h"

HRESULT PlayerManager::init()
{
	POINTF pt = POINTF(120, 215);
	_player = new Player(pt, DEFUALT_PLAYER_HP, DEFULAT_PLAYER_POWER, DEFAULT_LIFE_COUNT);
	_player->setKey('A', 'D', 'W', 'S', 'F');

	_player->_animation->setAnimationImage( PlayerAnimation::State::stop_right, "Stop_Right", "Resource/Images/Motion/stop_right.bmp", PLAYER_SIZE_X * 3, PLAYER_SIZE_Y, 3, 1);
	_player->_animation->setAnimationImage(PlayerAnimation::State::stop_left, "Stop_Left", "Resource/Images/Motion/stop_left.bmp", PLAYER_SIZE_X * 3, PLAYER_SIZE_Y, 3, 1);
	_player->_animation->setAnimationImage(PlayerAnimation::State::action_right, "Action_Right", "Resource/Images/Motion/action_right.bmp", PLAYER_SIZE_X, PLAYER_SIZE_Y, 1, 1);
	_player->_animation->setAnimationImage(PlayerAnimation::State::action_left, "Action_Left", "Resource/Images/Motion/action_left.bmp", PLAYER_SIZE_X, PLAYER_SIZE_Y, 1, 1);
	_player->_animation->setAnimationImage(PlayerAnimation::State::walk_right, "Walk_Right", "Resource/Images/Motion/walk_right.bmp", PLAYER_SIZE_X * 3, PLAYER_SIZE_Y, 3, 1);
	_player->_animation->setAnimationImage(PlayerAnimation::State::walk_left, "Walk_Left", "Resource/Images/Motion/walk_left.bmp", PLAYER_SIZE_X * 3, PLAYER_SIZE_Y, 3, 1);

	_player->_animation->setState(PlayerAnimation::State::stop_right);

	IMAGEMANAGER->addFileImage("heart", RES_HEART_PATH, TILE_SIZE * 0.7, TILE_SIZE * 0.7, true);
	IMAGEMANAGER->addFileImage("blank_heart", RES_HEART_BLANK_PATH, TILE_SIZE * 0.7, TILE_SIZE * 0.7, true);

	_hpGage = new ProgressBar({ 10, 10 }, TILE_SIZE * 1.3, TILE_SIZE * 0.5, DEFUALT_PLAYER_HP, DEFUALT_PLAYER_HP, C_PG_HP_TOP, C_PG_HP_BOTTOM);

	return S_OK;
}

void PlayerManager::update()
{
	_hpGage->setValue(_player->getHp());
}

void PlayerManager::release()
{
	SAFE_DELETE(_player);
}

void PlayerManager::render(HDC hdc)
{
	_hpGage->render(hdc);
	for (int i = 0; i < 3; i++) {
		IMAGEMANAGER->render(_player->_lifeCount < (i + 1) ? "blank_heart" : "heart", hdc, (i * 50) + 10, 50);
	}
	_player->_animation->render(hdc);
}

void PlayerManager::actionCollect(CollectionBase* collect)
{
	collect->hit(_player->_power);
	_player->actionCollect();
}
