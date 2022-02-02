#pragma once
#include "CollectAnimation.h"
#include "ItemBase.h"
#include "UI.h"

class CollectionBase: public UI
{
public:
	ItemBase* _dropItem;
	int _dropItemCount;

	SRECT _hitRc;

	int _xSizeOfTile; //Ÿ�� x ���� ������
	int _ySizeOfTile; //Ÿ�� y ���� ������

	bool _isPassable; //������ �� �ִ°�?
	bool _isBeforDrop; //���� ���ΰ�?
	bool _isHitStart; //�ѹ��̶� hit �������� �ִ���

	int _maxHitGage;
	int _hitGage; //�������� ������

	CollectionBase(PointF hitPt, int xSizeOfTile, int ySizeOfTile);

	bool hit(int power);
	bool isHitStart() { return _isHitStart; };
	
	RECT getHitRRect() { 
		return _hitRc.getRect(getRRc()); 
	}

	PointF getHitAPt() {
		RECT rc = getHitARc();
		return PointF{ (REAL)rc.left, (REAL)rc.top };
	};

	RECT getHitARc() {
		return _hitRc.getRect(*getARc());
	};

	PointF getProgressAPt() { 
		RECT rc = getHitARc();
		return { ((REAL)rc.left + (REAL)rc.right) / 2 - (COLLECT::UI_INFO::PROGRESS::X_SIZE / 2) ,(REAL)rc.bottom + COLLECT::UI_INFO::PROGRESS::SPACE_SIZE };
	}

	virtual vector<ItemBase*> getDropItem();

	void setAnimationImageAuto(CollectAnimation::State state, string key, char * fileName, int frameXCount, int frameYCount);
	~CollectionBase() {
		
	};
};

