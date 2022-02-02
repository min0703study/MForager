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

	SRECT _moveRect;
	SRECT _clickableRect;
	
public:
	int _moveLeft;
	int _moveRight;
	int _moveUp;
	int _moveDown;

	int _skillPoint;

	bool _isActioning;

	int _level;
	int _curSkillPoint;

	int _actionKey;

	int _maxHp;
	int _currentHp;
	int _lifeCount;
	int _power;

	int _curExpPoint;

	void move(float x, float y);
	void actionCollect();

	RECT getClickableRect();
	RECT getMoveRect();

	//getter, setter
	int getHp() { return _currentHp; }
	int getLifeCount() { return _lifeCount; }
	int getLevel() { return _level; }
	int getExpPoint() { return _curExpPoint; }


	void setKey(int moveFront, int moveBack, int jump, int attack, int defense);

};
