#ifndef LOAD_GAME_H
#define LOAD_GAME_H

//#include <SDL2/SDL.h>
#include "input_sys.h"
#include "display_engine.h"
#include "input_sys.h"
#include "constants.h"





class Load_Game
{

public:

    Load_Game();




    bool load_game(Display_Engine &disp, Input_sys &input);




	//Display_Engine disp;
	//Input_sys input;
	//Play play;

	bool done;

    bool complete;

    SDL_Rect size_pos;
    SDL_Rect sprite_info;

    int texture;

};
#endif



