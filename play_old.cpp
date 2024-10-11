#include "play.h"

Play::Play()
{
    play_state=OVERWORLD;
    init_needed=true;
    game_saved = false;
}

Play::~Play()
{
  
    fclose(output_check);
}


//load data need for the play class to run
void Play::load_data(Display_Engine &disp)
{

    srand ((unsigned int)time(NULL));
    int num_textures;


        if(DEBUG)
            {
                printf("%s %i\n","loading play state",play_state);
            }

    num_textures=disp.Load_Texture("test.png",textures,texture_size);
    //disp.Build_bmp_font("gamedata/resources/graphics/Anikki_square_16x16.bmp");
    disp.Build_bmp_font("gamedata/resources/graphics/Redjack17.bmp");
    //disp.Build_bmp_font("gamedata/resources/graphics/Kai-1280x400-v2_7512b5.bmp");
    if(DEBUG)
    {
        printf("number of textures loaded:%i\n", num_textures);
    }
    init_needed=false;

    //game_map.load_data(disp);
    game_map.load_data(disp, game_data);
    ui.UI_Load(disp);
            /*******
            temporary building level
        *******/
        build_level.new_level(game_data,0,/*player,*/objects,monsters);
        player.set_pos(game_data);
        output_check=fopen("play_build.txt","w");

//        fprintf(output_check,"\nplay load\n");
//            for(int y=0;y<MAX_Y;y++)
//                        {
//                            fprintf(output_check,"\ny=%d\n",y);
//                            for(int x=0;x<MAX_X;x++)
//                            {
//                                fprintf(output_check,"x=%d %d ",x,game_data.dungeon_level[y][x].object_index);
//                            }
//                        }

        //printf("\n calling new level in load in play\n");
        /**    end  temp   ****/
    return;
}


/* is the main loop of game play.
The gameplay screen is displayed and the player input is read.
*/
bool Play::play_run_main(Display_Engine &disp,Input_sys &input)
{
    char str[200];
    int n;
;


        if(init_needed)
        {
            load_data(disp);
            init_needed=false;
            
        }



        switch (play_state)
        {

               case START_SCREEN:
                        run_start_screen(disp,input);

                        if(input.KEY_SPACE==1&&input.KEY_SPACE_up==true)
                        {
                            input.KEY_SPACE_up=false;
                            play_state=OVERWORLD;

                            //init_needed=true;

                        }else if (input.KEY_SPACE==-1)
                        {
                            input.KEY_SPACE_up=true;
                        }
                    break;
                case OVERWORLD:


                        run_overworld(disp,input);
                        //if(input.KEY_SPACE==1&&input.KEY_SPACE_up==true)
                        //{
                        //    input.KEY_SPACE_up=false;
                        //    //game_map.change_level(game_data,1,player,objects,build_level);
                        //    build_level.change_level(game_data,1,/*player,*/objects,monsters);
                        //    player.set_pos(game_data);
                        //    play_state=DUNGEON;

                        //}else if (input.KEY_SPACE==-1)
                        //{
                        //    input.KEY_SPACE_up=true;
                        //}
                    break;
                case SHOP:
                        run_shop(disp,input);
                        if(input.KEY_SPACE==1&&input.KEY_SPACE_up==true)
                        {
                            input.KEY_SPACE_up=false;
                            play_state=SHOP;
                        }else if (input.KEY_SPACE==-1)
                        {
                            input.KEY_SPACE_up=true;
                        }


                    break;
                case DUNGEON:
                        if(input.KEY_TAB==1&&input.KEY_TAB_up==true)
                        {
                            input.KEY_TAB_up=false;
                            //game_map.new_level(game_data);
                            game_data.current_level++;
                            printf("game level=%d\n",game_data.current_level);

                            //game_map.change_level(game_data,game_data.current_level,player,objects,build_level);
                            build_level.change_level(game_data,game_data.current_level,/*player,*/objects,monsters);
                            player.set_pos(game_data);
                        }else if (input.KEY_TAB==-1)
                        {
                            input.KEY_TAB_up=true;
                        }


                        run_dungeon(disp, input);
                        if(input.KEY_SPACE==1&&input.KEY_SPACE_up==true)
                        {
                            input.KEY_SPACE_up=false;
                            play_state=INVENTORY;

                        }else if (input.KEY_SPACE==-1)
                        {
                            input.KEY_SPACE_up=true;
                        }

                    break;
               case INVENTORY:
                        run_inventory(disp, input);
                        if(input.KEY_SPACE==1&&input.KEY_SPACE_up==true)
                        {
                            input.KEY_SPACE_up=false;
                            play_state=SPELLS;

                        }else if (input.KEY_SPACE==-1)
                        {
                            input.KEY_SPACE_up=true;
                        }

                    break;
               case SPELLS:
                        run_spells(disp, input);
                        if(input.KEY_SPACE==1&&input.KEY_SPACE_up==true)
                        {
                            input.KEY_SPACE_up=false;
                            play_state=MAGIC;

                        }else if (input.KEY_SPACE==-1)
                        {
                            input.KEY_SPACE_up=true;
                        }
                    break;
               case MAGIC:
                        run_magic(disp,input);
                        if(input.KEY_SPACE==1&&input.KEY_SPACE_up==true)
                        {
                            input.KEY_SPACE_up=false;
                            play_state=START_SCREEN;

                        }else if (input.KEY_SPACE==-1)
                        {
                            input.KEY_SPACE_up=true;
                        }
                    break;
        }



                if(input.KEY_RETURN==1&&input.KEY_RETURN_up==true)
                {
                    input.KEY_RETURN_up=false;
                    return true;
                }else if (input.KEY_RETURN==-1)
                {
                    input.KEY_RETURN_up=true;
                }
    if(!player.alive)
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
    {

        return false;
    }

    
}

bool Play::run_start_screen(Display_Engine &disp,Input_sys &input)
{

                         disp.Disp_Text("start screen!",FONT_1,{35,55,128}, 225, 175);

        return true;
}
bool Play::run_overworld(Display_Engine &disp,Input_sys &input)
{
                    //player.player_input(input,game_data,objects,play_state,build_level,monsters);
   // printf("....overworld before player move....\n");
                    if (player.player_input(input,game_data,objects,play_state,build_level,monsters,ui,spells))
                    {
                        //printf("\n*****move monsters here*****\n");
                        monsters.move_monsters(game_data,player,ui);
                    }
                    //printf("....overworld after player move....");
                    ui.Display_UI(disp,input,player,game_data,objects,spells);
                    game_map.run(disp,input,game_data,player,objects,monsters);




                    //disp.Disp_Text("overworld!",FONT_1,{35,128,128}, 1, 1);

                      //char str[50];
                      //int n= sprintf(str,"mouse_x=%d",input.mouse_move_x);
                       //  disp.Disp_Text(str,FONT_1,{35,128,128},325,125);
                       // disp.Disp_Text("overworld!",FONT_1,{35,128,128}, 325, 175);

        return true;
}
bool Play::run_dungeon(Display_Engine &disp,Input_sys &input)
{
                        disp.Disp_Text("dungeon!",FONT_1,{35,55,28}, 125, 475);
                       // printf("\n....dungeon before player move....\n");
                        //printf("player state=%d\n", player.player_input_states);
                    //player.player_input(input,game_data,objects,play_state,build_level,monsters);
                        //printf("\ndungeon before player\n");
                    if (player.player_input(input,game_data,objects,play_state,build_level,monsters,ui,spells))
                    {
                        //printf("\n*****move monsters here*****\n");
                        
                        monsters.move_monsters(game_data,player,ui);
                    }
                    //printf("\ndungeon after player\n");
                    ui.Display_UI(disp,input,player,game_data,objects,spells);
                   // printf("dungeon after ui\n");
                    game_map.run(disp,input,game_data,player,objects,monsters);
                   // printf("dungeon after gamemap\n");


        return true;
}
bool Play::run_shop(Display_Engine &disp,Input_sys &input)
{

                         disp.Disp_Text("shop!",FONT_1,{135,55,128}, 125, 275);
        return true;
}
bool Play::run_inventory(Display_Engine &disp,Input_sys &input)
{
                         disp.Disp_Text("inventory!",FONT_1,{135,55,128}, 155, 175);

        return true;
}
bool Play::run_spells(Display_Engine &disp,Input_sys &input)
{
                         disp.Disp_Text("spells!",FONT_1,{35,155,128}, 125, 125);

        return true;
}
bool Play::run_magic(Display_Engine &disp,Input_sys &input)
{
                         disp.Disp_Text("magic!",FONT_1,{135,155,128}, 85, 175);

        return true;
}

bool Play::save_game()
{
    FILE* save_file = fopen("gamedata\\resources\\save_games\\save.txt", "w");
    int inventory_count,inventory_max;
    inventory_max = player.inventory.size();
    printf("saving\n");
        
        fprintf(save_file, "Save file\nPlayer Data\n");
        printf("saving\n");
        fprintf(save_file, "%d %d %d %d %d %d\n", player.x, player.y, player.color, player.current_weapon_index,player.current_armor_index,player.current_shield_index);
        printf("saved\n");
        fprintf(save_file, "%d\n", inventory_max);
        if (inventory_max > 0)
        {
            for (int i = 0; i < inventory_max; i++)
            {
                fprintf(save_file, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %c %s\n", 
                    player.inventory[i].id, 
                    //player.inventory[i].sub_id,
                    player.inventory[i].is_weapon, player.inventory[i].is_2h,
                    player.inventory[i].is_shield, player.inventory[i].is_armor,
                    player.inventory[i].is_unique, player.inventory[i].is_ring, 
                    player.inventory[i].is_necklace, player.inventory[i].is_equipped,
                    player.inventory[i].damage, player.inventory[i].armor, 
                    player.inventory[i].bonus, player.inventory[i].hp_bonus, 
                    player.inventory[i].mp_bonus, player.inventory[i].str_bonus,
                    player.inventory[i].dex_bonus, player.inventory[i].int_bonus 
                    //player.inventory[i].symbol, player.inventory[i].name
                    );
            }
            /********************************
            *
            *   finish saving player data
            * 
            *********************************/

        }
        printf("saved\n");
        fclose(save_file);
    return true;
}
