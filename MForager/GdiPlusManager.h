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
	Image* addImage(int intKey, const string fileName, int width, int height, bool isTranse);
	Image * findImage(int intKey);
	Image * rotate(int intKey, PointF centerPt, int angle);

	void release();
};

