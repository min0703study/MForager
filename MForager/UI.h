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
	
	UI(PointF* absPt, int width, int height);
	//UI(POINTF absPt, int width, int height);
	UI(PointF absPt, int width, int height);

	PointF getRPt() {
		return _relRc->getPtf();
	}

	RECT getRRc() {
		return _relRc->get();
	}

	void setIsShowing(bool isShowing) { this->_isShowing = isShowing; }

	virtual void play(HDC hdc);
	virtual void initAnimation();

	void setAnimationImage(int state, char * fileName, int frameXCount, int frameYCount);
	void setStopImage(int state, char * fileName);

};

