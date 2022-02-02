#pragma once

#include "MapTile.h"

using namespace MAP_C::UI_INFO;

class Map: public UI
{
public:
	Map() : UI({ 0,0 }, X_SIZE, Y_SIZE, nullptr) {};

	vector<UI*> _mapTiles;
	vector<UI*> _collisionTile; //�浹 Ÿ��

	TILE _tiles[TILE_COUNT];	//load Ÿ��

	HRESULT init();
	void load();
	void release();

	virtual void play(HDC hdc);
};
