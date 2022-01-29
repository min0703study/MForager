#include "Stdafx.h"
#include "NightFocus.h"

void NightFocus::initAnimation()
{
	_animation = new SimpleAnimation;
	_bAnimation = _animation;

	IMAGEMANAGER->addAlphaImage("night", RES_BACKGROUND_PATH, _width, _height);
}

void NightFocus::render(HDC hdc, POINTF pt) {
	_absPt.x = (pt.x - (_width * 0.5));
	_absPt.y = (pt.y - (_height * 0.5));

	IMAGEMANAGER->alphaRender("night", hdc, _absPt,  (BYTE)_currentTime);
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