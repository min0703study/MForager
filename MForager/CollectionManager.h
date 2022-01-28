#pragma once
#include "CollectionBase.h"
#include "ProgressBar.h"
#include "Rock.h"

class MapManager;
class UIManager;
class ItemManager;

#define COLLECT_OBJECT_COUNT	12

class CollectionManager
{
public:
	MapManager* _mapManager;
	UIManager* _uiManager;
	ItemManager* _itemManager;
public:
	CollectionBase* _collectObjects[COLLECT_OBJECT_COUNT];
	ProgressBar* _hitGage[COLLECT_OBJECT_COUNT];
	CollectionBase* getSelectCollect();

	bool _isSelect;
	int _selectIndex;

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	void makeRandomCollection();
	void hitCollect(int power);

	bool isFull();

	bool isPtInCollect(POINT pt);
	

	inline void setSelectFlag(bool isSelect) { _isSelect = isSelect; };
	
};

