#ifndef INVENTORY_H
#define INVENTORY_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "constants.h"


class Core_Engine;



class Inventory
{
private:


public:
    //add this, move it from the player file
    //Items item_list[num_items];
    Item blank_item;
    Item inven[Inventory_max_size];
    //std::vector<Item> item_list;
    Item item_list[Max_number_items];
    int inven_size;
    int inven_next_item;
    int num_items_in_inventory;


    bool dropped;


   Inventory();
    ~Inventory();

   bool add_item_to_inventory(Item item);
   bool remove_item_from_inventory(Core_Engine& core,int id, int open[]);
   bool equip_item(int id);
   bool is_empty();


};
#endif
