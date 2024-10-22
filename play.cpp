#include "play.h"

Play::Play()
{
    
    init_needed=true;
    size_pos = { 0,0,100,100 };
    sprite_info = { 0, 0, 100, 100 };

}

Play::~Play()
{
  
   
}


//load data need for the play class to run
void Play::load_data(Core_Engine &core)
{
    int temp;
    
    srand ((unsigned int)time(NULL));
    
    //loading texture of dungeon to see them
    
    temp = core.disp.Load_Texture("gamedata/resources/graphics/dungeon/cave.png", textures, texture_size);
    
    core.play_state = OVERWORLD;
    core.game_map.load_data(core);
    //core.disp.Build_bmp_font("gamedata/resources/graphics/Redjack17.bmp");
    
    /*
    
    
    core.play_state = OVERWORLD;
    core.ui_display.UI_Load(core);

    core. build_level.new_level(core, 0);
    */

    //core.player.set_pos(core);

    return;
}


/* is the main loop of game play.
The gameplay screen is displayed and the player input is read.
*/
bool Play::play_run_main(Core_Engine &core)
{




        if(init_needed)
        {
            load_data(core);
            init_needed=false;
            
        }
        //SDL_Rect temp_size = texture_size[0];
        //SDL_Rect temp_clipped = { 0, 0, 16, 16 };
        //temp_size.h = temp_clipped.h*2;
        //temp_size.w = temp_clipped.w * 2;

        //core.disp.Apply_Texture(0, temp_size, textures);
        //core.disp.Apply_clipped_texture(textures[0], &temp_size, &temp_clipped);


        
        switch (core.play_state)
        {

               case START_SCREEN:
                        run_start_screen(core);

                        if((core.input.KEY_SPACE==1) && (core.input.KEY_SPACE_up==true))
                        {
                            core.input.KEY_SPACE_up=false;
                            core.play_state=OVERWORLD;

                            //init_needed=true;

                        }else if (core.input.KEY_SPACE==-1)
                        {
                            core.input.KEY_SPACE_up=true;
                        }
                    break;
                case OVERWORLD:


                        run_overworld(core);

                    break;
                case SHOP:
                        run_shop(core);


                    break;
                case DUNGEON:


                        run_dungeon(core);


                    break;
               case INVENTORY:
                        run_inventory(core);
                        if((core.input.KEY_SPACE==1)&&(core.input.KEY_SPACE_up==true))
                        {
                            core.input.KEY_SPACE_up=false;
                            core.play_state=SPELLS;

                        }else if (core.input.KEY_SPACE==-1)
                        {
                            core.input.KEY_SPACE_up=true;
                        }

                    break;
               case SPELLS:
                        run_spells(core);
                        if((core.input.KEY_SPACE==1) && (core.input.KEY_SPACE_up==true))
                        {
                            core.input.KEY_SPACE_up=false;
                            core.play_state=MAGIC;

                        }else if (core.input.KEY_SPACE==-1)
                        {
                            core.input.KEY_SPACE_up=true;
                        }
                    break;
               case MAGIC:
                        run_magic(core);
                        if((core.input.KEY_SPACE==1)&&(core.input.KEY_SPACE_up==true))
                        {
                            core.input.KEY_SPACE_up=false;
                            core.play_state=START_SCREEN;

                        }else if (core.input.KEY_SPACE==-1)
                        {
                            core.input.KEY_SPACE_up=true;
                        }
                    break;
        }
        


                //if((core.input.KEY_RETURN==1)&&(core.input.KEY_RETURN_up==true))
                //{
                //    core.input.KEY_RETURN_up=false;
                //    return true;
                //}else if (core.input.KEY_RETURN==-1)
                //{
                //    core.input.KEY_RETURN_up=true;
                //}
    /*if (!player.alive)
    {
        return true;
    }
    else if (player.game_saved)
    {
        
        if (save_game())
        {

        }
        game_saved = true;
        return true;
    }
    else
    {*/

        return false;
    //}

    
}

bool Play::run_start_screen(Core_Engine &core)
{

        //core.disp.Disp_Text("start screen!",FONT_1,{35,55,128}, 225, 175);

        return true;
}
bool Play::run_overworld(Core_Engine &core)
{
    //core.disp.Disp_Text("overworld!", FONT_1, { 35,55,28 }, 125, 475);
    //printf("overworld\n");
    /*
    if (core.player.player_input(core))
    {

        //    monsters.move_monsters(game_data,player,ui);
    }
    core.ui_display.Display_UI(core);
    
    core.game_map.run(core);
    */
        return true;
}
bool Play::run_dungeon(Core_Engine &core)
{
                        //core.disp.Disp_Text("dungeon!",FONT_1,{35,55,28}, 125, 475);
                        //printf("dungeon\n");
                        
        /*
        if (core.player.player_input(core))
        {

            core.monsters.move_monsters(core);
        }
        core.ui_display.Display_UI(core);

        core.game_map.run(core);
         */          
        return true;
}
bool Play::run_shop(Core_Engine &core)
{

        //core.disp.Disp_Text("shop!",FONT_1,{135,55,128}, 125, 275);
        
        //core.shop.shop_main(core);
        //core.ui_display.display_shop(core);

        return true;
}
bool Play::run_inventory(Core_Engine &core)
{
        //core.disp.Disp_Text("inventory!",FONT_1,{135,55,128}, 155, 175);

        return true;
}
bool Play::run_spells(Core_Engine &core)
{
        //core.disp.Disp_Text("spells!",FONT_1,{35,155,128}, 125, 125);

        return true;
}
bool Play::run_magic(Core_Engine& core)
{
        //core.disp.Disp_Text("magic!",FONT_1,{135,155,128}, 85, 175);

        return true;
}

bool Play::save_game()
{
    //FILE* save_file = fopen("gamedata\\resources\\save_games\\save.txt", "w");
    ////int inventory_count;
    //int inventory_max = 0;
    ////inventory_max = player.inventory.size();
    //printf("saving\n");
    //    
    //    //fprintf(save_file, "Save file\nPlayer Data\n");
    //    printf("saving\n");
    //    //fprintf(save_file, "%d %d %d %d %d %d\n", player.x, player.y, player.color, player.current_weapon_index,player.current_armor_index,player.current_shield_index);
    //    printf("saved\n");
    //    //fprintf(save_file, "%d\n", inventory_max);
    //    if (inventory_max > 0)
    //    {
    //        for (int i = 0; i < inventory_max; i++)
    //        {
    //            //fprintf(save_file, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %c %s\n", 
    //                //player.inventory[i].id, 
    //                //player.inventory[i].sub_id,
    //                //player.inventory[i].is_weapon, player.inventory[i].is_2h,
    //                //player.inventory[i].is_shield, player.inventory[i].is_armor,
    //                //player.inventory[i].is_unique, player.inventory[i].is_ring, 
    //                //player.inventory[i].is_necklace, player.inventory[i].is_equipped,
    //                //player.inventory[i].damage, player.inventory[i].armor, 
    //                //player.inventory[i].bonus, player.inventory[i].hp_bonus, 
    //                //player.inventory[i].mp_bonus, player.inventory[i].str_bonus,
    //                //player.inventory[i].dex_bonus, player.inventory[i].int_bonus 
    //                //player.inventory[i].symbol, player.inventory[i].name
    //                //);
    //        }
    //        /********************************
    //        *
    //        *   finish saving player data
    //        * 
    //        *********************************/

    //    }
    //    printf("saved\n");
    //    fclose(save_file);
    return true;
}
