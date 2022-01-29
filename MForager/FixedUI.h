#pragma once
#include "AnimationBase.h"

class FixedUI
{
protected:
	AnimationBase* _bAnimation;

	POINTF _absPt;
	RECT _absRc;

	int _width;
	int _height;

	bool _isShowing;

public:
	FixedUI(POINTF absPt, int width, int height) :
		_absPt(absPt), 
		_absRc(RectMake(absPt, width, height)),
		_width(width), 
		_height(height), 
		_isShowing(true) {};

	POINTF getAPt() {
		return _absPt;
	}

	RECT getARect() {
		return _absRc;
	}

	void setApt(POINTF pt) {
		this->_absPt = pt;
	}
	
	virtual void play(HDC hdc);
	virtual void initAnimation();
};

