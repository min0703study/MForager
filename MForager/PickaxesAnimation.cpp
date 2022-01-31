#include "Stdafx.h"
#include "PickaxesAnimation.h"

void PickaxesAnimation::render(HDC hdc, POINTF startPt)
{
	if (_currentState == (int)State::action) {
		_currentAngle++;
		GDIPLUSMANAGER->rotate((int)State::action, startPt.toPointF(), _currentAngle);
	}
}
