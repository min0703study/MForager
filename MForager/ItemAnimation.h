#pragma once
class ItemAnimation
{
public:
	enum class State {
		stop,
		END
	};

	void setAnimationImage(State state, string key, char * fileName, int frameX, int frameY, int frameXCount, int frameYCount);
	void setStartPt(POINTF startPt) { _startPt = startPt; };
	void init(POINTF startPt, State initState);
	void render(HDC hdc);
private:
	string imageKey[(int)State::END];

	POINTF _startPt;
	State _currentState;

	int _delayCount;
};
