#ifndef BUILD_LEVEL_H
#define BUILD_LEVEL_H

#include <vector>
#include <stdio.h>
#include <stdlib.h>     /* atoi */
#include <time.h>
#include <string.h>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#define MAX_CARVED_TILES (MAX_X * MAX_Y / 4) // Stop at 25% fill



class Core_Engine;

class Build_Level
{
private:

    int carved_tiles = 0; // Track total tiles carved
    int premade_offset;


    void eat_rock(int lv, int x,int y, Core_Engine& core);
    void eat_rock_new(int lv, int x, int y, Core_Engine& core, int depth=0);

     void treasureroom(int level, Core_Engine& core);


    void troom(int lv, int xsize, int ysize, int tx, int ty, int glyph, Core_Engine& core);

     //void load_monster_data();
    bool isWall(Core_Engine& core, int x, int y);
     
    void printTextureMap(Core_Engine& core);

    void test_new_print(Core_Engine& core);

     //void add_monters(int max_y, int max_x, int level, Core_Engine& core);
     //void add_objects(int max_y,int max_x, int level, Core_Engine& core, int offset);
     //void add_gold(int max_y, int max_x, int level, Core_Engine& core);

public:

    Build_Level();
    ~Build_Level();
    FILE *output_check;


    void make_maze(int level, Core_Engine& core);


    //void make_overworld(Core_Engine& core);


    //void load_premade(int level, Core_Engine& core);

    void new_level(Core_Engine& core, int destination);

    //void change_level(Core_Engine& core,int destination);
    //void save_level(Core_Engine& core);// save object data, save monster data
    //void load_level(Core_Engine& core, int destination);
    void clean_level(Core_Engine& core);
};
#endif

