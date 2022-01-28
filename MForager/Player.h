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

	Player(POINTF pt, int width, int height, int maxHp, int power, int lifeCount);
	~Player();

	PlayerAnimation* _animation;

	//RECT _clickableRect;
	//RECT _moveRc;

	Direction _currentDirection;
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

	void directionCheck(POINT pt);

	void setWalkAnimation();

	void move(float addValue, bool isX);
	
	void actionCollect();

	RECT getClickableRect(RECT relRc);

	//getter/setter
	int getHp() { return _currentHp; }
	int getLifeCount() { return _lifeCount; }
	void setKey(int moveFront, int moveBack, int jump, int attack, int defense);
	void setDirection(Direction direction);

};
