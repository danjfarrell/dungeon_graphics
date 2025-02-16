#ifndef _CONSTANTS_H
#define _CONSTANTS_H

#include <string>
#include "SDL.h"





//#pragma warning(disable : 4996)
//#pragma warning(disable : 4995)

//DEBUG variable
const bool DEBUG{false};
//const bool DEBUG =true;
const bool INTRO_DEBUG { true };

//Screen attributes
const int SCREEN_WIDTH { 1200 };
const int SCREEN_HEIGHT{ 600 };
const int SCREEN_OFFSET{ 0 };

//Max map sizes
const int MAX_X = 67;
const int MAX_Y = 37;
//const int AREA_X = 13;
//const int AREA_Y = 7;
// 
//DISPLAY AREA
const int AREA_X = 24;
const int AREA_Y = 13;

const int overworld_player_start_pos_x = 5;
const int overworld_player_start_pos_y = 12;


//Max inventory size
const int Inventory_max_size = 26;
const int Max_number_items = 180;

//Monster NUmber basics
const int MAX_monster_num = 50;
const int number_of_monsters= 60;
const int MAXMONST =56;

//Max Alpha value
const int ALPHA_MAX=255;

//The frame rate
const int FRAMES_PER_SECOND = 30;

const int flash_counter=5;

//RBG Value for transparent value in textures
const int r_trans=1;
const int g_trans=1;
const int b_trans=1;






//const int PLAYER_CHARACTER =64
const int MAX_PC_LEVEL= 10;

const int MAX_DUNGEON_LEVEL =15;
const int MAX_VOLCANO_LEVEL =5;

const int PLAYER_FLASH_SPEED =10;

const int FONT_SIZE =16;

//const int MAP_X_OFFSET =275;
//const int MAP_Y_OFFSET =50;
const int MAP_X_OFFSET =5;
const int MAP_Y_OFFSET =5;

const int FONT_1_SIZE =16;


const int UI_MESSAGE_SIZE_LIST =10;
const int UI_MESSAGE_MAX_SIZE= 100;
const int NUM_DISP_ELEM= 20;
const int MESSAGE_TTL =500;
const int NUM_SPELLS =38;
const int NUM_SPELL_EFFECTS =10;




const int FOREGROUND_HEIGHT=310;

const int ROUND_DISPLAY=30;

//const char* const GAME_TITLE="Crawl";

enum  Game_State{INTRO,TITLE,LOAD_GAME,NEW_GAME,PLAY,GAME_OVER};
enum  Play_State{START_SCREEN,OVERWORLD,SHOP,DUNGEON,INVENTORY,SPELLS,MAGIC};
enum  Text_Color_List{BLACK,WHITE,RED,GREEN,BLUE,GOLD,SILVER,ORANGE};
enum  Buildings_List{DUNGEON_ENTRANCE,EQUIPMENT_STORE,COLLEGE};
typedef int Text_Colors;  //set this up for loading of color from file to be able to load more.

//enum Intro_States{Intro_Init,Intro_Run, Intro_Cleanup};
//enum Play_States{Play_Load,Play_Run,Play_Cleanup};

//enum Text_Color{BLACK,WHITE,RED,GREEN,BLUE,GOLD,SILVER,NUMCOLORS};


enum  Font_IDs{FONT_1,FONT_2,FONT_3,FONT_4,FONT_5,FONT_6};



enum Play_phases{G_DUNGEON,G_MAP,VOLCANO,PAUSED};

//enum Dungeon_sub_phase{D_P,D_R};
//enum Overworld_sub_phase{O_P,O_R,SHOP};
//enum Volcano_sub_phase{V_P,V_R};

enum Question{QUIT,SAVE,OBJECT,ITEM, NONE};

enum Player_Direction{P_UP,P_DOWN,P_LEFT,P_RIGHT,P_UR,P_DR,P_DL,P_UL,P_NONE};

enum Player_Input_States{PLAYER_MOVEMENT,PLAYER_CASTING,PLAYER_EQUIPPING,PLAYER_ON_OBJECT};


enum TextureID {
    FLOOR = 25,
    WALL = 2,
    CORNER_TOP_LEFT = 5,
    CORNER_TOP_RIGHT = 3,
    CORNER_BOTTOM_LEFT = 9,
    CORNER_BOTTOM_RIGHT = 16,
    INTERSECTION = 6,
    T_INTERSECTION_UP = 1,
    T_INTERSECTION_DOWN = 8,
    T_INTERSECTION_LEFT = 2,
    T_INTERSECTION_RIGHT = 7,
    END_LEFT=10,
    END_RIGHT = 14,
    END_UP = 12,
    END_DOWN = 13,
    VERTICAL = 11,
    HORIZONTAL=15

};



typedef struct
{
    int texture_id;
    SDL_Rect size_pos;
} MAP_BLOCK_ElEMENT;

typedef struct
{
    //unsigned char block_type;
    unsigned int block_type;
    bool player_loc;
    bool monster;
    bool item;
    bool object;
    bool gold;
    bool building;
    int monster_index;
    //unsigned char monster_symbol;
    //int item_index;
    //unsigned char item_symbol;
    //int object_index;
    //unsigned char object_symbol;
    int gold_value;
    int prox_ripple_value;
    bool visible;
    bool spell;
    //bool visited;
    MAP_BLOCK_ElEMENT block_data;
    //Text_Colors color;  //white=1
} MAP_BLOCK;



typedef struct
{
    int index_value;
    bool alive;
    bool gen;
    int hp;
    int intel;
    int gold;
    bool special;
    unsigned char symbol;
    int x;
    int y;
    int attack_power;
    int defense;
    int damage;
    int level;
    int xp_value;
    bool next_to_player;
    Text_Colors color;
    char name[15];
    //std::string name_2;
} MONSTER;


typedef struct
{
    unsigned char object_symbol;
    int x;
    int y;
    int object_type;
    int object_sub_type;
    int item_index;
    Text_Colors color;
    SDL_Color obj_color;
    int num_lines;
    char text[5][UI_MESSAGE_MAX_SIZE];
    //char text[200];
} Object;

typedef struct
{
    bool visited;
    int stairs_down_x, stairs_down_y;
    int stairs_up_x, stairs_up_y;
} Level;

typedef struct
{
    int hp;
    int max_hp;
    int mp;
    int max_mp;
    int str;
    int intel;
    int cha;
    int dex;
    int stam;
    int gold;
    int level;
    int exp;
    int base_attack;
    int base_damage;
    int base_defense;
    int attack_power;
    int defense;
    int damage;
    int agro_dist;
    char name[200];
    //bool stealth;
} Stats;

typedef struct
{
    int id;
    // int sub_id;
    int magic_prefix;

    bool is_weapon;
    bool is_2h;
    bool is_shield;
    bool is_armor;
    bool is_unique;
    bool is_ring;
    bool is_necklace;
    bool is_gem;
    bool is_consumable;

    bool is_equipped;

    int damage;
    int armor;
    int bonus;
    int hp_bonus;
    int mp_bonus;
    int str_bonus;
    int dex_bonus;
    int int_bonus;
    int gold_value;

    //char symbol;

    //char name[200];

} Item;

typedef struct
{
    bool purchased;
    int item_id;
    int item_cost;
} shop_item;

typedef struct
{
    bool purchased;
    int item_id;
    int inventory_position;
    int item_sell_value;
} trading_post_item;

typedef struct
{
    int x;
    int y;
    int d;
} prox_vector;

typedef struct
{
    int pos_x;
    int pos_y;
    int from_x;
    int from_y;
    bool visited;
} node;


#endif
