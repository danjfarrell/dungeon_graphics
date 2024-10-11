#ifndef UI_DISPLAY_H
#define UI_DISPLAY_H

#include <vector>
#include <stdio.h>
#include <stdlib.h>     /* atoi */
#include <stdexcept>      // std::out_of_range
#include <time.h>
#include <string.h>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstdarg>
#include "SDL.h"
#include "constants.h"
//#include "core_engine.h"

class Core_Engine;

class UI_Display
{
private:
    int n;
    char str[200];
    FILE* output_check;
    
    typedef struct
    {
        char element[20];
        int pos_y;
        int pos_x;
    } DISPLAY_ELEMENTS;
    
    typedef struct
    {
        int pos_y;
        int pos_x;
    } DISPLAY_POS;

    DISPLAY_POS display_pos[NUM_DISP_ELEM];


public:

    UI_Display();
    ~UI_Display();



    std::vector<SDL_Texture*> textures_list;

    std::vector<SDL_Rect> texture_size_list;
    

    std::vector<std::string>  messagelist;

    std::vector<DISPLAY_ELEMENTS>  display_elements;

       
    int mouse_pos_x, mouse_pos_y, player_pos_x,player_pos_y, message_x, message_y;

    //char message_list[UI_MESSAGE_SIZE_LIST][UI_MESSAGE_MAX_SIZE];
    std::string message_list[UI_MESSAGE_SIZE_LIST];
    SDL_Color message_color[UI_MESSAGE_SIZE_LIST];
    int messages_ttl[UI_MESSAGE_SIZE_LIST];
    int message_id_list[UI_MESSAGE_SIZE_LIST];
    bool message_keepalive[UI_MESSAGE_SIZE_LIST];
    int message_id;

    int Get_Next_Message_Id();
    void Set_Keep_Alive(int id);
    void Clear_Keep_Alive(int id);

    void UI_Load(Core_Engine& core);
    void Display_UI(Core_Engine& core);
    void Display_mouse_pos(Core_Engine& core);
    void Display_Inventory(Core_Engine& core, int starting_x_pos, int starting_y_pos, bool full_screen = false);
   // bool Add_ui_message(std::string new_message, SDL_Color color = {18,0,128}, int id = 1);
    bool Add_ui_message(std::string new_message, SDL_Color color = { 18,0,128 });
    /* bool Add_ui_message_long(std::string new_message, SDL_Color color = { 18,120,128 }, int max_size = 21);
    bool Add_ui_message_printf(SDL_Color color, int max_size, const char* fmt = "test", ...);*/
    
    int Add_ui_message_long(std::string new_message, SDL_Color color = { 18,120,128 }, int max_size = 21);
    int Add_ui_message_printf(SDL_Color color, int max_size, const char* fmt = "test", ...);
    
    void Display_player_data(Core_Engine& core);
    void reset_ttl(int num_messages);
    //void Display_player_data(Display_Engine& disp, Player& player, Spells& spells);



    void display_cmds(Core_Engine& core);
    void display_shop(Core_Engine& core);
    void display_shop_dnd(Core_Engine& core);
    void display_shop_trading(Core_Engine& core);
    void display_shop_bank(Core_Engine& core);
    void display_message_list(Core_Engine& core);


};
#endif
