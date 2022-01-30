#pragma once
#include "ItemBase.h"

class Inventory
{
public:
	bool addItem(ItemBase* _item);
struct InventoryItem {
	ItemBase* _item;
	int _count;

	InventoryItem(ItemBase* item) :_item(item), _count(0) {};
};

	int getSize() { return _inventorySize; };
	void setSize(int size) { _inventorySize = size; }

	vector<InventoryItem*> getItems() { return _items; };
private:
	vector<InventoryItem*> _items;
	int _inventorySize;
};
