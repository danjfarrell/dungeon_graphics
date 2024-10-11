#include "intro.h"

Intro::Intro()
{
    printf("starting intro\n");
    size_and_pos.x=0;
    size_and_pos.y=0;
    size_and_pos.w=SCREEN_WIDTH;
    size_and_pos.h=SCREEN_HEIGHT;

      phase=0;
      f_alpha=0;
      alpha=0;
      frame_count=-1;
      current_screen=0;
        init_needed=true;
     printf("end intro init\n");
}

//load data need for the intro class to run
bool Intro::load_data(Core_Engine &core)
{
     printf("load data start\n");
     srand ((unsigned int)time(NULL));
     int n;

     FILE *iFile;
     char filename[200];
     iFile = fopen("gamedata/resources/intro/intro.dat","r");
     if (iFile == NULL)
     {
         printf("load intro.dat failed\n");
         fclose(iFile);
         return false;
     }
     n=fscanf(iFile,"%i\n",&num_screens);
     
     printf("\nnum_screens:%i\n",num_screens);

	 for(int i=0;i<num_screens;i++)
 	 {
            splash temp;
            n=fscanf(iFile,"%s\n",filename);
    	    n=fscanf(iFile,"%i\n%i\n%i\n",&temp.fade_in_frame,&temp.hold,&temp.fade_out_frame);

    	    temp.fade_in_frame=temp.fade_in_frame*FRAMES_PER_SECOND;

    	    if(temp.fade_in_frame<=0)
            {
                temp.fade_in=255;
            }else
            {
                temp.fade_in=ALPHA_MAX/temp.fade_in_frame;
                if(temp.fade_in<=0)
                {
                    temp.fade_in=1;
                }
            }

                temp.fade_out_frame=temp.fade_out_frame*FRAMES_PER_SECOND;
    	    if(temp.fade_out_frame<=0)
    	    {
               temp.fade_out=0;
            }else
            {
                temp.fade_out=ALPHA_MAX/temp.fade_out_frame;
                if(temp.fade_out<=0)
                {
                    temp.fade_out=1;
                }
            }
                temp.hold=temp.hold*FRAMES_PER_SECOND;

           temp.texture_id=core.disp.Load_Texture(filename,textures,texture_size);
           //temp.texture_id=disp.Load_Texture(filename);
            s_screen.push_back(temp);

      }
      n = fscanf(iFile,"%i\n%i\n",&text_pos_x,&text_pos_y);

      fclose(iFile);

    script_not_done=false;
    init_needed=false;
    return true;
}


/*
This is the intro of game play.
The gameplay screen is displayed and the player input is read.
*/
bool Intro::run_intro(Core_Engine &core)
{
                //bool script_done;
              // core.disp.Disp_Text("the intro loop!",FONT_1,GREEN, 15, 375);
    //printf(" run_intro \n");
                //core.disp.Disp_Text("the intro loop!", FONT_1, { 0,255,0 ,0}, 35, 375);
                if(init_needed)
                {
                    printf("load_data started\n");
                    if (!load_data(core))
                    {
                        printf("load_data failed\n");
                        return true;
                    }
                    printf("load_data complete\n");
                }

                if((core.input.KEY_RETURN==1)&& (core.input.KEY_RETURN_up))
                {
                    core.input.KEY_RETURN_up=false;

                    return true;
                }else if (core.input.KEY_RETURN==-1)
                {
                    core.input.KEY_RETURN_up=true;
                }

                if(core.input.KEY_SPACE==1&&(core.input.KEY_SPACE_up==true))
                {
                        core.input.KEY_SPACE_up=false;
                        //play_state=OVERWORLD;
                        if(phase<1)
                        {
                            phase=1;
                            f_alpha=1.0;
                            alpha=255;
                        }else
                        {
                            phase=0;
                            alpha=0;
                            current_screen++;
                                  if(current_screen>=num_screens)
                                  {
                                       script_not_done=true;
                                       f_alpha=1.0;
                                       alpha=ALPHA_MAX;
                                  }
                        }
                        init_needed=true;

                }else if (core.input.KEY_SPACE==-1)
                {
                    core.input.KEY_SPACE_up=true;
                }

                if(!display_intro(core))
                {
                    clean_up();
                    
                    return true;
                }

    return false;
}
void Intro::clean_up()
{
    if (textures.size() > 0)
    {
        for (int i = 0; i < (int)textures.size(); i++)
        {
            SDL_DestroyTexture(textures[i]);
        }
    }
    textures.clear();
}



bool Intro::display_intro(Core_Engine &core)
{

         //int n;
         //char tst[20];



         //disp_eng.Apply_Texture(s_screen[current_screen].texture_id,size_and_pos);
         SDL_Rect temp;
         temp.h=texture_size[s_screen[current_screen].texture_id].h;
         temp.w=texture_size[s_screen[current_screen].texture_id].w;
         if(texture_size[s_screen[current_screen].texture_id].w<SCREEN_WIDTH)
         {
             temp.x=(SCREEN_WIDTH-temp.w)/2;
         }else if(texture_size[s_screen[current_screen].texture_id].w>SCREEN_WIDTH )
         {
             texture_size[s_screen[current_screen].texture_id].w=SCREEN_WIDTH;
             temp.x=0;
         }else
         {
             temp.x=0;
         }
         if(texture_size[s_screen[current_screen].texture_id].h<SCREEN_HEIGHT)
         {
             temp.y=(SCREEN_HEIGHT-temp.h)/2;
         }else if(texture_size[s_screen[current_screen].texture_id].h>SCREEN_HEIGHT )
         {
             texture_size[s_screen[current_screen].texture_id].h=SCREEN_HEIGHT;
             temp.y=0;
         }else
         {
            temp.y=0;
         }



         if(!script_not_done)
         {
            // printf("script not done\n");
             core.disp.Set_Texture_Alpha(s_screen[current_screen].texture_id,textures,alpha);
             core.disp.Apply_Texture(s_screen[current_screen].texture_id,temp,textures);

             switch(phase)
             {
                 case 0:
                     alpha=alpha+s_screen[current_screen].fade_in;

                     if(alpha>=255)
                     {
                                  alpha=255;
                                  phase=1;
                                  frame_count=-1;
                     }
                                                if(INTRO_DEBUG)
                                                {
                                                        //disp_eng.Disp_Text("fade in!",FONT_1,GREEN, 25, 25);
                                                }
                     break;
                  case 1:
                       f_alpha=1.0;
                       alpha=255;
                       frame_count++;

                       if(frame_count>(int)s_screen[current_screen].hold)
                       {
                                  phase=2;
                                  frame_count=0;
                       }
                                                if(INTRO_DEBUG)
                                                {
//                                                    disp_eng.Set_Text("Hold!",FONT_2,BLUE);
//                                                    disp_eng.Apply_Text(25,25);
                                                }
                       break;
                  case 2:

                                                if(INTRO_DEBUG)
                                                {
//                                                    disp_eng.Set_Text("Fade Out!",FONT_2,GREEN);
//                                                    disp_eng.Apply_Text(25,25);
                                                }
                     if( s_screen[current_screen].fade_out>0)
                     {
                        alpha=alpha-s_screen[current_screen].fade_out;
                     }else
                     {
                       alpha=0;
                     }
                     if(alpha<=0)
                     {
                                  alpha=0;
                                  phase=0;
                                  current_screen++;
                                  if(current_screen>=num_screens)
                                  {
                                       script_not_done=true;
                                       current_screen--;
                                       f_alpha=1.0;
                                       alpha=ALPHA_MAX;
                                  }
                     }
                     break;
            }
         }else
         {
			return false;
         }

         return true;
}
