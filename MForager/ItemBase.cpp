#include "Stdafx.h"
#include "ItemBase.h"

ItemBase::ItemBase(POINTF pt, int width, int height): UI(pt, width, height), _ItemId(getId()) {
	_animation = new ItemAnimation;
	_bAnimation = _animation;
}
