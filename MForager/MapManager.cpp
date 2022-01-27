#include "Stdafx.h"
#include "MapManager.h"

HRESULT MapManager::init()
{
	_map = new Map();
	_map->init();

	return S_OK;
}

bool MapManager::ptCollsionCheck(POINTF pt)
{
	for (int i = 0; i < _map->_collisionTilesCount; i++) {
		if (PtInRect(&_map->_collisionTiles[i]->rc, pt.toPOINT())) {
			return true;
		}
	}
	return false;
}

bool MapManager::ptInCollsionTile(int x, int y)
{
	RECT tempRect;
	for (int i = 0; i < _map->_collisionTilesCount; i++) {
		if (_map->_collisionTiles[i]->pt.x == x && _map->_collisionTiles[i]->pt.y == y) {
			return true;
		}
	}
	return false;
}

void MapManager::release(void)
{
	_map->release();
	delete _map;
}

void MapManager::render(HDC hdc)
{
	_map->render(hdc);
}

void MapManager::update()
{
}
