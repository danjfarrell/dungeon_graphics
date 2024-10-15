#include "input_sys.h"

Input_sys::Input_sys()
{
        mode = 1;
    
        repeat = false;
        key_value = ' ';
        mode = 0;
        mouse_x=0;
        mouse_y=0;
        mouse_move_x=0;
        mouse_move_y=0;
        mouse_button_x=0;
        mouse_button_y=0;
        KEY_BACKSPACE=-1;
        KEY_TAB=-1;
        KEY_CLEAR=-1;
        KEY_RETURN=-1;
        KEY_PAUSE=-1;
        KEY_ESCAPE=-1;
        KEY_SPACE=-1;
        KEY_EXCLAIM=-1;
        KEY_QUOTEDBL=-1;
        KEY_HASH=-1;
        KEY_DOLLAR=-1;
        KEY_AMPERSAND=-1;
        KEY_QUOTE=-1;
        KEY_LEFTPAREN=-1;
        KEY_RIGHTPAREN=-1;
        KEY_ASTERISK=-1;
        KEY_PLUS=-1;
        KEY_COMMA=-1;
        KEY_MINUS=-1;
        KEY_PERIOD=-1;
        KEY_SLASH=-1;
        KEY_0=-1;
        KEY_1=-1;
        KEY_2=-1;
        KEY_3=-1;
        KEY_4=-1;
        KEY_5=-1;
        KEY_6=-1;
        KEY_7=-1;
        KEY_8=-1;
        KEY_9=-1;
        KEY_COLON=-1;
        KEY_SEMICOLON=-1;
        KEY_LESS=-1;
        KEY_EQUALS=-1;
        KEY_GREATER=-1;
        KEY_QUESTION=-1;
        KEY_AT=-1;
        KEY_LEFTBRACKET=-1;
        KEY_BACKSLASH=-1;
        KEY_RIGHTBRACKET=-1;
        KEY_CARET=-1;
        KEY_UNDERSCORE=-1;
        KEY_BACKQUOTE=-1;
        KEY_a=-1;
        KEY_b=-1;
        KEY_c=-1;
        KEY_d=-1;
        KEY_e=-1;
        KEY_f=-1;
        KEY_g=-1;
        KEY_h=-1;
        KEY_i=-1;
        KEY_j=-1;
        KEY_k=-1;
        KEY_l=-1;
        KEY_m=-1;
        KEY_n=-1;
        KEY_o=-1;
        KEY_p=-1;
        KEY_q=-1;
        KEY_r=-1;
        KEY_s=-1;
        KEY_t=-1;
        KEY_u=-1;
        KEY_v=-1;
        KEY_w=-1;
        KEY_x=-1;
        KEY_y=-1;
        KEY_z=-1;
        KEY_DELETE=-1;
        KEY_KP0=-1;
        KEY_KP1=-1;
        KEY_KP2=-1;
        KEY_KP3=-1;
        KEY_KP4=-1;
        KEY_KP5=-1;
        KEY_KP6=-1;
        KEY_KP7=-1;
        KEY_KP8=-1;
        KEY_KP9=-1;
        KEY_KP_PERIOD=-1;
        KEY_KP_DIVIDE=-1;
        KEY_KP_MULTIPLY=-1;
        KEY_KP_MINUS=-1;
        KEY_KP_PLUS=-1;
        KEY_KP_ENTER=-1;
        KEY_KP_EQUALS=-1;
        KEY_UP=-1;
        KEY_DOWN=-1;
        KEY_RIGHT=-1;
        KEY_LEFT=-1;
        KEY_INSERT=-1;
        KEY_HOME=-1;
        KEY_END=-1;
        KEY_PAGEUP=-1;
        KEY_PAGEDOWN=-1;
        KEY_F1=-1;
        KEY_F2=-1;
        KEY_F3=-1;
        KEY_F4=-1;
        KEY_F5=-1;
        KEY_F6=-1;
        KEY_F7=-1;
        KEY_F8=-1;
        KEY_F9=-1;
        KEY_F10=-1;
        KEY_F11=-1;
        KEY_F12=-1;
        KEY_F13=-1;
        KEY_F14=-1;
        KEY_F15=-1;
        KEY_NUMLOCK=-1;
        KEY_CAPSLOCK=-1;
        KEY_SCROLLOCK=-1;
        KEY_RSHIFT=-1;
        KEY_LSHIFT=-1;
        KEY_RCTRL=-1;
        KEY_LCTRL=-1;
        KEY_RALT=-1;
        KEY_LALT=-1;
        KEY_RMETA=-1;
        KEY_LMETA=-1;
        KEY_LSUPER=-1;
        KEY_RSUPER=-1;
        KEY_MODE=-1;
        KEY_HELP=-1;
        KEY_PRINT=-1;
        KEY_SYSREQ=-1;
        KEY_BREAK=-1;
        KEY_MENU=-1;
        KEY_POWER=-1;
        KEY_EURO=-1;
        mouse_button_left=0;
        mouse_button_right=0;


         mouse_button_left_up=true;
         mouse_button_right_up=true;
      KEY_BACKSPACE_up=true;
      KEY_TAB_up=true;
      KEY_CLEAR_up=true;
      KEY_RETURN_up=true;
      KEY_PAUSE_up=true;
      KEY_ESCAPE_up=true;
      KEY_SPACE_up=true;
      KEY_EXCLAIM_up=true;
      KEY_QUOTEDBL_up=true;
      KEY_HASH_up=true;
      KEY_DOLLAR_up=true;
      KEY_AMPERSAND_up=true;
      KEY_QUOTE_up=true;
      KEY_LEFTPAREN_up=true;
      KEY_RIGHTPAREN_up=true;
      KEY_ASTERISK_up=true;
      KEY_PLUS_up=true;
      KEY_COMMA_up=true;
      KEY_MINUS_up=true;
      KEY_PERIOD_up=true;
      KEY_SLASH_up=true;
      KEY_0_up=true;
      KEY_1_up=true;
      KEY_2_up=true;
      KEY_3_up=true;
      KEY_4_up=true;
      KEY_5_up=true;
      KEY_6_up=true;
      KEY_7_up=true;
      KEY_8_up=true;
      KEY_9_up=true;
      KEY_COLON_up=true;
      KEY_SEMICOLON_up=true;
      KEY_LESS_up=true;
      KEY_EQUALS_up=true;
      KEY_GREATER_up=true;
      KEY_QUESTION_up=true;
      KEY_AT_up=true;
      KEY_LEFTBRACKET_up=true;
      KEY_BACKSLASH_up=true;
      KEY_RIGHTBRACKET_up=true;
      KEY_CARET_up=true;
      KEY_UNDERSCORE_up=true;
      KEY_BACKQUOTE_up=true;
      KEY_a_up=true;
      KEY_b_up=true;
      KEY_c_up=true;
      KEY_d_up=true;
      KEY_e_up=true;
      KEY_f_up=true;
      KEY_g_up=true;
      KEY_h_up=true;
      KEY_i_up=true;
      KEY_j_up=true;
      KEY_k_up=true;
      KEY_l_up=true;
      KEY_m_up=true;
      KEY_n_up=true;
      KEY_o_up=true;
      KEY_p_up=true;
      KEY_q_up=true;
      KEY_r_up=true;
      KEY_s_up=true;
      KEY_t_up=true;
      KEY_u_up=true;
      KEY_v_up=true;
      KEY_w_up=true;
      KEY_x_up=true;
      KEY_y_up=true;
      KEY_z_up=true;
      KEY_DELETE_up=true;
      KEY_KP0_up=true;
      KEY_KP1_up=true;
      KEY_KP2_up=true;
      KEY_KP3_up=true;
      KEY_KP4_up=true;
      KEY_KP5_up=true;
      KEY_KP6_up=true;
      KEY_KP7_up=true;
      KEY_KP8_up=true;
      KEY_KP9_up=true;
      KEY_KP_PERIOD_up=true;
      KEY_KP_DIVIDE_up=true;
      KEY_KP_MULTIPLY_up=true;
      KEY_KP_MINUS_up=true;
      KEY_KP_PLUS_up=true;
      KEY_KP_ENTER_up=true;
      KEY_KP_EQUALS_up=true;
      KEY_UP_up=true;
      KEY_DOWN_up=true;
      KEY_RIGHT_up=true;
      KEY_LEFT_up=true;
      KEY_INSERT_up=true;
      KEY_HOME_up=true;
      KEY_END_up=true;
      KEY_PAGEUP_up=true;
      KEY_PAGEDOWN_up=true;
      KEY_F1_up=true;
      KEY_F2_up=true;
      KEY_F3_up=true;
      KEY_F4_up=true;
      KEY_F5_up=true;
      KEY_F6_up=true;
      KEY_F7_up=true;
      KEY_F8_up=true;
      KEY_F9_up=true;
      KEY_F10_up=true;
      KEY_F11_up=true;
      KEY_F12_up=true;
      KEY_F13_up=true;
      KEY_F14_up=true;
      KEY_F15_up=true;
      KEY_NUMLOCK_up=true;
      KEY_CAPSLOCK_up=true;
      KEY_SCROLLOCK_up=true;
      KEY_RSHIFT_up=true;
      KEY_LSHIFT_up=true;
      KEY_RCTRL_up=true;
      KEY_LCTRL_up=true;
      KEY_RALT_up=true;
      KEY_LALT_up=true;
      KEY_RMETA_up=true;
      KEY_LMETA_up=true;
      KEY_LSUPER_up=true;
      KEY_RSUPER_up=true;
      KEY_MODE_up=true;
      KEY_HELP_up=true;
      KEY_PRINT_up=true;
      KEY_SYSREQ_up=true;
      KEY_BREAK_up=true;
      KEY_MENU_up=true;
      KEY_POWER_up=true;
      KEY_EURO_up=true;
}


bool Input_sys::get_input()
{
    //printf("get input, repeat=%d\n",repeat);
        while( SDL_PollEvent( &event ) )
        {
            

            //If the user has Xed out the window
            if (event.type == SDL_QUIT)
            {
                //Quit the program
                return true;
            }

            if (!mouse_events())
            {
                return true;
            }

            if (mode == 0)
            {

                return streaming_mode();
               
            }
            else
            {
                return single_mode();
            }


        }




     return false;
}


bool Input_sys::mouse_events()
{
    SDL_GetMouseState(&mouse_x, &mouse_y);
    if (event.type == SDL_MOUSEMOTION)
    {
        mouse_move_x = event.motion.x;
        mouse_move_y = event.motion.y;
    }

    if (event.type == SDL_MOUSEBUTTONDOWN)
    {
        //If the left mouse button was pressed
        if (event.button.button == SDL_BUTTON_LEFT)
        {
            mouse_button_x = event.button.x;
            mouse_button_y = event.button.y;
            mouse_button_left = 1;
        }
        if (event.button.button == SDL_BUTTON_RIGHT)
        {
            mouse_button_right = 1;
        }
    }
    if (event.type == SDL_MOUSEBUTTONUP)
    {
        //If the left mouse button was pressed
        if (event.button.button == SDL_BUTTON_LEFT)
        {
            mouse_button_left = -1;
        }
        if (event.button.button == SDL_BUTTON_RIGHT)
        {
            mouse_button_right = -1;
        }
    }

    return true;

}

bool Input_sys::streaming_mode()
{
    //printf("get input, repeat=%d\n",repeat);

        if ((event.type == SDL_KEYDOWN))
        {
            //handle the input
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                return true;
                break;
            case SDLK_BACKSPACE: KEY_BACKSPACE = 1; break;
            case SDLK_TAB: KEY_TAB = 1; break;
            case SDLK_CLEAR: KEY_CLEAR = 1; break;
            case SDLK_RETURN:key_value = '-'; KEY_RETURN = 1; break;
            case SDLK_PAUSE: KEY_PAUSE = 1; break;
            case SDLK_SPACE: KEY_SPACE = 1; break;
            case SDLK_EXCLAIM: KEY_EXCLAIM = 1; break;
            case SDLK_QUOTEDBL: KEY_QUOTEDBL = 1; break;
            case SDLK_HASH: KEY_HASH = 1; break;
            case SDLK_DOLLAR: KEY_DOLLAR = 1; break;
            case SDLK_AMPERSAND: KEY_AMPERSAND = 1; break;
            case SDLK_QUOTE: KEY_QUOTE = 1; break;
            case SDLK_LEFTPAREN: KEY_LEFTPAREN = 1; break;
            case SDLK_RIGHTPAREN: KEY_RIGHTPAREN = 1; break;
            case SDLK_ASTERISK: KEY_ASTERISK = 1; break;
            case SDLK_PLUS: KEY_PLUS = 1; break;
            case SDLK_COMMA: KEY_COMMA = 1; break;
            case SDLK_MINUS: KEY_MINUS = 1; break;
            case SDLK_PERIOD: KEY_PERIOD = 1; break;
            case SDLK_SLASH: KEY_SLASH = 1; break;
            case SDLK_0: KEY_0 = 1; break;
            case SDLK_1: KEY_1 = 1; break;
            case SDLK_2: KEY_2 = 1; break;
            case SDLK_3: KEY_3 = 1; break;
            case SDLK_4: KEY_4 = 1; break;
            case SDLK_5: KEY_5 = 1; break;
            case SDLK_6: KEY_6 = 1; break;
            case SDLK_7: KEY_7 = 1; break;
            case SDLK_8: KEY_8 = 1; break;
            case SDLK_9: KEY_9 = 1; break;
            case SDLK_COLON: KEY_COLON = 1; break;
            case SDLK_SEMICOLON: KEY_SEMICOLON = 1; break;
            case SDLK_LESS: KEY_LESS = 1; break;
            case SDLK_EQUALS: KEY_EQUALS = 1; break;
            case SDLK_GREATER: KEY_GREATER = 1; break;
            case SDLK_QUESTION: KEY_QUESTION = 1; break;
            case SDLK_AT: KEY_AT = 1; break;
            case SDLK_LEFTBRACKET: KEY_LEFTBRACKET = 1; break;
            case SDLK_BACKSLASH: KEY_BACKSLASH = 1; break;
            case SDLK_RIGHTBRACKET: KEY_RIGHTBRACKET = 1; break;
            case SDLK_CARET: KEY_CARET = 1; break;
            case SDLK_UNDERSCORE: KEY_UNDERSCORE = 1; break;
            case SDLK_BACKQUOTE: KEY_BACKQUOTE = 1; break;
            case SDLK_a: key_value = 'a'; KEY_a = 1; break;
            case SDLK_b: key_value = 'b';  KEY_b = 1; break;
            case SDLK_c: key_value = 'c';  KEY_c = 1; break;
            case SDLK_d: key_value = 'd'; KEY_d = 1; break;
            case SDLK_e: key_value = 'e'; KEY_e = 1; break;
            case SDLK_f: key_value = 'f'; KEY_f = 1; break;
            case SDLK_g: key_value = 'g'; KEY_g = 1; break;
            case SDLK_h: key_value = 'h'; KEY_h = 1; break;
            case SDLK_i: key_value = 'i'; KEY_i = 1; break;
            case SDLK_j: key_value = 'j'; KEY_j = 1; break;
            case SDLK_k: key_value = 'k'; KEY_k = 1; break;
            case SDLK_l: key_value = 'l'; KEY_l = 1; break;
            case SDLK_m: key_value = 'm';  KEY_m = 1; break;
            case SDLK_n: key_value = 'n';  KEY_n = 1; break;
            case SDLK_o: key_value = 'o';  KEY_o = 1; break;
            case SDLK_p: key_value = 'p';  KEY_p = 1; break;
            case SDLK_q: key_value = 'q';  KEY_q = 1; break;
            case SDLK_r: key_value = 'r';  KEY_r = 1; break;
            case SDLK_s:  key_value = 's'; KEY_s = 1; break;
            case SDLK_t:  key_value = 't'; KEY_t = 1; break;
            case SDLK_u:  key_value = 'u'; KEY_u = 1; break;
            case SDLK_v:  key_value = 'v'; KEY_v = 1; break;
            case SDLK_w:  key_value = 'w'; KEY_w = 1; break;
            case SDLK_x: key_value = 'x'; KEY_x = 1; break;
            case SDLK_y: key_value = 'y';  KEY_y = 1; break;
            case SDLK_z: key_value = 'z';  KEY_z = 1; break;
            case SDLK_DELETE: KEY_DELETE = 1; break;
            case SDLK_KP_0: KEY_KP0 = 1; break;
            case SDLK_KP_1: KEY_KP1 = 1; break;
            case SDLK_KP_2: KEY_KP2 = 1; break;
            case SDLK_KP_3: KEY_KP3 = 1; break;
            case SDLK_KP_4: KEY_KP4 = 1; break;
            case SDLK_KP_5: KEY_KP5 = 1; break;
            case SDLK_KP_6: KEY_KP6 = 1; break;
            case SDLK_KP_7: KEY_KP7 = 1; break;
            case SDLK_KP_8: KEY_KP8 = 1; break;
            case SDLK_KP_9: KEY_KP9 = 1; break;
            case SDLK_KP_PERIOD: KEY_KP_PERIOD = 1; break;
            case SDLK_KP_DIVIDE: KEY_KP_DIVIDE = 1; break;
            case SDLK_KP_MULTIPLY: KEY_KP_MULTIPLY = 1; break;
            case SDLK_KP_MINUS: KEY_KP_MINUS = 1; break;
            case SDLK_KP_PLUS: KEY_KP_PLUS = 1; break;
            case SDLK_KP_ENTER: KEY_KP_ENTER = 1; break;
            case SDLK_KP_EQUALS: KEY_KP_EQUALS = 1; break;
            case SDLK_UP: KEY_UP = 1; break;
            case SDLK_DOWN: KEY_DOWN = 1; break;
            case SDLK_RIGHT: KEY_RIGHT = 1; break;
            case SDLK_LEFT: KEY_LEFT = 1; break;
            case SDLK_INSERT: KEY_INSERT = 1; break;
            case SDLK_HOME: KEY_HOME = 1; break;
            case SDLK_END: KEY_END = 1; break;
            case SDLK_PAGEUP: KEY_PAGEUP = 1; break;
            case SDLK_PAGEDOWN: KEY_PAGEDOWN = 1; break;
            case SDLK_F1: KEY_F1 = 1; break;
            case SDLK_F2: KEY_F2 = 1; break;
            case SDLK_F3: KEY_F3 = 1; break;
            case SDLK_F4: KEY_F4 = 1; break;
            case SDLK_F5: KEY_F5 = 1; break;
            case SDLK_F6: KEY_F6 = 1; break;
            case SDLK_F7: KEY_F7 = 1; break;
            case SDLK_F8: KEY_F8 = 1; break;
            case SDLK_F9: KEY_F9 = 1; break;
            case SDLK_F10: KEY_F10 = 1; break;
            case SDLK_F11: KEY_F11 = 1; break;
            case SDLK_F12: KEY_F12 = 1; break;
            case SDLK_F13: KEY_F13 = 1; break;
            case SDLK_F14: KEY_F14 = 1; break;
            case SDLK_F15: KEY_F15 = 1; break;
            case SDLK_NUMLOCKCLEAR: KEY_NUMLOCK = 1; break;
            case SDLK_CAPSLOCK: KEY_CAPSLOCK = 1; break;
            case SDLK_SCROLLLOCK: KEY_SCROLLOCK = 1; break;
            case SDLK_RSHIFT: KEY_RSHIFT = 1; break;
            case SDLK_LSHIFT: KEY_LSHIFT = 1; break;
            case SDLK_RCTRL: KEY_RCTRL = 1; break;
            case SDLK_LCTRL: KEY_LCTRL = 1; break;
            case SDLK_RALT: KEY_RALT = 1; break;
            case SDLK_LALT: KEY_LALT = 1; break;
                //case SDLK_RMETA: KEY_RMETA=1;break;
                //case SDLK_LMETA: KEY_LMETA=1;break;
                //case SDLK_LSUPER: KEY_LSUPER=1;break;
                //case SDLK_RSUPER: KEY_RSUPER=1;break;
                //case SDLK_MODE: KEY_MODE=1;break;
            case SDLK_HELP: KEY_HELP = 1; break;
            case SDLK_PRINTSCREEN: KEY_PRINT = 1; break;
            case SDLK_SYSREQ: KEY_SYSREQ = 1; break;
                //case SDLK_BREAK: KEY_BREAK=1;break;
            case SDLK_MENU: KEY_MENU = 1; break;
            case SDLK_POWER: KEY_POWER = 1; break;
                //case SDLK_EURO: KEY_EURO=1;break;

            }
        }

        if ((KEY_a == 1) || (KEY_b == 1) || (KEY_c == 1) || (KEY_d == 1) || (KEY_e == 1) || (KEY_f == 1) ||
            (KEY_g == 1) || (KEY_h == 1) || (KEY_i == 1) || (KEY_j == 1) || (KEY_k == 1) || (KEY_l == 1) ||
            (KEY_m == 1) || (KEY_n == 1) || (KEY_o == 1) || (KEY_p == 1) || (KEY_q == 1) || (KEY_r == 1) ||
            (KEY_s == 1) || (KEY_t == 1) || (KEY_u == 1) || (KEY_v == 1) || (KEY_w == 1) || (KEY_x == 1) ||
            (KEY_y == 1) || (KEY_z == 1) || (KEY_RETURN == 1))
        {
            repeat = true;
        }


        if (event.type == SDL_KEYUP)
        {
            key_value = ' ';
            //handle the input
            switch (event.key.keysym.sym)
            {

            case SDLK_BACKSPACE: KEY_BACKSPACE = -1; break;
            case SDLK_TAB: KEY_TAB = -1; break;
            case SDLK_CLEAR: KEY_CLEAR = -1; break;
            case SDLK_RETURN: KEY_RETURN = -1; break;
            case SDLK_PAUSE: KEY_PAUSE = -1; break;
            case SDLK_SPACE: KEY_SPACE = -1; break;
            case SDLK_EXCLAIM: KEY_EXCLAIM = -1; break;
            case SDLK_QUOTEDBL: KEY_QUOTEDBL = -1; break;
            case SDLK_HASH: KEY_HASH = -1; break;
            case SDLK_DOLLAR: KEY_DOLLAR = -1; break;
            case SDLK_AMPERSAND: KEY_AMPERSAND = -1; break;
            case SDLK_QUOTE: KEY_QUOTE = -1; break;
            case SDLK_LEFTPAREN: KEY_LEFTPAREN = -1; break;
            case SDLK_RIGHTPAREN: KEY_RIGHTPAREN = -1; break;
            case SDLK_ASTERISK: KEY_ASTERISK = -1; break;
            case SDLK_PLUS: KEY_PLUS = -1; break;
            case SDLK_COMMA: KEY_COMMA = -1; break;
            case SDLK_MINUS: KEY_MINUS = -1; break;
            case SDLK_PERIOD: KEY_PERIOD = -1; break;
            case SDLK_SLASH: KEY_SLASH = -1; break;
            case SDLK_0: KEY_0 = -1; break;
            case SDLK_1: KEY_1 = -1; break;
            case SDLK_2: KEY_2 = -1; break;
            case SDLK_3: KEY_3 = -1; break;
            case SDLK_4: KEY_4 = -1; break;
            case SDLK_5: KEY_5 = -1; break;
            case SDLK_6: KEY_6 = -1; break;
            case SDLK_7: KEY_7 = -1; break;
            case SDLK_8: KEY_8 = -1; break;
            case SDLK_9: KEY_9 = -1; break;
            case SDLK_COLON: KEY_COLON = -1; break;
            case SDLK_SEMICOLON: KEY_SEMICOLON = -1; break;
            case SDLK_LESS: KEY_LESS = -1; break;
            case SDLK_EQUALS: KEY_EQUALS = -1; break;
            case SDLK_GREATER: KEY_GREATER = -1; break;
            case SDLK_QUESTION: KEY_QUESTION = -1; break;
            case SDLK_AT: KEY_AT = -1; break;
            case SDLK_LEFTBRACKET: KEY_LEFTBRACKET = -1; break;
            case SDLK_BACKSLASH: KEY_BACKSLASH = -1; break;
            case SDLK_RIGHTBRACKET: KEY_RIGHTBRACKET = -1; break;
            case SDLK_CARET: KEY_CARET = -1; break;
            case SDLK_UNDERSCORE: KEY_UNDERSCORE = -1; break;
            case SDLK_BACKQUOTE: KEY_BACKQUOTE = -1; break;
            case SDLK_a: KEY_a = -1; break;
            case SDLK_b: KEY_b = -1; break;
            case SDLK_c: KEY_c = -1; break;
            case SDLK_d: KEY_d = -1; break;
            case SDLK_e: KEY_e = -1; break;
            case SDLK_f: KEY_f = -1; break;
            case SDLK_g: KEY_g = -1; break;
            case SDLK_h: KEY_h = -1; break;
            case SDLK_i: KEY_i = -1; break;
            case SDLK_j: KEY_j = -1; break;
            case SDLK_k: KEY_k = -1; break;
            case SDLK_l: KEY_l = -1; break;
            case SDLK_m: KEY_m = -1; break;
            case SDLK_n: KEY_n = -1; break;
            case SDLK_o: KEY_o = -1; break;
            case SDLK_p: KEY_p = -1; break;
            case SDLK_q: KEY_q = -1; break;
            case SDLK_r: KEY_r = -1; break;
            case SDLK_s: KEY_s = -1; break;
            case SDLK_t: KEY_t = -1; break;
            case SDLK_u: KEY_u = -1; break;
            case SDLK_v: KEY_v = -1; break;
            case SDLK_w: KEY_w = -1; break;
            case SDLK_x: KEY_x = -1; break;
            case SDLK_y: KEY_y = -1; break;
            case SDLK_z: KEY_z = -1; break;
            case SDLK_DELETE: KEY_DELETE = -1; break;
            case SDLK_KP_0: KEY_KP0 = -1; break;
            case SDLK_KP_1: KEY_KP1 = -1; break;
            case SDLK_KP_2: KEY_KP2 = -1; break;
            case SDLK_KP_3: KEY_KP3 = -1; break;
            case SDLK_KP_4: KEY_KP4 = -1; break;
            case SDLK_KP_5: KEY_KP5 = -1; break;
            case SDLK_KP_6: KEY_KP6 = -1; break;
            case SDLK_KP_7: KEY_KP7 = -1; break;
            case SDLK_KP_8: KEY_KP8 = -1; break;
            case SDLK_KP_9: KEY_KP9 = -1; break;
            case SDLK_KP_PERIOD: KEY_KP_PERIOD = -1; break;
            case SDLK_KP_DIVIDE: KEY_KP_DIVIDE = -1; break;
            case SDLK_KP_MULTIPLY: KEY_KP_MULTIPLY = -1; break;
            case SDLK_KP_MINUS: KEY_KP_MINUS = -1; break;
            case SDLK_KP_PLUS: KEY_KP_PLUS = -1; break;
            case SDLK_KP_ENTER: KEY_KP_ENTER = -1; break;
            case SDLK_KP_EQUALS: KEY_KP_EQUALS = -1; break;
            case SDLK_UP: KEY_UP = -1; break;
            case SDLK_DOWN: KEY_DOWN = -1; break;
            case SDLK_RIGHT: KEY_RIGHT = -1; break;
            case SDLK_LEFT: KEY_LEFT = -1; break;
            case SDLK_INSERT: KEY_INSERT = -1; break;
            case SDLK_HOME: KEY_HOME = -1; break;
            case SDLK_END: KEY_END = -1; break;
            case SDLK_PAGEUP: KEY_PAGEUP = -1; break;
            case SDLK_PAGEDOWN: KEY_PAGEDOWN = -1; break;
            case SDLK_F1: KEY_F1 = -1; break;
            case SDLK_F2: KEY_F2 = -1; break;
            case SDLK_F3: KEY_F3 = -1; break;
            case SDLK_F4: KEY_F4 = -1; break;
            case SDLK_F5: KEY_F5 = -1; break;
            case SDLK_F6: KEY_F6 = -1; break;
            case SDLK_F7: KEY_F7 = -1; break;
            case SDLK_F8: KEY_F8 = -1; break;
            case SDLK_F9: KEY_F9 = -1; break;
            case SDLK_F10: KEY_F10 = -1; break;
            case SDLK_F11: KEY_F11 = -1; break;
            case SDLK_F12: KEY_F12 = -1; break;
            case SDLK_F13: KEY_F13 = -1; break;
            case SDLK_F14: KEY_F14 = -1; break;
            case SDLK_F15: KEY_F15 = -1; break;
            case SDLK_NUMLOCKCLEAR: KEY_NUMLOCK = -1; break;
            case SDLK_CAPSLOCK: KEY_CAPSLOCK = -1; break;
            case SDLK_SCROLLLOCK: KEY_SCROLLOCK = -1; break;
            case SDLK_RSHIFT: KEY_RSHIFT = -1; break;
            case SDLK_LSHIFT: KEY_LSHIFT = -1; break;
            case SDLK_RCTRL: KEY_RCTRL = -1; break;
            case SDLK_LCTRL: KEY_LCTRL = -1; break;
            case SDLK_RALT: KEY_RALT = -1; break;
            case SDLK_LALT: KEY_LALT = -1; break;
                //case SDLK_RMETA: KEY_RMETA=-1;break;
                //case SDLK_LMETA: KEY_LMETA=-1;break;
                //case SDLK_LSUPER: KEY_LSUPER=-1;break;
                //case SDLK_RSUPER: KEY_RSUPER=-1;break;
            case SDLK_MODE: KEY_MODE = -1; break;
            case SDLK_HELP: KEY_HELP = -1; break;
            case SDLK_PRINTSCREEN: KEY_PRINT = -1; break;
            case SDLK_SYSREQ: KEY_SYSREQ = -1; break;
                //case SDLK_BREAK: KEY_BREAK=-1;break;
            case SDLK_MENU: KEY_MENU = -1; break;
            case SDLK_POWER: KEY_POWER = -1; break;
                //case SDLK_EURO: KEY_EURO=-1;break;



            }
        }

        if ((KEY_a == -1) && (KEY_b == -1) && (KEY_c == -1) && (KEY_d == -1) && (KEY_e == -1) && (KEY_f == -1) &&
            (KEY_g == -1) && (KEY_h == -1) && (KEY_i == -1) && (KEY_j == -1) && (KEY_k == -1) && (KEY_l == -1) &&
            (KEY_m == -1) && (KEY_n == -1) && (KEY_o == -1) && (KEY_p == -1) && (KEY_q == -1) && (KEY_r == -1) &&
            (KEY_s == -1) && (KEY_t == -1) && (KEY_u == -1) && (KEY_v == -1) && (KEY_w == -1) && (KEY_x == -1) &&
            (KEY_y == -1) && (KEY_z == -1) && (KEY_RETURN == -1))
        {
            repeat = false;

        }

    return false;
}

bool Input_sys::single_mode()
{
   //printf("get input, single mode\n");

        if ((event.type == SDL_KEYDOWN))
        {
            printf("get input, single mode2\n");
            //handle the input
            if (all_keys_up())
            {
                printf("get input, single mode 3\n");
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE: return true; break; // end the game
                    case SDLK_BACKSPACE: KEY_BACKSPACE = 1; break;
                    case SDLK_TAB: KEY_TAB = 1; break;
                    case SDLK_CLEAR: KEY_CLEAR = 1; break;
                    case SDLK_RETURN:key_value = '-'; KEY_RETURN = 1; break;
                    case SDLK_PAUSE: KEY_PAUSE = 1; break;
                    case SDLK_SPACE: KEY_SPACE = 1; break;
                    case SDLK_EXCLAIM: KEY_EXCLAIM = 1; break;
                    case SDLK_QUOTEDBL: KEY_QUOTEDBL = 1; break;
                    case SDLK_HASH: KEY_HASH = 1; break;
                    case SDLK_DOLLAR: KEY_DOLLAR = 1; break;
                    case SDLK_AMPERSAND: KEY_AMPERSAND = 1; break;
                    case SDLK_QUOTE: KEY_QUOTE = 1; break;
                    case SDLK_LEFTPAREN: KEY_LEFTPAREN = 1; break;
                    case SDLK_RIGHTPAREN: KEY_RIGHTPAREN = 1; break;
                    case SDLK_ASTERISK: KEY_ASTERISK = 1; break;
                    case SDLK_PLUS: KEY_PLUS = 1; break;
                    case SDLK_COMMA: KEY_COMMA = 1; break;
                    case SDLK_MINUS: KEY_MINUS = 1; break;
                    case SDLK_PERIOD: KEY_PERIOD = 1; break;
                    case SDLK_SLASH: KEY_SLASH = 1; break;
                    case SDLK_0: KEY_0 = 1; break;
                    case SDLK_1: KEY_1 = 1; break;
                    case SDLK_2: KEY_2 = 1; break;
                    case SDLK_3: KEY_3 = 1; break;
                    case SDLK_4: KEY_4 = 1; break;
                    case SDLK_5: KEY_5 = 1; break;
                    case SDLK_6: KEY_6 = 1; break;
                    case SDLK_7: KEY_7 = 1; break;
                    case SDLK_8: KEY_8 = 1; break;
                    case SDLK_9: KEY_9 = 1; break;
                    case SDLK_COLON: KEY_COLON = 1; break;
                    case SDLK_SEMICOLON: KEY_SEMICOLON = 1; break;
                    case SDLK_LESS: KEY_LESS = 1; break;
                    case SDLK_EQUALS: KEY_EQUALS = 1; break;
                    case SDLK_GREATER: KEY_GREATER = 1; break;
                    case SDLK_QUESTION: KEY_QUESTION = 1; break;
                    case SDLK_AT: KEY_AT = 1; break;
                    case SDLK_LEFTBRACKET: KEY_LEFTBRACKET = 1; break;
                    case SDLK_BACKSLASH: KEY_BACKSLASH = 1; break;
                    case SDLK_RIGHTBRACKET: KEY_RIGHTBRACKET = 1; break;
                    case SDLK_CARET: KEY_CARET = 1; break;
                    case SDLK_UNDERSCORE: KEY_UNDERSCORE = 1; break;
                    case SDLK_BACKQUOTE: KEY_BACKQUOTE = 1; break;
                    case SDLK_a: key_value = 'a'; KEY_a = 1; break;
                    case SDLK_b: key_value = 'b';  KEY_b = 1; break;
                    case SDLK_c: key_value = 'c';  KEY_c = 1; break;
                    case SDLK_d: key_value = 'd'; KEY_d = 1; break;
                    case SDLK_e: key_value = 'e'; KEY_e = 1; break;
                    case SDLK_f: key_value = 'f'; KEY_f = 1; break;
                    case SDLK_g: key_value = 'g'; KEY_g = 1; break;
                    case SDLK_h: key_value = 'h'; KEY_h = 1; break;
                    case SDLK_i: key_value = 'i'; KEY_i = 1; break;
                    case SDLK_j: key_value = 'j'; KEY_j = 1; break;
                    case SDLK_k: key_value = 'k'; KEY_k = 1; break;
                    case SDLK_l: key_value = 'l'; KEY_l = 1; break;
                    case SDLK_m: key_value = 'm';  KEY_m = 1; break;
                    case SDLK_n: key_value = 'n';  KEY_n = 1; break;
                    case SDLK_o: key_value = 'o';  KEY_o = 1; break;
                    case SDLK_p: key_value = 'p';  KEY_p = 1; break;
                    case SDLK_q: key_value = 'q';  KEY_q = 1; break;
                    case SDLK_r: key_value = 'r';  KEY_r = 1; break;
                    case SDLK_s:  key_value = 's'; KEY_s = 1; break;
                    case SDLK_t:  key_value = 't'; KEY_t = 1; break;
                    case SDLK_u:  key_value = 'u'; KEY_u = 1; break;
                    case SDLK_v:  key_value = 'v'; KEY_v = 1; break;
                    case SDLK_w:  key_value = 'w'; KEY_w = 1; break;
                    case SDLK_x: key_value = 'x'; KEY_x = 1; break;
                    case SDLK_y: key_value = 'y';  KEY_y = 1; break;
                    case SDLK_z: key_value = 'z';  KEY_z = 1; break;
                    case SDLK_DELETE: KEY_DELETE = 1; break;
                    case SDLK_KP_0: KEY_KP0 = 1; break;
                    case SDLK_KP_1: KEY_KP1 = 1; break;
                    case SDLK_KP_2: KEY_KP2 = 1; break;
                    case SDLK_KP_3: KEY_KP3 = 1; break;
                    case SDLK_KP_4: KEY_KP4 = 1; break;
                    case SDLK_KP_5: KEY_KP5 = 1; break;
                    case SDLK_KP_6: KEY_KP6 = 1; break;
                    case SDLK_KP_7: KEY_KP7 = 1; break;
                    case SDLK_KP_8: KEY_KP8 = 1; break;
                    case SDLK_KP_9: KEY_KP9 = 1; break;
                    case SDLK_KP_PERIOD: KEY_KP_PERIOD = 1; break;
                    case SDLK_KP_DIVIDE: KEY_KP_DIVIDE = 1; break;
                    case SDLK_KP_MULTIPLY: KEY_KP_MULTIPLY = 1; break;
                    case SDLK_KP_MINUS: KEY_KP_MINUS = 1; break;
                    case SDLK_KP_PLUS: KEY_KP_PLUS = 1; break;
                    case SDLK_KP_ENTER: KEY_KP_ENTER = 1; break;
                    case SDLK_KP_EQUALS: KEY_KP_EQUALS = 1; break;
                    case SDLK_UP: KEY_UP = 1; break;
                    case SDLK_DOWN: KEY_DOWN = 1; break;
                    case SDLK_RIGHT: KEY_RIGHT = 1; break;
                    case SDLK_LEFT: KEY_LEFT = 1; break;
                    case SDLK_INSERT: KEY_INSERT = 1; break;
                    case SDLK_HOME: KEY_HOME = 1; break;
                    case SDLK_END: KEY_END = 1; break;
                    case SDLK_PAGEUP: KEY_PAGEUP = 1; break;
                    case SDLK_PAGEDOWN: KEY_PAGEDOWN = 1; break;
                    case SDLK_F1: KEY_F1 = 1; break;
                    case SDLK_F2: KEY_F2 = 1; break;
                    case SDLK_F3: KEY_F3 = 1; break;
                    case SDLK_F4: KEY_F4 = 1; break;
                    case SDLK_F5: KEY_F5 = 1; break;
                    case SDLK_F6: KEY_F6 = 1; break;
                    case SDLK_F7: KEY_F7 = 1; break;
                    case SDLK_F8: KEY_F8 = 1; break;
                    case SDLK_F9: KEY_F9 = 1; break;
                    case SDLK_F10: KEY_F10 = 1; break;
                    case SDLK_F11: KEY_F11 = 1; break;
                    case SDLK_F12: KEY_F12 = 1; break;
                    case SDLK_F13: KEY_F13 = 1; break;
                    case SDLK_F14: KEY_F14 = 1; break;
                    case SDLK_F15: KEY_F15 = 1; break;
                    case SDLK_NUMLOCKCLEAR: KEY_NUMLOCK = 1; break;
                    case SDLK_CAPSLOCK: KEY_CAPSLOCK = 1; break;
                    case SDLK_SCROLLLOCK: KEY_SCROLLOCK = 1; break;
                    case SDLK_RSHIFT: KEY_RSHIFT = 1; break;
                    case SDLK_LSHIFT: KEY_LSHIFT = 1; break;
                    case SDLK_RCTRL: KEY_RCTRL = 1; break;
                    case SDLK_LCTRL: KEY_LCTRL = 1; break;
                    case SDLK_RALT: KEY_RALT = 1; break;
                    case SDLK_LALT: KEY_LALT = 1; break;
                        //case SDLK_RMETA: KEY_RMETA=1;break;
                        //case SDLK_LMETA: KEY_LMETA=1;break;
                        //case SDLK_LSUPER: KEY_LSUPER=1;break;
                        //case SDLK_RSUPER: KEY_RSUPER=1;break;
                        //case SDLK_MODE: KEY_MODE=1;break;
                    case SDLK_HELP: KEY_HELP = 1; break;
                    case SDLK_PRINTSCREEN: KEY_PRINT = 1; break;
                    case SDLK_SYSREQ: KEY_SYSREQ = 1; break;
                        //case SDLK_BREAK: KEY_BREAK=1;break;
                    case SDLK_MENU: KEY_MENU = 1; break;
                    case SDLK_POWER: KEY_POWER = 1; break;
                        //case SDLK_EURO: KEY_EURO=1;break;

                }
            }
        }


        if (event.type == SDL_KEYUP)
        {
            key_value = ' ';
            //handle the input
            switch (event.key.keysym.sym)
            {

            case SDLK_BACKSPACE: KEY_BACKSPACE = -1; break;
            case SDLK_TAB: KEY_TAB = -1; break;
            case SDLK_CLEAR: KEY_CLEAR = -1; break;
            case SDLK_RETURN: KEY_RETURN = -1; break;
            case SDLK_PAUSE: KEY_PAUSE = -1; break;
            case SDLK_SPACE: KEY_SPACE = -1; break;
            case SDLK_EXCLAIM: KEY_EXCLAIM = -1; break;
            case SDLK_QUOTEDBL: KEY_QUOTEDBL = -1; break;
            case SDLK_HASH: KEY_HASH = -1; break;
            case SDLK_DOLLAR: KEY_DOLLAR = -1; break;
            case SDLK_AMPERSAND: KEY_AMPERSAND = -1; break;
            case SDLK_QUOTE: KEY_QUOTE = -1; break;
            case SDLK_LEFTPAREN: KEY_LEFTPAREN = -1; break;
            case SDLK_RIGHTPAREN: KEY_RIGHTPAREN = -1; break;
            case SDLK_ASTERISK: KEY_ASTERISK = -1; break;
            case SDLK_PLUS: KEY_PLUS = -1; break;
            case SDLK_COMMA: KEY_COMMA = -1; break;
            case SDLK_MINUS: KEY_MINUS = -1; break;
            case SDLK_PERIOD: KEY_PERIOD = -1; break;
            case SDLK_SLASH: KEY_SLASH = -1; break;
            case SDLK_0: KEY_0 = -1; break;
            case SDLK_1: KEY_1 = -1; break;
            case SDLK_2: KEY_2 = -1; break;
            case SDLK_3: KEY_3 = -1; break;
            case SDLK_4: KEY_4 = -1; break;
            case SDLK_5: KEY_5 = -1; break;
            case SDLK_6: KEY_6 = -1; break;
            case SDLK_7: KEY_7 = -1; break;
            case SDLK_8: KEY_8 = -1; break;
            case SDLK_9: KEY_9 = -1; break;
            case SDLK_COLON: KEY_COLON = -1; break;
            case SDLK_SEMICOLON: KEY_SEMICOLON = -1; break;
            case SDLK_LESS: KEY_LESS = -1; break;
            case SDLK_EQUALS: KEY_EQUALS = -1; break;
            case SDLK_GREATER: KEY_GREATER = -1; break;
            case SDLK_QUESTION: KEY_QUESTION = -1; break;
            case SDLK_AT: KEY_AT = -1; break;
            case SDLK_LEFTBRACKET: KEY_LEFTBRACKET = -1; break;
            case SDLK_BACKSLASH: KEY_BACKSLASH = -1; break;
            case SDLK_RIGHTBRACKET: KEY_RIGHTBRACKET = -1; break;
            case SDLK_CARET: KEY_CARET = -1; break;
            case SDLK_UNDERSCORE: KEY_UNDERSCORE = -1; break;
            case SDLK_BACKQUOTE: KEY_BACKQUOTE = -1; break;
            case SDLK_a: KEY_a = -1; break;
            case SDLK_b: KEY_b = -1; break;
            case SDLK_c: KEY_c = -1; break;
            case SDLK_d: KEY_d = -1; break;
            case SDLK_e: KEY_e = -1; break;
            case SDLK_f: KEY_f = -1; break;
            case SDLK_g: KEY_g = -1; break;
            case SDLK_h: KEY_h = -1; break;
            case SDLK_i: KEY_i = -1; break;
            case SDLK_j: KEY_j = -1; break;
            case SDLK_k: KEY_k = -1; break;
            case SDLK_l: KEY_l = -1; break;
            case SDLK_m: KEY_m = -1; break;
            case SDLK_n: KEY_n = -1; break;
            case SDLK_o: KEY_o = -1; break;
            case SDLK_p: KEY_p = -1; break;
            case SDLK_q: KEY_q = -1; break;
            case SDLK_r: KEY_r = -1; break;
            case SDLK_s: KEY_s = -1; break;
            case SDLK_t: KEY_t = -1; break;
            case SDLK_u: KEY_u = -1; break;
            case SDLK_v: KEY_v = -1; break;
            case SDLK_w: KEY_w = -1; break;
            case SDLK_x: KEY_x = -1; break;
            case SDLK_y: KEY_y = -1; break;
            case SDLK_z: KEY_z = -1; break;
            case SDLK_DELETE: KEY_DELETE = -1; break;
            case SDLK_KP_0: KEY_KP0 = -1; break;
            case SDLK_KP_1: KEY_KP1 = -1; break;
            case SDLK_KP_2: KEY_KP2 = -1; break;
            case SDLK_KP_3: KEY_KP3 = -1; break;
            case SDLK_KP_4: KEY_KP4 = -1; break;
            case SDLK_KP_5: KEY_KP5 = -1; break;
            case SDLK_KP_6: KEY_KP6 = -1; break;
            case SDLK_KP_7: KEY_KP7 = -1; break;
            case SDLK_KP_8: KEY_KP8 = -1; break;
            case SDLK_KP_9: KEY_KP9 = -1; break;
            case SDLK_KP_PERIOD: KEY_KP_PERIOD = -1; break;
            case SDLK_KP_DIVIDE: KEY_KP_DIVIDE = -1; break;
            case SDLK_KP_MULTIPLY: KEY_KP_MULTIPLY = -1; break;
            case SDLK_KP_MINUS: KEY_KP_MINUS = -1; break;
            case SDLK_KP_PLUS: KEY_KP_PLUS = -1; break;
            case SDLK_KP_ENTER: KEY_KP_ENTER = -1; break;
            case SDLK_KP_EQUALS: KEY_KP_EQUALS = -1; break;
            case SDLK_UP: KEY_UP = -1; break;
            case SDLK_DOWN: KEY_DOWN = -1; break;
            case SDLK_RIGHT: KEY_RIGHT = -1; break;
            case SDLK_LEFT: KEY_LEFT = -1; break;
            case SDLK_INSERT: KEY_INSERT = -1; break;
            case SDLK_HOME: KEY_HOME = -1; break;
            case SDLK_END: KEY_END = -1; break;
            case SDLK_PAGEUP: KEY_PAGEUP = -1; break;
            case SDLK_PAGEDOWN: KEY_PAGEDOWN = -1; break;
            case SDLK_F1: KEY_F1 = -1; break;
            case SDLK_F2: KEY_F2 = -1; break;
            case SDLK_F3: KEY_F3 = -1; break;
            case SDLK_F4: KEY_F4 = -1; break;
            case SDLK_F5: KEY_F5 = -1; break;
            case SDLK_F6: KEY_F6 = -1; break;
            case SDLK_F7: KEY_F7 = -1; break;
            case SDLK_F8: KEY_F8 = -1; break;
            case SDLK_F9: KEY_F9 = -1; break;
            case SDLK_F10: KEY_F10 = -1; break;
            case SDLK_F11: KEY_F11 = -1; break;
            case SDLK_F12: KEY_F12 = -1; break;
            case SDLK_F13: KEY_F13 = -1; break;
            case SDLK_F14: KEY_F14 = -1; break;
            case SDLK_F15: KEY_F15 = -1; break;
            case SDLK_NUMLOCKCLEAR: KEY_NUMLOCK = -1; break;
            case SDLK_CAPSLOCK: KEY_CAPSLOCK = -1; break;
            case SDLK_SCROLLLOCK: KEY_SCROLLOCK = -1; break;
            case SDLK_RSHIFT: KEY_RSHIFT = -1; break;
            case SDLK_LSHIFT: KEY_LSHIFT = -1; break;
            case SDLK_RCTRL: KEY_RCTRL = -1; break;
            case SDLK_LCTRL: KEY_LCTRL = -1; break;
            case SDLK_RALT: KEY_RALT = -1; break;
            case SDLK_LALT: KEY_LALT = -1; break;
                //case SDLK_RMETA: KEY_RMETA=-1;break;
                //case SDLK_LMETA: KEY_LMETA=-1;break;
                //case SDLK_LSUPER: KEY_LSUPER=-1;break;
                //case SDLK_RSUPER: KEY_RSUPER=-1;break;
            case SDLK_MODE: KEY_MODE = -1; break;
            case SDLK_HELP: KEY_HELP = -1; break;
            case SDLK_PRINTSCREEN: KEY_PRINT = -1; break;
            case SDLK_SYSREQ: KEY_SYSREQ = -1; break;
                //case SDLK_BREAK: KEY_BREAK=-1;break;
            case SDLK_MENU: KEY_MENU = -1; break;
            case SDLK_POWER: KEY_POWER = -1; break;
                //case SDLK_EURO: KEY_EURO=-1;break;



            }
        }




    return false;
}




bool Input_sys::all_keys_up()
{
    if ((KEY_a == -1) && (KEY_b == -1) && (KEY_c == -1) && (KEY_d == -1) && (KEY_e == -1) &&
        (KEY_f == -1) && (KEY_g == -1) && (KEY_h == -1) && (KEY_i == -1) && (KEY_j == -1) &&
        (KEY_k == -1) && (KEY_l == -1) && (KEY_m == -1) && (KEY_n == -1) && (KEY_o == -1) &&
        (KEY_p == -1) && (KEY_q == -1) && (KEY_r == -1) && (KEY_s == -1) && (KEY_t == -1) &&
        (KEY_u == -1) && (KEY_v == -1) && (KEY_w == -1) && (KEY_v == -1) && (KEY_y == -1) &&
        (KEY_z == -1) && (KEY_RETURN == -1))
    {
        return true;

    }
    return false;
}
bool Input_sys::any_keys_down()
{
    if (((KEY_a == 1) && (KEY_a_up == true)) || ((KEY_b == 1) && (KEY_b_up == true)) || ((KEY_c == 1) && (KEY_c_up == true)) ||
        ((KEY_d == 1) && (KEY_d_up == true)) || ((KEY_e == 1) && (KEY_e_up == true)) || ((KEY_f == 1) && (KEY_f_up == true)) ||
        ((KEY_g == 1) && (KEY_g_up == true)) || ((KEY_h == 1) && (KEY_h_up == true)) || ((KEY_i == 1) && (KEY_i_up == true)) ||
        ((KEY_j == 1) && (KEY_j_up == true)) || ((KEY_k == 1) && (KEY_k_up == true)) || ((KEY_l == 1) && (KEY_l_up == true)) ||
        ((KEY_m == 1) && (KEY_m_up == true)) || ((KEY_n == 1) && (KEY_n_up == true)) || ((KEY_o == 1) && (KEY_o_up == true)) ||
        ((KEY_p == 1) && (KEY_p_up == true)) || ((KEY_q == 1) && (KEY_q_up == true)) || ((KEY_r == 1) && (KEY_r_up == true)) ||
        ((KEY_s == 1) && (KEY_s_up == true)) || ((KEY_t == 1) && (KEY_t_up == true)) || ((KEY_u == 1) && (KEY_u_up == true)) ||
        ((KEY_w == 1) && (KEY_w_up == true)) || ((KEY_x == 1) && (KEY_x_up == true)) || ((KEY_y == 1) && (KEY_y_up == true)) ||
        ((KEY_v == 1) && (KEY_v_up == true)) || ((KEY_z == 1) && (KEY_z_up == true)) || ((KEY_RETURN == 1) && (KEY_RETURN_up == true)))
    {
        return true;

    }

    return false;
}
void Input_sys::set_all_keys_down()
{
    KEY_a_up = false; KEY_b_up = false; KEY_c_up = false; KEY_d_up = false;
    KEY_e_up = false; KEY_f_up = false; KEY_g_up = false; KEY_h_up = false;
    KEY_i_up = false; KEY_j_up = false; KEY_k_up = false; KEY_l_up = false;
    KEY_m_up = false; KEY_n_up = false; KEY_o_up = false; KEY_p_up = false;
    KEY_q_up = false; KEY_r_up = false; KEY_s_up = false; KEY_t_up = false;
    KEY_u_up = false; KEY_v_up = false; KEY_w_up = false; KEY_x_up = false;
    KEY_y_up = false; KEY_z_up = false; KEY_RETURN_up = false;


}
void Input_sys::set_all_keys_up()
{
    KEY_a_up = true; KEY_b_up = true; KEY_c_up = true; KEY_d_up = true;
    KEY_e_up = true; KEY_f_up = true; KEY_g_up = true; KEY_h_up = true;
    KEY_i_up = true; KEY_j_up = true; KEY_k_up = true; KEY_l_up = true;
    KEY_m_up = true; KEY_n_up = true; KEY_o_up = true; KEY_p_up = true;
    KEY_q_up = true; KEY_r_up = true; KEY_s_up = true; KEY_t_up = true;
    KEY_u_up = true; KEY_v_up = true; KEY_w_up = true; KEY_x_up = true;
    KEY_y_up = true; KEY_z_up = true; KEY_RETURN_up = true;

}