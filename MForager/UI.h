#pragma once
#include "FixedUI.h"
#include "AnimationBase.h"

static int UI_AMOUNT = 1;

class UI: public FixedUI
{
public:
	static LPRECT _cmRc;
public:
	LPDRECT _relRc;
	
	UI(PointF* absPt, int width, int height, AnimationBase* animation);
	UI(PointF absPt, int width, int height, AnimationBase* animation);

	PointF getRPt() {
		return _relRc->getPtf();
	}

	RECT getRRc() {
		return _relRc->get();
	}

	void setIsShowing(bool isShowing) { this->_isShowing = isShowing; }


	void setAnimationImage(int state, char * fileName, int frameXCount, int frameYCount);
	void setStopImage(int state, char * fileName);
	
	virtual void play(HDC hdc);
};

