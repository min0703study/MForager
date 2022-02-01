#include "Stdafx.h"
#include "Pickaxes.h"

void Pickaxes::play(HDC hdc)
{
	if (_currentAngle == 90.0 || _currentAngle == 0.0) i *= -1;
	_currentAngle += (i*5);
	GDIPLUSMANAGER->rotate(RES::PICKAXES_NORMAL, _absUiPos, _currentAngle);

}
