#pragma once
#include "Map.h"
class MapManager
{
private:
	Map* _map;
public:
	HRESULT init();
	void release(void);
	void render(HDC hdc);
	void update();

	bool ptCollsionCheck(POINTF pt);
	bool ptInCollsionTile(int x, int y);
};

