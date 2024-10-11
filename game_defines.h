#ifndef _GAME_DEFINES_H
#define _GAME_DEFINES_H

#include "constants.h"
#include <string>
#include "SDL.h"




//#define STRENGTH 0		/* characters physical strength not due to  objects */
//#define INTELLIGENCE 1
//#define WISDOM 2
//#define CONSTITUTION 3
//#define DEXTERITY 4
//#define CHARISMA 5
//#define HPMAX 6
//#define HP 7
//#define GOLD 8
//#define EXPERIENCE 9
//#define LEVEL 10
//#define REGEN 11
//#define WCLASS 12
//#define AC 13
//#define BANKACCOUNT 14
//#define SPELLMAX 15
//#define SPELLS 16
//#define ENERGY 17
//#define ECOUNTER 18
//#define MOREDEFENSES 19
//#define WEAR 20
//#define PROTECTIONTIME 21
//#define WIELD 22
//#define AMULET 23
//#define REGENCOUNTER 24
//#define MOREDAM 25
//#define DEXCOUNT 26
//#define STRCOUNT 27
//#define BLINDCOUNT 28
//#define CAVELEVEL 29
//#define CONFUSE 30
//#define ALTPRO 31
//#define HERO 32
//#define CHARMCOUNT 33
//#define INVISIBILITY 34
//#define CANCELLATION 35
//#define HASTESELF 36
//#define EYEOFLARN 37
//#define AGGRAVATE 38
//#define GLOBE 39
//#define TELEFLAG 40
//#define SLAYING 41
//#define NEGATESPIRIT 42
//#define SCAREMONST 43
//#define AWARENESS 44
//#define HOLDMONST 45
//#define TIMESTOP 46
//#define HASTEMONST 47
//#define CUBEofUNDEAD 48
//#define GIANTSTR 49
//#define FIRERESISTANCE 50
//#define BESSMANN 51
//#define NOTHEFT 52
//#define HARDGAME 53
//#define CPUTIME 54
//#define BYTESIN 55
//#define BYTESOUT 56
//#define MOVESMADE 57
//#define MONSTKILLED 58
//#define SPELLSCAST 59
//#define LANCEDEATH 60
//#define SPIRITPRO 61
//#define UNDEADPRO 62
//#define SHIELD 63
//#define STEALTH 64
//#define ITCHING 65
//#define LAUGHING 66
//#define DRAINSTRENGTH 67
//#define CLUMSINESS 68
//#define INFEEBLEMENT 69
//#define HALFDAM 70
//#define SEEINVISIBLE 71
//#define FILLROOM 72
//#define RANDOMWALK 73
//#define SPHCAST 74		/* nz if an active sphere of annihilation */
////#define WTW 75			/* walk through walls */
//#define STREXTRA 76		/* character strength due to objects or  enchantments */
//#define TMP 77			/* misc scratch space */
//#define LIFEPROT 78		/* life protection counter */

                 /* defines for the objects in the game		 */

//#define OALTAR 1
//#define OTHRONE 2
//#define ODESTROYEDTHRONE 3
//#define OORB 4
//#define OPIT 5
//#define OSTAIRSUP 6
//#define OELEVATORUP 6
//#define OFOUNTAIN 7
//#define OSTATUE 8
//#define OTELEPORTER 9
//#define OSCHOOL 10
//#define OMIRROR 11
//#define ODNDSTORE 12
//#define OSTAIRSDOWN 11
//#define OELEVATORDOWN 14
//#define OBANK2 15
//#define OBANK 16
//#define ODEADFOUNTAIN 17
//#define OMAXGOLD 70
//#define OGOLDPILE 18
//#define OOPENDOOR 12
//#define OCLOSEDDOOR 13
//#define OWALL 21
//#define OTRAPARROW 66
//#define OTRAPARROWIV 67
//
//#define OLARNEYE 22
//
//#define OPLATE 23
//#define OCHAIN 24
//#define OLEATHER 25
//#define ORING 60
//#define OSTUDLEATHER 61
//#define OSPLINT 62
//#define OPLATEARMOR 63
//#define OSSPLATE 64
//#define OSHIELD 68
//#define OELVENCHAIN 92
//
//#define OSWORDofSLASHING 26
//#define OHAMMER 27
//#define OSWORD 28
//#define O2SWORD 29
//#define OSPEAR 30
//#define ODAGGER 31
//#define OBATTLEAXE 57
//#define OLONGSWORD 58
//#define OFLAIL 59
//#define OLANCE 65
//#define OVORPAL 90
//#define OSLAYER 91
//
//#define ORINGOFEXTRA 32
//#define OREGENRING 33
//#define OPROTRING 34
//#define OENERGYRING 35
//#define ODEXRING 36
//#define OSTRRING 37
//#define OCLEVERRING 38
//#define ODAMRING 39
//
//#define OBELT 40
//
//#define OSCROLL 41
//#define OPOTION 42
//#define OBOOK 43
//#define OCHEST 44
//#define OAMULET 45
//
//#define OORBOFDRAGON 46
//#define OSPIRITSCARAB 47
//#define OCUBEofUNDEAD 48
//#define ONOTHEFT 49
//
//#define ODIAMOND 50
//#define ORUBY 51
//#define OEMERALD 52
//#define OSAPPHIRE 53
//
//#define OENTRANCE 24
//#define OVOLDOWN 55
//#define OVOLUP 56
//#define OHOME 69
//
//#define OKGOLD 71
//#define ODGOLD 72
//#define OIVDARTRAP 73
//#define ODARTRAP 74
//#define OTRAPDOOR 75
//#define OIVTRAPDOOR 76
//#define OTRADEPOST 77
//#define OIVTELETRAP 78
//#define ODEADTHRONE 79
//#define OANNIHILATION 80	/* sphere of annihilation */
//#define OTHRONE2 81
//#define OLRS 82			/* Larn Revenue Service */
//#define OCOOKIE 83
//#define OURN 84
//#define OBRASSLAMP 85
//#define OHANDofFEAR 86		/* hand of fear */
//#define OSPHTAILSMAN 87		/* tailsman of the sphere */
//#define OWWAND 88		/* wand of wonder */
//#define OPSTAFF 89		/* staff of power */
///* used up to 92 */
//
///* defines for the monsters as objects		 */
//
//#define BAT 1
//#define GNOME 2
//#define HOBGOBLIN 3
//#define JACKAL 4
//#define KOBOLD 5
//#define ORC 6
//#define SNAKE 7
//#define CENTIPEDE 8
//#define JACULI 9
//#define TROGLODYTE 10
//#define ANT 11
//#define EYE 12
//#define LEPRECHAUN 13
//#define NYMPH 14
//#define QUASIT 15
//#define RUSTMONSTER 16
//#define ZOMBIE 17
//#define ASSASSINBUG 18
//#define BUGBEAR 19
//#define HELLHOUND 20
//#define ICELIZARD 21
//#define CENTAUR 22
//#define TROLL 23
//#define YETI 24
//#define WHITEDRAGON 25
//#define ELF 26
//#define CUBE 27
//#define METAMORPH 28
//#define VORTEX 29
//#define ZILLER 30
//#define VIOLETFUNGI 31
//#define WRAITH 32
//#define FORVALAKA 33
//#define LAMANOBE 34
//#define OSEQUIP 35
//#define ROTHE 36
//#define XORN 37
//#define VAMPIRE 38
//#define INVISIBLESTALKER 39
//#define POLTERGEIST 40
//#define DISENCHANTRESS 41
//#define SHAMBLINGMOUND 42
//#define YELLOWMOLD 43
//#define UMBERHULK 44
//#define GNOMEKING 45
//#define MIMIC 46
//#define WATERLORD 47
//#define BRONZEDRAGON 48
//#define GREENDRAGON 49
//#define PURPLEWORM 50
//#define XVART 51
//#define SPIRITNAGA 52
//#define SILVERDRAGON 53
//#define PLATINUMDRAGON 54
//#define GREENURCHIN 55
//#define REDDRAGON 56
//#define DEMONLORD 57
//#define DEMONPRINCE 64
//
//
//#define ITEM_OFFSET 32
/*
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
	int item_index;
	unsigned char item_symbol;
	int object_index;
	unsigned char object_symbol;
	int gold_value;
	int prox_ripple_value;
	bool visible;
    bool spell;
	Text_Colors color;  //white=1
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
	int stairs_down_x,stairs_down_y;
	int stairs_up_x,stairs_up_y;
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
    int x;
    int y;
    int d;
} prox_vector;
*/
#endif
