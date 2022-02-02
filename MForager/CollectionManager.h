#pragma once
#include "CollectionBase.h"
#include "ProgressBar.h"

#include "Rock.h"
#include "Tree.h"
#include "BerryBush.h"

class MapManager;
class UIManager;
class ItemManager;

#define COLLECT_OBJECT_COUNT	23

class CollectionManager
{
public:
#if DEVELOP_MODE
	RECT* _collectBox[COLLECT_OBJECT_COUNT];
#endif
	MapManager* _mapManager;
	UIManager* _uiManager;
	ItemManager* _itemManager;

	CollectionBase* _collectObjects[COLLECT_OBJECT_COUNT];
	ProgressBar* _hitGage[COLLECT_OBJECT_COUNT];

	bool isPtAreadyObject(int x, int y);

	CollectionBase* getSelectCollect();

	bool _isSelect;
	int _selectIndex;


	void makeRandomCollection(bool isInit);
	bool hitCollect(int power);

	bool isFull();
	
	HRESULT init();
	void release();
	void update();

	bool isPtInCollect(POINT pt);
	inline void setSelectFlag(bool isSelect) { _isSelect = isSelect; };
};

