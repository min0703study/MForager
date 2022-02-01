#pragma once
#include "SingletonBase.h"

class GdiPlusManager: public SingletonBase<GdiPlusManager>
{
private:
	typedef map<int, Image*> mapImageList;
	typedef map<int, Image*>::iterator mapImageIter;

	Graphics* _graphics;
	mapImageList _mImageList;
public:
	void init(HDC hdc);
	Image* addImage(int intKey, const string fileName, bool isTranse = true);
	Image * findImage(int intKey);
	void render(int intKey, UIPOS * uiPos);
	Image * rotate(int intKey, UIPOS * uiPos, int angle);
	void release();
};

