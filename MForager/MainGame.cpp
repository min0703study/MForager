#include "Stdafx.h"
#include "MainGame.h"

HRESULT MainGame::init(void)
{
	GameNode::init();

	IMAGEMANAGER->addFileImage("cursor", RES_CURSOR_PATH, 20, 20, true);
	IMAGEMANAGER->addFrameImage("select_cursor", RES_SELECT_CURSOR_PATH, (TILE_SIZE + 20) * 5, (TILE_SIZE + 20), 5, 1);
	
	_map = new Map();
	_map->init();

	_cm = new CollectionManager();
	_cm->init();

	_pm = new PlayerManager();
	_pm->init();

	_im = new ItemManager();
	_im->init();

	return S_OK;
}

void MainGame::update(void)
{
	GameNode::update();

	makeRandomCollection();

	_pm->update();
	_cm->update();
	_im->RcCollisionCheckForDropItem(_pm->_player->_clickableRect);
	_im->update();

	_pm->_player->moveKeyCheck(_map);
}

void MainGame::release(void)
{
	GameNode::release();

	_map->release();
	_cm->release();
	_pm->release();
}

void MainGame::render(void)
{
	PatBlt(getMemDc(), 0, 0, _winsizeX, _winsizeY, BLACKNESS);

	_map->render(getMemDc());

	if (_cm->_isSelect) {
		/*
		if (delayCount % 3 == 0) {
			IMAGEMANAGER->nextFrame("select_cursor");
		}
		*/
		IMAGEMANAGER->nextFrame("select_cursor");
		IMAGEMANAGER->frameRender("select_cursor", getMemDc(),  _cm->_collectObjects[_cm->_selectIndex]->_currentPt);
	}

	_pm->render(getMemDc());
	_cm->render(getMemDc());
	_im->render(getMemDc());

	IMAGEMANAGER->render("cursor", getMemDc(), _currentPt.x, _currentPt.y);
	IMAGEMANAGER->render(getBackBufferKey(), getHdc());
	
}

void MainGame::mouseMoveEvent(POINT& currentPoint)
{
	_pm->_player->directionCheck(currentPoint);

	if (_pm->_player->ptIsClickable(currentPoint)) {
		_cm->getPtInCollect(currentPoint);
	}
	else {
		_cm->setSelectFlag(false);
	}
}

void MainGame::clickEvent(POINT & pt, bool isClickDown)
{
	if (isClickDown) {
		_pm->_player->_animation->setState(PlayerAnimation::State::action_left);
		if (_cm->_isSelect) {
			_pm->actionCollect();
			if (_cm->hitCollect(_pm->_player->_power)) {
				_im->createDropItem(_cm->getDropItem());
			};
		}
	}
	else {
		_pm->_player->_animation->setState(PlayerAnimation::State::stop_left);
	}
}

void MainGame::makeRandomCollection()
{
	int x = 0;
	int y = 0;

	while (!_cm->isFull()) {
		x = RND->getInt(TILE_X_COUNT) * TILE_SIZE;
		y = RND->getInt(TILE_Y_COUNT) * TILE_SIZE;

		if (!_map->ptInCollsionTile(x, y)) {
			_cm->makeRandomCollection(x, y);
		};
	}
}
