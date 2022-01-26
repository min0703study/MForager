#pragma once
#include "CollectionBase.h"
#include "Rock.h"
#include "Tree.h"
#include "ProgressBar.h"

#define COLLECT_OBJECT_COUNT	12

class CollectionManager
{
public:
	CollectionBase* _collectObjects[COLLECT_OBJECT_COUNT];
	ProgressBar* _hitGage;

	CollectionBase* getPtInCollect(POINT pt);
	CollectionBase* getSelectCollect();

	bool _isSelect;
	int _selectIndex;

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	bool loadSaveFile();

	void makeRandomCollection(int x, int y);

	bool hitCollect(int power);

	vector<ItemBase*> getDropItem();

	bool isFull();

	inline void setSelectFlag(bool isSelect) { _isSelect = isSelect; };
	
};

