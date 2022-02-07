#pragma once

typedef struct tagimage
{
	int			_width;
	int			_height;

	tagimage(int width, int height) : _width(width), _height(height) {};

} IMAGE_INFO, *LPIMAGE_INFO;

typedef struct tagFrame : public IMAGE_INFO
{
	HDC			hMemDC;
	HBITMAP		hBit;
	HBITMAP		hOBit;

	int	_frameWidth;
	int	_frameHeight;

	int	_frameXCount;
	int	_frameYCount;

	int	_currentFrameX;
	int	_currentFrameY;

} FRAME_INFO;

typedef struct tagAlpahInfo : public IMAGE_INFO
{
	BLENDFUNCTION		_blendFunc;

} ALPHA_INFO;

class ImageBase
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
	bool		_isLoadSuccess;
	LPIMAGE_INFO _imageInfo;

	char* _fileName;
	bool _isTrans;

	COLORREF _transColor;

public:
	IMAGE_TYPE _type;

	HRESULT init(int width, int height);
	HRESULT initFile(const char * fileName, int width, int height, bool isTrans = true);

	void release(void);

	HDC getMemDC(void) { return _hMemDC; }
};