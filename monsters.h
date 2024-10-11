#ifndef MONSTERS_H
#define MONSTERS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string>

#include "constants.h"



class Core_Engine;

class Monsters
{
private:
    int n;
    char str[200];
    FILE *output_check;


public:



    Monsters();
    ~Monsters();

    int add_Monster(int x, int y, int level);
    void load_level_monsters(int x, int y, int index);

    bool move_monsters(Core_Engine& core);
    bool move_monsters_dumb(Core_Engine& core,int index);
    bool move_monsters_smart(Core_Engine& core,int index);
    void monster_attack(int monster_id, Core_Engine& core);

    bool check_next_to_player(int monster_id, Core_Engine& core);
    /** start move monsters dump variables **/

        int last_x,last_y,temp_x,temp_y;
        bool fight=false;
        int num_monsters, rand_direction;
    /** end move monsters dumb variables **/

    std::vector<MONSTER> level_monsters;

    MONSTER temp_monster;
    std::vector<MONSTER> all_monsters;


};
#endif
