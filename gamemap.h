#ifndef Gamemap_H
#define Gamemap_H

#include <stdio.h>
#include <stdlib.h>     /* atoi */
#include <time.h>
#include <string.h>

#include <iostream>
#include <vector>
#include "SDL.h"
//#include "display_engine.h"
#include "constants.h"
//#include "input_sys.h"
//#include "game_defines.h"
//#include "build_level.h"
//#include "objects.h"
//#include "game_data.h"
//#include "player.h"

//class Player;
//class Build_Level;
//class Monsters;
class Core_Engine;

class Gamemap
{
private:





public:

      //qeustion enum
    Question question;
    //play phases enum
    Play_phases phase;  // this is an instance of the Play_Phase class


    //instances of classes
//

//    Objects objects;
    //Save_Load save_load;

    int x_min;
    int x_max;
    int y_min;
    int y_max;

    int x_pos;
    int y_pos;
    int y_count;
    int x_count;
     int num_files;


	 unsigned char dungeon[MAX_Y][MAX_X+1];

	 MAP_BLOCK dungeon_level[MAX_Y][MAX_X+1];

     bool level_visited[MAX_DUNGEON_LEVEL];

     int current_level;
     //SDL_Texture*  gamemap_texture;
    //SDL_Rect      gamemap_texture_size;
     //int           gamemap_texture_id;

     std::vector<int> play_texture;

    std::vector<SDL_Texture*> textures_list;

    std::vector<SDL_Rect> texture_size_list;

     std::vector<SDL_Rect> size_pos;

     int texture;

    FILE *output_check;
    bool one_pass_check;

    Gamemap();
    ~Gamemap();
    //void load_data(Display_Engine &disp);
    //bool run(Display_Engine &disp,Input_sys &input);
    void clean_up();
    //void new_level();


    //void load_data(Display_Engine &disp, MAP_BLOCK dungeon_level[MAX_Y][MAX_X+1]);
    void load_data(Core_Engine &core);
    //bool run(Display_Engine &disp,Input_sys &input, MAP_BLOCK dungeon_level[MAX_Y][MAX_X+1]);
    //bool run(Display_Engine &disp,Input_sys &input, Game_Data &game_data);
    bool run(Core_Engine &core);
    //void new_level(MAP_BLOCK dungeon_level[MAX_Y][MAX_X+1]);
    //void new_level(Game_Data &game_data,int destination,Player &player, Objects &objects,Build_Level &build_level);

    //void save_level(Game_Data &game_data);

   // void change_level(Game_Data &game_data,int destination,Player &player, Objects &objects,Build_Level &build_level);

};
#endif
