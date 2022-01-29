#pragma once
#include "FixedUI.h"
#include "AnimationBase.h"

static int UI_AMOUNT = 1;

class UI: public FixedUI
{
protected:
	POINTF _relPt;
	RECT _relRc;
public:
	UI(POINTF absPt, int width, int height);

	POINTF getRPt(POINTF cameraPt) {
		_relPt.x = _absPt.x - cameraPt.x;
		_relPt.y = _absPt.y - cameraPt.y;
		return _relPt;
	}

	RECT getRRect(RECT cameraRc) {
		_relRc.left = _absRc.left - cameraRc.left;
		_relRc.top = _absRc.top - cameraRc.top;
		_relRc.right = _absRc.right - cameraRc.left;
		_relRc.bottom = _absRc.bottom - cameraRc.top;

		return _relRc;
	}

	RECT getRRect(POINTF pt) {
		return RectMake(getRPt(pt), _width, _height);
	}

	void setIsShowing(bool isShowing) { this->_isShowing = isShowing; }

	virtual void play(HDC hdc, POINTF cameraPt);
	virtual void initAnimation();

	void setAnimationImage(int state, char * fileName, int frameXCount, int frameYCount);
	void setStopImage(int state, char * fileName);

};

