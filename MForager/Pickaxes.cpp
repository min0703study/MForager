#include "Stdafx.h"
#include "Pickaxes.h"

void Pickaxes::play(HDC hdc)
{
	setApt(*_playerAbsPt);
	if (_isShowing) {
		//_bAnimation->render(hdc, getRPt());
	}
}
