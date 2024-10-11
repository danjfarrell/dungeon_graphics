#ifndef SPELLS_H
#define SPELLS_H

//#include <SDL2/SDL.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <chrono>
//#include "input_sys.h"
//#include "display_engine.h"
#include "constants.h"
//#include "game_defines.h"

class Core_Engine;



class Spells
{

public:

   
	
	int spelweird[MAXMONST + 8][NUM_SPELLS];
    char spelmes[17][42];


    Spells();

    bool spell_list(Core_Engine &core);
    int build_spell(char spell_char);

    int spell_x;
    int spell_y;
    //double spell_duration[NUM_SPELLS];
    std::chrono::duration<double> spell_duration[NUM_SPELLS];
    int spell_direction;
    int spell_damage[NUM_SPELLS];
    int spell_character[NUM_SPELLS];
    int spell_x_mod;
    int spell_y_mod;
    time_t start_time;
    bool spell_description_displayed;
   // double spell_tick;
   // double spell_tick_interval[NUM_SPELLS];
    std::chrono::duration<double> spell_tick;
    std::chrono::duration<double> spell_tick_interval[NUM_SPELLS];
    std::chrono::time_point<std::chrono::system_clock> spell_start_time;
    

    int char_pos;

    int spell_index;

    char spellcode[NUM_SPELLS][4];
    char spellname[NUM_SPELLS][24];
    char speldescript[NUM_SPELLS+1][81];

    SDL_Color spell_color[NUM_SPELLS];

    

    char casting_spell[3];

};



#endif



