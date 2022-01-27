#pragma once
#include "CollectionBase.h"

#define B_GROUND_IMG_KEY		"BASE_GROUND_IMG"
#define TILE_IMG_KEY			"TILE_IMG_KEY"

#define B_GROUND_X_COUNT	9
#define B_GROUND_Y_COUNT	4

class Map
{
public:
	TILE _tiles[TILE_COUNT];
	TILE* _collisionTiles[TILE_COUNT];
	int _collisionTilesCount;

	HRESULT init();

	void Load();
	void render(HDC hdc);
	void release();

	bool ptInCollsionTile(int x, int y);

	bool ptCollsionCheck(POINTF pt);
	bool ptCollsionCheck(int x, int y);
	
	bool RectCollsionCheck(RECT rc);

};

