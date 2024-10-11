#include "player.h"
//#include "gamemap.h"
//#include "build_level.h"
//#include "ui_display.h"
//#include "monsters.h"
//#include "spells.h"
#include "core_engine.h"


Player::Player()
{
    printf("player \n");
//output_check=fopen("player_build.txt","w");
//fclose(output_check);
output_check=fopen("player_build.txt","w");
msg_sent = false;
srand((unsigned int)time(0));
//xp_required[0]=-100;

x = overworld_player_start_pos_x;
y= overworld_player_start_pos_y;
flash=1;
flash_counter=0;
underneath='.';
WTW=false;
EPA=false;
on_object=false;
object_ignore=false;
found_gold=false;
shift_direction=false;
equipping_weapon=false;
equipping_armor = false;
equipping_shield = false;
dropping_item = false;
entering_drop = false;
hit_monster=false;
hit_id=-1;
//equip_selection=-1;
choice_complete=true;
choice_made=false;
stats.intel=10;
stats.str=10;
stats.stam=10;
stats.dex=11;
stats.gold=10000000;
stats.level=1;
stats.hp=20;
//stats.max_hp=20 + floor((stats.stam - 10) / 2);
stats.max_hp = 20 + ((stats.stam - 10) / 2);
stats.max_mp = 2;
stats.mp=2;
stats.base_attack=5;
stats.base_damage=1;
stats.base_defense=10;
//stats.attack_power= stats.base_attack + floor((stats.dex - 10) / 2);
//stats.defense= stats.base_defense + floor((stats.dex - 10) / 2);
//stats.damage= stats.base_damage + floor((stats.str - 10) / 2);
stats.attack_power= stats.base_attack + ((stats.dex - 10) / 2);
stats.defense= stats.base_defense + ((stats.dex - 10) / 2);
stats.damage= stats.base_damage + ((stats.str - 10) / 2);
stats.agro_dist=10;
stats.exp=0;
strcpy(stats.name,"zenious");
color = { 252,227,3};
alive = true;
current_weapon_index=-1;
current_armor_index = -1;
current_shield_index = -1;
single_move = false;
invincible = false;
PLAYER_CHARACTER=64;
weapon_index = 0;
font = 0;
num_lines=0;



for (int i = 0; i < NUM_SPELLS; i++)
{
    known_spells[0] = false;
}
known_spells[0]=true;
known_spells[1] = true;
known_spells[37] = true;
//known_spells[5] = true;
//num_known_spells = 3;

load_xp_system();
spell_cast_msg_displayed = false;
game_saved = false;
casting_spell = false;
casting_selection = ' ';
mouse_move_inprogress = false;
player_input_states=PLAYER_MOVEMENT;

for (int i = 0; i < NUM_SPELL_EFFECTS; i++)
{
    effects_durations[i] = 0;
    effects_time[i][0] = 0;
    effects_time[i][1] = 0;
}
for (int i = 0; i <2; i++)
{
    hp_mp_regen_rate[i] = 2;
    hp_mp_regen[i] = 0;
}

        printf("player 2\n");
        //char str2[200];
        //n=sprintf(str2,"gamedata/resources/inventory_data.txt");
        //printf("\n%s",str2);
        //Item temp_item;
        //char temp_1,temp_2,temp_3,temp_4,temp_5,temp_6,temp_7;
        //char str3[50] ="";
        //int item_values[20];
        //for (int i = 0; i < 20; i++)
        //{
        //    item_values[i] = 0;
        //}
        //int count = 0;
        //char* token;
       /* FILE* resource_file_2 = fopen(str2, "r");
        if (resource_file_2 == NULL) {
            printf("\nFailed: \n");
            //return 1;
        }

        while (fgets(str3, sizeof(str3), resource_file_2))
        {
            count = 0;
            token = strtok(str3, " ");
            while (token != NULL)
            {
                if (strcmp(token, "T")==0)
                {
                    item_values[count] = 1;
                }
                else if (strcmp(token, "F")==0)
                {
                    item_values[count] = 0;
                }
                else
                {
                    item_values[count] = atoi(token);
                }
                
                
                printf("|%d %s %d|",count, token, item_values[count]);
                count++;
                token = strtok(NULL, " ");
            }
            printf(" count=%d\n", count);
            temp_item.id = item_values[0];
            temp_item.magic_prefix= item_values[1];
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
            item_list.push_back(temp_item);
        }
       
        fclose(resource_file_2);*/


//difficultity_level = 0;

    if (difficultity_level == 0) {
        //inventory.push_back(item_list[36]);
        //inventory.push_back(item_list[49]);

    }


}

Player::~Player()
{
    fclose(output_check);
}


void Player::set_pos(Core_Engine& core)
{
    bool found =false;
    int counting=1;
    //int c_x, c_y;
    int rand_x, rand_y;

    if(core.game_data.dungeon_level[y][x].block_type!='.')
    {
        core.game_data.dungeon_level[y][x].player_loc=false;
        while(!found)
        {
             rand_x= rand()%(MAX_X-1);
             rand_y=rand()%(MAX_Y);
             if(core.game_data.dungeon_level[rand_y][rand_x].block_type=='.')
             {
                 found=true;

                 x=rand_x;
                 y=rand_y;
                 core.game_data.dungeon_level[y][x].player_loc=true;
             }

        }
    }else
    {
        core.game_data.dungeon_level[y][x].player_loc=true;
    }

}

void Player::set_pos(Core_Engine& core,int new_x,int new_y)
{

    core.game_data.dungeon_level[y][x].player_loc=false;
    x=new_x;
    y=new_y;
    core.game_data.dungeon_level[y][x].player_loc=true;
}


void Player::load_xp_system()
{
    //required_experience[0]= 0;
    for (int i=0;i<MAX_PC_LEVEL+1;i++)
    {
        required_experience[i]= i*100;
    }


}

bool Player::gain_xp(int xp)
{
    stats.exp+=xp;
    if(stats.exp >= required_experience[stats.level])
    {
        //stats.level++;
        raise_level();
        return true; // gained a level
    }
    return false;
}

void Player::raise_level()
{
    stats.level++;
    stats.max_hp+= 10+ (int)ceil(stats.stam*.25);
    stats.stam+=1;
    stats.str+=1;
    stats.dex+=1;
    stats.intel+=1;
    stats.hp=stats.max_hp;
    return;
}

bool Player::player_input(Core_Engine& core)
{
        bool player_moved=false;
                        
        



        if (core.input.KEY_PAGEUP == 1 && core.input.KEY_PAGEUP_up == true)
        {
            core.input.KEY_PAGEUP_up = false;
            invincible = !invincible;
            WTW = !WTW;
            for (int i = 0; i < NUM_SPELLS; i++)
            {
                //known_spells[i] = true;
            }
           core.ui_display.Add_ui_message_printf({ 50,215,150 }, 27, "testing %d, %s", 2, "invincible!");
            //ui_display.Add_ui_message_printf({ 50,215,150 }, 27, "testing %d, %s", 1, "walk through walls enables!");
        }
        else if (core.input.KEY_PAGEUP == -1)
        {
            core.input.KEY_PAGEUP_up = true;
        }

        //save game (left control and s)
        if (core.input.KEY_LCTRL == 1 && core.input.KEY_LCTRL_up == true && core.input.KEY_s == 1 && core.input.KEY_s_up == true)
        {
            core.input.KEY_LCTRL_up = false;
            core.input.KEY_s_up = false;
            game_saved = true;

            /************************************
            *           save game function      *
            *           in play.ccp             *
            ************************************/

            return false;
            //invincible = !invincible;
        }
        else if ((core.input.KEY_LCTRL == -1) && (core.input.KEY_s == -1))
        {
            core.input.KEY_LCTRL_up = true;
                core.input.KEY_s_up = true;
        }

        //F1 command to equip weapon
        if (core.input.KEY_LCTRL == 1 && core.input.KEY_LCTRL_up == true && core.input.KEY_x == 1 && core.input.KEY_x_up == true)
        {
            
            core.input.KEY_LCTRL_up = false;
            core.input.KEY_x_up = false;
            equipping_weapon = true;
            equipping_armor = false;
            player_input_states = PLAYER_EQUIPPING;
            //printf("player core.input state changed = %d\n", player_core.input_states);
            //if (!inventory.empty())
            //{
            //    core.ui_display.Add_ui_message_long("Enter the letter of the weapon to equip Or enter \\ to cancel.", { 35,55,128 },40);
            //    //old//ui_display.Add_ui_message_long("weapon to equip:", { 35,55,128 });
            //    //old//ui_display.Add_ui_message_long("Or enter \\ to cancel.", { 35,55,0 });
            //}
            //else
            //{ 
            //   //not yet// ui_display.Add_ui_message_long("You have no items, you poor unfortunate soul!", { 35,55,255 });
            //    player_input_states = PLAYER_MOVEMENT;
            //}
        }
        else if ((core.input.KEY_LCTRL == -1) && (core.input.KEY_x == -1))
        {
            core.input.KEY_LCTRL_up = true;
            core.input.KEY_x_up = true;
        }
        //(left control and z)
        if (core.input.KEY_LCTRL == 1 && core.input.KEY_LCTRL_up == true && core.input.KEY_z == 1 && core.input.KEY_z_up == true)
        {

            core.input.KEY_LCTRL_up = false;
            core.input.KEY_z_up = false;
            equipping_weapon = false;
            equipping_armor = true;
            player_input_states = PLAYER_EQUIPPING;
            //printf("player core.input state changed = %d\n", player_core.input_states);
            //if (!inventory.empty())
            //{
            //    core.ui_display.Add_ui_message_long("Enter the letter of the armor to wear or \\ to cancel!", { 0,255,0 }, 35);
            //   //old //ui_display.Add_ui_message_long("weapon to equip:", { 35,55,128 });
            //   //old //ui_display.Add_ui_message_long("Or enter \\ to cancel.", { 35,55,0 });
            //}
            //else
            //{
            //    core.ui_display.Add_ui_message_long("You have no items, you poor unfortunate soul!", { 35,55,255 }, 30);
            //    player_input_states = PLAYER_MOVEMENT;
            //}
        }
        else if ((core.input.KEY_LCTRL == -1) && (core.input.KEY_z == -1))
        {
            core.input.KEY_LCTRL_up = true;
            core.input.KEY_z_up = true;
        }

        if (core.input.KEY_LCTRL == 1 && core.input.KEY_LCTRL_up == true && core.input.KEY_d == 1 && core.input.KEY_d_up == true)
        {

            core.input.KEY_LCTRL_up = false;
            core.input.KEY_d_up = false;
            equipping_weapon = false;
            equipping_armor = false;
            dropping_item = true;
            entering_drop = true;

            player_input_states = PLAYER_EQUIPPING;

        }
        else if ((core.input.KEY_LCTRL == -1) && (core.input.KEY_d == -1))
        {
            core.input.KEY_LCTRL_up = true;
            core.input.KEY_d_up = true;
        }

        //cast a spell (left control and c)
        if (core.input.KEY_LCTRL == 1 && core.input.KEY_LCTRL_up == true && core.input.KEY_c  == 1 && core.input.KEY_c_up == true)
        {
            core.input.KEY_LCTRL_up = false;
            core.input.KEY_c_up = false;
            //printf("casting\n");
            //casting_spell = true;
            if (stats.mp > 0)
            {
                //not yet//ui_display.Add_ui_message_long("Enter the spell code:");
                //core.input.key_value = ' ';
                stats.mp -= 1;
                player_input_states = PLAYER_CASTING;

            }
            else
            {
                core.ui_display.Add_ui_message_long("Need more magic.");
            }


            //return false;

        }
        else if ((core.input.KEY_LCTRL == -1) && (core.input.KEY_c == -1))
        {
            core.input.KEY_LCTRL_up = true;
            core.input.KEY_c_up = true;
        }

        //demO spell description (left control and j
        if (core.input.KEY_LCTRL == 1 && core.input.KEY_LCTRL_up == true && core.input.KEY_j == 1 && core.input.KEY_j_up == true)
        {
            core.input.KEY_LCTRL_up = false;
            core.input.KEY_j_up = false;
            //not yet//std::string s(spells.speldescript[1]);
            //not yet//ui_display.Add_ui_message_long(s);

            return false;
            //invincible = !invincible;
        }
        else if ((core.input.KEY_LCTRL == -1) && (core.input.KEY_j == -1))
        {
            core.input.KEY_LCTRL_up = true;
            core.input.KEY_j_up = true;
        }
    
        //printf("\t\tplayer input state, %d\n", player_input_states);
    switch (player_input_states)
    {
        case 0://player movement state

                player_moved=player_movement_fun(core);
          
                //printf("\n player movement, %d\n", player_moved);
            if(player_moved)
            {
                build_proximity_matrix(core);
                core.game_data.time_ticks++;
                if (core.game_data.time_ticks >= 100)
                {
                    core.game_data.time_elapsed++;
                    core.game_data.time_ticks = 0;
                    //add decrease spell effects
                    //add status effect time checks
                     
                }
               // printf("\n complete level load 111\n");
            }else if(hit_monster)//if(hit_id!=-1)
            {
                 player_fight_fun(core);
                 player_moved=true;
               //  printf("\n complete level load 112\n");
            }
         //   printf("\n complete level load 10\n");
        break;
        case 1://player cast state
            //player_on_object_fun(core.input,game_data,objects,play_state,build_level,monster,ui_display);
           //printf("going to casting\n");
           // printf("return = %d\n\tkey=%d\n", core.input.KEY_RETURN, core.input.key_value);
            if (!spell_cast_msg_displayed)
            {
                core.ui_display.Add_ui_message_long("Casting spell, Enter the Spell Code:");
                spell_cast_msg_displayed = true;
            }
                player_casting_fun(core);
            //printf("wtf?\n");
        break;
        case 2://player equipping state
            //if (equipping_weapon) {

            //    player_equipping_fun(core, equipping_weapon);
            //}else if (equipping_armor)
            //{
            //    
            //    player_equipping_fun(core, equipping_armor);
            //}
            //if (!inventory.empty())
            if(!core.inventory.is_empty())
            {
                //core.ui_display.Add_ui_message_long("You have items, but this isnt working yet!", { 35,55,255 }, 30);
                //player_input_states = PLAYER_MOVEMENT;
                
                if (!player_equipping_fun(core))
                {
                    //printf("player equiping\n");

                }
                else
                {
                    //core.ui_display.Add_ui_message_long("DROPPED6!", { 35,55,255 }, 30);
                    player_input_states = PLAYER_MOVEMENT;
                    //printf("player_state=%d\n", player_input_states);
                }
            }
            else
            {
                core.ui_display.Add_ui_message_long("You have no items, you poor unfortunate soul!", { 35,55,255 }, 30);
                player_input_states = PLAYER_MOVEMENT;
            }

            //printf("out equip 3\n");
            break;
        case 3://player on object
            if (player_on_object_fun_new(core))
            {
                //printf("\n player obejcts\n");
            }
            else
            {
                player_input_states = PLAYER_MOVEMENT;
                object_ignore = true;
            }
        break;
    }
    //printf("wtf2?\n");
    update_spell_effects(core);

    //printf("end of player_core.input\n");
    //printf("end of player_core.input, player_moved=%d\n", player_moved);
    return player_moved ;
}

void Player::update_spell_effects(Core_Engine& core)
{

    int past_ticks, past_elapsed;
    int update;
    for (int i = 0; i < NUM_SPELL_EFFECTS; i++)
    {
        update = 0;
        past_ticks = core.game_data.time_ticks - effects_time[i][0];
        past_elapsed = core.game_data.time_elapsed - effects_time[i][1];
        if ((past_elapsed > 0) && (past_ticks > 0))
        {
            update = 1;
            effects_time[i][0] = core.game_data.time_ticks;
            effects_time[i][1] = core.game_data.time_elapsed;
        }
        if ((effects_durations[i] > 0)&&(update==1))
        {
            effects_durations[i]--;
        }
    }
    //hp regen
    update = 0;
    past_ticks = core.game_data.time_ticks - hp_mp_regen_time[0][0];
    past_elapsed = core.game_data.time_elapsed - hp_mp_regen_time[0][1];
    if ((past_elapsed > 0) && (past_ticks > 0))
    {
        update = 1;
        hp_mp_regen_time[0][0] = core.game_data.time_ticks;
        hp_mp_regen_time[0][1] = core.game_data.time_elapsed;
    }
    if ( (update == 1))
    {
        hp_mp_regen[0] += hp_mp_regen_rate[0];
        if (hp_mp_regen[0] >= 1)
        {
            hp_mp_regen[0] = 0.0;
            stats.hp += 1;
            if (stats.hp > stats.max_hp)
            {
                stats.hp = stats.max_hp;
            }

        }
    }
    //mp regen
    update = 0;
    past_ticks = core.game_data.time_ticks - hp_mp_regen_time[1][0];
    past_elapsed = core.game_data.time_elapsed - hp_mp_regen_time[1][1];
    if ((past_elapsed > 0) && (past_ticks > 0))
    {
        update = 1;
        hp_mp_regen_time[1][0] = core.game_data.time_ticks;
        hp_mp_regen_time[1][1] = core.game_data.time_elapsed;
    }
    if ((update == 1))
    {
        hp_mp_regen[1] += hp_mp_regen_rate[1];
        if (hp_mp_regen[1] >= 1)
        {
            hp_mp_regen[1] = 0.0;
            stats.mp += 1;
            if (stats.mp > stats.max_mp)
            {
                stats.mp = stats.max_mp;
            }

        }
    }



    recalc_all();
}

void Player::recalc_all()
{
    int prot = 0;
    
    if ((effects_durations[0] > 0) || (effects_durations[0] == -1))
    {
        prot=2;
    }
    
    if (current_weapon_index >= 0)
    {
        stats.attack_power = stats.base_attack + inventory[current_weapon_index].bonus + inventory[current_weapon_index].bonus + ((stats.dex - 10) / 2);
        
        stats.damage = stats.base_damage + inventory[current_weapon_index].damage + inventory[current_weapon_index].bonus + ((stats.str - 10) / 2);
    }
    else
    {
        stats.attack_power = stats.base_attack  + ((stats.dex - 10) / 2);
        
        stats.damage = stats.base_damage  + ((stats.str - 10) / 2);
    }
    if (current_armor_index >= 0)
    {
        stats.defense = stats.base_defense + inventory[current_armor_index].bonus + +inventory[current_armor_index].armor + ((stats.dex - 10) / 2) + prot;
    }
    else
    {
        stats.defense = stats.base_defense + ((stats.dex - 10) / 2) + prot;
    }
    

}


void Player::player_casting_fun(Core_Engine& core)
{
    
    char spell_char;
    
    //int spell_index=-1;
   // printf("casting2\n");
   //if(!casting_spell)
   // {
    if (core.spells.spell_index == -1)
    {
       // printf("casting2\n");
        if (core.input.any_keys_down())
        {
            /**********************
            core.input.set_all_keys_down(); makes sure that the core.input key isnt read a second time.
            ************************/
            //printf("casting2\n");

            core.input.set_all_keys_down();
            spell_char = core.input.key_value;
            printf("spell_char=%c %d\n", spell_char, spell_char);
            core.spells.spell_index = core.spells.build_spell(spell_char);
            printf("spell_index=%i\n", core.spells.spell_index);

            if (core.spells.spell_index != -1)
            {
                //ui_display.Add_ui_message_long(spells.speldescript[spell_index]);
                //player_core.input_states = PLAYER_MOVEMENT;
                printf("%d\n", core.spells.spell_index);
                //casting_spell = true;
                if (player_casted_spell_fun(core, core.spells.spell_index))
                {
                    //stuff happens in player casted spell fun
                    //spell is complete when false
                }
                else
                {
                    core.spells.spell_index = -1;
                }
                // casting_spell = false;
                 //spell_index = -1;
            }
        }
        else if (core.input.all_keys_up())
        {
            //printf("here12345\n");
            core.input.set_all_keys_up();

        }
        //not yet//ui_display.reset_ttl(1);
    }
    else
    {
        //printf("%d\n", spells.spell_index);
        //casting_spell = true;
        if ((player_casted_spell_fun(core, core.spells.spell_index))&&(core.spells.spell_index<38))
        {
            //stuff happens in player casted spell fun
            //spell is complete when false
        }
        else
        {
            core.spells.spell_index = -1;
            core.spells.spell_description_displayed = false;
            core.spells.spell_tick = std::chrono::seconds(0);
            player_input_states = PLAYER_MOVEMENT;
            spell_cast_msg_displayed = false;
        }


    }
        //printf("%d\n", player_core.input_states);
        //printf("casting3\n");

    
        return;
}

bool Player::player_casted_spell_fun(Core_Engine& core, int spell_id)
{
    // COMPLETE THE WHAT HAPPENS WHEN A SPELL IS CAST
    //printf("%d - %s\n", spell_id, spells.speldescript[spell_id]);
    //ui_display.Add_ui_message_long(spells.speldescript[spell_id],{ 255,50,150 },40);
   // char selection = ' ';
    if (core.spells.spell_description_displayed == false)
    {
        player_cast_display_message(core, spell_id);
        core.spells.spell_description_displayed = true;
   }
       
    //player_core.input_states = PLAYER_MOVEMENT;
    
    bool spell_complete = true;
   // printf("spell id =%d, spell_complete=%d\n", spell_id, spell_complete);
    switch (spell_id)
    {
        case 0:
            if (effects_durations[0] >= 0)
            {
                effects_durations[0] = 2;
                effects_time[0][0] = core.game_data.time_ticks;
                effects_time[0][1] = core.game_data.time_elapsed;
                player_input_states = PLAYER_MOVEMENT;
                spell_complete = false;
            }
            break;
        case 1:
            //casting_spell = true;
           // printf("magic missle\n");
            if (casting_selection == ' ')
            {
                casting_selection = player_casting_selection(core, spell_id);
                //add code to limit selection to only the direction keys
            }
            else
            {
                casting_selection = casting_los_spell(core, spell_id,casting_selection);
                //casting_selection = ' ';
                if (casting_selection == ' ')
                {
                    player_input_states = PLAYER_MOVEMENT;
                    spell_complete = false;
                }
            }
            //casting_spell = false;
            break;
        case 37:
            if (effects_durations[0] >= 0)
            {
                effects_durations[0] = -1;
            }
            known_spells[37] = false;
            player_input_states = PLAYER_MOVEMENT;
            spell_complete = false;
            break;
        default:
        {
            player_input_states = PLAYER_MOVEMENT;
            spell_complete = false;
        }
    }
    //printf("spell id =%d, spell_complete=%d\n", spell_id, spell_complete);
    return spell_complete;
}

char Player::casting_los_spell(Core_Engine& core, int spell_id, char selection)
{
    //int length = 0;
    //int damage = 0;
 

    time_t now = time(NULL);
    //printf("moving spell, ymod%d xmod%d\n",spells.spell_y_mod,spells.spell_x_mod);
    double t_diff = (difftime(now, core.spells.start_time));
    std::chrono::time_point<std::chrono::system_clock> current = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = current - core.spells.spell_start_time;
    //n = sprintf(str, "time:%f", t_diff);
   // disp.Disp_Text_Wrapped(str, FONT_1, { 0,128,128 }, 500, 750);
   // ui_display.Add_ui_message_printf({ 0,128,128 }, 75, "time:%f,x=%d,y=%d,xmod=%d,ymod=%d,ticks=%f", elapsed_seconds, spells.spell_x, spells.spell_y, spells.spell_x_mod, spells.spell_y_mod, spells.spell_tick);

    //if (spells.spell_duration[spell_id] > (difftime(now, spells.start_time)))
    if (core.spells.spell_duration[spell_id] > elapsed_seconds)
    {
        if (elapsed_seconds > core.spells.spell_tick)
        {
            core.game_data.dungeon_level[core.spells.spell_y][core.spells.spell_x].spell = false;
            core.spells.spell_x += core.spells.spell_x_mod;
            core.spells.spell_y += core.spells.spell_y_mod;
            if (core.spells.spell_x >= MAX_X - 1)
            {
                core.spells.spell_x = MAX_X - 1;
                selection = ' ';
                core.game_data.dungeon_level[core.spells.spell_y][core.spells.spell_x].spell = false;
            }
            else if (core.spells.spell_x < 0)
            {
                core.spells.spell_x = 0;
                selection = ' ';
                core.game_data.dungeon_level[core.spells.spell_y][core.spells.spell_x].spell = false;
            }
            if (core.spells.spell_y >= MAX_Y - 1)
            {
                core.spells.spell_y = MAX_Y - 1;
                selection = ' ';
                core.game_data.dungeon_level[core.spells.spell_y][core.spells.spell_x].spell = false;
            }
            else if (core.spells.spell_y < 0)
            {
                core.spells.spell_y = 0;
                selection = ' ';
                core.game_data.dungeon_level[core.spells.spell_y][core.spells.spell_x].spell = false;
            }
            if (core.game_data.dungeon_level[core.spells.spell_y][core.spells.spell_x].block_type == '#')
            {
                selection = ' ';
                core.game_data.dungeon_level[core.spells.spell_y][core.spells.spell_x].spell = false;
                
                int wall_strength = rand() % 20 + 1;
                if ((core.spells.spell_y > 0) && (core.spells.spell_y < (MAX_Y - 1)) && (core.spells.spell_x > 0) && (core.spells.spell_x < (MAX_X - 1)) && (core.spells.spell_damage[spell_id] >= wall_strength))
                {
                    core.ui_display.Add_ui_message_printf({ 0,128,128 }, 95, "You hit the wall with your %s and destroyed it!", core.spells.spellname[spell_id]);
                    core.game_data.dungeon_level[core.spells.spell_y][core.spells.spell_x].block_type = '.';
                    core.game_data.dungeon_level[core.spells.spell_y][core.spells.spell_x].color = GREEN;
                }
                else
                {
                    core.ui_display.Add_ui_message_printf({ 0,128,128 }, 95, "You hit the wall with your %s.", core.spells.spellname[spell_id]);
                }
            }
            else if (core.game_data.dungeon_level[core.spells.spell_y][core.spells.spell_x].monster)
            {

               //notyet// core.ui_display.Add_ui_message_printf({ 0,128,128 }, 75, "You hit %s with your %s", monster.level_monsters[game_data.dungeon_level[spells.spell_y][spells.spell_x].monster_index].name, spells.spellname[spell_id]);
                selection = ' ';
                core.game_data.dungeon_level[core.spells.spell_y][core.spells.spell_x].spell = false;
                printf("monster hit by spell\n");
               //monsters not yet// monster.level_monsters[game_data.dungeon_level[spells.spell_y][spells.spell_x].monster_index].hp -= spells.spell_damage[spell_id];
                printf("monster hit by spell, damge removed\n");
                //if (monster.level_monsters[game_data.dungeon_level[spells.spell_y][spells.spell_x].monster_index].hp<=0)
                //{
                //    printf("monster hit by spell,killed\n");
                //    killed_monster(core.input, game_data, objects, play_state, build_level, monster, ui_display, game_data.dungeon_level[spells.spell_y][spells.spell_x].monster_index);
                //}
                    
            }
            else if(selection!= ' ')
            {
                core.game_data.dungeon_level[core.spells.spell_y][core.spells.spell_x].spell = true;
            }
            
            core.spells.spell_tick += core.spells.spell_tick_interval[spell_id];
        }
    }
    else
    {
        selection = ' ';
        core.game_data.dungeon_level[core.spells.spell_y][core.spells.spell_x].spell = false;
    }



    return selection;
}

void Player::player_cast_display_message(Core_Engine& core, int spell_id)
{
    //ui_display.Add_ui_message_long(spells.speldescript[spell_id], { 255,50,150 }, 40);
    switch (spell_id)
    {
    case 0:
        core.ui_display.Add_ui_message_long("You cast Protection!", { 255,50,150 }, 40);
        break;
    case 1:
        core.ui_display.Add_ui_message_long("You cast Magic Missle!", { 255,50,150 }, 40);
        core.ui_display.Add_ui_message_long("Select A Direction:", { 255,50,150 }, 40);
        break;
    case 37:

        break;
    }
    
    return;
}


char Player::player_casting_selection(Core_Engine& core, int spell_id)
{
   
   // get the spell direction and return the character 
    //defualt to this case
    char selection = ' ';


    //printf("here direction\n");

    if (core.input.any_keys_down())
    {
        /**********************
        core.input.set_all_keys_down(); makes sure that the core.input key isnt read a second time.
        ************************/
        core.input.set_all_keys_down();
        selection = core.input.key_value;
        printf("spell direction=%c\n", selection);
    }
    else if (core.input.all_keys_up())
    {
        //printf("here12345\n");
        core.input.set_all_keys_up();

    }
    switch (selection)
    {
        case 'd':
            core.spells.spell_y_mod = 0;
            core.spells.spell_x_mod = 1;
            printf("d\n");
            break;
        case 'a':
            core.spells.spell_y_mod = 0;
            core.spells.spell_x_mod = -1;
            printf("a\n");
            break;
        case 'w':
            core.spells.spell_y_mod = -1;
            core.spells.spell_x_mod = 0;
            printf("w\n");
            break;
        case 's':
            core.spells.spell_y_mod = 1;
            core.spells.spell_x_mod = 0;
            printf("s\n");
            break;


    }


    core.spells.spell_x = x;
    core.spells.spell_y = y;





    if (selection != ' ')
    {
        core.spells.start_time = time(NULL);
        core.spells.spell_start_time = std::chrono::system_clock::now();
        spell_char = core.spells.spell_character[spell_id];
        spell_color = core.spells.spell_color[spell_id];
        //printf("%c\n", spell_char);
        core.game_data.dungeon_level[core.spells.spell_y][core.spells.spell_x].spell = true;
        core.spells.spell_tick += core.spells.spell_tick_interval[spell_id];

       // printf("spell direction=%c,spell_index=%d,spell_tick=%f\n", selection, spell_id, spells.spell_tick);


    }

    return selection;
}









int Player::mouse_direction(Core_Engine& core, int move_x, int move_y)
{
    int NS, EW;
    EW = move_x - x;
    NS = move_y - y;
        

        if ((NS == -1) && (EW == 0))
        {
            return P_UP;
        }
        else if ((NS == 1) && (EW == 0))
        {
            return P_DOWN;
        }
        else if ((NS == 0) && (EW == -1))
        {
            return P_LEFT;
        }
        else if ((NS == 0) && (EW == 1))
        {
            return P_RIGHT;
        }
        else if ((NS == -1) && (EW == -1))
        {
            return P_UL;
        }
        else if ((NS == 1) && (EW == 1))
        {
            return P_DR;
        }
        else if ((NS == 1) && (EW == -1))
        {
            return P_DL;
        }
        else if ((NS == -1) && (EW == 1))
        {
            return P_UR;
        }
        else
        {
            
            return -1;
        }
    
    
   
    return -1;
}

int Player::mouse_move(Core_Engine& core)
{
    int direction=-1;
    //if (!mouse_move_inprogress)
    //{
        if ((core.input.mouse_button_left == 1)&&(core.input.mouse_button_left_up==true))
        {
            mouse_x_move_target = ((core.input.mouse_x - MAP_X_OFFSET) / FONT_SIZE)+core.game_map.x_min;
            mouse_y_move_target = ((core.input.mouse_y - MAP_Y_OFFSET) / FONT_SIZE) + core.game_map.y_min;
            printf("x=%d,y=%d,mx=%d,my=%d\n", x, y, mouse_x_move_target, mouse_y_move_target);
            core.input.mouse_button_left_up = false;
            if (((x != mouse_x_move_target) && (y != mouse_y_move_target))|| ((x == mouse_x_move_target) && (y != mouse_y_move_target))|| ((x != mouse_x_move_target) && (y == mouse_y_move_target)))
            {
                direction = mouse_direction(core, mouse_x_move_target, mouse_y_move_target);
                    
                //mouse_move_inprogress = true;
                //mouse_moves = mouse_bfs(core, mouse_x_move_target, mouse_y_move_target);
            }
        }
        else if (core.input.mouse_button_left == -1)
        {
            core.input.mouse_button_left_up = true;
            direction = -1;
                
        }
   
    return direction;
}



bool Player::player_movement_fun(Core_Engine& core)
{
      bool player_move_fun=false;
      int n;
      char str[UI_MESSAGE_MAX_SIZE];

      int direction;
      

      if ((direction = mouse_move(core))>-1)
      {
          //fprintf(output_check, "direction:=%d\n", direction);
          //printf("direction mouse=%d\n", direction);
      }
      else
      {
          direction = player_direction(core);
      }
      

        if (direction!=P_NONE)
        {
            move_count++;
            if(move_count>=6)
            {
                found_gold=false;
                move_count=0;
            }
            player_move_fun=false;
        }

        //printf("****direction=%d\n", direction);
      switch (direction)
      {
         
         case P_DOWN:
         {

             if(y+1>MAX_Y-1)
             {
                 mouse_y_move_target = core.player.y;
                 return false;
             }
             else if((core.game_data.dungeon_level[y+1][x].monster_index!=-1))
            {
                  printf("\n hit a monster\n");
                  hit_monster=true;
                  hit_id= core.game_data.dungeon_level[y+1][x].monster_index;
                  mouse_y_move_target = core.player.y;
            }
            else if((core.game_data.dungeon_level[y+1][x].block_type=='.')||(WTW))
             {
                 core.game_data.dungeon_level[y][x].player_loc=false;
                 y++;
                 if(y>=MAX_Y-1)
                 {
                     y=MAX_Y-1;
                 }
                 core.game_data.dungeon_level[y][x].player_loc=true;
                 object_ignore=false;
                 player_move_fun=true;
                 msg_sent = false;
             }
            break;
         }
         case P_UP:
         {
             //printf("mouse move 6\n");
             if(y<=0)
             {
                // printf("mouse move 7\n");
                 mouse_y_move_target = core.player.y;
                 return false;
             }else if((core.game_data.dungeon_level[y-1][x].monster_index!=-1))
            {
                 // printf("\n hit a monster\n");
                  hit_monster=true;
                  hit_id= core.game_data.dungeon_level[y-1][x].monster_index;
                  mouse_y_move_target = core.player.y;
            }
             else if((core.game_data.dungeon_level[y-1][x].block_type=='.')||(WTW))
             {
                 //printf("mouse move 8\n");
                 core.game_data.dungeon_level[y][x].player_loc=false;
                 y--;
                 if(y<=0)
                 {
                     y=0;
                 }
                 core.game_data.dungeon_level[y][x].player_loc=true;
                 object_ignore=false;
                 player_move_fun=true;
                 msg_sent = false;
             }

            break;
         }
         case P_RIGHT:
         {
             if(x>=MAX_X-1)
             {
                 mouse_x_move_target = core.player.x;
                 return false;
             }else if((core.game_data.dungeon_level[y][x+1].monster_index!=-1))
            {
                  printf("\n hit a monster\n");
                  hit_monster=true;
                  hit_id= core.game_data.dungeon_level[y][x+1].monster_index;
                  mouse_x_move_target = core.player.x;
            }
             else if((core.game_data.dungeon_level[y][x+1].block_type=='.')||(WTW))
             {

                 core.game_data.dungeon_level[y][x].player_loc=false;
                 x++;
                 core.game_data.dungeon_level[y][x].player_loc=true;
                 object_ignore=false;
                 player_move_fun=true;
                 msg_sent = false;
             }
            break;
         }
         case P_LEFT:
         {
             if(x<=0)
             {
                 mouse_x_move_target = core.player.x;
                 return false;
             }else if((core.game_data.dungeon_level[y][x-1].monster_index!=-1))
            {
                  printf("\n hit a monster\n");
                  hit_monster=true;
                  hit_id= core.game_data.dungeon_level[y][x-1].monster_index;
                  mouse_x_move_target = core.player.x;
            }
             else if((core.game_data.dungeon_level[y][x-1].block_type=='.')||(WTW))
             {

                 core.game_data.dungeon_level[y][x].player_loc=false;
                 x--;
                 core.game_data.dungeon_level[y][x].player_loc=true;
                 object_ignore=false;
                 player_move_fun=true;
                 msg_sent = false;
             }
            break;
         }
         case P_UR:
         {
             if((y<=0)||(x>=MAX_X-1))
             {
                 return false;
             }else if((core.game_data.dungeon_level[y-1][x+1].monster_index!=-1))
            {
                  printf("\n hit a monster\n");
                  hit_monster=true;
                  hit_id= core.game_data.dungeon_level[y-1][x+1].monster_index;
            }
             else if((core.game_data.dungeon_level[y-1][x+1].block_type=='.')||(WTW))
             {

                 core.game_data.dungeon_level[y][x].player_loc=false;
                 x++;
                 y--;
                 core.game_data.dungeon_level[y][x].player_loc=true;
                 object_ignore=false;
                 player_move_fun=true;
                 msg_sent = false;
             }
            break;
         }
         case P_UL:
         {
             if((y<=0)||(x<=0))
             {
                 return false;
             }else if((core.game_data.dungeon_level[y-1][x-1].monster_index!=-1))
            {
                  printf("\n hit a monster\n");
                  hit_monster=true;
                  hit_id= core.game_data.dungeon_level[y-1][x-1].monster_index;
            }
             else if((core.game_data.dungeon_level[y-1][x-1].block_type=='.')||(WTW))
             {

                 core.game_data.dungeon_level[y][x].player_loc=false;
                 x--;
                 y--;
                 core.game_data.dungeon_level[y][x].player_loc=true;
                 object_ignore=false;
                 player_move_fun=true;
                 msg_sent = false;
             }
            break;
         }
         case P_DL:
         {
             if((y+1>MAX_Y-1)||(x<=0))
             {
                return false;
             }else if((core.game_data.dungeon_level[y+1][x-1].monster_index!=-1))
            {
                  printf("\n hit a monster\n");
                  hit_monster=true;
                  hit_id= core.game_data.dungeon_level[y+1][x-1].monster_index;
            }
             else if((core.game_data.dungeon_level[y+1][x-1].block_type=='.')||(WTW))
             {
                 core.game_data.dungeon_level[y][x].player_loc=false;
                 x--;
                 y++;
                 core.game_data.dungeon_level[y][x].player_loc=true;
                 object_ignore=false;
                 player_move_fun=true;
                 msg_sent = false;
             }
            break;
         }
         case P_DR:
         {
             if((y+1>MAX_Y-1)||(x>=MAX_X-1))
             {
                 return false;
             }else if((core.game_data.dungeon_level[y+1][x+1].monster_index!=-1))
            {
                  printf("\n hit a monster\n");
                  hit_monster=true;
                  hit_id= core.game_data.dungeon_level[y+1][x+1].monster_index;
            }
             else if((core.game_data.dungeon_level[y+1][x+1].block_type=='.')||(WTW))
             {

                 core.game_data.dungeon_level[y][x].player_loc=false;
                 x++;
                 y++;
                 core.game_data.dungeon_level[y][x].player_loc=true;
                 object_ignore=false;
                 player_move_fun=true;
                 msg_sent = false;
             }
            break;
         }
      }
    if(hit_monster)
    {
        //ui_display.Add_ui_message("you hit a monster");
       // n=sprintf(str,"you hit a %s with id=%d",monster.level_monsters[hit_id].name,hit_id);
        //ui_display.Add_ui_message(str);
    }

    if((core.game_data.dungeon_level[y][x].gold))
    {
        stats.gold+= core.game_data.dungeon_level[y][x].gold_value;
        gold_found_value= core.game_data.dungeon_level[y][x].gold_value;
        n=sprintf(str," ");
        core.ui_display.Add_ui_message(str);
        n=sprintf(str,"You have found %d gold!", core.game_data.dungeon_level[y][x].gold_value);
        core.ui_display.Add_ui_message(str, {255,215,0});
        found_gold=true;
        core.game_data.dungeon_level[y][x].gold=false;
        move_count=0;
        mouse_y_move_target = core.player.y;
        mouse_x_move_target = core.player.x;
    }
    //if((game_data.dungeon_level[y][x].object)&& (!object_ignore))
    if ((core.game_data.dungeon_level[y][x].object) && (!object_ignore))
    {
        /*  update this code to not pause when on an object*/

      
        player_input_states=PLAYER_ON_OBJECT;
        mouse_y_move_target = core.player.y;
        mouse_x_move_target = core.player.x;
        mouse_move_inprogress = false;


        //moving to new function
       // on_object = true;
       // player_on_object_fun(core.input, game_data, objects, play_state, build_level, monster, ui_display);
       //// printf("\n complete level load 8\n");
       // if (!msg_sent)
       // {
       //    // printf("\n complete level load 8.1\n");
       //     for(int i=0;i<5;i++)
       //     {
       //         if(strcmp(objects.object_data_list[game_data.dungeon_level[y][x].object_index].text[i]," ")!=0)
       //         {
       //            ui_display.Add_ui_message(objects.object_data_list[game_data.dungeon_level[y][x].object_index].text[i], { 255,255,0 });
       //         }
       //         
       //     }
       //     msg_sent = true;
       // }
       // printf("\n complete level load 8.2\n");
    }
    else
    {
        //on_object=false;
    }
   // printf("\n complete level load 8\n");
    return player_move_fun;

}



bool Player::player_on_object_fun_new(Core_Engine& core)
{
    bool complete =false;
    //int num_lines = 0;
    //bool msg_sent = false;
    std::string a;
    
   // printf("object id = %d %d\n", game_data.dungeon_level[y][x].object_index, OENTRANCE);
    if (!msg_sent)
      {
        if (core.game_data.dungeon_level[y][x].object_index <= 32)
        {
            num_lines = display_object_message_enviroment(core, core.game_data.dungeon_level[y][x].object_index);
        }
        else
        {
            num_lines = display_object_message_item(core, core.game_data.dungeon_level[y][x].object_index);
        }
        
        msg_sent = true;
        object_ignore = false;
          //complete = true;
      }

    if (core.game_data.dungeon_level[y][x].object_index <= 32)
    {
        complete = object_handling_enviroment(core, core.game_data.dungeon_level[y][x].object_index);
    }
    else
    {
        complete = object_handling_item(core, core.game_data.dungeon_level[y][x].object_index);
    }
   // complete = object_handling(core.input, game_data, objects, play_state, build_level, monster, ui_display, game_data.dungeon_level[y][x].object_index);
    if (!complete)
    {
        msg_sent = false;
        num_lines = 0;
    }
    return complete;

} 


int Player::display_object_message_enviroment(Core_Engine& core, int object_id)
{
    int num_lines_1, num_lines_2;
   //not yet// core.ui_display.Add_ui_message_printf({ 120,0,120 }, 40, "You have found %s.", objects.object_names[game_data.dungeon_level[y][x].object_index].c_str());
    //switch (object_id)
    //{
        //case core.game_data.OENTRANCE:
    printf("*******object_ib=%d*******\n", object_id);
        if(object_id== core.game_data.OENTRANCE)
        {
            num_lines_1 = core.ui_display.Add_ui_message_printf({ 120,0,120 }, 30, "You have found %s.", core.objects.object_names[core.game_data.dungeon_level[y][x].object_index].c_str());
            //Do you wish to enter ? (Y / N)
            num_lines_2 = core.ui_display.Add_ui_message_long("Do you wish to enter? (Y / N)", {25,125,25},30);
            //break;
        } else if (object_id == core.game_data.OSTAIRSDOWN)
        //case core.game_data.OSTAIRSDOWN: //> (downward stairs)
        {
            num_lines_1 = core.ui_display.Add_ui_message_printf({ 120,0,120 }, 30, "You have found %s.", core.objects.object_names[core.game_data.dungeon_level[y][x].object_index].c_str());
            //Do you wish to enter ? (Y / N)
            num_lines_2 = core.ui_display.Add_ui_message_long("Do you wish to go down? (Y / N)", { 25,125,25 }, 35);
            //break;
        } else if (object_id == core.game_data.OCLOSEDDOOR)
        //case core.game_data.OCLOSEDDOOR: //> (downward stairs)
        {
            num_lines_1 = core.ui_display.Add_ui_message_printf({ 120,0,120 }, 30, "You have found %s.", core.objects.object_names[core.game_data.dungeon_level[y][x].object_index].c_str());
            //Do you wish to enter ? (Y / N)
            //core.ui_display.Add_ui_message_printf({ 120,0,120 }, 30, "object number %d.", core.game_data.dungeon_level[y][x].object_index);

            num_lines_2 = core.ui_display.Add_ui_message_long("Do you wish to open the door? (Y / N)", { 25,125,25 }, 30);
         //   break;
        }
        else if (object_id == core.game_data.OOPENDOOR)
       // case core.game_data.OOPENDOOR: //> (downward stairs)
        {
            num_lines_1 = core.ui_display.Add_ui_message_printf({ 120,0,120 }, 30, "You have found %s.", core.objects.object_names[core.game_data.dungeon_level[y][x].object_index].c_str());
            //Do you wish to enter ? (Y / N)
            num_lines_2 = core.ui_display.Add_ui_message_long("Do you wish to close the door? (Y / N)", { 25,125,25 }, 30);
           // break;
        }
        else if (object_id == core.game_data.ODNDSTORE)
            // case core.game_data.OOPENDOOR: //> (downward stairs)
        {
            num_lines_1 = core.ui_display.Add_ui_message_printf({ 120,0,120 }, 30, "You have found %s.", core.objects.object_names[core.game_data.dungeon_level[y][x].object_index].c_str());
            //Do you wish to enter ? (Y / N)
            num_lines_2 = core.ui_display.Add_ui_message_long("Do you wish to enter? (Y / N)", { 25,125,25 }, 30);
            // break;
        }
        else if (object_id == core.game_data.OTRADEPOST)
        {
            num_lines_1 = core.ui_display.Add_ui_message_printf({ 120,0,120 }, 30, "You have found %s.", core.objects.object_names[core.game_data.dungeon_level[y][x].object_index].c_str());
            //Do you wish to enter ? (Y / N)
            num_lines_2 = core.ui_display.Add_ui_message_long("Do you wish to enter? (Y / N)", { 25,125,25 }, 30);
            // break;
        }
        else if (object_id == core.game_data.OBANK)
        {
            num_lines_1 = core.ui_display.Add_ui_message_printf({ 120,0,120 }, 30, "You have found %s.", core.objects.object_names[core.game_data.dungeon_level[y][x].object_index].c_str());
            //Do you wish to enter ? (Y / N)
            num_lines_2 = core.ui_display.Add_ui_message_long("Do you wish to enter? (Y / N)", { 25,125,25 }, 30);
            // break;
        }

        else
        {
            num_lines_1 = core.ui_display.Add_ui_message_long("nothing", { 25,125,25 }, 30);
            num_lines_2 = 0;
        }
    //}

        return (num_lines_1 + num_lines_2);
}

//void Player::display_object_message_item(Core_Engine& core, int object_id)
int Player::display_object_message_item(Core_Engine& core, int object_id)
{
    int num_lines_1, num_lines_2;
    num_lines_1 = core.ui_display.Add_ui_message_printf(core.objects.object_color[4], 40, "You have found %s.", core.objects.object_names[core.game_data.dungeon_level[y][x].object_index].c_str());
    num_lines_2=core.ui_display.Add_ui_message_long("Do you wish to pick it up (Y/N)?", { 25,125,25 }, 35);
    return (num_lines_1 + num_lines_2);
}



bool Player::object_handling_enviroment(Core_Engine& core, int object_id)
{
    //switch (object_id)
    //{
    //case core.game_data.OENTRANCE:
    core.ui_display.reset_ttl(num_lines);
    if(object_id== core.game_data.OENTRANCE)
    {
        //core.ui_display.reset_ttl(2);
        if (core.input.KEY_y == 1)
        {
            if (core.game_data.current_level == 0)
            {
                core.build_level.change_level(core, 1);
                set_pos(core, MAX_X / 2, MAX_Y - 2);
                core.play_state = DUNGEON;
                n = sprintf(str, "You have entered the Dungeon!");
                core.ui_display.Add_ui_message(str, { 255,0,255 });
                n = sprintf(str, " *** Hint:  Dont die! ****");
                core.ui_display.Add_ui_message(str, { 0,255,0 });
            }
            else
            {
                core.build_level.change_level(core, 0);
                set_pos(core, 3, 3);
                core.play_state = OVERWORLD;
            }
            return false;
        }
        if (core.input.KEY_n == 1)
        {
            return false;
        }
       // break;
    }else if (object_id == core.game_data.OSTAIRSDOWN)
   // case core.game_data.OSTAIRSDOWN: //> (downward stairs)
    {
        
        if (core.input.KEY_y == 1)
        {
            //object_ignore = true;
            //choice_made = true;
            //game_data.current_level+=1;
           // printf("level-complete srarting %d\n", game_data.current_level);
            core.build_level.change_level(core, core.game_data.current_level + 1);
            //printf("level-complete %d \n", game_data.current_level);
            n = sprintf(str, "game_level=%d", core.game_data.current_level);
            core.ui_display.Add_ui_message(str);
            // printf("added to ui message");
            set_pos(core);
            return false;
        }
        if (core.input.KEY_n == 1)
        {
            //object_ignore = true;
            //choice_made = true;
            return false;
        }
    //    break;
    }else if (object_id == core.game_data.OSTAIRSUP)
  //  case core.game_data.OSTAIRSUP: //> (downward stairs)
    {
        if (core.input.KEY_y == 1)
        {

            core.build_level.change_level(core, core.game_data.current_level - 1);
            //printf("level-complete %d \n", game_data.current_level);
            n = sprintf(str, "game_level=%d", core.game_data.current_level);
            core.ui_display.Add_ui_message(str);
            // printf("added to ui message");
            set_pos(core);
            return false;
        }
        if (core.input.KEY_n == 1)
        {
            //object_ignore = true;
            //choice_made = true;
            return false;
        }
   //     break;
    }     else if (object_id == core.game_data.OCLOSEDDOOR)
    {
        if (core.input.KEY_y == 1)
        {
            core.game_data.dungeon_level[y][x].object_index = core.game_data.OOPENDOOR;
            return false;
        }
        if (core.input.KEY_n == 1)
        {
            //object_ignore = true;
            //choice_made = true;
            return false;
        }
    //    break;
    }else if (object_id == core.game_data.OOPENDOOR)
   // case core.game_data.OOPENDOOR: //> (downward stairs)
    {
        if (core.input.KEY_y == 1)
        {
            core.game_data.dungeon_level[y][x].object_index = core.game_data.OCLOSEDDOOR;
            return false;
        }
        if (core.input.KEY_n == 1)
        {
            //object_ignore = true;
            //choice_made = true;
            return false;
        }
     //   break;
    }
    else if (object_id == core.game_data.ODNDSTORE)
    {
        if (core.input.KEY_y == 1)
        {
            //core.game_data.dungeon_level[y][x].object_index = core.game_data.OCLOSEDDOOR;
            core.previous = core.play_state;
            core.play_state = SHOP;
            core.shop.entering_shop = true;
            core.shop.entering_trading_post = false;
            core.shop.entering_bank = false;
            core.input.key_value = ' ';
            return false;
        }
        if (core.input.KEY_n == 1)
        {
            //object_ignore = true;
            //choice_made = true;
            return false;
        }
    }
    else if (object_id == core.game_data.OTRADEPOST)
    {
        if (core.input.KEY_y == 1)
        {
            //core.game_data.dungeon_level[y][x].object_index = core.game_data.OCLOSEDDOOR;
            core.previous = core.play_state;
            core.play_state = SHOP;
            core.shop.entering_shop = false;
            core.shop.entering_trading_post = true;
            core.shop.entering_bank = false;
            core.input.key_value = ' ';
            return false;
        }
        if (core.input.KEY_n == 1)
        {
            //object_ignore = true;
            //choice_made = true;
            return false;
        }
    }
    else if (object_id == core.game_data.OBANK)
    {
    if (core.input.KEY_y == 1)
    {
        //core.game_data.dungeon_level[y][x].object_index = core.game_data.OCLOSEDDOOR;
        core.previous = core.play_state;
        core.play_state = SHOP;
        core.shop.entering_shop = false;
        core.shop.entering_trading_post = false;
        core.shop.entering_bank = true;
        core.input.key_value = ' ';
        return false;
    }
    if (core.input.KEY_n == 1)
    {
        //object_ignore = true;
        //choice_made = true;
        return false;
    }
    }
    else if (object_id == core.game_data.OFOUNTAIN)
   // case core.game_data.OFOUNTAIN: //> (bubbling fountain)
    {
       /* if (core.input.KEY_y == 1)
        {
            game_data.dungeon_level[y][x].object_index = OCLOSEDDOOR;
            return false;
        }
        if (core.input.KEY_n == 1)
        {
            //object_ignore = true;
            //choice_made = true;
            return false;
        }*/
        return false;
    //    break;
    }
    else
    {
        //nothing here
    }

   // }

    



    return true;
}

bool Player::object_handling_item(Core_Engine& core, int object_id)
{
    core.ui_display.reset_ttl(num_lines);
    //printf("here1\n");
    if (core.input.KEY_y == 1)
    {

        core.game_data.dungeon_level[y][x].object_index = -1;
        core.game_data.dungeon_level[y][x].object = false;
        //inventory.push_back(item_list[object_id]);
        core.inventory.add_item_to_inventory(core.inventory.item_list[object_id]);
        //printf("%d %d\n", object_id, core.inventory.item_list[object_id].id);
        return false;
    }
    if (core.input.KEY_n == 1)
    {
        return false;
    }
   



    return true;
}


void Player::find_open_spot(Core_Engine& core, int open[])
{
    open[0] = -1;
    open[1] = -1;
   // printf("finding open \n");
    if ((core.game_data.dungeon_level[y][x].object == false) && (core.game_data.dungeon_level[y][x].block_type == '.'))
    {
        //printf("finding open i =%d, \n";
        open[0] = x;
        open[1] = y;
    }
    else
    {
        for (int i = (x - 1); i <= x + 1; i++)
        {
            for (int j = (y - 1); j <= y + 1; j++)
            {
                if ((i >= 0) && (i <= core.game_map.x_max))
                {
                    if ((j >= 0) && (j <= core.game_map.y_max))
                    {
                        if ((core.game_data.dungeon_level[j][i].object == false) && (core.game_data.dungeon_level[j][i].block_type == '.'))
                        {
                            //printf("finding open i =%d, \n";
                            open[0] = i;
                            open[1] = j;
                        }
                    }
                }
            }
        }
    }
    return;
}

bool Player::player_equipping_fun(Core_Engine& core)
{
    bool complete = false;
    //int num_lines = 0;
    //bool msg_sent = false;
    std::string a;

    // printf("object id = %d %d\n", game_data.dungeon_level[y][x].object_index, OENTRANCE);
    if (!msg_sent)
    {

            num_lines = display_equipping_message(core);

        msg_sent = true;
        //object_ignore = false;
        //complete = true;
    }

    core.ui_display.reset_ttl(num_lines);
    complete = handling_equipping_fun(core);
    if (complete)
    {
        msg_sent = false;
    }
    return complete;

}


int Player::display_equipping_message(Core_Engine& core)
{
    int num_lines_1=0;
    
    if (equipping_weapon)
    {
        num_lines_1 = core.ui_display.Add_ui_message_long("Enter the letter of the weapon to equip Or enter \\ to cancel.", { 35,55,128 }, 40);
    }
    else if (equipping_armor)
    {
        num_lines_1=core.ui_display.Add_ui_message_long("Enter the letter of the armor to wear or \\ to cancel!", { 0,255,0 }, 35);
    }
    else if (equipping_shield)
    {
     
    }else if (dropping_item)
    {
        num_lines_1 = core.ui_display.Add_ui_message_long("Enter the letter of item to drop!", { 0,255,0 }, 35);
    }

    //num_lines_1 = core.ui_display.Add_ui_message_printf(core.objects.object_color[4], 40, "You have found %s.", core.objects.object_names[core.game_data.dungeon_level[y][x].object_index].c_str());
    //num_lines_2 = core.ui_display.Add_ui_message_long("Do you wish to pick it up (Y/N)?", { 25,125,25 }, 35);
    return  num_lines_1;
}


bool Player::handling_equipping_fun(Core_Engine& core)
{
          int id;
          //int num_lines = 0;
          int n;
          //int invent_size;
          int equip_selection = -1;
          int open[2];
          
          if ((core.input.all_keys_up()) && (core.inventory.dropped == true))
          {
              //printf("here12345\n");
              //core.input.set_all_keys_up();
              entering_drop = false;
              core.inventory.dropped = false;
              //core.ui_display.Add_ui_message_long("here!", { 35,55,255 }, 30);
              return true;
          }
          equip_selection = equipment_selection(core);
          //invent_size = inventory.size();
          //printf("equip_sel%d\n", equip_selection);
          if (equipping_weapon)
          {
              if ((equip_selection >= 0)&&(equip_selection<core.inventory.inven_size))
              {
                  printf("id=%d,\n ", inventory[equip_selection].id);
                  id = inventory[equip_selection].id;
                  if ((inventory[equip_selection].is_weapon))
                  {
                      if (current_weapon_index >= 0)
                      {
                          inventory[current_weapon_index].is_equipped=false;
                      }

                      inventory[equip_selection].is_equipped = true;
                      current_weapon_index = equip_selection;
                      
                      n=core.ui_display.Add_ui_message_printf({ 250,0,120 }, 40, "You are weilding a %s!", core.objects.object_names[id].c_str());

                  }
                  else {
                      n = core.ui_display.Add_ui_message_long("Can not weild that is not a weapon!");
                  }

                  equipping_weapon = false;
                  equipping_armor = false;
                  equipping_shield = false;
                  num_lines = 0;
                  recalc_all();
                  msg_sent = false;
                  player_input_states = PLAYER_MOVEMENT;

              } else if (equip_selection == -10)
              {
                  core.ui_display.Add_ui_message_long("Equiping cancalled!");
                  equipping_weapon = false;
                  equipping_armor = false;
                  equipping_shield = false;
                  
                  player_input_states = PLAYER_MOVEMENT;
              }

              return true;
          }
          else if(equipping_armor)
          {
              if (equip_selection >= 0)
              {
                  printf("id=%d,\n ", inventory[equip_selection].id);
                  id = inventory[equip_selection].id;
                  if ((inventory[equip_selection].is_armor))
                  {
                      if (current_armor_index >= 0)
                      {
                          inventory[current_armor_index].is_equipped = false;
                      }

                      inventory[equip_selection].is_equipped = true;
                      current_armor_index = equip_selection;

                      n = core.ui_display.Add_ui_message_printf({ 250,0,120 }, 40, "You are wearing a %s!", core.objects.object_names[id].c_str());

                  }
                  else {
                      n = core.ui_display.Add_ui_message_long("Can not weild that is not a weapon!");
                  }

                  equipping_weapon = false;
                  equipping_armor = false;
                  equipping_shield = false;
                  num_lines = 0;
                  msg_sent = false;
                  recalc_all();

                  player_input_states = PLAYER_MOVEMENT;

              }
              else if (equip_selection == -10)
              {
                  equipping_weapon = false;
                  equipping_armor = false;
                  equipping_shield = false;
                  player_input_states = PLAYER_MOVEMENT;
              }
              //num_lines = 0;
              //recalc_all();
              return true;
          }
          else if (equipping_shield) 
          {
              if (equip_selection >= 0)
              {
                  printf("id=%d,\n ", inventory[equip_selection].id);
                  id = inventory[equip_selection].id;
                  if ((inventory[equip_selection].is_shield))
                  {
                      if (current_shield_index >= 0)
                      {
                          inventory[current_shield_index].is_equipped = false;
                      }

                      inventory[equip_selection].is_equipped = true;
                      current_shield_index = equip_selection;

                      n = core.ui_display.Add_ui_message_printf({ 250,0,120 }, 40, "You are carrying a %s!", core.objects.object_names[id].c_str());

                  }
                  else {
                      n = core.ui_display.Add_ui_message_long("Can not weild that is not a weapon!");
                  }

                  equipping_shield = false;
                  player_input_states = PLAYER_MOVEMENT;

              }
              else if (equip_selection == -10)
              {
                  equipping_weapon = false;
                  equipping_armor = false;
                  equipping_shield = false;
                  player_input_states = PLAYER_MOVEMENT;
              }
              recalc_all();
              return true;
          }
          else if (dropping_item)
          {
              find_open_spot(core, open);
              if (core.inventory.inven_next_item==0)
              {
                  core.inventory.dropped = true;
                  core.ui_display.Add_ui_message_long("You have no items to drop!", { 35,55,255 }, 30);
              }
              else if((open[0]==-1)&&(open[1]==-1))
              {
                  core.ui_display.Add_ui_message_long("Can't drop no empty ground!", { 35,55,255 }, 30);
                  return true;
              }
              else if ((core.inventory.inven[equip_selection].id == 0) && (equip_selection >=0))
              {
                  core.ui_display.Add_ui_message_long("Invalid Selection! Try again!", { 35,55,255 }, 30);
              }
              else if ((equip_selection >= 0) && (equip_selection < core.inventory.inven_size))
              {
                  //printf("drop id=%d,\n ", equip_selection);
                  
                  if (core.inventory.dropped == false)
                  {
                      //core.ui_display.Add_ui_message_long("dropped!", { 35,55,255 }, 30);
                      find_open_spot(core, open);
                      core.inventory.remove_item_from_inventory(core, equip_selection,open);
                  }
              }
              else if (equip_selection >= 0)
              {
                  core.ui_display.Add_ui_message_long("Invalid Selection! Try again!", { 35,55,255 }, 30);
              }

          }



          recalc_all();
          return false;


}


int Player::equipment_selection(Core_Engine& core)
{
    
    int equip_selection = -1;
    if (core.input.any_keys_down() && entering_drop == false)
    {
        /**********************
        core.input.set_all_keys_down(); makes sure that the core.input key isnt read a second time.
        ************************/
        core.input.set_all_keys_down();
        
        if (core.input.KEY_a == 1)
        {
            equip_selection = 0;
        }
        else if (core.input.KEY_b == 1)
        {
            equip_selection = 1;
        }
        else if (core.input.KEY_c == 1)
        {
            equip_selection = 2;
        }
        else if (core.input.KEY_d == 1)
        {
            equip_selection = 3;
        }
        else if (core.input.KEY_e == 1)
        {
            equip_selection = 4;
        }
        else if (core.input.KEY_f == 1)
        {
            equip_selection = 5;
        }
        else if (core.input.KEY_g == 1)
        {
            equip_selection = 6;
        }
        else if (core.input.KEY_BACKSLASH == 1)
        {
            equip_selection = -10;
        }
        else if (core.input.KEY_z == 1)
        {
            equip_selection = 26;
        }


    }
    else if (core.input.all_keys_up())
    {
        //printf("here12345\n");
        core.input.set_all_keys_up();
        entering_drop = false;
        core.inventory.dropped = false;    
    }



    //printf("equip_selection=%d\n", equip_selection);
    return equip_selection;
}

void Player::player_fight_fun(Core_Engine& core)
{
    int  n=0;
    int roll_value;
    char str[200];
    //printf("\nyou hit id %d,",hit_id);
    roll_value =rand() % 20 + 1;

    /*not yet*/
    if((stats.attack_power+roll_value)>1)//not yet monster.level_monsters[hit_id].defense)
    {
        
        core.monsters.level_monsters[hit_id].hp = core.monsters.level_monsters[hit_id].hp - stats.damage;
        n=sprintf(str,"%d",stats.level);
        core.ui_display.Add_ui_message(str);
        n=sprintf(str,"You hit a %s", core.monsters.level_monsters[hit_id].name);
        core.ui_display.Add_ui_message(str,{0,0,128});
        //n = sprintf(str, "%s has %i hp left", core.monsters.level_monsters[hit_id].name, core.monsters.level_monsters[hit_id].hp);
        //core.ui_display.Add_ui_message(str, { 0,0,128 });

        n=sprintf(str,"You did %d damage,",stats.damage);
        core.ui_display.Add_ui_message(str,{0,128,0});


        if(core.monsters.level_monsters[hit_id].hp<=0)
        {
            killed_monster(core, hit_id);
        }
        

        //hit_id=-1;
        //hit_monster=false;
    }else
    {
        
        n=sprintf(str,"you missed the %s", core.monsters.level_monsters[hit_id].name);
        core.ui_display.Add_ui_message(str);
         n=sprintf(str,"%s defense=%d", core.monsters.level_monsters[hit_id].name,core.monsters.level_monsters[hit_id].defense);
         core.ui_display.Add_ui_message(str);
        n=sprintf(str,"your attack=%d",stats.attack_power);
        core.ui_display.Add_ui_message(str);
        
    }


        hit_id=-1;
        hit_monster=false;
    //need to update the monsters to carry their own position also
    //printf("monster_y=%d, monster_x=%d, y=%d,x=%d",monster.level_monsters[hit_id].y,monster.level_monsters[hit_id].x,y,x);
    //monster.level_monsters[hit_id].alive=false;
    //printf("\nmonster index %d",game_data.dungeon_level[monster.level_monsters[hit_id].y][monster.level_monsters[hit_id].x].monster_index);

    //raise_level();
    //sprintf(str,"YOU HAVE REACHED LEVEL %d!",stats.level);
    //ui_display.Add_ui_message(str);

}

void Player::killed_monster(Core_Engine& core, int hit_id)
{
    int  n = 0;
    char str[200];
    //stats.exp+=monster.level_monsters[hit_id].xp_value;
    //n = sprintf(str, "%d", stats.level);
    //ui_display.Add_ui_message(str);
    
    n = sprintf(str, "You kill a %s", core.monsters.level_monsters[hit_id].name);
    core.ui_display.Add_ui_message(str, { 128,0,0 });

    n = sprintf(str, "You received %d xp ", core.monsters.level_monsters[hit_id].xp_value);
    core.ui_display.Add_ui_message(str, { 128,255,0 });

    if (gain_xp(core.monsters.level_monsters[hit_id].xp_value))
    {
        n = sprintf(str, "You gained a Level!");
        core.ui_display.Add_ui_message(str);

        n = sprintf(str, "You are now Level %d!", stats.level);
        core.ui_display.Add_ui_message(str);

    }

    core.game_data.dungeon_level[core.monsters.level_monsters[hit_id].y][core.monsters.level_monsters[hit_id].x].monster_index = -1;
    core.game_data.dungeon_level[core.monsters.level_monsters[hit_id].y][core.monsters.level_monsters[hit_id].x].monster = false;
    core.monsters.level_monsters[hit_id].alive = false;
    core.monsters.level_monsters[hit_id].next_to_player = false;
    if (core.monsters.level_monsters[hit_id].gold != 0)
    {
        if (core.game_data.dungeon_level[core.monsters.level_monsters[hit_id].y][core.monsters.level_monsters[hit_id].x].gold == true)
        {
            //printf("current gold value:%d, monster gold value:%d", core.game_data.dungeon_level[core.monsters.level_monsters[hit_id].y][core.monsters.level_monsters[hit_id].x].gold_value, core.monsters.level_monsters[hit_id].gold);
            core.game_data.dungeon_level[core.monsters.level_monsters[hit_id].y][core.monsters.level_monsters[hit_id].x].gold_value += core.monsters.level_monsters[hit_id].gold;
        }
        else
        {
            core.game_data.dungeon_level[core.monsters.level_monsters[hit_id].y][core.monsters.level_monsters[hit_id].x].gold = true;
            core.game_data.dungeon_level[core.monsters.level_monsters[hit_id].y][core.monsters.level_monsters[hit_id].x].gold_value = core.monsters.level_monsters[hit_id].gold;
        }
    }
}

int Player::player_direction(Core_Engine& core)
{
     int direction;

         if(core.input.KEY_LSHIFT==1)
         {

                 if(core.input.KEY_s==1)
                 {
                     direction = P_DOWN;
                     //shift_direction=true;
                    // printf("\nshift x\n");
                     return direction;
                 }
                 else if(core.input.KEY_d==1)
                 {
                     direction = P_RIGHT;
                     //shift_direction=true;
                   //  printf("\nshift x\n");
                     return direction;
                 }else if(core.input.KEY_a==1)
                 {
                     direction = P_LEFT;
                     //shift_direction=true;
                     //printf("\nshift x\n");
                     return direction;
                 }else if(core.input.KEY_w==1)
                 {
                     direction = P_UP;
                     //shift_direction=true;
                   // printf("\nshift x\n");
                     return direction;
                 }else if(core.input.KEY_e==1)
                 {
                     direction = P_UR;
                     //shift_direction=true;
                    // printf("\nshift x\n");
                     return direction;
                 }else if(core.input.KEY_q==1)
                 {
                     direction = P_UL;
                    // shift_direction=true;
                     //printf("\nshift x\n");
                     return direction;
                 }else if(core.input.KEY_z==1)
                 {
                     direction = P_DL;
                     //shift_direction=true;
                    // printf("\nshift x\n");
                     return direction;
                 }else if(core.input.KEY_c==1)
                 {
                     direction = P_DR;
                    // shift_direction=true;
                   //  printf("\nshift x\n");
                     return direction;
                 }
             //}else
             //{
             //    if((core.input.KEY_s!=1)&&(core.input.KEY_e!=1)&&(core.input.KEY_d!=1)&&(core.input.KEY_c!=1)&&(core.input.KEY_z!=1)&&(core.input.KEY_a!=1)&&(core.input.KEY_q!=1)&&(core.input.KEY_w!=1))
             //    {
             //        direction=P_NONE;
             //       // printf("\not shift x\n");
             //        shift_direction=false;
             //        return direction;

             //    }
             //}
             direction=P_NONE;
             return direction;

         }



        /* if(core.input.KEY_s==1)
         {
             direction = P_DOWN;
         }else if(core.input.KEY_d==1)
         {
             direction = P_RIGHT;
         }else if(core.input.KEY_a==1)
         {
             direction = P_LEFT;
         }else if(core.input.KEY_w==1)
         {
             direction = P_UP;
         }else if(core.input.KEY_e==1)
         {
             direction = P_UR;
         }else if(core.input.KEY_q==1)
         {
             direction = P_UL;
         }else if(core.input.KEY_z==1)
         {
             direction = P_DL;
         }else if(core.input.KEY_c==1)
         {
             direction = P_DR;
         }else
         {
             direction=P_NONE;
             core.input.KEY_LSHIFT_up=false;
         }*/

         if ((core.input.KEY_s == 1)&& (!single_move))
         {
             direction = P_DOWN;
             single_move = true;
         }
         else if ((core.input.KEY_d == 1) && (!single_move))
         {
             direction = P_RIGHT;
             single_move = true;
         }
         else if ((core.input.KEY_a == 1) && (!single_move))
         {
             direction = P_LEFT;
             single_move = true;
         }
         else if ((core.input.KEY_w == 1) && (!single_move))
         {
             direction = P_UP;
             single_move = true;
         }
         else if ((core.input.KEY_e == 1) && (!single_move))
         {
             direction = P_UR;
             single_move = true;
         }
         else if ((core.input.KEY_q == 1) && (!single_move))
         {
             direction = P_UL;
             single_move = true;
         }
         else if ((core.input.KEY_z == 1) && (!single_move))
         {
             direction = P_DL;
             single_move = true;
         }
         else if ((core.input.KEY_c == 1) && (!single_move))
         {
             direction = P_DR;
             single_move = true;
         }
         else
         {
             direction = P_NONE;
             core.input.KEY_LSHIFT_up = false;
             if ((core.input.KEY_s != 1) && (core.input.KEY_e != 1) && (core.input.KEY_d != 1) && (core.input.KEY_c != 1) && (core.input.KEY_z != 1) && (core.input.KEY_a != 1) && (core.input.KEY_q != 1) && (core.input.KEY_w != 1))
             {
                 single_move = false;
             }

         }



    return direction;
 }



void Player::build_proximity_matrix(Core_Engine& core)
{
    //set the initial vector

    y_min=y-(stats.agro_dist+1);
    x_min=x-(stats.agro_dist+1);
    x_max=x+(stats.agro_dist+1);
    y_max=y+(stats.agro_dist+1);
    if(y_min<0)
    {
        y_min=0;
    }
    if(y_max<0)
    {
        y_min=MAX_Y-1;
    }
    if(x_min<0)
    {
        x_min=0;
    }
    if(x_max<0)
    {
        x_min=MAX_X-1;
    }

    for(int i=y_min;i<y_max;i++)
    {
        for(int j=x_min;j<x_max;j++)
        {
            core.game_data.dungeon_level[i][j].prox_ripple_value=256;
        }
    }
    initial.x=x;
    initial.y=y;
    initial.d=0;

    vector_queue.push(initial);
        prox_vector temp;
        prox_vector current;

    while(!vector_queue.empty())
    {

        current=vector_queue.front();
        vector_queue.pop();
        x_min=current.x-1;
        if(x_min<0)
        {
            x_min=0;
        }
        x_max=current.x+1;
        if(x_max>MAX_X-1)
        {
            x_max=MAX_X-1;
        }
        y_min=current.y-1;
        if(y_min<0)
        {
            y_min=0;
        }
        y_max=current.y+1;
        if(y_max>MAX_Y-1)
        {
            y_max=MAX_Y-1;
        }
        for(int i=y_min;i<=y_max;i++)
        {
            for(int j=x_min; j<=x_max;j++)
            {

                if(core.game_data.dungeon_level[i][j].block_type!='#')
                {
                    if((current.d+1)<core.game_data.dungeon_level[i][j].prox_ripple_value)
                    {
                        core.game_data.dungeon_level[i][j].prox_ripple_value=current.d+1;
                        temp.x=j;
                        temp.y=i;
                        temp.d=current.d+1;

                        if(temp.d<stats.agro_dist)
                        {
                            vector_queue.push(temp);
                        }

                    }
                }

            }
        }

    }

}
