#include "ItemBase.h"

#define STONE_WIDTH		50
#define STONE_HEIGHT	50

class Wood : public ItemBase
{
private:
	typedef ITEM::WOOD::TYPE TYPE;
	typedef ITEM::WOOD::ID ID;
	TYPE _type;
public:

	Wood(PointF pt);
	inline int setIdForType(TYPE _type);
};