#include "Stdafx.h"

#include "ItemManager.h"
#include "PlayerManager.h"
#include "MapManager.h"
#include "CollectionManager.h"

#include "ProgressBar.h"
#include "UIManager.h"

void PlayerManager::addInventoryItem(ItemBase* item)
{
	//_inventory->_items.push_back(item);
}

HRESULT PlayerManager::init()
{
	_inventory = new Inventory;

	_player = new Player({(float)PLAYER::DEFAULT_VALUE::START_X, (float)PLAYER::DEFAULT_VALUE::START_Y},
		PLAYER::UI_INFO::X_SIZE,
		PLAYER::UI_INFO::Y_SIZE,
		PLAYER::DEFAULT_VALUE::HP,
		PLAYER::DEFAULT_VALUE::POWER,
		PLAYER::DEFAULT_VALUE::LIFE_COUNT);

	_player->setKey('A', 'D', 'W', 'S', 'F');
	
	_pickaxes = new Pickaxes(_player->getAPt(), 60, 60);
	
	_uiManager->addUI(_player);
	_uiManager->addUI(_pickaxes);

	//_uiManager->addDevelopUI(_player->getMoveRect());

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
		//_player->getMoveRect().getRRect(_uiManager->getRcCamera());
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
	return _player->getRRc();
}

RECT PlayerManager::getPlayerAbsRect() {
	return *_player->getARc();
}

PointF PlayerManager::getPlayerRelPt()
{
	return _player->getRPt();
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
	/*
	if (_uiManager->getCursorDirection() == C_LEFT) {
		switch (_curActType)
		{
		case STOP:
			_player->_animation->setState((int)PlayerAnimation::State::stop_left);
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
	*/
}
