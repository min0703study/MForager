#pragma once
#include "CameraManager.h"
#include "Map.h"

class MapManager
{
private:
	Map* _map;
public:
	CameraManager* _cameraManager;

	HRESULT init();
	RECT rectToCamera(RECT _rc);
	POINTF ptToCamera(POINTF pt);
	void release(void);
	void render(HDC hdc);
	void update();

	bool ptCollsionCheck(POINTF pt);
	bool ptInCollsionTile(int x, int y);
};

