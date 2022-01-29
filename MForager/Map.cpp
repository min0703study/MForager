#include "Stdafx.h"
#include "Map.h"

HRESULT Map::init()
{
	IMAGEMANAGER->addFrameImage(
		B_GROUND_IMG_KEY,
		RES_MAP_SPRITE_PATH, 
		TILE_SIZE * B_GROUND_X_COUNT, 
		TILE_SIZE * B_GROUND_Y_COUNT, 
		B_GROUND_X_COUNT, 
		B_GROUND_Y_COUNT);
	
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
		tile.pt = POINTF(tile.xIndex * TILE_SIZE, tile.yIndex * TILE_SIZE);
		tile.rc = RectMakeF(tile.pt, TILE_SIZE, TILE_SIZE);
	}
}

void Map::render(HDC hdc)
{
	for (TILE tile : _tiles)
	{
		IMAGEMANAGER->setCurrentFrame(B_GROUND_IMG_KEY, tile.ground % B_GROUND_X_COUNT, tile.ground / B_GROUND_X_COUNT);
		IMAGEMANAGER->frameRender(B_GROUND_IMG_KEY, hdc, tile.pt);
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
			IMAGEMANAGER->setCurrentFrame(B_GROUND_IMG_KEY, tile.ground % B_GROUND_X_COUNT, tile.ground / B_GROUND_X_COUNT);

			int x = tile.pt.x - cameraPt.x;
			int y = tile.pt.y - cameraPt.y;

			IMAGEMANAGER->frameRender(B_GROUND_IMG_KEY, hdc, POINTF{ x, y });
		//}
	}
}

