#include "build_level.h"
#include "core_engine.h"

Build_Level::Build_Level()
{
    output_check=fopen("build.txt","w");
    //load_monster_data();
}
Build_Level::~Build_Level()
{
    
    if (output_check != NULL) {
        fclose(output_check);
        output_check = NULL;  
    }
    
    
    //load_monster_data();
}

bool  Build_Level::isWall(Core_Engine& core, int y, int x) {
    //return x >= 0 && x < map.size() && y >= 0 && y < map[0].size() && map[x][y] == '#';
    if ((x < 0) || (y < 0) || (y >= MAX_Y) || (x>=MAX_X)){
        return false;
    }
    return x >= 0 && x < MAX_X && y >= 0 && y < MAX_Y && core.game_data.dungeon_level[y][x].block_type == '#';
}

void  Build_Level::printTextureMap(Core_Engine& core) {
    
    std::string result,temp1;  // Initialize an empty string
    for (int i = 0; i < MAX_Y; i++)
    {
        result.clear();
        for (int j = 0; j < MAX_X; j++)
        {
            result.push_back(core.game_data.dungeon_level[i][j].block_type);


        }
        printf("%s\n", result.c_str());
    }
    printf("\n");
    for (int i = 0; i < MAX_Y; i++)
    {
        result.clear();
        for (int j = 0; j < MAX_X; j++)
        {

            result += std::to_string(core.game_data.dungeon_level[i][j].block_data.texture_id);


        }
        printf("%s\n", result.c_str());
    }



    
}
void  Build_Level::test_new_print(Core_Engine& core) {

    
    printf("testing new eat rock\n");
    std::string result, temp1;  // Initialize an empty string
    for (int i = 0; i < MAX_Y; i++)
    {
        result.clear();
        for (int j = 0; j < MAX_X; j++)
        {
            result.push_back(core.game_data.dungeon_level_test[i][j].block_type);


        }
        printf("%s\n", result.c_str());
    }
    printf("\n");
    




}



void Build_Level::make_maze(int level,Core_Engine &core)
{
    //FILE *dungeon_check=fopen("dungeon_check.txt","w");

    int temp_x,temp_y, /*temp_yl,*/ temp_yh, temp_xl, /*temp_xh,*/ temp;
    int premade=rand()%100;
    premade=30;
    bool premade_used = false;
    premade_offset = 0;
   // fprintf(dungeon_check,"level=%i, c1\n",level);
    clean_level(core);
    if(level==0)
    {
        printf("\n...overworld...\n");
        //make_overworld(dungeon, level_info);
        //make_overworld(core);
    }else
    {
       if((premade<=100)&&(level!=1))
       {
            //load_premade(level,dungeon,level_info);
            //load_premade(level,core);
            premade_used=true;
            printf("using premade\n");
       }else
       {
           printf("using random\n");
            for(int i=0;i<MAX_Y;i++)
            {
                for (int j=0;j<MAX_X;j++)
                {
                    core.game_data.dungeon_level[i][j].block_type='#';
                    core.game_data.dungeon_level_test[i][j].block_type = '#';
                    core.game_data.dungeon_level[i][j].object=false;
                    //core.game_data.dungeon_level[i][j].object_index=-1;
                    core.game_data.dungeon_level[i][j].monster_index = -1;
                    //core.game_data.dungeon_level[i][j].object_symbol='~';
                    core.game_data.dungeon_level[i][j].visible=true;
                    core.game_data.dungeon_level[i][j].prox_ripple_value=256;
                    //core.game_data.dungeon_level[i][j].color= SILVER;
                    core.game_data.dungeon_level[i][j].player_loc=false;
                    core.game_data.dungeon_level[i][j].gold = false;
                    //core.game_data.dungeon_level[i][j].visited = false;
                }
            }
            eat_rock(level,1,1, core);
            printf("starting new eat rock\n");
            eat_rock_newest(level, 1, 1, core);
            test_new_print(core);
            printf("done\n");
            if (core.game_data.dungeon_level[1][1].block_type == '#' && core.game_data.dungeon_level[1][2].block_type == '.')
            {
                core.game_data.dungeon_level[1][1].block_type = '.';
            }


            /*  not sure what this does
            temp=rand()%6+3;

            for(int i=0;i<=temp;i++)
            {
                temp_y = (rand()%10)+1;
                //temp_yl = temp_y - rand()%2;
                temp_yh = temp_y + rand()%4+3;

                if (temp/2 ==0)
                {
                    temp_x = rand()%44+10;
                    temp_xl = temp_x - rand()%10+5;
                    //temp_xh = temp_x + rand()%12+3;
                }
                else
                {
                    temp_x = rand()%50+5;
                    temp_xl = temp_x - rand()%4+7;
                    //temp_xh = temp_x + rand()%2;
                }
                    for(int k=temp_y;k<temp_yh;k++)
                   {
                        for(int j=temp_x;j<temp_xl;j++)
                        {
                            core.game_data.dungeon_level[k][j].block_type='.';
                            core.game_data.dungeon_level[k][j].color=GREEN;
                           // fprintf(dungeon_check,"k=%i, j=%i\n",k,j);
                        }
                   }
            }
            */
            if (level>1)
            {
                treasureroom(level,core);
            }
       }//end not premade

       if (!premade_used)
       {
           for(int i=0;i<MAX_Y;i++)
            {
               core.game_data.dungeon_level[i][0].block_type='#';
                core.game_data.dungeon_level[i][MAX_X-1].block_type='#';
            }
           for(int k=1;k<=level;k++)
           {
                for(int i=0;i<MAX_X;i++)
                {
                    core.game_data.dungeon_level[0][i].block_type='#';
                    core.game_data.dungeon_level[MAX_Y-1][i].block_type='#';
                }
           }
       }


       //add_objects(MAX_Y, MAX_X, level, core, premade_offset);


      

  /************create the gold***************/
        //add_gold(MAX_Y, MAX_X, level, core);


  /********* create monsters *********/
        int num_monsters=(rand()%5)+20;
        int mon_index=0;
        //int mon_selection;

        //for(int i=0;i<num_monsters;i++)
        //{

        //   
        //    temp_x = rand()%(MAX_X-2)+1;
        //    temp_y=rand()%(MAX_Y-2)+1;
        //    while((core.game_data.dungeon_level[temp_y][temp_x].block_type=='#') || (core.game_data.dungeon_level[temp_y][temp_x].block_type == '`') ||(core.game_data.dungeon_level[temp_y][temp_x].monster)||((temp_y==(MAX_Y-2))&&(temp_x==MAX_X/2)))
        //    {

        //        temp_x = rand()%(MAX_X-2)+1;
        //        temp_y = rand()%(MAX_Y-2)+1;
        //    }
        //    //printf("\nmaking monster #%d &%d,%d\n",i+1,temp_x,temp_y);
        //    core.game_data.dungeon_level[temp_y][temp_x].monster=true;
        //    core.game_data.dungeon_level[temp_y][temp_x].monster_index= core.monsters.add_Monster(temp_x,temp_y, core.game_data.current_level);
        //}


     printf("\n...end make dungeon level\n");
    }
    printf("\n..end make maze..\n");
    std::string result;  // Initialize an empty string
    for (int i = 0; i < MAX_Y; i++)
    {
        result.clear();
        for (int j = 0; j < MAX_X; j++)
        {
            //core.game_data.dungeon_level[i][j].block_type = '#';
            result.push_back(core.game_data.dungeon_level[i][j].block_type);

            // Push characters into the string
            
        }
        fprintf(output_check, "%s\n", result.c_str());
    }

    result = "\n";
    int x1=0, x2 = 0, x3 = 0, y1 = 0, y2 = 0, y3=0;

    std::string temp1;
    //fprintf(output_check, "%s\n", result.c_str());

    for (int i = 0; i < MAX_Y; i++)
    {
        for (int j = 0; j < MAX_X; j++)
        {
            bool up = isWall( core , i - 1, j);
            bool down = isWall(core, i + 1, j);
            bool left = isWall(core, i, j - 1);
            bool right = isWall(core, i, j + 1);
            bool center = isWall(core, i, j);




            //FLOOR = 25, WALL = 2, INTERSECTION = 6,VERTICAL = 11, HORIZONTAL = 15
            // CORNER_TOP_LEFT = 4, CORNER_TOP_RIGHT = 3, CORNER_BOTTOM_LEFT = 9, CORNER_BOTTOM_RIGHT = 16,  
            // T_INTERSECTION_UP = 1,  T_INTERSECTION_DOWN = 8, T_INTERSECTION_LEFT = 2,  T_INTERSECTION_RIGHT = 7,
            // END_LEFT = 10,  END_RIGHT = 14,  END_UP = 13,END_DOWN = 12,
                
            if (!center)
            {
                core.game_data.dungeon_level[i][j].block_data.texture_id = FLOOR;
            }
            else if (center && up && down && left && right) {
                core.game_data.dungeon_level[i][j].block_data.texture_id = INTERSECTION;
            }
            else if (center && up && down && (left || right)) {
                if (left) {
                    core.game_data.dungeon_level[i][j].block_data.texture_id = T_INTERSECTION_LEFT;
                }
                else {
                    core.game_data.dungeon_level[i][j].block_data.texture_id = T_INTERSECTION_RIGHT;
                }
            }
            else if (center && left && right && (up || down)) {
                if (up) {
                    core.game_data.dungeon_level[i][j].block_data.texture_id = T_INTERSECTION_DOWN;
                }
                else {
                    core.game_data.dungeon_level[i][j].block_data.texture_id = T_INTERSECTION_UP;
                }
            }
            else if (center && up && down) {
                core.game_data.dungeon_level[i][j].block_data.texture_id = VERTICAL;
            }
            else if (center && left && right) {
                core.game_data.dungeon_level[i][j].block_data.texture_id = HORIZONTAL;


            }
            else if (center && up && left) {
                core.game_data.dungeon_level[i][j].block_data.texture_id = CORNER_BOTTOM_RIGHT;
            }
            else if (center && up && right) {
                core.game_data.dungeon_level[i][j].block_data.texture_id = CORNER_BOTTOM_LEFT;
            }
            else if (center && down && left) {
                core.game_data.dungeon_level[i][j].block_data.texture_id = CORNER_TOP_LEFT;
            }
            else if (center  && down && right) {
                core.game_data.dungeon_level[i][j].block_data.texture_id = CORNER_TOP_RIGHT;
            }
            else if (center && up) {
                core.game_data.dungeon_level[i][j].block_data.texture_id = END_UP;
            }
            else if (center && right) {
                core.game_data.dungeon_level[i][j].block_data.texture_id = END_RIGHT;
            }
            else if (center && left) {
                core.game_data.dungeon_level[i][j].block_data.texture_id = END_LEFT;
            }
            else if (center && down) {
                core.game_data.dungeon_level[i][j].block_data.texture_id = END_DOWN;
            }
        }
    }
    //printTextureMap(core);

   

    fclose(output_check);
    return;
}


void Build_Level::eat_rock(int lv,int y, int x, Core_Engine& core)
{
    int direction, trys;
    direction=rand()%4+1;
    //direction=2;
    trys=2;
    while(trys)
    {
        switch(direction)
        {
            case 1:
                if(x<=2)
                    break; /*west edge*/
                if((core.game_data.dungeon_level[y-1][x].block_type!='#')||(core.game_data.dungeon_level[y-2][x].block_type!='#'))
                    break;
                core.game_data.dungeon_level[y-1][x].block_type='.';
                //core.game_data.dungeon_level[y-1][x].color=GREEN;
                core.game_data.dungeon_level[y-2][x].block_type='.';
                //core.game_data.dungeon_level[y-2][x].color=GREEN;
                eat_rock(lv,y-2,x, core);
            break;
            case 2:
                if(y>=MAX_Y-3)
                    break; /*west edge*/
                if((core.game_data.dungeon_level[y+1][x].block_type!='#')||(core.game_data.dungeon_level[y+2][x].block_type!='#'))
                    break;
                core.game_data.dungeon_level[y+1][x].block_type='.';
                //core.game_data.dungeon_level[y+1][x].color=GREEN;
                core.game_data.dungeon_level[y+2][x].block_type='.';
                //core.game_data.dungeon_level[y+2][x].color=GREEN;
                eat_rock(lv,y+2,x,core);
            break;
            case 3:
                if(x<=2)
                    break; /*west edge*/
                if((core.game_data.dungeon_level[y][x-1].block_type!='#')||(core.game_data.dungeon_level[y][x-2].block_type!='#'))
                    break;
                core.game_data.dungeon_level[y][x-1].block_type='.';
                //core.game_data.dungeon_level[y][x-1].color=GREEN;
                core.game_data.dungeon_level[y][x-2].block_type='.';
                //core.game_data.dungeon_level[y][x-2].color=GREEN;
                eat_rock(lv,y,x-2, core);
            break;
            case 4:
                if(x>=MAX_X-3)
                    break; /*west edge*/
                if((core.game_data.dungeon_level[y][x+1].block_type!='#')||(core.game_data.dungeon_level[y][x+2].block_type!='#'))
                    break;
                core.game_data.dungeon_level[y][x+1].block_type='.';
                //core.game_data.dungeon_level[y][x+1].color=GREEN;
                core.game_data.dungeon_level[y][x+2].block_type='.';
                //core.game_data.dungeon_level[y][x+2].color=GREEN;
                eat_rock(lv,y,x+2, core);
            break;
        };
        if(++direction>4)
        {
            direction=1;
            --trys;
        }
    }

    return;
}


void Build_Level::eat_rock_newest(int lv, int start_y, int start_x, Core_Engine& core)
{
    std::stack<Position> stack;

    // ✅ Ensure the starting position is open for carving
    if (start_x <= 0 || start_y <= 0 || start_x >= MAX_X - 1 || start_y >= MAX_Y - 1) {
        std::cerr << "Invalid starting position: (" << start_x << ", " << start_y << ")\n";
        return;
    }
    core.game_data.dungeon_level_test[start_y][start_x].block_type = '.';
    stack.push({ start_x, start_y }); // ✅ Add first position

    while (!stack.empty()) {
        Position current = stack.top();
        stack.pop();

        int x = current.x, y = current.y;

        // ✅ Ensure carving within the grid
        if (x <= 0 || y <= 0 || x >= MAX_X - 1 || y >= MAX_Y - 1) continue;
        if (core.game_data.dungeon_level_test[y][x].block_type != '#') continue; // Already visited

        // ✅ Carve the current tile
        core.game_data.dungeon_level_test[y][x].block_type = '.';

        // ✅ Randomize movement directions
        std::vector<int> directions = { 1, 2, 3, 4 }; // 1=N, 2=S, 3=W, 4=E
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(directions.begin(), directions.end(), g);

        for (int direction : directions) {
            int nx = x, ny = y;

            switch (direction) {
            case 1: ny -= 2; break; // North
            case 2: ny += 2; break; // South
            case 3: nx -= 2; break; // West
            case 4: nx += 2; break; // East
            }

            if (nx > 0 && ny > 0 && nx < MAX_X - 1 && ny < MAX_Y - 1 &&
                core.game_data.dungeon_level_test[ny][nx].block_type == '#') {

                // ✅ Check if the tile is surrounded by walls (prevents breaking structure)
                int wall_count = 0;
                if (core.game_data.dungeon_level_test[ny - 1][nx].block_type == '#') wall_count++;
                if (core.game_data.dungeon_level_test[ny + 1][nx].block_type == '#') wall_count++;
                if (core.game_data.dungeon_level_test[ny][nx - 1].block_type == '#') wall_count++;
                if (core.game_data.dungeon_level_test[ny][nx + 1].block_type == '#') wall_count++;

                if (wall_count >= 3) {
                    // ✅ Open a passage between current and next tile
                    core.game_data.dungeon_level_test[y + (ny - y) / 2][x + (nx - x) / 2].block_type = '.';

                    // ✅ Push the new position onto the stack
                    stack.push({ nx, ny });

                    // ✅ Debug log
                    std::cerr << "Carving path from (" << x << ", " << y << ") to (" << nx << ", " << ny << ")\n";
                }
            }
        }
    }

    // ✅ Log the final dungeon map
    std::ofstream logFile("dungeon_log.txt");
    for (int y = 0; y < MAX_Y; y++) {
        for (int x = 0; x < MAX_X; x++) {
            logFile << core.game_data.dungeon_level_test[y][x].block_type;
        }
        logFile << "\n";
    }
    logFile.close();

    std::cout << "Dungeon map logged to dungeon_log.txt\n";

}



void Build_Level::eat_rock_new(int lv, int y, int x, Core_Engine& core, int depth)
{
	//test_new_print(core);


    if (carved_tiles > MAX_CARVED_TILES) {
        //std::cerr << "Max carved tiles reached. Stopping recursion.\n";
        return;
    }
    
    
    if (depth > MAX_RECURSION_DEPTH) {
        //std::cerr << "Max recursion depth reached at (" << x << ", " << y << ")\n";
        return;  // Stop recursion to avoid a crash
    }

    if (x <= 0 || y <= 0 || x >= MAX_X - 1 || y >= MAX_Y - 1) {
        std::cerr << "Out of bounds: (" << x << ", " << y << ")\n";
        return;
    }


    if (core.game_data.dungeon_level_test[y][x].block_type != '#') {
        //std::cerr << "Already cleared: (" << x << ", " << y << ")\n";
        return;
    }
    std::vector<int> directions = { 1, 2, 3, 4 }; // 1=North, 2=South, 3=West, 4=East
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(directions.begin(), directions.end(), g); // Shuffle directions

    core.game_data.dungeon_level_test[y][x].block_type = '.'; // Mark as path
    //std::cerr << "Carving path at (" << x << ", " << y << ") - Depth: " << depth << "\n";

    carved_tiles++; // Increment carved count

    for (int direction : directions) 
    {
        int nx = x, ny = y;

        switch (direction) {
        case 1: ny -= 2; break; // North
        case 2: ny += 2; break; // South
        case 3: nx -= 2; break; // West
        case 4: nx += 2; break; // East
        }

        // Bounds check
        if (nx <= 0 || ny <= 0 || nx >= MAX_X - 1 || ny >= MAX_Y - 1) {
            std::cerr << "Skipping out-of-bounds move to (" << nx << ", " << ny << ")\n";
            continue; // Prevent moving out-of-bounds
        }

        // Ensure the path isn't already carved
        if (core.game_data.dungeon_level_test[ny][nx].block_type == '#') {
            // Clear path
            core.game_data.dungeon_level_test[y + (ny - y) / 2][x + (nx - x) / 2].block_type = '.';
            //core.game_data.dungeon_level_test[ny][nx].block_type = '.';
            std::cerr << "Depth: " << depth << ", Carving (" << x << ", " << y << ") -> (" << nx << ", " << ny << ")|\n";
            // Recur with the new position
            eat_rock_new(lv, ny, nx, core,depth+1);
        }
    }




    return;
}




//
//void Build_Level::treasureroom(int lv,MAP_BLOCK dungeon[1+MAX_DUNGEON_LEVEL+MAX_VOLCANO_LEVEL][MAX_Y][MAX_X+1])
//void Build_Level::treasureroom(int lv,MAP_BLOCK dungeon[MAX_Y][MAX_X+1])
void Build_Level::treasureroom(int lv, Core_Engine& core)
{
	int tx, ty, xsize, ysize;
    //fprintf(output_check,"here1 level=%i \n",lv);
	//rand()%4+1;
	for (tx=rand()%10+2;  tx<MAX_X-11;  tx+=10)
    {
   // fprintf(output_check,"here2 tx=%i \n",tx);
		if ( (lv==MAX_DUNGEON_LEVEL-1) || ((rand()%2+1)==2))
		{
		   // fprintf(output_check,"here3 \n");
			xsize = (rand()%6+1)+3;
			ysize = (rand()%3+1)+3;
			//fprintf(output_check,"here4  xsize=%i  ysize=%i \n",xsize,ysize);
			ty = (rand()%(MAX_Y-10)+2);  /* upper left corner of room */
			//fprintf(output_check,"here5  ty=%i \n",ty);
//			if (lv==MAX_DUNGEON_LEVEL-1 || lv==MAX_DUNGEON_LEVEL+MAX_VOLCANO_LEVEL-1)
//				troom(lv,xsize,ysize,tx+(rand()%(MAX_X-24)+1),ty,(rand()%3+1)+6,dungeon);
//			else
            troom(lv,xsize,ysize,tx,ty,rand()%9+1  , core);
            break;
        }

    }
}
//
//void Build_Level::troom(int lv, int xsize, int ysize, int tx, int ty, int glyph ,MAP_BLOCK dungeon[1+MAX_DUNGEON_LEVEL+MAX_VOLCANO_LEVEL][MAX_Y][MAX_X+1])
//void Build_Level::troom(int lv, int xsize, int ysize, int tx, int ty, int glyph ,MAP_BLOCK dungeon[MAX_Y][MAX_X+1])
void Build_Level::troom(int lv, int xsize, int ysize, int tx, int ty, int glyph, Core_Engine& core)
{
	int i, j;
	//int tp1, tp2;
	int temp_x,temp_y;
	int f_x,f_y;
    //fprintf(output_check,"here6  \n",ty);
	for (j=ty-1; j<=ty+ysize; j++)
    {

        for (i=tx-1; i<=tx+xsize; i++)          /* clear out space for room */
		{
		//    fprintf(output_check,"here7  j=%i  i=%i \n",j,i);
            core.game_data.dungeon_level[j][i].block_type='.';
            //core.game_data.dungeon_level[j][i].color=GREEN;
		}
    }

	for (j=ty; j<ty+ysize; j++)
	{
	    for (i=tx; i<tx+xsize; i++)             /* now put in the walls */
		{
            core.game_data.dungeon_level[j][i].block_type='#';

			//mitem[i][j]=0;
		}
    }
		for (j=ty+1; j<ty+ysize-1; j++)
		{
                for (i=tx+1; i<tx+xsize-1; i++)         /* now clear out interior */
                    core.game_data.dungeon_level[j][i].block_type='.';
                //core.game_data.dungeon_level[j][i].color=GREEN;
		}

        temp_x = rand()%2;
        temp_y=rand()%2;


        //fprintf(output_check,"temp_x=set_visible(player,false,false,false);%i, temp_y=%i  \n",temp_x,temp_y);
		switch(rand()%2+1)      /* locate the door on the treasure room */
		{
		case 1:
            f_x=tx+(xsize-1)*temp_x;
            f_y=ty+rand()%ysize;
            core.game_data.dungeon_level[f_y][f_x].object=true;
			//dungeon[lv][f_y][f_x].object_index=objects.add_object('D',f_x,f_y);
			//game_data.dungeon_level[f_y][f_x].object_symbol='D';
            //core.game_data.dungeon_level[f_y][f_x].object_index = core.game_data.OCLOSEDDOOR;
            //game_data.dungeon_level[f_y][f_x].object_index = objects.add_object('a', temp_x, temp_y, GREEN, 1, 1);

			//dungeon[ty+rand()%ysize][tx+(xsize-1)*temp_x].block_type='D';

			break;
		case 2:
			//dungeon[ty+(ysize-1)*temp_y][tx+rand()%xsize].block_type='D';
			f_x=tx+rand()%xsize;
			f_y=ty+(ysize-1)*temp_y;

            core.game_data.dungeon_level[f_y][f_x].object=true;
			//dungeon[lv][f_y][f_x].object_index=objects.add_object('D',f_x,f_y);
            //game_data.dungeon_level[f_y][f_x].object_symbol='D';
            //core.game_data.dungeon_level[f_y][f_x].object_index = core.game_data.OCLOSEDDOOR;
            //game_data.dungeon_level[f_y][f_x].object_index = objects.add_object('a', temp_x, temp_y, GREEN, 1, 1);
			break;
		};

}
//


//void Build_Level::make_overworld(Core_Engine& core)
//{
//        int temp_x,temp_y;
//        printf("\t\tgame_data odoorclosed=%d\n", core.game_data.OCLOSEDDOOR);
//        printf("\n.....make overworld.....\n");
//        for(int i=0;i<MAX_Y;i++)
//        {
//            fprintf(output_check,"\ny=%d\n",i);
//            //printf("game_data odoorclosed=%d, %d\ngame_data odoorclosed=%d, %d\n", core.game_data.OCLOSEDDOOR,i,core.game_data.OOPENDOOR,i);
//            for (int j=0;j<MAX_X;j++)
//            {
//                //fprintf(output_check, "x=%d,", j);
//                core.game_data.dungeon_level[i][j].block_type='.';
//                core.game_data.dungeon_level[i][j].color=RED;
//                core.game_data.dungeon_level[i][j].object=false;
//                core.game_data.dungeon_level[i][j].object_index=-1;
//                core.game_data.dungeon_level[i][j].visible=true;
//                core.game_data.dungeon_level[i][j].prox_ripple_value=128;
//                core.game_data.dungeon_level[i][j].player_loc=false;
//            }
//
//        }
//       // printf("game_data odoorclosed=%d\n", core.game_data.OCLOSEDDOOR);
//       temp_x=5;
//       temp_y=5;
//       //adding entrance to dungeon
//       core.game_data.dungeon_level[temp_y][temp_x].object_index = core.game_data.OENTRANCE;
//       core.game_data.dungeon_level[temp_y][temp_x].object=true;
//        printf("%d\n", core.game_data.dungeon_level[temp_y][temp_x].object_index);
//        temp_x=6;
//       temp_y=7;
//
//        core.game_data.dungeon_level[temp_y][temp_x].object_index = core.game_data.ODNDSTORE;
//          printf("%d\n", core.game_data.dungeon_level[temp_y][temp_x].object_index);
//       core.game_data.dungeon_level[temp_y][temp_x].object=true;
//
//       temp_x = 10;
//       temp_y = 8;
//
//       core.game_data.dungeon_level[temp_y][temp_x].object_index = core.game_data.OTRADEPOST;
//       printf("%d\n", core.game_data.dungeon_level[temp_y][temp_x].object_index);
//       core.game_data.dungeon_level[temp_y][temp_x].object = true;
//
//       temp_x = 9;
//       temp_y = 10;
//
//       core.game_data.dungeon_level[temp_y][temp_x].object_index = core.game_data.OBANK;
//       printf("%d\n", core.game_data.dungeon_level[temp_y][temp_x].object_index);
//       core.game_data.dungeon_level[temp_y][temp_x].object = true;
//
//       //printf("game_data odoorclosed=%d\n", core.game_data.OCLOSEDDOOR);
//         temp_x=5;
//       temp_y=10;
//
//       core.game_data.dungeon_level[temp_y][temp_x].object_index = 3+ core.game_data.ITEM_OFFSET;
//       printf("%d\n", core.game_data.dungeon_level[temp_y][temp_x].object_index);
//         core.game_data.dungeon_level[temp_y][temp_x].object=true;
//         temp_x = 7;
//         temp_y = 10;
//
//         core.game_data.dungeon_level[temp_y][temp_x].object_index = 15 + core.game_data.ITEM_OFFSET;
//         printf("%d\n", core.game_data.dungeon_level[temp_y][temp_x].object_index);
//         core.game_data.dungeon_level[temp_y][temp_x].object = true;
//
//
//
//
//
//        printf("\n.end make overworld.\n");
//
//}


//void Build_Level::load_premade(int level, Core_Engine& core)
//{
//     //FILE *resource_file = fopen("gamedata\\resources\\graphics\\mazefile.txt","r");
//
//     //FILE *out_file = fopen("gamedata\\resources\\premade_check.txt","w");
//        unsigned char temp;
//        char str[70];
//        char str2[100];
//        //char line[MAX_X+5];
//        int n;
//        int rand_level =(rand()%24)*18;
//        //rand_level=0;
//        n=sprintf(str2,"gamedata/resources/graphics/mazefiles/mazefile_%i.dat",rand_level/18);
//        //printf("\n%s",str2);
//
//        FILE *resource_file_2 = fopen(str2,"r");
//        if (resource_file_2 == NULL) {
//            printf("\nFailed: \n");
//            return;
//        }
//        printf("\n%s\n",str2);
//        int premade_height=0;
//        int premade_offset=0;
//
//        int premade_color;
//
//
//        for(int i=0;i<rand_level;i++)
//        {
//                //printf("reading lines, rand_level=%i\n",rand_level);
//                //fgets(line,MAX_X+5,resource_file);
//        }
//
//
//
//
//        //fscanf(resource_file,"%i %i\n",&premade_height,&premade_color);
//        int nnn;
//        nnn=fscanf(resource_file_2,"%i %i\n",&premade_height,&premade_color);
//        printf("premade_height=%i\n",premade_height);
//        //premade_offset=(MAX_Y-premade_height)/2;
//        
//   
//
//        premade_offset=(MAX_Y-(premade_height*2))/2;
//        printf("premade_offset=%i\n", premade_offset);
//        
//        if(premade_offset%2==1)
//        {
//            for (int y = 0; y < premade_offset+1; y++)
//            {
//                for (int x = 0; x < MAX_X + 1; x++)
//                {
//                    core.game_data.dungeon_level[y][x].block_type = '`';
//
//
//                    core.game_data.dungeon_level[y][x].object_symbol = '~';
//                    core.game_data.dungeon_level[y][x].gold = false;
//                }
//            }
//        }
//        else
//        {
//            for (int y = 0; y < premade_offset; y++)
//            {
//                for (int x = 0; x < MAX_X + 1; x++)
//                {
//                    core.game_data.dungeon_level[y][x].block_type = '`';
//                    core.game_data.dungeon_level[y][x].object_symbol = '~';
//                    core.game_data.dungeon_level[y][x].gold = false;
//                }
//            }
//
//
//        }
//
//        if (premade_offset % 2 == 1)
//        {
//            for (int y = (MAX_Y - (premade_offset+1)); y < MAX_Y; y++)
//            {
//                printf("premade top y =%i\n", y);
//                for (int x = 0; x < MAX_X + 1; x++)
//                {
//                    core.game_data.dungeon_level[y][x].block_type = '`';
//                    core.game_data.dungeon_level[y][x].object_symbol = '~';
//                    core.game_data.dungeon_level[y][x].gold = false;
//                }
//            }
//        }
//        else
//        {
//            for (int y = (MAX_Y - premade_offset); y < MAX_Y; y++)
//            {
//                printf("premade top y =%i\n", y);
//                for (int x = 0; x < MAX_X + 1; x++)
//                {
//                    core.game_data.dungeon_level[y][x].block_type = '`';
//                    core.game_data.dungeon_level[y][x].object_symbol = '~';
//                    core.game_data.dungeon_level[y][x].gold = false;
//                }
//            }
//
//
//        }
//
//
//
//
//
//        for(int y= 0;y<(premade_height*2);y=y+2)
//        {
//           // printf("y=%i ",y);
//            n=fscanf(resource_file_2,"%s",str);
//            for(int x=0;x<MAX_X+1;x++)
//            {
//                //fscanf(resource_file,"%hhc",dungeon[level][y][x].bloc);
//                //fscanf(resource_file,"%hhc",&temp);
//                temp=str[x];
//                if(temp=='D')
//                {
//                    core.game_data.dungeon_level[y+premade_offset][x].object=true;
//                    //game_data.dungeon_level[y+premade_offset][x].object_symbol='D';
//                    core.game_data.dungeon_level[y + premade_offset][x].object_index = core.game_data.OCLOSEDDOOR;
//                    //game_data.dungeon_level[y + premade_offset][x].object_index = objects.add_object('a', x, y + premade_offset, GREEN, 1, 1);
//                   //objects.object_list[game_data.dungeon_level[y + premade_offset][x].object_index].color = ORANGE;
//                    core.game_data.dungeon_level[y+premade_offset][x].block_type='.';
//                    core.game_data.dungeon_level[y+premade_offset][x].color=1;
//                    
//
//                    core.game_data.dungeon_level[y + premade_offset+1][x].block_type = '.';
//                    core.game_data.dungeon_level[y + premade_offset + 1][x].object = true;
//                    core.game_data.dungeon_level[y + premade_offset + 1][x].object_index = core.game_data.OCLOSEDDOOR;
//                    //game_data.dungeon_level[y + premade_offset + 1][x].object_index = objects.add_object('a', x, y + premade_offset, GREEN, 1, 1);
//                    //objects.object_list[game_data.dungeon_level[y + premade_offset+1][x].object_index].color = ORANGE;
//                    //game_data.dungeon_level[y + premade_offset + 1][x].object_symbol = 'd';
//                    //game_data.dungeon_level[y + premade_offset + 1][x].object_symbol = 'D';
//                    core.game_data.dungeon_level[y + premade_offset + 1][x].color = 1;
//                    
//                }else
//                {
//                    core.game_data.dungeon_level[y+premade_offset][x].block_type=temp;
//                    core.game_data.dungeon_level[y+premade_offset][x].object=false;
//                    core.game_data.dungeon_level[y+premade_offset][x].object_index=-1;
//                    core.game_data.dungeon_level[y+premade_offset][x].object_symbol='~';
//                    core.game_data.dungeon_level[y+premade_offset][x].color=premade_color;
//
//                    core.game_data.dungeon_level[y + premade_offset + 1][x].block_type = temp;
//                    core.game_data.dungeon_level[y + premade_offset + 1][x].object = false;
//                    core.game_data.dungeon_level[y + premade_offset + 1][x].object_index = -1;
//                    core.game_data.dungeon_level[y + premade_offset + 1][x].object_symbol ='~';
//                    core.game_data.dungeon_level[y + premade_offset + 1][x].color = premade_color;
//                }
//
//                core.game_data.dungeon_level[y+premade_offset][x].visible=true;
//                core.game_data.dungeon_level[y+premade_offset][x].prox_ripple_value=256;
//                    core.game_data.dungeon_level[y + premade_offset][x].gold = false;
//                    core.game_data.dungeon_level[y + premade_offset+1][x].visible = true;
//                    core.game_data.dungeon_level[y + premade_offset+1][x].prox_ripple_value = 256;
//                    core.game_data.dungeon_level[y + premade_offset + 1][x].gold = false;
//                //fprintf(out_file,"%c",temp);
//            }
//
//        }
//
//
//
//     //fclose(resource_file);
//          fclose(resource_file_2);
//     //fclose(out_file);
//
//}



//void Build_Level::change_level(Core_Engine& core,int destination)
//{
//    int /*n,*/ last_level = 0;
//    //char file_name[30];
//    printf("*****  loading new level current level=%d, destination level =%d", core.game_data.current_level, destination);
//    
//    save_level(core);
//    
//    printf("saving old level\n");
//    
//    
//    if (core.game_data.current_level > 0)
//    {
//        last_level = core.game_data.current_level;
//        printf("leaving level(last level)=%d\n", last_level);
//    }
//    else
//    {
//        last_level = 0;
//    }
//    
//    if(destination>=MAX_DUNGEON_LEVEL)
//    {
//        destination=MAX_DUNGEON_LEVEL-1;
//
//        core.game_data.current_level=destination;
//    }
//    if(!core.game_data.level_visited[destination])
//    {
//        printf("level not visited\n");
//        core.game_data.last_level_down_x = core.game_data.current_level_down_x;
//        core.game_data.last_level_down_y = core.game_data.current_level_down_y;
//
//        new_level(core,destination);
//
//    }else
//    {
//        printf("level visited\n");
//        //n = sprintf(filename, "map_char_%i.op", game_data.current_level);
//        //FILE* output = fopen();
//        //load_level(game_data);
//        printf("\n loading level\n");
//        load_level(core, destination);
//        printf("\n complete level load 1\n");
//    }
//
//    return;
//}


void Build_Level::new_level(Core_Engine& core, int destination)
{
    printf("\n at new level %i\n",destination);
    //if(game_data.current_level>=-1)
    //{
        if(core.game_data.current_level>=0)
        {
           // save_level(game_data, objects);
            //printf("\n saving old level\n");
            //save monster data
            //save object data
        }

        make_maze(destination, core);
        core.game_data.current_level=destination;
        //core.game_data.level_visited[destination]=true;
        //player.set_pos(game_data);
    //}

    return;
}

//void Build_Level::save_level(Core_Engine &core)
//{
//    char str[200];
//    int n;
//    printf("\n saving level \n");
//    n=sprintf(str,"gamedata/resources/graphics/mazefiles/saved/level_%i.dat", core.game_data.current_level);
//    FILE *saved_level= fopen(str,"w");
//    if (saved_level==NULL)
//    {
//        printf("\n saving level open file fail\n");
//    }
//    printf("\n saving level 1\n");
//    fprintf(saved_level,"block_type player_loc monster object gold monster_index object_index gold_value prox_ripple_value visible color\n");
//   
//
//    printf("\n saving level 2\n");
//    for(int i=0;i<MAX_Y;i++)
//    {
//        for(int j=0;j<MAX_X;j++)
//        {
//           fprintf(saved_level,"%d %d %c %d %d %d %d %d %d %d %d %d\n",
//               i,
//               j,
//               core.game_data.dungeon_level[i][j].block_type,
//               core.game_data.dungeon_level[i][j].monster,
//               core.game_data.dungeon_level[i][j].object,
//               core.game_data.dungeon_level[i][j].gold,
//               core.game_data.dungeon_level[i][j].monster_index,
//               core.game_data.dungeon_level[i][j].object_index,
//               core.game_data.dungeon_level[i][j].gold_value,
//               core.game_data.dungeon_level[i][j].prox_ripple_value,
//               core.game_data.dungeon_level[i][j].visible,
//               core.game_data.dungeon_level[i][j].color);
//        }
//        
//    }
//    printf("\n saving level 2\n");
//    
//    fprintf(saved_level, "%d\n", core.monsters.level_monsters.size());
//
//   for (unsigned int z = 0; z < core.monsters.level_monsters.size(); z++)
//   {
//       //fprintf(saved_level,"%d\n",)
//       fprintf(saved_level, "%d %d %d\n", core.monsters.level_monsters[z].x, core.monsters.level_monsters[z].y, core.monsters.level_monsters[z].index_value);
//   }
//   core.monsters.level_monsters.clear();
//    
//    fclose(saved_level);
//    return;
//}

void Build_Level::clean_level(Core_Engine& core)
{
    for (int i = 0; i < MAX_Y; i++)
    {
        for (int j = 0; j < MAX_X; j++)
        {
            core.game_data.dungeon_level[i][j].block_type = '#';
            core.game_data.dungeon_level[i][j].player_loc = false;
            core.game_data.dungeon_level[i][j].monster = false;
            core.game_data.dungeon_level[i][j].item = false;
            core.game_data.dungeon_level[i][j].object = false;
            core.game_data.dungeon_level[i][j].gold = false;
            core.game_data.dungeon_level[i][j].building = false;
            core.game_data.dungeon_level[i][j].monster_index = -1;
           // core.game_data.dungeon_level[i][j].item_index = -1;
            //game_data.dungeon_level[i][j].item_symbol = '-';
            //core.game_data.dungeon_level[i][j].object_index = -1;
            //core.game_data.dungeon_level[i][j].object_symbol = '-';
            core.game_data.dungeon_level[i][j].gold_value = -1;
            core.game_data.dungeon_level[i][j].prox_ripple_value = 99;
            core.game_data.dungeon_level[i][j].visible = true;
           
            //core.game_data.dungeon_level[i][j].color = BLACK;
         }

    }


    //core.monsters.level_monsters.clear();
}

//void Build_Level::load_level(Core_Engine & core, int destination)
//{
//    char str[200];
//    char temp_1[200];
//    //char temp_2[20];
//    //char temp_3[20];
//    //char temp_4[20];
//    //char temp_5[20];
//    //char temp_6[20];
//    //char temp_7[20];
//   // char temp_8[20];
//    //char temp_9[20];
//    //char temp_10[20];
//    //char temp_11[20];
//    //char temp_12[20];
//    //char temp_13[20];
//    //char temp_14[20];
//    //char temp_15[20];
//    //char temp_16[20];
//    //char temp_17[20];
//
//    unsigned char block_type;
//   // int player_loc;   //bool
//    int monster_bool;   //bool
//   // int item;   //bool
//    int object;   //bool
//    int gold;   //bool
//    //int building;   //bool
//    int monster_index;
//    //unsigned char monster_symbol;
//    //int item_index;
//    //unsigned char item_symbol;
//    int object_index;
//    //unsigned char object_symbol;
//    int gold_value;
//    int prox_ripple_value;
//    int visible;   //bool
//    
//    int color;  //Text_Colors
//
//    int x, y;
//
//    int index_value;
//    
//    int n;
//
//    int num_monsters;
//
//    printf("\n loading level %d\n", destination);
//    n = sprintf(str, "gamedata/resources/graphics/mazefiles/saved/level_%i.dat", destination);
//    FILE* load_level = fopen(str, "r");
//    //FILE* test_level = fopen("gamedata/resources/graphics/mazefiles/saved/test.txt", "w");
//    //n = fscanf(load_level, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n", temp_1, temp_2, temp_3, temp_4, temp_5, temp_6, temp_7, temp_8, temp_9, temp_10, temp_11, temp_12, temp_13, temp_14, temp_15, temp_16, temp_17);
//    //printf("%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n", temp_1, temp_2, temp_3, temp_4, temp_5, temp_6, temp_7, temp_8, temp_9, temp_10, temp_11, temp_12, temp_13, temp_14, temp_15, temp_16, temp_17);
//
//    fgets(temp_1, 200, load_level);
//    for (int i = 0; i < MAX_Y; i++)
//    {
//        for (int j = 0; j < MAX_X; j++)
//        {
//            
//            n = fscanf(load_level,"%d %d %c %d %d %d %d %d %d %d %d %d\n",&x,&y,&block_type, &monster_bool, &object, &gold, &monster_index,&object_index, &gold_value, &prox_ripple_value, &visible, &color);
//
//            core.game_data.dungeon_level[i][j].block_type = block_type;
//           /* if (player_loc == 0)
//            {
//                game_data.dungeon_level[i][j].player_loc = false;
//            }
//            else
//            {
//                game_data.dungeon_level[i][j].player_loc = true;
//            }*/
//            if (monster_bool == 0)
//            {
//                core.game_data.dungeon_level[i][j].monster = false;
//            }
//            else
//            {
//                core.game_data.dungeon_level[i][j].monster = true;
//            }
//            /*if (item == 0)
//            {
//                game_data.dungeon_level[i][j].item = false;
//            }
//            else
//            {
//                game_data.dungeon_level[i][j].item = true;
//            }*/
//            if (object == 0)
//            {
//                core.game_data.dungeon_level[i][j].object = false;
//            }
//            else
//            {
//                core.game_data.dungeon_level[i][j].object = true;
//            }
//            if (gold == 0)
//            {
//                core.game_data.dungeon_level[i][j].gold = false;
//            }
//            else
//            {
//                core.game_data.dungeon_level[i][j].gold = true;
//            }
//           /* if (building == 0)
//            {
//                game_data.dungeon_level[i][j].building = false;
//            }
//            else
//            {
//                game_data.dungeon_level[i][j].building = true;
//            }*/
//            core.game_data.dungeon_level[i][j].monster_index = monster_index;
//           // game_data.dungeon_level[i][j].item_index = item_index;
//           // game_data.dungeon_level[i][j].item_symbol = item_symbol;
//            core.game_data.dungeon_level[i][j].object_index = object_index;
//           // game_data.dungeon_level[i][j].object_symbol = object_symbol;
//            core.game_data.dungeon_level[i][j].gold_value = gold_value;
//            core.game_data.dungeon_level[i][j].prox_ripple_value = prox_ripple_value;
//            if (visible == 0)
//            {
//                core.game_data.dungeon_level[i][j].visible = false;
//            }
//            else
//            {
//                core.game_data.dungeon_level[i][j].visible = true;
//            }
//
//            //Text_Color_List{BLACK,WHITE,RED,GREEN,BLUE,GOLD,SILVER,ORANGE};
//            switch (color) {
//            case 0:
//                core.game_data.dungeon_level[i][j].color = BLACK;
//                break;
//            case 1:
//                core.game_data.dungeon_level[i][j].color = WHITE;
//                break;
//            case 2:
//                core.game_data.dungeon_level[i][j].color = RED;
//                break;
//            case 3:
//                core.game_data.dungeon_level[i][j].color = GREEN;
//                break;
//            case 4:
//                core.game_data.dungeon_level[i][j].color = BLUE;
//                break;
//            case 5:
//                core.game_data.dungeon_level[i][j].color = GOLD;
//                break;
//            case 6:
//                core.game_data.dungeon_level[i][j].color = SILVER;
//                break;
//            case 7:
//                core.game_data.dungeon_level[i][j].color = ORANGE;
//                break;
//            default:
//                core.game_data.dungeon_level[i][j].color = BLUE;
//            }
//
//        }
//        //fprintf(saved_level,"\n");
//    }
//    printf("map data loaded\n");
//    
//    //game_data.current_level = destination;
//   // num_monsters
//    n = fscanf(load_level, "%d \n", &num_monsters);
//    printf("num_monsters = %d\n", num_monsters);
//    for (int z = 0; z < num_monsters; z++)
//    {
//        printf("monster = %d\n", z);
//        n=fscanf(load_level, "%d %d %d\n", &x, &y, &index_value);
//        
//        core.monsters.load_level_monsters(x, y, index_value);
//
//
//
//    }
//
//    printf("\n loading level %d complete\n", destination);
//    core.game_data.current_level = destination;
//    return;
//}
//
//
//
//void Build_Level::add_objects(int max_y, int max_x, int level, Core_Engine &core,int offset)
//{
//    int temp_x, temp_y, y_range /*, x_range*/;
//    temp_x = rand() % (MAX_X - 10);
//    y_range = MAX_Y - max_y;
//    temp_y = rand() % (MAX_Y - 5);
//    if (y_range == 0)
//    {
//        temp_y = rand() % (MAX_Y - 5);
//    }
//    else
//    {
//        //temp_y= (rand() % ())
//    }
//
//    if (level == 1)
//    {
//        //add entrance
//        temp_x = MAX_X / 2;
//        temp_y = MAX_Y - 1;
//        core.game_data.dungeon_level[temp_y][temp_x].object = true;
//        core.game_data.dungeon_level[temp_y][temp_x].block_type = '.';
//        //game_data.dungeon_level[temp_y][temp_x].object_index = objects.add_object('a', temp_x, temp_y, GREEN, 1, 0);
//       
//        core.game_data.dungeon_level[temp_y][temp_x].object_index = core.game_data.OENTRANCE;
//    }
//
//    //temp_x = (MAX_X / 2)-1;
//     //temp_y = MAX_Y - 2;
//    //'`'
//    if (level < MAX_DUNGEON_LEVEL - 1)
//    {
//        while ((core.game_data.dungeon_level[temp_y][temp_x].object) || (core.game_data.dungeon_level[temp_y][temp_x].block_type == '#') || (core.game_data.dungeon_level[temp_y][temp_x].block_type == ' ') || (core.game_data.dungeon_level[temp_y][temp_x].block_type == '`'))
//        {
//            //temp_x = temp_x - 1;
//            temp_x = rand() % (MAX_X - 10);
//            temp_y = rand() % (MAX_Y - 5);
//        }
//        core.game_data.dungeon_level[temp_y][temp_x].object = true;
//        core.game_data.dungeon_level[temp_y][temp_x].object_index = core.game_data.OSTAIRSDOWN;
//        printf(" down stairs at y=%d,x=%d\n", temp_y, temp_x);
//    }
//    if (level > 1)
//    {
//        while ((core.game_data.dungeon_level[temp_y][temp_x].object) || (core.game_data.dungeon_level[temp_y][temp_x].block_type == '#') || (core.game_data.dungeon_level[temp_y][temp_x].block_type == ' ') || (core.game_data.dungeon_level[temp_y][temp_x].block_type == '`'))
//        {
//            //temp_x = temp_x - 1;
//            temp_x = rand() % (MAX_X - 10);
//            temp_y = rand() % (MAX_Y - 5);
//        }
//        core.game_data.dungeon_level[temp_y][temp_x].object = true;
//        core.game_data.dungeon_level[temp_y][temp_x].object_index = core.game_data.OSTAIRSUP;
//        printf(" up stairs at y=%d,x=%d, upvalue = %d\n", temp_y, temp_x,core.game_data.OSTAIRSUP);
//    }
//   
//    return;
//}
//
//
//
//void Build_Level::add_gold(int max_y, int max_x, int level, Core_Engine &core)
//{
//    //create the gold
//    int num_gold=(rand()%10)+10;
//    int temp_x, temp_y, gold_value;
//
//    printf("\n");
//    temp_x = rand() % (MAX_X - 2) + 1;
//    temp_y = rand() % (MAX_Y - 2) + 1;
//    for(int i=0;i<num_gold;i++)
//    {
//
//        while((core.game_data.dungeon_level[temp_y][temp_x].object)||(core.game_data.dungeon_level[temp_y][temp_x].block_type=='#') || (core.game_data.dungeon_level[temp_y][temp_x].block_type == '~') || (core.game_data.dungeon_level[temp_y][temp_x].block_type == '`') ||(core.game_data.dungeon_level[temp_y][temp_x].gold)||((temp_y==(MAX_Y-2))&&(temp_x==MAX_X/2)))
//        {
//
//            temp_x = rand() % (MAX_X - 2) + 1;
//            temp_y = rand() % (MAX_Y - 2) + 1;
//                
//        }
//        
//        
//        core.game_data.dungeon_level[temp_y][temp_x].gold=true;
//        gold_value = ((rand() % 25) + 1) * level;
//        //printf("y=%i,x=%i,c=%c, g=%d\n", temp_y, temp_x, core.game_data.dungeon_level[temp_y][temp_x].block_type,gold_value);
//        core.game_data.dungeon_level[temp_y][temp_x].gold_value=gold_value;
//    }
//
//    return;
//}