#pragma once
class Image
{
protected:
	enum IMAGE_LOAD_KIND
	{
		LOAD_RESOURCE = 0,
		LOAD_FILE,
		LOAD_EMPTY,
		LOAD_END
	};
public:
	HDC			_hMemDC;
	HBITMAP		_hBit;
	HBITMAP		_hOBit;
	int			_width;
	int			_height;
	BYTE		_loadType;

	char* _fileName;
	bool _isTrans;

	COLORREF _transColor;

public:
	enum IMAGE_TYPE {
		DEFAULT,
		FRAME,
		ALPHA,
	};

	IMAGE_TYPE _type;

	HRESULT init(int width, int height);
	HRESULT initFile(const char * fileName, int width, int height, bool isTrans = true);
	void release(void);

	HDC getMemDC(void) { return _hMemDC; }
};