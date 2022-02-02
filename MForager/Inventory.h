#pragma once
#include "ItemBase.h"

class Inventory
{
public:

struct InventoryItem {
	ItemBase* _item;
	int _count;

	InventoryItem(ItemBase* item) :
		_item(item), 
		_count(1)
	{};
};
bool addItem(ItemBase* _item);

Inventory(): _inventorySize(16) {};

	vector<InventoryItem*> _items;
	int _inventorySize;

	int getSize() { return _inventorySize; };
	void setSize(int size) { _inventorySize = size; }

	vector<InventoryItem*> getItems() { return _items; };


	~Inventory();

};
