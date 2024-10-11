#include "game_main.h"

bool Game_Main::Init()
{
    printf("game main init\n");
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
		printf("SDL_Init Error: ");
		return false;
	}
    printf("sdl init worked!\n");
    if( !disp.Init())
    {

        return false;
    }
    printf("wtf");
    //disp.Build_bmp_font();

    done=false;
   next_phase=false;

//game_state=INTRO;
game_state=PLAY;

    return true;
}



void Game_Main::Loop()
{
//int i;

   //play.load_data(disp);
    while(!input.get_input()&&!done)
    {
        SDL_RenderClear(disp.ren);


        switch (game_state)
        {

               case INTRO:
                        //printf("in intro");
                        if(intro.run_intro(disp,input))
                        {

                                game_state=TITLE;
                                if(DEBUG)
                                {
                                    printf("%s\n","changing to title screen");
                                }
                        }
                        //printf("here");
                    break;
                case TITLE:

                        if(title.run_title(disp,input))
                        {
                                game_state=LOAD_GAME;
                        }

                    break;
                case LOAD_GAME:

                        if(load_game.load_game(disp,input))
                        {
                                game_state=NEW_GAME;
                        }

                    break;
                case NEW_GAME:

                        if(new_game.new_game(disp,input))
                        {
                                game_state=PLAY;
                        }

                    break;
               case PLAY:

                    if(play.play_run_main(disp,input))
                    {
                            game_state=GAME_OVER;
                    }


                    break;
               case GAME_OVER:
                    if(game_over.game_over(disp,input,play.game_saved))
                    {

                            done=true;
                    }
                    break;
        }




        //update the display render
        //int n;
        //n=SDL_RenderSetScale(disp.ren,.5,.5);
        SDL_RenderPresent(disp.ren);



    }



    disp.Cleanup_Display();


}


void Game_Main::Quit()
{
   SDL_Quit();
}

