#include "Stdafx.h"
#include "MainGame.h"

HRESULT MainGame::init(void)
{
	GameNode::init();

	_mm = new MapManager();
	_mm->init();

	_cm = new CollectionManager();
	_cm->init();

	_uim = new UIManager;
	_uim->init();

	_pm = new PlayerManager();
	_pm->_uiManager = _uim;
	_pm->init();

	_im = new ItemManager();
	_im->init();

	_cmm = new CameraManager;
	_cmm->init();


	_pm->_itemManager = _im;
	_pm->_mapManager = _mm;
	_pm->_cameraManager = _cmm;
	_pm->_collectionManager = _cm;

	_im->_playerManager = _pm;
	_im->_uiManager = _uim;

	_cm->_mapManager = _mm;
	_cm->_uiManager = _uim;
	_cm->_itemManager = _im;

	_mm->_cameraManager = _cmm;

	_uim->_cameraManager = _cmm;
	_uim->_playerManager = _pm;
	_uim->_collectionManager = _cm;

	_cm->makeRandomCollection();

	return S_OK;
}

void MainGame::update(void)
{
	GameNode::update();

	_pm->update();
	_cm->update();
	_mm->update();
//	_im->RcCollisionCheckForDropItem(_pm->_player->_clickableRect);
	_im->update();
}

void MainGame::release(void)
{
	GameNode::release();
	_im->release();
	_mm->release();
	_cm->release();
	_pm->release();
}

void MainGame::render(void)
{
	PatBlt(getMemDc(), 0, 0, _winsizeX, _winsizeY, BLACKNESS);

	_mm->render(getMemDc());
	_uim->render(getMemDc());

	IMAGEMANAGER->render(getBackBufferKey(), getHdc());
}

void MainGame::mouseMoveEvent(POINT& currentPoint)
{
	//_pm->_player->directionCheck(currentPoint);
	_uim->mouseMoveEvent(currentPoint);
}

void MainGame::clickEvent(POINT & pt, bool isClickDown)
{
	_uim->clickEvent(pt, isClickDown);
}
