#include <iostream>
#include <stdio.h>
#include <time.h>
#include <cstdlib>
#define MAX 5
#define Nbloks 3
#define Nmonsters 3

using namespace std;

int dungeon[MAX][MAX];
int dungeonapp[MAX][MAX];
int X,Xprim,Y,Yprim;

void dungeon_creation();
void matrix_stamp();
void position_monsters();
void position_treasure();
void position_player();
void position_unbrecable_bloks();

int player_move();
int monsters_move(int Jmonster, int Imonster);
int win(int WinImput);
int dungeon_update(int result);


int main()
{
    int retry=1;
    int monsters_moved=0;
    int WinLoseNull=0;
    int i,j;

    do
    {
        dungeon_creation();
        position_monsters();
        position_treasure();
        position_player();
        position_unbrecable_bloks();
        matrix_stamp();
        do
        {
            WinLoseNull=player_move();
            WinLoseNull=dungeon_update(WinLoseNull);
            if(WinLoseNull!=2 && WinLoseNull!=1)
            {
               do
                {
                    for(j=0;j<MAX;j++)
                    {
                        for(i=0;i<MAX;i++)
                        {
                            if(dungeon[j][i]==5)
                            {
                                WinLoseNull=monsters_move(j, i);
                                monsters_moved++;
                            }
                        }
                    }
                }
                while(monsters_moved<Nmonsters);
            }
            matrix_stamp();
            dungeon_update(WinLoseNull);
            matrix_stamp();
            retry=win(WinLoseNull);
        }
        while(WinLoseNull!=1 && WinLoseNull!=2);
    }
    while(retry==1);


    return 0;
}

/////stampa matrice
void matrix_stamp()
{
    system("PAUSE");
    system("CLS");
    for(int j=0;j<MAX;j++)
    {
        for(int i=0;i<MAX;i++)
        {
            cout << dungeon[j][i];
        }
        cout << "" <<endl;
    }
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
void position_monsters()
{
    int i,j;
    srand(time(NULL));
    for(int k=0; k<Nmonsters;)
    {
        i=rand()%MAX;
        j=rand()%MAX;
        if(dungeon[j][i]==0)
        {
            dungeon[j][i]=5;
            k++;
        }
    }
}

/////posizionamento tesoro
void position_treasure()
{
    int i,j;
    srand(time(NULL));
    do
    {
        i=rand()%MAX;
        j=rand()%MAX;
        if(dungeon[j][i]==0)
        {
            dungeon[j][i]=1;
        }
    }
    while(dungeon[j][i]!=1);
}

/////posizionamento del giocatore
void position_player()
{
    int i,j;
    srand(time(NULL));
    do
    {
        i=rand()%MAX;
        j=rand()%MAX;
        Y=j;
        X=i;
        Yprim=j;
        Xprim=i;
        if(dungeon[j][i]==0)
        {
            dungeon[j][i]=7;
        }
    }
    while(dungeon[j][i]!=7);
}

//////posizionamento blocchi indistruttibili
void position_unbrecable_bloks()
{
    int i,j;
    int bloks=0;
    srand(time(NULL));
    do
    {
        i=rand()%MAX;
        j=rand()%MAX;
        if(dungeon[j][i]==0)
        {
            dungeon[j][i]=6;
            bloks++;
        }
    }
    while(bloks<Nbloks);
}

/////movimento del giocatore
int player_move()
{
    char moves;
    int result=0;
    int quit=0;
    int Wok=0;
    int Aok=0;
    int Sok=0;
    int Dok=0;
////////controllo possibili movimenti
    cout << "Fai la tua mossa:" << endl;
    if(Y>0 && dungeon[Y-1][X]!=6)
    {
        cout << "W => su" << endl;
        Wok=1;
    }
    if(X>0 && dungeon[Y][X-1]!=6)
    {
        cout << "A => sx" << endl;
        Aok=1;
    }
    if(Y<MAX-1 && dungeon[Y+1][X]!=6)
    {
        cout << "S => giu" << endl;
        Sok=1;
    }
    if(X<MAX-1 && dungeon[Y][X+1]!=6)
    {
        cout << "D => dx" << endl;
        Dok=1;
    }
///////esecuzione movimento
    do
    {
        cin >> moves;
/////////su
        if(moves=='w' || moves=='W')
        {
            if(Wok==0)
            {
                cout << "Reinserisci, mossa non possibile" << endl;
            }
            else
            {
                Xprim=X;
                Yprim=Y;
                Y--;
                quit=1;
            }
        }
/////////sx
        else if(moves=='a' || moves=='A')
        {
            if(Aok==0)
            {
                cout << "Reinserisci, mossa non possibile" << endl;
            }
            else
            {
                Yprim=Y;
                Xprim=X;
                X--;
                quit=1;
            }
        }
/////////giu
        else if(moves=='s' || moves=='S')
        {
            if(Sok==0)
            {
                cout << "Reinserisci, mossa non possibile" << endl;
            }
            else
            {
                Xprim=X;
                Yprim=Y;
                Y++;
                quit=1;
            }
        }
/////////dx
        else if(moves=='d' || moves=='D')
        {
            if(Dok==0)
            {
                cout << "Reinserisci, mossa non possibile" << endl;
            }
            else
            {
                Yprim=Y;
                Xprim=X;
                X++;
                quit=1;
            }
        }
    }
    while(quit==0);

    if(dungeon[Yprim][Xprim]==5)
    {
        result=2;
    }

    return result;
}

/////aggiornamento dungeon
int dungeon_update(int result)
{
////risultati: 1 vinto, 2 Perso, 0 Nulla
    int j,i;

    if(dungeon[Y][X]==5)
    {
        result=2;
    }
    else if(dungeon[Y][X]==1)
    {
        result=1;
    }
    else if(result!=2)
    {
        dungeon[Y][X]=7;
        dungeon[Yprim][Xprim]=0;
    }

    for(j=0;j<MAX;j++)
    {
        for(i=0;i<MAX;i++)
        {
            if(dungeonapp[j][i]==5)
            {
                dungeonapp[j][i]=0;
                dungeon[j][i]=5;
            }
        }
    }

    return result;
}

/////controllo vittoria/sconfitta
int win(int WinImput)
{
    int result=1;
    do
    {
        if(WinImput==1)
        {
            cout << "Complimenti, hai vinto!" << endl;
            cout << "Vuoi riprovare?(1 Yes/ 0 No)" << endl;
            cin >> result;
        }
        else if(WinImput==2)
        {
            cout << "Mi spiace, hai perso" << endl;
            cout << "Vuoi riprovare?(1 Yes/ 0 No)" << endl;
            cin >> result;
        }
        if(result!=0 && result!=1)
        {
            cout << "Errore nell'inserimento, riprovare" << endl;
        }
    }
    while(result!=0 && result!=1);

    return result;
}

/////movimento mostri
int monsters_move(int Jmonster, int Imonster)
{
    int result=0;
    int random_move;
    int move_executed=0;
    srand(time(NULL));

    do
    {
        random_move=rand()%4;
        switch(random_move)
        {
            case 0:
                if((dungeon[Jmonster+1][Imonster]==0 || dungeon[Jmonster+1][Imonster]==7) && Jmonster+1<MAX)
                {
                    if(dungeon[Jmonster+1][Imonster]==7)
                    {
                        result=2;
                    }

                    dungeonapp[Jmonster+1][Imonster]=5;
                    dungeon[Jmonster][Imonster]=0;
                    move_executed=1;
                }
                break;

            case 1:
                if((dungeon[Jmonster-1][Imonster]==0 || dungeon[Jmonster-1][Imonster]==7) && Jmonster-1>=0)
                {
                    if(dungeon[Jmonster-1][Imonster]==7)
                    {
                        result=2;
                    }

                    dungeonapp[Jmonster-1][Imonster]=5;
                    dungeon[Jmonster][Imonster]=0;
                    move_executed=1;
                }
                break;

            case 2:
                if((dungeon[Jmonster][Imonster+1]==0 || dungeon[Jmonster][Imonster+1]==7) && Imonster+1<MAX)
                {
                    if(dungeon[Jmonster][Imonster+1]==7)
                    {
                        result=2;
                    }

                    dungeonapp[Jmonster][Imonster+1]=5;
                    dungeon[Jmonster][Imonster]=0;
                    move_executed=1;
                }
                break;

            case 3:
                if((dungeon[Jmonster][Imonster-1]==0 || dungeon[Jmonster][Imonster-1]==7) && Imonster-1>=0)
                {
                    if(dungeon[Jmonster][Imonster-1]==7)
                    {
                        result=2;
                    }

                    dungeonapp[Jmonster][Imonster-1]=5;
                    dungeon[Jmonster][Imonster]=0;
                    move_executed=1;
                }
                break;

            default:
                break;
        }
    }
    while(move_executed==0);

    return result;
}
