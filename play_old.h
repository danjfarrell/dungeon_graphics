#ifndef PLAY_H
#define PLAY_H

#include <vector>
#include <stdio.h>
#include <stdlib.h>     /* atoi */
#include <time.h>
#include <string.h>
#include <iostream>
#include <queue>
#include <stdio.h>
#include "SDL.h"
#include "display_engine.h"
#include "input_sys.h"
//#include "gamemap.h"
//#include "game_input.h"
//#include "objects.h"
//#include "player.h"
//#include "game_defines.h"
//#include "game_data.h"
//#include "ui_display.h"
#include "build_level.h"
//#include "monsters.h"
//#include "spells.h"

class Play
{
private:


    Play_State play_state;
    bool init_needed;

FILE *output_check;

public:


      Play();
      ~Play();
  //    Game_Data game_data;
 //     Gamemap game_map;
      //Game_Input game_input;
 //     Player player;
 //     UI_Display  ui;
      //Objects objects;
      Build_Level build_level;
      //Monsters monsters;
      //Spells spells;

    std::vector<SDL_Texture*> textures;

    std::vector<SDL_Rect> texture_size;


    void load_data(Display_Engine &disp);

    bool play_run_main(Display_Engine &disp,Input_sys &input);

    bool run_start_screen(Display_Engine &disp,Input_sys &input);
    bool run_overworld(Display_Engine &disp,Input_sys &input);
    bool run_dungeon(Display_Engine &disp,Input_sys &input);
    bool run_shop(Display_Engine &disp,Input_sys &input);
    bool run_inventory(Display_Engine &disp,Input_sys &input);
    bool run_spells(Display_Engine &disp,Input_sys &input);
    bool run_magic(Display_Engine &disp,Input_sys &input);


    SDL_Rect size_pos;
    SDL_Rect sprite_info;

    bool game_saved;

    bool save_game();
};
#endif
