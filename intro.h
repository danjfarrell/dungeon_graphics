#ifndef INTRO_H
#define INTRO_H

//#include <SDL2/SDL.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>     /* atoi */
#include <time.h>
#include <string.h>
#include <string>
#include <iostream>
#include "input_sys.h"
#include "core_engine.h"
#include "constants.h"

//class Core_Engine;

typedef struct
{


	int fade_in_frame;
	int fade_in;
	int hold;
	int fade_out_frame;
    int fade_out;


	int texture_id;


}splash;



class Intro
{
private:
    bool init_needed;

public:

    Intro();


    //void load_data(Display_Engine &disp);

   

    std::vector<SDL_Texture*> textures;
    std::vector<SDL_Rect> texture_size;

	//Display_Engine disp;
	//Input_sys input;
	//Play play;

	bool done;

    bool complete;

    SDL_Rect size_pos;
    SDL_Rect sprite_info;

    int texture;

          int num_screens;
      std::vector<splash> s_screen;


      int phase;

    float f_alpha;
    int alpha;
      int frame_count;
      int current_screen;

      bool script_not_done;

      int text_pos_x;
      int text_pos_y;


      SDL_Rect size_and_pos;

      bool run_intro(Core_Engine& core);
      bool load_data(Core_Engine &core);
      //void scripted_intro(Display_Engine &disp_eng);
      bool display_intro(Core_Engine &core);
      //void intro_input(Input_sys &input,Game_States &game_state);
      void clean_up();


};
#endif

