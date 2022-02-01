#pragma once
#include "UI.h"
#include "SimpleAnimation.h"

class SelectPtBox: public UI
{
public:
	
	SelectPtBox(PointF pt, int width, int height) 
		:UI(pt, width, height, new SimpleAnimation) {
		setIsShowing(false);
		initAnimation();
	};
};

