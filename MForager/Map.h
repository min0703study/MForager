#pragma once
#include "CollectionBase.h"

using namespace UI_INFO::MAP;

class Map: public UI
{
public:
	Map() : UI({ 0,0 }, X_SIZE, Y_SIZE) {};

	TILE _tiles[TILE_COUNT];	//타일
	TILE* _collisionTiles[TILE_COUNT]; //충돌 타일
	int _collisionTilesCount; //충돌 타일 수

	HRESULT init();
	void Load();
	void release();

	virtual void play(HDC hdc);
};
