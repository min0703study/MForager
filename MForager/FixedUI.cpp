#include "Stdafx.h"
#include "FixedUI.h"

void FixedUI::playFixed(HDC hdc)
{
	if (_isShowing) {
		_animation->render(hdc, *getAPt());
	}
}
