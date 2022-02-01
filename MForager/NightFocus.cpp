#include "Stdafx.h"
#include "NightFocus.h"

void NightFocus::initAnimation()
{
	IMAGEMANAGER->addAlphaImage("night", RES_BACKGROUND_PATH, getWidth(), getHeight());
}

void NightFocus::render(HDC hdc) {
	//IMAGEMANAGER->alphaRender("night", hdc, *_playerPtf, (BYTE)_currentTime);
}

void NightFocus::addTime(int time) {
	_currentTime += time * _timerCheck;
	if (_currentTime > 254) {
		_timerCheck = -1;
	}
	else if(_currentTime < 1) {
		_timerCheck = 1;
	}
}