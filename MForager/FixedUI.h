#pragma once
#include "AnimationBase.h"

using namespace Gdiplus;

class FixedUI
{
public:
	UIPOS* _absUiPos;
	AnimationBase* _animation;
protected:

	bool _isShowing;
public:
	FixedUI(PointF* absPt, int width, int height, AnimationBase* animation) :
		_absUiPos(new UIPOS(absPt, width, height)),
		_animation(animation),
		_isShowing(true) {

	};

	PointF* getAPt() {
		return _absUiPos->_pt;
	}

	LPRECT getARc() {
		return  _absUiPos->_rc;
	}

	void setApt(PointF pt) {
		_absUiPos->changePt(pt);
	}

	float getWidth() {
		return _absUiPos->_width;
	}

	float getHeight() {
		return _absUiPos->_height;
	}

	void addApt(PointF pt) {
		_absUiPos->addPt(pt);
	}

	
	virtual void play(HDC hdc);
	virtual void initAnimation();
};

