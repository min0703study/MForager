#include "Stdafx.h"
#include "ItemAnimation.h"

void ItemAnimation::setAnimationImage(State state, string key, char * fileName, int frameX, int frameY, int frameXCount, int frameYCount)
{
	imageKey[(int)state] = key;
	IMAGEMANAGER->addFrameImage(key, fileName, frameX, frameY, frameXCount, frameYCount, true);
}

void ItemAnimation::init(POINTF startPt, State initState)
{
	_startPt = startPt;
	_currentState = initState;
}

void ItemAnimation::render(HDC hdc)
{
	FrameImage* img = (FrameImage*)IMAGEMANAGER->findImage(imageKey[(int)_currentState]);

	IMAGEMANAGER->frameRender(imageKey[(int)_currentState], hdc, _startPt);

	_delayCount++;
	if (_delayCount % 6 == 0) {
		IMAGEMANAGER->nextFrame(imageKey[(int)_currentState]);
	}
}

