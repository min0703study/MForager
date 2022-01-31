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

	int _xSizeOfTile; //타일 x 기준 사이즈
	int _ySizeOfTile; //타일 y 기준 사이즈

	bool _isPassable; //지나갈 수 있는가?
	bool _isBeforDrop; //수집 전인가?
	bool _isHitStart; //한번이라도 hit 당한적이 있는지

	int _maxHitGage;
	int _hitGage; //지워지는 게이지

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

