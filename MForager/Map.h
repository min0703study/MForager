#pragma once
#include "CollectionBase.h"

using namespace UI_INFO::MAP;

class Map: public UI
{
public:
	Map() : UI({ 0,0 }, X_SIZE, Y_SIZE) {};

	TILE _tiles[TILE_COUNT];	//Ÿ��
	TILE* _collisionTiles[TILE_COUNT]; //�浹 Ÿ��
	int _collisionTilesCount; //�浹 Ÿ�� ��

	HRESULT init();
	void Load();
	void release();

	virtual void play(HDC hdc);
};
