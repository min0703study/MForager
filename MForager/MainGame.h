#pragma once
#include "GameNode.h"

#include "PlayerManager.h"
#include "CollectionManager.h"
#include "ItemManager.h"
#include "MapManager.h"
#include "CameraManager.h"
#include "UIManager.h"

class MainGame: public GameNode
{
private:
	MapManager* _mm;
	CollectionManager* _cm;
	PlayerManager* _pm;
	ItemManager* _im;
	CameraManager* _cmm;
	UIManager* _uim;
public:
	HRESULT init(void);
	void update(void);
	void release(void);
	void render(void);

	void mouseMoveEvent(POINT& currentPoint) override;
	void clickEvent(POINT& pt, bool isClickDown) override;
};
