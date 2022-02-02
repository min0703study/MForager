#include "Stdafx.h"
#include "Furanace.h"

bool Furanace::makeConditionCheck(int makeItemId, Inventory* inventory)
{
	for (INGEDIENTS* ingediets : _list) {
		if (ingediets->_craftingItemId == makeItemId) {
			for (INGEDIENTS::NeedItem* needItem : ingediets->_needItemList) {
				for (Inventory::InventoryItem* items : inventory->getItems()) {
					if (items->_item->getId() == needItem->_itemId) {
						if (items->_count >= needItem->_itemCount) {
							_isMaking = true;
							_makeTime = ingediets->_makeTime;
							_makeItem = new Stone({_absUiPos->getCenter().X, _absUiPos->getRectF().GetBottom()}, ITEM::STONE::COAL);
							items->_count -= needItem->_itemCount;
							return true;
						}
					}
				}
			}
		};	
	}
	return false;
}

ItemBase* Furanace::overMaking() {
	_isMaking = false;
	_makeTime = 0;

	return _makeItem;
}
