#pragma once
#include "CollectAnimation.h"
#include "ItemBase.h"
#include "UI.h"

class CollectionBase: public UI
{
public:
	CollectAnimation* _animation;

	ItemBase* _dropItem;
	int _dropItemCount;

	PointF _hitPt;

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
	
	RECT getHitRect() { return *MakeLPRECT(_hitPt, 60.0f, 60.0f); }
	PointF getHitPt() { return _hitPt; }
	PointF getProgressPt() { 
		RECT rc = getHitRect();
		return { (REAL)rc.left ,(REAL)rc.bottom + 5 };
	}

	virtual vector<ItemBase*> getDropItem();
	void initAnimation() override;
	void setAnimationImageAuto(CollectAnimation::State state, string key, char * fileName, int frameXCount, int frameYCount);
	virtual ~CollectionBase() {};
};

