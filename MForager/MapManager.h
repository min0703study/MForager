#pragma once

#include "UIManager.h"
#include "Map.h"

class MapManager
{
private:
	Map* _map;
public:
	UIManager* _uiManager;

	HRESULT init();
\
	void release(void);
	void update();

	bool rcCollsionCheck(RECT & rc);
	bool ptInCollsionTile(int x, int y);
};

