#include "Stdafx.h"
#include "HeartAnimation.h"

void HeartAnimation::setAnimationImage(State state, string key, char * fileName, int frameX, int frameY, int frameXCount, int frameYCount)
{
	AnimationBase::setAnimationImage((int)state, key, fileName, frameX, frameY, frameXCount, frameYCount);
	_currentState = (int)State::live;
}

void HeartAnimation::setState(State state)
{
	_currentState = (int)state;
}
