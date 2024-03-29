#pragma once
#include "AnimationBase.h"
class PickaxesAnimation : public AnimationBase
{
public:
	enum class State {
		stop = 0,
		action,
		END
	};
	float _currentAngle;
	int i;
	bool flag;
	PickaxesAnimation() :AnimationBase((int)State::END), _currentAngle(45.0) {
		mapping((int)State::stop, RES::PICKAXES_NORMAL);
	};

	void render(HDC hdc, POINTF startPt);
	void setImage(State state, int intKey, int width, int height) { AnimationBase::setImage((int)state, intKey, width, height); };
	void init(State initState) { AnimationBase::init((int)initState); };
};

