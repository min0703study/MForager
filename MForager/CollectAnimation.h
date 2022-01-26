#pragma once

class CollectAnimation
{
public:
	enum class State {
		create,
		stop,
		hit,
		drop,
		END
	};

	void setAnimationImage(State state, string key, char * fileName, int frameX, int frameY, int frameXCount, int frameYCount);
	void init(POINT startPt, State initState);
	void render(HDC hdc);
private:
	string imageKey[(int)State::END];

	POINT _startPt;
	State _currentState;

	int _delayCount;
};

