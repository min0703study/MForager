#include "Stdafx.h"
#include "CollectionBase.h"

CollectionBase::CollectionBase(POINT pt, int maxHitGage, int xSizeOfTile, int ySizeOfTile) :
	_currentPt(pt),
	_maxHitGage(maxHitGage),
	_hitGage(maxHitGage),
	_xSizeOfTile(xSizeOfTile),
	_ySizeOfTile(ySizeOfTile),
	_isBeforDrop(false),
	_isHitStart(false)
{

}

bool CollectionBase::hit(int power)
{
	if (!_isHitStart) _isHitStart = !_isHitStart;
	_hitGage -= power;
	if (_hitGage <= 0) {
		_isBeforDrop = true;
	}

	return _isBeforDrop;
}

vector<ItemBase*> CollectionBase::getDropItem()
{
	vector<ItemBase*> _dropItem;
	_dropItem.push_back(new Stone(_currentPt));
	_dropItem.push_back(new Stone(_currentPt));
	return _dropItem;
}
