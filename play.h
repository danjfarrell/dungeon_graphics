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
//#include "display_engine.h"
//#include "input_sys.h"
#include "core_engine.h"
//#include "gamemap.h"
//#include "game_input.h"
//#include "objects.h"
//#include "player.h"
//#include "game_defines.h"
//#include "game_data.h"
//#include "ui_display.h"
//#include "build_level.h"
//#include "monsters.h"
//#include "spells.h"

class Play
{
private:


    
    bool init_needed;

    //FILE *output_check;

public:


      Play();
      ~Play();

     
     // Build_Level build_level;

    std::vector<SDL_Texture*> textures;
    std::vector<SDL_Rect> texture_size;

    


    void load_data(Core_Engine &core);

    bool play_run_main(Core_Engine &core);

    bool run_start_screen(Core_Engine &core);
    bool run_overworld(Core_Engine &core);
    bool run_dungeon(Core_Engine &core);
    bool run_shop(Core_Engine &core);
    bool run_inventory(Core_Engine &core);
    bool run_spells(Core_Engine &core);
    bool run_magic(Core_Engine &core);


    SDL_Rect size_pos;
    SDL_Rect sprite_info;

    

    bool save_game();
};
#endif
