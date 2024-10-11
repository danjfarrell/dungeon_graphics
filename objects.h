#ifndef OBJECTS_H
#define OBJECTS_H

#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"

class Core_Engine;

class Objects
{
private:
    
public:

    Objects();

    //int add_object(unsigned char symbol,int x, int y, Text_Colors color, int ob_type,int osub_type);
    
    std::vector<char> object_character;
    std::vector<std::string> object_names;
    std::vector<SDL_Color> object_color;
    std::vector<int> object_font;

    //std::vector<Object> object_data_list;
    //std::vector<Object> object_list;



};
#endif
