#pragma once

enum RES_KEY {
	MAP = 1000,
	MAP_SPRITE,
	CURSOR,
	SELECT_BOX,
	INVENTORY_BOX,
	ROCK_NORMAL_STOP_1,
	ROCK_NORMAL_STOP_2,
	ROCK_IRON_STOP_1,
	ROCK_IRON_STOP_2,
	TREE_NORMAL_STOP,
	BERRY_BUSH_STOP,
	WOOD_NORMAL_STOP,
	PICKAXES_NORMAL,
	HEART,
	HEART_BLANK,
	PLAYER_STOP_R,
	PLAYER_STOP_L,
	PLAYER_WALK_R,
	PLAYER_WALK_L,
	PLAYER_ACTION_R,
	PLAYER_ACTION_L,
	BERRY_STOP,
	CITRUS_STOP,
	FURANACE_STOP,
	STONE_NORMAL_STOP,
	IRON_ORE_STOP,
	COAL_STOP,
	FURANACE_MENU,
	PICKAXES = 7001,
	END
};

namespace ETC{
	namespace CURSOR {
		namespace UI_INFO {
			static const int X_SIZE = 20;
			static const int Y_SIZE = 20;
		}
	}

	namespace SELECT_BOX {
		namespace UI_INFO {
			static const int X_SIZE = 70;
			static const int Y_SIZE = 70;

			const static int SPRITE_X_COUNT = 5;
			const static int SPRITE_Y_COUNT = 1;
		}
	}

}

namespace MAP_C {
	namespace UI_INFO {
		static int CAMERA_TILE_X_COUNT = 17;
		static int CAMERA_TILE_Y_COUNT = 10;

		static int CAMERA_X_SIZE = CAMERA_TILE_X_COUNT * 60;
		static int CAMERA_Y_SIZE = CAMERA_TILE_Y_COUNT * 60;

		static int CAMERA_R_X_SIZE = CAMERA_X_SIZE + 20;
		static int CAMERA_R_Y_SIZE = CAMERA_Y_SIZE - 40;

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

namespace PLAYER {
	namespace UI_INFO {
		const static int X_SIZE = 60;
		const static int Y_SIZE = 60;

		const static float START_X = MAP_C::UI_INFO::CAMERA_X_SIZE / 2.0f - 35.0f;
		const static float START_Y = MAP_C::UI_INFO::CAMERA_Y_SIZE / 2.0f - 35.0f;

		const static int STOP_SPRITE_X = 3;
		const static int STOP_SPRITE_Y = 1;

		const static int WALK_SPRITE_X = 3;
		const static int WALK_SPRITE_Y = 1;
	}

	namespace DEFAULT_VALUE {
		const static int POWER = 50;
		const static int HP = 100;
		const static int LIFE_COUNT = 3;
		const static int HIT_EXP = 3;
		const static int HIT_MINUS_HP = 1;
	}
}

namespace INDUSTRIAL {
	namespace FURANACE {
		namespace UI_INFO {
			const static float X_SIZE = MAP_C::UI_INFO::TILE_SIZES * 2;
			const static float Y_SIZE = MAP_C::UI_INFO::TILE_SIZES * 2.5;
		}

		namespace MENU {
			namespace UI_INFO {
				const static float X_SIZE = 300;
				const static float Y_SIZE = 400;

				const static float START_X = MAP_C::UI_INFO::CAMERA_X_SIZE / 2.0f - (X_SIZE / 2.0f);
				const static float START_Y = MAP_C::UI_INFO::CAMERA_Y_SIZE / 2.0f - (Y_SIZE / 2.0f);
			}
		}
	}
}

namespace COLLECT {
	namespace UI_INFO{
		namespace PROGRESS {
			const static float SPACE_SIZE = 17.0f;

			const static float X_SIZE = 40;
			const static float Y_SIZE = 15;

			const static COLORREF TCOLOR = RGB(255, 98, 963);
			const static COLORREF BCOLOR = RGB(249, 76, 74);
		}
	}
}

namespace MAIN {
	namespace LIFE_COUNT {
		namespace UI_INFO {
			const static float START_X = 10;
			const static float START_Y = 10;

			const static float X_SIZE = 30;
			const static float Y_SIZE = 27;

			const static float SPACE_SIZE = 3;
		}
	}

	namespace HP_PROGRESS_BAR {
		namespace UI_INFO {
			const static float START_X = 10.0f;
			const static float START_Y = LIFE_COUNT::UI_INFO::START_Y + LIFE_COUNT::UI_INFO::Y_SIZE + 5.0f;

			const static float X_SIZE = 65;
			const static float Y_SIZE = 28;

			const static COLORREF TCOLOR =	RGB(196, 223, 155);
			const static COLORREF BCOLOR = RGB(124, 197, 118);
		}
	}

	namespace EXP_PROGRESS_BAR {
		namespace UI_INFO {

			const static float X_SIZE = 600;
			const static float Y_SIZE = 30;

			const static float START_X = MAP_C::UI_INFO::CAMERA_X_SIZE / 2 - X_SIZE/2.0f;
			const static float START_Y = 7.0f;

			const static COLORREF TCOLOR = RGB(255, 242, 117);
			const static COLORREF BCOLOR = RGB(255, 191, 54);
		}
	}

	namespace TOOLBAR {
		namespace UI_INFO {
			static const int X_SIZE = 60;
			static const int Y_SIZE = 60;

			static const int START_Y = MAP_C::UI_INFO::CAMERA_R_Y_SIZE - Y_SIZE;
		}
	}
}

namespace MENU {
	namespace INVENTORY {
		namespace UI_INFO {
			const static int BOX_SIZE_X = 70;
			const static int BOX_SIZE_Y = 70;
			const static int BOX_X_COUNT = 8;
			const static int BOX_Y_COUNT = 2;
			const static int BOX_SPACE = 10;
			const static int FRAME_X_SIZE = BOX_SIZE_X * BOX_X_COUNT + BOX_SPACE * (BOX_X_COUNT - 1);
			const static int FRAME_Y_SIZE = BOX_SIZE_Y * BOX_Y_COUNT + BOX_SPACE * (BOX_Y_COUNT - 1);
		}

		enum ID {
			WOOD_ID
		};

		enum TYPE {
			WOOD
		};
	}
}

namespace ITEM {
	namespace WOOD{
		namespace UI_INFO {
			const static int X_SIZE = 60;
			const static int Y_SIZE = 60;
		}

		enum ID {
			WOOD_ID = 200,
		};

		enum TYPE {
			WOOD
		};
	}
	namespace STONE {
		enum ID {
			STONE_ID = 7000,
			COAL_ID = 7001,
			IRON_ORE_ID = 7002,
			GOLD_ORE_ID = 7003
		};

		enum TYPE {
			STONE,
			COAL,
			IRON_ORE,
			GOLD_ORE
		};

	}
	namespace FOOD {
		enum ID {
			BERRY_ID = 300
		};
		enum TYPE {
			BERRY,
			CIR
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

		namespace DEFAULT_VALUE {
			const static int ROCK_HIT_GAGE = 300;
			const static int COAL_HIT_GAGE = 300;
			const static int IRON_HIT_GAGE = 300;
		}
	}

	namespace TREE {
		enum TYPE {
			NOMAL
		};

		namespace DEFAULT_VALUE {
			const static int TREE_HIT_GAGE = 300;
		}
	}

	namespace BERRY_BUSH {
		enum TYPE {
			NOMAL
		};

		namespace DEFAULT_VALUE {
			const static int BERRY_BUSH_HIT_GAGE = 10;
		}
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

	IMAGEMANAGER->addFrameImage(RES_KEY::MAP_SPRITE,
		resJson["map_sprite"].asCString(),
		MAP_C::UI_INFO::SPRITE_X_SIZE,
		MAP_C::UI_INFO::SPRITE_Y_SIZE,
		MAP_C::UI_INFO::SPRITE_X_COUNT,
		MAP_C::UI_INFO::SPRITE_Y_COUNT,
		true);

	IMAGEMANAGER->addFrameImage(RES_KEY::SELECT_BOX,
		resJson["select_box"].asCString(),
		ETC::SELECT_BOX::UI_INFO::X_SIZE * ETC::SELECT_BOX::UI_INFO::SPRITE_X_COUNT,
		ETC::SELECT_BOX::UI_INFO::Y_SIZE * ETC::SELECT_BOX::UI_INFO::SPRITE_Y_COUNT,
		ETC::SELECT_BOX::UI_INFO::SPRITE_X_COUNT,
		ETC::SELECT_BOX::UI_INFO::SPRITE_Y_COUNT,
		true);


	IMAGEMANAGER->addFrameImage(RES_KEY::PLAYER_STOP_R, 
		resJson["player_stop_right"].asCString(),
		PLAYER::UI_INFO::STOP_SPRITE_X * PLAYER::UI_INFO::X_SIZE,
		PLAYER::UI_INFO::STOP_SPRITE_Y * PLAYER::UI_INFO::Y_SIZE,
		PLAYER::UI_INFO::STOP_SPRITE_X,
		PLAYER::UI_INFO::STOP_SPRITE_Y,
		true);

	IMAGEMANAGER->addFrameImage(RES_KEY::PLAYER_STOP_L,
		resJson["player_stop_left"].asCString(),
		PLAYER::UI_INFO::STOP_SPRITE_X * PLAYER::UI_INFO::X_SIZE,
		PLAYER::UI_INFO::STOP_SPRITE_Y * PLAYER::UI_INFO::Y_SIZE,
		PLAYER::UI_INFO::STOP_SPRITE_X,
		PLAYER::UI_INFO::STOP_SPRITE_Y,
		true);

	IMAGEMANAGER->addFrameImage(RES_KEY::PLAYER_WALK_R,
		resJson["player_walk_right"].asCString(),
		PLAYER::UI_INFO::WALK_SPRITE_X * PLAYER::UI_INFO::X_SIZE,
		PLAYER::UI_INFO::WALK_SPRITE_Y * PLAYER::UI_INFO::Y_SIZE,
		PLAYER::UI_INFO::WALK_SPRITE_X,
		PLAYER::UI_INFO::WALK_SPRITE_Y,
		true);

	IMAGEMANAGER->addFrameImage((int)RES_KEY::PLAYER_WALK_L,
		resJson["player_walk_left"].asCString(),
		PLAYER::UI_INFO::WALK_SPRITE_X * PLAYER::UI_INFO::X_SIZE,
		PLAYER::UI_INFO::WALK_SPRITE_Y * PLAYER::UI_INFO::Y_SIZE,
		PLAYER::UI_INFO::WALK_SPRITE_X,
		PLAYER::UI_INFO::WALK_SPRITE_Y,
		true);

	IMAGEMANAGER->addFileImage((int)RES_KEY::PLAYER_ACTION_R,
		resJson["player_action_right"].asCString(),
		PLAYER::UI_INFO::X_SIZE,
		PLAYER::UI_INFO::Y_SIZE, true);

	IMAGEMANAGER->addFileImage((int)RES_KEY::PLAYER_ACTION_L,
		resJson["player_action_left"].asCString(),
		PLAYER::UI_INFO::X_SIZE,
		PLAYER::UI_INFO::Y_SIZE, true);

	IMAGEMANAGER->addFileImage((int)RES_KEY::FURANACE_MENU,
		resJson["furanace_menu"].asCString(),
		INDUSTRIAL::FURANACE::MENU::UI_INFO::X_SIZE,
		INDUSTRIAL::FURANACE::MENU::UI_INFO::Y_SIZE, true);


	IMAGEMANAGER->addFileImage((int)RES_KEY::WOOD_NORMAL_STOP,
		resJson["wood_stop"].asCString(),
		ITEM::WOOD::UI_INFO::X_SIZE,
		ITEM::WOOD::UI_INFO::Y_SIZE, true);

	IMAGEMANAGER->addFileImage((int)RES_KEY::COAL_STOP,
		resJson["coal_stop"].asCString(),
		ITEM::WOOD::UI_INFO::X_SIZE,
		ITEM::WOOD::UI_INFO::Y_SIZE, true);


	IMAGEMANAGER->addFileImage((int)RES_KEY::BERRY_STOP,			resJson["berry_stop"].asCString(), 50, 50, true);
	IMAGEMANAGER->addFileImage((int)RES_KEY::STONE_NORMAL_STOP,		resJson["stone_stop"].asCString(), 50, 50, true);
	IMAGEMANAGER->addFileImage((int)RES_KEY::IRON_ORE_STOP,			resJson["iron_ore_stop"].asCString(), 50, 50, true);
	IMAGEMANAGER->addFileImage((int)RES_KEY::BERRY_BUSH_STOP,		resJson["berry_bush_stop"].asCString(), 50, 50, true);
	IMAGEMANAGER->addFileImage((int)RES_KEY::HEART,					resJson["heart"].asCString(), MAIN::LIFE_COUNT::UI_INFO::X_SIZE, MAIN::LIFE_COUNT::UI_INFO::Y_SIZE, true);
	IMAGEMANAGER->addFileImage((int)RES_KEY::HEART_BLANK,			resJson["heart_blank"].asCString(), MAIN::LIFE_COUNT::UI_INFO::X_SIZE, MAIN::LIFE_COUNT::UI_INFO::Y_SIZE, true);
	IMAGEMANAGER->addFileImage((int)RES_KEY::FURANACE_STOP,			resJson["furanace"].asCString(), INDUSTRIAL::FURANACE::UI_INFO::X_SIZE, INDUSTRIAL::FURANACE::UI_INFO::Y_SIZE, true);

	GDIPLUSMANAGER->addImage((int)RES_KEY::PICKAXES_NORMAL,			resJson["pickaxes_normal"].asCString());
	GDIPLUSMANAGER->addImage((int)RES_KEY::PICKAXES,				resJson["pickaxes_normal"].asCString());
	GDIPLUSMANAGER->addImage((int)RES_KEY::CURSOR,					resJson["cursor"].asCString());
	GDIPLUSMANAGER->addImage((int)RES_KEY::SELECT_BOX,				resJson["select_box"].asCString());
	GDIPLUSMANAGER->addImage((int)RES_KEY::ROCK_NORMAL_STOP_1,		resJson["rock_normal_stop_1"].asCString());
	GDIPLUSMANAGER->addImage((int)RES_KEY::ROCK_NORMAL_STOP_2,		resJson["rock_normal_stop_2"].asCString());
	GDIPLUSMANAGER->addImage((int)RES_KEY::ROCK_IRON_STOP_1,		resJson["rock_iron_stop_1"].asCString());
	GDIPLUSMANAGER->addImage((int)RES_KEY::ROCK_IRON_STOP_2,		resJson["rock_iron_stop_2"].asCString());

	GDIPLUSMANAGER->addImage((int)RES_KEY::CITRUS_STOP,				resJson["citrus_stop"].asCString());
	GDIPLUSMANAGER->addImage((int)RES_KEY::INVENTORY_BOX,			resJson["inventory_box"].asCString());

	cout << endl;
}

inline void getFuranaceList(OUT vector<INDUSTRIAL::CRAFTING::INGEDIENTS*> &_list) {
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
			_ingedients->_needItemList.push_back(_makeItem);
		}
		_list.push_back(_ingedients);
	}
	cout<<endl;
}
