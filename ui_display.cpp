#include "ui_display.h"
#include "core_engine.h"

UI_Display::UI_Display()
{
    //printf("ui \n");
    //char test[UI_MESSAGE_MAX_SIZE];
//    std::string blank = " ";
//    int n;
    for(int i =0;i<UI_MESSAGE_SIZE_LIST;i++)
    {
////       n = sprintf(test," ");
//       //strcpy(message_list[i],test);
//        message_list[i] = blank;
        messagelist.push_back("   ");
        message_color[i]={128,55,128};
        messages_ttl[i] = -1;
        message_id_list[i] = -1;
        message_keepalive[i] = false;
        message_id = 0;
    }
    //printf("ui_2 \n");
    mouse_pos_x = 900;
    mouse_pos_y = 500;

    output_check = fopen("ui.txt","w");
    fclose(output_check);
    strcpy(str, " ");
    message_x = 0;
    message_y = 0;
    player_pos_x = 0;
    player_pos_y = 0;
        n = 0;
        
        for (int i = 0; i < NUM_DISP_ELEM; i++)
        {
            display_pos[i].pos_y = 10;
            display_pos[i].pos_x = 10;

        }

    return;

}

int UI_Display::Get_Next_Message_Id()
{
    message_id++;
    return message_id;
}

void UI_Display::UI_Load(Core_Engine& core)
{

    printf("ui loading");
    


    if(core.disp.Load_Texture_list_from_file("gamedata\\resources\\ui_resources.txt",textures_list,texture_size_list))
    {
        printf("loaded ui texture list\n");
    }
    /*****************
    load ui elements and setup displays
    *****/
    FILE* resource_file = fopen("gamedata\\resources\\ui_display_pos.txt", "r");
    if (resource_file == NULL)
    {
        printf("failed to open ui display pos\n");
        //return false;
    }
    printf("\n********\nloading ui display position values\n");

    const unsigned MAX_LENGTH = 256;
    char buffer[MAX_LENGTH];
    const char s[2] = " ";
    char* token;
    //char* token_y;
    //char* token_x;
   // int val_x, val_y;
    std::vector<std::string>  tokens_elements;


    while (fgets(buffer, MAX_LENGTH, resource_file))
    {    
        /* get the first token */
        token = strtok(buffer, s);
        while (token != NULL)
        {
            printf("%s\n", token);
            tokens_elements.push_back(token);
            token = strtok(NULL, s);
        }
        printf("tokens_elements.size() = %i\n", tokens_elements.size());
        if (tokens_elements.size() == 3)
        {
            DISPLAY_ELEMENTS temp_element;
            strcpy(temp_element.element, tokens_elements[0].c_str());
            temp_element.pos_x = atoi(tokens_elements[1].c_str());
            temp_element.pos_y = atoi(tokens_elements[2].c_str());
            display_elements.push_back(temp_element);
        }
        
        tokens_elements.clear();
        
    }

    fclose(resource_file);


    printf("display_elements.size() = %i\n", display_elements.size());


    for (unsigned int i = 0; i < display_elements.size(); i++)
    {
        int x = display_elements[i].pos_x;
        int y = display_elements[i].pos_y;
        printf("%d %d : %d\n", i,x,y);
        if (strcmp("p_name", display_elements[i].element)==0)
        {
            
            display_pos[0].pos_y = y;
            display_pos[0].pos_x = x;
        }
        else if (strcmp("p_xp", display_elements[i].element)==0)
        {
            display_pos[1].pos_y = y;
            display_pos[1].pos_x = x;

        }
        else if (strcmp("p_time", display_elements[i].element) == 0)
        {
            display_pos[2].pos_y = y;
            display_pos[2].pos_x = x;

        }
        else if (strcmp("p_level", display_elements[i].element) == 0)
        {
            display_pos[3].pos_y = y;
            display_pos[3].pos_x = x;

        }
        else if (strcmp("p_hp", display_elements[i].element) == 0)
        {
            display_pos[4].pos_y = y;
            display_pos[4].pos_x = x;

        }
        else if (strcmp("p_mp", display_elements[i].element) == 0)
        {
            display_pos[5].pos_y = y;
            display_pos[5].pos_x = x;

        }
        else if (strcmp("p_damage", display_elements[i].element) == 0)
        {
            display_pos[6].pos_y = y;
            display_pos[6].pos_x = x;

        }
        else if (strcmp("p_attack", display_elements[i].element) == 0)
        {
            display_pos[7].pos_y = y;
            display_pos[7].pos_x = x;

        }
        else if (strcmp("p_gold", display_elements[i].element) == 0)
        {
            display_pos[8].pos_y = y;
            display_pos[8].pos_x = x;

        }
        else if (strcmp("p_str", display_elements[i].element) == 0)
        {
            display_pos[9].pos_y = y;
            display_pos[9].pos_x = x;

        }
        else if (strcmp("p_dex", display_elements[i].element) == 0)
        {
            display_pos[10].pos_y = y;
            display_pos[10].pos_x = x;

        }
        else if (strcmp("p_ac", display_elements[i].element) == 0)
        {
            display_pos[11].pos_y = y;
            display_pos[11].pos_x = x;

        }
        else if (strcmp("invent", display_elements[i].element) == 0)
        {
            display_pos[12].pos_y = y;
            display_pos[12].pos_x = x;

        }
        else if (strcmp("spells", display_elements[i].element) == 0)
        {
            display_pos[13].pos_y = y;
            display_pos[13].pos_x = x;

        }
        else
        {
            printf("no display element named that \n \t try again\n");
        }



    }






    printf("load complete\n");



    return;

}

void UI_Display::display_message_list(Core_Engine& core)
{
    for (int i = 0; i < (int)messagelist.size(); i++)
    {
        message_x = 5;
        message_y = 750 - (i * FONT_1_SIZE);

        if (messages_ttl[i] > 255)
        {

            core.disp.Disp_Text(messagelist.at(i), FONT_1, message_color[i], message_x, message_y);
            n = sprintf(str, "TTL: %d, ", messages_ttl[i]);
            core.disp.Disp_Text(str, FONT_1, message_color[i], 550, message_y);
        }
        else if (messages_ttl[i] > 0)
        {

            message_color[i].a--;
            core.disp.Disp_Text(messagelist.at(i), FONT_1, message_color[i], message_x, message_y);

        }
        if (message_keepalive[i] == false)
        {
            messages_ttl[i]--;
            if (messages_ttl[i] < -1)
            {
                messages_ttl[i] = -1;
            }
        }
    }
    
    return;

}

void UI_Display::Display_UI(Core_Engine& core)
{
    char str[50];
    SDL_Rect size_pos;
    size_pos.h=8;
    size_pos.w=8;
    size_pos.x=MAP_X_OFFSET;
    size_pos.y=MAP_Y_OFFSET;


   // printf("\tyo\n");
    //disp.Disp_Text_Wrapped("displaying ui! \nmore text",FONT_1,{35,55,128}, 225, 500);
    //.Apply_Texture(0, texture_size_list, textures_list);
    //disp.Apply_Texture_with_Alpha(0, size_pos, textures_list,100);
    //size_pos.h=(AREA_Y*2*FONT_SIZE)+(FONT_SIZE*2);
    //size_pos.w=(AREA_X*2*FONT_SIZE )+(FONT_SIZE*2);
    //size_pos.x=MAP_X_OFFSET-FONT_SIZE;
    //size_pos.y=MAP_Y_OFFSET-FONT_SIZE;
    //disp.Apply_Texture(2, size_pos, textures_list);

/******************** draws a border around the map
    size_pos.h=(FONT_SIZE);
    size_pos.w=(AREA_X*2*FONT_SIZE )+(FONT_SIZE*2);
    size_pos.x=MAP_X_OFFSET-FONT_SIZE;
    size_pos.y=MAP_Y_OFFSET-FONT_SIZE;

    disp.Draw_Rect(size_pos,0,65,10);
    size_pos.y=MAP_Y_OFFSET+(AREA_Y*2*(FONT_SIZE)+FONT_SIZE );
    disp.Draw_Rect(size_pos,0,65,10);


    size_pos.h=(AREA_Y*2*FONT_SIZE)+(FONT_SIZE*2);
    size_pos.w=FONT_SIZE;
    size_pos.x=MAP_X_OFFSET-FONT_SIZE;
    size_pos.y=MAP_Y_OFFSET-FONT_SIZE;

    disp.Draw_Rect(size_pos,0,65,10);
    size_pos.x=MAP_X_OFFSET+(AREA_X*2*FONT_SIZE );
    disp.Draw_Rect(size_pos,0,65,10);
*************************************************/



    //SDL_Color outputcolor;
   


    display_message_list(core);



   Display_mouse_pos(core);
   // int w, h;
    n = sprintf(str, "Time Elapsed: %d, Time Left: %d", core.game_data.time_elapsed, (core.game_data.max_game_time - core.game_data.time_elapsed));
    //printf("ticks=%s\n", str);
    core.disp.Disp_Text(str, FONT_2, { 128,55,128,255 }, display_pos[2].pos_x, display_pos[2].pos_y);
    
    n = sprintf(str, "Time Ticks: %d", core.game_data.time_ticks);
    core.disp.Disp_Text(str, FONT_2, { 128,55,128,255 }, display_pos[2].pos_x, display_pos[2].pos_y+25);

    //core.debug = true;
    if (DEBUG)
    {
        n = sprintf(str, "Input sys variables");
        core.disp.Disp_Text(str, FONT_1, { 128,55,128,255 }, 850, 600);
        n = sprintf(str, "Left Cntl: %d %d", core.input.KEY_LCTRL, core.input.KEY_LCTRL_up);
        core.disp.Disp_Text(str, FONT_1, { 128,55,128,255 }, 850, 620);
        n = sprintf(str, "        C: %d %d", core.input.KEY_c, core.input.KEY_c_up);
        core.disp.Disp_Text(str, FONT_1, { 128,55,128,255 }, 850, 640);
        n = sprintf(str, "        Z: %d %d", core.input.KEY_z,core.input.KEY_z_up);
        core.disp.Disp_Text(str, FONT_1, { 128,55,128,255 }, 850, 660);
        n = sprintf(str, "        player state: %d", core.player.player_input_states);
        core.disp.Disp_Text(str, FONT_1, { 128,55,128,255 }, 850, 680);

        
    }


    Display_player_data(core);

   // SDL_GetRendererOutputSize(disp.ren, &w, &h);
   // n = sprintf(str, "w=%d h=%d", w, h);
   // disp.Disp_Text(str, FONT_1, { 128,55,128 }, 1000, 5);


    return;
}

void UI_Display::Display_mouse_pos(Core_Engine& core)
{


   int x_value;
   int y_value;
   x_value=(core.input.mouse_x-MAP_X_OFFSET)/FONT_SIZE;
   y_value=(core.input.mouse_y-MAP_Y_OFFSET)/FONT_SIZE;
   if(x_value<0)
   {
       x_value=0;
   }else if(x_value>MAX_X)
   {
       x_value=MAX_X;
   }
    if(y_value<0)
   {
       y_value=0;
   }else if(y_value>MAX_Y)
   {
       y_value=MAX_Y;
   }
   
   SDL_Rect rect;
   rect.x = (x_value * FONT_SIZE)+ MAP_X_OFFSET;
   rect.y = (y_value * FONT_SIZE)+ MAP_Y_OFFSET;
   rect.h = FONT_SIZE;
   rect.w = FONT_SIZE;
   if (((x_value <= 47) && (y_value <= 25))&& ((x_value >= 0) && (y_value >= 0)))
   {
       core.disp.Draw_Rect(rect, 255, 15, 15, true);
   }
   /*n = sprintf(str, "mouse x=%d;\nmouse_move_inprogress=%d ", core.player.mouse_x_move_target, core.player.mouse_move_inprogress);
   core.disp.Disp_Text_Wrapped(str, FONT_1, { 0,128,128 }, 800, 75);
   n = sprintf(str, "player.x=%d,player.y=%d",  core.player.x, core.player.y);
   core.disp.Disp_Text_Wrapped(str, FONT_1, { 0,128,128 }, 800, 125);
   n = sprintf(str, "grid.x=%d,grid.y=%d", x_value, y_value);
   core.disp.Disp_Text_Wrapped(str, FONT_1, { 0,128,128 }, 800, 175);
   n = sprintf(str, "x_min=%d,x_max.y=%d", core.game_map.x_min, core.game_map.x_max);
   core.disp.Disp_Text_Wrapped(str, FONT_1, { 0,128,128 }, 800, 200);*/
   //n = sprintf(str, "FONT_SIZE=%d", FONT_SIZE);
   //core.disp.Disp_Text_Wrapped(str, FONT_1, { 0,128,128 }, 800, 175);
}

void UI_Display::Display_player_data(Core_Engine& core)
{
    //update player location
    n=sprintf(str, "Name:%s",core.player.stats.name);
    core.disp.Disp_Text_Wrapped(str,FONT_1,{0,128,128}, display_pos[0].pos_x, display_pos[0].pos_y);
    n=sprintf(str, "Level:%d", core.player.stats.level);
    core.disp.Disp_Text_Wrapped(str,FONT_1,{0,128,128}, display_pos[3].pos_x, display_pos[3].pos_y);
    n=sprintf(str, "HP:%d", core.player.stats.hp);
    core.disp.Disp_Text_Wrapped(str,FONT_1,{0,128,128}, display_pos[4].pos_x, display_pos[4].pos_y);
   n = sprintf(str, "MP:%d", core.player.stats.mp);
   core.disp.Disp_Text_Wrapped(str, FONT_1, { 0,128,128 }, display_pos[5].pos_x, display_pos[5].pos_y);
    n=sprintf(str, "Dmg:%d", core.player.stats.damage);
    core.disp.Disp_Text_Wrapped(str,FONT_1,{0,128,128}, display_pos[6].pos_x, display_pos[6].pos_y);
   n = sprintf(str, "Atk:%d", core.player.stats.attack_power);
   core.disp.Disp_Text_Wrapped(str, FONT_1, { 0,128,128 }, display_pos[7].pos_x, display_pos[7].pos_y);
   n = sprintf(str, "AC:%d", core.player.stats.defense);
   core.disp.Disp_Text_Wrapped(str, FONT_1, { 0,128,128 }, display_pos[11].pos_x, display_pos[11].pos_y);
    n=sprintf(str, "GOLD:%d", core.player.stats.gold);
    core.disp.Disp_Text_Wrapped(str,FONT_1,{0,128,128}, display_pos[8].pos_x, display_pos[8].pos_y);
   n=sprintf(str, "XP:%d", core.player.stats.exp);
   core.disp.Disp_Text_Wrapped(str, FONT_1, { 0,128,128 }, display_pos[1].pos_x, display_pos[1].pos_y);
   n = sprintf(str, "STR:%d", core.player.stats.str);
   core.disp.Disp_Text_Wrapped(str, FONT_1, { 0,128,128 }, display_pos[9].pos_x, display_pos[9].pos_y);
   n = sprintf(str, "DEX:%d", core.player.stats.dex);
   core.disp.Disp_Text_Wrapped(str, FONT_1, { 0,128,128 }, display_pos[10].pos_x, display_pos[10].pos_y);
   //disp.Disp_Text_Wrapped(str,FONT_1,{0,128,128}, 750, 600);
   //   n=sprintf(str, "alive=%d",player.alive);
   
   if(core.player.WTW)
   {
       core.disp.Disp_Text_Wrapped("WTW",FONT_1,{0,0,128}, 900, 480);
   }
   if (core.player.invincible)
   {
       core.disp.Disp_Text_Wrapped("INVINCIBLE", FONT_1, { 0,0,128 }, 700, 480);
   }

   //n = sprintf(str, "y=%d, x= %d", core.player.y,core.player.x);
   //core.disp.Disp_Text_Wrapped(str, FONT_1, { 0,128,128 }, 750, 450);


   Display_Inventory(core, display_pos[12].pos_x, display_pos[12].pos_y);


   //if(core.player.inventory.size()>0)
   //{
   //  for(int x=0;x< (int)core.player.inventory.size();x++)
   //  { 
   //     if(core.player.inventory[x].is_equipped)
   //     {
   //         
   //         n = sprintf(str, "%c.) [e] %s", (x + 65), core.objects.object_names[core.player.inventory[x].id].c_str());
   //         core.disp.Disp_Text_Wrapped(str,FONT_1,{0,128,128}, inventory_base_x, inventory_base_y+=20);
   //        
   //     }else
   //     {
   //         //n=sprintf(str, "%c.) %s",(x+65),objects.object_names[player.inventory[x].id].c_str());
   //        
   //         n = sprintf(str, "%c.) %s", (x + 65), core.objects.object_names[core.player.inventory[x].id].c_str());
   //         //printf("%d\n", player.inventory[x].id);
   //         core.disp.Disp_Text_Wrapped(str,FONT_1,{0,128,128}, inventory_base_x, inventory_base_y += 20);
   //         
   //     }

   //  }
   //}

   int spell_base_y = display_pos[13].pos_y;
   int spell_base_x = display_pos[13].pos_x;

   core.disp.Disp_Text_Wrapped("Spells:", FONT_1, { 0,255,128 }, spell_base_x - 20, spell_base_y);

   for (int x = 0; x < NUM_SPELLS; x++)
   {
       if (core.player.known_spells[x])
       {
           n = sprintf(str, "%s - %s", core.spells.spellcode[x], core.spells.spellname [x]);
           core.disp.Disp_Text_Wrapped(str, FONT_1, { 0,128,255 }, spell_base_x, spell_base_y += 20);
           //n = sprintf(str, "%s", spells.speldescript[x]);
           //disp.Disp_Text_Wrapped(str, FONT_1, { 0,128,128 }, spell_base_x+20, spell_base_y += 20);
       }

   }

   
   // n = sprintf(str, "%d, ", player.effects_durations[0]);
  // disp.Disp_Text(str, FONT_1, { 128,55,128,255 }, 1000, 600);
   if ((core.player.effects_durations[0] > 0) || (core.player.effects_durations[0] == -1))
   {
       n = sprintf(str, "PRO");
       core.disp.Disp_Text(str, FONT_1, { 128,55,128,255 }, 600, 400);
   }

   display_cmds(core);

}
void UI_Display::display_cmds(Core_Engine& core)
{
    SDL_Rect size_pos;

    /******************** draws a border around the map */
        size_pos.h=150;
        size_pos.w=500;
        size_pos.x=850;
        size_pos.y=600;

        core.disp.Draw_Rect(size_pos,200,65,10,true);
        
        core.disp.Disp_Text_Wrapped("Equip Armor: LCNTRL + Z", FONT_2, { 128,128,128 }, 870, 620);
        core.disp.Disp_Text_Wrapped("Equip Weapon: LCNTRL + X", FONT_2, { 128,128,128 }, 870, 640);
        core.disp.Disp_Text_Wrapped("Cast Spell: LCNTRL + C", FONT_2, { 128,128,128 }, 870, 660);
        core.disp.Disp_Text_Wrapped("Read Scroll: LCNTRL + R", FONT_2, { 128,128,128 }, 870, 680);
        core.disp.Disp_Text_Wrapped("Drink Potion: LCNTRL + Q", FONT_2, { 128,128,128 }, 870, 700);
        core.disp.Disp_Text_Wrapped("Drop Item: LCNTRL + D", FONT_2, { 128,128,128 }, 870, 720);
    /************************************************/

}
void UI_Display::Display_Inventory(Core_Engine& core, int starting_x_pos, int starting_y_pos, bool full_screen)
{
    int inventory_base_y = starting_y_pos;
    int inventory_base_x = starting_x_pos;

    if (!full_screen)
    {
        core.disp.Disp_Text_Wrapped("Inventory:", FONT_2, { 0,128,128 }, inventory_base_x - 20, inventory_base_y);
        inventory_base_y += 20;
        for (int x = 0; x < core.inventory.inven_size; x++)
        {
            if (x < 10)
            {
                if (core.inventory.inven[x].is_equipped)
                {

                    n = sprintf(str, "%c.) [e] %s", (x + 65), core.objects.object_names[core.inventory.inven[x].id].c_str());
                    
                }
                else
                {
                    //n=sprintf(str, "%c.) %s",(x+65),objects.object_names[player.inventory[x].id].c_str());

                    n = sprintf(str, "%c.) %s", (x + 65), core.objects.object_names[core.inventory.inven[x].id].c_str());
                    //printf("%d\n", player.inventory[x].id);
                    //core.disp.Disp_Text_Wrapped(str, FONT_2, { 0,128,128 }, inventory_base_x, inventory_base_y + (20 * x));

                }

                core.disp.Disp_Text_Wrapped(str, FONT_2, { 0,128,128 }, inventory_base_x, inventory_base_y + (20 * x));
                //add checkj of item length to make sure they fit inthe item display

            }
            else
            {
                if (core.inventory.inven[x].is_equipped)
                {

                    n = sprintf(str, "%c.) [e] %s", (x + 65), core.objects.object_names[core.inventory.inven[x].id].c_str());
                    

                }
                else
                {
                    //n=sprintf(str, "%c.) %s",(x+65),objects.object_names[player.inventory[x].id].c_str());

                    n = sprintf(str, "%c.) %s", (x + 65), core.objects.object_names[core.inventory.inven[x].id].c_str());
                    //printf("%d\n", player.inventory[x].id);
                    //core.disp.Disp_Text_Wrapped(str, FONT_2, { 0,128,128 }, inventory_base_x + 300, inventory_base_y + (20 * (x - 10)));

                }
                core.disp.Disp_Text_Wrapped(str, FONT_2, { 0,128,128 }, inventory_base_x + 300, inventory_base_y + (20 * (x - 10)));

            }
        }
    }
    
}
//
//bool UI_Display::Add_ui_message(std::string new_message, SDL_Color color, int id)
bool UI_Display::Add_ui_message(std::string new_message, SDL_Color color)
{
    ///messagelist.push_back(new_message);
   //printf("got message %s\n", new_message.c_str());
    messagelist.insert(messagelist.begin(), new_message);

    for (int i = (UI_MESSAGE_SIZE_LIST - 1); i > 0; i--)
    {
        
        message_color[i] = message_color[i-1];
        messages_ttl[i] = messages_ttl[i - 1];
        //message_id_list[i]= message_id_list[i-1];
       // message_keepalive[i]= message_keepalive[i-1];
        //printf("message_color at %d = %d,%d,%d\n",(i + 1), message_color[i + 1].r, message_color[i + 1].b, message_color[i + 1].g);
    }
    color.a = 255;
    message_color[0] = color;
    messages_ttl[0] = MESSAGE_TTL;
   // message_keepalive[0] = false;
   // message_id_list[0] = id;
    //printf("message_color at 0 = %d,%d,%d\n", color.r, color.b, color.g);

    //printf("got message %s\n", new_message.c_str());
    if (messagelist.size() > UI_MESSAGE_SIZE_LIST)
    {
        messagelist.pop_back();

    }
   // printf("got message %s\n", new_message.c_str());

    return true;
    
}


//bool UI_Display::Add_ui_message_long(std::string new_message, SDL_Color color, int max_size)
int UI_Display::Add_ui_message_long(std::string new_message, SDL_Color color, int max_size)
{
    int len,start_sub,end_sub;
    int num_lines=0;
    //int max_size = 21;
    int temp_size;
    char check_char='a';
    start_sub = 0;

    
    std::string sub;
    len = new_message.length();
    /************************
    determine way to cleany break not in the middle of words
    
    
    ***********************/
    //id = Get_Next_Message_Id();
    while (start_sub < len)
    {
        temp_size = max_size;
        end_sub = start_sub + temp_size;
        if ((start_sub + max_size) < len)
        {
            while (new_message.at(end_sub) != ' ')
            {
                temp_size--;
                end_sub = start_sub + temp_size;
            }
        }

        sub = new_message.substr(start_sub, temp_size);
        Add_ui_message(sub, color );
        start_sub = end_sub+1;
        num_lines++;
    }

    //return true;message_id++;
    return num_lines;
}


//bool UI_Display::Add_ui_message_printf(SDL_Color color, int max_size, const char* fmt, ...)
int UI_Display::Add_ui_message_printf(SDL_Color color, int max_size, const char* fmt, ...)
    {
        char buf[200];
        int num_lines;
        std::string s;
        //printf("     \t%s\n", fmt);
        va_list args;
        va_start(args, fmt);
        vsprintf(buf, fmt, args);
        va_end(args);
        s.append(buf);
        //printf("%s\n");
        num_lines= Add_ui_message_long(s, color, max_size);

        //return true;
        //message_id++;
        return num_lines;
    }


//void UI_Display::Set_Keep_Alive(int id)
//{
//    for (int i = 0; i < UI_MESSAGE_SIZE_LIST; i++)
//    {
//        if (message_id_list[i] == id)
//        {
//            message_keepalive[i] = true;
//        }
//    }
//}
//void UI_Display::Clear_Keep_Alive(int id)
//{
//    for (int i = 0; i < UI_MESSAGE_SIZE_LIST; i++)
//    {
//        if (message_id_list[i] == id)
//        {
//            message_keepalive[i] = false;
//        }
//    }
//}


void UI_Display::display_shop(Core_Engine& core)
{
    if (core.shop.entering_shop)
    {
        display_shop_dnd(core);
        //core.disp.Disp_Text("shop", FONT_1, { 55,55,128,255 }, 600, 400);
    }
    else if(core.shop.entering_trading_post)
    {
        display_shop_trading(core);
       // core.disp.Disp_Text("post", FONT_1, { 128,55,55,255 }, 600, 400);
    }
    else
    {
        display_shop_bank(core);
       // core.disp.Disp_Text("bank", FONT_1, { 128,128,128,255 }, 600, 400);
    }

}

void UI_Display::display_shop_dnd(Core_Engine& core)
{
    int n = 0;
    char str[1000];
    int index = 0;
    int flip = 0;
    int line = 0;
    n = sprintf(str, "Welcome to the Larn Thrift Shoppe. We stock many items explorers find useful in their adventures.Feel free to browse to your hearts content. Also be advised, if you break em, you pay for 'em.");
    core.disp.Disp_Text_Wrapped(str, FONT_3, { 125,128,255 }, 10, 10, 1300);
    //n = sprintf(str, "a) %s - %d", core.objects.object_names[core.game_data.ITEM_OFFSET].c_str(), core.inventory.item_list[core.game_data.ITEM_OFFSET].gold_value);
    //core.disp.Disp_Text_Wrapped(str, FONT_2, { 255,128,255 }, 10, 80, 700);
    //if (core.shop.shop_page == 0)
    //{
    for (int i = 0; i < core.shop.max_items_per_page; i++)
    {
        //printf("here %d %d %d %d\n", core.shop.shop_page, core.shop.shop_items[i][core.shop.shop_page].purchased, core.shop.shop_items[i][core.shop.shop_page].item_id, i);
        if (core.shop.shop_items[i][core.shop.shop_page].purchased == false && core.shop.shop_items[i][core.shop.shop_page].item_id >= 0)
        {
            if (flip == 0)
            {
                n = sprintf(str, "%c) %s", 97 + i, core.objects.object_names[core.shop.shop_items[i][core.shop.shop_page].item_id].c_str());
                core.disp.Disp_Text_Wrapped(str, FONT_3, { 255,128,255 }, 10, 100 + (line * 25), 700);
                n = sprintf(str, "%d", core.shop.shop_items[i][core.shop.shop_page].item_cost);
                core.disp.Disp_Text_Wrapped(str, FONT_3, { 255,128,255 }, 570, 100 + (line * 25), 700);
            }
            else
            {
                n = sprintf(str, "%c) %s", 97 + i, core.objects.object_names[core.shop.shop_items[i][core.shop.shop_page].item_id].c_str());
                core.disp.Disp_Text_Wrapped(str, FONT_3, { 255,128,255 }, 670, 100 + (line * 25), 700);
                n = sprintf(str, "%d", core.shop.shop_items[i][core.shop.shop_page].item_cost);
                core.disp.Disp_Text_Wrapped(str, FONT_3, { 255,128,255 }, 1230, 100 + (line * 25), 700);
            }

        }
        flip++;
        if (flip > 1)
        {
            flip = 0;
            line++;
        }
    }

    //}



    n = sprintf(str, "Enter letter to buy item!");
    core.disp.Disp_Text_Wrapped(str, FONT_3, { 255,128,255 }, 10, 450, 700);
    n = sprintf(str, "Hit Space for Next Page or Hit TAB to exit!");
    core.disp.Disp_Text_Wrapped(str, FONT_3, { 255,128,255 }, 10, 485, 800);

    display_message_list(core);
    Display_Inventory(core, 725, 525);

    n = sprintf(str, "Name:%s", core.player.stats.name);
    core.disp.Disp_Text_Wrapped(str, FONT_3, { 0,128,128 }, 10, 520);
    n = sprintf(str, "GOLD:%d", core.player.stats.gold);
    core.disp.Disp_Text_Wrapped(str, FONT_3, { 0,128,128 }, 300, 520);


}

void UI_Display::display_shop_trading(Core_Engine& core)
{
    int n = 0;
    //char str[1000];
    //int index = 0;
    int flip = 0;
    int line = 0;
    n = sprintf(str, "Welcome to the Larn trading post, we buy your stuff!");
    core.disp.Disp_Text_Wrapped(str, FONT_3, { 125,128,255 }, 10, 10, 1300);

    for (int x = 0; x < core.inventory.inven_size; x++)
    {
        if (core.inventory.inven[x].id != 0)
        {
            if (flip == 0)
            {
                n = sprintf(str, "%c.) %s", (x + 65), core.objects.object_names[core.inventory.inven[x].id].c_str());
                core.disp.Disp_Text_Wrapped(str, FONT_2, { 0,128,128 }, 10, 100 + (line * 25), 700);
            }
            else
            {
                n = sprintf(str, "%c.) %s", (x + 65), core.objects.object_names[core.inventory.inven[x].id].c_str());
                core.disp.Disp_Text_Wrapped(str, FONT_2, { 0,128,128 }, 670, 100 + (line * 25), 700);
            }

            flip++;
            if (flip > 1)
            {
                flip = 0;
                line++;
            }
        }
    }

    n = sprintf(str, "Enter letter to buy item!");
    core.disp.Disp_Text_Wrapped(str, FONT_3, { 255,128,255 }, 10, 450, 700);
    n = sprintf(str, "Hit Space for Next Page or Hit TAB to exit!");
    core.disp.Disp_Text_Wrapped(str, FONT_3, { 255,128,255 }, 10, 485, 800);

    display_message_list(core);
    Display_Inventory(core, 725, 525);

    n = sprintf(str, "Name:%s", core.player.stats.name);
    core.disp.Disp_Text_Wrapped(str, FONT_3, { 0,128,128 }, 10, 520);
    n = sprintf(str, "GOLD:%d", core.player.stats.gold);
    core.disp.Disp_Text_Wrapped(str, FONT_3, { 0,128,128 }, 300, 520);


}



void UI_Display::display_shop_bank(Core_Engine& core)
{
    //int n = 0;
    //char str[1000];
    //int index = 0;
    //int flip = 0;
    //int line = 0;
    n = sprintf(str, "Welcome to the Larn Bank, we buy your stuff!");
    core.disp.Disp_Text_Wrapped(str, FONT_3, { 125,128,255 }, 10, 10, 1300);
    ////n = sprintf(str, "a) %s - %d", core.objects.object_names[core.game_data.ITEM_OFFSET].c_str(), core.inventory.item_list[core.game_data.ITEM_OFFSET].gold_value);
    ////core.disp.Disp_Text_Wrapped(str, FONT_2, { 255,128,255 }, 10, 80, 700);
    ////if (core.shop.shop_page == 0)
    ////{
    //for (int i = 0; i < core.shop.max_items_per_page; i++)
    //{
    //    //printf("here %d %d %d %d\n", core.shop.shop_page, core.shop.shop_items[i][core.shop.shop_page].purchased, core.shop.shop_items[i][core.shop.shop_page].item_id, i);
    //    if (core.shop.shop_items[i][core.shop.shop_page].purchased == false && core.shop.shop_items[i][core.shop.shop_page].item_id >= 0)
    //    {
    //        if (flip == 0)
    //        {
    //            n = sprintf(str, "%c) %s", 97 + i, core.objects.object_names[core.shop.shop_items[i][core.shop.shop_page].item_id].c_str());
    //            core.disp.Disp_Text_Wrapped(str, FONT_3, { 255,128,255 }, 10, 100 + (line * 25), 700);
    //            n = sprintf(str, "%d", core.shop.shop_items[i][core.shop.shop_page].item_cost);
    //            core.disp.Disp_Text_Wrapped(str, FONT_3, { 255,128,255 }, 570, 100 + (line * 25), 700);
    //        }
    //        else
    //        {
    //            n = sprintf(str, "%c) %s", 97 + i, core.objects.object_names[core.shop.shop_items[i][core.shop.shop_page].item_id].c_str());
    //            core.disp.Disp_Text_Wrapped(str, FONT_3, { 255,128,255 }, 670, 100 + (line * 25), 700);
    //            n = sprintf(str, "%d", core.shop.shop_items[i][core.shop.shop_page].item_cost);
    //            core.disp.Disp_Text_Wrapped(str, FONT_3, { 255,128,255 }, 1230, 100 + (line * 25), 700);
    //        }

    //    }
    //    flip++;
    //    if (flip > 1)
    //    {
    //        flip = 0;
    //        line++;
    //    }
    //}

    ////}



    //n = sprintf(str, "Enter letter to buy item!");
    //core.disp.Disp_Text_Wrapped(str, FONT_3, { 255,128,255 }, 10, 450, 700);
    //n = sprintf(str, "Hit Space for Next Page or Hit TAB to exit!");
    //core.disp.Disp_Text_Wrapped(str, FONT_3, { 255,128,255 }, 10, 485, 800);

    //display_message_list(core);
    //Display_Inventory(core, 725, 525);

    //n = sprintf(str, "Name:%s", core.player.stats.name);
    //core.disp.Disp_Text_Wrapped(str, FONT_3, { 0,128,128 }, 10, 520);
    //n = sprintf(str, "GOLD:%d", core.player.stats.gold);
    //core.disp.Disp_Text_Wrapped(str, FONT_3, { 0,128,128 }, 300, 520);


}



void UI_Display::reset_ttl(int num_messages)
{
    for (int i = 0; i < num_messages; i++)
    {
        messages_ttl[i] = MESSAGE_TTL;
    }
}



UI_Display::~UI_Display()
{

   // fclose(output_check);
    return;

}



