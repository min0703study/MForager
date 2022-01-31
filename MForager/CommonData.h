#pragma once
enum RES {
	MAP = 700,
	MAP_SPRITE,
	SAVE_MAP,
	CURSOR,
	SELECT_BOX,
	ROCK_NORMAL_STOP_1,
	ROCK_NORMAL_STOP_2,
	ROCK_IRON_STOP_1,
	ROCK_IRON_STOP_2,
	TREE_NORMAL_STOP,
	PICKAXES_NORMAL,
	END
};

namespace UI_INFO {
	static int CAMERA_TILE_X_COUNT = 17;
	static int CAMERA_TILE_Y_COUNT = 10;

	namespace MAP {
		static int TILE_SIZES = 60;

		const static int TILE_X_COUNT = 20;
		const static int TILE_Y_COUNT = 20;

		//static int TILE_SIZE = 60;
		const static int TILE_COUNT = 20 * 20;

		const static int X_COUNT = 20;
		const static int Y_COUNT = 20;

		const static int X_SIZE = 60 * 20;
		const static int Y_SIZE = 60 * 20;

		const static int SPRITE_X_COUNT = 9;
		const static int SPRITE_Y_COUNT = 5;

		const static int SPRITE_X_SIZE = TILE_SIZES * SPRITE_X_COUNT;
		const static int SPRITE_Y_SIZE = TILE_SIZES * SPRITE_Y_COUNT;
	}
}

namespace ITEM {
	namespace WOOD{
		enum ID {
			WOOD_ID
		};

		enum TYPE {
			WOOD
		};
	}
	namespace STONE {
		enum ID {
			STONE_ID,
			COAL_ID,
			IRON_ORE_ID,
			GOLD_ORE_ID
		};

		enum TYPE {
			STONE,
			COAL,
			IRON_ORE,
			GOLD_ORE
		};

	}
}


namespace COLLECT {
	namespace ROCK {
		enum TYPE {
			ROCK,
			COAL,
			IRON,
			GOLD
		};
	}

	namespace TREE {
		enum TYPE {
			NOMAL
		};
	}
}

namespace INDUSTRIAL {
	namespace CRAFTING {
		struct INGEDIENTS
		{
			struct NeedItem {
				int _itemId;
				int _itemCount;
			};

			int _craftingItemId;
			int _needLevelMin;
			int _makeTime;
			vector<NeedItem*> _needItemList;
			INGEDIENTS() {};
		};

		static vector<INGEDIENTS*> sFuranaceList;
	}
}

inline void CommonDatainit() {
	Json::Value resJson = LoadJsonFile("jsonFile/res_path_info.json");
	IMAGEMANAGER->addFrameImage((int)RES::MAP_SPRITE, 
		resJson["map_sprite"].asCString(),
		UI_INFO::MAP::SPRITE_X_SIZE,
		UI_INFO::MAP::SPRITE_Y_SIZE,
		UI_INFO::MAP::SPRITE_X_COUNT,
		UI_INFO::MAP::SPRITE_Y_COUNT,
		true);

	GDIPLUSMANAGER->addImage((int)RES::PICKAXES_NORMAL,
		resJson["pickaxes_normal"].asCString(),
		UI_INFO::MAP::SPRITE_X_SIZE,
		UI_INFO::MAP::SPRITE_Y_SIZE,
		true);

	Json::Value furance = LoadJsonFile("jsonFile/furanace_crafting.json");
	for (Json::Value::iterator itRoot = furance.begin(); itRoot != furance.end(); itRoot++) {
		INDUSTRIAL::CRAFTING::INGEDIENTS* _ingedients = new INDUSTRIAL::CRAFTING::INGEDIENTS;
		_ingedients->_craftingItemId = (*itRoot)["crafting_item_id"].asInt();
		_ingedients->_needLevelMin = (*itRoot)["need_level_min"].asInt();
		_ingedients->_makeTime = (*itRoot)["make_time"].asInt();
		
		for (Json::Value::iterator itMakeItem = (*itRoot)["make_item"].begin(); itMakeItem != (*itRoot)["make_item"].end(); itMakeItem++) {
			INDUSTRIAL::CRAFTING::INGEDIENTS::NeedItem* _makeItem = new INDUSTRIAL::CRAFTING::INGEDIENTS::NeedItem;
			_makeItem->_itemId = (*itMakeItem)["item_id"].asInt();
			_makeItem->_itemCount = (*itMakeItem)["count"].asInt();
		}
	}
	cout << endl;
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
