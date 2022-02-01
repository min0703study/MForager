#pragma once
#include "PlayerAnimation.h"
#include "UI.h"

class Player: public UI
{
public:
	enum Direction {
		D_LEFT,
		D_RIGHT
	};

	Player(PointF pt, int width, int height, int maxHp, int power, int lifeCount);
	~Player();

	Direction _currentDirection;

	SDRECT _moveRect;
	SDRECT _clickableRect;
	
public:
	int _moveLeft;
	int _moveRight;
	int _moveUp;
	int _moveDown;

	int _actionKey;

	int _maxHp;
	int _currentHp;
	int _lifeCount;
	int _power;

	void move(float x, float y);
	void actionCollect();

	SDRECT getClickableRect();
	SDRECT getMoveRect();

	virtual void initAnimation();

	//getter, setter
	int getHp() { return _currentHp; }
	int getLifeCount() { return _lifeCount; }


	void setKey(int moveFront, int moveBack, int jump, int attack, int defense);

};
