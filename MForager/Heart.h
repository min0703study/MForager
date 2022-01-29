#pragma once
#include "UI.h"
#include "HeartAnimation.h"

class Heart : public UI
{
public:
	HeartAnimation* _animation;

	Heart(POINTF pt, int width, int height) :UI(pt, width, height) {
		_isShowing = true;
		initAnimation();
	};

	void initAnimation() override;
};

