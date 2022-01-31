#include "Stdafx.h"
#include "UI.h"

LPRECT UI::_cmRc = nullptr;

UI::UI(PointF* absPt, int width, int height): FixedUI(absPt, width, height)
{
	_relRc = new DRECT(_cmRc, _absUiPos->_rc);
}

/*
UI::UI(POINTF absPt, int width, int height): FixedUI(new PointF(absPt.x, absPt.y), width, height)
{
	_relRc = new DRECT(_cmRc, _absUiPos->_rc);
}
*/
UI::UI(PointF absPt, int width, int height) : FixedUI(new PointF(absPt.X, absPt.Y), width, height)
{
	_relRc = new DRECT(_cmRc, _absUiPos->_rc);
}

void UI::play(HDC hdc)
{
	if (_isShowing) {
		_bAnimation->render(hdc, _relRc->getPtf());
	}
}

void UI::initAnimation()
{
}

void UI::setAnimationImage(int state, char* fileName, int frameXCount, int frameYCount)
{
	_bAnimation->setAnimationImage (
		state,
		to_string(UI_AMOUNT++),
		fileName,
		(int)_absUiPos->_width,
		(int)_absUiPos->_height,
		frameXCount,
		frameYCount);
}

void UI::setStopImage(int state, char* fileName)
{
	_bAnimation->setStopImage(
		state,
		to_string(UI_AMOUNT++),
		fileName,
		_absUiPos->_width,
		_absUiPos->_height);
}