#include "Stdafx.h"
#include "PlayerAnimation.h"

void PlayerAnimation::setState(State state)
{
	if (_currentState != state) {
		_currentState = state;
	}
}

void PlayerAnimation::setAnimationImage(State state, string key, char * fileName, int frameX, int frameY, int frameXCount, int frameYCount)
{
	imageKey[(int)state] = key;
	IMAGEMANAGER->addFrameImage(key, fileName, frameX, frameY, frameXCount, frameYCount, true);
}
void PlayerAnimation::init(POINT startPt, State initState)
{
	_delayCount = 0;
}
void PlayerAnimation::render(HDC hdc, POINT position)
{
	POINTF ptf = POINTF(position);
	this->render(hdc, ptf);
}
void PlayerAnimation::render(HDC hdc, POINTF position)
{
	FrameImage* img = (FrameImage*)IMAGEMANAGER->findImage(imageKey[(int)_currentState]);

	IMAGEMANAGER->frameRender(imageKey[(int)_currentState], hdc, position);

	_delayCount++;
	if (isPlaying && _delayCount % 6 == 0) {
		IMAGEMANAGER->nextFrame(imageKey[(int)_currentState]);
	}
}

PlayerAnimation::PlayerAnimation()
{
}

PlayerAnimation::~PlayerAnimation()
{
}
