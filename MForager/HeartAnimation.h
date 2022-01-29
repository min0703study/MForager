#pragma once
#include "AnimationBase.h"

class HeartAnimation : public AnimationBase {
public:
	enum class State {
		live,
		blank,
		END
	};
public:
	HeartAnimation() : AnimationBase((int)State::END) {};
	void setAnimationImage(State state, string key, char * fileName, int frameX, int frameY, int frameXCount, int frameYCount);
	void setState(State state);
};


