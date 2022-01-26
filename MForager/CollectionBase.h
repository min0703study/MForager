#pragma once
#include "CollectAnimation.h"

class CollectionBase
{
public:
	CollectAnimation* _animation;

	POINT _currentPt;
	RECT _currentRc;

	int _xSizeOfTile; //타일 x 기준 사이즈
	int _ySizeOfTile; //타일 y 기준 사이즈

	bool _isPassable; //지나갈 수 있는가?
	bool _isBeforDrop; //수집 전인가?
	bool _isHitStart; //한번이라도 hit 당한적이 있는지

	int _maxHitGage;
	int _hitGage; //지워지는 게이지

	void hit(int power);
	bool isHitStart() { return _isHitStart; };

	CollectionBase(POINT pt, int maxHitGage, int xSizeOfTile, int ySizeOfTile);
	virtual ~CollectionBase() {};
};

