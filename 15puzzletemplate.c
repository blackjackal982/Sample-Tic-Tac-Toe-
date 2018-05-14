#include <stdio.h>
#include <stdlib.h>

void draw_board();
char take_input();
void process_input(char ch);
void go_left();
void go_up();
void go_down();
void go_right();
void clear_board();
void swap(int x1,int y1,int x2,int y2);
int check_win();

//Initial board , change the values and zero indexes for various boards
int board[4][4]= {1,2,3,4,5,6,7,8,9,10,11,12,0,13,14,15};

//Intially zero postions ,first and second indexes , if 0 is at (1,3) firstindex will be 1 and second will be 3
int zero_pos_first_index=3;
int zero_pos_second_index=0;
//Initial move count
int move_count=0;

int main()
{
   //Intitially draw the board
    draw_board();

    //Loop till check_win is not equal to 1
      while(check_win()!=1)
      {  char ch;
        //Take input and store in ch
        ch=take_input();
        //Process input (ch)
           process_input(ch);
        //Clear the board
          clear_board();
        //Draw the board again
          draw_board();
        //Increase move count
        move_count+=1;
        }
    //End Loop
    //Print You have won with ___ Moves
    printf("You have won with %d Moves",move_count);
}

void draw_board()
{
/*
Print the current board like
 1  2  3  4
 5  6  7  8
 9 10 11 12
13 14  0 15

----------[W] UP --- [S] Down --- [A] LEFT --- [D] Right--------------
*/
  int i,j;
  for(i=0;i<4;i++)
  {
      printf("\n");
      for(j=0;j<4;j++)
        printf(" %d ",board[i][j]);
  }
  printf("\n[W] UP --- [S] Down --- [A] LEFT --- [D] RIGHT");
}
void clear_board(){
    //Clear the board
    system("cls");
}
char take_input()
{ char ch;
/*
Take input and return it ,Use Fflush if scanf is being used

*/
ch= getchar();
 printf("character entered is %c",ch);
 return ch;
}

void process_input(char ch)
{
/*
Handle the input char ch ,which is either w,a,s,d ,for up,left,down and right
Use a switch case and call go_left(),go_right()etc respectively
*/
 switch(ch)
 {
     case 'w':
     case 'W':go_up();
               break;
     case 'a':
     case 'A': go_left();
               break;
    case 's' :
    case 'S':go_down();
             break;
    case 'd':
    case 'D': go_right();
              break;
 }
}

void go_left()
{
//move 0 tile left
if(zero_pos_second_index>0)
{swap(zero_pos_first_index,zero_pos_second_index,zero_pos_first_index,zero_pos_second_index-1);
 zero_pos_second_index=zero_pos_second_index-1;
}
}
void go_right()
{
//move 0 tile right
if(zero_pos_second_index<3)
{
    swap(zero_pos_first_index,zero_pos_second_index,zero_pos_first_index,zero_pos_second_index+1);
    zero_pos_second_index=zero_pos_second_index+1;
}
}
void go_up()
{
//Move 0 tile up
if(zero_pos_first_index>0)
{
     swap(zero_pos_first_index,zero_pos_second_index,zero_pos_first_index-1,zero_pos_second_index);
     zero_pos_first_index=zero_pos_first_index-1;
}
}
void go_down()
{
//Move 0 tile down
if(zero_pos_first_index<3)
{
    swap(zero_pos_first_index,zero_pos_second_index,zero_pos_first_index+1,zero_pos_second_index);
    zero_pos_first_index=zero_pos_first_index+1;
}
}

void swap(int x1,int y1,int x2,int y2)
{ int temp;
//Swap board[x1][y1] and board[x2][y2];
 temp=board[x1][y1];
 board[x1][y1]=board[x2][y2];
 board[x2][y2]=temp;
 printf("%d %d",board[x1][y1],board[x2][y2]);
}

int check_win(){
//Return 1 , if current board has all tiles perfectly places ,or 0 otherwise
int b[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};
int i , j ;
for(i=0;i<4;i++)
{
    for(j=0;j<4;j++)
    {
        if(board[i][j]!=b[i][j])
    return 0;
    }
}
return 1;
}
