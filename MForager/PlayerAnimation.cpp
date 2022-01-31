#include "Stdafx.h"
#include "PlayerAnimation.h"

void PlayerAnimation::setState(State state)
{
	if (State(_currentState) != state) {
		_currentState = (int)state;
	}
}

void PlayerAnimation::setAnimationImage(State state, string key, char * fileName, int frameX, int frameY, int frameXCount, int frameYCount)
{
	AnimationBase::setAnimationImage((int)state, key, fileName, frameX, frameY, frameXCount, frameYCount);
}