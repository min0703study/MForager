#pragma once
#include "CollectionBase.h"

#define B_GROUND_IMG_KEY		"BASE_GROUND_IMG"
#define TILE_IMG_KEY			"TILE_IMG_KEY"

#define B_GROUND_X_COUNT	9
#define B_GROUND_Y_COUNT	5

class Map: public UI
{
public:
	Map() : UI({ 0,0 }, TILE_X_COUNT * TILE_SIZE, TILE_Y_COUNT * TILE_SIZE) {};

	TILE _tiles[TILE_COUNT];	//타일
	TILE* _collisionTiles[TILE_COUNT]; //충돌 타일
	int _collisionTilesCount; //충돌 타일 수

	HRESULT init();
	void Load();
	void render(HDC hdc);
	void release();

	virtual void play(HDC hdc, POINTF cameraPt);
};

/*

bool Map::ptInCollsionTile(int x, int y)
{
	RECT tempRect;
	for (int i = 0; i < _collisionTilesCount; i++) {
		if (_collisionTiles[i]->pt.x == x && _collisionTiles[i]->pt.y == y) {
			return true;
		}
	}
	return false;
}

bool Map::ptCollsionCheck(POINTF pt)
{
	for (int i = 0; i < _collisionTilesCount; i++) {
		if (PtInRect(&_collisionTiles[i]->rc, pt.toPOINT())) {
			return true;
		}
	}
	return false;
}

bool Map::ptCollsionCheck(int x, int y)
{
	return this->ptCollsionCheck({ x, y });
}

bool Map::RectCollsionCheck(RECT rc)
{
	RECT tempRect;
	for (int i = 0; i < _collisionTilesCount; i++) {
		if (IntersectRect(&tempRect, &rc, &_collisionTiles[i]->rc)) {
			return true;
		}
	}
	return false;
}
*/

