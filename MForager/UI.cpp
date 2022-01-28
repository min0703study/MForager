#include "Stdafx.h"
#include "UI.h"

void UI::play(HDC hdc, POINTF cameraPt)
{
	if (_isShowing) {
		_bAnimation->render(hdc, getRPt(cameraPt));
	}
}
