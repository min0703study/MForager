#pragma once
#include "AnimationBase.h"

class SimpleAnimation : public AnimationBase {
public:
	enum class State {
		oneMove,
		END
	};
public:
	SimpleAnimation() : AnimationBase((int)State::END) {};
	void setAnimationImage(string key, char* fileName, int frameX, int frameY, int frameXCount, int frameYCount);
};
