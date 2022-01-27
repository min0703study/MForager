#include "Stdafx.h"
#include "CollectionManager.h"

HRESULT CollectionManager::init()
{
	_hitGage = new ProgressBar(TILE_SIZE, TILE_SIZE * 0.4, C_PG_COLLECT_GAGE_TOP, C_PG_COLLECT_GAGE_BOTTOM);
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
	makeRandomCollection();
}

bool CollectionManager::loadSaveFile()
{
	return false;
}

void CollectionManager::makeRandomCollection(int x, int y)
{
	for (int i = 0; i < COLLECT_OBJECT_COUNT; i++) {
		if (_collectObjects[i] == nullptr) {
			_collectObjects[i] = new Rock(Rock::TYPE::ROCK, { x, y });
			break;
		}
	}
}

bool CollectionManager::hitCollect(int power)
{
	return _collectObjects[_selectIndex]->hit(power);
}

vector<ItemBase*> CollectionManager::getDropItem()
{
	vector<ItemBase*> returnVector = _collectObjects[_selectIndex]->getDropItem();
	delete _collectObjects[_selectIndex];
	
	_isSelect = false;
	_selectIndex = - 1;
	
	return returnVector;
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

CollectionBase * CollectionManager::getPtInCollect(POINT pt)
{
	for (int i = 0; i < COLLECT_OBJECT_COUNT; i++) {
		if (PtInRect(&_collectObjects[i]->_currentRc, pt)) {
			_isSelect = true;
			_selectIndex = i;
			return _collectObjects[i];
		}
	}

	_isSelect = false;
	return nullptr;
}

CollectionBase* CollectionManager::getSelectCollect()
{
	return _collectObjects[_selectIndex];
}

void CollectionManager::render(HDC hdc)
{
	for (int i = 0; i < COLLECT_OBJECT_COUNT; i++) {
		if (_collectObjects[i] != nullptr && !_collectObjects[i]->_isBeforDrop) {
			_collectObjects[i]->_animation->render(hdc);

			if (_collectObjects[i]->_isHitStart) {
				_hitGage->setValue({_collectObjects[i]->_currentRc.left , _collectObjects[i]->_currentRc.bottom + 10}, 
					_collectObjects[i]->_maxHitGage, 
					_collectObjects[i]->_hitGage);
				_hitGage->render(hdc);
			}
		}
	}
}

void CollectionManager::makeRandomCollection()
{
	int x = 0;
	int y = 0;

	while (!isFull()) {
		x = RND->getInt(TILE_X_COUNT) * TILE_SIZE;
		y = RND->getInt(TILE_Y_COUNT) * TILE_SIZE;

		if (!_mapManager->ptInCollsionTile(x, y)) {
			makeRandomCollection(x, y);
		};
	}
}
