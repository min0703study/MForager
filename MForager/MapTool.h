#pragma once
#include "GameNode.h"
#include "Map.h"

class MapTool : public GameNode
{
private:
	RECT _drawRc[TILE_COUNT];
	TILE _drawTiles[TILE_COUNT];
	TILE _selectTiles[B_GROUND_X_COUNT * B_GROUND_Y_COUNT];
	
	TILE _currentSelectTile;
	bool isDrag;
public:
	HRESULT init(void) override;
	void update(void) override;
	void release(void) override;
	void render(void) override;

	void saveMap(void);
	void loadMap(void);

	void clickEvent(POINT& pt, bool isClickDown) override;
	void mouseMoveEvent(POINT& pt) override;
};
