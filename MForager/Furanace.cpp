#include "Stdafx.h"
#include "Furanace.h"

bool Furanace::makeConditionCheck(int makeItemId, Inventory* inventory)
{
	for (INGEDIENTS* ingediets : sFuranaceList) {
		if (ingediets->_craftingItemId == makeItemId) {
			for (INGEDIENTS::NeedItem* needItem : ingediets->_needItemList) {
				for (Inventory::InventoryItem* items : inventory->getItems()) {
					if (items->_item->getId() == needItem->_itemId) {
						if (items->_count > needItem->_itemCount) {
							return true;
						}
					}
				}
			}
		};	
	}

	return false;
}
