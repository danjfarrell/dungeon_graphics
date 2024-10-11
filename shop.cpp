#include "shop.h"

#include "core_engine.h"


Shop::Shop()
{
    max_items_per_page = 26;
    entering_shop = false;
    entering_trading_post=false;
    entering_bank = false;
    
    for (int i = 0; i < 80; i++)
    {
        shop_items[i][0].purchased = false;
        shop_items[i][0].item_id = -1;
        shop_items[i][0].item_cost = -1;
        shop_items[i][1].purchased = false;
        shop_items[i][1].item_id = -1;
        shop_items[i][1].item_cost = -1;
        shop_items[i][2].purchased = false;
        shop_items[i][2].item_id = -1;
        shop_items[i][2].item_cost = -1;
    }
    char str2[200];
    int n,item_index_1,item_index_2,item_index_3;
    n = sprintf(str2, "gamedata/resources/shop_items.txt");
    FILE* resource_file = fopen(str2, "r");
    const unsigned MAX_LENGTH = 256;
    char buffer[MAX_LENGTH];
    const char split[2] = ",";
    char* token;
    char id[20], cost[20],page[20];
    int page_num;
    item_index_1 = 0;
    item_index_2 = 0;
    item_index_3 = 0;
    while (fgets(buffer, MAX_LENGTH, resource_file))
    {
        token = strtok(buffer, split);
        strcpy(id ,token);
        strcpy(cost, strtok(NULL, split));
        strcpy(page, strtok(NULL, split));
        page_num = std::stoi(page);
        if (page_num == 0)
        {
            shop_items[item_index_1][page_num].item_id = std::stoi(token);
            shop_items[item_index_1][page_num].item_cost = std::stoi(cost);
            item_index_1++;
            printf("item %d %s %s %d\n", item_index_1, token, cost, page_num);
        }else if (page_num == 1)
        {
            shop_items[item_index_2][page_num].item_id = std::stoi(token);
            shop_items[item_index_2][page_num].item_cost = std::stoi(cost);
            item_index_2++;
            printf("item %d %s %s %d\n", item_index_2, token, cost, page_num);
        }
        else if (page_num == 2)
        {
            shop_items[item_index_3][page_num].item_id = std::stoi(token);
            shop_items[item_index_3][page_num].item_cost = std::stoi(cost);
            item_index_3++;
            printf("item %d %s %s %d\n", item_index_3, token, cost, page_num);
        }
        else
        {
            printf("****error****\nbad page index\n");
        }
        
        //item_index++;
       
        //printf("items %d %s %s\n", item_index, id, cost);
    }
    fclose(resource_file);
    
    shop_page = 0;
    num_shop_items = item_index_1+item_index_2+item_index_3;
    printf("num_shop_items = %d\n", num_shop_items);
}
    
 

Shop::~Shop()
{
    
}

bool Shop::shop_main(Core_Engine& core)
{
    if (entering_shop)
    {
        dnd_store(core);
        
    }
    else if(entering_trading_post)
    {
        trading_post(core);
    }
    else
    {
        bank(core);
    }


    return true;
}


bool Shop::trading_post(Core_Engine& core)
{
    char buy_char;
    if (core.input.KEY_TAB == 1 && core.input.KEY_TAB_up == true)
    {
        core.input.KEY_PAGEUP_up = false;
        Play_State temp_state;
        temp_state = core.previous;
        core.play_state = core.previous;
        core.previous = temp_state;

    }
    else if (core.input.KEY_PAGEUP == -1)
    {
        core.input.KEY_PAGEUP_up = true;
    }
    if (core.input.KEY_SPACE == 1)
    {
        shop_page += 1;
        if (shop_page > 2)
        {
            shop_page = 0;
        }
    }
    //if (core.input.KEY_SPACE == 1 && core.input.KEY_SPACE_up == true)
    //{
    //    core.input.KEY_SPACE = false;
    //    shop_page += 1;
    //    if (shop_page > 2)
    //    {
    //        shop_page = 0;
    //    }
    //}
    //else if (core.input.KEY_SPACE == -1)
    //{
    //    core.input.KEY_SPACE_up = true;
    //}

    if (core.input.any_keys_down() && entering_shop == false)
    {
        /**********************
        core.input.set_all_keys_down(); makes sure that the core.input key isnt read a second time.
        ************************/
        char str[100];
        int n, item_index;
        core.input.set_all_keys_down();
        buy_char = core.input.key_value;

        item_index = buy_char - 97;

        if ((shop_items[item_index][shop_page].item_cost < core.player.stats.gold) && (shop_items[item_index][shop_page].purchased == false))
        {

            if (!core.inventory.add_item_to_inventory(core.inventory.item_list[shop_items[item_index][shop_page].item_id]))
            {
                n = sprintf(str, "Your inventory is to full can not carry anymore!\n");
                core.ui_display.Add_ui_message(str, { 255,0,255 });
            }
            else
            {
                core.player.stats.gold -= shop_items[item_index][shop_page].item_cost;
                shop_items[item_index][shop_page].purchased = true;
            }
        }
        else if ((shop_items[item_index][shop_page].item_cost < core.player.stats.gold))
        {
            n = sprintf(str, "that costs more gold than you have!\n");
            core.ui_display.Add_ui_message(str, { 255,0,255 });
        }
    }
    else if (core.input.all_keys_up())
    {
        //printf("here12345\n");
        core.input.set_all_keys_up();
        entering_shop = false;

    }


    return true;
}


bool Shop::bank(Core_Engine& core)
{
    char buy_char;
    if (core.input.KEY_TAB == 1 && core.input.KEY_TAB_up == true)
    {
        core.input.KEY_PAGEUP_up = false;
        Play_State temp_state;
        temp_state = core.previous;
        core.play_state = core.previous;
        core.previous = temp_state;

    }
    else if (core.input.KEY_PAGEUP == -1)
    {
        core.input.KEY_PAGEUP_up = true;
    }

    if (core.input.KEY_SPACE == 1 && core.input.KEY_SPACE_up == true)
    {
        core.input.KEY_SPACE = false;
        shop_page += 1;
        if (shop_page > 2)
        {
            shop_page = 0;
        }
    }
    else if (core.input.KEY_SPACE == -1)
    {
        core.input.KEY_SPACE_up = true;
    }

    if (core.input.any_keys_down() && entering_shop == false)
    {
        /**********************
        core.input.set_all_keys_down(); makes sure that the core.input key isnt read a second time.
        ************************/
        char str[100];
        int n, item_index;
        core.input.set_all_keys_down();
        buy_char = core.input.key_value;

        item_index = buy_char - 97;

        if ((shop_items[item_index][shop_page].item_cost < core.player.stats.gold) && (shop_items[item_index][shop_page].purchased == false))
        {

            if (!core.inventory.add_item_to_inventory(core.inventory.item_list[shop_items[item_index][shop_page].item_id]))
            {
                n = sprintf(str, "Your inventory is to full can not carry anymore!\n");
                core.ui_display.Add_ui_message(str, { 255,0,255 });
            }
            else
            {
                core.player.stats.gold -= shop_items[item_index][shop_page].item_cost;
                shop_items[item_index][shop_page].purchased = true;
            }
        }
        else if ((shop_items[item_index][shop_page].item_cost < core.player.stats.gold))
        {
            n = sprintf(str, "that costs more gold than you have!\n");
            core.ui_display.Add_ui_message(str, { 255,0,255 });
        }
    }
    else if (core.input.all_keys_up())
    {
        //printf("here12345\n");
        core.input.set_all_keys_up();
        entering_shop = false;

    }


    return true;
}

bool Shop::dnd_store(Core_Engine& core)
{
    char buy_char;
    if (core.input.KEY_TAB == 1 && core.input.KEY_TAB_up == true)
    {
        core.input.KEY_PAGEUP_up = false;
        Play_State temp_state;
        temp_state = core.previous;
        core.play_state = core.previous;
        core.previous = temp_state;
        entering_shop = false;
    }
    else if (core.input.KEY_TAB == -1)
    {
        core.input.KEY_TAB_up = true;
    }
    if (core.input.KEY_SPACE == 1)
    {
        shop_page += 1;
        if (shop_page > 2)
        {
            shop_page = 0;
        }
    }




    //if (core.input.KEY_SPACE == 1 && core.input.KEY_SPACE_up == true)
    //{
    //    core.input.KEY_SPACE = false;
    //    shop_page += 1;
    //    if (shop_page > 2)
    //    {
    //        shop_page = 0;
    //    }
    //}
    //else if (core.input.KEY_SPACE == -1)
    //{
    //    core.input.KEY_SPACE_up = true;
    //}

   // if (core.input.any_keys_down() && entering_shop == false)
    if (core.input.any_keys_down() )
    {
        /**********************
        core.input.set_all_keys_down(); makes sure that the core.input key isnt read a second time.
        ************************/
        char str[100];
        int n, item_index;
        //core.input.set_all_keys_down();
        buy_char = core.input.key_value;

        item_index = buy_char - 97;

        if ((shop_items[item_index][shop_page].item_cost < core.player.stats.gold) && (shop_items[item_index][shop_page].purchased == false))
        {

            if (!core.inventory.add_item_to_inventory(core.inventory.item_list[shop_items[item_index][shop_page].item_id]))
            {
                n = sprintf(str, "Your inventory is to full can not carry anymore!\n");
                core.ui_display.Add_ui_message(str, { 255,0,255 });
            }
            else
            {
                core.player.stats.gold -= shop_items[item_index][shop_page].item_cost;
                shop_items[item_index][shop_page].purchased = true;
            }
        }
        else if ((shop_items[item_index][shop_page].item_cost < core.player.stats.gold))
        {
            n = sprintf(str, "that costs more gold than you have!\n");
            core.ui_display.Add_ui_message(str, { 255,0,255 });
        }
    }
    else if (core.input.all_keys_up())
    {
        //printf("here12345\n");
        core.input.set_all_keys_up();
       // entering_shop = false;

    }


    return true;
}