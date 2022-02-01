#include "Stdafx.h"
#include "MapManager.h"

HRESULT MapManager::init()
{
	_map = new Map();
	_map->init();
	
	_uiManager->map = _map;
	_uiManager->addMap(_map);

	return S_OK;
}

bool MapManager::rcCollsionCheck(RECT& rc)
{
	RECT tempRect;
	for (int i = 0; i < _map->_collisionTilesCount; i++) {
		if (IntersectRect(&tempRect, &_map->_collisionTiles[i]->rc, &rc)) {
			return true;
		}
	}
	return false;
}

bool MapManager::ptInCollsionTile(int x, int y)
{
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

void MapManager::update()
{
}
