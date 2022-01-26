#include "Stdafx.h"
#include "Image.h"

HRESULT Image::init(int width, int height)
{
	HDC hdc = GetDC(_hWnd);

	_loadType = LOAD_EMPTY;
	_hMemDC = CreateCompatibleDC(hdc);
	_hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height);
	_hOBit = (HBITMAP)SelectObject(_hMemDC, _hBit);
	_width = width;
	_height = height;


	_fileName = NULL;
	_isTrans = FALSE;

	if (_hBit == 0) {
		release();
		return E_FAIL;
	}

	ReleaseDC(_hWnd, hdc);

	return S_OK;
}

HRESULT Image::initFile(const char * fileName, int width, int height, bool isTrans)
{
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
}

void Image::release(void)
{
	SelectObject(_hMemDC, _hOBit);
	DeleteObject(_hBit);
	DeleteDC(_hMemDC);

	_isTrans = FALSE;
}