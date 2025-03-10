#ifndef GAME_DATA_H
#define GAME_DATA_H


//#include <stdio.h>
//#include <vector>
#include "common.h"

#include "constants.h"
//#include "game_defines.h"
//#include "player.h"
//#include <unordered_set>

class Game_Data
{

public:

    Game_Data();

    //Player player;

/*
    int current_level;
    int x_origin;
    int y_origin;
    int map_height;
    int map_width;
    int previous_state;
    int prev_state_x;
    int prev_state_y;
    int last_level_down_x;
    int last_level_down_y;
    int current_level_down_x;
    int current_level_down_y;
    int object_base_weapon_index;
    int max_game_time;
    int time_elapsed;
    int time_ticks;


    //int STRENGTH;
 //int INTELLIGENCE;
 //int WISDOM;
 //int CONSTITUTION;
 //int DEXTERITY;
 //int CHARISMA;
 //int HPMAX;
 //int HP;
 //int GOLD;
 //int EXPERIENCE;
 //int LEVEL;
 //int REGEN;
 //int WCLASS;
 //int AC;
 //int BANKACCOUNT;
 //int SPELLMAX;
 //int SPELLS;
 //int ENERGY;
 //int ECOUNTER;
 //int MOREDEFENSES;
 //int WEAR;
 //int PROTECTIONTIME;
 //int WIELD;
 //int AMULET;
 //int REGENCOUNTER;
 //int MOREDAM;
 //int DEXCOUNT;
 //int STRCOUNT;
 //int BLINDCOUNT;
 //int CAVELEVEL;
 //int CONFUSE;
 //int ALTPRO;
 //int HERO;
 //int CHARMCOUNT;
 //int INVISIBILITY;
 //int CANCELLATION;
 //int HASTESELF;
 //int EYEOFLARN;
 //int AGGRAVATE;
 //int GLOBE;
 //int TELEFLAG;
 //int SLAYING;
 //int NEGATESPIRIT;
 //int SCAREMONST;
 //int AWARENESS;
 //int HOLDMONST;
 //int TIMESTOP;
 //int HASTEMONST;
 //int CUBEofUNDEAD;
 //int GIANTSTR;
 //int FIRERESISTANCE;
 //int BESSMANN;
 //int NOTHEFT;
 //int HARDGAME;
 //int CPUTIME;
 //int BYTESIN;
 //int BYTESOUT;
 //int MOVESMADE;
 //int MONSTKILLED;
 //int SPELLSCAST;
 //int LANCEDEATH;
 //int SPIRITPRO;
 //int UNDEADPRO;
 //int SHIELD;
 //int STEALTH;
 //int ITCHING;
 //int LAUGHING;
 //int DRAINSTRENGTH;
 //int CLUMSINESS;
 //int INFEEBLEMENT;
 //int HALFDAM;
 //int SEEINVISIBLE;
 //int FILLROOM;
 //int RANDOMWALK;
 //int SPHCAST;
 //int WTW;
 //int STREXTRA;
 //int TMP;
 //int LIFEPROT;


    int OALTAR;
    int OTHRONE;
    int ODESTROYEDTHRONE;
    int OORB;
    int OPIT;
    int OSTAIRSUP;
    int OELEVATORUP;
    int OFOUNTAIN;
    int OSTATUE;
    int OTELEPORTER;
    int OSCHOOL;
    int OMIRROR;
    int ODNDSTORE;
    int OSTAIRSDOWN;
    int OELEVATORDOWN;
    int OBANK2;
    int OBANK;
    int ODEADFOUNTAIN;
    int OMAXGOLD;
    int OGOLDPILE;
    int OOPENDOOR;
    int OCLOSEDDOOR;
    int OWALL;
    int OFLOOR;
    int OTRAPARROW;
    int OTRAPARROWIV;

    int OLARNEYE;

    int OPLATE;
    int OCHAIN;
    int OLEATHER;
    int ORING;
    int OSTUDLEATHER;
    int OSPLINT;
    int OPLATEARMOR;
    int OSSPLATE;
    int OSHIELD;
    int OELVENCHAIN;

    int OSWORDofSLASHING;
    int OHAMMER;
    int OSWORD;
    int O2SWORD;
    int OSPEAR;
    int ODAGGER;
    int OBATTLEAXE;
    int OLONGSWORD;
    int OFLAIL;
    int OLANCE;
    int OVORPAL;
    int OSLAYER;

    int ORINGOFEXTRA;
    int OREGENRING;
    int OPROTRING;
    int OENERGYRING;
    int ODEXRING;
    int OSTRRING;
    int OCLEVERRING;
    int ODAMRING;

    int OBELT;

    int OSCROLL;
    int OPOTION;
    int OBOOK;
    int OCHEST;
    int OAMULET;

    int OORBOFDRAGON;
    int OSPIRITSCARAB;
    int OCUBEofUNDEAD;
    int ONOTHEFT;

    int ODIAMOND;
    int ORUBY;
    int OEMERALD;
    int OSAPPHIRE;

    int OENTRANCE;
    int OVOLDOWN;
    int OVOLUP;
    int OHOME;

    int OKGOLD;
    int ODGOLD;
    int OIVDARTRAP;
    int ODARTRAP;
    int OTRAPDOOR;
    int OIVTRAPDOOR;
    int OTRADEPOST;
    int OIVTELETRAP;
    int ODEADTHRONE;
    int OANNIHILATION;
    int OTHRONE2;
    int OLRS;
    int OCOOKIE;
    int OURN;
    int OBRASSLAMP;
    int OHANDofFEAR;
    int OSPHTAILSMAN;
    int OWWAND;
    int OPSTAFF;

    int Psleep;
    int Phealing;
    int Praise_level;
    int Pincrease_ability;
    int Pwisdom;
    int Pstrength;
    int Praise_charisma;
    int Pdizziness;
    int Plearning;
    int Pobject_detection;
    int Pmonster_detection;
    int Pforgetfulness;
    int Pwater;
    int Pblindness;
    int Pconfusion;
    int Pheroism;
    int Psturdiness;
    int Pgiant_strength;
    int Pfire_resistance;
    int Ptreasure_finding;
    int Pinstant_healing;
    int Ppoison;
    int Psee_invisible;
    int Senchant_armor;
    int Senchant_weapon;
    int Senlightenment;
    int Sblank_papper;
    int Screate_monster;
    int Screate_artifact;
    int Saggravate_monsters;
    int Stime_warp;
    int Steleportation;
    int Sexpanded_awareness;
    int Shaste_monsters;
    int Smonster_healing;
    int Sspirit_protection;
    int Sundead_protection;
    int Sstealth;
    int Smagic_mapping;
    int Shold_monsters;
    int Sgem_perfection;
    int Sspell_extension;


    int BAT;
    int GNOME;
    int HOBGOBLIN;
    int JACKAL;
    int KOBOLD;
    int ORC;
    int SNAKE;
    int CENTIPEDE;
    int JACULI;
    int TROGLODYTE;
    int ANT;
    int EYE;
    int LEPRECHAUN;
    int NYMPH;
    int QUASIT;
    int RUSTMONSTER;
    int ZOMBIE;
    int ASSASSINBUG;
    int BUGBEAR;
    int HELLHOUND;
    int ICELIZARD;
    int CENTAUR;
    int TROLL;
    int YETI;
    int WHITEDRAGON;
    int ELF;
    int CUBE;
    int METAMORPH;
    int VORTEX;
    int ZILLER;
    int VIOLETFUNGI;
    int WRAITH;
    int FORVALAKA;
    int LAMANOBE;
    int OSEQUIP;
    int ROTHE;
    int XORN;
    int VAMPIRE;
    int INVISIBLESTALKER;
    int POLTERGEIST;
    int DISENCHANTRESS;
    int SHAMBLINGMOUND;
    int YELLOWMOLD;
    int UMBERHULK;
    int GNOMEKING;
    int MIMIC;
    int WATERLORD;
    int BRONZEDRAGON;
    int GREENDRAGON;
    int PURPLEWORM;
    int XVART;
    int SPIRITNAGA;
    int SILVERDRAGON;
    int PLATINUMDRAGON;
    int GREENURCHIN;
    int REDDRAGON;
    int DEMONLORD;
    int DEMONPRINCE;


    int ITEM_OFFSET;*/
    int current_level{};
int x_origin{};
int y_origin{};
int map_height{};
int map_width{};
int previous_state{};
int prev_state_x{};
int prev_state_y{};

    int last_level_down_x{ 1 };
    int last_level_down_y{ 1 };
    int current_level_down_x{ 1 };
    int current_level_down_y{ 1 };
    int object_base_weapon_index{ 0 };
    int max_game_time{ 600 };
    int time_elapsed{ 0 };
    int time_ticks{ 0 };



    /*
    int STRENGTH{0};
        int INTELLIGENCE{1};
        int WISDOM{2};
        int CONSTITUTION{3};
        int DEXTERITY{4};
        int CHARISMA{5};
        int HPMAX{6};
        int HP{7};
        int GOLD{8};
        int EXPERIENCE{9};
        int LEVEL{10};
        int REGEN{11};
        int WCLASS{12};
        int AC{13};
        int BANKACCOUNT{14};
        int SPELLMAX{15};
        int SPELLS{16};
        int ENERGY{17};
        int ECOUNTER{18};
        int MOREDEFENSES{19};
        int WEAR{20};
        int PROTECTIONTIME{21};
        int WIELD{22};
        int AMULET{23};
        int REGENCOUNTER{24};
        int MOREDAM{25};
        int DEXCOUNT{26};
        int STRCOUNT{27};
        int BLINDCOUNT{28};
        int CAVELEVEL{29};
        int CONFUSE{30};
        int ALTPRO{31};
        int HERO{32};
        int CHARMCOUNT{33};
        int INVISIBILITY{34};
        int CANCELLATION{35};
        int HASTESELF{36};
        int EYEOFLARN{37};
        int AGGRAVATE{38};
        int GLOBE{39};
        int TELEFLAG{40};
        int SLAYING{41};
        int NEGATESPIRIT{42};
        int SCAREMONST{43};
        int AWARENESS{44};
        int HOLDMONST{45};
        int TIMESTOP{46};
        int HASTEMONST{47};
        int CUBEofUNDEAD{48};
        int GIANTSTR{49};
        int FIRERESISTANCE{50};
        int BESSMANN{51};
        int NOTHEFT{52};
        int HARDGAME{53};
        int CPUTIME{54};
        int BYTESIN{55};
        int BYTESOUT{56};
        int MOVESMADE{57};
        int MONSTKILLED{58};
        int SPELLSCAST{59};
        int LANCEDEATH{60};
        int SPIRITPRO{61};
        int UNDEADPRO{62};
        int SHIELD{63};
        int STEALTH{64};
        int ITCHING{65};
        int LAUGHING{66};
        int DRAINSTRENGTH{67};
        int CLUMSINESS{68};
        int INFEEBLEMENT{69};
        int HALFDAM{70};
        int SEEINVISIBLE{71};
        int FILLROOM{72};
        int RANDOMWALK{73};
        int SPHCAST{74};
        int WTW{75};
        int STREXTRA{76};
        int TMP{77};
        int LIFEPROT{78};
        */

    int OFLOOR{ 0 };
    int OALTAR{ 1 };
    int OTHRONE{ 2 };
    int ODESTROYEDTHRONE{ 3 };
    int OORB{ 4 };
    int OPIT{ 5 };
    int OSTAIRSUP{ 6 };
    int OFOUNTAIN{ 7 };
    int ODEADFOUNTAIN{ 8 };
    int OSTATUE{ 9 };
    int OMIRROR{ 10 };
    int OSTAIRSDOWN{ 11 };//check this
    int OOPENDOOR{ 12 };//check this 13
    int OCLOSEDDOOR{ 13 };//check this 14
    //int //OELEVATORDOWN {11};
    //int //ODEADFOUNTAIN {17};
    int OTRAPARROW{ 14 };
    int OTRAPARROWIV{ 15 };
    int ODARTRAP{ 16 };
    int OIVDARTRAP{ 17 };
    int OTRAPDOOR{ 18 };
    int OIVTRAPDOOR{ 19 };
    int OTELEPORTER{ 20 };
    int OIVTELETRAP{ 21 };
    int OANNIHILATION{ 22 };
    int OSCHOOL{ 23 };
    int OENTRANCE{ 24 };//fix 25
    int OVOLDOWN{ 25 };
    //int OVOLUP {56};
    int OHOME{ 26 };
    int OLRS{ 27 };
    int ODNDSTORE{ 28 };
    int OBANK{ 29 };
    int OBANK2{ 30 };
    int OTRADEPOST{ 31 };
    int OLARNEYE{ 32 };
    int OPLATE{ 33 };
    int OCHAIN{ 34 };
    int OLEATHER{ 35 };
    int ORING{ 36 };
    int OSTUDLEATHER{ 37 };
    int OSPLINT{ 38 };
    int OPLATEARMOR{ 39 };
    int OSSPLATE{ 40 };
    int OSHIELD{ 41 };
    int OSWORDofSLASHING{ 42 };
    int OHAMMER{ 43 };
    int OSWORD{ 44 };
    int O2SWORD{ 45 };
    int OSPEAR{ 46 };
    int ODAGGER{ 47 };
    int OBATTLEAXE{ 48 };
    int OLONGSWORD{ 49 };
    int OFLAIL{ 50 };
    int OLANCE{ 51 };
    int ORINGOFEXTRA{ 52 };
    int OREGENRING{ 53 };
    int OPROTRING{ 54 };
    int OENERGYRING{ 55 };
    int ODEXRING{ 56 };
    int OSTRRING{ 57 };
    int OCLEVERRING{ 58 };
    int ODAMRING{ 59 };
    int OBELT{ 60 };
    int OSCROLL{ 61 };
    int OPOTION{ 62 };
    int OBOOK{ 63 };
    int OCHEST{ 64 };
    int OAMULET{ 65 };
    int OCOOKIE{ 66 };
    int OORBOFDRAGON{ 67 };
    int OSPIRITSCARAB{ 68 };
    int OCUBEofUNDEAD{ 69 };
    int ONOTHEFT{ 70 };

    int ODIAMOND{ 71 };
    int ORUBY{ 72 };
    int OEMERALD{ 73 };
    int OSAPPHIRE{ 74 };

    int Psleep{ 76 };
    int Phealing{ 77 };
    int Praise_level{ 78 };
    int Pincrease_ability{ 79 };
    int Pwisdom{ 80 };
    int Pstrength{ 81 };
    int Praise_charisma{ 82 };
    int Pdizziness{ 83 };
    int Plearning{ 84 };
    int Pobject_detection{ 85 };
    int Pmonster_detection{ 86 };
    int Pforgetfulness{ 87 };
    int Pwater{ 88 };
    int Pblindness{ 89 };
    int Pconfusion{ 90 };
    int Pheroism{ 91 };
    int Psturdiness{ 92 };
    int Pgiant_strength{ 93 };
    int Pfire_resistance{ 94 };
    int Ptreasure_finding{ 95 };
    int Pinstant_healing{ 96 };
    int Ppoison{ 97 };
    int Psee_invisible{ 98 };
    int Senchant_armor{ 99 };
    int Senchant_weapon{ 100 };
    int Senlightenment{ 101 };
    int Sblank_papper{ 102 };
    int Screate_monster{ 103 };
    int Screate_artifact{ 104 };
    int Saggravate_monsters{ 105 };
    int Stime_warp{ 106 };
    int Steleportation{ 107 };
    int Sexpanded_awareness{ 108 };
    int Shaste_monsters{ 109 };
    int Smonster_healing{ 110 };
    int Sspirit_protection{ 111 };
    int Sundead_protection{ 112 };
    int Sstealth{ 113 };
    int Smagic_mapping{ 114 };
    int Shold_monsters{ 115 };
    int Sgem_perfection{ 116 };
    int Sspell_extension{ 117 };




    int OKGOLD{ 71 };
    int ODGOLD{ 72 };


    int ODEADTHRONE{ 79 };

    int OTHRONE2{ 81 };




    int OURN{ 84 };
    int OBRASSLAMP{ 85 };
    int OHANDofFEAR{ 86 };
    int OSPHTAILSMAN{ 87 };
    int OWWAND{ 88 };
    int OPSTAFF{ 89 };
    int OELVENCHAIN{ 92 };
    int OVORPAL{ 90 };
    int OSLAYER{ 91 };
    int OMAXGOLD{ 70 };
    int OGOLDPILE{ 18 };
    int OWALL{ 35 };

    int BAT{ 1 };
    int GNOME{ 2 };
    int HOBGOBLIN{ 3 };
    int JACKAL{ 4 };
    int KOBOLD{ 5 };
    int ORC{ 6 };
    int SNAKE{ 7 };
    int CENTIPEDE{ 8 };
    int JACULI{ 9 };
    int TROGLODYTE{ 10 };
    int ANT{ 11 };
    int EYE{ 12 };
    int LEPRECHAUN{ 13 };
    int NYMPH{ 14 };
    int QUASIT{ 15 };
    int RUSTMONSTER{ 16 };
    int ZOMBIE{ 17 };
    int ASSASSINBUG{ 18 };
    int BUGBEAR{ 19 };
    int HELLHOUND{ 20 };
    int ICELIZARD{ 21 };
    int CENTAUR{ 22 };
    int TROLL{ 23 };
    int YETI{ 24 };
    int WHITEDRAGON{ 25 };
    int ELF{ 26 };
    int CUBE{ 27 };
    int METAMORPH{ 28 };
    int VORTEX{ 29 };
    int ZILLER{ 30 };
    int VIOLETFUNGI{ 31 };
    int WRAITH{ 32 };
    int FORVALAKA{ 33 };
    int LAMANOBE{ 34 };
    int OSEQUIP{ 35 };
    int ROTHE{ 36 };
    int XORN{ 37 };
    int VAMPIRE{ 38 };
    int INVISIBLESTALKER{ 39 };
    int POLTERGEIST{ 40 };
    int DISENCHANTRESS{ 41 };
    int SHAMBLINGMOUND{ 42 };
    int YELLOWMOLD{ 43 };
    int UMBERHULK{ 44 };
    int GNOMEKING{ 45 };
    int MIMIC{ 46 };
    int WATERLORD{ 47 };
    int BRONZEDRAGON{ 48 };
    int GREENDRAGON{ 49 };
    int PURPLEWORM{ 50 };
    int XVART{ 51 };
    int SPIRITNAGA{ 52 };
    int SILVERDRAGON{ 53 };
    int PLATINUMDRAGON{ 54 };
    int GREENURCHIN{ 55 };
    int REDDRAGON{ 56 };
    int DEMONLORD{ 57 };
    int DEMONPRINCE{ 64 };


    int ITEM_OFFSET{ 32 };


    int dungeon_tile_texture_index[5]{};
    int current_map{ 0 }; //this is the current texture file for the map
    int current_map_set{ 1 }; // this is whether the first or second map is being used

    std::unordered_set<char> dung_chars;
    std::unordered_map<int, MAP_BLOCK_ElEMENT> umap_blocks;
    std::vector< std::unordered_map<int, MAP_BLOCK_ElEMENT>> list_map_block_sets;
    
    int character_map_texture_size[1][2]{};

    SDL_Rect display_characters_sizepos[256]{};
   
    //SDL_Rect  dungeon_texture_layout[MAX_Y][MAX_X + 1];
    //bool level_visited[MAX_DUNGEON_LEVEL]{};
    std::vector<bool> level_visited;

    std::vector< MAP_BLOCK_ElEMENT> map_blocks;

    MAP_BLOCK dungeon_level[MAX_Y][MAX_X + 1]{};
    MAP_BLOCK dungeon_level_test[MAX_Y][MAX_X + 1]{};
};
#endif
