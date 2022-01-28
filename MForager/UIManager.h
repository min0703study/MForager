#pragma once
#include "UI.h"
#include "CameraManager.h"
#include "SelectPtBox.h"

class CollectionManager;
class PlayerManager;

class UIManager
{
	
private:
	enum Direction {
		D_LEFT = 0,
		D_RIGHT
	};

	vector<UI*> _uiList;
	vector<UI*>::iterator _iUiList;

	POINT _currentPt;
	SelectPtBox* _selectPtBox;
	
	Direction _cursorDirection;
public:
	CameraManager* _cameraManager;
	CollectionManager* _collectionManager;
	PlayerManager* _playerManager;

	HRESULT init();

	void update();
	void release();
	void render(HDC hdc);

	void addUI(UI* ui);
	void deleteUI(UI* ui);
	POINTF getRelPt(UI * ui);
	RECT getRelRect(UI * ui);
	RECT getRelCenterPt(UI * ui);

	void mouseMoveEvent(POINT& currentPoint);
	void clickEvent(POINT & pt, bool isClickDown);

	int getCursorDirection() { return _cursorDirection; };
};

