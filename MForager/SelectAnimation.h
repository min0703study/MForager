#pragma once
#include "AnimationBase.h"
class SelectAnimation: public AnimationBase
{
public:
	enum class State {
		select,
		no_select,
		END
	};
public:
	SelectAnimation() : AnimationBase((int)State::END) {};
};