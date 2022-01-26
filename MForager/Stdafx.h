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

#define TRANCE_COLOR			MAGENTA

// =============================================
// # 매크로 함수 # (클래스에서 동적할당된 부분 해제)
// =============================================
#define SAFE_DELETE(p)         {if(p != NULL) {delete (p); (p)=nullptr;}}
#define SAFE_DELETE_ARRAY(p)   {if(p) {delete[] (p); (p)=nullptr;}}
#define SAFE_RELEASE(p)         {if(p) {(p)->release(); (p)=nullptr;}}

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
#define RES_ROCK_NORMAL_STOP_PATH			"Resource/images/Rock/rock_normal_stop.bmp"
#define RES_STONE_NORMAL_STOP_PATH			"Resource/images/Item/stone_stop.bmp"
#define RES_HEART_PATH						"Resource/images/Etc/heart.bmp"
#define RES_HEART_BLANK_PATH				"Resource/images/Etc/heart_blank.bmp"

#define TILE_SIZE				60
#define TILE_X_COUNT			14
#define TILE_Y_COUNT			14	
#define TILE_COUNT			TILE_X_COUNT * TILE_Y_COUNT

#define WINNAME			(LPSTR)(TEXT("Forager"))
#define WINSTYLE		WS_POPUPWINDOW | WS_MAXIMIZE
#define WINSTART_X		0
#define WINSTART_Y		0
#define WINSIZE_X		TILE_SIZE * TILE_X_COUNT
#define WINSIZE_Y		TILE_SIZE * TILE_Y_COUNT

#define PLAYER_SIZE_X		(TILE_SIZE + 10)
#define PLAYER_SIZE_Y		(TILE_SIZE + 10)
#define PLAYER_SPEED		7

extern HINSTANCE	_hInstance;
extern HWND			_hWnd;

extern int			_winsizeX;
extern int			_winsizeY;

extern int			_winRealSizeX;
extern int			_winRealSizeY;