#pragma once
#include "PlayerAnimation.h"
#include "Map.h"

enum Direction {
	D_LEFT, 
	D_RIGHT
};

class Player
{
public:
	Player(POINTF pt, int maxHp, int power, int lifeCount);
	~Player();

	PlayerAnimation* _animation;

	POINTF _currentPt;
	RECT _currentRc;

	RECT _clickableRect;
	RECT _moveRc;

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
	int _power; //Â÷ÈÄ °î±ªÀÌ¿¡ power

	void setKey(int moveFront, int moveBack, int jump, int attack, int defense);
	void setDirection(Direction direction);
	void directionCheck(POINT pt);

	void setWalkAnimation();

	void moveKeyCheck();
	void move(int addValue, bool isX);
	
	void actionCollect();

	void playAnimation(HDC hdc);
	bool ptIsClickable(POINT pt);

	int getHp() { return _currentHp; }
	int getLifeCount() { return _lifeCount; }

};
