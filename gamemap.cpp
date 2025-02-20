#include "gamemap.h"
#include <random>
#include "core_engine.h"

Gamemap::Gamemap()
{
    printf("game map \n");
    //one_pass_check = false;
    std::random_device rd;  // Seed source
    std::mt19937 gen(rd()); // Mersenne Twister generator

    // Define distribution (1 or 2)
    std::uniform_int_distribution<int> dist(1, 2);

    // Generate and print random number
    random_number = dist(gen);
}
Gamemap::~Gamemap()
{

   
}

void Gamemap::load_data(Core_Engine &core)
{
    //char filename[200];
    int temp=0;



    //loading texture of dungeon to see them

    core.game_data.dungeon_tile_texture_index[temp] = core.disp.Load_Texture("gamedata/resources/graphics/dungeon/cave.png", textures_list, size_pos);
    temp++;
    core.game_data.dungeon_tile_texture_index[temp] = core.disp.Load_Texture("gamedata/resources/graphics/dungeon/Cavern.png", textures_list, size_pos);
    srand ( (unsigned int)time(NULL));

    printf("\n game_map load\n");

    /*for(int i=0;i<MAX_DUNGEON_LEVEL;i++)
    {
        core.game_data.level_visited[i]=false;
    }*/
        //game_data.level_visited[0]=true;
        //game_data.level_visited[1]=true;
    //build the level
    core.game_data.current_level=-1;

			//not implemented yet
			//set_visible(player,false,false,false);

    //load the textures
    //num_files=0;
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
    /*texture = core.disp.Load_Texture("gamedata\\resources\\graphics\\DungeonCrawl_ProjectUtumnoTileset.png", textures_list, texture_size_list);
    if(texture>=0)
    {
        printf("loaded texture list\n");
    }
    else {
        printf("gamemap load failed\n");
    }*/

    core.build_level.make_maze(1, core);

    return;
}


bool Gamemap::run(Core_Engine &core)
{
    
        /*
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
        */
        y_min = 0;
        y_max = MAX_Y;

        x_min = 0;
        x_max = MAX_X;

        if (!one_pass_check)
        {
            output_check = fopen("map_check.txt", "w");
        }
        //printf("%d,%d\n", y_min, y_max);
        for(int y=y_min;y<y_max;y++)
        {
            x_count=0;
            //printf("here7\n");
            for(int x=x_min;x<x_max;x++)
            {


                x_pos=MAP_X_OFFSET+x_count*FONT_SIZE;
                y_pos=MAP_Y_OFFSET+y_count*FONT_SIZE;
                x_count++;
                if((!core.game_data.dungeon_level[y][x].visible)||(core.game_data.dungeon_level[y][x].block_type==' '))
                {
                    //display nothing
                    //printf("here1\n");
                    
                }
                else if ((core.game_data.dungeon_level[y][x].block_type == '.') || (core.game_data.dungeon_level[y][x].block_type == '#'))
                {
                    //core.game_data.dungeon_level[i][j].block_data.texture_id
                   
                    SDL_Rect size;
                    int text_id;
                    size.h = 16;
                    size.w = 16;
                    size.x = x * 16;
                    size.y = y * 16;
                    text_id = core.game_data.dungeon_level[y][x].block_data.texture_id;
                    //printf("%d \n", text_id);
                    core.disp.Apply_clipped_texture(textures_list[core.game_data.dungeon_tile_texture_index[random_number]], &size, &core.game_data.map_blocks[text_id].size_pos);
                   // core.disp.Apply_clipped_texture(textures_list[0], &size, &core.game_data.map_blocks[core.game_data.dungeon_level[y][x].block_data.texture_id].size_pos);
                }
                else if (core.game_data.dungeon_level[y][x].spell)
                {
                    //printf("here2\n");
                }
                /*
                else if ((x==core.player.x) && (y==core.player.y))
                {
                        core.disp.Apply_BMP_FONT_Textures(x_pos, y_pos, core.player.PLAYER_CHARACTER, core.player.color, FONT_SIZE, core.player.font);
                        //core.disp.Apply_BMP_FONT_Texture(x_pos,y_pos,core.player.PLAYER_CHARACTER,core.player.color,FONT_SIZE);
                        //printf("player\n");
                }
                */               
                else if(core.game_data.dungeon_level[y][x].monster)
                {
                    //printf("here3\n");
                        /*
                        if(core.monsters.level_monsters[core.game_data.dungeon_level[y][x].monster_index].alive)
                        {
                            core.disp.Apply_BMP_FONT_Texture(x_pos,y_pos, core.monsters.level_monsters[core.game_data.dungeon_level[y][x].monster_index].symbol, core.monsters.level_monsters[core.game_data.dungeon_level[y][x].monster_index].color,FONT_SIZE);
                        }
                        */
                        
                }
			    else if(core.game_data.dungeon_level[y][x].object)
                {
                    //printf("here4\n");
                    /*
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
                    */
                }
                else if(core.game_data.dungeon_level[y][x].gold)
                {
                    //printf("here5\n");
                    //core.disp.Apply_BMP_FONT_Texture(x_pos,y_pos,'*',GOLD,FONT_SIZE);
                }

				else 
                {
                    //printf("here6\n");
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
            //fclose(output_check);
            if (output_check != NULL) {
                fclose(output_check);
                output_check = NULL;
            }
        }
        one_pass_check = true;


    return  true;
}





void Gamemap::clean_up()
{

    return;
}
