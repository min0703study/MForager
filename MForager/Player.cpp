#include "Stdafx.h"
#include "Player.h"

Player::Player(PointF pt, int width, int height, int maxHp, int power, int lifeCount)
	:UI(pt, width, height, new PlayerAnimation),
	_maxHp(maxHp),
	_currentHp(maxHp),
	_power(power),
	_lifeCount(lifeCount),
	_moveRect(SRECT(20, 40, -20, 0)),
	_level(1),
	_curExpPoint(0),
	_clickableRect(SRECT(-TILE_SIZE, -TILE_SIZE, TILE_SIZE, TILE_SIZE))
{}

Player::~Player()
{
}

void Player::setKey(int moveLeft , int moveRight, int moveUp, int moveDown, int action)
{
	this->_moveLeft = moveLeft;
	this->_moveRight = moveRight;
	this->_moveUp = moveUp;
	this->_moveDown = moveDown;
	this->_actionKey = action;
}

void Player::move(float x, float y) {
	addApt({ x, y });
}

void Player::actionCollect()
{
	_currentHp -= PLAYER::DEFAULT_VALUE::HIT_MINUS_HP;

	if (_currentHp <= 0) {
		_lifeCount--;
		_currentHp = _maxHp;
	}
}

RECT Player::getClickableRect()
{
	return _clickableRect.getRect(getRRc());
}

RECT Player::getMoveRect()
{
	return _moveRect.getRect(getRRc());
}