#pragma once

enum RIK {
	MAP = 0,
	MAP_SPRITE,
	SAVE_MAP,
	CURSOR,
	SELECT_BOX,
	ROCK_NORMAL_STOP_1,
	ROCK_NORMAL_STOP_2,
	ROCK_IRON_STOP_1,
	ROCK_IRON_STOP_2,
	TREE_NORMAL_STOP,
	END
};

namespace UI_INFO {
	static int TILE_SIZE = 60;

	static int TILE_X_COUNT = 20;
	static int TILE_Y_COUNT = 20;

	static int TILE_COUNT = TILE_X_COUNT * TILE_Y_COUNT;

	static int CAMERA_TILE_X_COUNT = 17;
	static int CAMERA_TILE_Y_COUNT = 10;

	namespace MAP {
		static int MAP_X_SIZE = TILE_X_COUNT * TILE_SIZE;
		static int MAP_Y_SIZE = TILE_Y_COUNT * TILE_SIZE;

		static int MAP_SPRITE_X_COUNT = 9;
		static int MAP_SPRITE_Y_COUNT = 5;
	}
}

inline void CommonDatainit() {
	Json::Value resJson = LoadJsonFile("jsonFile/res_path_info.json");
	IMAGEMANAGER->addFrameImage((int)RIK::MAP_SPRITE, 
		resJson["map_sprite"].toStyledString().c_str(),
		UI_INFO::MAP::MAP_X_SIZE,
		UI_INFO::MAP::MAP_Y_SIZE,
		UI_INFO::MAP::MAP_SPRITE_X_COUNT,
		UI_INFO::MAP::MAP_SPRITE_Y_COUNT,
		true);
}

/*
inline void ResourceInit() {
	init(MAP, MAP_SPRITE);
}
inline void CommonDatainit() {
	Json::Value resJson = LoadJsonFile("jsonFile/res_path_info.json");

	RES_PATH::MAP = resJson["map"].toStyledString();
	RES_PATH::MAP_SPRITE = resJson["map_sprite"].toStyledString();
	RES_PATH::SAVE_MAP = resJson["save_map"].toStyledString();
	RES_PATH::CURSOR = resJson["cursor"].toStyledString();
	RES_PATH::SELECT_BOX = resJson["select_box"].toStyledString();

	//COLLECT
	RES_PATH::ROCK_NORMAL_STOP_1 = resJson["rock_normal_stop_1"].toStyledString();
	RES_PATH::ROCK_NORMAL_STOP_2 = resJson["rock_normal_stop_2"].toStyledString();
	RES_PATH::ROCK_IRON_STOP_1 = resJson["rock_iron_stop_1"].toStyledString();
	RES_PATH::ROCK_IRON_STOP_2 = resJson["rock_iron_stop_2"].toStyledString();
	RES_PATH::TREE_NORMAL_STOP = resJson["tree_normal_stop_1"].toStyledString();
}
*/
