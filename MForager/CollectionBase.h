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

