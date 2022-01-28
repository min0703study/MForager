#include "Stdafx.h"
#include "UIManager.h"
#include "PlayerManager.h"
#include "CollectionManager.h"

HRESULT UIManager::init()
{
	//선택 상자 init
	_selectPtBox = new SelectPtBox({ 0,0 }, TILE_SIZE + 20, TILE_SIZE + 20);
	_selectPtBox->_animation->setAnimationImage("select_cursor", RES_SELECT_CURSOR_PATH, (TILE_SIZE + 20) * 5, (TILE_SIZE + 20), 5, 1);

	//커스텀 cursor
	IMAGEMANAGER->addFileImage("cursor", RES_CURSOR_PATH, 20, 20, true);

	addUI(_selectPtBox);

	return S_OK;
}

void UIManager::update()
{
}

void UIManager::release()
{
}

void UIManager::render(HDC hdc)
{
	IMAGEMANAGER->render("cursor", hdc, _currentPt.x, _currentPt.y);

	for (UI* ui : _uiList) {
		ui->play(hdc, _cameraManager->getCurPt());
	}
}

void UIManager::addUI(UI* ui)
{
	_uiList.push_back(ui);
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
	return ui->getRPt(_cameraManager->getCurPt());
}

RECT UIManager::getRelRect(UI* ui)
{
	return ui->getRRect(_cameraManager->getRcCamera());
}

RECT UIManager::getRelCenterPt(UI* ui)
{
	return ui->getRRect(_cameraManager->getRcCamera());
}

void UIManager::mouseMoveEvent(POINT& currentPoint)
{
	_currentPt = currentPoint;
	if (_playerManager->ptIsClickable(currentPoint)) { //사용자의 click 가능 범위에 있는지
		if (_collectionManager->isPtInCollect(currentPoint)) { //암석 위에 있는지
			_selectPtBox->setIsShowing(true);
			_selectPtBox->setApt(_collectionManager->getSelectCollect()->getAPt());
		};
	}
	else {
		_selectPtBox->setIsShowing(false);
		_collectionManager->setSelectFlag(false);
	}

	if (FindCenterPt(_playerManager->getPlayerRelRect()).x < currentPoint.x) {
		_cursorDirection = D_LEFT;
	}
	else {
		_cursorDirection = D_RIGHT;
	}
	
}

void UIManager::clickEvent(POINT & pt, bool isClickDown)
{
	if (isClickDown) {
		if (_collectionManager->_isSelect) {
			_playerManager->actionCollect();
		}
	}
}
