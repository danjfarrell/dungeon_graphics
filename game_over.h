#ifndef GAME_OVER_H
#define GAME_OVER_H

//#include <SDL2/SDL.h>
#include "input_sys.h"
#include "display_engine.h"
#include "input_sys.h"
#include "constants.h"





class Game_Over
{

public:

    Game_Over();




    bool game_over(Display_Engine &disp, Input_sys &input, bool saved);




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


