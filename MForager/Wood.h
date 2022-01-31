#include "ItemBase.h"

#define STONE_WIDTH		50
#define STONE_HEIGHT	50

using namespace ITEM::WOOD;

class Wood : public ItemBase
{
private:
	TYPE _type;
public:
	Wood(PointF pt, int width = STONE_WIDTH, int height = STONE_HEIGHT);
	
	inline int setIdForType(TYPE _type);
	void initAnimation() override;

};