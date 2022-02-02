#pragma once
#include "FixedUI.h"
#include "SizeChangeAnimation.h"

class InventoryBox: public FixedUI
{
public:
	InventoryBox(PointF pt, int width, int height)
		:FixedUI(pt, width, height, new SizeChangeAnimation) {
		_isShowing = true;
		_animation->mapping((int)SizeChangeAnimation::State::stop, RES::INVENTORY_BOX);
	};
	virtual void playFixed(HDC hdc) {
		GDIPLUSMANAGER->render(hdc, RES::INVENTORY_BOX, _absUiPos);
	};

	RectF getCountRect() {
		RECT rc = *getARc();
		rc.top += 100;
		return RectF(rc.bottom - 20, rc.right - 20,20,20);
	}
};

