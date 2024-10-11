#ifndef SHOP_H
#define SHOP_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "constants.h"


class Core_Engine;



class Shop
{
private:


public:
    
	
   Shop();
    ~Shop();

    shop_item shop_items[80][3];
    trading_post_item trading_post_items[80];

    int shop_page;
    int num_shop_items;
    int max_items_per_page;
    bool entering_shop;
    bool entering_trading_post;
    bool entering_bank;

   bool shop_main(Core_Engine& core);
   bool dnd_store(Core_Engine& core);
   bool trading_post(Core_Engine& core);
   bool bank(Core_Engine& core);
};
#endif
