#include "load_game.h"

Load_Game::Load_Game()
{

}




/*
This is the intro of game play.
The gameplay screen is displayed and the player input is read.
*/
bool Load_Game::load_game(Display_Engine &disp, Input_sys &input)
{
                //disp.Disp_Text("the load game loop!",FONT_1,RED, 55, 375);

    disp.Disp_Text("the load game loop!", FONT_1, { 255,0,0 }, 55, 375);

                if((input.KEY_RETURN==1)&&(input.KEY_RETURN_up))
                {
                    input.KEY_RETURN_up=false;

                    return true;
                }else if (input.KEY_RETURN==-1)
                {
                    input.KEY_RETURN_up=true;
                }








    return false;
}



