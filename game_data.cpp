#include "game_data.h"

Game_Data::Game_Data()
{

    //dungeon_level[overworld_player_start_pos_y][overworld_player_start_pos_x].player_loc=true;

    
    //character_map_texture_size[0][0] = 2048;
    //character_map_texture_size[0][1] = 1536;


    for (int i = 0; i < MAX_Y; i++)
    {
        for (int j = 0; j < MAX_X; j++)
        {
            //dungeon_level[i][j].block_type='#';
            if ((j % 2) == 0)
            {
                dungeon_level[i][j].block_type = OWALL;
                //printf("mod 2, %d %d\n", dungeon_level[i][j].block_type, j);
            }
            else
            {
                dungeon_level[i][j].block_type = OFLOOR;
                //printf("not mod 2, %d %d\n", dungeon_level[i][j].block_type, j);
            }
            dungeon_level[i][j].gold = false;
            dungeon_level[i][j].gold_value = 0;
            dungeon_level[i][j].item = false;
            //dungeon_level[i][j].item_index = 0;
            // dungeon_level[i][j].item_symbol = '~';
            dungeon_level[i][j].monster = false;

            dungeon_level[i][j].monster_index = -1;
            //dungeon_level[i][j].object_symbol = '-';
            dungeon_level[i][j].object = false;
            //dungeon_level[i][j].object_index = -1;

            dungeon_level[i][j].player_loc = false;
            dungeon_level[i][j].visible = true;

            //dungeon_level[i][j].color = GOLD;
            //dungeon[i][j]='#';

            //dungeon_texture_layout[i][j].x = j * 32;
            //dungeon_texture_layout[i][j].y = i * 32;
            //dungeon_texture_layout[i][j].w = 32;
            //dungeon_texture_layout[i][j].h = 32;
        }

    }
    
    //printf("game_data odoorclosed=%d\n", OCLOSEDDOOR);




}


