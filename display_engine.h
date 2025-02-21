#ifndef DISPLAY_ENGINE_H
#define DISPLAY_ENGINE_H

//#include <stdio.h>
//#include <vector>
//#include <stdlib.h>
//#include <string.h>
////#include <windows.h>
//#include <iostream>

#include "common.h"

#include <SDL.h>
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "constants.h"

//The Display engine, handles loading images, creating surfaces, and displaying output text to the screen.
class Display_Engine
{
private:

    SDL_Window *win=NULL;

    FILE* color_font_check;
    
    
    /*
    
    //TTF_Font *font = NULL;
    

    SDL_Surface *surf_text=NULL;

    SDL_Texture *display_texture=NULL;

    SDL_Rect display_text_size;

    //char *game_title;

    std::vector<SDL_Color> textColor;


    std::vector<TTF_Font*> font;

    std::vector<SDL_Texture*> textures;

    std::vector<SDL_Rect> texture_size;

    SDL_Texture* bmp_font;
    SDL_Texture* bmp_font_2;
    SDL_Texture* bmp_font_3;
    SDL_Texture* bmp_font_4;

    std::vector< SDL_Texture*> bmp_fonts;

    bool fullscreen;
    */


public:
    Display_Engine();
    ~Display_Engine();
    

    SDL_Renderer* ren = NULL;
    
    
    //std::vector<SDL_Color> textColors;
    
    
    
    //bool windowOK;

    // Initialize the display engine
    bool Init();
    // Cleanup the display engine when the program is done
    void Cleanup_Display();
    
    //Set the background color
    void Set_Background_Color(int r, int g, int b, int a);

    // This function loads a texture onto a vector of textures, along with loading the size of the texture
    // onto a vector of SDL_Rect structures
    int Load_Texture(std::string filename, std::vector<SDL_Texture*>& textures, std::vector<SDL_Rect>& texture_size);
    
    //most basic version of load_texture, just specify a filename and it is loaded 
    int Load_Texture(std::string filename);


    //This will set the alpha modification to a texture.
    void Set_Texture_Alpha(int texture_id, int alpha);

    //set the texture alpha for a class specific texture stack
    void Set_Texture_Alpha(int texture_id, std::vector<SDL_Texture*>& textures, int alpha);

    /*Apply the full texture provied by texture_id in the textures vector to the display
    at a specified location and size from the size_pos Rect. */
    void Apply_Texture(int texture_id, SDL_Rect size_pos, std::vector<SDL_Texture*>& textures);
    
    /*Apply the full texture provied by texture_id in the textures vector to the display
    at a specified location and size from the size_pos vector of type Rect.*/
    void Apply_Texture(int texture_id, std::vector<SDL_Rect>& size_pos, std::vector<SDL_Texture*>& textures);


    //Apply a subsection of the texture)
    void Apply_clipped_texture(SDL_Texture *texture, SDL_Rect *size_pos,  SDL_Rect *subsection);


    /*
//Apply the full texture to the full screen
    void Apply_Texture(int texture_id);



//Apply the full texture to the display at a specified location and size.
    void Apply_Texture(int texture_id,SDL_Rect size_pos);
//Apply part of the texture to the display
    void Apply_Texture(int texture_id,  SDL_Rect size_pos, SDL_Rect sprite);

//Apply the texture, from the subclass specific texture list
    void Apply_Texture(int texture_id,std::vector<SDL_Texture*> &textures);

    //Apply the full texture to the display at a specified location and size.
    void Apply_Texture(int texture_id,SDL_Rect size_pos,std::vector<SDL_Texture*> &textures);

    void Apply_Texture(int texture_id, std::vector<SDL_Rect> &size_pos, std::vector<SDL_Texture*> &textures);

    void Apply_Texture_with_Alpha(int texture_id, std::vector<SDL_Rect> &size_pos, std::vector<SDL_Texture*> &textures,int alpha);

    void Apply_Texture_with_Alpha(int texture_id, const SDL_Rect size_pos, std::vector<SDL_Texture*> &textures,int alpha);

// Apply a clipped texture using texture and size vectors
    void Apply_Texture(int texture_id, int x, int y, std::vector<SDL_Texture*>& textures, SDL_Rect sprite);


//Apply bmp font textures, at a position
    void Apply_BMP_FONT_Texture(int x, int y, int value);
//Apply bmp font textures, at a position, and set a color
    void Apply_BMP_FONT_Texture(int x, int y, int value, Text_Colors color_id);
//Apply bmp font textures, at a position, and set a color and set a size
    //void Apply_BMP_FONT_Texture(int x, int y, int value, Text_Color color_id, int font_size);
    void Apply_BMP_FONT_Texture(int x, int y, int value, Text_Colors color_id, int font_size);
    void Apply_BMP_FONT_Texture(int x, int y, int value, SDL_Color color_id, int font_size);
    void Apply_BMP_FONT_Textures(int x, int y, int value, SDL_Color color_id, int font_size, int font_num);
//This will set the color modification to a texture.
    void Set_Texture_Color(int texture_id, int r, int g, int b);




    int Load_Texture(std::string filename);
    
    int Load_Texture(std::string filename, int w, int h);

    bool Load_Texture_list_from_file(std::string  filename, std::vector<SDL_Texture*> &textures,std::vector<SDL_Rect> &texture_size);

    bool Set_Text(char *display_string,Font_IDs font_id, Text_Colors color_id);
    void Apply_Text(int x, int y);

    bool Disp_Text(std::string display_string,Font_IDs font_id, Text_Colors color_id, int x, int y);

    bool Disp_Text(std::string display_string,Font_IDs font_id, SDL_Color tempColor, int x, int y);

    bool Disp_Text_Wrapped(std::string display_string,Font_IDs font_id, SDL_Color tempColor, int x, int y,int wrapped_size= SCREEN_WIDTH);

    

    bool Build_Fonts_and_Colors();

    bool Build_bmp_font(std::string filename);

    bool Build_bmp_fonts();

    void Draw_Rect(SDL_Rect rect, int r, int g, int b, bool outline);

    int Sizeof_Textures();

    */


};
#endif
