#include <iostream>
#include <stdio.h>
#include <time.h>
#include <cstdlib>
#define MAX 5
#define Ntrappole 3

using namespace std;

int dungeon[MAX][MAX];
int X,Xprim,Y,Yprim;

void dungeon_creation();
void matrix_stamp();
void position_trap();
void position_treasure();
void position_player();
void player_move();

int win(int WinImput);
int dungeon_update();


int main()
{
    int retry=1;
    int WinLoseNull;

    do
    {
        dungeon_creation();
        position_trap();
        position_treasure();
        position_player();
        matrix_stamp();
        do
        {
            player_move();
            WinLoseNull=dungeon_update();
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
void position_trap()
{
    int i,j;
    srand(time(NULL));
    for(int k=0; k<Ntrappole;)
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

/////movimento del giocatore
void player_move()
{

    char moves;
    int quit=0;
    int Wok=0;
    int Aok=0;
    int Sok=0;
    int Dok=0;
////////controllo possibili movimenti
    cout << "Fai la tua mossa:" << endl;
    if(Y>0)
    {
        cout << "W => su" << endl;
        Wok=1;
    }
    if(X>0)
    {
        cout << "A => sx" << endl;
        Aok=1;
    }
    if(Y<MAX-1)
    {
        cout << "S => giu" << endl;
        Sok=1;
    }
    if(X<MAX-1)
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

}

/////aggiornamento dungeon
int dungeon_update()
{
////risultati: 1 vinto, 2 Perso, 0 Nulla
    int result;

    if(dungeon[Y][X]==5)
    {
        result=2;
    }
    else if(dungeon[Y][X]==1)
    {
        result=1;
    }
    else
    {
        dungeon[Y][X]=7;
        dungeon[Yprim][Xprim]=0;
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
