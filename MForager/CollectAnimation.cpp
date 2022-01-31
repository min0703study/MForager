#include "Stdafx.h"
#include "CollectAnimation.h"

void CollectAnimation::setAnimationImage(State state, string key, char * fileName, int frameX, int frameY, int frameXCount, int frameYCount)
{
	AnimationBase::setAnimationImage((int)state, key, fileName, frameX, frameY, frameXCount, frameYCount);
}

void CollectAnimation::init(State initState)
{
	AnimationBase::init((int)initState);
}
