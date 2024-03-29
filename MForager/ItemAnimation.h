#pragma once
#include "AnimationBase.h"
class ItemAnimation : public AnimationBase
{
public:
	enum class State {
		stop,
		END
	};

	ItemAnimation() :AnimationBase((int)State::END) {};
	void setAnimationImage(State state, string key, char * fileName, int frameX, int frameY, int frameXCount, int frameYCount);
	void init(State initState);
};
