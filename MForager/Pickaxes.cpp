#include "Stdafx.h"
#include "Pickaxes.h"

void Pickaxes::play(HDC hdc)
{
	int size = 10;
	if (_direction == -1) size += 10;
	Gdiplus::RectF rc(_absUiPos->_rcf->GetLeft() - (_direction * size), _absUiPos->_rcf->GetTop() + 10, getWidth(), getHeight());
	if (_animation->_currentState == (int)PickaxesAnimation::State::stop) {
		GDIPLUSMANAGER->render(hdc, RES_KEY::PICKAXES_NORMAL, rc);
	}
	else {
		if (_currentAngle >= 90.0) {
			_currentAngle = 90;
			i *= -1;
		}
		else if (_currentAngle <= 0.0f) {
			_currentAngle = 0;
			i *= -1;
		}
		_currentAngle += (i * 8);

		GDIPLUSMANAGER->rotate(hdc, RES_KEY::PICKAXES_NORMAL, rc, _currentAngle, _direction == 1);
	}
}
