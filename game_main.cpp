#include "game_main.h"

Game_Main::Game_Main(){
    
    done = false; 
    next_phase = false;



    size_pos={0,0,0,10};
    sprite_info = { 0,0,0,10 };

    texture=0;

    game_state = PLAY;
    
}



bool Game_Main::Init()
{
    printf("game main init\n");
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
		printf("SDL_Init Error: ");
		return false;
	}
    printf("sdl init worked!\n");
    core.Init();
    printf("display engine init\n");
    if( !core.disp.Init())
    {
        printf("\ndisp init failed\n");
        return false;
    }
    else {
        printf("\ndisp init passed");
    }
    
    

    done=false;
    next_phase=false;

    
    game_state=PLAY;
    //game_state = INTRO;
    printf("\ngame init passed\n");
    
    return true;
}



void Game_Main::Loop()
{
    
    while(!core.input.get_input()&&!done)
    {

        SDL_RenderClear(core.disp.ren);
        
        switch (game_state)
        {
                //Intro is working successfully moves directly into title
                case INTRO:
                        //printf("in intro");
                        
                        if(intro.run_intro(core))
                        {

                                game_state=TITLE;
                                if(DEBUG)
                                {
                                    printf("%s\n","changing to title screen");
                                }
                        }
                        //printf("here");
                    break;
                //Skipping title going to work on play
                case TITLE:
                        //if(title.run_title(core))
                        //{
                        //        game_state=LOAD_GAME;
                        //}
                    break;
                case NEW_GAME:
                        //Place holder for eventual stuff if needed
                        // if(new_game.new_game(core.disp, core.input))
                        //{
                       //         game_state=PLAY;
                       // }
                    break;
               case PLAY:
                    if(play.play_run_main(core))
                    {
                            game_state=GAME_OVER;
                    }
                    break;
               case GAME_OVER:
                    //if (game_over.game_over(disp, input, play.game_saved))
                    //{
                    //
                   //         done=true;
                    //}
                    break;
        }

        //update the display render
        //int n;
        //n=SDL_RenderSetScale(disp.ren,.5,.5);
        
        SDL_RenderPresent(core.disp.ren);
    }
    printf("quiting\n");
    core.disp.Cleanup_Display();
    printf("quiting2\n");
    
}


void Game_Main::Quit()
{
    printf("quiting\n");
    SDL_Quit();
}

