#include "Stdafx.h"
#include "CollectionBase.h"

CollectionBase::CollectionBase(POINTF hitPt, int xSizeOfTile, int ySizeOfTile):
	UI({ hitPt.x - TILE_SIZE * (xSizeOfTile - 1), hitPt.y - (TILE_SIZE * (ySizeOfTile - 1)) },
	xSizeOfTile * TILE_SIZE,
	ySizeOfTile * TILE_SIZE),
	_hitPt(hitPt),
	_xSizeOfTile(xSizeOfTile),
	_ySizeOfTile(ySizeOfTile),
	_isBeforDrop(false),
	_isHitStart(false)
{
	initAnimation();
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

void CollectionBase::initAnimation()
{
	_animation = new CollectAnimation();
	_bAnimation = _animation;
}

void CollectionBase::setAnimationImageAuto(CollectAnimation::State state, string key, char * fileName, int frameXCount, int frameYCount) {
	_animation->setAnimationImage(
		state, 
		key,
		fileName, 
		_width,
		_height,
		frameXCount, 
		frameXCount
	);
}
