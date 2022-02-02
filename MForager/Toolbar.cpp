#include "Stdafx.h"
#include "Toolbar.h"

void Toolbar::playFixed(HDC hdc)
{
	GDIPLUSMANAGER->DrawRectangle(hdc, *_absUiPos->_pt, getWidth(), getHeight());
	GDIPLUSMANAGER->render(hdc, 7001, _absUiPos->getRectF());
}
