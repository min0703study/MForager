#include "Stdafx.h"
#include "FrameImage.h"

void FrameImage::release(void)
{
	Image::release();
}

HRESULT FrameImage::initFile(const char * fileName, int width, int height, int frameXCount, int frameYCount, bool isTrans)
{
	Image::initFile(fileName, width, height, isTrans);

	_type = FRAME;

	_frameWidth = width / frameXCount;
	_frameHeight = height / frameYCount;

	_frameXCount = frameXCount;
	_frameYCount = frameYCount;

	_currentFrameX = 0;
	_currentFrameY = 0;

	return S_OK;
}

void FrameImage::nextFrame()
{
	_currentFrameX++;
	if (_currentFrameX >= _frameXCount) {
		_currentFrameX = 0;
		_currentFrameY++;
		if (_currentFrameY >= _frameYCount) {
			_currentFrameY = 0;
		}
	}
}

void FrameImage::setCurrentFrame(int x, int y)
{
	_currentFrameX = x;
	_currentFrameY = y;
}
