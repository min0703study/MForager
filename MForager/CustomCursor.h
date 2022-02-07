#pragma once
#include "UI.h"
class CustomCursor
{
public:
	LPDPoinF _relPtf;
	PointF* _pt;
	SizeF _size;

	POINT getPos() {
		return POINT({ (int)_pt->X, (int)_pt->Y });
	}

	PointF getRPt() {
		return _relPtf->get();
	};

	POINT getRPOINT() {
		return POINT({ (int)_relPtf->get().X, (int)_relPtf->get().Y });
	};
public:
	CustomCursor(PointF* pt, PointF* _cmPt, int width, int height) {
		_pt = pt;
		_relPtf = new DPF(pt, _cmPt);
		_size = SizeF(width, height);
	};

	void render(HDC hdc) {
		GDIPLUSMANAGER->render(hdc, RES_KEY::CURSOR, *_pt, _size);
	}
	
};

