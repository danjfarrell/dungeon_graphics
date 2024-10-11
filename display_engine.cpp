#include "display_engine.h"



Display_Engine::Display_Engine()
{
    color_font_check = fopen("font_color_check.txt", "w");
    

}

Display_Engine::~Display_Engine()
{
    fclose(color_font_check); 
   

}
void Display_Engine::fullscreen_swap()
{
    //If the screen is windowed
    if (fullscreen == true)
    {
        //Set the screen to fullscreen
        //win = SDL_CreateWindow("CRAWL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1366, 768, SDL_WINDOW_FULLSCREEN);

        //If there's an error
        if (win == NULL)
        {
            windowOK = false;
            return;
        }

        //Set the window state flag
        fullscreen = false;
    }
    //If the screen is fullscreen
    else if (fullscreen == false)
    {
        //Window the screen
        //win = SDL_CreateWindow("CRAWL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1366, 768, SDL_WINDOW_SHOWN);
        //SDL_SetWindowSize(screen, dm.w, dm.h + 10);
        //SDL_SetWindowPosition(screen, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
        //If there's an error
        if (win == NULL)
        {
            windowOK = false;
            return;
        }

        //Set the window state flag
        fullscreen = true;
    }


}
bool Display_Engine::Init()
{
    //int n;
    printf("starting display engine\n");
        //win = SDL_CreateWindow("CRAWL", 50, 50, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    //win = SDL_CreateWindow("CRAWL", 50, 50, 1366, 768, SDL_WINDOW_FULLSCREEN);
    //win = SDL_CreateWindow("CRAWL", 50, 50, 1366, 768, SDL_WINDOW_FULLSCREEN);//SDL_WINDOW_BORDERLESS
    // win = SDL_CreateWindow("CRAWL", 0, 0, 1366, 768, SDL_WINDOW_MAXIMIZED);
    win = SDL_CreateWindow("CRAWL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1366, 768, SDL_WINDOW_SHOWN);
    SDL_GetDesktopDisplayMode(1,&windowed_mode);
        //win = SDL_CreateWindow("CRAWL", 50, 50, 2732, 1536, SDL_WINDOW_FULLSCREEN);
    //win = SDL_CreateWindow("CRAWL", 50, 50, 1366, 768, SDL_WINDOW_BORDERLESS);//
    fullscreen = false;
    if (win == NULL)
    {
             return false;
    }



	 ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	 //n= SDL_RenderSetScale(ren, .5,.5);
     if (ren == NULL)
     {

              return false;
     }

    Set_Background_Color(0x00,0x00,0x00,0xFF);

     if( TTF_Init() == -1 )
      {

          return false;
      }



    //call function to create the fonts and colors needed

     if (!Build_Fonts_and_Colors())
     {
         return false;
     }


    //Build_bmp_font("gamedata/resources/graphics/Anikki_square_16x16.bmp");
    //Build_bmp_font("gamedata/resources/graphics/Kai-1280x400-v2_7512b5.bmp");
    
     
     if (!Build_bmp_font("gamedata/resources/graphics/Redjack17.bmp"))
     {
         return false;
     }
     if (!Build_bmp_fonts())
     {
         return false;
     }
    return true;
}


  bool Display_Engine::Build_Fonts_and_Colors()
  {

      
      FILE* f_textcolors= fopen("gamedata\\resources\\text_colors.txt", "r");
     if(f_textcolors == NULL)
     {
         printf("failed to load text colors\n");
         fclose(f_textcolors);
         return false;
     }
    

     
     int num_colors;
     char str[200];
     SDL_Color tempColor;
     int r, g, b,a,n;
     n= fscanf(f_textcolors,"%i\n",&num_colors);
     //printf("num_colors:%i\n",num_colors);

     for(int i=0;i<num_colors;i++)
 	 {

           n= fscanf(f_textcolors,"%s\n",str);
            printf("\n%s\n",str);
    	   n= fscanf(f_textcolors,"%i %i %i %i\n",&r,&g ,&b,&a );
            tempColor.r = r;
            tempColor.g = g;
            tempColor.b = b;
            tempColor.a = a;
            textColors.push_back(tempColor);
      }
      fclose(f_textcolors);


      //FILE *ttf_out=fopen("ttf_out.txt","w");

      TTF_Font *temp_font=NULL;

  //create load from file colors
  //black
      tempColor={0,0,0};
      textColor.push_back(tempColor);
  //white
      tempColor={255,255,255};
      textColor.push_back(tempColor);
  //red
      tempColor={255,0,0};

      textColor.push_back(tempColor);
  //green
      tempColor={0,200,100};
      textColor.push_back(tempColor);
  //blue
      tempColor={0,100,200};
      textColor.push_back(tempColor);
  //gold
      tempColor={255,215,0};
      textColor.push_back(tempColor);
  //silver
      tempColor={192,192,192};
      textColor.push_back(tempColor);

      temp_font = TTF_OpenFont( "gamedata/resources/fonts/prstart.ttf", 16 );

      if (temp_font)
      {
          font.push_back(temp_font);
      }
      else
      {
          // fprintf(ttf_out,"TTF_OpenFont: %s\n", TTF_GetError());
          printf("ttf 1 load failed\n");
              return false;
      }
      //gamedata\\intro\\intro.dat
      temp_font = TTF_OpenFont( "gamedata/resources/fonts/prstart.ttf", 12 );
      if(temp_font)
      {
         font.push_back(temp_font);
      }else
      {
         // fprintf(ttf_out,"TTF_OpenFont: %s\n", TTF_GetError());
          printf("ttf 2 load failed\n");
          return false;
      }

      temp_font = TTF_OpenFont( "gamedata/resources/fonts/prstart.ttf", 18 );
      if (temp_font)
      {
          font.push_back(temp_font);
      }
      else
      {
          // fprintf(ttf_out,"TTF_OpenFont: %s\n", TTF_GetError());
          printf("ttf 3 load failed\n");
              return false;
      }

          temp_font = TTF_OpenFont( "gamedata/resources/fonts/prstart.ttf", 24 );
          if (temp_font)
          {
              font.push_back(temp_font);
          }
          else
          {
              // fprintf(ttf_out,"TTF_OpenFont: %s\n", TTF_GetError());
              printf("ttf 4 load failed\n");
                  return false;
          }

          temp_font = TTF_OpenFont( "gamedata/resources/fonts/prstart.ttf", 36 );
          if (temp_font)
          {
              font.push_back(temp_font);
          }
          else
          {
              // fprintf(ttf_out,"TTF_OpenFont: %s\n", TTF_GetError());
                    printf("ttf 5 load failed\n");
                  return false;
          }

                temp_font = TTF_OpenFont( "gamedata/resources/fonts/prstart.ttf", 8 );
                if (temp_font)
                {
                    font.push_back(temp_font);
                }
                else
                {
                    // fprintf(ttf_out,"TTF_OpenFont: %s\n", TTF_GetError());
                    printf("ttf 6 load failed\n");
                        return false;
                }
    
      //TTF_CloseFont( temp_font );

      //fclose(ttf_out);
                printf("all loaded fonts and colors\n");


      return true;
  }


  bool Display_Engine::Build_bmp_font(std::string filename)
  {
          SDL_Rect pos;
          SDL_Texture *tex=NULL;
          pos.x = 0;
          pos.y = 0;


          //strcpy(path,"gamedata/resources/graphics/Anikki_square_16x16.bmp");


      SDL_Surface* surf = IMG_Load( filename.c_str());

      if(surf==NULL)
      {
          printf( "\nUnable to load image %s!\n SDL_image Error: %s\n",filename.c_str(), IMG_GetError() );
          return false;
      }else
      {
            printf("load bmp font good \n");

            SDL_SetColorKey( surf, SDL_TRUE, SDL_MapRGB( surf->format, 255, 0, 255 ) );
            //tex=IMG_LoadTexture(ren,filename);
            bmp_font = SDL_CreateTextureFromSurface(ren, surf);


      }

      SDL_FreeSurface(surf);
     // Anikki_square_16x16.bmp
      surf = IMG_Load("gamedata/resources/graphics/Anikki_square_16x16.bmp");

      if (surf == NULL)
      {
          printf("\nUnable to load image %s!\n SDL_image Error: %s\n", filename.c_str(), IMG_GetError());
          return false;
      }
      else
      {
          printf("load bmp font good \n");

          SDL_SetColorKey(surf, SDL_TRUE, SDL_MapRGB(surf->format, 255, 0, 255));
          //tex=IMG_LoadTexture(ren,filename);
          bmp_font_2 = SDL_CreateTextureFromSurface(ren, surf);


      }

      SDL_FreeSurface(surf);

      return true;

  }

  bool Display_Engine::Build_bmp_fonts()
  {
      SDL_Rect pos;
      SDL_Texture* tex = NULL;
      pos.x = 0;
      pos.y = 0;


      //strcpy(path,"gamedata/resources/graphics/Anikki_square_16x16.bmp");


      SDL_Surface* surf = IMG_Load("gamedata/resources/graphics/Redjack17.bmp");

      if (surf == NULL)
      {
          printf("\nUnable to load image %s!\n SDL_image Error: %s\n", "gamedata/resources/graphics/Redjack17.bmp", IMG_GetError());
          return false;
      }
      else
      {
          printf("load bmp font good 1 \n");

          SDL_SetColorKey(surf, SDL_TRUE, SDL_MapRGB(surf->format, 255, 0, 255));
          //tex=IMG_LoadTexture(ren,filename);
          //bmp_font = SDL_CreateTextureFromSurface(ren, surf);
          tex = SDL_CreateTextureFromSurface(ren, surf);
          if (tex == NULL) {
              fprintf(stderr, "CreateTextureFromSurface failed: %s\n", SDL_GetError());
          }
          bmp_fonts.push_back(tex);
         int temp1 = SDL_SetTextureColorMod(bmp_fonts[0], 12, 12, 12);
          if (temp1 < 0)
          {
              //printf("wtf5");
             printf("font_num=%d, SDL_Init failed: %s\n",0, SDL_GetError());
          }
      }

      SDL_FreeSurface(surf);
      //SDL_DestroyTexture(tex);
      tex = NULL;

      // Anikki_square_16x16.bmp
      surf = IMG_Load("gamedata/resources/graphics/Anikki_square_16x16.bmp");

      if (surf == NULL)
      {
          printf("\nUnable to load image %s!\n SDL_image Error: %s\n", "gamedata/resources/graphics/Anikki_square_16x16.bmp", IMG_GetError());
          return false;
      }
      else
      {
          printf("load bmp font good 2 \n");

          SDL_SetColorKey(surf, SDL_TRUE, SDL_MapRGB(surf->format, 255, 0, 255));
          //tex=IMG_LoadTexture(ren,filename);
          //bmp_font_2 = SDL_CreateTextureFromSurface(ren, surf);
          tex = SDL_CreateTextureFromSurface(ren, surf);

          if (tex == NULL) {
              fprintf(stderr, "CreateTextureFromSurface failed: %s\n", SDL_GetError());
          }
          bmp_fonts.push_back(tex);

      }

      SDL_FreeSurface(surf);
      //SDL_DestroyTexture(tex);
      tex = NULL;

      //Build_bmp_font("gamedata/resources/graphics/Kai-1280x400-v2_7512b5.bmp");
      surf = IMG_Load("gamedata/resources/graphics/Kai-1280x400-v2_7512b5.bmp");

      if (surf == NULL)
      {
          printf("\nUnable to load image %s!\n SDL_image Error: %s\n", "gamedata/resources/graphics/Kai-1280x400-v2_7512b5.bmp", IMG_GetError());
          return false;
      }
      else
      {
          printf("load bmp font good 3 \n");

          SDL_SetColorKey(surf, SDL_TRUE, SDL_MapRGB(surf->format, 255, 0, 255));
          //tex=IMG_LoadTexture(ren,filename);
          //bmp_font_2 = SDL_CreateTextureFromSurface(ren, surf);
          tex = SDL_CreateTextureFromSurface(ren, surf);
          bmp_fonts.push_back(tex);

      }
      printf("number of tex=%d \n",bmp_fonts.size());
      //SDL_FreeSurface(surf);
      //SDL_DestroyTexture(tex);
      tex = NULL;
      return true;

  }


//int Display_Engine::Load_Texture(char *filename)
int Display_Engine::Load_Texture(std::string filename)
{
             SDL_Rect pos;
             SDL_Texture *tex=NULL;
         pos.x = 0;
         pos.y = 0;
         //pos.w=640;
          //pos.h=240;
     //surf = SDL_LoadBMP("resources/hello.bmp");
     //surf = SDL_LoadBMP(filename);
     //if (surf == NULL)
     //{
              //std::cout << SDL_GetError() << std::endl;
      //        return false;
     //}

     //tex = SDL_CreateTextureFromSurface(ren, surf);
     //textures.push_back(SDL_CreateTextureFromSurface(ren, surf));
     //printf("%i",textures.size());


     SDL_Surface* surf = IMG_Load( filename .c_str());

      if(surf==NULL)
      {
          printf( "\nUnable to load image %s!\n SDL_image Error: %s\n",filename.c_str(), IMG_GetError() );
      }else
      {
            printf("adding texture to the stack\n");

        SDL_SetColorKey( surf, SDL_TRUE, SDL_MapRGB( surf->format, r_trans, g_trans, b_trans ) );
         //tex=IMG_LoadTexture(ren,filename);
         tex = SDL_CreateTextureFromSurface(ren, surf);


         textures.push_back(tex);
         SDL_QueryTexture(textures[textures.size()-1], NULL, NULL, &pos.w, &pos.h);
         texture_size.push_back(pos);


      }





     //SDL_FreeSurface(surf);
     //SDL_DestroyTexture(tex);
     tex=NULL;
     return textures.size()-1;
 }



//int Display_Engine::Load_Texture(char *filename, std::vector<SDL_Texture*> &textures,std::vector<SDL_Rect> &texture_size)
int Display_Engine::Load_Texture(std::string filename, std::vector<SDL_Texture*>& textures, std::vector<SDL_Rect>& texture_size)
{
        SDL_Rect pos;
        SDL_Texture *tex=NULL;
        pos.x = 1;
        pos.y = 0;

     SDL_Surface* surf = IMG_Load( filename.c_str());
     if(!surf)
     {
         printf("IMG_Load: %s\n", IMG_GetError());
         return -1;
     // handle error
     }else
     {
         SDL_SetColorKey( surf, SDL_TRUE, SDL_MapRGB( surf->format, r_trans, g_trans, b_trans ) );

         tex = SDL_CreateTextureFromSurface(ren, surf);


         textures.push_back(tex);
         SDL_QueryTexture(textures[textures.size()-1], NULL, NULL, &pos.w, &pos.h);
         //pos.w=surf->w;
         //pos.h=surf->h;
         texture_size.push_back(pos);

         //SDL_FreeSurface(surf);
         //SDL_DestroyTexture(tex);
         tex=NULL;
         printf("returning texture id=%d\n", textures.size() - 1);
         return textures.size()-1;
     }
     return -1;
 }


//bool Display_Engine::Load_Texture_list_from_file(char *data_file_name, std::vector<SDL_Texture*> &textures,std::vector<SDL_Rect> &texture_size)
bool Display_Engine::Load_Texture_list_from_file(std::string data_file_name, std::vector<SDL_Texture*>& textures, std::vector<SDL_Rect>& texture_size)
{
    char filename[200];
    int num_files=0;
    FILE *resource_file = fopen(data_file_name.c_str(),"r");
    if (resource_file == NULL)
    {
        printf("failed to open load_text)list_from_file\n");
        fclose(resource_file);
        return false;
    }
    printf("\n********\nin load_texture_list_from_file\n");
    FILE *out=fopen("game_resources_check.txt","w");

    int t_w,t_h,tx,ty;
    //SDL_Rect temp_size_pos;
    //int temp_texture;
    int n;
    n=fscanf(resource_file,"%i\n",&num_files);

        SDL_Texture *tex=NULL;

        SDL_Rect pos;
        pos.x = 0;
        pos.y = 0;
        printf("loading list\n");
   ///change this to send to display and return full vector of textures
    for(int i=0;i<num_files;i++)
    {
        n=fscanf(resource_file,"%s %i %i %i %i\n",filename,&tx,&ty,&t_w,&t_h);
        //question=NONE;    //std::cout<<filename<<"\n";
        printf("%s\n",filename);

         SDL_Surface* surf = IMG_Load( filename );
         if(!surf)
         {
             printf("IMG_Load: %s\n", IMG_GetError());

             return false;
         // handle error
         }else
         {
             SDL_SetColorKey( surf, SDL_TRUE, SDL_MapRGB( surf->format, r_trans, g_trans, b_trans ) );
             tex = SDL_CreateTextureFromSurface(ren, surf);
             textures.push_back(tex);
             SDL_QueryTexture(textures[textures.size()-1], NULL, NULL, &t_w, &t_h);
             //SDL_QueryTexture(textures[textures.size()-1], NULL, NULL, &pos.w, &pos.h);
             pos.w=t_w;
             pos.h=t_h;
             texture_size.push_back(pos);


             //SDL_FreeSurface(surf);
             //SDL_DestroyTexture(tex);
             surf=NULL;
             tex=NULL;

        //temp_texture=disp.Load_Texture(filename);
        //printf("texture_id %i \n",temp_texture);


            printf("%s %i %i %i %i\n",filename,pos.x,pos.y,pos.w,pos.h);
        }
    }
    fclose(resource_file);
    fclose (out);



     return true;
 }



 //int Display_Engine::Load_Texture(char *filename, int w, int h)
 int Display_Engine::Load_Texture(std::string filename, int w, int h)
 {
              SDL_Rect pos;
             SDL_Texture *tex=NULL;
         pos.x = 0;
         pos.y = 0;
         pos.w=w;
         pos.h=h;
  //    surf = SDL_LoadBMP(filename);
  //    if (surf == NULL)
 //    {
  //             //std::cout << SDL_GetError() << std::endl;
  //             return false;
  //    }

      //tex = SDL_CreateTextureFromSurface(ren, surf);
      //textures.push_back(SDL_CreateTextureFromSurface(ren, surf));

      tex=IMG_LoadTexture(ren,filename.c_str());
      textures.push_back(tex);

      texture_size.push_back(pos);


      tex=NULL;
     // SDL_FreeSurface(surf);
     return textures.size()-1;
  }


  void Display_Engine::Apply_Texture(int texture_id)
  {
   SDL_RenderCopy(ren,textures[texture_id],NULL,NULL);
  }

  void Display_Engine::Apply_Texture(int texture_id,std::vector<SDL_Texture*> &textures)
  {
        SDL_RenderCopy(ren,textures[texture_id],NULL,NULL);
  }


  void Display_Engine::Apply_Texture(int texture_id,SDL_Rect size_pos)
  {
     //Render_Clear();
     //SDL_Rect pos;
     //pos.x=x;
     //pos.y=y;
     //pos.w=texture_size[texture_id].w;
     //pos.h=texture_size[texture_id].h;

          SDL_RenderCopy(ren,textures[texture_id],NULL,&size_pos);
      //Render_Display();
      return;
  }


  void Display_Engine::Apply_Texture(int texture_id, SDL_Rect size_pos, std::vector<SDL_Texture*> &textures)
  {

          SDL_RenderCopy(ren,textures[texture_id],NULL,&size_pos);

      return;
  }

  void Display_Engine::Apply_Texture(int texture_id, std::vector<SDL_Rect> &size_pos, std::vector<SDL_Texture*> &textures)
  {

          SDL_RenderCopy(ren,textures[texture_id],NULL,&size_pos[texture_id]);

      return;
  }

  void Display_Engine::Apply_Texture_with_Alpha(int texture_id, std::vector<SDL_Rect> &size_pos, std::vector<SDL_Texture*> &textures,int alpha)
  {

          unsigned char x;
          SDL_GetTextureAlphaMod(textures[texture_id],&x);

          SDL_SetTextureAlphaMod(textures[texture_id],alpha);
          SDL_RenderCopy(ren,textures[texture_id],NULL,&size_pos[texture_id]);
          SDL_SetTextureAlphaMod(textures[texture_id],x);

      return;
  }

  void Display_Engine::Apply_Texture_with_Alpha(int texture_id,const SDL_Rect size_pos, std::vector<SDL_Texture*> &textures,int alpha)
  {

          unsigned char x;
          SDL_GetTextureAlphaMod(textures[texture_id],&x);

          SDL_SetTextureAlphaMod(textures[texture_id],alpha);
          SDL_RenderCopy(ren,textures[texture_id],NULL,&size_pos);
          SDL_SetTextureAlphaMod(textures[texture_id],x);

      return;
  }


  //apply a texture tht is clipped;
  void Display_Engine::Apply_Texture(int texture_id, SDL_Rect size_pos, SDL_Rect sprite)
  {
         SDL_RenderCopy(ren,textures[texture_id],&sprite,&size_pos);
      return;
  }
  //apply a clipped texture using vectors for texture and texture size;
  void Display_Engine::Apply_Texture(int texture_id, int x, int y, std::vector<SDL_Texture*>& textures, SDL_Rect sprite)
  {
      //SDL_RenderCopy(ren,textures[texture_id],NULL,&size_pos[texture_id]);
      SDL_Rect size_pos;
      size_pos.h = 32;
      size_pos.w = 32;
      size_pos.x = x * 32;
      size_pos.y = y * 32;
      SDL_RenderCopy(ren, textures[texture_id], &sprite, &size_pos);
      return;
  }



  void Display_Engine::Apply_BMP_FONT_Texture(int x, int y, int value)
  {
         SDL_Rect pos;
         pos.x=x;
         pos.y=y;
         pos.w=16;
         pos.h=16;

         SDL_Rect sprite;
         sprite.x=(value%16)*16;
         sprite.y=(value/16)*16;
         sprite.w=16;
         sprite.h=16;

      SDL_RenderCopy(ren,bmp_font,&sprite,&pos);
  }

 void Display_Engine::Apply_BMP_FONT_Texture(int x, int y, int value, Text_Colors color_id)
  {
         SDL_Texture *tex=NULL;
         SDL_Rect pos;
         pos.x=x;
         pos.y=y;
         pos.w=16;
         pos.h=16;

         SDL_Rect sprite;
         sprite.x=(value%16)*16;
         sprite.y=(value/16)*16;
         sprite.w=16;
         sprite.h=16;

      //    SDL_BlitSurface(bmp_font,&sprite,surf_text,NULL);

        // tex = SDL_CreateTextureFromSurface(ren, surf_text);

  //Modulate texture
      SDL_SetTextureColorMod( bmp_font, textColors[color_id].r ,textColors[color_id].g , textColors[color_id].b );

      //SDL_SetTextureColorMod( bmp_font, 128 ,textColor[color_id].g , 0 );

      SDL_RenderCopy(ren,bmp_font,&sprite,&pos);
     //SDL_SetTextureColorMod( bmp_font, 0 ,0 , 255 );
     // tex=NULL;
     // SDL_FreeSurface(surf_text);
  }

//void Display_Engine::Apply_BMP_FONT_Texture(int x, int y, int value, Text_Color color_id, int font_size)
  void Display_Engine::Apply_BMP_FONT_Texture(int x, int y, int value, Text_Colors color_id, int font_size)
  {
         if (font_size<=0)
         {
             font_size=16;
         }

         SDL_Texture *tex=NULL;
         SDL_Rect pos;
         pos.x=x;
         pos.y=y;
         pos.w=font_size;
         pos.h=font_size;

         SDL_Rect sprite;
         sprite.x=(value%16)*16;  //use modulo to find the column of the value
         sprite.y=(value/16)*16;  // use division to find the row of the value
         sprite.w=16;
         sprite.h=16;

      SDL_SetTextureColorMod( bmp_font, textColors[color_id].r ,textColors[color_id].g , textColors[color_id].b );

      SDL_RenderCopy(ren,bmp_font,&sprite,&pos);

  }
  
  void Display_Engine::Apply_BMP_FONT_Texture(int x, int y, int value, SDL_Color color_id, int font_size)
  {
      if (font_size <= 0)
      {
          font_size = 16;
      }

      SDL_Texture* tex = NULL;
      SDL_Rect pos;
      pos.x = x;
      pos.y = y;
      pos.w = font_size;
      pos.h = font_size;

      SDL_Rect sprite;
      sprite.x = (value % 16) * 16;  //use modulo to find the column of the value
      sprite.y = (value / 16) * 16;  // use division to find the row of the value
      sprite.w = 16;
      sprite.h = 16;

      SDL_SetTextureColorMod(bmp_font, color_id.r, color_id.g, color_id.b);

      SDL_RenderCopy(ren, bmp_font, &sprite, &pos);

  }

  void Display_Engine::Apply_BMP_FONT_Textures(int x, int y, int value, SDL_Color color_id, int font_size, int font_num)
  {
      int temp1;
      //int temp2;
      
      if (font_size <= 0)
      {
          font_size = 16;
      }
      if (((unsigned int) font_num >= bmp_fonts.size())||(font_num<0))
      {
          font_num = 0;
      }
      //fprintf(color_font_check,"color.r=%d,color.d=%d,color.b=%d,font_num=%d\n", color_id.r, color_id.g, color_id.b, font_num);
      //if (bmp_fonts[font_num] == NULL)
      //{
      //    fprintf(color_font_check, "fon t null");
      //}
      SDL_Texture* tex = NULL;
      SDL_Rect pos;
      pos.x = x;
      pos.y = y;
      pos.w = font_size;
      pos.h = font_size;

      SDL_Rect sprite;
      sprite.x = (value % 16) * 16;  //use modulo to find the column of the value
      sprite.y = (value / 16) * 16;  // use division to find the row of the value
      sprite.w = 16;
      sprite.h = 16;

      /*if (font_num == 0)
      {
          temp1 =SDL_SetTextureColorMod(bmp_font, color_id.r, color_id.g, color_id.b);
          if (temp1 < 0)
          {
              printf("wtf2");
          }
          SDL_RenderCopy(ren, bmp_font, &sprite, &pos);
      } else if (font_num == 1)
      {
          temp1 =  SDL_SetTextureColorMod(bmp_font_2, color_id.r, color_id.g, color_id.b);
          if (temp1 < 0)
          {
              printf("wtf3");
          }
          SDL_RenderCopy(ren, bmp_font_2, &sprite, &pos);
      } else if (font_num == 2)
      {
          temp1 = SDL_SetTextureColorMod(bmp_font_3, color_id.r, color_id.g, color_id.b);
          if (temp1 < 0)
          {
              printf("wtf4");
          }
          SDL_RenderCopy(ren, bmp_font_3, &sprite, &pos);
      }*/
      //printf("font num= %d,\n", font_num);
     // tex = bmp_fonts[font_num];
     //temp1 = SDL_SetTextureColorMod(bmp_fonts[font_num], color_id.r, color_id.g, color_id.b);
      temp1 = SDL_SetTextureColorMod(bmp_fonts.at(font_num), color_id.r, color_id.g, color_id.b);
      if (temp1 < 0)
      {
         //printf("wtf5");
         printf("font_num=%d, SDL_Init failed: %s\n",font_num, SDL_GetError());
      }
      SDL_RenderCopy(ren, bmp_fonts[font_num], &sprite, &pos);

      tex = NULL;
  }



  //This will set the color modification to a texture.
  void Display_Engine::Set_Texture_Color(int texture_id, int r, int g, int b)
  {
      SDL_SetTextureColorMod(textures[texture_id],r,g,b);
      return;
  }

  void Display_Engine::Set_Texture_Alpha(int texture_id, int alpha)
  {
      SDL_SetTextureAlphaMod(textures[texture_id],alpha);
      return;

  }


   void Display_Engine::Set_Texture_Alpha(int texture_id,std::vector<SDL_Texture*> &textures,int alpha)
  {



   //SDL_RenderCopy(ren,textures[texture_id],NULL,NULL);

        SDL_SetTextureAlphaMod(textures[texture_id],alpha);
        return;

  }


  int Display_Engine::Sizeof_Textures()
  {
      return textures.size();
  }


void Display_Engine::Cleanup_Display()
{
    //Close the font that was used
//    TTF_CloseFont( font );

//    font.clear();
    //Quit SDL_ttf
    printf("cleanup 1\n");
    TTF_Quit();
    printf("cleanup 2\n");
    //SDL_DestroyTexture(tex);
    if(textures.size()>0)
    {
     for(int i=0;i<(int)textures.size();i++)
      {
          SDL_DestroyTexture(textures[i]);
      }
    }
    printf("cleanup 3\n");
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    printf("cleanup 4\n");
    return;
}


 // this is an old function that has been combined with apply_text() to create disp_text()
 bool Display_Engine::Set_Text(char *display_string,Font_IDs font_id, Text_Colors color_id)
 {
     display_texture=NULL;
      surf_text = TTF_RenderText_Solid( font[font_id], display_string, textColors[color_id] );

      //If there was an error in rendering the text
      if( surf_text == NULL )
      {
          return false;
      }
      display_texture=SDL_CreateTextureFromSurface(ren, surf_text);
      SDL_QueryTexture( display_texture, NULL, NULL, &display_text_size.w, &display_text_size.h);
      SDL_FreeSurface(surf_text);
      //SDL_DestroyTexture(display_text);
      return true;
  }
  //old function us disp_text instead
  void Display_Engine::Apply_Text(int x,int y)
  {
      SDL_Rect pos;
     pos.x=x;
     pos.y=y;
     pos.w=display_text_size.w;
     pos.h=display_text_size.h;

          SDL_RenderCopy(ren, display_texture,NULL,&pos);
          SDL_DestroyTexture(display_texture);
      return;
  }

  //set the text to be displayed at a particular spot and use a predefined color
  //bool Display_Engine::Disp_Text(const char *display_string,Font_IDs font_id, Text_Colors color_id, int x, int y)
  bool Display_Engine::Disp_Text(std::string display_string, Font_IDs font_id, Text_Colors color_id, int x, int y)
  {
          display_texture=NULL;
      surf_text = TTF_RenderText_Solid( font[font_id], display_string.c_str(), textColors[color_id] );
     // printf(" color_id, r= %d, b = %d, g= %d\n", textColors[color_id].r, textColors[color_id].b, textColors[color_id].g);
      //If there was an error in rendering the text
      if( surf_text == NULL )
      {
          
          return false;
      }
      display_texture=SDL_CreateTextureFromSurface(ren, surf_text);
      if (display_texture == NULL) {
          fprintf(stderr, "CreateTextureFromSurface failed: %s\n", SDL_GetError());
          return false;
      }
      SDL_QueryTexture( display_texture, NULL, NULL, &display_text_size.w, &display_text_size.h);
      SDL_FreeSurface(surf_text);
      //SDL_DestroyTexture(display_text);

          SDL_Rect pos;
     pos.x=x;
     pos.y=y;
     pos.w=display_text_size.w;
     pos.h=display_text_size.h;

          SDL_RenderCopy(ren, display_texture,NULL,&pos);

          SDL_DestroyTexture(display_texture);
      return true;

  }




  //set the text to be displayed at a particular spot and use a any color as specified by an SDL_Color vector {R,G,B}
  bool Display_Engine::Disp_Text(std::string display_string,Font_IDs font_id, SDL_Color tempColor, int x, int y)
  {
          display_texture=NULL;
      surf_text = TTF_RenderText_Solid( font[font_id], display_string.c_str(), tempColor );
      //printf(" tempColor, r= %d, b = %d, g= %d\n", tempColor.r, tempColor.b, tempColor.g);

      SDL_SetSurfaceAlphaMod(surf_text, tempColor.a);
      //If there was an error in rendering the text
      if( surf_text == NULL )
      {
          printf("surf failed\n");
          return false;
      }
      display_texture=SDL_CreateTextureFromSurface(ren, surf_text);
      if (display_texture == NULL) {
          fprintf(stderr, "CreateTextureFromSurface failed: %s\n", SDL_GetError());
          return false;
      }
      SDL_QueryTexture( display_texture, NULL, NULL, &display_text_size.w, &display_text_size.h);
      SDL_FreeSurface(surf_text);
      //SDL_DestroyTexture(display_text);

          SDL_Rect pos;
     pos.x=x;
     pos.y=y;
     pos.w=display_text_size.w;
     pos.h=display_text_size.h;

          SDL_RenderCopy(ren, display_texture,NULL,&pos);
          SDL_DestroyTexture(display_texture);
      return true;

  }
//set the text to be displayed at a particular spot and use a any color as specified by an SDL_Color vector {R,G,B}
  bool Display_Engine::Disp_Text_Wrapped(std::string display_string,Font_IDs font_id, SDL_Color tempColor, int x, int y, int wrapped_size)
  {
          display_texture=NULL;
      //surf_text = TTF_RenderText_Solid( font[font_id], display_string, tempColor );
//TTF_RenderText_Blended_Wrapped
surf_text= TTF_RenderText_Blended_Wrapped(font[font_id], display_string.c_str(), tempColor, wrapped_size);
//surf_text = TTF_RenderText_Blended_Wrapped( font[font_id], display_string, tempColor );
      //If there was an error in rendering the text
      if( surf_text == NULL )
      {
          return false;
      }
      display_texture=SDL_CreateTextureFromSurface(ren, surf_text);
      SDL_QueryTexture( display_texture, NULL, NULL, &display_text_size.w, &display_text_size.h);
      SDL_FreeSurface(surf_text);
      //SDL_DestroyTexture(display_text);

          SDL_Rect pos;
     pos.x=x;
     pos.y=y;
     pos.w=display_text_size.w;
     pos.h=display_text_size.h;

          SDL_RenderCopy(ren, display_texture,NULL,&pos);
          SDL_DestroyTexture(display_texture);
      return true;

  }




void Display_Engine::Set_Background_Color(int r, int g, int b,int a)
{
    SDL_SetRenderDrawColor( ren, r, g, b, a );
    return;
}


void Display_Engine::Draw_Rect(SDL_Rect rect, int r, int g, int b, bool outline)
{
    SDL_Point points[5]; 
    Set_Background_Color(r, g, b, 255);
    if (outline)
    {
        points[0].x = rect.x;
        points[0].y = rect.y;
        points[1].x = rect.x + rect.w;
        points[1].y = rect.y;
        points[2].x = rect.x + rect.w;
        points[2].y = rect.y + rect.h;
        points[3].x = rect.x;
        points[3].y = rect.y + rect.h;
        points[4].x = rect.x;
        points[4].y = rect.y;
        SDL_RenderDrawLines(ren, points, 5);
    }
    else
    {
        SDL_RenderFillRect(ren, &rect);

    }
    
    
    

    

    Set_Background_Color(0x00, 0x00, 0x00, 0xFF);
}




