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

void AnimationBase::setImage(int state, int intKey, int width, int height)
{
	_imageKesInt[state] = intKey;
}

void AnimationBase::init(int initState)
{
	_currentState = initState;
	_delayCount = 6;
}

void AnimationBase::update()
{
}

void AnimationBase::render(HDC hdc, POINTF startPt)
{
	IMAGEMANAGER->render(_imageKeys[(int)_currentState], hdc, startPt);

	if (IMAGEMANAGER->getType(_imageKeys[(int)_currentState]) == FRAME) {
		_delayCount++;
		if (_delayCount % 6 == 0) {
			_delayCount = 0;
			IMAGEMANAGER->nextFrame(_imageKeys[(int)_currentState]);
		}
	}
}

void AnimationBase::render(HDC hdc, PointF& startPt)
{
	IMAGEMANAGER->render(_imageKeys[(int)_currentState], hdc, startPt);

	if (IMAGEMANAGER->getType(_imageKeys[(int)_currentState]) == FRAME) {
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
