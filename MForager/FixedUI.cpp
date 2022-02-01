#include "Stdafx.h"
#include "FixedUI.h"

void FixedUI::play(HDC hdc)
{
	if (_isShowing) {
		_animation->render(hdc, *getAPt());
	}
}

void FixedUI::initAnimation()
{
}
