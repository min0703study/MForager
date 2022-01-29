#pragma once
#include "UI.h"
#include "SimpleAnimation.h"

class NightFocus: public UI
{
private:
	int _currentTime; //255
	int _timerCheck; // 1 or -1
public:
	SimpleAnimation* _animation;
	void initAnimation() override;

	NightFocus(POINTF pt, int width, int height) :UI(pt, width, height) {
		initAnimation();
	};

	void render(HDC hdc, POINTF pt);
	void addTime(int time);
};

