#include "Stdafx.h"
#include "SimpleAnimation.h"

void SimpleAnimation::setAnimationImage(string key, char * fileName, int frameX, int frameY, int frameXCount, int frameYCount)
{
	AnimationBase::setAnimationImage((int)State::oneMove, key, fileName, frameX, frameY, frameXCount, frameYCount);
	_currentState = (int)State::oneMove;
}
