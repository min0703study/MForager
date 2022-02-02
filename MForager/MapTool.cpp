#include "Stdafx.h"
#include "MapTool.h"

HRESULT MapTool::init(void)
{
	GameNode::init();
	ShowCursor(true);

	IMAGEMANAGER->addFrameImage(
		B_GROUND_IMG_KEY, 
		RES_MAP_SPRITE_PATH, 
		TILE_SIZE * B_GROUND_X_COUNT,
		TILE_SIZE * B_GROUND_Y_COUNT, 
		B_GROUND_X_COUNT,
		B_GROUND_Y_COUNT);

	for (int i = 0; i < B_GROUND_Y_COUNT; i++) {
		for (int j = 0; j < B_GROUND_X_COUNT; j++) {
			_selectTiles[i * B_GROUND_X_COUNT + j].rc = {
				j * TILE_SIZE + (TILE_X_COUNT * TILE_SIZE),
				i * TILE_SIZE, 
				j * TILE_SIZE + TILE_SIZE + (TILE_X_COUNT * TILE_SIZE),
				i * TILE_SIZE + TILE_SIZE };
			_selectTiles[i * B_GROUND_X_COUNT + j].ground = GROUND(i * B_GROUND_X_COUNT + j);
		}
	}

	for (int i = 0; i < TILE_Y_COUNT; i++) {
		for (int j = 0; j < TILE_X_COUNT; j++) {
			_drawRc[i * TILE_X_COUNT + j] = {j * TILE_SIZE, i * TILE_SIZE, j * TILE_SIZE + TILE_SIZE,i * TILE_SIZE + TILE_SIZE };
		}
	}

	for (int i = 0; i < TILE_COUNT; i++) {
		_drawTiles[i].pt = { -1,-1 };
		_drawTiles[i].xIndex = -1;
		_drawTiles[i].yIndex = -1;
	}

	return S_OK;
}

void MapTool::update(void)
{
	GameNode::update();
	if (KEYMANAGER->isOnceKeyDown('S')) {
		saveMap();
	}

	if (KEYMANAGER->isOnceKeyDown('L')) {
		loadMap();
	}
}

void MapTool::release(void)
{
	GameNode::release();
}

void MapTool::render(void)
{
	PatBlt(getMemDc(), 0, 0, _winsizeX, _winsizeY, BLACKNESS);

	for (RECT rc : _drawRc) {
		RectangleMake(getMemDc(), rc);
	}

	for (int i = 0; i < TILE_Y_COUNT; i++) {
		for (int j = 0; j < TILE_X_COUNT; j++) {
			if (i == (TILE_X_COUNT - 12) /2 && j == (TILE_Y_COUNT - 12) / 2) {
				RectangleMake(getMemDc(), POINTF(i * TILE_SIZE, j * TILE_SIZE), 10, 10);
			}

			if (i == (TILE_X_COUNT - 12) / 2 && j == (TILE_Y_COUNT - 12) / 2 + 12) {
				RectangleMake(getMemDc(), POINTF(i * TILE_SIZE, j * TILE_SIZE), 10, 10);
			}
		}
	}
	
	for (TILE tile : _drawTiles)
	{
		if (tile.xIndex == -1) continue;
		IMAGEMANAGER->setCurrentFrame(B_GROUND_IMG_KEY, tile.ground % B_GROUND_X_COUNT, tile.ground / B_GROUND_X_COUNT);
		IMAGEMANAGER->frameRender(B_GROUND_IMG_KEY, getMemDc(), tile.pt);
	}

	IMAGEMANAGER->render(B_GROUND_IMG_KEY, getMemDc(), TILE_X_COUNT * TILE_SIZE, 0);
	IMAGEMANAGER->render(getBackBufferKey(), getHdc());
}

void MapTool::saveMap(void)
{
	SaveFile<TILE[TILE_COUNT]>(RES_SAVE_MAP_PATH, _drawTiles, sizeof(TILE) * TILE_COUNT);
}

void MapTool::loadMap(void)
{
	LoadFile<TILE[TILE_COUNT]>(RES_SAVE_MAP_PATH, _drawTiles, sizeof(TILE) * TILE_COUNT);
	for (TILE& tile : _drawTiles)
	{
		if (tile.xIndex == -1) continue;
		tile.pt = POINTF(tile.xIndex * TILE_SIZE, tile.yIndex * TILE_SIZE);
		tile.rc = RectMakeF(tile.pt, TILE_SIZE, TILE_SIZE);
	}

	
}

void MapTool::clickEvent(POINT & pt, bool isClickDown)
{
	isDrag = isClickDown;
	if (isClickDown) {
		for (int i = 0; i < TILE_COUNT; i++) {
			if (PtInRect(&_drawRc[i], pt)) {
				_drawTiles[i] = _currentSelectTile;
				
				_drawTiles[i].xIndex = i % TILE_Y_COUNT;
				_drawTiles[i].yIndex = i / TILE_Y_COUNT;

				_drawTiles[i].rc = _drawRc[i];
				_drawTiles[i].pt = { _drawRc[i].left, _drawRc[i].top };
			}
		}

		for (TILE tile : _selectTiles)
		{
			if (PtInRect(&tile.rc, pt)) {
				_currentSelectTile = tile;
			}
		}
	}
}

void MapTool::mouseMoveEvent(POINT & pt)
{
	if (isDrag) {
		for (int i = 0; i < TILE_COUNT; i++) {
			if (PtInRect(&_drawRc[i], pt)) {
				_drawTiles[i] = _currentSelectTile;

				_drawTiles[i].xIndex = i % TILE_Y_COUNT;
				_drawTiles[i].yIndex = i / TILE_Y_COUNT;

				_drawTiles[i].rc = _drawRc[i];
				_drawTiles[i].pt = { _drawRc[i].left, _drawRc[i].top };

			}
		}
	};
}