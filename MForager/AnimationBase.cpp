#include "Stdafx.h"
#include "AnimationBase.h"

void AnimationBase::setAnimationImage(int state, string key, char * fileName, int frameX, int frameY, int frameXCount, int frameYCount)
{
	_imageKeys[(int)state] = key;
	IMAGEMANAGER->addFrameImage(key, fileName, frameX, frameY, frameXCount, frameYCount, true);
}

void AnimationBase::setStopImage(int state, string key, char * fileName, int frameX, int frameY)
{
	_imageKeys[(int)state] = key;
	IMAGEMANAGER->addFileImage(key, fileName, frameX, frameY, true);
}

void AnimationBase::init(POINTF startPt, int initState)
{
	_startPt = startPt;
	_currentState = initState;

	_delayCount = 6;
}

void AnimationBase::update()
{
}

void AnimationBase::render(HDC hdc)
{
	render(hdc, _startPt);
}

void AnimationBase::render(HDC hdc, POINTF startPt)
{
	Image* img = IMAGEMANAGER->findImage(_imageKeys[(int)_currentState]);
	IMAGEMANAGER->render(_imageKeys[(int)_currentState], hdc, startPt);

	if (img->_type == FRAME) {
		_delayCount++;
		if (_delayCount % 6 == 0) {
			_delayCount = 0;
			IMAGEMANAGER->nextFrame(_imageKeys[(int)_currentState]);
		}
	}
}

void AnimationBase::release()
{

}
