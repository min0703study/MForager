#include "Stdafx.h"

#include "ItemManager.h"
#include "PlayerManager.h"
#include "MapManager.h"
#include "CollectionManager.h"

#include "ProgressBar.h"
#include "UIManager.h"

void PlayerManager::moveKeyCheck()
{
}

void PlayerManager::addInventoryItem(ItemBase* item)
{
	//_inventory->_items.push_back(item);
}

HRESULT PlayerManager::init()
{
	_inventory = new Inventory;

	POINTF pt = FindCenterPt(_uiManager->getRcCamera());
	
	pt.x -= PLAYER_SIZE_X / 2;
	pt.y -= PLAYER_SIZE_Y / 2;

	_player = new Player(pt, PLAYER_SIZE_X,PLAYER_SIZE_Y, DEFUALT_PLAYER_HP, DEFULAT_PLAYER_POWER, DEFAULT_LIFE_COUNT);
	_player->setKey('A', 'D', 'W', 'S', 'F');
	
	_uiManager->addUI(_player);
	_uiManager->addDevelopUI(_player->getMoveRect());

	return S_OK;
}

void PlayerManager::update()
{

	if (KEYMANAGER->isStayKeyDown(_player->_moveLeft)) {
		move(-PLAYER_SPEED, 0, M_LEFT);
	}

	if (KEYMANAGER->isStayKeyDown(_player->_moveRight)) {
		move(PLAYER_SPEED, 0, M_RIGHT);
	}

	if (KEYMANAGER->isStayKeyDown(_player->_moveUp)) {
		move(0, -PLAYER_SPEED, M_TOP);
	}

	if (KEYMANAGER->isStayKeyDown(_player->_moveDown)) {
		move(0, PLAYER_SPEED, M_BOTTOM);
	}

	if (
		KEYMANAGER->isOnceKeyUp(_player->_moveLeft) ||
		KEYMANAGER->isOnceKeyUp(_player->_moveRight) ||
		KEYMANAGER->isOnceKeyUp(_player->_moveUp) ||
		KEYMANAGER->isOnceKeyUp(_player->_moveDown) ||
		KEYMANAGER->isOnceKeyUp(_player->_actionKey)
		) {
		setState(WALK, false);
	}
}

void PlayerManager::move(int addX, int addY, MOVE_DIRECTION mDirection)
{
	setState(WALK, true);

	RECT rc = _player->getMoveRect().getARect();

	rc.left += addX;
	rc.right += addX;
	rc.top += addY;
	rc.bottom += addY;

	if (!_mapManager->rcCollsionCheck(rc)) {
		_player->getMoveRect().getRRect(_uiManager->getRcCamera());
		_uiManager->moveCamera(addX, addY, mDirection);
		_player->move(addX, addY);
	}
}

void PlayerManager::release()
{
	SAFE_DELETE(_player);
}

void PlayerManager::actionCollect()
{
	setState(ACTION, true);

	_player->actionCollect();
	_collectionManager->hitCollect(_player->_power);
}

void PlayerManager::stopAction()
{
	setState(ACTION, false);
}

bool PlayerManager::ptIsClickable(POINTF pt)
{
	return PtInRect(&_player->getClickableRect().getARect(), pt.toPOINT());
}

RECT PlayerManager::getPlayerRelRect() {
	return _uiManager->getRelRect(_player);
}

POINTF PlayerManager::getPlayerRelPt()
{
	return _uiManager->getRelPt(_player);
}
void PlayerManager::setState(ACTION_TYPE act, BOOL isStart)
{
	_curActType = isStart ? act : STOP;
	changeAnimation();
}

void PlayerManager::changeDirection() {
	changeAnimation();
}

void PlayerManager::changeAnimation()
{
	if (_uiManager->getCursorDirection() == C_LEFT) {
		switch (_curActType)
		{
		case STOP:
			_player->_animation->setState(PlayerAnimation::State::stop_left);
			break;
		case WALK:
			_player->_animation->setState(PlayerAnimation::State::walk_left);
			break;
		case ACTION:
			_player->_animation->setState(PlayerAnimation::State::action_left);
			break;
		}
	}
	else {
		switch (_curActType)
		{
		case STOP:
			_player->_animation->setState(PlayerAnimation::State::stop_right);
			break;
		case WALK:
			_player->_animation->setState(PlayerAnimation::State::walk_right);
			break;
		case ACTION:
			_player->_animation->setState(PlayerAnimation::State::action_right);
		}
	}
}
