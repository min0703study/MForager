#include "Stdafx.h"

#include "ItemManager.h"
#include "PlayerManager.h"
#include "MapManager.h"
#include "CollectionManager.h"

#include "ProgressBar.h"
#include "UIManager.h"

void PlayerManager::addInventoryItem(ItemBase* item)
{
	_inventory->addItem(item);
}

HRESULT PlayerManager::init()
{
#if DEVELOP_MODE
	_playerClickableRc = new RECT();
	_playerMoveRc = new RECT();

	_uiManager->addDevelopUI(_playerClickableRc);
	_uiManager->addDevelopUI(_playerMoveRc);
#endif
	_inventory = new Inventory;

	_player = new Player({
		PLAYER::UI_INFO::START_X, 
		PLAYER::UI_INFO::START_Y},
		PLAYER::UI_INFO::X_SIZE,
		PLAYER::UI_INFO::Y_SIZE,
		PLAYER::DEFAULT_VALUE::HP,
		PLAYER::DEFAULT_VALUE::POWER,
		PLAYER::DEFAULT_VALUE::LIFE_COUNT);

	_player->setKey('A', 'D', 'W', 'S', 'F');
	setState(STOP, true);

	_pickaxes = new Pickaxes(_player->getAPt(), 50, 50);
	
	_uiManager->addUI(_player);
	_uiManager->addUI(_pickaxes);

	_hpGage = new ProgressBar(
		{
			MAIN::HP_PROGRESS_BAR::UI_INFO::START_X,
			MAIN::HP_PROGRESS_BAR::UI_INFO::START_Y 
		},
		MAIN::HP_PROGRESS_BAR::UI_INFO::X_SIZE,
		MAIN::HP_PROGRESS_BAR::UI_INFO::Y_SIZE,
		PLAYER::DEFAULT_VALUE::HP,
		PLAYER::DEFAULT_VALUE::HP,
		MAIN::HP_PROGRESS_BAR::UI_INFO::TCOLOR,
		MAIN::HP_PROGRESS_BAR::UI_INFO::BCOLOR);


	_expGage = new ProgressBar(
		{
			MAIN::EXP_PROGRESS_BAR::UI_INFO::START_X,
			MAIN::EXP_PROGRESS_BAR::UI_INFO::START_Y
		},
		MAIN::EXP_PROGRESS_BAR::UI_INFO::X_SIZE,
		MAIN::EXP_PROGRESS_BAR::UI_INFO::Y_SIZE,
		getMaxEtcPointOfLevel(_player->getLevel()),
		_player->getExpPoint(),
		MAIN::EXP_PROGRESS_BAR::UI_INFO::TCOLOR,
		MAIN::EXP_PROGRESS_BAR::UI_INFO::BCOLOR);

	_toolbars.push_back(new Toolbar(
		(Bundlable*)_pickaxes,
		PointF{ (REAL)MAP_C::UI_INFO::CAMERA_X_SIZE / 2 - MAIN::TOOLBAR::UI_INFO::X_SIZE / 2, (REAL)MAIN::TOOLBAR::UI_INFO::START_Y },
		MAIN::TOOLBAR::UI_INFO::X_SIZE,
		MAIN::TOOLBAR::UI_INFO::Y_SIZE
	));

	for (Toolbar* toolbar : _toolbars) {
		_uiManager->addFixedUI(toolbar);
	}

	_uiManager->addFixedUI(_hpGage);
	_uiManager->addFixedUI(_expGage);

	//_uiManager->addDevelopUI(_player->getMoveRect());

	return S_OK;
}

void PlayerManager::update()
{
#if DEVELOP_MODE
	RECT rc = _player->getMoveRect();
	_playerMoveRc->left = rc.left;
	_playerMoveRc->top = rc.top;
	_playerMoveRc->right = rc.right;
	_playerMoveRc->bottom = rc.bottom;

	RECT crc = _player->getClickableRect();
	_playerClickableRc->left = crc.left;
	_playerClickableRc->top = crc.top;
	_playerClickableRc->right = crc.right;
	_playerClickableRc->bottom = crc.bottom;
#endif
	for (vector<Inventory::InventoryItem*>::iterator _item = _inventory->_items.begin(); _item != _inventory->_items.end();) {
		if ((*_item)->_count <= 0) {
			_item = _inventory->_items.erase(_item);
		}
		else {
			_item++;
		}
	}

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

	if (_actionTime > 0) {
		_actionTime--;
		if (_actionTime == 0) {
			_isActionIng = false;
			stopAction();
		}
	}

	_hpGage->setValue(_player->getHp());
	_expGage->setValue(_player->getExpPoint());

}

void PlayerManager::move(int addX, int addY, MOVE_DIRECTION mDirection)
{
	setState(WALK, true);

	RECT rc = _player->getMoveRect();

	rc.left += addX;
	rc.right += addX;
	rc.top += addY;
	rc.bottom += addY;

	if (!_mapManager->rcCollsionCheck(rc)) {
		_uiManager->moveCamera(addX, addY, mDirection);
		_player->move(addX, addY);

		_itemManager->CollisionCheckForDropItem(rc);
	}
}

void PlayerManager::release()
{
	SAFE_DELETE(_player);
}

void PlayerManager::actionCollect()
{
	if (_isActionIng) return;
	
	_actionTime = DEFAULT_ACTION_TIME;
	_isActionIng = true;

	setState(ACTION, true);
	_pickaxes->startAction();
	_player->actionCollect();
	if (_collectionManager->hitCollect(_player->_power)) {
		addExp();
	};
}

void PlayerManager::stopAction()
{
	setState(ACTION, false);
	if (_actionTime > 0) return;
	_pickaxes->stopAction();
}

bool PlayerManager::ptIsClickable(POINT rPt)
{
	return PtInRect(&_player->getClickableRect(), rPt);
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
void PlayerManager::addExp()
{
	_player->_curExpPoint += PLAYER::DEFAULT_VALUE::HIT_EXP;
	if (_player->_curExpPoint > getMaxEtcPointOfLevel(_player->_level)) {
		_player->_level++;
		_player->_curExpPoint = 0;
		_expGage->setValue(getMaxEtcPointOfLevel(_player->_level), 0);
		_player->_skillPoint++;
	}
}
int PlayerManager::getMaxEtcPointOfLevel(int level)
{
	switch(level) {
	case 1:
		return 80;
	case 2:
		return 91;
	case 3:
		return 106;
	case 4:
		return 121;
	case 5:
		return 141;
	}
}

void PlayerManager::setState(ACTION_TYPE act, bool isStart)
{
	_curActType = isStart ? act : STOP;
	changeAnimation();
}

void PlayerManager::changeDirection() {
	_pickaxes->changeDirect();
	changeAnimation();
}

void PlayerManager::changeAnimation()
{
	
	if (_uiManager->getCursorDirection() == C_LEFT) {
		switch (_curActType)
		{
		case STOP:
			_player->_animation->chageState((int)AniState::stop_left);
			break;
		case WALK:
			_player->_animation->chageState((int)AniState::walk_left);
			break;
		case ACTION:
			_player->_animation->chageState((int)AniState::action_left);
			break;
		}
	}
	else {
		switch (_curActType)
		{
		case STOP:
			_player->_animation->chageState((int)AniState::stop_right);
			break;
		case WALK:
			_player->_animation->chageState((int)AniState::walk_right);
			break;
		case ACTION:
			_player->_animation->chageState((int)AniState::action_right);
		}
		
	}
	
}

int PlayerManager::eatFood(int energe)
{
	_player->_currentHp += energe;
	return 0;
}
