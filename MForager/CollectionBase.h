#pragma once
#include "CollectAnimation.h"

class CollectionBase
{
public:
	CollectAnimation* _animation;

	POINT _currentPt;
	RECT _currentRc;

	int _xSizeOfTile; //Ÿ�� x ���� ������
	int _ySizeOfTile; //Ÿ�� y ���� ������

	bool _isPassable; //������ �� �ִ°�?
	bool _isBeforDrop; //���� ���ΰ�?
	bool _isHitStart; //�ѹ��̶� hit �������� �ִ���

	int _maxHitGage;
	int _hitGage; //�������� ������

	void hit(int power);
	bool isHitStart() { return _isHitStart; };

	CollectionBase(POINT pt, int maxHitGage, int xSizeOfTile, int ySizeOfTile);
	virtual ~CollectionBase() {};
};

