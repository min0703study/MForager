#include "Stdafx.h"
#include "ItemManager.h"

HRESULT ItemManager::init()
{
	return S_OK;
}

void ItemManager::update()
{
	for (DropItem* dItem : _dropItems) {
		if (!dItem->_isEndDrop && dItem->_endPt.y > dItem->_dropItem->_currentPt.y) {
			dItem->_dropItem->_currentPt = { dItem->_dropItem->_currentPt.x + (dItem->_dropSpeed * dItem->_dropDirection) , dItem->_dropItem->_currentPt.y - (dItem->_dropSpeed + dItem->_gravity) };
			dItem->_dropItem->_animation->setStartPt(dItem->_dropItem->_currentPt);
			dItem->_gravity -= 0.4f;
		}
		else {
			dItem->_isEndDrop = true;
			dItem->_dropRc = RectMake(dItem->_dropItem->_currentPt, 50, 50);
		}
	}
}

void ItemManager::render(HDC hdc)
{
	for (DropItem* dItem : _dropItems) {
		if(!dItem->_isDropToPlayer)
			dItem->_dropItem->_animation->render(hdc);
	}
}

void ItemManager::createDropItem(vector<ItemBase*> dropItems)
{
	int i = 1;
	for (ItemBase* dItem : dropItems) {
		DropItem* dropItem = new DropItem(dItem, {dItem->_currentPt.x, dItem->_currentPt.y + 20}, i);
		i *= -1;
		_dropItems.push_back(dropItem);
	}
}

void ItemManager::RcCollisionCheckForDropItem(RECT & rc)
{
	RECT tempRect;
	for (DropItem* dropItem : _dropItems) {
		if (!dropItem->_isEndDrop) continue;
		if (IntersectRect(&tempRect, &rc, &dropItem->_dropRc)) {
			dropItem->_isDropToPlayer = true;
		}
	}
}

void ItemManager::release()
{
}
