#pragma once
#include "ItemBase.h"

struct InventoryItem {
	ItemBase* _item;
	int _count;

	InventoryItem(ItemBase* item) :_item(item), _count(0) {};
};
class Inventory
{
private:
	vector<InventoryItem*> _items;
	int _inventorySize;
public:
	bool addItem(ItemBase* _item);

	int getSize() { return _inventorySize; };
	void setSize(int size) { _inventorySize = size; }
};
