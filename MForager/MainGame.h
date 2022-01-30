#pragma once
#include "GameNode.h"

#include "PlayerManager.h"
#include "CollectionManager.h"
#include "ItemManager.h"
#include "MapManager.h"
#include "UIManager.h"

#define TICK_TIMER_ID			201

class MainGame: public GameNode
{
private:
	MapManager* _mm;
	CollectionManager* _cm;
	PlayerManager* _pm;
	ItemManager* _im;
	UIManager* _uim;
public:
	HRESULT init(void);
	void update(void);
	void release(void);
	void render(void);
	
	void timerEvent(int timerId) override;
	void mouseMoveEvent(POINT& currentPoint) override;
	void clickEvent(POINT& pt, bool isClickDown) override;
};
