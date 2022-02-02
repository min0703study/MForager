#include "Stdafx.h"
#include "NightFocus.h"

void NightFocus::render(HDC hdc) {
	IMAGEMANAGER->alphaRender("night", hdc, POINTF{0,0}, (BYTE)_currentTime);
}

void NightFocus::addTime(int time) {
	
	_currentTime += time * _timerCheck;
	if (_currentTime > 100) {
		_currentTime = 99;
		_timerCheck = -1;
	}
	else if(_currentTime < 10) {
		_currentTime = 10;
		_timerCheck = 1;
	}
}