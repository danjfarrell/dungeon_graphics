#include "gamemap.h"
//#include "player.h"
//#include "build_level.h"
//#include "monsters.h"
#include "core_engine.h"

Gamemap::Gamemap()
{
    printf("game map \n");
    //for(int i=1;i< MAX_DUNGEON_LEVEL;i++)
   // {
   //     level_visited[i]=true;
  //  }
   // level_visited[0]=false;
    one_pass_check = false;

    
}
Gamemap::~Gamemap()
{

 
   
}
//load_data(Display_Engine &disp,Player &player, Objects &objects)
//void Gamemap::load_data(Display_Engine &disp, MAP_BLOCK dungeon_level[MAX_Y][MAX_X+1])
void Gamemap::load_data(Core_Engine &core)
{
    //char filename[200];


    srand ( (unsigned int)time(NULL));

    printf("\n game_map load\n");

    for(int i=0;i<MAX_DUNGEON_LEVEL;i++)
    {
        core.game_data.level_visited[i]=false;
    }
        //game_data.level_visited[0]=true;
        //game_data.level_visited[1]=true;
    //build the level
    core.game_data.current_level=-1;

			//not implemented yet
			//set_visible(player,false,false,false);

    //load the textures
    num_files=0;
    //question=NONE;    //std::cout<<filename<<"\n";

    //FILE *resource_file = fopen("gamedata\\resources\\graphics_resources.txt","r");
      //output_check = fopen("gamedata\\game_map.txt","w");
    //if (disp.Load_Texture_list_from_file("gamedata\\resources\\graphics_resources.txt", textures_list, texture_size_list))
    //{
    //    printf("loaded texture list\n");
    //}
    //else {
    //    printf("gamemap 0load failed\n");
    //}
    texture = core.disp.Load_Texture("gamedata\\resources\\graphics\\DungeonCrawl_ProjectUtumnoTileset.png", textures_list, texture_size_list);
    if(texture>=0)
    {
        printf("loaded texture list\n");
    }
    else {
        printf("gamemap load failed\n");
    }

    return;
}

//bool Gamemap::run(Display_Engine &disp,Input_sys &input,Player &player, UI_Display &ui,Objects &objects)
//bool Gamemap::run(Display_Engine &disp,Input_sys &input)
//bool Gamemap::run(Display_Engine &disp,Input_sys &input,MAP_BLOCK dungeon_level[MAX_Y][MAX_X+1])
//bool Gamemap::run(Display_Engine &disp,Input_sys &input,Game_Data &game_data)
bool Gamemap::run(Core_Engine &core)
{
    //char tst[200];
    //char object_symbol;
    //int index;
    //int temp_obj_index;
  

//*************************not implemented*******************************//
//                         if (player.flash==1)
//                         {
//                             game_data.dungeon_level[player.y][player.x].player=true;
//                         }else
//                         {
//                             game_data.dungeon[player.y][player.x]='.';
//                         }
//*************************not implemented*******************************//
        
        y_min= core.player.y-AREA_Y;
        //y_min = 0;
        if(y_min<0)
        {
            y_min=0;
        }else if(y_min>(MAX_Y-(AREA_Y*2)))
        {
            y_min=(MAX_Y-(AREA_Y*2));
        }
        y_max= core.player.y+AREA_Y;
        //y_max = (AREA_Y * 2);
        if(y_max>MAX_Y)
        {
            y_max=MAX_Y;
        }else if (y_max<(AREA_Y*2))
        {
            y_max=(AREA_Y*2);
        }

        x_min= core.player.x-AREA_X;
        //x_min = 0;
        if(x_min<0)
        {
            x_min=0;
        }else if(x_min>(MAX_X-(AREA_X*2)))
        {
            x_min=(MAX_X-(AREA_X*2));
        }
        x_max=core.player.x+AREA_X;
        //x_max = (AREA_X * 2);
        if(x_max>MAX_X)
        {
            x_max=MAX_X;
        }else if (x_max<(AREA_X*2))
        {
            x_max=(AREA_X*2);
        }
        x_count=0;
        y_count=0;
        

        //printf("\n*gamemap_1*\n");
        //for(int y=0;y<MAX_Y;y++)
    //printf("game_map\n");

        if (!one_pass_check)
        {
            output_check = fopen("map_check.txt", "w");
        }
        //output_check = fopen("map_check.txt", "a");
        //fprintf(output_check, "odoorclosed:%d/n", core.game_data.OCLOSEDDOOR);
        for(int y=y_min;y<y_max;y++)
        {
            x_count=0;
            //for(int x=0;x<MAX_X;x++)
            for(int x=x_min;x<x_max;x++)
            {

                //x_pos= MAP_X_OFFSET+x*FONT_SIZE;
                //y_pos=MAP_Y_OFFSET+y*FONT_SIZE;
                x_pos=MAP_X_OFFSET+x_count*FONT_SIZE;
                y_pos=MAP_Y_OFFSET+y_count*FONT_SIZE;
                x_count++;
                //disp.Apply_BMP_FONT_Texture(x*16,y*16,dungeon[y][x]);

                 //printf("x=%d,player.x=%d,y=%d,player.y=%d, player_loc=%d\n", x, core.player.x, y, core.player.y, core.game_data.dungeon_level[y][x].player_loc);
                if((!core.game_data.dungeon_level[y][x].visible)||(core.game_data.dungeon_level[y][x].block_type==' '))
                {
                    //display nothing
                    //printf("\n**gamemap_3**\n");
                }
                else if (core.game_data.dungeon_level[y][x].spell)
                {
                    //core.disp.Apply_BMP_FONT_Texture(x_pos, y_pos, player.spell_char, player.spell_color, FONT_SIZE);
                }
			    //else if(core.game_data.dungeon_level[y][x].player_loc)
                else if ((x==core.player.x) && (y==core.player.y))
                {
                        core.disp.Apply_BMP_FONT_Textures(x_pos, y_pos, core.player.PLAYER_CHARACTER, core.player.color, FONT_SIZE, core.player.font);
                        //core.disp.Apply_BMP_FONT_Texture(x_pos,y_pos,core.player.PLAYER_CHARACTER,core.player.color,FONT_SIZE);
                        //printf("player\n");
                }
                                 
                else if(core.game_data.dungeon_level[y][x].monster)
                    //else if (game_data.dungeon_level[y][x].monster_index!=-1)
                {


                        if(core.monsters.level_monsters[core.game_data.dungeon_level[y][x].monster_index].alive)
                        {
                            core.disp.Apply_BMP_FONT_Texture(x_pos,y_pos, core.monsters.level_monsters[core.game_data.dungeon_level[y][x].monster_index].symbol, core.monsters.level_monsters[core.game_data.dungeon_level[y][x].monster_index].color,FONT_SIZE);
                        }

                        //printf("%d %d %d\n",x,y, dungeon_level[y][x].object_index);
                }
			    else if(core.game_data.dungeon_level[y][x].object)
                {
                    int index_value = core.game_data.dungeon_level[y][x].object_index;
                    
                    if ((index_value >= 0) && (index_value <= 22))
                    {
                        core.disp.Apply_BMP_FONT_Textures(x_pos, y_pos, core.objects.object_character[index_value], core.objects.object_color[index_value], FONT_SIZE, core.objects.object_font[index_value]);
                    }
                    else if((core.game_data.dungeon_level[y][x].object_index > 22) && (core.game_data.dungeon_level[y][x].object_index <= 31))
                    {
                        core.disp.Apply_BMP_FONT_Textures(x_pos, y_pos, core.objects.object_character[index_value], core.objects.object_color[index_value], FONT_SIZE, core.objects.object_font[index_value]);
                    }
                    else
                    {
                        core.disp.Apply_BMP_FONT_Textures(x_pos, y_pos, core.objects.object_character[index_value], core.objects.object_color[index_value], FONT_SIZE, core.objects.object_font[index_value]);
                    }
                }
                else if(core.game_data.dungeon_level[y][x].gold)
                {

                    core.disp.Apply_BMP_FONT_Texture(x_pos,y_pos,'*',GOLD,FONT_SIZE);
                }
                        /*this is now the default as all characters carrie their own color now******/
				else /*if ((dungeon_level[y][x].block_type=='#')||(dungeon_level[y][x].block_type=='~'))*/
                {
                    //display using bmp fonts
                   core.disp.Apply_BMP_FONT_Texture(x_pos,y_pos, core.game_data.dungeon_level[y][x].block_type, core.game_data.dungeon_level[y][x].color,FONT_SIZE);
                    
                    //printf("%d, %d,%d,%d,%d, %d,%d,%d,%d\n", core.game_data.dungeon_level[y][x].block_type, core.game_data.display_characters_sizepos[core.game_data.dungeon_level[y][x].block_type].x, core.game_data.display_characters_sizepos[core.game_data.dungeon_level[y][x].block_type].y, core.game_data.display_characters_sizepos[core.game_data.dungeon_level[y][x].block_type].w, core.game_data.display_characters_sizepos[core.game_data.dungeon_level[y][x].block_type].h, core.game_data.dungeon_texture_layout[y][x].x, core.game_data.dungeon_texture_layout[y][x].y, core.game_data.dungeon_texture_layout[y][x].w, core.game_data.dungeon_texture_layout[y][x].h);
                    //display use clipped textures
                    //fprintf(output_check, "x=%d, y=%d, block=%d, layout.x=%d, layout.y=%d, layout.h=%d, layout.w=%d\t", x, y, core.game_data.dungeon_level[y][x].block_type, core.game_data.dungeon_texture_layout[y][x].x, core.game_data.dungeon_texture_layout[y][x].y, core.game_data.dungeon_texture_layout[y][x].h, core.game_data.dungeon_texture_layout[y][x].w);
                    //core.disp.Apply_Texture(texture, core.game_data.dungeon_texture_layout[y][x], textures_list, core.game_data.display_characters_sizepos[core.game_data.dungeon_level[y][x].block_type]);
                    //core.disp.Apply_Texture(texture, x,y, textures_list, core.game_data.display_characters_sizepos[core.game_data.dungeon_level[y][x].block_type]);
                    //fprintf(output_check, "x=%d, y=%d, block=%d, layout.x=%d, layout.y=%d, layout.h=%d, layout.w=%d\t", x, y, core.game_data.dungeon_level[y][x].block_type, core.game_data.dungeon_texture_layout[y][x].x, core.game_data.dungeon_texture_layout[y][x].y, core.game_data.dungeon_texture_layout[y][x].h, core.game_data.dungeon_texture_layout[y][x].w);
                }
            }
            y_count++;
           // fprintf(output_check, "\n");
            if (!one_pass_check)
            {
                fprintf(output_check, "\n");
            }

        }

        if (!one_pass_check)
        {
            fclose(output_check);
        }
        one_pass_check = true;


    return  true;
}





void Gamemap::clean_up()
{

    return;
}
