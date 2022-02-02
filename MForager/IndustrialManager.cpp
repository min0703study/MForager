#include "Stdafx.h"
#include "IndustrialManager.h"
int i = 0;
HRESULT IndustrialManager::init()
{
	_furanace = new Furanace({MAP_C::UI_INFO::CAMERA_R_X_SIZE / 2.0f, 300 }, INDUSTRIAL::FURANACE::UI_INFO::X_SIZE, INDUSTRIAL::FURANACE::UI_INFO::Y_SIZE);
	_uiManager->addf(_furanace);
	isOpen = false;
	getFuranaceList(_furanace->_list);
	return S_OK;
}

void IndustrialManager::update()
{
	RECT tempRect;
	if (KEYMANAGER->isOnceKeyDown('E')) {
		if (IntersectRect(&tempRect, &_playerManager->getPlayerRelRect(), &_furanace->getPlayerCheckRect())) {
			isOpen = !isOpen;
			if (isOpen) {

			}
		}
	}

	if (_furanace->_isMaking) {
		_furanace->_makeTime--;
		if (_furanace->_makeTime == 0) {
			_itemManager->createDropItem(_furanace->overMaking());
		}
	}

}

void IndustrialManager::render(HDC hdc) {
	if (isOpen) {
		GDIPLUSMANAGER->DrawRectangle(hdc, 0, 0, MAP_C::UI_INFO::CAMERA_X_SIZE, MAP_C::UI_INFO::CAMERA_Y_SIZE);
		IMAGEMANAGER->render(to_string(RES::FURANACE_MENU), hdc, 
			INDUSTRIAL::FURANACE::MENU::UI_INFO::START_X,
			INDUSTRIAL::FURANACE::MENU::UI_INFO::START_Y);
	}


	if (_furanace->_isMaking) {
		if (_furanace->_makeTime % 50 == 0 || i == 0) {
			i = _furanace->_makeTime / 50;
		}
		wstring w = to_wstring(i);
		GDIPLUSMANAGER->drawTextCenter(hdc, w, _furanace->getRRc(), 18, Gdiplus::Color(255, 255, 255));
	}
}

void IndustrialManager::release()
{
}

void IndustrialManager::clickEvent(POINT & pt, bool isClickDown)
{
	if (isOpen && isClickDown) {
		isOpen = false;
		_furanace->makeConditionCheck(ITEM::STONE::COAL_ID, _playerManager->getInventory());
	}

}
