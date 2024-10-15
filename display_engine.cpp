#include "display_engine.h"



Display_Engine::Display_Engine()
{
    errno_t err;
    
    err= fopen_s(&color_font_check,"font_color_check.txt", "w");
    
    if (err == 0)
    {
        printf("The file 'crt_fopen_s.c' was opened\n");
    }
    else
    {
        printf("The file 'crt_fopen_s.c' was not opened\n");
    }
}

Display_Engine::~Display_Engine()
{
    fclose(color_font_check); 
   

}



bool Display_Engine::Init()
{

    printf("starting display engine\n");

    win = SDL_CreateWindow("Crawl Graphics", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1366, 768, SDL_WINDOW_SHOWN);
    
    
    if (win == NULL)
    {
             return false;
    }



	 ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

     if (ren == NULL)
     {

              return false;
     }

    Set_Background_Color(0x00,0x00,0x00,0xFF);

     if( TTF_Init() == -1 )
     {

          return false;
     }
     int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
     if ((IMG_Init(imgFlags) & imgFlags) != imgFlags) {
         std::cerr << "Failed to initialize SDL2_image for all formats: " << IMG_GetError() << std::endl;
         
         return false;
     }


     //call function to create the fonts and colors needed
     /*
     if (!Build_Fonts_and_Colors())
     {
         return false;
     }
  
     
     if (!Build_bmp_font("gamedata/resources/graphics/Redjack17.bmp"))
     {
         return false;
     }
     if (!Build_bmp_fonts())
     {
         return false;
     }
     */
    return true;
}

void Display_Engine::Cleanup_Display()
{

    
    printf("cleanup 1\n");
    //Quit SDL_ttf
    TTF_Quit();
    printf("cleanup 2\n");
    //Clean up the Textures used
    /*
    if (textures.size() > 0)
    {
        for (int i = 0; i < (int)textures.size(); i++)
        {
            SDL_DestroyTexture(textures[i]);
        }
    }*/
    
    printf("cleanup 3\n");
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    printf("cleanup 4\n");
    return;
}


void Display_Engine::Set_Background_Color(int r, int g, int b, int a)
{
    SDL_SetRenderDrawColor(ren, r, g, b, a);
    return;
}



int Display_Engine::Load_Texture(std::string filename, std::vector<SDL_Texture*>& textures, std::vector<SDL_Rect>& texture_size)
{
    SDL_Rect pos;
    SDL_Texture* tex = NULL;
    pos.x = 1;
    pos.y = 0;

    SDL_Surface* surf = IMG_Load(filename.c_str());
    if (!surf)
    {
        printf("IMG_Load: %s\n", IMG_GetError());
        return -1;
        // handle error
    }
    else
    {
        SDL_SetColorKey(surf, SDL_TRUE, SDL_MapRGB(surf->format, r_trans, g_trans, b_trans));

        tex = SDL_CreateTextureFromSurface(ren, surf);


        textures.push_back(tex);
        SDL_QueryTexture(textures[textures.size() - 1], NULL, NULL, &pos.w, &pos.h);
        //pos.w=surf->w;
        //pos.h=surf->h;
        texture_size.push_back(pos);

        //SDL_FreeSurface(surf);
        //SDL_DestroyTexture(tex);
        tex = NULL;
        printf("returning texture id=%d\n", textures.size() - 1);
        return textures.size() - 1;
    }
    return -1;
}


void Display_Engine::Set_Texture_Alpha(int texture_id, int alpha)
{
    //Display engines texture vector not yet unlocked
    //SDL_SetTextureAlphaMod(textures[texture_id], alpha);
    return;

}


void Display_Engine::Set_Texture_Alpha(int texture_id, std::vector<SDL_Texture*>& textures, int alpha)
{



    //SDL_RenderCopy(ren,textures[texture_id],NULL,NULL);

    SDL_SetTextureAlphaMod(textures[texture_id], alpha);
    return;

}

void Display_Engine::Apply_Texture(int texture_id, SDL_Rect size_pos, std::vector<SDL_Texture*>& textures)
{

    SDL_RenderCopy(ren, textures[texture_id], NULL, &size_pos);

    return;
}

void Display_Engine::Apply_Texture(int texture_id, std::vector<SDL_Rect>& size_pos, std::vector<SDL_Texture*>& textures)
{

    SDL_RenderCopy(ren, textures[texture_id], NULL, &size_pos[texture_id]);

    return;
}

void Display_Engine::Apply_clipped_texture(SDL_Texture* texture, SDL_Rect *size_pos, SDL_Rect *subsection)
{
    SDL_RenderCopy(ren, texture, subsection, size_pos);

    return;

}






