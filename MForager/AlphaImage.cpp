#include "Stdafx.h"
#include "AlphaImage.h"
#pragma comment (lib, "msimg32.lib")

HRESULT AlphaImage::init(const char * fileName, int width, int height, BOOL isTrans)
{
	_type = ALPHA;

	_blendFunc.BlendFlags = 0;
	_blendFunc.BlendOp = AC_SRC_OVER;
	_blendFunc.AlphaFormat = AC_SRC_ALPHA;

	HDC hdc = GetDC(_hWnd);

	_loadType = LOAD_FILE;
	_hMemDC = CreateCompatibleDC(hdc);
	_hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_hOBit = (HBITMAP)SelectObject(_hMemDC, _hBit);

	_width = width;
	_height = height;

	int len = strlen(fileName);

	_fileName = new CHAR[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	_isTrans = isTrans;
	_transColor = TRANCE_COLOR;

	if (_hBit == 0) {
		release();
		return E_FAIL;
	}

	ReleaseDC(_hWnd, hdc);
	return S_OK;
}