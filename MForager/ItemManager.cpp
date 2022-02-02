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
	for (vector<DropItem*>::iterator _iDropItem = _dropItems.begin(); _iDropItem != _dropItems.end();) {
		if ((*_iDropItem)->_isDropToPlayer) {
			_iDropItem = _dropItems.erase(_iDropItem);
		}
		else {
			_iDropItem++;
		}
	}
	for (vector<DropItem*>::iterator _iDropItem = _dropItems.begin(); _iDropItem != _dropItems.end(); _iDropItem++) {
		if ((*_iDropItem)->_isDropToPlayer) {
			_iDropItem = _dropItems.erase(_iDropItem);
		}
		if (!(*_iDropItem)->_isEndDrop &&
			(*_iDropItem)->_endPt.y > (*_iDropItem)->_dropItem->getAPt()->Y) {
			(*_iDropItem)->_dropItem->setApt(
				{ (*_iDropItem)->_dropItem->getAPt()->X + ((*_iDropItem)->_dropSpeed * (*_iDropItem)->_dropDirection),
				(*_iDropItem)->_dropItem->getAPt()->Y - ((*_iDropItem)->_dropSpeed + (*_iDropItem)->_gravity) });
			(*_iDropItem)->_gravity -= 0.4f;
			
		}
		else {
			(*_iDropItem)->_isEndDrop = true;
			(*_iDropItem)->_dropRc = RectMake(*(*_iDropItem)->_dropItem->getAPt(), 50, 50);
		}
	}
}

void ItemManager::createDropItem(vector<ItemBase*> dropItems)
{
	int i = 1;
	for (ItemBase* dItem : dropItems) {
		DropItem* dropItem = new DropItem(dItem, {dItem->getAPt()->X, dItem->getAPt()->Y + 20}, i);
		i *= -1;
		_uiManager->addUI(dItem);
		_dropItems.push_back(dropItem);
	}
}

void ItemManager::createDropItem(ItemBase* dropItems)
{
	DropItem* dropItem = new DropItem(dropItems, { dropItems->getAPt()->X, dropItems->getAPt()->Y + 20 }, RND->getFlag() ? 1: -1);
	_uiManager->addUI(dropItems);
	_dropItems.push_back(dropItem);
}

void ItemManager::CollisionCheckForDropItem(RECT& playerRRc)
{
	RECT tempRect;
	for (DropItem* dropItem : _dropItems) {
		if (!dropItem->_isEndDrop || dropItem->_isDropToPlayer) continue;
		if (IntersectRect(&tempRect, &playerRRc, &dropItem->_dropItem->getRRc())) {
			dropItem->_isDropToPlayer = true;
			dropItem->_dropItem->setIsShowing(false);
			
			_playerManager->addInventoryItem(dropItem->_dropItem);
			_uiManager->deleteUI(dropItem->_dropItem);
			break;
		}
	}
}

void ItemManager::release()
{
}
