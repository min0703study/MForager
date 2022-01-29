#include "Stdafx.h"
#include "UIManager.h"
#include "PlayerManager.h"
#include "CollectionManager.h"

HRESULT UIManager::init()
{
	//커스텀 cursor
	IMAGEMANAGER->addFileImage("cursor", RES_CURSOR_PATH, 20, 20, true);
	_nightFocus = new NightFocus(_playerManager->getPlayerRelPt(), 1500, 1500);

	//선택 상자 init
	_selectPtBox = new SelectPtBox({ 0,0 }, TILE_SIZE + 20, TILE_SIZE + 20);
	_selectPtBox->_animation->setAnimationImage("select_cursor", RES_SELECT_CURSOR_PATH, (TILE_SIZE + 20) * 5, (TILE_SIZE + 20), 5, 1);
	addUI(_selectPtBox);

	for (int i = 0; i < 3; i++) {
		_lifeCount[i] = new Heart({i * 50 + 10, TILE_SIZE}, TILE_SIZE, TILE_SIZE);
		addFixedUI(_lifeCount[i]);
	}

	_hpGage = new ProgressBar({ 10, 10 }, TILE_SIZE * 1.3, TILE_SIZE * 0.5, DEFUALT_PLAYER_HP, DEFUALT_PLAYER_HP, C_PG_HP_TOP, C_PG_HP_BOTTOM);
	addFixedUI(_hpGage);

	return S_OK;
}

HRESULT UIManager::initCamera()
{
	_camera = new Camera;

	_camera->_xSize = CAMERASIZE_X;
	_camera->_ySize = CAMERASIZE_Y;
	_camera->_startPt = { 0,0 };
	_camera->_rcCamera = RectMake(_camera->_startPt, CAMERASIZE_X, CAMERASIZE_Y);

	return S_OK;
}

void UIManager::moveCamera(float x, float y, MOVE_DIRECTION mDirection)
{
	/*
	bool isCanMove;
	switch (mDirection) {
	case M_LEFT:
		isCanMove = _camera->_rcCamera.left > 0;
		break;
	case M_RIGHT:
		isCanMove = _camera->_rcCamera.right < _winsizeY;
		break;
	case M_TOP:
		isCanMove = _camera->_rcCamera.top > 0;
		break;
	case M_BOTTOM:
		isCanMove = _camera->_rcCamera.bottom < _winsizeY;
		break;
	}
	isCanMove = true;
	*/

	_camera->_startPt.x += x;
	_camera->_startPt.y += y;

	ChangeRect(_camera->_startPt, &_camera->_rcCamera, _camera->_xSize, _camera->_ySize);
}

void UIManager::update()
{
	_hpGage->setValue(_playerManager->getHp());

	for (int i = 0; i < 3; i++) {
		_lifeCount[i]->_animation->setState(_playerManager->getLifeCount() < (i + 1) ? HeartAnimation::State::blank : HeartAnimation::State::live);
	}
}

void UIManager::release()
{
}

void UIManager::render(HDC hdc)
{
	_map->play(hdc, _camera->_startPt);
	

	for (UI* ui : _uiList) {
		ui->play(hdc, _camera->_startPt);
	}

	_nightFocus->render(hdc, FindCenterPt(_playerManager->getPlayerRelRect()));

	for (DRECT rc : _developUi) {
		//RectangleMake(hdc, rc.getRRect(_cameraManager->getRcCamera()));
	}
	for (FixedUI* fUi : _fixedUiList) {
		fUi->play(hdc);
	}

	IMAGEMANAGER->render("cursor", hdc, _currentPt.x, _currentPt.y);
}

void UIManager::addFixedUI(FixedUI* ui)
{
	_fixedUiList.push_back(ui);
}

void UIManager::addUI(UI* ui)
{
	_uiList.push_back(ui);
}

void UIManager::addMap(UI * map)
{
	_map = map;
}

void UIManager::deleteUI(UI* ui)
{
	for (_iUiList = _uiList.begin(); _iUiList != _uiList.end(); _iUiList++) {
		if (*_iUiList == ui) {
			_uiList.erase(_iUiList);
			break;
		}
	}
}

POINTF UIManager::getRelPt(UI* ui) {
	return ui->getRPt(_camera->_startPt);
}

RECT UIManager::getRelRect(UI* ui)
{
	return ui->getRRect(_camera->_rcCamera);
}

RECT UIManager::getRelCenterPt(UI* ui)
{
	return ui->getRRect(_camera->_rcCamera);
}

POINTF UIManager::getAbsPt(POINTF pt) {
	pt.x = pt.x + _camera->_startPt.x;
	pt.y = pt.y + _camera->_startPt.y;
	return pt;
}

RECT UIManager::getRcCamera()
{
	return _camera->_rcCamera;
}


void UIManager::mouseMoveEvent(POINT& curPt)
{
	_currentPt = curPt;

	if (_playerManager->ptIsClickable(getAbsPt(curPt))) { //사용자의 click 가능 범위에 있는지
		if (_collectionManager->isPtInCollect(getAbsPt(curPt))) { //암석 위에 있는지
			_selectPtBox->setIsShowing(true);
			_selectPtBox->setApt(_collectionManager->getSelectCollect()->getHitPt());
		};
	}
	else {
		_selectPtBox->setIsShowing(false);
		_collectionManager->setSelectFlag(false);
	}

	if (CAMERASIZE_X/ 2 < curPt.x) {
		changeCursorDirection(C_RIGHT);
	}
	else {
		changeCursorDirection(C_LEFT);
	}
}

void UIManager::clickEvent(POINT & pt, bool isClickDown)
{
	if (isClickDown) {
		if (_collectionManager->_isSelect) {
			_playerManager->actionCollect();
		}
	}
	else {
		_playerManager->stopAction();
	}
}

//1초마다 호출
void UIManager::addGameTime()
{
	_nightFocus->addTime(1);
}


void UIManager::addDevelopUI(DRECT rc)
{
	_developUi.push_back(rc);
}

void UIManager::changeCursorDirection(CURSOR_DIRECTION direction) {
	if (_cursorDirection != direction) {
		_cursorDirection = direction;
		_playerManager->changeDirection();
	}
}