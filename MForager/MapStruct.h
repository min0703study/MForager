#pragma once

//Ÿ��
enum GROUND {
	LEFT_TOP_CORNER = 0,
	TOP,
	RIGHT_TOP_CORNER,
	RIGHT_BOTTOM_INSIDE_CORNER,
	LEFT_BOTTOM_INSIDE_CORNER,
	TOP_FLOWER,
	RIGHT_TOP_CORNER_1,
	RIGHT_OVER_FLOWER,
	RIGHT_OVER_GRASS,

	LEFT = 9,
	CENTER,
	RIGHT,
	RIGHT_TOP_INSIDE_CORNER,
	LEFT_TOP_INSIDE_CORNER,
	SEE,
	SEE_TO_GROUND_LEFT,
	SEE_TO_GROUND_CENTER,
	SEE_TO_GROUND_RIGHT,
	
	LEFT_BOTTOM_CORNER = 18,
	BOTTOM,
	RIGHT_BOTTOM_CORNER,
	CENTER_1,
	CENTER_2,
	CENTER_3,
	CENTER_4,
	CENTER_5,
	CENTER_6,
	
	CENTER_7 = 27,
	CENTER_8,
	CENTER_9,
	ALONE,
	LEFT_TOP_BOTTOM_CORNER,
	TOP_LEFT_RIGHT_CORNER,
	RIGHT_TOP_BOTTOM_CORNER,
	LEFT_ALONE,
	RIGHT_ALONE
};

const int COLLISION_GROUND[4] = {
		SEE,
		SEE_TO_GROUND_LEFT,
		SEE_TO_GROUND_CENTER,
		SEE_TO_GROUND_RIGHT,
};


//���
enum PICKAXE {
	NOMAL_PICKAXE
};

typedef struct tagTile
{
	GROUND ground;

	RECT rc;
	POINT pt;
} TILE;