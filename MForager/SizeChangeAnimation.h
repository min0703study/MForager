#pragma once
#include "AnimationBase.h"
class SizeChangeAnimation: public AnimationBase
{
public:
	enum class State {
		stop = 0,
		size_change,
		END
	};
public:
	SizeChangeAnimation() : AnimationBase((int)State::END) {};

};

