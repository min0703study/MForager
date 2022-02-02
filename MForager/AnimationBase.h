#pragma once
class AnimationBase
{
private:
	string* _imageKeys;
	int* _imageKesInt;

	int _imageKeysSize;

	int _oWidth;
	int _oHeight;

	int _delayCount;

protected:
public:
	int _currentState;
	
	AnimationBase(int imgKeysSize) : 
		_imageKeys(new string[imgKeysSize]), 
		_imageKesInt(new int[imgKeysSize])
	{ 
		_imageKeysSize = imgKeysSize; 
	};

	void init(int initState);
	
	void setAnimationImage(int state, string key, char* fileName, int frameX, int frameY, int frameXCount, int frameYCount);
	void setStopImage(int state, string key, char * fileName, int frameX, int frameY);
	void setImage(int state, int intKey, int width, int height);

	void mapping(int state, int intKey) { _imageKeys[state] = to_string(intKey); };
	string getCurImageKeys() { return _imageKeys[_currentState]; };
	void chageState(int state) { _currentState = state; };

	virtual void render(HDC hdc, PointF& startPt);
	virtual void render(HDC hdc, POINTF startPt);
	
	void update();
	void release();

};
