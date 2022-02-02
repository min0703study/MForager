#pragma once
#include "UI.h"
#include "ProgressBar.h"
#include "SelectPtBox.h"
#include "NightFocus.h"
#include "Heart.h"
#include "Camera.h"
#include "Map.h"
#include "CustomCursor.h"

class CollectionManager;
class PlayerManager;

class UIManager
{
	
private:
	vector<FixedUI*> _fixedUiList;
	vector<UI*> _uiList;
	vector<RECT*> _developUi;



	PointF* _currentPtf;

	SelectPtBox* _selectPtBox;
	NightFocus* _nightFocus;

	Heart* _lifeCount[3];
	ProgressBar* _hpGage;
	
	CURSOR_DIRECTION _cursorDirection;

	int _playTimeSec;

public:
	CustomCursor* _cursor;

	UI* _furanace;
	Camera* _camera;
	CollectionManager* _collectionManager;
	PlayerManager* _playerManager;

	HRESULT init();
	HRESULT initCamera();

	void moveCamera(float x, float y, MOVE_DIRECTION mDirection);

	Map* map;
	void update();
	void release();
	void render(HDC hdc);

	void addFixedUI(FixedUI * ui);
	void addUI(UI* ui);
	void addf(UI * ui);
	void addMap(UI* map);

	void deleteUI(UI* ui);

	void mouseMoveEvent(POINT& currentPoint);

	void clickEvent(POINT & pt, bool isClickDown);
	void addGameTime();

	void addDevelopUI(LPRECT rc);

	void changeCursorDirection(CURSOR_DIRECTION dirc);

	int getCursorDirection() { return _cursorDirection; };
};

