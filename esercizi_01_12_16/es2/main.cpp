#include <iostream>
#include <stdio.h>
#include <time.h>
#include <cstdlib>
#define MAX 5
#define Ntrappole 3

using namespace std;

int dungeon[MAX][MAX];

void dungeon_creation();
void matrix_stamp();
void position_trap();

int main()
{

    dungeon_creation();
    matrix_stamp();
    position_trap();
    matrix_stamp();



    return 0;
}

/////stampa matrice
void matrix_stamp()
{
    for(int j=0;j<MAX;j++)
    {
        for(int i=0;i<MAX;i++)
        {
            cout << dungeon[j][i];
        }
        cout << "" <<endl;
    }
    system("PAUSE");
    system("CLS");
}

/////creazione dungeon
void dungeon_creation()
{
    for(int j=0;j<MAX;j++)
    {
        for(int i=0;i<MAX;i++)
        {
            dungeon[j][i]=0;
        }
    }
}

/////posizionamento trappole
void position_trap()
{
    int i,j;
    srand(time(NULL));
    for(int k=0; k<Ntrappole;)
    {
        i=rand()%MAX;
        j=rand()%MAX;
        if(dungeon[j][i]!=0)
        {
            dungeon[j][i]=5;
            k++;
        }
    }
}
