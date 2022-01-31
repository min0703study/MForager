#include "Stdafx.h"
#include "Player.h"

Player::Player(PointF pt,int width, int height, int maxHp, int power, int lifeCount)
	:UI(pt, width, height),
	_maxHp(maxHp),
	_currentHp(maxHp),
	_power(power),
	_lifeCount(lifeCount),
	_moveRect(SDRECT(getARc(), 20, 40, -20, 0)),
	_clickableRect(SDRECT(getARc(), -TILE_SIZE, -TILE_SIZE, TILE_SIZE, TILE_SIZE))
{
	initAnimation();
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

void Player::move(float x, float y) {
	addApt({ x, y });
}

void Player::actionCollect()
{
	_currentHp -= 10;
	if (_currentHp <= 0) {
		_lifeCount--;
		_currentHp = _maxHp;
	}
}

SDRECT Player::getClickableRect()
{
	return _clickableRect;
}

SDRECT Player::getMoveRect()
{
	return _moveRect;
}

void Player::initAnimation()
{
	_animation = new PlayerAnimation();

	_animation->setAnimationImage(PlayerAnimation::State::stop_right, "Stop_Right", "Resource/Images/Motion/stop_right.bmp", PLAYER_SIZE_X * 3, PLAYER_SIZE_Y, 3, 1);
	_animation->setAnimationImage(PlayerAnimation::State::stop_left, "Stop_Left", "Resource/Images/Motion/stop_left.bmp", PLAYER_SIZE_X * 3, PLAYER_SIZE_Y, 3, 1);
	_animation->setAnimationImage(PlayerAnimation::State::action_right, "Action_Right", "Resource/Images/Motion/action_right.bmp", PLAYER_SIZE_X, PLAYER_SIZE_Y, 1, 1);
	_animation->setAnimationImage(PlayerAnimation::State::action_left, "Action_Left", "Resource/Images/Motion/action_left.bmp", PLAYER_SIZE_X, PLAYER_SIZE_Y, 1, 1);
	_animation->setAnimationImage(PlayerAnimation::State::walk_right, "Walk_Right", "Resource/Images/Motion/walk_right.bmp", PLAYER_SIZE_X * 3, PLAYER_SIZE_Y, 3, 1);
	_animation->setAnimationImage(PlayerAnimation::State::walk_left, "Walk_Left", "Resource/Images/Motion/walk_left.bmp", PLAYER_SIZE_X * 3, PLAYER_SIZE_Y, 3, 1);

	_animation->setState(PlayerAnimation::State::stop_right);
	
	_bAnimation = _animation;
}
