#pragma once
#include "Image.h"

class FrameImage: public ImageBase
{
public:
	int			_frameWidth;
	int			_frameHeight;

	int			_frameXCount;
	int			_frameYCount;

	int			_currentFrameX;
	int			_currentFrameY;

public:
	HRESULT initFile(const char * fileName, int width, int height, int frameXCount, int frameYCount, bool isTrans = true);
	void nextFrame();
	void setCurrentFrame(int x, int y);
	void release(void);

	FrameImage() {};
	~FrameImage() {};
};
