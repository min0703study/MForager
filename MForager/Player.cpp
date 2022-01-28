#include "Stdafx.h"
#include "Player.h"

Player::Player(POINTF pt,int width, int height, int maxHp, int power, int lifeCount)
	:UI(pt, width, height),
	_maxHp(maxHp),
	_currentHp(maxHp),
	_power(power),
	_lifeCount(lifeCount)
{
	//_clickableRect = { _absRc.left - TILE_SIZE, _absRc.top - TILE_SIZE, _absRc.right + TILE_SIZE,  _absRc.bottom + TILE_SIZE };
	//_moveRc = { _absRc.left + 10, _absRc.top + 20,  _absRc.right - 10, _absRc.bottom };
	_animation = new PlayerAnimation();
	UI::_bAnimation = _animation;
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

void Player::setWalkAnimation()
{
	if (_currentDirection == D_LEFT) {
		_animation->setState(PlayerAnimation::State::walk_left);
	}
	else {
		_animation->setState(PlayerAnimation::State::walk_right);
	}
}

void Player::move(float addValue, bool isX)
{
	if (isX) {
		_absPt.x += addValue;
		_absRc.left += addValue;
		_absRc.right += addValue;
	}
	else {
		_absPt.y += addValue;
		_absRc.top += addValue;
		_absRc.bottom += addValue;
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

RECT Player::getClickableRect(RECT relRc)
{
	return { relRc.left - TILE_SIZE, relRc.top - TILE_SIZE, relRc.right + TILE_SIZE,  relRc.bottom + TILE_SIZE };
}
