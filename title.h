#ifndef TITLE_H
#define TITLE_H

//#include <SDL2/SDL.h>
#include "input_sys.h"
#include "core_engine.h"
//#include "display_engine.h"
//#include "input_sys.h"
#include "constants.h"





class Title
{

public:

    Title();




    bool run_title(Core_Engine &core);




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


