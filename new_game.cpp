#include "new_game.h"

New_Game::New_Game()
{

}




/*
This is the intro of game play.
The gameplay screen is displayed and the player input is read.
*/
bool New_Game::new_game(Display_Engine &disp, Input_sys &input)
{


                    //disp.Disp_Text("the new game loop!",FONT_1,WHITE, 25, 375);
    disp.Disp_Text("the new game loop!", FONT_1, { 255,255,255 }, 25, 375);
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




