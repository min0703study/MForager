#include "ItemBase.h"

#define STONE_WIDTH		50
#define STONE_HEIGHT	50

class Wood : public ItemBase
{
public:
	Wood(POINTF pt, int width = STONE_WIDTH, int height = STONE_HEIGHT);
	int getId() override { return 2; }

	void initAnimation() override;
};