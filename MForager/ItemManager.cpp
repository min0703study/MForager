#include "Stdafx.h"
#include "PlayerManager.h"
#include "ItemManager.h"
#include "UIManager.h"

HRESULT ItemManager::init()
{
	return S_OK;
}

void ItemManager::update()
{
	for (DropItem* dItem : _dropItems) {
		if (!dItem->_isEndDrop && 
			dItem->_endPt.y > dItem->_dropItem->getAPt().y) {
			dItem->_dropItem->setApt({ dItem->_dropItem->getAPt().x + (dItem->_dropSpeed * dItem->_dropDirection) , dItem->_dropItem->getAPt().y - (dItem->_dropSpeed + dItem->_gravity) });
			dItem->_gravity -= 0.4f;
		}
		else {
			dItem->_isEndDrop = true;
			dItem->_dropRc = RectMake(dItem->_dropItem->getAPt(), 50, 50);
		}
	}
}

void ItemManager::render(HDC hdc)
{
	/*
	for (DropItem* dItem : _dropItems) {
		if(!dItem->_isDropToPlayer)
			dItem->_dropItem->_animation->render(hdc);
	}
	
	*/
}

void ItemManager::createDropItem(vector<ItemBase*> dropItems)
{
	int i = 1;
	for (ItemBase* dItem : dropItems) {
		DropItem* dropItem = new DropItem(dItem, {dItem->getAPt().x, dItem->getAPt().y + 20}, i);
		i *= -1;
		_uiManager->addUI(dItem);
		_dropItems.push_back(dropItem);
	}
}

void ItemManager::RcCollisionCheckForDropItem()
{
	RECT tempRect;
	for (DropItem* dropItem : _dropItems) {
		if (!dropItem->_isEndDrop || dropItem->_isDropToPlayer) continue;
		if (IntersectRect(&tempRect, &_playerManager->getPlayerRelRect(), &_uiManager->getRelRect(dropItem->_dropItem))) {
			dropItem->_isDropToPlayer = true;
			dropItem->_dropItem->setIsShowing(false);
		}
	}
}

void ItemManager::release()
{
}
