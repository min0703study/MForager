#include "Stdafx.h"
#include "CollectAnimation.h"

void CollectAnimation::init(POINT startPt, State initState)
{
	_startPt = startPt;
	_currentState = initState;
}

void CollectAnimation::setAnimationImage(State state, string key, char * fileName, int frameX, int frameY, int frameXCount, int frameYCount)
{
	imageKey[(int)state] = key;
	IMAGEMANAGER->addFrameImage(key, fileName, frameX, frameY, frameXCount, frameYCount, true);
}

void CollectAnimation::render(HDC hdc)
{
	FrameImage* img = (FrameImage*)IMAGEMANAGER->findImage(imageKey[(int)_currentState]);

	IMAGEMANAGER->frameRender(imageKey[(int)_currentState], hdc, _startPt);

	_delayCount++;
	if (_delayCount % 6 == 0) {
		IMAGEMANAGER->nextFrame(imageKey[(int)_currentState]);
	}
}
