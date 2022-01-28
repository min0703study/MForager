#pragma once
#include "CollectAnimation.h"
#include "Stone.h"
#include "UI.h"
class CollectionBase: public UI
{
public:
	CollectAnimation* _animation;

	ItemBase* _dropItem;
	int _dropItemCount;

	int _xSizeOfTile; //Ÿ�� x ���� ������
	int _ySizeOfTile; //Ÿ�� y ���� ������

	bool _isPassable; //������ �� �ִ°�?
	bool _isBeforDrop; //���� ���ΰ�?
	bool _isHitStart; //�ѹ��̶� hit �������� �ִ���

	int _maxHitGage;
	int _hitGage; //�������� ������

	bool hit(int power);
	bool isHitStart() { return _isHitStart; };

	vector<ItemBase*> getDropItem();

	CollectionBase(POINT pt, int maxHitGage, int xSizeOfTile, int ySizeOfTile);
	virtual ~CollectionBase() {};
};

