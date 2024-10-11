#include "game_over.h"

Game_Over::Game_Over()
{

}




/*
This is the intro of game play.
The gameplay screen is displayed and the player input is read.
*/
bool Game_Over::game_over(Display_Engine &disp, Input_sys &input,bool saved)
{

    if (saved)
    {
        disp.Disp_Text("You saved your game! Come Back Soon!", FONT_1, { 255,215,0 }, 35, 375);
    }
    else
    {

        //disp.Disp_Text("YOU DIED! GAME OVER!", FONT_1, BLUE, 35, 375);
        disp.Disp_Text("YOU DIED! GAME OVER!", FONT_1, {0,0,255}, 35, 375);
    }



                if((input.KEY_RETURN==1)&&(input.KEY_RETURN_up==true))
                {
                    input.KEY_RETURN_up=false;
                    return true;
                }else if (input.KEY_RETURN==-1)
                {
                    input.KEY_RETURN_up=true;
                }


    return false;
}


