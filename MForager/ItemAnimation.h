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
	void setStartPt(POINTF startPt) { _startPt = startPt; };
	void init(POINTF startPt, State initState);
};
