// MINI PROJECT
//TIC TAC TOE
//CREATED BY MANAV GOSWAMI ON 16/11/2017
#include<stdio.h>
#include<string.h>
void input(int[][3],int);
char check(int[][3]);
void display(int[][3]);
int main()         //main function : name of players and other function calling
{
    char name1[30],name2[30],name3[30],b,c;
    int table[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}},count=0,k=0,f,opt=0;
    printf("ENTER THE NAME OF PLAYER X :");
    gets(name1);
    printf("ENTER THE NAME OF PLAYER 0 :");
    gets(name2);
    do
    {
    do
    {
        printf("who will play first, %s or %s :",name1,name2);
        gets(name3);
        if((strcmp(name1,name3)!=0)&&(strcmp(name2,name3)!=0))
        {
            printf("%s is not a registered player ",name3);
        }
            else
            {
                if(strcmp(name1,name3)==0)
                {
                    b='X';
                    c='O';
                }
                else
                {
                    b='O';
                    c='X';
                    k=1;
                }
            }
    }while((strcmp(name1,name3)!=0)&&(strcmp(name2,name3)!=0));
    display(table);
    while(count<9)
    {
        if(count%2==0)
        {
            if(k%2==0)
            printf("\n\n PLAYER FOR CURRENT TURN :%s\n",name1);
            else
            printf("\n\n PLAYER FOR CURRENT TURN :%s\n",name2);
            input(table,b);
            k++;
        }
        else
        {
            if(k%2==0)
                printf("\n\nplayer for current turn :%s\n",name1);
            else
                printf("\n\nplayer for current turn  :%s\n",name2);
                input(table,c);
                k++;
        }
        if(count>=4)
            f=check(table);
            display(table);
        if(f=='X'||f=='O')
                break;
                count++;
    }
        if(f=='X')
        printf("\n%s WINS\n",name1);
        else if(f=='O')
        printf("\n%s WINS\n",name2);
        else
        printf("\n MATCH DRAW\n");
        return 0;
        printf("DO YOU WANT TO CONTINUE Y/N :");
        scanf("%d",&opt);
    }while(opt==1);
}
void input(int table[3][3],int x)
{
    int i,j;
    do
    {
        do
        {
            printf("choose a number {0 to 2} :");
            scanf("%d",&i);
            if(i>2||i<0)
            printf("%d is not a valid  row",i);
        }while(i<0 || i>2);

        printf("choose a column number {0 to 2} :");
        scanf("%d",&j);
        if(j<0||j>2)
        printf("%d is not a valid column ",j);
    }while((j<0||j>2)&&(i>2||i<0));
    if(table[i][j]=='1'||table[i][j]=='2'||table[i][j]=='3'||table[i][j]=='4'||table[i][j]=='5'||table[i][j]=='6'
       ||table[i][j]=='7'||table[i][j]=='8'||table[i][j]=='9')
    table[i][j]=x;
    else
    {
        printf("\n space already occupied \n");
        input(table,x);
    }
}
void display(int table[3][3])
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%c",table[i][j]);
        }
        printf("\n");
    }
}
char check(int table[][3])
{

     if(table[0][0]==table[1][1]&&table[1][1]==table[2][2])
        return(table[0][0]);
     else if(table[0][2]==table[1][1]&&table[1][1]==table[2][0])
        return(table[0][2]);
     else if(table[0][0]==table[0][1]&&table[0][1]==table[0][2])
        return(table[0][0]);
     else if(table[1][0]==table[1][1]&&table[1][1]==table[1][2])
        return(table[1][0]);
     else if(table[2][0]==table[2][1]&&table[2][1]==table[2][2])
        return(table[2][0]);
     else if(table[0][0]==table[1][0]&&table[1][0]==table[2][0])
        return(table[2][0]);
     else if(table[0][1]==table[1][1]&&table[1][1]==table[2][1])
        return(table[0][1]);
     else if(table[0][2]==table[1][2]&&table[1][2]==table[2][2])
        return(table[2][2]);
        else
           return('a');
 }

