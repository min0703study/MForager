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
		if (PtInRect(&rectToCamera(_map->_collisionTiles[i]->rc), pt.toPOINT())) {
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


RECT MapManager::rectToCamera(RECT _rc)
{
	_rc.left = _rc.left - _cameraManager->getRcCamera().left;
	_rc.top = _rc.top - _cameraManager->getRcCamera().top;
	_rc.right = _rc.right - _cameraManager->getRcCamera().left;
	_rc.bottom = _rc.bottom - _cameraManager->getRcCamera().top;
	return _rc;
}


POINTF MapManager::ptToCamera(POINTF pt)
{
	pt.x = pt.x - _cameraManager->getCurPt().x;
	pt.y = pt.y - _cameraManager->getCurPt().y;
	return pt;
}

void MapManager::release(void)
{
	_map->release();
	delete _map;
}

void MapManager::render(HDC hdc)
{
	for (TILE tile:_map->_tiles) {
		RECT tempRect;
		if (IntersectRect(&tempRect, &_cameraManager->getRcCamera(), &tile.rc)) {
			IMAGEMANAGER->setCurrentFrame(B_GROUND_IMG_KEY, tile.ground % B_GROUND_X_COUNT, tile.ground / B_GROUND_X_COUNT);
			
			int x = tile.pt.x - _cameraManager->getCurPt().x;
			int y = tile.pt.y - _cameraManager->getCurPt().y;

			IMAGEMANAGER->frameRender(B_GROUND_IMG_KEY, hdc, POINTF{x, y});
		}
	}
}

void MapManager::update()
{
}
