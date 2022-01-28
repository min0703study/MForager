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
			_hitGage[_selectIndex] = new ProgressBar(
				_collectObjects[_selectIndex]->getAPt(), 
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

bool CollectionManager::isPtInCollect(POINT pt)
{
	_isSelect = false;
	for (int i = 0; i < COLLECT_OBJECT_COUNT; i++) {
		if (SAFE_NULL_CHECK(_collectObjects[i])) continue;
		if (PtInRect(&_uiManager->getRelRect(_collectObjects[i]), pt)) {
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

void CollectionManager::render(HDC hdc)
{
}

void CollectionManager::makeRandomCollection()
{
	int x = 0;
	int y = 0;

	for (int i = 0; i < COLLECT_OBJECT_COUNT;) {
		x = RND->getInt(TILE_X_COUNT) * TILE_SIZE;
		y = RND->getInt(TILE_Y_COUNT) * TILE_SIZE;

		if (!_mapManager->ptInCollsionTile(x, y)) {
			_collectObjects[i] = new Rock(Rock::TYPE::ROCK, { x, y });
			_uiManager->addUI(_collectObjects[i]);
			i++;
		};
	}
}
