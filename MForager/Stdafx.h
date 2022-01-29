#pragma once
#include <SDKDDKver.h>

#define WIN32_LEAN_AND_MEAN 

#include <Windows.h>

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>
#include <assert.h>

#include <iostream>
#include <random>

#include <bitset>
#include <vector>
#include <map>

using namespace std;

//==Singleton
#define IMAGEMANAGER		ImageManager::getSingleton()
#define KEYMANAGER			KeyManager::getSingleton()
#define RND					RandomFunction::getSingleton()
//Singleton==

#define FPS		60

#define GREEN					RGB(0, 255, 0)
#define RED						RGB(255, 0, 0)
#define MAGENTA					RGB(255, 0, 255)
#define YELLOW					RGB(255, 255, 0)
#define WHITE_GRAY				RGB(200, 200, 200)
#define BLACK					RGB(0, 0, 0)
#define WHITE					RGB(255, 255, 255)

#define C_PG_HP_TOP				RGB(196,223,155)				
#define C_PG_HP_BOTTOM			RGB(124,197,118)		

#define C_PG_COLLECT_GAGE_TOP				RGB(255,98,963)		
#define C_PG_COLLECT_GAGE_BOTTOM			RGB(249,76,74)		
#define SEE_COLOR							RGB(0, 142, 239)	

#define TRANCE_COLOR			MAGENTA

// =============================================
// # ��ũ�� �Լ� # (Ŭ�������� �����Ҵ�� �κ� ����)
// =============================================
#define SAFE_DELETE(p)         {if(p != NULL) {delete (p); (p)=nullptr;}}
#define SAFE_DELETE_ARRAY(p)   {if(p) {delete[] (p); (p)=nullptr;}}
#define SAFE_RELEASE(p)         {if(p) {(p)->release(); (p)=nullptr;}}
#define SAFE_NULL_CHECK(p)      (p) == nullptr

typedef struct tagPointf {
	float x;
	float y;

	tagPointf() {
		this->x = 0;
		this->y = 0;
	}

	tagPointf(float x, float y) {
		this->x = x;
		this->y = y;
	}

	tagPointf(POINT pt) {
		this->x = (float)pt.x;
		this->y = (float)pt.y;
	}

	tagPointf(int x, int y) {
		this->x = (float)x;
		this->y = (float)y;
	}

	POINT toPOINT() { return POINT({ (int)x, (int)y }); };
} POINTF;

typedef struct tagDynamicRect
{
	LPRECT baseRc;

	int changeLeft;
	int changeTop;
	int changeRight;
	int changeBottom;

	tagDynamicRect(LPRECT bRc, int cLeft, int cTop, int cRight, int cBottom):
		baseRc(bRc), 
		changeLeft(cLeft), 
		changeTop(cTop), 
		changeRight(cRight), 
		changeBottom(cBottom) {

	}

	RECT getARect() {
		return {
			baseRc->left + changeLeft,
			baseRc->top + changeTop,
			baseRc->right + changeRight,
			baseRc->bottom + changeBottom
		};
	}

	RECT getRRect(RECT cameraRc) {
		RECT rc = getARect();
		return {
			rc.left - cameraRc.left,
			rc.top - cameraRc.top,
			rc.right - cameraRc.left,
			rc.bottom - cameraRc.top
		};
	}
} DRECT;


typedef struct tagPosInfo
{
	LPRECT rc;
	POINTF pt;
	int width;
	int height;

} POSINFO;

//==CommonFunction
#include "FileUtil.h"
#include "MapStruct.h"
#include "ImageManager.h"
#include "ShapeFunction.h"
#include "KeyManager.h"
#include "RandomFuction.h"
//CommonFunction==

//resource
#define	RES_MAP_PATH						"Resource/Map/mapsave.map"
#define	RES_MAP_SPRITE_PATH					"Resource/Map/map_sprite.bmp"
#define	RES_SAVE_MAP_PATH					"Resource/Map/save_map.map"
#define	RES_CURSOR_PATH						"Resource/images/cursor.bmp"
#define	RES_SELECT_CURSOR_PATH				"Resource/images/select_cursor.bmp"
#define RES_ROCK_NORMAL_STOP_1_PATH			"Resource/images/Rock/rock_normal_stop_1.bmp"
#define RES_ROCK_NORMAL_STOP_2_PATH			"Resource/images/Rock/rock_normal_stop_2.bmp"
#define RES_ROCK_IRON_STOP_1_PATH			"Resource/images/Rock/rock_iron_stop_1.bmp"
#define RES_ROCK_IRON_STOP_2_PATH			"Resource/images/Rock/rock_iron_stop_2.bmp"
#define RES_TREE_NORMAL_STOP_1_PATH			"Resource/images/Tree/tree_normal_stop.bmp"

//FOOD
#define RES_FOOD_BERRY_STOP_1_PATH			"Resource/images/Tree/tree_normal_stop.bmp"

//ITEM
#define RES_STONE_NORMAL_STOP_PATH			"Resource/images/Item/stone_stop.bmp"
#define RES_IRON_ORE_STOP_PATH		"Resource/images/Item/iron_ore_stop.bmp"
#define RES_WOOD_NORMAL_STOP_PATH			"Resource/images/Item/wood_stop.bmp"

#define RES_HEART_PATH						"Resource/images/Etc/heart.bmp"
#define RES_HEART_BLANK_PATH				"Resource/images/Etc/heart_blank.bmp"
#define RES_BACKGROUND_PATH					"Resource/images/background1.bmp"

#define TILE_SIZE				60

#define TILE_X_COUNT			20
#define TILE_Y_COUNT			20

#define CAMERA_TILE_X_COUNT		17
#define CAMERA_TILE_Y_COUNT		10

#define TILE_COUNT			TILE_X_COUNT * TILE_Y_COUNT

#define WINNAME			(LPSTR)(TEXT("MForager"))
#define WINSTYLE		WS_CAPTION | WS_SYSMENU
#define WINSTART_X		0
#define WINSTART_Y		0
#define WINSIZE_X		(TILE_SIZE * TILE_X_COUNT) + 700
#define WINSIZE_Y		(TILE_SIZE * TILE_Y_COUNT) + 100

#define CAMERASIZE_X		TILE_SIZE * CAMERA_TILE_X_COUNT
#define CAMERASIZE_Y		TILE_SIZE * CAMERA_TILE_Y_COUNT

#define PLAYER_SIZE_X		(TILE_SIZE + 10)
#define PLAYER_SIZE_Y		(TILE_SIZE + 10)
 
#define PLAYER_SPEED		5.0f

#define ABSOLUTE_POS		TRUE

extern HINSTANCE	_hInstance;
extern HWND			_hWnd;

extern int			_winsizeX;
extern int			_winsizeY;

extern int			_winRealSizeX;
extern int			_winRealSizeY;

enum MOVE_DIRECTION {
	M_TOP,
	M_BOTTOM,
	M_LEFT,
	M_RIGHT
};

enum CURSOR_DIRECTION {
	C_LEFT = 0,
	C_RIGHT
};

//DevelopMode
//#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

