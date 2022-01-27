#include "Stdafx.h"
#include "MenuManager.h"

HRESULT MenuManager::init()
{
	_isOpenMenu = false;
	_curMenu = M_INVENTORY;
	return S_OK;
}

void MenuManager::release(void)
{
}

void MenuManager::render(HDC hdc)
{
	if (_isOpenMenu) {
		switch (_curMenu)
		{
		case M_INVENTORY:
						
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
