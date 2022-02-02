#include "Stdafx.h"
#include "Inventory.h"

bool Inventory::addItem(ItemBase * _item)
{
	bool isAddItem = false;
	for (InventoryItem* inven: _items) {
		if (inven->_item->getId() == _item->getId()) {
			inven->_count++;
			isAddItem = true;
			break;
		}
	}

	if (!isAddItem && _items.size() < _inventorySize) {
		_items.push_back(new InventoryItem(_item));
		isAddItem = true;
	}

	return isAddItem;
}

Inventory::~Inventory()
{
	for (vector<InventoryItem*>::iterator _item = _items.begin(); _item != _items.end();) {
		_item = _items.erase(_item);
		SAFE_DELETE(*_item);
	}
}
