#include "title.h"

Title::Title()
{
    done=false;

    complete=false;

    size_pos.h=0;
    size_pos.w = 0;
    size_pos.x = 0;
    size_pos.y = 0;
    sprite_info.h=0;
    sprite_info.w = 0;
    sprite_info.x = 0;
    sprite_info.y = 0;

    texture =0 ;
}




/*
This is the intro of game play.
The gameplay screen is displayed and the player input is read.
*/
bool Title::run_title(Core_Engine &core)
{
                //core.disp.Disp_Text("the title!",FONT_2,GOLD, 45, 475);
                //printf("title time\n");
                core.disp.Disp_Text("the title!", FONT_2, { 255,0,0,255 }, 25, 275); 
                //core.disp.Disp_Text("the title loop!", FONT_3, GREEN, 55, 375);
                //core.disp.Disp_Text("the intro loop 2!", FONT_1, GREEN, 15, 175);
                if((core.input.KEY_RETURN==1)&&(core.input.KEY_RETURN_up))
                {
                    core.input.KEY_RETURN_up=false;

                    return true;
                }else if (core.input.KEY_RETURN==-1)
                {
                    core.input.KEY_RETURN_up=true;
                }








    return false;
}


