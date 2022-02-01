#pragma once

#include "MapTile.h"

using namespace MAP_C::UI_INFO;

class Map: public UI
{
public:
	Map() : UI({ 0,0 }, X_SIZE, Y_SIZE, nullptr) {};

	vector<UI*> _mapTiles;
	
	TILE _tiles[TILE_COUNT];	//Ÿ��
	TILE* _collisionTiles[TILE_COUNT]; //�浹 Ÿ��
	int _collisionTilesCount; //�浹 Ÿ�� ��

	HRESULT init();
	void load();
	void release();

	virtual void play(HDC hdc);
};
