#pragma once
#include "AnimationBase.h"

class PlayerAnimation: public AnimationBase {
public:
	enum class State {
		walk_right,
		walk_left,
		action_right,
		action_left,
		stop_right,
		stop_left,
		END
	};
public:
	PlayerAnimation() : AnimationBase((int)State::END) {};

	void setState(State state);
	void setAnimationImage(State state, string key, char * fileName, int frameX, int frameY, int frameXCount, int frameYCount);

	State getCurrentState() const { return State(_currentState); };
};

