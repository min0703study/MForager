#include "Stdafx.h"
#include "Food.h"

Food::Food(POINTF pt, TYPE type):
	ItemBase(pt, TILE_SIZE, TILE_SIZE)
{
	initAnimation();

	switch (type)
	{
		case Berry:
			setStopImage((int)ItemAnimation::State::stop, RES_ROCK_NORMAL_STOP_1_PATH);
			_energy = 5;
			break;
		case Citrus:
			setStopImage((int)ItemAnimation::State::stop, RES_ROCK_NORMAL_STOP_1_PATH);
			_energy = 5;
			break;
	}
}