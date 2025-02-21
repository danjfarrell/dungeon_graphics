#include "game_data.h"


Game_Data::Game_Data()
{

    //dungeon_level[overworld_player_start_pos_y][overworld_player_start_pos_x].player_loc=true;

    
    //character_map_texture_size[0][0] = 2048;
    //character_map_texture_size[0][1] = 1536;




    dung_chars.insert('.');
    dung_chars.insert('#');


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
            //dungeon_level[i][j].visited = false;

            //dungeon_level[i][j].color = GOLD;
            //dungeon[i][j]='#';

            //dungeon_texture_layout[i][j].x = j * 32;
            //dungeon_texture_layout[i][j].y = i * 32;
            //dungeon_texture_layout[i][j].w = 32;
            //dungeon_texture_layout[i][j].h = 32;
        }

    }
    
    FILE* textures;
    errno_t err;
    err = fopen_s(&textures, "gamedata/resources/graphics/dungeon/texture_list.txt", "r");

    if (err != 0)
    {
        printf("The file 'texture_list.txt' was not opened\n");
        return;
    }


    int num_entries,tx,ty,th,tw,tn,n;
    n=fscanf(textures, "%d\n", &num_entries);
    MAP_BLOCK_ElEMENT temp1;
    for (int i = 0; i < num_entries; i++)
    {
        n= fscanf(textures, "%d %d %d %d %d\n", &tn, &th, &tw, &tx, &ty);
        printf("%d %d %d %d %d\n", tn, th, tw, tx, ty);
        temp1.texture_id = tn;
        temp1.size_pos.h = th;
        temp1.size_pos.w = tw;
        temp1.size_pos.x = tx;
        temp1.size_pos.y = ty;
        map_blocks.push_back(temp1);
    }

    fclose(textures);
 
    //********** 0 ***************

    /*
    //********** 1 ***************
    temp1.texture_id = 1;
    temp1.size_pos.h = 16;
    temp1.size_pos.w = 16;
    temp1.size_pos.x = 0;
    temp1.size_pos.y = 0;
    map_blocks.push_back(temp1);
    
    //********** 2 ***************
    temp1.texture_id = 2;
    temp1.size_pos.h = 16;
    temp1.size_pos.w = 16;
    temp1.size_pos.x = 16;
    temp1.size_pos.y = 0;
    map_blocks.push_back(temp1);
    //********** 3 ***************
    temp1.texture_id = 3;
    temp1.size_pos.h = 16;
    temp1.size_pos.w = 16;
    temp1.size_pos.x = 32;
    temp1.size_pos.y = 0;
    map_blocks.push_back(temp1);
    //********** 4 ***************
    temp1.texture_id = 4;
    temp1.size_pos.h = 16;
    temp1.size_pos.w = 16;
    temp1.size_pos.x = 48;
    temp1.size_pos.y = 0;
    map_blocks.push_back(temp1);
    //********** 5 ***************
    temp1.texture_id = 5;
    temp1.size_pos.h = 16;
    temp1.size_pos.w = 16;
    temp1.size_pos.x = 64;
    temp1.size_pos.y = 0;
    map_blocks.push_back(temp1);

    temp1.texture_id = 6;
    temp1.size_pos.h = 16;
    temp1.size_pos.w = 16;
    temp1.size_pos.x = 80;
    temp1.size_pos.y = 0;
    map_blocks.push_back(temp1);
    
    temp1.texture_id = 7;
    temp1.size_pos.h = 16;
    temp1.size_pos.w = 16;
    temp1.size_pos.x = 0;
    temp1.size_pos.y = 16;
    map_blocks.push_back(temp1);
    
    temp1.texture_id = 8;
    temp1.size_pos.h = 16;
    temp1.size_pos.w = 16;
    temp1.size_pos.x = 16;
    temp1.size_pos.y = 16;
    map_blocks.push_back(temp1);
    
    temp1.texture_id = 9;
    temp1.size_pos.h = 16;
    temp1.size_pos.w = 16;
    temp1.size_pos.x = 32;
    temp1.size_pos.y = 16;
    map_blocks.push_back(temp1);
    
    temp1.texture_id = 10;
    temp1.size_pos.h = 16;
    temp1.size_pos.w = 16;
    temp1.size_pos.x = 48;
    temp1.size_pos.y = 16;
    map_blocks.push_back(temp1);
    
    temp1.texture_id = 11;
    temp1.size_pos.h = 16;
    temp1.size_pos.w = 16;
    temp1.size_pos.x = 64;
    temp1.size_pos.y = 16;
    map_blocks.push_back(temp1);


    temp1.texture_id = 12;
    temp1.size_pos.h = 16;
    temp1.size_pos.w = 16;
    temp1.size_pos.x = 0;
    temp1.size_pos.y = 32;
    map_blocks.push_back(temp1);
    
    temp1.texture_id = 13;
    temp1.size_pos.h = 16;
    temp1.size_pos.w = 16;
    temp1.size_pos.x = 16;
    temp1.size_pos.y = 32;
    map_blocks.push_back(temp1);
    
    temp1.texture_id = 14;
    temp1.size_pos.h = 16;
    temp1.size_pos.w = 16;
    temp1.size_pos.x = 32;
    temp1.size_pos.y = 32;
    map_blocks.push_back(temp1);
    temp1.texture_id = 15;
    temp1.size_pos.h = 16;
    temp1.size_pos.w = 16;
    temp1.size_pos.x = 48;
    temp1.size_pos.y = 32;
    map_blocks.push_back(temp1);

    temp1.texture_id = 16;
    temp1.size_pos.h = 16;
    temp1.size_pos.w = 16;
    temp1.size_pos.x = 64;
    temp1.size_pos.y = 32;
    map_blocks.push_back(temp1);




    temp1.texture_id = 17;
    temp1.size_pos.h = 16;
    temp1.size_pos.w = 16;
    temp1.size_pos.x = 80;
    temp1.size_pos.y = 0;
    map_blocks.push_back(temp1);
    
    temp1.texture_id = 18;
    temp1.size_pos.h = 16;
    temp1.size_pos.w = 16;
    temp1.size_pos.x = 80;
    temp1.size_pos.y = 0;
    map_blocks.push_back(temp1);

    temp1.texture_id = 19;
    temp1.size_pos.h = 16;
    temp1.size_pos.w = 16;
    temp1.size_pos.x = 80;
    temp1.size_pos.y = 0;
    map_blocks.push_back(temp1);

    temp1.texture_id = 20;
    temp1.size_pos.h = 16;
    temp1.size_pos.w = 16;
    temp1.size_pos.x = 80;
    temp1.size_pos.y = 0;
    map_blocks.push_back(temp1);

    temp1.texture_id = 21;
    temp1.size_pos.h = 16;
    temp1.size_pos.w = 16;
    temp1.size_pos.x = 80;
    temp1.size_pos.y = 0;
    map_blocks.push_back(temp1);

    temp1.texture_id = 22;
    temp1.size_pos.h = 16;
    temp1.size_pos.w = 16;
    temp1.size_pos.x = 80;
    temp1.size_pos.y = 0;
    map_blocks.push_back(temp1);

    temp1.texture_id = 23;
    temp1.size_pos.h = 16;
    temp1.size_pos.w = 16;
    temp1.size_pos.x = 80;
    temp1.size_pos.y = 0;
    map_blocks.push_back(temp1);

    temp1.texture_id = 24;
    temp1.size_pos.h = 16;
    temp1.size_pos.w = 16;
    temp1.size_pos.x = 128;
    temp1.size_pos.y = 48;
    map_blocks.push_back(temp1);


    temp1.texture_id = 25;
    temp1.size_pos.h = 16;
    temp1.size_pos.w = 16;
    temp1.size_pos.x = 128;
    temp1.size_pos.y = 48;
    map_blocks.push_back(temp1);
    */
    //printf("map_blocks size = %d\n", map_blocks.size());
}


