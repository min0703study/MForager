#include "Stdafx.h"
#include "MenuManager.h"

HRESULT MenuManager::init()
{
	_isOpenMenu = false;
	_curMenu = M_INVENTORY;

	_frameRect = new RECT(RectMake(CAMERASIZE_X / 2 - 20, CAMERASIZE_Y / 2, 
		INVENTORY::UI_INFO::FRAME_X_SIZE, 
		INVENTORY::UI_INFO::FRAME_Y_SIZE, 
		true));


	for (int i = 0; i < INVENTROY_COUNT; i++) {
		_itemBoxList.push_back(new InventoryBox (
			{(REAL)_frameRect->left + (i % INVENTORY::UI_INFO::BOX_X_COUNT) * (INVENTORY::UI_INFO::BOX_SIZE_X + INVENTORY::UI_INFO::BOX_SPACE), (REAL)_frameRect->top + (i / INVENTORY::UI_INFO::BOX_X_COUNT) * (INVENTORY::UI_INFO::BOX_SIZE_Y + INVENTORY::UI_INFO::BOX_SPACE) }
			,INVENTORY::UI_INFO::BOX_SIZE_X
			,INVENTORY::UI_INFO::BOX_SIZE_Y));
	}
	
	int i = 0;

	return S_OK;
}

void MenuManager::release(void)
{
}

void MenuManager::render(HDC hdc)
{
	if (_isOpenMenu) {
		int i = 0;
		switch (_curMenu)
		{
		
		case M_INVENTORY:
			GDIPLUSMANAGER->DrawRectangle(hdc, 0,0, MAP_C::UI_INFO::CAMERA_X_SIZE, MAP_C::UI_INFO::CAMERA_Y_SIZE);
			for (FixedUI* ib: _itemBoxList) {
				ib->playFixed(hdc);
			}

			for (Inventory::InventoryItem* item : _playerManager->getInventory()->getItems()) {
				PointF pf = *_itemBoxList[i]->getAPt();
				pf.X += 10;
				pf.Y += 10;
				item->_item->setApt(pf);
				item->_item->play(hdc, pf);
				item->_item->_animation->render(hdc, *item->_item->getAPt());
				GDIPLUSMANAGER->drawText(hdc, to_wstring(item->_count),*_itemBoxList[i]->getAPt(), 24, Gdiplus::Color(255,255,255));
				i++;
			};
			break;
		default:
			break;
		}
	}
}

void MenuManager::update()
{
	_isOpenMenu = KEYMANAGER->isToggleKey(VK_ESCAPE);
}

void MenuManager::mouseClickEvent(POINT & currentPoint, bool isClickDown)
{
	if (!isClickDown) return;
	if (_isOpenMenu) {
		for (int i = 0; i < 16; i++) {
			if (PtInRect(_itemBoxList[i]->getARc(), currentPoint)) {
				if (i < _playerManager->getInventory()->getItems().size()) {
					if (_playerManager->getInventory()->getItems()[i]->_item->_ItemId == ITEM::FOOD::BERRY_ID) {
						Food* fd = (Food*)_playerManager->getInventory()->getItems()[i]->_item;
						_playerManager->getInventory()->getItems()[i]->_count--;
						_playerManager->eatFood(fd->getEnergy());
						//_playerManager->getInventory()->getItems().erase(_playerManager->getInventory()->getItems().begin() + i);
						//delete fd;
					}
				}
			};
		}
	}
}
