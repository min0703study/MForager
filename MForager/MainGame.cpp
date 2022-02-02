#include "Stdafx.h"
#include "MainGame.h"

HRESULT MainGame::init(void)
{
	GameNode::init();
	
	CommonDatainit();
	ShowCursor(false);
	addTimer(1, TICK_TIMER_ID);

	_mm = new MapManager();
	_cm = new CollectionManager();
	_uim = new UIManager;
	_uim->initCamera();
	_pm = new PlayerManager();
	_im = new ItemManager();
	_mem = new MenuManager();
	_idm = new IndustrialManager();

	_pm->_uiManager = _uim;
	_uim->_playerManager = _pm;

	_pm->_itemManager = _im;
	_pm->_mapManager = _mm;
	_pm->_collectionManager = _cm;

	_im->_playerManager = _pm;
	_im->_uiManager = _uim;

	_cm->_mapManager = _mm;
	_cm->_uiManager = _uim;
	_cm->_itemManager = _im;

	_mm->_uiManager = _uim;
	_uim->_collectionManager = _cm;
	_idm->_playerManager = _pm;
	_idm->_uiManager = _uim;

	_mem->_playerManager = _pm;
	_idm->_itemManager = _im;

	_pm->init();
	_uim->init();
	_cm->init();
	_mm->init();
	_im->init();
	_idm->init();
	_mem->init();
	_cm->makeRandomCollection(true);
	return S_OK;
}

void MainGame::update(void)
{
	GameNode::update();

	_pm->update();
	_cm->update();
	_mm->update();
	_uim->update();
	_im->update();
	_mem->update();
	_idm->update();
}

void MainGame::release(void)
{
	GameNode::release();
	_im->release();
	_mm->release();
	_cm->release();
	_pm->release();
	_mem->release();
}

void MainGame::render(void)
{
	PatBlt(getMemDc(), 0, 0, _winsizeX, _winsizeY, WHITENESS);
	RECT rcBackground = RectMake(0, 0, CAMERASIZE_X, CAMERASIZE_Y);
	HBRUSH brush = CreateSolidBrush(RGB(0, 142, 239));
	FillRect(getMemDc(), &rcBackground, brush);
	DeleteObject(brush);
	
	_uim->render(getMemDc());
	_mem->render(getMemDc());
	_idm->render(getMemDc());
	_uim->_cursor->render(getMemDc());
	IMAGEMANAGER->render(getBackBufferKey(), getHdc());

}

void MainGame::timerEvent(int timerId)
{
	if (timerId == TICK_TIMER_ID) {
		_uim->addGameTime();
	}
}

void MainGame::mouseMoveEvent(POINT& currentPoint)
{
	_uim->mouseMoveEvent(currentPoint);
}

void MainGame::clickEvent(POINT & pt, bool isClickDown)
{
	_mem->mouseClickEvent(pt, isClickDown);
	_uim->clickEvent(pt, isClickDown);
	_idm->clickEvent(pt, isClickDown);
}
