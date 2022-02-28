#include "game.h"
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#define MAP_WIDTH 15 
#define MAP_HEIGHT 11
#define PLAYER_POSITION pos_y * MAP_WIDTH + pos_x
using namespace std;
int dest_squares[10];                                                   // array to store cell indexes for 'x' cells
char map[165];
char map1[] = {
    "----Level-1----"
    "---######------"
    "---#xB ####----"
    "---###   ##----"
    "---#x@B  ##----"
    "---### Bx##----"
    "---#x##B ##----"
    "---# # x ###---"
    "---#B OBBx##---"
    "---#   x  ##---"
    "---#########---"
};// Size HxW = 10x8 Updated to 11x15
char map2[] ={
    "----Level-2----"
    "---########----"
    "---#x   Bx#----"
    "---#B     #----"
    "---#x@B   #----"
    "---#  B  x#----"
    "---#x# B  #----"
    "---# # x  #----"
    "---#B#OB  #----"
    "---#   x  #----"
    "---########----"    
};// Size HxW = 10x8 Updated to 11x15
char map3[] ={
    "----Level-3----"
    "---########----"
    "---#x B   #----"
    "---#      #----"
    "---#      #----"
    "---#      #----"
    "---#@     #----"
    "---#      #----"
    "---#      #----"
    "---#      #----"
    "---########----"
};// Size HxW = 10x8 Updated to 11x12
char map4[] ={
    "----Level-4----"
    "---########----"
    "---#      #----"
    "---#@ B   #----"
    "---#  ##B #----"
    "---#  #   #----"
    "---#  #   #----" 
    "---#  #   #----"
    "---#x #   #----"
    "---#  #x  #----"
    "---########----"
};// Size HxW = 10x8 Updated to 11x15
char map5[] ={
    "----Level-5----"
    "---##########--"
    "---##@####  #--"
    "---##B#     #--"
    "---## #  ## #--"
    "---## ## ## #--"
    "--### ## ## #--"
    "--##  ## ## #--"
    "--##     ##x#--"
    "--#####  ## #--"
    "-----########--"
};// Size HxW = 10x10 Updated to 11x12
int GetDestSquares()                                                    // init 'x' cells indexes
{
    int count = 0, cell;                                                // 'x' cell number, current cell index
    for(int row = 0; row < MAP_HEIGHT; row++)                           // loop ower map rows
    {
        for(int col = 0; col < MAP_WIDTH; col++)                        // loop ower map columns
        {
            cell = row * MAP_WIDTH + col;                               // init current cell index        
            if(map[cell] == 'x' || map[cell] == 'O')                    // if 'x' cell is emty or with box on it
                dest_squares[count++] = cell;                           // store it in array
        }
    }
    return count;                                                       // return number of 'x' cells
}
char map6[]={
    "----Level-6----"
    "---------------"
    "---#########---"
    "---#x #   ##---"
    "---#  B   ##---"
    "---#   # ###---"
    "---## # Bx##---"
    "---#   B  ##---"
    "---#  x# @##---"
    "---#########---"
    "---------------"
};// Size HxW = 8x8 Updatd to 11x15
char map7[]={
    "----Level-7----"
    "---------------"
    "---------------"
    "--##########---"
    "--##  x# x##---"
    "--## B   @##---"
    "--## BB## ##---"
    "--##     x##---"
    "--##########---"
    "---------------"
    "---------------"
};// Size Hxw = 6x8 Updated to 11=x15
char map8[]={
    "----Level-8----"
    "--###########--"
    "--###      ##--"
    "--###B     ##--"
    "--##       ##--"
    "--##x ###B ##--"
    "--##   B   ##--"
    "--##      x##--"
    "--##   @  ###--"
    "--##     x###--"
    "--###########--"
};// Size Hxw = 10x9 Updated to 11=x15
char map9[]={
    "----Level-9----"
    "---------------"
    "---########----"
    "---##  ####----"
    "---## B ###----"
    "---##   x##----"
    "---## B ###----"
    "---###   ##----"
    "---####x@##----"
    "---########----"
    "---------------"
};// Size Hxw = 6x8 Updated to 11=x15
char map10[]={
    "---Level-10----"
    "---------------"
    "-#############-"
    "-##   #      #-"
    "-##   #B#    #-"
    "-##          #-"
    "-####    B   #-"
    "-##     ######-"
    "-##  @   xx###-"
    "-#############-"
    "---------------"
};// Size Hxw = 8x12 Updated to 11=x15






void GetPosition(int *pos_x, int *pos_y)
{
    int cell;                                                           // current cell index
    for(int row = 0; row < MAP_HEIGHT; row++)                           // loop ower map rows
    {
        for(int col = 0; col < MAP_WIDTH; col++)                        // loop ower map columns
        {
            cell = row * MAP_WIDTH + col;                               // init current cell index
            if(map[cell] == '@')                                        // if current cell on the map contains player
            {
                *pos_x = col;                                           // store player's x coordinate
                *pos_y = row;                                           // store player's y coordinate
            }
        }
    }
}





char map11[]={
    "---Level-11----"
    "###############"
    "#   #   #     #"
    "#   #   #     #"
    "#             #"
    "# # # ## ######"
    "#   # ## ##   #"
    "#             #"
    "#  #B## #@#   #"
    "#  #    ###  x#"
    "###############"
};// Size Hxw = 10x15 Updated to 11=15
char map12[]={
    "---Level-12----"
    "---########----"
    "---#x    x#----"
    "---#      #----"
    "---#####B #----"
    "---#      #----"
    "---#      #----"
    "---# B#####----"
    "---#      #----"
    "---#     @#----"
    "---########----"
};// Size Hxw = 10x8 Updated to 11=15
char map13[]={
    "---Level-13----"
    "---------------"
    "-----###-------"
    "-----#x#-------"
    "-----# ####----"
    "---###B Bx#----"
    "---#x B@###----"
    "---####B#------"
    "------#x#------"
    "------###------"
    "---------------"
};// Size Hxw = 8x8 Updated to 11=15
char map14[]={
    "---Level-14----"
    "---------------"
    "---#####-------"
    "---#   #-------"
    "---# B@#-###---"
    "---# BB#-#x#---"
    "---### ###x#---"
    "----##    x#---"
    "----#   #  #---"
    "----#   ####---"
    "----#####------"
};// Size Hxw = 8x8 Updated to 11=15
char map15[]={
    "---Level-15----"
    "---------------"
    "-----####------"
    "----##  #------"
    "----# @B#------"
    "----##B ##-----"
    "----## B #-----"
    "----#xB  #-----"
    "----#xxOx#-----"
    "----######-----"
    "---------------"
};// Size Hxw = 8x6 Updated to 11=15
char map16[]={
    "---Level-16----"
    "---------------"
    "----####-------"
    "----# @###-----"
    "----# B  #-----"
    "---### # ##----"
    "---#x# #  #----"
    "---#xB  # #----"
    "---#x   B #----"
    "---########----"
    "---------------"
};// Size Hxw = 8x6 Updated to 11=15
char map17[]={
    "---Level-17----"
    "---------------"
    "-------####----"
    "-----######----"
    "-----#    #----"
    "---###BBB #----"
    "---#  Bxx #----"
    "---#@Bxxx##----"
    "---####  #-----"
    "------####-----"
    "---------------"
};// Size Hxw = 8x6 Updated to 11=15
char map18[]={
    "---Level-18----"
    "---------------"
    "-----#####-----"
    "---###  @#-----"
    "---#  Bx ##----"
    "---#  xBx #----"
    "---### OB #----"
    "-----#   ##----"
    "-----#####-----"
    "---------------"
    "---------------"
};// Size Hxw = 8x6 Updated to 11=15
char map19[]={
    "---Level-19----"
    "---------------"
    "-----####------"
    "-----#xx#------"
    "----## x##-----"
    "----#  Bx#-----"
    "---## B  ##----"
    "---#  #BB #----"
    "---#  @   #----"
    "---########----"
    "---------------"
};// Size Hxw = 8x6 Updated to 11=15
char map20[]={
    "---Level-20----"
    "---------------"
    "-----####------"
    "---########----"
    "---#  #   #----"
    "---# BxxB #----"
    "---#@BxO ##----"
    "---# BxxB #----"
    "---#  #   #----"
    "---########----"
    "---------------"
};// Size Hxw = 8x6 Updated to 11=15
void MoveCharacter(int pos_x, int pos_y, int offset)
{
    if(map[PLAYER_POSITION + offset] != '#')                            // if player doesn't hit the wall
    {
        if(((map[PLAYER_POSITION + offset] == 'B') ||                   // if player hits the box
            (map[PLAYER_POSITION + offset] == 'O')) &&                  // or the box on 'x' cell
            (map[PLAYER_POSITION + offset * 2] != '#' ||                // and box doesn't hit a wall
             map[PLAYER_POSITION + offset * 2] != 'B' ||                // or another box
             map[PLAYER_POSITION + offset * 2] != 'O'))                 // or box on 'x' cell
        {
            map[PLAYER_POSITION] = ' ';                                 // clear previous player's position
            pos_x += offset;                                            // update player's coordinate

            if(map[PLAYER_POSITION + offset] == ' ')                    // if the square next to the box is empty
            {    map[PLAYER_POSITION + offset] = 'B'; }                   // push the box
            else if(map[PLAYER_POSITION + offset] == 'x')               // if the square next to the box is 'x'  
            {    map[PLAYER_POSITION + offset] = 'O';  }                 // mark the box is on it's place
            else
            {
                map[PLAYER_POSITION - offset] = '@';                    // if box hits the wall or another box
                return;                                                 // don't push it any further
            }
            map[PLAYER_POSITION] = '@';                                 // draw the player in the new position
        }
        else                                                            // if the square next to the player is empty                                                        
        {
            map[PLAYER_POSITION] = ' ';                                 // clear previous player position
            pos_x += offset;                                            // update player's coordinate
            map[PLAYER_POSITION] = '@';                                 // draw the player in the new position
        }
    }   
}
char map21[]={
    "---Level-21----"
    "-----#####-----"
    "-----#  x#-----"
    "-----#B  #-----"
    "---###  B##----"
    "---#x B B #----"
    "-### #x## ##---"
    "-#         #---"
    "-##### ###@#---"
    "-----#x    #---"
    "-----#######---"
};// Size Hxw = 8x6 Updated to 11=15
char map22[]={
    "---Level-22----"
    "---------------"
    "-----####------"
    "---######------"
    "---#    #------"
    "---# BBB##-----"
    "---#  #xx###---"
    "---##  xxB #---"
    "----# @    #---"
    "----########---"
    "---------------"
};// Size Hxw = 8x6 Updated to 11=15
char map23[]={
    "---Level-23----"
    "---------------"
    "---########----"
    "---#xx    #----"
    "---##     #----"
    "---# B    #----"
    "---#  @  ##----"
    "---#   BBx#----"
    "---#     ##----"
    "---########----"
    "---------------"
};// Size Hxw = 8x6 Updated to 11=15
char map24[]={
    "---Level-24----"
    "---------------"
    "--##########---"
    "--#x       #---"
    "--# #      #---"
    "--#BB      #---"
    "--# #      #---"
    "--# #  #@  #---"
    "--#    ##x #---"
    "--##########---"
    "---------------"
};// Size Hxw = 8x6 Updated to 11=15
char map25[]={
    "---Level-25----"
    "---------------"
    "---########----"
    "---#  #  x#----"
    "---#  # B #----"
    "---#x   B##----"
    "---##     #----"
    "---#x @#B #----"
    "---#   #  #----"
    "---########----"
    "---------------"
};// Size Hxw = 8x8 Updated to 11=15





void clear_dest_square()
{
    for (int clear =0; clear<10; clear++)// this function will clear stored goal indexes defined in the previous level
    {
        dest_squares[clear]= dest_squares[clear]-dest_squares[clear];
    }
}
int POSITION_MATCH()
{
    int dest_count=0;
    for(int b = 0; b < 10; b++)                                     // for all destination squares
    {            
        if(map[dest_squares[b]] == 'O') dest_count++;               // increase 'x' cells counter if box is on 'x' cell
        
        if(map[dest_squares[b]] == ' ') map[dest_squares[b]] = 'x'; // if 'x' cell has been erased restore it                              
    }
    return dest_count;
}




char map26[]={
    "---Level-26----"
    "---------------"
    "---#########---"
    "---#  #x   #---"
    "---#  ##   #---"
    "---###  #B #---"
    "---#x#  Bx #---"
    "---#     B #---"
    "---#   @   #---"
    "---#########---"
    "---------------"
};// Size Hxw = 8x8 Updated to 11=15
char map27[]={
    "---Level-27----"
    "---------------"
    "----######-----"
    "----#    #-----"
    "---## B  ##----"
    "---## Bx###----"
    "---###xB ##----"
    "---##    ##----"
    "----# @ x#-----"
    "----######-----"
    "---------------"
};// Size Hxw = 8x6 Updated to 11=15
char map28[]={
    "---Level-28----"
    "---------------"
    "------##-------"
    "----######-----"
    "----# x  #-----"
    "---## #B ##----"
    "---## B@###----"
    "----#   x#-----"
    "----######-----"
    "------##-------"
    "---------------"
};// Size Hxw = 8x6 Updated to 11=15
char map29[]={
    "---Level-29----"
    "---------------"
    "-----#####-----"
    "---#########---"
    "---#   x#  #---"
    "---#    #  #---"
    "---#  B #  #---"
    "---#  # B  #---"
    "---#  #  x@#---"
    "---#########---"
    "---------------"
};// Size Hxw = 8x6 Updated to 11=15
char maplast[]={
    "---Lastlevel---"
    "---------------"
    "---#####-------"
    "---#   #####---"
    "---# # #   #---"
    "---# B   B #---"
    "---#xx#B#B##---"
    "---#x B   #----"
    "---#xx@ ###----"
    "---######------"
    "---------------"
};// Size Hxw = 8x9 Updated to 11=15
void Place_Path(int level)
{
    for(int index=0;index<165;index++)// Copying levels from to map
    {
        if(level==1) map[index]=map1[index];

        if(level==2) map[index]=map2[index];

        if(level==3) map[index]=map3[index];

        if(level==4) map[index]=map4[index];

        if(level==5) map[index]=map5[index];

        if(level==6) map[index]=map6[index];

        if(level==7) map[index]=map7[index];

        if(level==8) map[index]=map8[index];

        if(level==9) map[index]=map9[index];

        if(level==10) map[index]=map10[index];

        if(level==11) map[index]=map11[index];

        if(level==12) map[index]=map12[index];

        if(level==13) map[index]=map13[index];

        if(level==14) map[index]=map14[index];

        if(level==15) map[index]=map15[index];

        if(level==16) map[index]=map16[index];

        if(level==17) map[index]=map17[index];

        if(level==18) map[index]=map18[index];

        if(level==19) map[index]=map19[index];

        if(level==20) map[index]=map20[index];

        if(level==21) map[index]=map21[index];

        if(level==22) map[index]=map22[index];

        if(level==23) map[index]=map23[index];

        if(level==24) map[index]=map24[index];

        if(level==25) map[index]=map25[index];

        if(level==26) map[index]=map26[index];

        if(level==27) map[index]=map27[index];

        if(level==28) map[index]=map28[index];

        if(level==29) map[index]=map29[index];

        if(level==30) map[index]=maplast[index];
    }
}
int main()
{
    InitScreen();
    int level=1;
    int pos_x, pos_y;                                                   //  player's coordinates
    int dest_count;                                                     //  'x' cells counter
//-------------------------Level1--------------------------------------//
    Place_Path(level);
    int center_x = SCREEN_WIDTH / 2 - MAP_WIDTH / 2;
    int center_y = SCREEN_HEIGHT / 2 - MAP_HEIGHT / 2;
    PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
    clear_dest_square();
    int dest_num = GetDestSquares();
    for (int a=1; a<47; a++)
    {
        GetPosition(&pos_x, &pos_y);
        if((a==2)||(a==3)||(a==27)||(a==28)||(a==32)||(a==35)||(a==36)||(a==37))
        {
            MoveCharacter(pos_x, pos_y,  - MAP_WIDTH);//To Move UP Only
        }
        if((a==6)||(a==9)||((a>15)&&(a<19))||(a==20)||(a==24)||(a==29)||(a==40)||(a==42)||(a==44)||(a==45))
        {
            MoveCharacter(pos_x, pos_y,  MAP_WIDTH);//To Move Down Only
        }
        if((a==4)||(a==10)||(a==11)||(a==12)||(a==19)||(a==22)||(a==23)||(a==25)||(a==26)||(a==38)||(a==39)||(a==46))
        {
            MoveCharacter(pos_x, pos_y, -1);//To Move Left Only
        }
        if ((a==1)||(a==5)||(a==7)||(a==8)||((a>12)&&(a<16))||(a==21)||(a==30)||(a==31)||(a==33)||(a==34)||(a==41)||(a==43) )
        {
            MoveCharacter(pos_x, pos_y, 1);//To Move Right Only
        }
        Sleep(1000);//delay for 1 second
        dest_count = POSITION_MATCH();                                                 // reset 'x' cells counter
        PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
        if((dest_num == dest_count)&&((dest_num!=0)&&(dest_count!=0)))
        {
            Sleep(1000);
            RefreshScreen();
            break;           
        }       
    }
//---------------------------Level2---------------------------------//
    level=level+1;    
    Place_Path(level);
    pos_x = pos_x - pos_x;
    pos_y = pos_y - pos_y;
    center_x = SCREEN_WIDTH / 2 - MAP_WIDTH / 2;
    center_y = SCREEN_HEIGHT / 2 - MAP_HEIGHT / 2;    
    PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
    clear_dest_square();
    dest_num = GetDestSquares();
    for (int a=1; a<43; a++)
    {
        GetPosition(&pos_x, &pos_y);
        if((a==2)||(a==4)||(a==25)||(a==26)||(a==33)||(a==34)||(a==37)||(a==39)||(a==40))
        {
            MoveCharacter(pos_x, pos_y,  - MAP_WIDTH);//To Move UP Only
        }
        if((a==8)||(a==9)||(a==13)||((a>16)&&(a<21))||(a==27)||(a==28)||(a==36)||(a==42))
        {
            MoveCharacter(pos_x, pos_y,  MAP_WIDTH);//To Move Down Only
        }
        if((a==1)||(a==10)||(a==11)||(a==12)||(a==21)||((a>21)&&(a<25))||(a==35)||(a==38))
        {
            MoveCharacter(pos_x, pos_y, -1);//To Move Left Only
        }
        if((a==3)||(a==5)||(a==6)||(a==7)||((a>13)&&(a<17))||((a>28)&&(a<33))||(a==41))
        {
            MoveCharacter(pos_x, pos_y, 1);//To Move Right Only
        }
        Sleep(1000);//delay for 1 second
        dest_count = POSITION_MATCH();                                                 // reset 'x' cells counter
        PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
        if((dest_num == dest_count)&&((dest_num!=0)&&(dest_count!=0)))
        {
            Sleep(1000);//delay for 1 second
            RefreshScreen();
            break;           
        }       
    }
//---------------------------Level3---------------------------------//
    level=level+1;    
    Place_Path(level);
    pos_x = pos_x - pos_x;
    pos_y = pos_y - pos_y;
    center_x = SCREEN_WIDTH / 2 - MAP_WIDTH / 2;
    center_y = SCREEN_HEIGHT / 2 - MAP_HEIGHT / 2;    
    PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
    clear_dest_square();
    dest_num = GetDestSquares();
    for (int a=1; a<10; a++)
    {
        GetPosition(&pos_x, &pos_y);
        if((a>3)&&(a<8))
        {
            MoveCharacter(pos_x, pos_y,  - MAP_WIDTH);//To Move UP Only
        }
         //No Moves to Down
        if((a==8)||(a==9))
        {
            MoveCharacter(pos_x, pos_y, -1);//To Move Left Only
        }
        if((a>0)&&(a<4))
        {
            MoveCharacter(pos_x, pos_y, 1);//To Move Right Only
        }
        Sleep(1000);//delay for 1 second
        dest_count = POSITION_MATCH();                                                 // reset 'x' cells counter
        PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
        if((dest_num == dest_count)&&((dest_num!=0)&&(dest_count!=0)))
        {
            Sleep(1000);//delay for 1 second
            RefreshScreen();
            break;           
        }       
    }
 //---------------------------Level4---------------------------------//
    level=level+1;    
    Place_Path(level);
    pos_x = pos_x - pos_x;
    pos_y = pos_y - pos_y;
    center_x = SCREEN_WIDTH / 2 - MAP_WIDTH / 2;
    center_y = SCREEN_HEIGHT / 2 - MAP_HEIGHT / 2;    
    PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
    clear_dest_square();
    dest_num = GetDestSquares();
    for (int a=1; a<31; a++)
    {
        GetPosition(&pos_x, &pos_y);
        if((a==1)||((a>14)&&(a<21))||(a==24))
        {
            MoveCharacter(pos_x, pos_y,  - MAP_WIDTH);//To Move UP Only
        }
        if(((a>5)&&(a<12))||(a==13)||((a>25)&&(a<31)))
        {
            MoveCharacter(pos_x, pos_y,  MAP_WIDTH);//To Move Down Only
        } 
        if((a==14)||((a>20)&&(a<24))||(a==25))
        {
            MoveCharacter(pos_x, pos_y, -1);//To Move Left Only
        }
        if(((a>1)&&(a<6))||(a==12))
        {
            MoveCharacter(pos_x, pos_y, 1);//To Move Right Only
        }
        Sleep(1000);//delay for 1 second
        dest_count = POSITION_MATCH();                                                 // reset 'x' cells counter
        PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
        if((dest_num == dest_count)&&((dest_num!=0)&&(dest_count!=0)))
        {
             Sleep(1000);//delay for 1 second
            RefreshScreen();
            break;           
        }       
    }
  //---------------------------Level5---------------------------------//
    level=level+1;    
    Place_Path(level);
    pos_x = pos_x - pos_x;
    pos_y = pos_y - pos_y;
    center_x = SCREEN_WIDTH / 2 - MAP_WIDTH / 2;
    center_y = SCREEN_HEIGHT / 2 - MAP_HEIGHT / 2;    
    PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
    clear_dest_square();
    dest_num = GetDestSquares();
    for (int a=1; a<30; a++)
    {
        GetPosition(&pos_x, &pos_y);
        if(((a>12)&&(a<20))||(a==23))
        {
            MoveCharacter(pos_x, pos_y,  - MAP_WIDTH);//To Move UP Only
        }
        if(((a>0)&&(a<6))||(a==7)||(a==11)||((a>24)&&(a<30)))
        {
            MoveCharacter(pos_x, pos_y,  MAP_WIDTH);//To Move Down Only
        } 
        if((a==6)||(a==18))
        {
            MoveCharacter(pos_x, pos_y, -1);//To Move Left Only
        }
        if(((a>7)&&(a<11))||(a==12)||((a>19)&&(a<23))||(a==24))
        {
            MoveCharacter(pos_x, pos_y, 1);//To Move Right Only
        }
        Sleep(1000);//delay for 1 second
        dest_count = POSITION_MATCH();                                                 // reset 'x' cells counter
        PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
        if((dest_num == dest_count)&&((dest_num!=0)&&(dest_count!=0)))
        {
             Sleep(1000);//delay for 1 second
            sprintf(screen + (SCREEN_WIDTH * SCREEN_HEIGHT / 2) - MAP_WIDTH / 2, "YOU WIN!");
            RefreshScreen();
            break;           
        }       
    }
  //---------------------------Level6---------------------------------//
    level=level+1;    
    Place_Path(level);
    pos_x = pos_x - pos_x;
    pos_y = pos_y - pos_y;
    center_x = SCREEN_WIDTH / 2 - MAP_WIDTH / 2;
    center_y = SCREEN_HEIGHT / 2 - MAP_HEIGHT / 2;    
    PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
    clear_dest_square();
    dest_num = GetDestSquares();
    for (int a=1; a<23; a++)
    {
        GetPosition(&pos_x, &pos_y);
        if((a==1)||(a==6)||(a==8)||(a==9)||(a==15))
        {
            MoveCharacter(pos_x, pos_y,  - MAP_WIDTH);//To Move UP Only
        }
        if((a==13)||((a>16)&&(a<20))||(a==21))
        {
            MoveCharacter(pos_x, pos_y,  MAP_WIDTH);//To Move Down Only
        } 
        if(((a>1)&&(a<5))||((a>9)&&(a<13))||(a==14)||(a==20))
        {
            MoveCharacter(pos_x, pos_y, -1);//To Move Left Only
        }
        if((a==5)||(a==7)||(a==16)||(a==22))
        {
            MoveCharacter(pos_x, pos_y, 1);//To Move Right Only
        }
        Sleep(1000);//delay for 1 Second
        dest_count = POSITION_MATCH();                                                 // reset 'x' cells counter
        PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
        if((dest_num == dest_count)&&((dest_num!=0)&&(dest_count!=0)))
        {
             Sleep(1000);//delay for 1 second
            RefreshScreen();
            break;           
        }       
    }
  //---------------------------Level7---------------------------------//
    level=level+1;    
    Place_Path(level);
    pos_x = pos_x - pos_x;
    pos_y = pos_y - pos_y;
    center_x = SCREEN_WIDTH / 2 - MAP_WIDTH / 2;
    center_y = SCREEN_HEIGHT / 2 - MAP_HEIGHT / 2;    
    PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
    clear_dest_square();
    dest_num = GetDestSquares();
    for (int a=1; a<46; a++)
    {
        GetPosition(&pos_x, &pos_y);
        if((a==4)||(a==23)||(a==24)||(a==33)||(a==34)||(a==36))
        {
            MoveCharacter(pos_x, pos_y,  - MAP_WIDTH);//To Move UP Only
        }
        if((a==7)||(a==16)||(a==17)||(a==30)||(a==31)||(a==38)||(a==40)||(a==42))
        {
            MoveCharacter(pos_x, pos_y,  MAP_WIDTH);//To Move Down Only
        } 
        if(((a>0)&&(a<4))||(a==5)||(a==6)||((a>11)&&(a<16))||((a>24)&&(a<30))||(a==35)||(a==41))
        {
            MoveCharacter(pos_x, pos_y, -1);//To Move Left Only
        }
        if(((a>7)&&(a<12))||((a>17)&&(a<23))||(a==32)||(a==37)||(a==39)||((a>42)&&(a<46)))
        {
            MoveCharacter(pos_x, pos_y, 1);//To Move Right Only
        }
        Sleep(1000);//delay for 1 second
        dest_count = POSITION_MATCH();                                                 // reset 'x' cells counter
        PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
        if((dest_num == dest_count)&&((dest_num!=0)&&(dest_count!=0)))
        {
             Sleep(1000);//delay for 1 second
            RefreshScreen();
            break;           
        }       
    }
  //---------------------------Level8---------------------------------//
    level=level+1;    
    Place_Path(level);
    pos_x = pos_x - pos_x;
    pos_y = pos_y - pos_y;
    center_x = SCREEN_WIDTH / 2 - MAP_WIDTH / 2;
    center_y = SCREEN_HEIGHT / 2 - MAP_HEIGHT / 2;    
    PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
    clear_dest_square();
    dest_num = GetDestSquares();
    for (int a=1; a<38; a++)
    {
        GetPosition(&pos_x, &pos_y);
        if((a==1)||(a==3)||(a==9)||(a==11)||(a==12)||(a==14)||(a==15)||(a==29)||(a==31)||(a==32))
        {
            MoveCharacter(pos_x, pos_y,  - MAP_WIDTH);//To Move UP Only
        }
        if((a==7)||((a>16)&&(a<21))||(a==22)||((a>33)&&(a<38)))
        {
            MoveCharacter(pos_x, pos_y,  MAP_WIDTH);//To Move Down Only
        } 
        if(((a>3)&&(a<7))||(a==8)||(a==16)||(a==21)||(a==33))
        {
            MoveCharacter(pos_x, pos_y, -1);//To Move Left Only
        }
        if((a==2)||(a==10)||(a==13)||((a>22)&&(a<29))||(a==30))
        {
            MoveCharacter(pos_x, pos_y, 1);//To Move Right Only
        }
        Sleep(1000);//delay for 1 second
        dest_count = POSITION_MATCH();                                                 // reset 'x' cells counter
        PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
        if((dest_num == dest_count)&&((dest_num!=0)&&(dest_count!=0)))
        {
             Sleep(1000);//delay for 1 second
           RefreshScreen();
            break;           
        }       
    }
//---------------------------Level9---------------------------------//
    level=level+1;    
    Place_Path(level);
    pos_x = pos_x - pos_x;
    pos_y = pos_y - pos_y;
    center_x = SCREEN_WIDTH / 2 - MAP_WIDTH / 2;
    center_y = SCREEN_HEIGHT / 2 - MAP_HEIGHT / 2;    
    PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
    clear_dest_square();
    dest_num = GetDestSquares();
    for (int a=1; a<23; a++)
    {
        GetPosition(&pos_x, &pos_y);
        if((a==1)||(a==3)||(a==4)||(a==7)||(a==8)||(a==19))
        {
            MoveCharacter(pos_x, pos_y,  - MAP_WIDTH);//To Move UP Only
        }
        if((a==10)||(a==12)||(a==17)||(a==21)||(a==22))
        {
            MoveCharacter(pos_x, pos_y,  MAP_WIDTH);//To Move Down Only
        } 
        if((a==2)||(a==5)||(a==6)||(a==11)||(a==15)||(a==16))
        {
            MoveCharacter(pos_x, pos_y, -1);//To Move Left Only
        }
        if((a==9)||(a==13)||(a==14)||(a==18)||(a==20))
        {
            MoveCharacter(pos_x, pos_y, 1);//To Move Right Only
        }
        Sleep(1000);//delay for 1 second
        dest_count = POSITION_MATCH();                                                 // reset 'x' cells counter
        PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
        if((dest_num == dest_count)&&((dest_num!=0)&&(dest_count!=0)))
        {
             Sleep(1000);//delay for 1 second
            RefreshScreen();
            break;           
        }       
    }
//---------------------------Level10---------------------------------//
    level=level+1;    
    Place_Path(level);
    pos_x = pos_x - pos_x;
    pos_y = pos_y - pos_y;
    center_x = SCREEN_WIDTH / 2 - MAP_WIDTH / 2;
    center_y = SCREEN_HEIGHT / 2 - MAP_HEIGHT / 2;    
    PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
    clear_dest_square();
    dest_num = GetDestSquares();
    for (int a=1; a<40; a++)
    {
        GetPosition(&pos_x, &pos_y);
        if(((a>0)&&(a<4))||(a==8)||(a==9)||((a>22)&&(a<26))||(a==32))
        {
            MoveCharacter(pos_x, pos_y,  - MAP_WIDTH);//To Move UP Only
        }
        if(((a>11)&&(a<16))||(a==17)||(a==29)||(a==34)||(a==35)||(a==37))
        {
            MoveCharacter(pos_x, pos_y,  MAP_WIDTH);//To Move Down Only
        } 
        if((a==10)||(a==11)||(a==16)||(a==21)||(a==22)||(a==30)||(a==31)||(a==33)||(a==36))
        {
            MoveCharacter(pos_x, pos_y, -1);//To Move Left Only
        }
        if(((a>3)&&(a<8))||((a>17)&&(a<21))||((a>25)&&(a<29))||(a==38)||(a==39))
        {
            MoveCharacter(pos_x, pos_y, 1);//To Move Right Only
        }
        Sleep(1000);//delay for 1 second
        dest_count = POSITION_MATCH();                                                 // reset 'x' cells counter
        PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
        if((dest_num == dest_count)&&((dest_num!=0)&&(dest_count!=0)))
        {
             Sleep(1000);//delay for 1 second
            RefreshScreen();
            break;           
        }       
    }
//---------------------------Level11---------------------------------//
    level=level+1;    
    Place_Path(level);
    pos_x = pos_x - pos_x;
    pos_y = pos_y - pos_y;
    center_x = SCREEN_WIDTH / 2 - MAP_WIDTH / 2;
    center_y = SCREEN_HEIGHT / 2 - MAP_HEIGHT / 2;    
    PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
    clear_dest_square();
    dest_num = GetDestSquares();
    for (int a=1; a<39; a++)
    {
        GetPosition(&pos_x, &pos_y);
        if((a==1)||(a==9)||(a==14)||(a==15)||((a>17)&&(a<21))||(a==35))
        {
            MoveCharacter(pos_x, pos_y,  - MAP_WIDTH);//To Move UP Only
        }
        if((a==4)||(a==5)||(a==10)||((a>22)&&(a<26))||(a==37)||(a==38))
        {
            MoveCharacter(pos_x, pos_y,  MAP_WIDTH);//To Move Down Only
        } 
        if((a==2)||(a==3)||((a>5)&&(a<9))||(a==16)||(a==17)||(a==21)||(a==22))
        {
            MoveCharacter(pos_x, pos_y, -1);//To Move Left Only
        }
        if(((a>10)&&(a<14))||((a>25)&&(a<35))||(a==36))
        {
            MoveCharacter(pos_x, pos_y, 1);//To Move Right Only
        }
        Sleep(1000);//delay for 1 second
        dest_count = POSITION_MATCH();                                                 // reset 'x' cells counter
        PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
        if((dest_num == dest_count)&&((dest_num!=0)&&(dest_count!=0)))
        {
             Sleep(1000);//delay for 1 second
            RefreshScreen();
            break;           
        }       
    }
//---------------------------Level12---------------------------------//
    level=level+1;    
    Place_Path(level);
    pos_x = pos_x - pos_x;
    pos_y = pos_y - pos_y;
    center_x = SCREEN_WIDTH / 2 - MAP_WIDTH / 2;
    center_y = SCREEN_HEIGHT / 2 - MAP_HEIGHT / 2;    
    PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
    clear_dest_square();
    dest_num = GetDestSquares();
    for (int a=1; a<35; a++)
    {
        GetPosition(&pos_x, &pos_y);
        if(((a>4)&&(a<8))||(a==9)||(a==16)||(a==18)||(a==19)||(a==21)||(a==33)||(a==34))
        {
            MoveCharacter(pos_x, pos_y,  - MAP_WIDTH);//To Move UP Only
        }
        if((a==14)||(a==26)||(a==30)||(a==31))
        {
            MoveCharacter(pos_x, pos_y,  MAP_WIDTH);//To Move Down Only
        } 
        if(((a>0)&&(a<5))||(a==8)||(a==17)||((a>21)&&(a<26)))
        {
            MoveCharacter(pos_x, pos_y, -1);//To Move Left Only
        }
        if(((a>9)&&(a<14))||(a==15)||(a==20)||((a>26)&&(a<30))||(a==32))
        {
            MoveCharacter(pos_x, pos_y, 1);//To Move Right Only
        }
        Sleep(1000);//delay for 1 second
        dest_count = POSITION_MATCH();                                                 // reset 'x' cells counter
        PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
        if((dest_num == dest_count)&&((dest_num!=0)&&(dest_count!=0)))
        {
             Sleep(1000);//delay for 1 second
            RefreshScreen();
            break;           
        }       
    }
//---------------------------Level13---------------------------------//
    level=level+1;    
    Place_Path(level);
    pos_x = pos_x - pos_x;
    pos_y = pos_y - pos_y;
    center_x = SCREEN_WIDTH / 2 - MAP_WIDTH / 2;
    center_y = SCREEN_HEIGHT / 2 - MAP_HEIGHT / 2;    
    PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
    clear_dest_square();
    dest_num = GetDestSquares();
    for (int a=1; a<14; a++)
    {
        GetPosition(&pos_x, &pos_y);
        if((a==2)||(a==7)||(a==12)||(a==13))
        {
            MoveCharacter(pos_x, pos_y,  - MAP_WIDTH);//To Move UP Only
        }
        if((a==1)||(a==10))
        {
            MoveCharacter(pos_x, pos_y,  MAP_WIDTH);//To Move Down Only
        } 
        if((a==3)||(a==4)||(a==9)||(a==11))
        {
            MoveCharacter(pos_x, pos_y, -1);//To Move Left Only
        }
        if((a==5)||(a==6)||(a==8))
        {
            MoveCharacter(pos_x, pos_y, 1);//To Move Right Only
        }
        Sleep(1000);//delay for 1 second
        dest_count = POSITION_MATCH();                                                 // reset 'x' cells counter
        PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
        if((dest_num == dest_count)&&((dest_num!=0)&&(dest_count!=0)))
        {
             Sleep(1000);//delay for 1 second
            RefreshScreen();
            break;           
        }       
    }
//---------------------------Level14---------------------------------//
    level=level+1;    
    Place_Path(level);
    pos_x = pos_x - pos_x;
    pos_y = pos_y - pos_y;
    center_x = SCREEN_WIDTH / 2 - MAP_WIDTH / 2;
    center_y = SCREEN_HEIGHT / 2 - MAP_HEIGHT / 2;    
    PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
    clear_dest_square();
    dest_num = GetDestSquares();
    for (int a=1; a<92; a++)
    {
        GetPosition(&pos_x, &pos_y);
        if((a==9)||(a==13)||(a==15)||(a==21)||(a==22)||((a>27)&&(a<32))||(a==36)||(a==47)||(a==51)||
           (a==53)||(a==60)||((a>64)&&(a<68))||(a==72)||(a==82)||(a==86)||(a==88))
        {
            MoveCharacter(pos_x, pos_y,  - MAP_WIDTH);//To Move UP Only
        }
        if(((a>0)&&(a<4))||(a==5)||(a==6)||(a==11)||(a==19)||(a==23)||(a==34)||((a>37)&&(a<42))||
            (a==43)||(a==44)||(a==49)||(a==58)||(a==70)||((a>73)&&(a<77))||(a==78)||(a==79)||(a==84))
        {
            MoveCharacter(pos_x, pos_y,  MAP_WIDTH);//To Move Down Only
        } 
        if((a==7)||(a==8)||(a==14)||((a>23)&&(a<28))||(a==32)||(a==33)||(a==45)||(a==46)||(a==52)||
           ((a>60)&&(a<65))||(a==68)||(a==69)||(a==80)||(a==81)||(a==87))
        {
            MoveCharacter(pos_x, pos_y, -1);//To Move Left Only
        }
        if((a==4)||(a==10)||(a==12)||((a>15)&&(a<19))||(a==20)||(a==35)||(a==37)||(a==42)||(a==48)||
           (a==50)||((a>53)&&(a<58))||(a==59)||(a==71)||(a==73)||(a==77)||(a==83)||(a==85)||((a>88)&&
           (a<92)))
        {
            MoveCharacter(pos_x, pos_y, 1);//To Move Right Only
        }
        Sleep(1000);//delay for 1 second
        dest_count = POSITION_MATCH();                                                 // reset 'x' cells counter
        PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
        if((dest_num == dest_count)&&((dest_num!=0)&&(dest_count!=0)))
        {
             Sleep(1000);//delay for 1 second
            RefreshScreen();
            break;           
        }       
    }
//---------------------------Level15---------------------------------//
    level=level+1;    
    Place_Path(level);
    pos_x = pos_x - pos_x;
    pos_y = pos_y - pos_y;
    center_x = SCREEN_WIDTH / 2 - MAP_WIDTH / 2;
    center_y = SCREEN_HEIGHT / 2 - MAP_HEIGHT / 2;    
    PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
    clear_dest_square();
    dest_num = GetDestSquares();
    for (int a=1; a<36; a++)
    {
        GetPosition(&pos_x, &pos_y);
        if((a==11)||(a==12)||(a==17)||(a==18)||((a>21)&&(a<26))||(a==33))
        {
            MoveCharacter(pos_x, pos_y,  - MAP_WIDTH);//To Move UP Only
        }
        if((a==1)||(a==3)||(a==5)||(a==6)||(a==14)||(a==20)||(a==21)||((a>26)&&(a<30))||(a==31)||(a==35))
        {
            MoveCharacter(pos_x, pos_y,  MAP_WIDTH);//To Move Down Only
        } 
        if((a==7)||(a==8)||(a==13)||(a==15)||(a==19)||(a==30))
        {
            MoveCharacter(pos_x, pos_y, -1);//To Move Left Only
        }
        if((a==2)||(a==4)||(a==9)||(a==10)||(a==16)||(a==26)||(a==32)||(a==34))
        {
            MoveCharacter(pos_x, pos_y, 1);//To Move Right Only
        }
        Sleep(1000);//delay for 1 second
        dest_count = POSITION_MATCH();                                                 // reset 'x' cells counter
        PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
        if((dest_num == dest_count)&&((dest_num!=0)&&(dest_count!=0)))
        {
             Sleep(1000);//delay for 1 second
            RefreshScreen();
            break;           
        }       
    }
//---------------------------Level16---------------------------------//
    level=level+1;    
    Place_Path(level);
    pos_x = pos_x - pos_x;
    pos_y = pos_y - pos_y;
    center_x = SCREEN_WIDTH / 2 - MAP_WIDTH / 2;
    center_y = SCREEN_HEIGHT / 2 - MAP_HEIGHT / 2;    
    PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
    clear_dest_square();    
    dest_num = GetDestSquares();
    for (int a=1; a<50; a++)
    {
        GetPosition(&pos_x, &pos_y);
        if((a==11)||(a==16)||(a==23)||(a==24)||(a==26)||(a==27)||(a==32)||(a==33)||(a==47))
        {
            MoveCharacter(pos_x, pos_y,  - MAP_WIDTH);//To Move UP Only
        }
        if((a==1)||(a==4)||(a==5)||(a==7)||(a==8)||(a==14)||(a==20)||(a==30)||(a==31)||(a==36)||
          (a==37)||(a==39)||(a==40))
        {
            MoveCharacter(pos_x, pos_y,  MAP_WIDTH);//To Move Down Only
        } 
        if((a==9)||(a==10)||(a==12)||(a==13)||(a==15)||(a==25)||(a==28)||(a==29)||((a>40)&&(a<45))||
          (a==48)||(a==49))
        {
            MoveCharacter(pos_x, pos_y, -1);//To Move Left Only
        }
        if((a==2)||(a==3)||(a==6)||((a>16)&&(a<20))||(a==21)||(a==22)||(a==34)||(a==35)||(a==38)||
          (a==45)||(a==46))
        {
            MoveCharacter(pos_x, pos_y, 1);//To Move Right Only
        }
        Sleep(1000);//delay for 1 second
        dest_count = POSITION_MATCH();                                                 // reset 'x' cells counter
        PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
        if((dest_num == dest_count)&&((dest_num!=0)&&(dest_count!=0)))
        {
             Sleep(1000);//delay for 1 second
            RefreshScreen();
            break;           
        }       
    }
//---------------------------Level17---------------------------------//
    level=level+1;    
    Place_Path(level);
    pos_x = pos_x - pos_x;
    pos_y = pos_y - pos_y;
    center_x = SCREEN_WIDTH / 2 - MAP_WIDTH / 2;
    center_y = SCREEN_HEIGHT / 2 - MAP_HEIGHT / 2;    
    PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
    clear_dest_square();    
    dest_num = GetDestSquares();
    for (int a=1; a<33; a++)
    {
        GetPosition(&pos_x, &pos_y);
        if((a==4)||(a==7)||(a==8)||(a==17)||(a==21)||(a==22)||(a==27)||(a==30))
        {
            MoveCharacter(pos_x, pos_y,  - MAP_WIDTH);//To Move UP Only
        }
        if((a==11)||(a==12)||(a==14)||(a==25)||(a==29)||(a==32))
        {
            MoveCharacter(pos_x, pos_y,  MAP_WIDTH);//To Move Down Only
        } 
        if((a==9)||(a==10)||(a==13)||(a==15)||(a==16)||(a==26)||(a==28)||(a==31))
        {
            MoveCharacter(pos_x, pos_y, -1);//To Move Left Only
        }
        if(((a>0)&&(a<4))||(a==5)||(a==6)||((a>17)&&(a<21))||(a==23)||(a==24))
        {
            MoveCharacter(pos_x, pos_y, 1);//To Move Right Only
        }
        Sleep(1000);//delay for 1 second
        dest_count = POSITION_MATCH();                                                 // reset 'x' cells counter
        PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
        if((dest_num == dest_count)&&((dest_num!=0)&&(dest_count!=0)))
        {
             Sleep(1000);//delay for 1 second
            RefreshScreen();
            break;           
        }       
    }
//---------------------------Level18---------------------------------//
    level=level+1;    
    Place_Path(level);
    pos_x = pos_x - pos_x;
    pos_y = pos_y - pos_y;
    center_x = SCREEN_WIDTH / 2 - MAP_WIDTH / 2;
    center_y = SCREEN_HEIGHT / 2 - MAP_HEIGHT / 2;    
    PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
    clear_dest_square();    
    dest_num = GetDestSquares();
    for (int a=1; a<32; a++)
    {
        GetPosition(&pos_x, &pos_y);
        if((a==7)||(a==10)||(a==21)||((a>24)&&(a<28)))
        {
            MoveCharacter(pos_x, pos_y,  - MAP_WIDTH);//To Move UP Only
        }
        if((a==2)||(a==4)||(a==13)||(a==14)||(a==17)||(a==18)||(a==22)||(a==30))
        {
            MoveCharacter(pos_x, pos_y,  MAP_WIDTH);//To Move Down Only
        } 
        if((a==1)||(a==3)||(a==5)||(a==6)||(a==15)||(a==16)||(a==23)||(a==24)||(a==28)||(a==29))
        {
            MoveCharacter(pos_x, pos_y, -1);//To Move Left Only
        }
        if((a==8)||(a==9)||(a==11)||(a==12)||(a==19)||(a==20)||(a==31))
        {
            MoveCharacter(pos_x, pos_y, 1);//To Move Right Only
        }
        Sleep(1000);//delay for 1 second
        dest_count = POSITION_MATCH();                                                 // reset 'x' cells counter
        PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
        if((dest_num == dest_count)&&((dest_num!=0)&&(dest_count!=0)))
        {
             Sleep(1000);//delay for 1 second
            RefreshScreen();
            break;           
        }       
    }
//---------------------------Level19---------------------------------//
    level=level+1;    
    Place_Path(level);
    pos_x = pos_x - pos_x;
    pos_y = pos_y - pos_y;
    center_x = SCREEN_WIDTH / 2 - MAP_WIDTH / 2;
    center_y = SCREEN_HEIGHT / 2 - MAP_HEIGHT / 2;    
    PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
    clear_dest_square();    
    dest_num = GetDestSquares();
    for (int a=1; a<71; a++)
    {
        GetPosition(&pos_x, &pos_y);
        if((a==2)||(a==3)||(a==6)||(a==7)||(a==16)||(a==20)||((a>25)&&(a<29))||(a==34)||(a==42)||
           (a==43)||(a==45)||(a==52)||(a==53)||(a==55)||(a==56)||(a==65)||(a==66)||(a==69||(a==70)))
        {
            MoveCharacter(pos_x, pos_y,  - MAP_WIDTH);//To Move UP Only
        }
        if((a==8)||((a>10)&&(a<14))||(a==17)||(a==22)||(a==32)||((a>36)&&(a<40))||((a>46)&&(a<50))||
           (a==57)||(a==58)||(a==60)||(a==61)||(a==67))
        {
            MoveCharacter(pos_x, pos_y,  MAP_WIDTH);//To Move Down Only
        } 
        if((a==1)||((a==9)||(a==10))||(a==21)||((a>22)&&(a<26))||(a==33)||(a==35)||(a==36)||(a==46)||
           (a==50)||(a==51)||(a==59)||(a==68))
        {
            MoveCharacter(pos_x, pos_y, -1);//To Move Left Only
        }
        if((a==4)||(a==5)||(a==14)||(a==15)||(a==18)||(a==19)||((a>28)&&(a<32))||(a==40)||
           (a==41)||(a==44)||(a==54)||((a>61)&&(a<65)))
        {
            MoveCharacter(pos_x, pos_y, 1);//To Move Right Only
        }
        Sleep(1000);//delay for 1 second
        dest_count = POSITION_MATCH();                                                 // reset 'x' cells counter
        PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
        if((dest_num == dest_count)&&((dest_num!=0)&&(dest_count!=0)))
        {
             Sleep(1000);//delay for 1 second
            RefreshScreen();
            break;           
        }       
    }
//---------------------------Level20---------------------------------//
    level=level+1;    
    Place_Path(level);
    pos_x = pos_x - pos_x;
    pos_y = pos_y - pos_y;
    center_x = SCREEN_WIDTH / 2 - MAP_WIDTH / 2;
    center_y = SCREEN_HEIGHT / 2 - MAP_HEIGHT / 2;    
    PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
    clear_dest_square();    
    dest_num = GetDestSquares();
    for (int a=1; a<57; a++)
    {
        GetPosition(&pos_x, &pos_y);
        if((a==1)||(a==7)||(a==16)||((a>18)&&(a<22))||(a==32)||(a==34)||(a==42)||(a==44)||(a==49)||
           (a==50))
        {
            MoveCharacter(pos_x, pos_y,  - MAP_WIDTH);//To Move UP Only
        }
        if((a==4)||(a==5)||(a==10)||(a==13)||(a==24)||(a==26)||(a==28)||(a==29)||(a==39)||(a==40)||
           (a==52)||(a==54))
        {
            MoveCharacter(pos_x, pos_y,  MAP_WIDTH);//To Move Down Only
        } 
        if((a==3)||(a==11)||(a==17)||(a==18)||(a==25)||(a==27)||(a==33)||((a>34)&&(a<39))||(a==43)||
           (a==47)||(a==48)||(a==53))
        {
            MoveCharacter(pos_x, pos_y, -1);//To Move Left Only
        }
        if((a==2)||(a==6)||(a==8)||(a==9)||(a==12)||(a==14)||(a==15)||(a==22)||(a==23)||(a==30)||
           (a==31)||(a==41)||(a==45)||(a==46)||(a==51)||(a==55)||(a==56))
        {
            MoveCharacter(pos_x, pos_y, 1);//To Move Right Only
        }
        Sleep(1000);//delay for 1 second
        dest_count = POSITION_MATCH();                                                 // reset 'x' cells counter
        PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
        if((dest_num == dest_count)&&((dest_num!=0)&&(dest_count!=0)))
        {
             Sleep(1000);//delay for 1 second
            RefreshScreen();
            break;           
        }       
    }
//---------------------------Level21---------------------------------//
    level=level+1;    
    Place_Path(level);
    pos_x = pos_x - pos_x;
    pos_y = pos_y - pos_y;
    center_x = SCREEN_WIDTH / 2 - MAP_WIDTH / 2;
    center_y = SCREEN_HEIGHT / 2 - MAP_HEIGHT / 2;    
    PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
    clear_dest_square();    
    dest_num = GetDestSquares();
    for (int a=1; a<34; a++)
    {
        GetPosition(&pos_x, &pos_y);
        if((a==1)||(a==3)||(a==4)||(a==6)||(a==7)||(a==15)||(a==19)||(a==20)||((a>26)&&(a<30)))
        {
            MoveCharacter(pos_x, pos_y,  - MAP_WIDTH);//To Move UP Only
        }
        if((a==8)||((a>10)&&(a<15))||((a>30)&&(a<34)))
        {
            MoveCharacter(pos_x, pos_y,  MAP_WIDTH);//To Move Down Only
        } 
        if((a==2)||(a==5)||(a==9)||(a==10)||((a>20)&&(a<25))||(a==30))
        {
            MoveCharacter(pos_x, pos_y, -1);//To Move Left Only
        }
        if(((a>15)&&(a<19))||(a==25)||(a==26))
        {
            MoveCharacter(pos_x, pos_y, 1);//To Move Right Only
        }
        Sleep(1000);//delay for 1 second
        dest_count = POSITION_MATCH();                                                 // reset 'x' cells counter
        PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
        if((dest_num == dest_count)&&((dest_num!=0)&&(dest_count!=0)))
        {
             Sleep(1000);//delay for 1 second
            RefreshScreen();
            break;           
        }       
    }
//---------------------------Level22---------------------------------//
    level=level+1;    
    Place_Path(level);
    pos_x = pos_x - pos_x;
    pos_y = pos_y - pos_y;
    center_x = SCREEN_WIDTH / 2 - MAP_WIDTH / 2;
    center_y = SCREEN_HEIGHT / 2 - MAP_HEIGHT / 2;    
    PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
    clear_dest_square();    
    dest_num = GetDestSquares();
    for (int a=1; a<79; a++)
    {
        GetPosition(&pos_x, &pos_y);
        if((a==2)||(a==3)||(a==5)||(a==6)||((a>14)&&(a<18))||(a==22)||(a==32)||(a==33)||(a==35)||
           (a==42)||(a==46)||(a==51)||(a==55)||((a>61)&&(a<66))||(a==70)||(a==71)||(a==76))
        {
            MoveCharacter(pos_x, pos_y,  - MAP_WIDTH);//To Move UP Only
        }
        if((a==10)||(a==11)||(a==13)||(a==20)||(a==24)||(a==25)||(a==27)||(a==28)||((a>36)&&(a<40))||
           (a==43)||(a==49)||(a==52)||(a==57)||(a==68)||(a==69)||(a==74)||(a==78))
        {
            MoveCharacter(pos_x, pos_y,  MAP_WIDTH);//To Move Down Only
        } 
        if((a==1)||(a==4)||(a==14)||(a==18)||(a==19)||((a>28)&&(a<32))||(a==34)||(a==44)||(a==45)||
           (a==56)||((a>57)&&(a<62))||(a==72)||(a==73))
        {
            MoveCharacter(pos_x, pos_y, -1);//To Move Left Only
        }
        if(((a>6)&&(a<10))||(a==12)||(a==21)||(a==23)||(a==26)||(a==36)||(a==40)||(a==41)||(a==47)||
            (a==48)||(a==50)||(a==53)||(a==54)||(a==66)||(a==67)||(a==75)||(a==77))
        {
            MoveCharacter(pos_x, pos_y, 1);//To Move Right Only
        }
        Sleep(1000);//delay for 1 second
        dest_count = POSITION_MATCH();                                                 // reset 'x' cells counter
        PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
        if((dest_num == dest_count)&&((dest_num!=0)&&(dest_count!=0)))
        {
             Sleep(1000);//delay for 1 second
            RefreshScreen();
            break;           
        }       
    }
//---------------------------Level23---------------------------------//
    level=level+1;    
    Place_Path(level);
    pos_x = pos_x - pos_x;
    pos_y = pos_y - pos_y;
    center_x = SCREEN_WIDTH / 2 - MAP_WIDTH / 2;
    center_y = SCREEN_HEIGHT / 2 - MAP_HEIGHT / 2;    
    PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
    clear_dest_square();    
    dest_num = GetDestSquares();
    for (int a=1; a<24; a++)
    {
        GetPosition(&pos_x, &pos_y);
        if((a==2)||(a==3)||(a==5)||(a==14)||((a>16)&&(a<20))||(a==21))
        {
            MoveCharacter(pos_x, pos_y,  - MAP_WIDTH);//To Move UP Only
        }
        if(((a>6)&&(a<12)))
        {
            MoveCharacter(pos_x, pos_y,  MAP_WIDTH);//To Move Down Only
        } 
        if((a==1)||(a==6)||(a==16)||(a==22)||(a==23))
        {
            MoveCharacter(pos_x, pos_y, -1);//To Move Left Only
        }
        if((a==4)||(a==12)||(a==13)||(a==15)||(a==20))
        {
            MoveCharacter(pos_x, pos_y, 1);//To Move Right Only
        }
        Sleep(1000);//delay for 1 second
        dest_count = POSITION_MATCH();                                                 // reset 'x' cells counter
        PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
        if((dest_num == dest_count)&&((dest_num!=0)&&(dest_count!=0)))
        {
             Sleep(1000);//delay for 1 second
            RefreshScreen();
            break;           
        }       
    }
//---------------------------Level24---------------------------------//
    level=level+1;    
    Place_Path(level);
    pos_x = pos_x - pos_x;
    pos_y = pos_y - pos_y;
    center_x = SCREEN_WIDTH / 2 - MAP_WIDTH / 2;
    center_y = SCREEN_HEIGHT / 2 - MAP_HEIGHT / 2;    
    PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
    clear_dest_square();    
    dest_num = GetDestSquares();
    for (int a=1; a<24; a++)
    {
        GetPosition(&pos_x, &pos_y);
        if((a==1)||((a>8)&&(a<13))||(a==19))
        {
            MoveCharacter(pos_x, pos_y,  - MAP_WIDTH);//To Move UP Only
        }
        if((a==4)||(a==5)||(a==13)||((a>20)&&(a<24)))
        {
            MoveCharacter(pos_x, pos_y,  MAP_WIDTH);//To Move Down Only
        } 
        if((a==2)||(a==3)||((a>5)&&(a<9)))
        {
            MoveCharacter(pos_x, pos_y, -1);//To Move Left Only
        }
        if(((a>13)&&(a<19))||(a==20))
        {
            MoveCharacter(pos_x, pos_y, 1);//To Move Right Only
        }
        Sleep(1000);//delay for 1 second
        dest_count = POSITION_MATCH();                                                 // reset 'x' cells counter
        PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
        if((dest_num == dest_count)&&((dest_num!=0)&&(dest_count!=0)))
        {
             Sleep(1000);//delay for 1 second
            RefreshScreen();
            break;           
        }       
    }
//---------------------------Level25---------------------------------//
    level=level+1;    
    Place_Path(level);
    pos_x = pos_x - pos_x;
    pos_y = pos_y - pos_y;
    center_x = SCREEN_WIDTH / 2 - MAP_WIDTH / 2;
    center_y = SCREEN_HEIGHT / 2 - MAP_HEIGHT / 2;    
    PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
    clear_dest_square();    
    dest_num = GetDestSquares();
    for (int a=1; a<57; a++)
    {
        GetPosition(&pos_x, &pos_y);
        if((a==1)||(a==8)||(a==10)||(a==14)||(a==20)||(a==21)||(a==24)||(a==25)||(a==32)||(a==33)||(a==34)||((a>49)&&(a<54))||(a==55))
        {
            MoveCharacter(pos_x, pos_y,  - MAP_WIDTH);//To Move UP Only
        }
        if((a==5)||(a==6)||(a==16)||(a==18)||(a==28)||(a==30)||(a==31)||(a==36)||(a==38)||(a==45)||(a==47)||(a==48))
        {
            MoveCharacter(pos_x, pos_y,  MAP_WIDTH);//To Move Down Only
        } 
        if((a==7)||((a>10)&&(a<14))||(a==15)||(a==19)||(a==29)||(a==35)||((a>38)&&(a<42))||(a==49)|(a==54))
        {
            MoveCharacter(pos_x, pos_y, -1);//To Move Left Only
        }
        if(((a>1)&&(a<5))||(a==9)||(a==17)||(a==22)||(a==23)||(a==26)||(a==27)||(a==37)||((a>41)&&(a<45))||(a==46)||(a==56))
        {
            MoveCharacter(pos_x, pos_y, 1);//To Move Right Only
        }
        Sleep(1000);//delay for 1 second
        dest_count = POSITION_MATCH();                                                 // reset 'x' cells counter
        PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
        if((dest_num == dest_count)&&((dest_num!=0)&&(dest_count!=0)))
        {
             Sleep(1000);//delay for 1 second
            RefreshScreen();
            break;           
        }       
    }
//---------------------------Level26---------------------------------//
	level=level+1;    
    Place_Path(level);
    pos_x = pos_x - pos_x;
    pos_y = pos_y - pos_y;
    center_x = SCREEN_WIDTH / 2 - MAP_WIDTH / 2;
    center_y = SCREEN_HEIGHT / 2 - MAP_HEIGHT / 2;    
    PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
    clear_dest_square();    
    dest_num = GetDestSquares();
    for (int a=1; a<33; a++)
    {
        GetPosition(&pos_x, &pos_y);
        if((a==5)||(a==6)||(a==8)||(a==9)||(a==11)||(a==27)||(a==30))
        {
            MoveCharacter(pos_x, pos_y,  - MAP_WIDTH);//To Move UP Only
        }
        if((a==1)||((a>14)&&(a<18))||(a==19)||(a==25))
        {
            MoveCharacter(pos_x, pos_y,  MAP_WIDTH);//To Move Down Only
        } 
        if((a==7)||(a==12)||(a==13)||((a>19)&&(a<25))||(a==26))
        {
            MoveCharacter(pos_x, pos_y, -1);//To Move Left Only
        }
        if(((a>1)&&(a<5))||(a==10)||(a==14)||(a==18)||(a==28)||(a==29)||(a==31)||(a==32))
        {
            MoveCharacter(pos_x, pos_y, 1);//To Move Right Only
        }
        Sleep(1000);//delay for 1 second
        dest_count = POSITION_MATCH();                                                 // reset 'x' cells counter
        PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
        if((dest_num == dest_count)&&((dest_num!=0)&&(dest_count!=0)))
        {
             Sleep(1000);//delay for 1 second
            RefreshScreen();
            break;           
        }       
    }
//---------------------------Level27---------------------------------//
	level=level+1;    
    Place_Path(level);
    pos_x = pos_x - pos_x;
    pos_y = pos_y - pos_y;
    center_x = SCREEN_WIDTH / 2 - MAP_WIDTH / 2;
    center_y = SCREEN_HEIGHT / 2 - MAP_HEIGHT / 2;    
    PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
    clear_dest_square();    
    dest_num = GetDestSquares();
    for (int a=1; a<37; a++)
    {
        GetPosition(&pos_x, &pos_y);
        if((a==3)||(a==4)||((a>5)&&(a<9))||(a==13)||(a==23)||(a==26)||((a>29)&&(a<33)))
        {
            MoveCharacter(pos_x, pos_y,  - MAP_WIDTH);//To Move UP Only
        }
        if((a==11)||((a>14)&&(a<18))||(a==19)||(a==20)||(a==28)||(a==35))
        {
            MoveCharacter(pos_x, pos_y,  MAP_WIDTH);//To Move Down Only
        } 
        if((a==5)||(a==9)||(a==10)||((a>20)&&(a<23))||(a==29)||(a==33)||(a==34))
        {
            MoveCharacter(pos_x, pos_y, -1);//To Move Left Only
        }
        if((a==1)||(a==2)||(a==12)||(a==14)||(a==18)||(a==24)||(a==25)||(a==27)||(a==36))
        {
            MoveCharacter(pos_x, pos_y, 1);//To Move Right Only
        }
        Sleep(1000);//delay for 1 second
        dest_count = POSITION_MATCH();                                                 // reset 'x' cells counter
        PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
        if((dest_num == dest_count)&&((dest_num!=0)&&(dest_count!=0)))
        {
             Sleep(1000);//delay for 1 second
            RefreshScreen();
            break;           
        }       
    }
//---------------------------Level28---------------------------------//
	level=level+1;    
    Place_Path(level);
    pos_x = pos_x - pos_x;
    pos_y = pos_y - pos_y;
    center_x = SCREEN_WIDTH / 2 - MAP_WIDTH / 2;
    center_y = SCREEN_HEIGHT / 2 - MAP_HEIGHT / 2;    
    PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
    clear_dest_square();    
    dest_num = GetDestSquares();
    for (int a=1; a<25; a++)
    {
        GetPosition(&pos_x, &pos_y);
        if(((a>3)&&(a<7))||(a==11)||(a==12)||(a==20)||(a==21)||(a==23))
        {
            MoveCharacter(pos_x, pos_y,  - MAP_WIDTH);//To Move UP Only
        }
        if((a==1)||(a==9)||(a==10)||(a==15)||(a==16)||(a==18))
        {
            MoveCharacter(pos_x, pos_y,  MAP_WIDTH);//To Move Down Only
        } 
        if((a==2)||(a==3)||(a==13)||(a==14)||(a==24))
        {
            MoveCharacter(pos_x, pos_y, -1);//To Move Left Only
        }
        if((a==7)||(a==8)||(a==17)||(a==19)||(a==22))
        {
            MoveCharacter(pos_x, pos_y, 1);//To Move Right Only
        }
        Sleep(1000);//delay for 1 second
        dest_count = POSITION_MATCH();                                                 // reset 'x' cells counter
        PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
        if((dest_num == dest_count)&&((dest_num!=0)&&(dest_count!=0)))
        {
             Sleep(1000);//delay for 1 second
            RefreshScreen();
            break;           
        }       
    }
//---------------------------Level29---------------------------------//
	level=level+1;    
    Place_Path(level);
    pos_x = pos_x - pos_x;
    pos_y = pos_y - pos_y;
    center_x = SCREEN_WIDTH / 2 - MAP_WIDTH / 2;
    center_y = SCREEN_HEIGHT / 2 - MAP_HEIGHT / 2;    
    PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
    clear_dest_square();    
    dest_num = GetDestSquares();
    for (int a=1; a<31; a++)
    {
        GetPosition(&pos_x, &pos_y);
        if(((a>3)&&(a<6))||(a==7)||(a==13)||(a==14)||(a==16)||(a==27)||(a==28))
        {
            MoveCharacter(pos_x, pos_y,  - MAP_WIDTH);//To Move UP Only
        }
        if((a==10)||(a==11)||(a==19)||(a==21)||(a==22)||(a==24)||(a==30))
        {
            MoveCharacter(pos_x, pos_y,  MAP_WIDTH);//To Move Down Only
        } 
        if(((a>0)&&(a<4))||(a==6)||(a==8)||(a==9)||(a==15)||(a==29))
        {
            MoveCharacter(pos_x, pos_y, -1);//To Move Left Only
        }
        if((a==12)||(a==17)||(a==18)||(a==20)||(a==23)||(a==25)||(a==26))
        {
            MoveCharacter(pos_x, pos_y, 1);//To Move Right Only
        }
        Sleep(1000);//delay for 1 second
        dest_count = POSITION_MATCH();                                                 // reset 'x' cells counter
        PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
        if((dest_num == dest_count)&&((dest_num!=0)&&(dest_count!=0)))
        {
             Sleep(1000);//delay for 1 second
            RefreshScreen();
            break;           
        }       
    }
    //---------------------------Levellast---------------------------------//
    level=level+1;    
    Place_Path(level);
    pos_x = pos_x - pos_x;
    pos_y = pos_y - pos_y;
    center_x = SCREEN_WIDTH / 2 - MAP_WIDTH / 2;
    center_y = SCREEN_HEIGHT / 2 - MAP_HEIGHT / 2;    
    PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
    clear_dest_square();
    dest_num = GetDestSquares();
    for (int a=1; a<196; a++)
    {
        GetPosition(&pos_x, &pos_y);
        if((a==2)||(a==7)||(a==8)||((a>14)&&(a<20))||(a==28)||(a==36)||(a==37)||(a==49)||(a==55)||
           ((a>56)&&(a<60))||(a==66)||(a==68)||(a==77)||(a==78)||(a==80)||(a==86)||(a==87)||((a>102)&&
           (a<106))||(a==113)||(a==114)||(a==122)||((a>127)&&(a<131))||(a==132)||(a==140)||(a==141)||
           ((a>147)&&(a<152))||(a==158)||(a==159)||(a==165)||(a==165)||(a==173)||(a==177)||(a==178)||
           (a==180)||(a==190)||(a==191))
       {
            MoveCharacter(pos_x, pos_y,  - MAP_WIDTH);//To Move UP Only
        }
        if((a==4)||(a==10)||(a==12)||(a==22)||(a==23)||(a==31)||((a>39)&&(a<43))||(a==44)||(a==50)||
           (a==62)||(a==63)||(a==65)||(a==71)||(a==73)||(a==74)||(a==82)||(a==90)||(a==91)||((a>98)&&
           (a<102))||(a==109)||(a==110)||((a>117)&&(a<121))||(a==125)||(a==135)||((a>143)&&(a<148))||
           (a==154)||(a==155)||((a>161)&&(a<165))||(a==169)||(a==170)||(a==174)||(a==183)||(a==194)||
           (a==195))
        {
            MoveCharacter(pos_x, pos_y,  MAP_WIDTH);//To Move Down Only
        } 
        if((a==3)||(a==5)||(a==6)||(a==11)||(a==14)||(a==24)||((a>31)&&(a<36))||(a==38)||(a==39)||
           ((a>50)&&(a<55))||(a==56)||(a==72)||(a==75)||(a==76)||((a>82)&&(a<86))||(a==88)||(a==89)||
           ((a>95)&&(a<99))||(a==102)||(a==111)||((a>114)&&(a<118))||(a==121)||(a==126)||((a>135)&&
           (a<140))||(a==142)||(a==143)||(a==156)||(a==160)||(a==161)||(a==175)||(a==176)||((a>183)&&
           (a<189))||(a==192)||(a==193))
        {
            MoveCharacter(pos_x, pos_y, -1);//To Move Left Only
        }
        if((a==1)||(a==9)||(a==13)||(a==20)||(a==21)||((a>24)&&(a<28))||(a==29)||(a==30)||(a==43)||
           ((a>44)&&(a<49))||(a==60)||(a==61)||(a==64)||(a==67)||(a==69)||(a==70)||(a==79)||(a==81)||
           ((a>91)&&(a<96))||(a==32)||((a>105)&&(a<109))||(a==112)||(a==121)||(a==123)||(a==124)||
           (a==127)||(a==131)||(a==133)||(a==134)||(a==152)||(a==153)||(a==157)||((a>165)&&(a<169))||
           (a==171)||(a==172)||(a==179)||(a==181)||(a==182)||(a==189))
        {
            MoveCharacter(pos_x, pos_y, 1);//To Move Right Only
        }
        Sleep(1000);//delay for 1 second
        dest_count = POSITION_MATCH();                                                 // reset 'x' cells counter
        PrintMap(center_x, center_y, MAP_WIDTH, MAP_HEIGHT, map);
        if((dest_num == dest_count)&&((dest_num!=0)&&(dest_count!=0)))
        {
             Sleep(1000);//delay for 1 second
            sprintf(screen + (SCREEN_WIDTH * SCREEN_HEIGHT / 2) - MAP_WIDTH / 2, "   YOU WIN!");
            RefreshScreen();
            break;           
        }       
    }
    Leave();
    return 0;
}
