#include "game_data.h"

Game_Data::Game_Data()
{
    
    for(int i=0;i<MAX_Y;i++)
    {
        for (int j=0;j<MAX_X;j++)
        {
            dungeon_level[i][j].block_type='#';
            dungeon_level[i][j].gold=false;
            dungeon_level[i][j].gold_value=0;
            dungeon_level[i][j].item=false;
            dungeon_level[i][j].item_index=0;
           // dungeon_level[i][j].item_symbol = '~';
            dungeon_level[i][j].monster=false;
            
            dungeon_level[i][j].monster_index=-1;
            dungeon_level[i][j].object_symbol = '-';
            dungeon_level[i][j].object=false;
            dungeon_level[i][j].object_index=-1;

            dungeon_level[i][j].player_loc=false;
            dungeon_level[i][j].visible=true;

			dungeon_level[i][j].color=GOLD;
            //dungeon[i][j]='#';
        }

    }



    dungeon_level[1][1].player_loc=true;

    last_level_down_x=1;
    last_level_down_y=1;
    current_level_down_x=1;
    current_level_down_y=1;
    object_base_weapon_index=0;
    max_game_time=600;
    time_elapsed=0;
    time_ticks = 0;


}


