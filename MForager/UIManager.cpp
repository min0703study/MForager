#include "Stdafx.h"
#include "UIManager.h"
#include "PlayerManager.h"
#include "CollectionManager.h"

HRESULT UIManager::init()
{
	//커스텀 cursor
	IMAGEMANAGER->addFileImage("cursor", "Resource/images/cursor.bmp", 20, 20, true);
	_nightFocus = new NightFocus(_playerManager->getPlayerRelPt(), 1500, 1500);

	//선택 상자 init
	_selectPtBox = new SelectPtBox({ 0,0 }, TILE_SIZE + 20, TILE_SIZE + 20);
	_selectPtBox->_animation->setAnimationImage("select_cursor", RES_SELECT_CURSOR_PATH, (TILE_SIZE + 20) * 5, (TILE_SIZE + 20), 5, 1);
	addUI(_selectPtBox);

	for (int i = 0; i < 3; i++) {
		_lifeCount[i] = new Heart({(float)i * 50 + 10, (float)TILE_SIZE}, TILE_SIZE, TILE_SIZE);
		addFixedUI(_lifeCount[i]);
	}

	//_hpGage = new ProgressBar(new PointF{ 10, 10 }, TILE_SIZE * 1.3, TILE_SIZE * 0.5, DEFUALT_PLAYER_HP, DEFUALT_PLAYER_HP, C_PG_HP_TOP, C_PG_HP_BOTTOM);
	//addFixedUI(_hpGage);

	return S_OK;
}

HRESULT UIManager::initCamera()
{
	_camera = new Camera({0,0}, CAMERASIZE_X, CAMERASIZE_Y);
	UI::_cmRc = _camera->_cameraPos->_rc;
	return S_OK;
}

void UIManager::moveCamera(float x, float y, MOVE_DIRECTION mDirection)
{
	_camera->_cameraPos->addPt({x,y});
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
	_map->play(hdc);
	
	for (UI* ui : _uiList) {
		ui->play(hdc);
	}

	_nightFocus->render(hdc);

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

void UIManager::mouseMoveEvent(POINT& curPt)
{
	_currentPt = curPt;

	if (_playerManager->ptIsClickable(curPt)) { //사용자의 click 가능 범위에 있는지
		if (_collectionManager->isPtInCollect(curPt)) { //암석 위에 있는지
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