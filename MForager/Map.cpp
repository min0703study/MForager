#include "Stdafx.h"
#include "Map.h"

HRESULT Map::init()
{
	this->load();
	return S_OK;
}

void Map::load()
{
	LoadFile<TILE[TILE_COUNT]>(RES_SAVE_MAP_PATH, _tiles, sizeof(TILE) * TILE_COUNT);
	for (TILE& tile : _tiles)
	{
		if (tile.xIndex == -1) continue;
		tile.pt = POINTF(tile.xIndex * TILE_SIZES, tile.yIndex * TILE_SIZES);
		tile.rc = RectMakeF(tile.pt, TILE_SIZES, TILE_SIZES);
	}

	for (int i = 0; i < TILE_COUNT; i++) {
		MapTile* mapTile = new MapTile(
			_tiles[i].ground,
			_tiles[i].ground % SPRITE_X_COUNT,
			_tiles[i].ground / SPRITE_X_COUNT,
			PointF(_tiles[i].xIndex * TILE_SIZE, _tiles[i].yIndex * TILE_SIZE),
			TILE_SIZE,
			TILE_SIZE);

		_mapTiles.push_back(mapTile);

		for (int cTile : COLLISION_GROUND) {
			if (_tiles[i].ground == cTile) {
				_collisionTile.push_back(mapTile);
				break;
			}
		}
	}
}

void Map::release()
{

}

void Map::play(HDC hdc)
{
	for (TILE tile : _tiles) {
		RECT tempRect;
		IMAGEMANAGER->setCurrentFrame(MAP_SPRITE, tile.ground % 9, tile.ground / 9);

		int x = tile.pt.x - _cmRc->left;
		int y = tile.pt.y - _cmRc->top;

		IMAGEMANAGER->frameRender(MAP_SPRITE, hdc, POINTF{ x, y });
	}
}

