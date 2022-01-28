#pragma once
#include "AnimationBase.h"
class UI
{
protected:
	AnimationBase* _bAnimation;

	POINTF _absPt;
	RECT _absRc;

	POINTF _relPt;
	RECT _relRc;

	int _width;
	int _height;

	bool _isShowing;

public:
	UI(POINTF absPt, int width, int height) : 
		_absPt(absPt), 
		_width(width), 
		_height(height), 
		_absRc(RectMake(absPt, width, height)),
		_isShowing(true) {};

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

	POINTF getAPt() {
		return _absPt;
	}

	RECT getARect() {
		return _absRc;
	}

	void setApt(POINTF pt) {
		this->_absPt = pt;
	}

	void setIsShowing(bool isShowing) { this->_isShowing = isShowing; }

	virtual void play(HDC hdc, POINTF cameraPt);
};

