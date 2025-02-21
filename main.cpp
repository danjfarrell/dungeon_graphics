//#include <stdio.h>
//#include <iostream>
//#include <stdlib.h>
//#include <string>

#include "common.h"
#include "SDL.h"
#include "game_main.h"


int main(int argc, char *args[])
{

    Game_Main* game = new Game_Main();
        
    if(!game->Init())
    {
        
      return 1;
    }
    //SDL_Delay(5000);
    
    game->Loop();

    game->Quit();
    printf("done\n");
	return 0;
}


