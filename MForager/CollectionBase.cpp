#include "Stdafx.h"
#include "CollectionBase.h"

CollectionBase::CollectionBase(PointF hitPt, int xSizeOfTile, int ySizeOfTile):
	UI({ hitPt.X - TILE_SIZE * (xSizeOfTile - 1), hitPt.Y - (TILE_SIZE * (ySizeOfTile - 1)) },
	xSizeOfTile * TILE_SIZE,
	ySizeOfTile * TILE_SIZE,
	new CollectAnimation),
	_hitPt(hitPt),
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
	return vector<ItemBase*>();
}

void CollectionBase::setAnimationImageAuto(CollectAnimation::State state, string key, char * fileName, int frameXCount, int frameYCount) {
	_animation->setAnimationImage(
		(int)state, 
		key,
		fileName, 
		getWidth(),
		getHeight(),
		frameXCount, 
		frameXCount
	);
}
