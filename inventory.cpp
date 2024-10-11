#include "inventory.h"

#include "core_engine.h"


Inventory::Inventory()
{
    inven_size = 15;
    inven_next_item = 0;
   
    num_items_in_inventory = 0;

    dropped = false;


    blank_item.id = 0;
    blank_item.is_equipped = false;


    for (int i = 0; i < Inventory_max_size; i++)
    {
        inven[i] = blank_item;
    }
    for (int i = 0; i < Max_number_items; i++)
    {
        item_list[i] = blank_item;
    }

    int item_values[20];
    for (int i = 0; i < 20; i++)
    {
        item_values[i] = 0;

    }
    char str4[500];
    char str2[200];
    char str3[50] = "";
    int count = 0;
    int pos = 0;
    int n;
    char* token;
    Item  temp_item;
    FILE* resource_file_2;
    n = sprintf(str2, "gamedata/resources/inventory_data.txt");
    resource_file_2 = fopen(str2, "r");
    printf("\nInventory item build: \n");
    if (resource_file_2 == NULL) {
        printf("\nFailed: \n");
        //return 1;
    }
    fgets(str4, sizeof(str4), resource_file_2);
    printf("%s\n", str4);
    while (fgets(str3, sizeof(str3), resource_file_2))
    {
        count = 0;
        //pos = 0;
        token = strtok(str3, " ");
        while (token != NULL)
        {
            if (strcmp(token, "T") == 0)
            {
                item_values[count] = 1;
            }
            else if (strcmp(token, "F") == 0)
            {
                item_values[count] = 0;
            }
            else
            {
                item_values[count] = atoi(token);
            }
            printf("|%d %s %d|", count, token, item_values[count]);
            count++;
            token = strtok(NULL, " ");
        }
       // printf(" count=%d\n", count);
        temp_item.id = item_values[0];
        temp_item.magic_prefix = item_values[1];
        if (item_values[2] == 1)
        {
            temp_item.is_weapon = true;
        }
        else
        {
            temp_item.is_weapon = false;
        }
        if (item_values[3] == 1)
        {
            temp_item.is_armor = true;
        }
        else
        {
            temp_item.is_armor = false;
        }
        if (item_values[4] == 1)
        {
            temp_item.is_shield = true;
        }
        else
        {
            temp_item.is_shield = false;
        }
        if (item_values[5] == 1)
        {
            temp_item.is_2h = true;
        }
        else
        {
            temp_item.is_2h = false;
        }
        if (item_values[6] == 1)
        {
            temp_item.is_unique = true;
        }
        else
        {
            temp_item.is_unique = false;
        }
        if (item_values[7] == 1)
        {
            temp_item.is_ring = true;
        }
        else
        {
            temp_item.is_ring = false;
        }
        if (item_values[8] == 1)
        {
            temp_item.is_necklace = true;
        }
        else
        {
            temp_item.is_necklace = false;
        }
        if (item_values[9] == 1)
        {
            temp_item.is_gem = true;
        }
        else
        {
            temp_item.is_gem = false;
        }
        if (item_values[10] == 1)
        {
            temp_item.is_consumable = true;
        }
        else
        {
            temp_item.is_consumable = false;
        }
        temp_item.is_equipped = false;
        temp_item.damage = item_values[11];
        temp_item.armor = item_values[12];
        temp_item.bonus = item_values[13];
        temp_item.hp_bonus = item_values[14];
        temp_item.mp_bonus = item_values[15];
        temp_item.str_bonus = item_values[16];
        temp_item.dex_bonus = item_values[17];
        temp_item.int_bonus = item_values[18];
        temp_item.gold_value = item_values[19];
        item_list[pos] = temp_item;
        //item_list.push_back(temp_item);
        pos++;
        //printf("\npos =%d\n", pos);
    }

    fclose(resource_file_2);

    


    printf("\nInventory item build done: num items =%d\n",pos);

    
}
    
 

Inventory::~Inventory()
{
    
}

bool Inventory::add_item_to_inventory(Item item)
{
    if (inven_next_item < Inventory_max_size)
    {
        
        
        
        printf("add item to inventory id=%d\n",item.id);
       
        inven[inven_next_item] = item;
        inven_next_item++;
        num_items_in_inventory ++;
        return true;
    }
    else
    {
        return false;
    }
    return false;
}

bool Inventory::remove_item_from_inventory(Core_Engine& core,int id,int open[])
{
    
    if (inven[id].is_equipped)
    {
        inven[id].is_equipped = false;
    }
    //printf("id=%d y=%d x=%d, open[0]=%d,open[1]=%d, \n",inven[id].id, core.player.y, core.player.x,open[0],open[1]);

    //core.game_data.dungeon_level[core.player.y][core.player.x].object_index = inven[id].id;
    //core.game_data.dungeon_level[core.player.y][core.player.x].object = true;
    core.game_data.dungeon_level[open[1]][open[0]].object_index = inven[id].id;
    core.game_data.dungeon_level[open[1]][open[0]].object = true;
    for (int i = 1; i < Inventory_max_size; i++)
    {
        inven[i - 1] = inven[i];
    }
    inven[Inventory_max_size - 1] = blank_item;
    inven_next_item--;
    dropped = true;
    return true;
    

}

bool Inventory::is_empty()
{
    if (num_items_in_inventory > 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}