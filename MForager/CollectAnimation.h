#pragma once
#include "AnimationBase.h"

class CollectAnimation : public AnimationBase
{
public:
	enum class State {
		create,
		stop,
		hit,
		drop,
		END
	};

	CollectAnimation():AnimationBase((int)State::END) {};
	void setAnimationImage(State state, string key, char * fileName, int frameX, int frameY, int frameXCount, int frameYCount);
	void init(State initState);
};

