#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#include <time.h>
#include <chrono>
#include <algorithm> 
#include "constants.h"


class Core_Engine;



class Player
{
private:
    int n{};
    char str[200]{};


    

    //Player_Direction player_direction(Core_Engine& core);
    int player_direction(Core_Engine& core);
public:
    
    int current_weapon_index{};
    int current_armor_index{};
    int current_shield_index{};

    int mouse_x_move_target{};
    int mouse_y_move_target{};
    bool mouse_move_inprogress{};
    
    //int equip_selection;
    FILE* output_check{};
    //Build_Level build_level;


    

    //::queue<int> from_x_loc;
    //std::queue<int> from_y_loc;
    std::vector<int> path_x{};
    std::vector<int> path_y{};
    int mouse_moves;

    int dx[8]{};
    int dy[8]{};
    
    Player();
    ~Player();

   

    //void player_input(Input_sys &input, Game_Data &game_data,Objects &objects);
    //Play_State player_input(Input_sys &input, Game_Data &game_data,Objects &objects,Play_State play_state,Build_Level &build_level);

      bool player_input(Core_Engine& core);

      void set_pos(Core_Engine& core);
            void set_pos(Core_Engine& core,int x,int y);
    //void set_pos(MAP_BLOCK dungeon_level[1+MAX_DUNGEON_LEVEL+MAX_VOLCANO_LEVEL][MAX_Y][MAX_X+1],int d_x, int d_y,int level);
            

    bool player_movement_fun( Core_Engine& core);
    int mouse_move(Core_Engine& core);


    int mouse_direction(Core_Engine& core, int move_x, int move_y);

   
    void player_on_object_fun(Core_Engine& core);
    bool player_on_object_fun_new(Core_Engine& core);
    bool object_handling(Core_Engine& core, int object_id);
    bool object_handling_enviroment(Core_Engine& core, int object_id);
    bool object_handling_item(Core_Engine& core, int object_id);
    //void display_object_message_enviroment(Core_Engine& core, int object_id);
    int display_object_message_enviroment(Core_Engine& core, int object_id);
    int display_object_message_item(Core_Engine& core, int object_id);
    
    bool player_equipping_fun(Core_Engine& core);
    int display_equipping_message(Core_Engine& core);
    bool handling_equipping_fun(Core_Engine& core);
    int equipment_selection(Core_Engine& core);

    void player_fight_fun(Core_Engine& core);

    void player_casting_fun(Core_Engine& core);
    bool player_casted_spell_fun(Core_Engine& core, int spell_id);
    void player_cast_display_message(Core_Engine& core, int spell_id);
    char player_casting_selection(Core_Engine& core, int spell_id);

    char casting_los_spell(Core_Engine& core, int spell_id, char selection);

    void killed_monster(Core_Engine& core, int hit_id);

    void update_spell_effects(Core_Engine& core);
    void recalc_all();

    void build_proximity_matrix(Core_Engine& core);

    void find_open_spot(Core_Engine& core, int open[]);
    /*start proximity_matrix variables*/
    int x_min,x_max,y_min,y_max;
    std::queue<prox_vector> vector_queue;
    prox_vector initial;
    /****end proximity_matrix variables***/

    Player_Input_States player_input_states;

    void load_xp_system();
    bool gain_xp(int xp);
    void raise_level();


    bool known_spells[NUM_SPELLS];
    int num_known_spells;
    int x;
    int y;
    int last_x;
    int last_y;
    int flash;
    int flash_counter;

    int difficultity_level;

    char underneath;

    SDL_Color color;
    //int xp_required[11];
    int required_experience[MAX_PC_LEVEL+1];

    std::vector<Item> inventory;
    int numb_items;
    Item temp_item;
    std::vector<Item> item_list;

    Stats stats;

    int PLAYER_CHARACTER;
    int font;

    int move_count;

    bool msg_sent;
    bool spell_cast_msg_displayed;

   bool equipping_armor;
   bool equipping_weapon;
   bool equipping_shield;
   bool dropping_item;
   bool entering_drop;

   bool choice_complete;
   bool choice_made;

   int num_lines;

    int gold_found_value;
    bool WTW;  // walk through walls
    bool EPA; //expanded awerness
    bool on_object;
    bool object_ignore;
    bool shift_direction;
    bool found_gold;
    bool hit_monster;
    int hit_id;
    bool alive;
    bool invincible;
    bool single_move;

    int weapon_index;

    bool game_saved;
    bool casting_spell;
    char casting_selection;
    int spell_x;
    int spell_y;
    char spell_char;
    SDL_Color spell_color;
   

    int effects_durations[NUM_SPELL_EFFECTS];
    int effects_time[NUM_SPELL_EFFECTS][2];
   
    int hp_mp_regen_time[2][2];
    float hp_mp_regen_rate[2];
    float hp_mp_regen[2];

    //int vision_distance;

};
#endif
