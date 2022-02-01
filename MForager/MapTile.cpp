#include "Stdafx.h"
#include "MapTile.h"

void MapTile::play(HDC hdc)
{
	IMAGEMANAGER->setCurrentFrame(MAP_SPRITE, _xFrame, _yFrame);
	IMAGEMANAGER->frameRender(MAP_SPRITE, hdc, getRPt());
}
