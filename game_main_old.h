#ifndef GAME_MAIN_H
#define GAME_MAIN_H

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
//#include "SDL2/SDL.h"
#include "SDL.h"
#include "input_sys.h"
#include "display_engine.h"
//#include "timer.h"
#include "constants.h"
#include "intro.h"
#include "play.h"
#include "title.h"
#include "game_over.h"
#include "load_game.h"
#include "new_game.h"
//#include "player.h"
//#include "ui_display.h"
#include "game_over.h"



class Game_Main
{

public:

    Game_State game_state;


    bool Init();
    void Loop();
    void Quit();

    void handle_input();

	Display_Engine disp;
	Input_sys input;


	
	Play play;
	Intro intro;
	Title title;
	Game_Over game_over;
	Load_Game load_game;
	New_Game new_game;

	bool done;
    bool next_phase;



    SDL_Rect size_pos;
    SDL_Rect sprite_info;

    int texture;

};
#endif
