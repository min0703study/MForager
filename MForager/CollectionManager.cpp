#include "Stdafx.h"
#include "CollectionManager.h"
#include "ItemManager.h"
#include "MapManager.h"
#include "UIManager.h"

HRESULT CollectionManager::init()
{
	return S_OK;
}

void CollectionManager::release()
{
	for (int i = 0; i < COLLECT_OBJECT_COUNT; i++) {
		SAFE_DELETE(_collectObjects[i]);
	}
}

void CollectionManager::update()
{

}

void CollectionManager::hitCollect(int power)
{

	if (_collectObjects[_selectIndex]->hit(power)) {
		_itemManager->createDropItem(_collectObjects[_selectIndex]->getDropItem());
		_uiManager->deleteUI(_collectObjects[_selectIndex]);
		SAFE_DELETE(_collectObjects[_selectIndex]);

		_uiManager->deleteUI(_hitGage[_selectIndex]);
		SAFE_DELETE(_hitGage[_selectIndex]);

		_selectIndex = -1;
		_isSelect = false;
	}
	else {
		if (SAFE_NULL_CHECK(_hitGage[_selectIndex])) {
			_hitGage[_selectIndex] = new ProgressBar (
				_collectObjects[_selectIndex]->getProgressPt(), 
				TILE_SIZE, 
				TILE_SIZE * 0.4,
				_collectObjects[_selectIndex]->_maxHitGage,
				_collectObjects[_selectIndex]->_hitGage,
				C_PG_COLLECT_GAGE_TOP, 
				C_PG_COLLECT_GAGE_BOTTOM);
			_uiManager->addUI(_hitGage[_selectIndex]);
		}

		_hitGage[_selectIndex]->setValue(_collectObjects[_selectIndex]->_hitGage);
	}
}

bool CollectionManager::isFull()
{
	for (int i = 0; i < COLLECT_OBJECT_COUNT; i++) {
		if (_collectObjects[i] == nullptr) {
			return false;
		}
	}
	return true;
}

bool CollectionManager::isPtInCollect(POINTF pt)
{
	_isSelect = false;
	for (int i = 0; i < COLLECT_OBJECT_COUNT; i++) {
		if (SAFE_NULL_CHECK(_collectObjects[i])) continue;
		if (PtInRect(&_collectObjects[i]->getHitRect(), pt.toPOINT())) {
			_isSelect = true;
			_selectIndex = i;
		}
	}
	return _isSelect;
}

CollectionBase* CollectionManager::getSelectCollect()
{
	return _collectObjects[_selectIndex];
}

void CollectionManager::makeRandomCollection()
{
	int x = 0;
	int y = 0;

	for (int i = 0; i < COLLECT_OBJECT_COUNT;) {
		x = RND->getInt(TILE_X_COUNT) * TILE_SIZE;
		y = RND->getInt(TILE_Y_COUNT) * TILE_SIZE;

		if (!_mapManager->ptInCollsionTile(x, y)) {
			switch(RND->getInt(3)) {
				case 0:
					_collectObjects[i] = new Rock({ x, y }, Rock::TYPE::IRON);
					break;
				case 1:
					_collectObjects[i] = new Rock({ x, y },Rock::TYPE::ROCK);
					break;
				case 2:
					_collectObjects[i] = new Tree({ x, y }, Tree::TYPE::NOMAL);
					break;
			};
			_uiManager->addUI(_collectObjects[i]);
			i++;
		};
	}
}
