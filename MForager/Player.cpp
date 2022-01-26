#include "Stdafx.h"
#include "Player.h"
#define State					 PlayerAnimation::State
Player::Player(POINTF pt, int maxHp, int power, int lifeCount):
	_currentPt(pt),
	_currentRc({ (LONG)pt.x, (LONG)pt.y, (LONG)pt.x + PLAYER_SIZE_X, (LONG)pt.y + PLAYER_SIZE_Y }),
	_maxHp(maxHp),
	_currentHp(maxHp),
	_power(power),
	_lifeCount(lifeCount)
{
	_clickableRect = { _currentRc.left - TILE_SIZE ,_currentRc.top - TILE_SIZE, _currentRc.right + TILE_SIZE ,  _currentRc.bottom + TILE_SIZE };
	_moveRc = { _currentRc.left + 10, _currentRc.top + 20,  _currentRc.right - 10, _currentRc.bottom };

	_power = 10;
	_animation = new PlayerAnimation();
}

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

void Player::setDirection(Direction direction)
{
	if (_currentDirection != direction) {
		_currentDirection = direction;
	}
}

void Player::setWalkAnimation()
{
	if (_currentDirection == D_LEFT) {
		_animation->setState(State::walk_left);
	}
	else {
		_animation->setState(State::walk_right);
	}
}

void Player::directionCheck(POINT pt)
{
	if (pt.x > _currentPt.x + 30)
	{
		_currentDirection = Direction::D_RIGHT;
	}
	else {
		_currentDirection = Direction::D_LEFT;
	}
}


void Player::playAnimation(HDC hdc)
{
	_animation->render(hdc);
}

bool Player::ptIsClickable(POINT pt)
{
	return PtInRect(&_clickableRect, pt);
}

void Player::moveKeyCheck(Map * map)
{
	if (KEYMANAGER->isStayKeyDown(_moveLeft)) {
		setWalkAnimation();
		if (!map->ptCollsionCheck(_moveRc.left, _moveRc.bottom)) {
			move(-PLAYER_SPEED, true);
		}
	}

	if (KEYMANAGER->isStayKeyDown(_moveRight)) {
		setWalkAnimation();
		if (!map->ptCollsionCheck(_moveRc.right, _moveRc.top)) {
			move(PLAYER_SPEED, true);
		}
	}

	if (KEYMANAGER->isStayKeyDown(_moveUp)) {
		setWalkAnimation();
		if (!map->ptCollsionCheck(_moveRc.left, _moveRc.top)) {
			move(-PLAYER_SPEED, false);
		}
	}

	if (KEYMANAGER->isStayKeyDown(_moveDown)) {
		setWalkAnimation();
		if (!map->ptCollsionCheck(_moveRc.left, _moveRc.bottom)) {
			move(PLAYER_SPEED, false);
		}
	}
}

void Player::move(int addValue, bool isX)
{
	if (isX) {
		_currentPt.x += addValue;
		_currentRc.left += addValue;
		_currentRc.right += addValue;

		_moveRc.left += addValue;
		_moveRc.right += addValue;

		_clickableRect.left += addValue;
		_clickableRect.right += addValue;

	}
	else {
		_currentPt.y += addValue;
		
		_currentRc.top += addValue;
		_currentRc.bottom += addValue;

		_moveRc.top += addValue;
		_moveRc.bottom += addValue;

		_clickableRect.top += addValue;
		_clickableRect.bottom += addValue;
	}
}

void Player::actionCollect()
{
	_currentHp -= 10;
	if (_currentHp <= 0) {
		_lifeCount--;
		_currentHp = _maxHp;
	}
}
