#include "Stdafx.h"
#include "UIManager.h"
#include "PlayerManager.h"
#include "CollectionManager.h"

HRESULT UIManager::init()
{
	_currentPtf = new PointF();

	//커스텀 cursor
	_cursor = new CustomCursor(
		_currentPtf,
		_camera->_cameraPos->_pt, 
		ETC::CURSOR::UI_INFO::X_SIZE, 
		ETC::CURSOR::UI_INFO::Y_SIZE);

	_nightFocus = new NightFocus({ CAMERA_R_X_SIZE /2.0f , CAMERA_R_Y_SIZE / 2.0f}, CAMERA_R_X_SIZE, CAMERA_R_Y_SIZE);

	//선택 상자 init
	_selectPtBox = new SelectPtBox({ 0,0 }, 70, 70);
	addUI(_selectPtBox);

	for (int i = 0; i < 3; i++) {
		_lifeCount[i] = new Heart(
			{
				MAIN::LIFE_COUNT::UI_INFO::START_X + (i * (MAIN::LIFE_COUNT::UI_INFO::X_SIZE + MAIN::LIFE_COUNT::UI_INFO::SPACE_SIZE)),
				MAIN::LIFE_COUNT::UI_INFO::START_Y
			}, 
			MAIN::LIFE_COUNT::UI_INFO::X_SIZE,
			MAIN::LIFE_COUNT::UI_INFO::Y_SIZE);

		addFixedUI(_lifeCount[i]);
	}

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
	//_hpGage->setValue(_playerManager->getHp());
	for (int i = 0; i < 3; i++) {
		_lifeCount[i]->_animation->init((int)(_playerManager->getLifeCount() < (i + 1) ? HeartAnimation::State::blank : HeartAnimation::State::live));
	}
}

void UIManager::release()
{
}

void UIManager::render(HDC hdc)
{
	//_map->play(hdc);
	
	for (UI* ui : map->_mapTiles) {
		ui->play(hdc);
	}
#if DEVELOP_MODE
	for (RECT* rc : _developUi) {
		RectangleMake(hdc, *rc);
	}
#endif
	_furanace->play(hdc);
	for (UI* ui : _uiList) {
		ui->play(hdc);
	}
	_nightFocus->render(hdc);

	for (FixedUI* fUi : _fixedUiList) {
		fUi->playFixed(hdc);
	}

	_nightFocus->render(hdc);

	wstring w = 
		L"레벨 " 
		+ to_wstring(_playerManager->_player->getLevel()) + 
		L" (" + 
		to_wstring(_playerManager->_player->getExpPoint()) + 
		L"/" +
		to_wstring(_playerManager->getMaxEtcPointOfLevel(_playerManager->_player->getLevel()))+
		L")";

	GDIPLUSMANAGER->drawTextCenter(hdc , w, _playerManager->_expGage->_absUiPos->getRectF(), 18, Gdiplus::Color(255, 255, 255));

	if (_playerManager->_player->_skillPoint > 0) {
		RECT rc = *_playerManager->_expGage->getARc();
		RectF temprc = RectF(rc.left, rc.top + 40, rc.right - rc.left, rc.bottom - rc.top);
		wstring s =
			L"스킬 포인트 :  "
			+ to_wstring(_playerManager->_player->_skillPoint);

		GDIPLUSMANAGER->drawTextCenter(hdc, s, temprc, 18, Gdiplus::Color(255, 191, 34));
	}
	

}

void UIManager::addFixedUI(FixedUI* ui)
{
	_fixedUiList.push_back(ui);
}

void UIManager::addUI(UI* ui)
{
	_uiList.push_back(ui);
}


void UIManager::addf(UI* ui)
{
	_furanace = ui;
}

void UIManager::addMap(UI * map)
{
	//_map = map;
}

void UIManager::deleteUI(UI* ui)
{
	
	for (vector<UI*>::iterator _iUiList = _uiList.begin(); _iUiList != _uiList.end(); _iUiList++) {
		if (*_iUiList == ui) {
			_uiList.erase(_iUiList);
			break;
		}
	}
	
}

void UIManager::mouseMoveEvent(POINT& curPt)
{
	_currentPtf->X = curPt.x;
	_currentPtf->Y = curPt.y;

	if (_playerManager->ptIsClickable(_cursor->getPos())) { //사용자의 click 가능 범위에 있는지
		if (_collectionManager->isPtInCollect(_cursor->getPos())) { //암석 위에 있는지ASDW
			_selectPtBox->setIsShowing(true);
			_selectPtBox->setARc(_collectionManager->getSelectCollect()->getHitARc());
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
			_selectPtBox->setIsShowing(_collectionManager->_isSelect);
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
	_playTimeSec += 1;

	if (_playTimeSec % 10 == 0) {
		_collectionManager->makeRandomCollection(false);
	}
}


void UIManager::addDevelopUI(LPRECT rc)
{
	_developUi.push_back(rc);
}

void UIManager::changeCursorDirection(CURSOR_DIRECTION direction) {
	if (_cursorDirection != direction) {
		_cursorDirection = direction;
		_playerManager->changeDirection();
	}
}