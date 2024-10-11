#include "core_engine.h"


Core_Engine::Core_Engine() {

    game_saved = false;
    difficultity_level = 0;

}


bool Core_Engine::Init()
{
    printf("Core init start\n");
    
    

    
    if (difficultity_level == 0) {
        //inventory.add_item_to_inventory(inventory.item_list[36]);
        //inventory.add_item_to_inventory(inventory.item_list[49]);

    }
    printf("Core init complete\n");
    return true;
}


