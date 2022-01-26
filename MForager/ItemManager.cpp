#include "Stdafx.h"
#include "ItemManager.h"

HRESULT ItemManager::init()
{
	vector<ItemBase*> test;
	test.push_back(new Stone({400,400}));
	test.push_back(new Stone({400,400}));
	createDropItem(test);
	return S_OK;
}

void ItemManager::release()
{
}

void ItemManager::update()
{
	for (DropItem* dItem : _dropItems) {

		dItem->_dropItem->_currentPt = { dItem->_dropItem->_currentPt.x + (dItem->_dropSpeed * dItem->_dropDirection) , dItem->_dropItem->_currentPt.y - (dItem->_dropSpeed + dItem->_gravity) };
		dItem->_dropItem->_animation->setStartPt(dItem->_dropItem->_currentPt);
		dItem->_gravity -= 0.4f;
	}
}

void ItemManager::render(HDC hdc)
{
	for (DropItem* dItem : _dropItems) {
		dItem->_dropItem->_animation->render(hdc);
	}
}

void ItemManager::createDropItem(vector<ItemBase*> dropItems)
{
	int i = 1;
	for (ItemBase* dItem : dropItems) {
		DropItem* dropItem = new DropItem(dItem, { 50,50 }, {60,60}, i);
		i *= -1;
		_dropItems.push_back(dropItem);
	}
}
