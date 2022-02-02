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
	for (UI* cTile: _map->_collisionTile) {
		if (IntersectRect(&tempRect, &cTile->getRRc(), &rc)) {
			return true;
		}
	}
	return false;
}

bool MapManager::ptInCollsionTile(int rX, int rY)
{
	for (UI* cTile : _map->_collisionTile) {
		if (cTile->getAPt()->X == rX && cTile->getAPt()->Y == rY) {
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
