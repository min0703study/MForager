#include "Stdafx.h"
#include "Map.h"

HRESULT Map::init()
{
	this->Load();

	_collisionTilesCount = 0;
	for (TILE& tile : _tiles)
	{
		for (int cTile : COLLISION_GROUND) {
			if (tile.ground == cTile) {
				_collisionTiles[_collisionTilesCount] = &tile;
				_collisionTilesCount++;
				break;
			}
		}
	}

	return S_OK;
}

void Map::Load()
{
	LoadFile<TILE[TILE_COUNT]>(RES_SAVE_MAP_PATH, _tiles, sizeof(TILE) * TILE_COUNT);
	for (TILE& tile : _tiles)
	{
		if (tile.xIndex == -1) continue;
		tile.pt = POINTF(tile.xIndex * TILE_SIZES, tile.yIndex * TILE_SIZES);
		tile.rc = RectMakeF(tile.pt, TILE_SIZES, TILE_SIZES);
	}
}

void Map::release()
{
	for (TILE* tile : _collisionTiles) {
		SAFE_DELETE(tile);
	}
}

void Map::play(HDC hdc, POINTF cameraPt)
{
	for (TILE tile : _tiles) {
		RECT tempRect;
		//if (IntersectRect(&tempRect, &_cameraManager->getRcCamera(), &tile.rc)) {
			IMAGEMANAGER->setCurrentFrame(MAP_SPRITE, tile.ground % 9, tile.ground / 9);

			int x = tile.pt.x - cameraPt.x;
			int y = tile.pt.y - cameraPt.y;

			IMAGEMANAGER->frameRender("701", hdc, POINTF{ x, y });
		//}
	}
}

