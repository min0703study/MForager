#include "Stdafx.h"
#include "UI.h"

UI::UI(POINTF absPt, int width, int height) :
	FixedUI(absPt, width, height)
{

}

void UI::play(HDC hdc, POINTF cameraPt)
{
	if (_isShowing) {
		_bAnimation->render(hdc, getRPt(cameraPt));
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
		_width,
		_height,
		frameXCount,
		frameYCount);
}

void UI::setStopImage(int state, char* fileName)
{
	_bAnimation->setStopImage(
		state,
		to_string(UI_AMOUNT++),
		fileName,
		_width,
		_height);
}