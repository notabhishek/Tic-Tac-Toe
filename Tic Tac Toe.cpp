//Code by Abhishek Tiwari
//Hackerearth : https://www.hackerearth.com/@become
//Github :https://github.com/becomeahacker

#include<iostream>
#include<stdlib.h>
using namespace std;
char b[3][3];
void Draw_board()
{
    system("cls");
    cout<<"\n\n\t\t\tT i c k   T a c   T o e\n";
    cout<<"\tPlayer1 [X] \n";
    cout<<"\tPlayer2 [O] \n\n";

    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<b[0][0]<<"  |  "<<b[0][1]<<"  |  "<<b[0][2]<<"  \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<b[1][0]<<"  |  "<<b[1][1]<<"  |  "<<b[1][2]<<"  \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<b[2][0]<<"  |  "<<b[2][1]<<"  |  "<<b[2][2]<<"  \n";
    cout<<"\t\t     |     |     \n";

}

int check_won()
{
    char p='X';
    // CHECK IF PLAYER 1 [X] HAS WON
    for(int i=0;i<3;++i)
    if(b[i][0]==p && b[i][1]==p && b[i][2]==p)
        return 1;

    for(int i=0;i<3;++i)
    if(b[0][i]==p && b[1][i]==p && b[2][i]==p)
        return 1;

    if(b[0][0]==p && b[1][1]==p && b[2][2]==p)
        return 1;

    if(b[0][2]==p && b[1][1]==p && b[2][0]==p)
        return 1;

    //CHECK IF PLAYER 2 [O] HAS WON
    p='O';

    for(int i=0;i<3;++i)
    if(b[i][0]==p && b[i][1]==p && b[i][2]==p)
        return 2;

    for(int i=0;i<3;++i)
    if(b[0][i]==p && b[1][i]==p && b[2][i]==p)
        return 2;

    if(b[0][0]==p && b[1][1]==p && b[2][2]==p)
        return 2;

    if(b[0][2]==p && b[1][1]==p && b[2][0]==p)
        return 2;

    //CHECK FOR A DRAW
    for(int i=0;i<3;++i)
        for(int j=0;j<3;++j)
        if(b[i][j]<='9' && b[i][j]>='1')
        return 0; // No One has won game continues

    return -1; // DRAW
}
int main()
{

        for(int i=0;i<3;++i)
        for(int j=0;j<3;++j)
        b[i][j]=(i*3+j)+'1';

        Draw_board();
        bool flag=true;
        int chance=1;
        int choice;
        while(flag)
        {
            cout<<"Enter your choice Player "<<chance<<"\n";
            A:
            cin>>choice;
            if(b[choice/3][choice%3-1]=='X' || b[choice/3][choice%3-1]=='O')
                {
                cout<<"Already occupied!!! Enter other place\n";
                goto A;
                }

            if(chance==1)
                {
                    b[choice/3][choice%3-1]='X';
                    chance=2;
                }
            else
                {
                    b[choice/3][choice%3-1]='O';
                    chance=1;
                }
            Draw_board();

        int result=check_won();
        if(result==-1)
        {
            cout<<"DRAW!!!\n";
            flag=false;
        }
        if(result==1)
        {
            cout<<"Player 1 Won!!!\n";
            flag=false;
        }
        if(result==2)
        {
            cout<<"Player 2 Won!!!\n";
            flag=false;
        }


        }


return 0;
}
