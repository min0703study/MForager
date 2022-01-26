#pragma once

enum class State {
	walk_right,
	walk_left,
	action_right,
	action_left,
	stop_right,
	stop_left,
	END
};

class PlayerAnimation {
private:
	string imageKey[(int)State::END];

	State _currentState;
	bool isPlaying;

	int _delayCount;
public:
	void setState(State state);
	void setAnimationImage(State state, string key, char * fileName, int frameX, int frameY, int frameXCount, int frameYCount);
	void init(POINT startPt, State initState);
	void render(HDC hdc, POINT position);
	void render(HDC hdc, POINTF position);

	State getCurrentState() const { return _currentState; };

	PlayerAnimation();
	~PlayerAnimation();
};

