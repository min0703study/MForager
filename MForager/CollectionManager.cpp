#include "Stdafx.h"
#include "CollectionManager.h"
#include "ItemManager.h"
#include "MapManager.h"
#include "UIManager.h"

HRESULT CollectionManager::init()
{
#if DEVELOP_MODE
	for (int i = 0; i < COLLECT_OBJECT_COUNT; i++) {
		_collectBox[i] = new RECT;
		//_uiManager->addDevelopUI(_collectBox[i]);
	}
#endif

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
#if DEVELOP_MODE
	for (int i = 0; i < COLLECT_OBJECT_COUNT; i++) {
		//copyRect(_collectBox[i], _collectObjects[i]->getHitRRect());
	}
#endif
}

bool CollectionManager::hitCollect(int power)
{
	if (_collectObjects[_selectIndex]->hit(power)) {
		_itemManager->createDropItem(_collectObjects[_selectIndex]->getDropItem());
		_uiManager->deleteUI(_collectObjects[_selectIndex]);
		SAFE_DELETE(_collectObjects[_selectIndex]);

		_uiManager->deleteUI(_hitGage[_selectIndex]);
		SAFE_DELETE(_hitGage[_selectIndex]);

		_selectIndex = -1;
		_isSelect = false;

		return true;
	}
	else {
		if (SAFE_NULL_CHECK(_hitGage[_selectIndex])) {
			_hitGage[_selectIndex] = new ProgressBar(
				_collectObjects[_selectIndex]->getProgressAPt(),
				COLLECT::UI_INFO::PROGRESS::X_SIZE,
				COLLECT::UI_INFO::PROGRESS::Y_SIZE,
				_collectObjects[_selectIndex]->_maxHitGage,
				_collectObjects[_selectIndex]->_hitGage,
				COLLECT::UI_INFO::PROGRESS::TCOLOR,
				COLLECT::UI_INFO::PROGRESS::BCOLOR);

			_uiManager->addUI(_hitGage[_selectIndex]);
		}
		_hitGage[_selectIndex]->setValue(_collectObjects[_selectIndex]->_hitGage);
		return false;
	}
}

bool CollectionManager::isFull()
{
	for (int i = 0; i < COLLECT_OBJECT_COUNT; i++) {
		if (_collectObjects[i] == nullptr) {
			return false;
		}
		_collectObjects[i]->_isBeforDrop;
	}
	return true;
}

bool CollectionManager::isPtInCollect(POINT pt)
{
	_isSelect = false;
	for (int i = 0; i < COLLECT_OBJECT_COUNT; i++) {
		if (SAFE_NULL_CHECK(_collectObjects[i])) continue;
		if (PtInRect(&_collectObjects[i]->getHitRRect(), pt)) {
			_isSelect = true;
			_selectIndex = i;
		}
	}
	return _isSelect;
}


bool CollectionManager::isPtAreadyObject(int x, int y)
{
	for (int i = 0; i < COLLECT_OBJECT_COUNT; i++) {
		if (SAFE_NULL_CHECK(_collectObjects[i])) continue;

		PointF rc = _collectObjects[i]->getHitAPt();
		if ((int)rc.X == x && (int)rc.Y == y) {
			return true;
		}
	}
	return false;
}

CollectionBase* CollectionManager::getSelectCollect()
{
	return _collectObjects[_selectIndex];
}

void CollectionManager::makeRandomCollection(bool isInit)
{
	float x = 0;
	float y = 0;

	int i = 0;
	while (isInit ? i < COLLECT_OBJECT_COUNT : !isFull()) {
		if (_collectObjects[i] != nullptr) {
			i++;
			continue;
		}

		x = RND->getInt(TILE_X_COUNT) * TILE_SIZE;
		y = RND->getInt(TILE_Y_COUNT) * TILE_SIZE;
		
		if (!_mapManager->ptInCollsionTile(x, y)&& !isPtAreadyObject(x, y)) {
			if (PtInRect(_uiManager->_furanace->getARc(), {(long)x,(long)y})) continue;
			switch (RND->getInt(6)) {
			case 0:
				_collectObjects[i] = new Rock({ x, y }, COLLECT::ROCK::TYPE::IRON);
				break;
			case 1:
			case 2:
				_collectObjects[i] = new Rock({ x, y }, COLLECT::ROCK::TYPE::ROCK);
				break;
			case 3:
			case 4:
				_collectObjects[i] = new Tree({ x, y }, COLLECT::TREE::TYPE::NOMAL);
				break;
			case 5:
				_collectObjects[i] = new BerryBush({ x, y }, COLLECT::BERRY_BUSH::TYPE::NOMAL);
				break;
			};
			_uiManager->addUI(_collectObjects[i]);
			i++;
			if (!isInit) break;
		}
	}
}
