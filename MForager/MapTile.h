#pragma once
#include "UI.h"
class MapTile: public UI
{
private:
	GROUND _ground;
	int _xFrame;
	int _yFrame;
public:
	MapTile(GROUND ground, int xFrame, int yFrame, PointF pt, int width, int height)
		:UI(pt, width, height, nullptr),
		_ground(ground),
		_xFrame(xFrame),
		_yFrame(yFrame)
	{

	};

	virtual void play(HDC hdc);
};

