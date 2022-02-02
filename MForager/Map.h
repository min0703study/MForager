#pragma once

#include "MapTile.h"

using namespace MAP_C::UI_INFO;

class Map: public UI
{
public:
	Map() : UI({ 0,0 }, X_SIZE, Y_SIZE, nullptr) {};

	vector<UI*> _mapTiles;
	vector<UI*> _collisionTile; //충돌 타일

	TILE _tiles[TILE_COUNT];	//load 타일

	HRESULT init();
	void load();
	void release();

	virtual void play(HDC hdc);
};
