#pragma once
#include "Image.h"

class AlphaImage : public ImageBase
{
public:
	BLENDFUNCTION		_blendFunc;
	HRESULT init(const char * fileName, int width, int height, BOOL isTrans);
private:
};