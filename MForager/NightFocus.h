#pragma once
#include "UI.h"
#include "SimpleAnimation.h"

class NightFocus: public UI
{
private:
	int _currentTime; //255
	int _timerCheck; // 1 or -1

	PointF* _playerPtf;
public:
	NightFocus(PointF pt, int width, int height):
		UI(pt, width, height, new SimpleAnimation) {
		IMAGEMANAGER->addAlphaImage("night", RES_BACKGROUND_PATH, getWidth(), getHeight());
	};

	void render(HDC hdc);
	void addTime(int time);
};

