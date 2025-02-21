#ifndef CORE_ENGINE_H
#define CORE_ENGINE_H

//#include <stdio.h>
#include "common.h"



#include "SDL.h"
#include "input_sys.h"
#include "display_engine.h"
#include "constants.h"
#include "gamemap.h"
////#include "game_defines.h"
#include "game_data.h"
//#include "constants.h"
//#include "monsters.h"
//#include "spells.h"
//#include "ui_display.h"
//#include "objects.h"
//#include "player.h"
#include "build_level.h"
//#include "inventory.h"
//#include "shop.h"

class Core_Engine
{

public:

	Core_Engine();

    bool Init();
	Display_Engine disp;
	Input_sys input;
	

	Game_Data game_data;
	Gamemap game_map;
	//Inventory inventory;
	//Player player;
	//Spells spells;
	//UI_Display  ui_display;
	Build_Level build_level;
	//Objects objects;
	//Monsters monsters;
	//Shop shop;
	
	
	//Play_State previous;
	Play_State play_state;



	bool game_saved;
	int difficultity_level;
	//bool debug;

};
#endif
