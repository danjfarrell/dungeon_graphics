#ifndef GAME_MAIN_H
#define GAME_MAIN_H

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "SDL.h"

#include "constants.h"

#include "intro.h"
#include "play.h"
//#include "title.h"

#include "core_engine.h"


class Game_Main
{

public:

    Game_State game_state;
	Game_Main();

    bool Init();
    void Loop();
    void Quit();

    //void handle_input();


	Core_Engine core;

	
	Play play;
	Intro intro;
	//Title title;
	//Game_Over game_over;
	//Load_Game load_game;
	//New_Game new_game;

	bool done;
    bool next_phase;



    SDL_Rect size_pos;
    SDL_Rect sprite_info;

    int texture;

};
#endif
