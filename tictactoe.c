#include<stdio.h>
#include<string.h>
#define WIN 1
#define LOSS -1

char board[3][3]= {'1','2','3','4','5','6','7','8','9'};
void display()
{
    int index1,index2;
    for(index1=0; index1<3; index1++)
    {
        for(index2=0; index2<3; index2++)
        {
            printf("%c ",board[index1][index2]);
        }
        printf("\n");
    }
}
int is_moves_left()
{
    int index1,index2;
    for(index1=0; index1<3; index1++)
    {
        for(index2=0; index2<3; index2++)
        {
            if(board[index1][index2]!='X' && board[index1][index2]!='O')
                return 1; //denotes moves left
        }
    }
    return 0;  //denotes board full
}
void take_input(char ch,char input)
{
    int index1=0,index2=0;
    for(index1=0; index1<3; index1++)
    {
        for(index2=0; index2<3; index2++)
        {
            if(ch==board[index1][index2])
                board[index1][index2]=input;
        }
    }
}
int check_win()
{
    int index1,index2;
    int flagr=0,flagc=0,flagd=0;
    for(index1=0;index1<3;index1++)
    {
        if(board[index1][0]==board[index1][1]&&board[index1][1]==board[index1][2])
        {
            flagr=1;
        }
    }
    for(index1=0;index1<3;index1++)
    {
        if(board[0][index1]==board[1][index1]&&board[1][index1]==board[2][index1])
        {
            flagc=1;
        }
    }
    if(board[0][0]==board[1][1]&&board[1][1]==board[2][2])
        flagd=1;
    else if(board[2][0]==board[1][1]&&board[1][1]==board[0][2])
        flagd=1;
    if(flagc==1||flagd==1||flagr==1)
        return WIN;
    else
        return LOSS;
}
int main()
{
    int player=0;
    char player1[20],player2[20],ch,pm1=0,pm2=0;
    printf("Enter name of player 1(X is your char):");
    scanf("%s",player1);
    printf("\nEnter name of player 2(O is your char):");
    scanf("%s",player2);
    display();
    while(is_moves_left()==1)
    {
        if(player==0)
        {
            printf("\nEnter number player (your move is X)%s:",player1);
            fflush(stdin);
            scanf("%c",&ch);
            take_input(ch,'X');
            system("cls");
            display();
            if(check_win()==1)
            {
                printf("\nPlayer %s wins!!\n",player1);
                break;
            }
        }
        else
        {
            printf("\nEnter number player (your move is O)%s:",player2);
            fflush(stdin);
            scanf("%c",&ch);
            take_input(ch,'O');
            system("cls");
            display();
            if(check_win()==1)
            {
                printf("\nPlayer %s wins!!\n",player2);
                break;
            }
        }
        player=!player;
    }
    if(check_win()==-1)
    {
        printf("\nNO PLAYER WON!! MATCH IS A DRAW\n");
    }
    return 0;
}
