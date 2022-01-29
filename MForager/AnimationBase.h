#pragma once
class AnimationBase
{
private:
	string* _imageKeys;
	int _imageKeysSize;

	int _delayCount;
protected:
	AnimationBase(int imgKeysSize) : _imageKeys(new string[imgKeysSize]) { _imageKeysSize = imgKeysSize; };
	

	void init(POINTF startPt, int initState);
	
	POINTF _startPt;
	int _currentState;
public:
	void setAnimationImage(int state, string key, char* fileName, int frameX, int frameY, int frameXCount, int frameYCount);
	void setStopImage(int state, string key, char * fileName, int frameX, int frameY);

	void render(HDC hdc);
	void render(HDC hdc, POINTF startPt);

	void update();
	void release();

};
