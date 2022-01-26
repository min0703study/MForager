#pragma once
#include "GameNode.h"

#include "Map.h"
#include "PlayerManager.h"
#include "CollectionManager.h"
#include "ItemManager.h"

class MainGame: public GameNode
{
private:
	Map* _map;

	CollectionManager* _cm;
	PlayerManager* _pm;
	ItemManager* _im;

public:
	HRESULT init(void);
	void update(void);
	void release(void);
	void render(void);

	void mouseMoveEvent(POINT& currentPoint) override;
	void clickEvent(POINT& pt, bool isClickDown) override;

	void makeRandomCollection();
};
