#include "monsters.h"
#include "core_engine.h"

Monsters::Monsters()
{
output_check=fopen("smart_movement check","w");
fclose(output_check);
output_check=fopen("smart_movement check","a");

srand((unsigned int)time(0));

        char str2[200];
        //char str_temp[20];
        int gen;
        int special;
        int index = 0;
        printf("loading monsters\n");
        //n=sprintf(str2,"gamedata/resources/monster_data.txt");
        n = sprintf(str2, "gamedata/resources/monster_data_v2.txt");
        char temp_1[6],temp_2[6],temp_3[6],temp_4[6],temp_5[6],temp_6[6],temp_7[6], temp_8[6], temp_9[6], temp_10[6], temp_11[6], temp_12[6], temp_13[8];
        //char str3[200];

        FILE *resource_file_2 = fopen(str2,"r");
        if (resource_file_2 == NULL) {
            printf("\nFailed: \n");
            //return 1;
        }
        else
        {
            printf("resource file open\n");
            n = fscanf(resource_file_2, "%s %s %s %s %s %s %s %s %s %s %s %s %s", temp_1, temp_2, temp_3, temp_4, temp_5, temp_6, temp_7, temp_8, temp_9, temp_10, temp_11, temp_12, temp_13);
            printf("n=%d\n", n);
            n = fscanf(resource_file_2, "%s %d %d %d %d %d %d %d %d %d %d %d %c\n", temp_monster.name, &temp_monster.level, &temp_monster.defense, &temp_monster.damage, &temp_monster.attack_power, &temp_monster.defense, &gen, &temp_monster.intel, &temp_monster.gold, &temp_monster.hp, &temp_monster.xp_value, &special, &temp_monster.symbol);
            while (n != EOF)
            {
                n = fscanf(resource_file_2, "%s %d %d %d %d %d %d %d %d %d %d %d %c\n", temp_monster.name, &temp_monster.level, &temp_monster.defense, &temp_monster.damage, &temp_monster.attack_power, &temp_monster.defense, &gen, &temp_monster.intel, &temp_monster.gold, &temp_monster.hp, &temp_monster.xp_value, &special, &temp_monster.symbol);
                printf("n=%d\n", n);
                temp_monster.index_value = index;
                temp_monster.next_to_player = false;
                temp_monster.color = WHITE;
                temp_monster.x = 1;
                temp_monster.y = 1;
                if (gen == 0)
                {
                    temp_monster.gen = false;
                }
                else
                {
                    temp_monster.gen = true;
                }
                if (special == 0)
                {
                    temp_monster.special = false;
                }
                else
                {
                    temp_monster.special = true;
                }
                all_monsters.push_back(temp_monster);
                index++;
            }


            fclose(resource_file_2);

        }

        

    

}

Monsters::~Monsters()
{
    fclose(output_check);
}

int Monsters::add_Monster(int x, int y, int level)
{
    MONSTER temp_monster;

    int index;
    int n;
    n=all_monsters.size();
    index = rand()%(n);
    //printf("\nn=%d,index=%d",n,index);
    temp_monster=all_monsters[index];
    //temp_monster=all_monsters[0];
    temp_monster.x=x;
    temp_monster.y=y;
    temp_monster.alive=true;



    level_monsters.push_back(temp_monster);
    index = level_monsters.size()-1;

    return index;
}

bool Monsters::move_monsters(Core_Engine& core)
{
    num_monsters=level_monsters.size();
    //printf("\n in monster move\n");
    /*
    need to make sure that monsters cannot move out of the enterance onthe first dungeon level)
    */
    for(int x=0;x<num_monsters;x++)
    {
        if(level_monsters[x].alive)
        {
            if (level_monsters[x].intel>10)
            {

                move_monsters_smart(core,x);

            }else
            {
                //printf("\n in monster dumb move\n");
                move_monsters_dumb(core,x);
            }
        }
        //check_next_to_player(x, game_data, player, ui_display);
        //if(level_monsters[x].next_to_player)
        //{
        //    monster_attack(x, game_data,player,ui_display);

        //    n=sprintf(str,"%s attacks player", level_monsters[x].name);
        //    ui_display.Add_ui_message(str,{120,25,15});
        //}
    }
    return true;
}

bool Monsters::move_monsters_smart(Core_Engine& core,int index)
{
        //int n;
        //char str[20];
       // printf("RIP=%d\n", game_data.dungeon_level[temp_y][temp_x].prox_ripple_value);

        
        last_x=level_monsters[index].x;
        last_y=level_monsters[index].y;
        temp_x=level_monsters[index].x;
        temp_y=level_monsters[index].y;
        core.game_data.dungeon_level[temp_y][temp_x].monster=false;
        core.game_data.dungeon_level[temp_y][temp_x].monster_index=-1;
    //printf("RIP=%d\n", game_data.dungeon_level[temp_y][temp_x].prox_ripple_value);
    //fprintf(output_check,"smart_movement,index=%d,type=%s\n",index,level_monsters[index].name);
   // fprintf(output_check,"current_ripple_value=%d",game_data.dungeon_level[temp_y][temp_x].prox_ripple_value);
    if((core.game_data.dungeon_level[temp_y][temp_x].prox_ripple_value> core.game_data.dungeon_level[temp_y+1][temp_x+1].prox_ripple_value))
    {
                //check in +x and +y direction
                temp_x+=1;
                temp_y+=1;
    }else if(core.game_data.dungeon_level[temp_y][temp_x].prox_ripple_value> core.game_data.dungeon_level[temp_y+1][temp_x-1].prox_ripple_value)
    {
                //check in -x and +y direction
                temp_x-=1;
                temp_y+=1;
    }else if(core.game_data.dungeon_level[temp_y][temp_x].prox_ripple_value> core.game_data.dungeon_level[temp_y-1][temp_x-1].prox_ripple_value)
    {
                //check in -x and -y direction
                temp_x-=1;
                temp_y-=1;
    }else if(core.game_data.dungeon_level[temp_y][temp_x].prox_ripple_value> core.game_data.dungeon_level[temp_y-1][temp_x+1].prox_ripple_value)
    {
                //check in +x and -y direction
                temp_x+=1;
                temp_y-=1;
    }else if(core.game_data.dungeon_level[temp_y][temp_x].prox_ripple_value> core.game_data.dungeon_level[temp_y][temp_x+1].prox_ripple_value)
    {
                //check in +x and no change y direction
                temp_x+=1;
                //temp_y-=1;
    }else if(core.game_data.dungeon_level[temp_y][temp_x].prox_ripple_value> core.game_data.dungeon_level[temp_y][temp_x-1].prox_ripple_value)
    {
                //check in -x and no change y direction
                temp_x-=1;
                //temp_y-=1;
    }else if(core.game_data.dungeon_level[temp_y][temp_x].prox_ripple_value> core.game_data.dungeon_level[temp_y+1][temp_x].prox_ripple_value)
    {
                //check in no change x and +y direction
                //temp_x+=1;
                temp_y+=1;
    }else if(core.game_data.dungeon_level[temp_y][temp_x].prox_ripple_value> core.game_data.dungeon_level[temp_y-1][temp_x].prox_ripple_value)
    {
                //check in no change x and -y direction
                //temp_x+=1;
                temp_y-=1;
    }

//                         if ((player.x==temp_x)&&(player.y==temp_y))
//                       {
//                            printf("\nplayer is here\n");
//                                n=sprintf(str,"monster attack");
//                                ui_display.Add_ui_message(str,{120,25,15});
//
//                       }


    if((core.game_data.dungeon_level[temp_y][temp_x].block_type=='#')||(core.game_data.dungeon_level[temp_y][temp_x].object_symbol=='D')||(core.game_data.dungeon_level[temp_y][temp_x].monster)||((core.player.x==temp_x)&&(core.player.y==temp_y)))
    {
                       //if ((player.x==temp_x)&&(player.y==temp_y))
                       //{
                       //     printf("\nplayer is here\n");
                       //     printf("%s attacks the player\n", level_monsters[index].name);
                       //     // n=sprintf(str,"monster attack");
                       //     //ui_display.Add_ui_message(str);
                       //}

                            temp_x=level_monsters[index].x;
                            temp_y=level_monsters[index].y;
                            core.game_data.dungeon_level[temp_y][temp_x].monster=true;
                            core.game_data.dungeon_level[temp_y][temp_x].monster_index=index;
    }else
    {
                            //printf("\nplayer is not here2\n");
                                //n=sprintf(str,"monster Smart Move");
                                //ui_display.Add_ui_message(str,{120,25,178});
                            fprintf(output_check,"moving_to_ripple_value=%d\n", core.game_data.dungeon_level[temp_y][temp_x].prox_ripple_value);
                            level_monsters[index].x=temp_x;
                            level_monsters[index].y=temp_y;
                            core.game_data.dungeon_level[temp_y][temp_x].monster=true;
                            core.game_data.dungeon_level[temp_y][temp_x].monster_index=index;

    }

    if (core.game_data.dungeon_level[level_monsters[index].y][level_monsters[index].x].prox_ripple_value <= 1)
    {

        monster_attack(index, core);

    }
//if((dungeon_level[current_level][temp_y][temp_x].block_type=='#')||(dungeon_level[current_level][temp_y][temp_x].object_symbol=='D')||(dungeon_level[current_level][temp_y][temp_x].monster)||(dungeon_level[current_level][temp_y][temp_x].player))
//               {
//
//                   if ((dungeon_level[current_level][temp_y][temp_x].player)&&(dungeon_level[current_level][temp_y][temp_x].object_symbol!='D'))
//                   {
//                       //ui.Add_ui_message("fight y");
//                       fight=true;
//                   }
//
//
//                   temp_y=last_y;
//                   temp_x=last_x;
//                   //ui.Add_ui_message("something there no move smart");
//
//               }
//
//                dungeon_level[current_level][temp_y][temp_x].monster=true;
//                dungeon_level[current_level][temp_y][temp_x].monster_index=index;
//
//                monsters[current_level][index].x=temp_x;
//                monsters[current_level][index].y=temp_y;
//                //ui.Add_ui_message(" ");
//            if(fight)
//            {
//                if(!monster_attack(player,ui,index))
//                {
//                        return false;
//                }
//            }





    return true;
}


bool Monsters::move_monsters_dumb(Core_Engine& core,int index)
{
            //printf("index=%d size=%d\n", index, level_monsters.size());
            last_x=level_monsters[index].x;
            last_y=level_monsters[index].y;
            temp_x=level_monsters[index].x;
            temp_y=level_monsters[index].y;
            //printf("dumb here 2\n");
            if((temp_x-5<= core.player.x)&&(temp_x+5>= core.player.x)&&(temp_y-5<= core.player.y)&&(temp_y+5>= core.player.y))
            {
                       move_monsters_smart(core,index);
            }else
            {
                        rand_direction=rand()%7;
                        switch (rand_direction)
                        {
                            case 0://move right
                                temp_x=temp_x+1;
//                                if((game_data.dungeon_level[temp_y][temp_x].block_type!='#')||(game_data.dungeon_level[temp_y][temp_x].object_symbol=='D')||(game_data.dungeon_level[temp_y][temp_x].monster)||((player.x==temp_x)&&(player.y==temp_y)))
//                                {
//                                    game_data.dungeon_level[temp_y][temp_x-1].monster=false;
//                                    game_data.dungeon_level[temp_y][temp_x-1].monster_index=-1;
//                                    game_data.dungeon_level[temp_y][temp_x].monster=true;
//                                    game_data.dungeon_level[temp_y][temp_x].monster_index=index;
//                                    level_monsters[index].x=temp_x;
//                                }
                            break;
                            case 1://move left
                                temp_x=temp_x-1;
//                                if(game_data.dungeon_level[temp_y][temp_x].block_type!='#')
//                                {
//                                    game_data.dungeon_level[temp_y][temp_x+1].monster=false;
//                                    game_data.dungeon_level[temp_y][temp_x+1].monster_index=-1;
//                                    game_data.dungeon_level[temp_y][temp_x].monster=true;
//                                    game_data.dungeon_level[temp_y][temp_x].monster_index=index;
//                                    level_monsters[index].x=temp_x;
//                                }
                            break;
                            case 2://move up
                                temp_y=temp_y-1;
//                                if(game_data.dungeon_level[temp_y][temp_x].block_type!='#')
//                                {
//                                    game_data.dungeon_level[temp_y+1][temp_x].monster=false;
//                                    game_data.dungeon_level[temp_y+1][temp_x].monster_index=-1;
//                                    game_data.dungeon_level[temp_y][temp_x].monster=true;
//                                    game_data.dungeon_level[temp_y][temp_x].monster_index=index;
//                                    level_monsters[index].y=temp_y;
//                                }
                            break;
                            case 3://move down
                                temp_y=temp_y+1;
//                                if(game_data.dungeon_level[temp_y][temp_x].block_type!='#')
//                                {
//                                    game_data.dungeon_level[temp_y-1][temp_x].monster=false;
//                                    game_data.dungeon_level[temp_y-1][temp_x].monster_index=-1;
//                                    game_data.dungeon_level[temp_y][temp_x].monster=true;
//                                    game_data.dungeon_level[temp_y][temp_x].monster_index=index;
//                                    level_monsters[index].y=temp_y;
//                                }
                            break;
                            case 4://move up-right
                                temp_y=temp_y-1;
                                temp_x=temp_x+1;
//                                if(game_data.dungeon_level[temp_y][temp_x].block_type!='#')
//                                {
//                                    game_data.dungeon_level[temp_y+1][temp_x-1].monster=false;
//                                    game_data.dungeon_level[temp_y+1][temp_x-1].monster_index=-1;
//                                    game_data.dungeon_level[temp_y][temp_x].monster=true;
//                                    game_data.dungeon_level[temp_y][temp_x].monster_index=index;
//                                    level_monsters[index].x=temp_x;
//                                    level_monsters[index].y=temp_y;
//                                }
                            break;
                            case 5://move down-right
                                temp_y=temp_y+1;
                                temp_x=temp_x+1;
//                                if(game_data.dungeon_level[temp_y][temp_x].block_type!='#')
//                                {
//                                    game_data.dungeon_level[temp_y-1][temp_x-1].monster=false;
//                                    game_data.dungeon_level[temp_y-1][temp_x-1].monster_index=-1;
//                                    game_data.dungeon_level[temp_y][temp_x].monster=true;
//                                    game_data.dungeon_level[temp_y][temp_x].monster_index=index;
//                                    level_monsters[index].x=temp_x;
//                                    level_monsters[index].y=temp_y;
//                                }
                            break;
                            case 6://move down-left
                                temp_y=temp_y+1;
                                temp_x=temp_x-1;
//                                if(game_data.dungeon_level[temp_y][temp_x].block_type!='#')
//                                {
//                                    game_data.dungeon_level[temp_y-1][temp_x+1].monster=false;
//                                    game_data.dungeon_level[temp_y-1][temp_x+1].monster_index=-1;
//                                    game_data.dungeon_level[temp_y][temp_x].monster=true;
//                                    game_data.dungeon_level[temp_y][temp_x].monster_index=index;
//                                    level_monsters[index].x=temp_x;
//                                    level_monsters[index].y=temp_y;
//                                }
                            break;
                            case 7://move up-left
                                temp_y=temp_y-1;
                                temp_x=temp_x-1;
//                                if(game_data.dungeon_level[temp_y][temp_x].block_type!='#')
//                                {
//                                    game_data.dungeon_level[temp_y+1][temp_x+1].monster=false;
//                                    game_data.dungeon_level[temp_y+1][temp_x+1].monster_index=-1;
//                                    game_data.dungeon_level[temp_y][temp_x].monster=true;
//                                    game_data.dungeon_level[temp_y][temp_x].monster_index=index;
//                                    level_monsters[index].x=temp_x;
//                                    level_monsters[index].y=temp_y;
//                                }
                            break;
                        }


                        //if((game_data.dungeon_level[temp_y][temp_x].block_type!='#')||(game_data.dungeon_level[temp_y][temp_x].object_symbol!='D')||(!game_data.dungeon_level[temp_y][temp_x].monster)||((player.x!=temp_x)&&(player.y!=temp_y)))
                        if ((core.game_data.dungeon_level[temp_y][temp_x].block_type != '#') && (core.game_data.dungeon_level[temp_y][temp_x].object_symbol != 'D') && (!core.game_data.dungeon_level[temp_y][temp_x].monster))
                        {
                            //printf("dumb here 3\n");
                            //printf("%s is causing problem\n", level_monsters[index].name);
                            core.game_data.dungeon_level[level_monsters[index].y][level_monsters[index].x].monster_index=-1;
                            core.game_data.dungeon_level[level_monsters[index].y][level_monsters[index].x].monster=false;

                            //printf("dumb move=%d %d\n", index, level_monsters.size());
                            level_monsters[index].x = temp_x;
                            level_monsters[index].y = temp_y;
                            core.game_data.dungeon_level[temp_y][temp_x].monster = true;
                            core.game_data.dungeon_level[temp_y][temp_x].monster_index = index;
                        }
                        


            }

return true;
}


void Monsters::monster_attack(int monster_id, Core_Engine& core)
{
    int damage=0;
    //int n;
    //char str[20];
    std::string str_2;
    std::string str_3;
    int roll_value =rand() % 20 + 1;
    if(level_monsters[monster_id].attack_power+roll_value>core.player.stats.defense)
    {
            //n=sprintf(str,"%s hit you",level_monsters[monster_id].name);

        //ui_display.Add_ui_message(str);
        if(!core.player.invincible)
        {
            str_2 = level_monsters[monster_id].name;
            std::cout << str_2 << std::endl;
            str_3 = str_2 + " hit you";
            std::cout << str_3<<std::endl;
            core.ui_display.Add_ui_message(str_3);
            core.player.stats.hp= core.player.stats.hp-level_monsters[monster_id].damage;
            if(core.player.stats.hp<=0)
            {
                core.player.alive=false;
            }
        }
        else
        {
            //n = sprintf(str, "%s hit you, but", level_monsters[monster_id].name);
            str_2 = level_monsters[monster_id].name;
            str_3 = str_2 + " hit you";
            core.ui_display.Add_ui_message(str_3);
            str_3 ="you are invincible!";
            core.ui_display.Add_ui_message(str_3);
        }
    }else
    {
        str_2 = level_monsters[monster_id].name;
        std::cout << str_2 << std::endl;
        str_3 = str_2+ " missed you";
        std::cout << str_3 << std::endl;
        //n=sprintf(str,"%s missed you",level_monsters[monster_id].name);
        core.ui_display.Add_ui_message(str_3);
    }



    //re damage;
}

void Monsters::load_level_monsters(int x, int y, int index)
{
    MONSTER temp_monster;
    temp_monster = all_monsters[index];
    temp_monster.x = x;
    temp_monster.y = y;
    temp_monster.alive = true;
    level_monsters.push_back(temp_monster);

    return;
}

bool Monsters::check_next_to_player(int monster_id, Core_Engine& core)
{


    return false;
}