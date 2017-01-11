#include <iostream>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define MaxTab 10

using namespace std;

void allyposition(int longship, int numShip);
void showBoard1();
void showBoard2();

void shotNblowUp();
int controlBoard1();
int controlBoard2();

////matrici
int Board1[MaxTab][MaxTab];
int Board2[MaxTab][MaxTab];

int appB1[MaxTab][MaxTab];
int appB2[MaxTab][MaxTab];

////creazione classi
//////classe base
class ship
{
protected:
    int longship;
    int numShip;

public:
/////acquisizioni
    int getLong(){return longship;}
    int getNumShip(){return numShip;}

/////posizionamento nave
    void shipPosition(int longship, int numShip);

////costruttore
    ship();

};

/////cacciatorpediniere
class destroyer : public ship
{
////costruttore
public:
    destroyer();
};

/////sottomarino
class submarine : public ship
{
////costruttore
public:
    submarine();
};

////corazzata
class battleship : public ship
{
////costruttore
public:
    battleship();
};

////portaerei
class  aircraftCarrier : public ship
{
////costruttore
public:
    aircraftCarrier();
};

/////costruttori
////nave
ship::ship()
{}

////cacciatorpediniere
destroyer::destroyer()
{
    longship=2;
    numShip=1;
}

////sottomarino
submarine::submarine()
{
    longship=3;
    numShip=3;
}

/////corazzata
battleship::battleship()
{
    longship=4;
    numShip=2;
}

/////portaerei
aircraftCarrier::aircraftCarrier()
{
    longship=5;
    numShip=1;
}

/////posizionamento nave
/////nemiche
void ship::shipPosition(int longship, int numShip)
{
    int i;
    int j;

    int nopos;

    int posX;
    int posY;
    int posXY;
    cout << "Posizionamento navi da " << longship << endl;

    for(j=0;j<numShip;j++)
    {
        showBoard2();
        cout << "Posizionamento nave " << j+1 << endl;
        for(nopos=0;nopos!=1;)
        {
            nopos=1;
            cout << "Seleziona asse Riga" << endl;
            do
            {
               cin >> posY;
               if(posY>MaxTab || posY<0)
               {
                   cout << "Posizione non valida, riprova" << endl;
               }
            }
            while(posY>MaxTab || posY<0);

            cout << "Seleziona asse Colonna" << endl;
            do
            {
               cin >> posX;
               if(posX>MaxTab || posX<0)
               {
                   cout << "Posizione non valida, riprova" << endl;
               }
            }
            while(posX>MaxTab || posX<0);

            if(Board2[posX][posY]==4)
            {
                nopos=0;
            }
            else
            {
                cout << "In che direzione vuoi far andare la nave? (0 Basso/ 1 DX)" << endl;
                do
                {
                   cin >> posXY;
                   if(posXY>1 || posXY<0)
                   {
                       cout << "Valore non valido, riprova" << endl;
                   }
                }
                while(posXY>1 || posXY<0);
            }
            if(nopos==0)
            {
                cout << "Area non valida, reinserire" << endl;
            }
        }

/////posizionamento nave
        if(posXY==0)
        {
            for(i=0;i<longship;i++)
            {
                Board2[posX+i][posY]=4;
            }
        }
        if(posXY==1)
        {
           for(i=0;i<longship;i++)
            {
                Board2[posX][posY+i]=4;
            }
        }
    }
}

/////alleate
void allyposition(int longship, int numShip)
{
     int i;
    int j;

    int nopos;

    int posX;
    int posY;
    int posXY;
    cout << "Posizionamento navi da " << longship << endl;

    for(j=0;j<numShip;j++)
    {
        showBoard1();
        cout << "Posizionamento nave " << j+1 << endl;
        for(nopos=0;nopos!=1;)
        {
            nopos=1;
            cout << "Seleziona asse Riga" << endl;
            do
            {
               cin >> posY;
               if(posY>MaxTab || posY<0)
               {
                   cout << "Posizione non valida, riprova" << endl;
               }
            }
            while(posY>MaxTab || posY<0);

            cout << "Seleziona asse Colonna" << endl;
            do
            {
               cin >> posX;
               if(posX>MaxTab || posX<0)
               {
                   cout << "Posizione non valida, riprova" << endl;
               }
            }
            while(posX>MaxTab || posX<0);

            if(Board1[posX][posY]==4)
            {
                nopos=0;
            }
            else
            {
                cout << "In che direzione vuoi far andare la nave? (0 Basso/ 1 DX)" << endl;
                do
                {
                   cin >> posXY;
                   if(posXY>1 || posXY<0)
                   {
                       cout << "Valore non valido, riprova" << endl;
                   }
                }
                while(posXY>1 || posXY<0);
            }
            if(nopos==0)
            {
                cout << "Area non valida, reinserire" << endl;
            }
        }

/////posizionamento nave
        if(posXY==0)
        {
            for(i=0;i<longship;i++)
            {
                Board1[posX+i][posY]=4;
            }
        }
        if(posXY==1)
        {
           for(i=0;i<longship;i++)
            {
                Board1[posX][posY+i]=4;
            }
        }
    }
}

/////stampa delle griglie
void showBoard1()
{
    int i;
    int j;
    for(j=0;j<MaxTab;j++)
    {
        for(i=0;i<MaxTab;i++)
        {
            cout << Board1[j][i];
        }
        cout << "" << endl;
    }
}
void showBoard2()
{
    int i;
    int j;
    for(j=0;j<MaxTab;j++)
    {
        for(i=0;i<MaxTab;i++)
        {
            cout << Board2[j][i];
        }
        cout << "" << endl;
    }
}
void showappB1()
{
    int i;
    int j;
    for(j=0;j<MaxTab;j++)
    {
        for(i=0;i<MaxTab;i++)
        {
            cout << appB1[j][i];
        }
        cout << "" << endl;
    }
}
void showappB2()
{
    int i;
    int j;
    for(j=0;j<MaxTab;j++)
    {
        for(i=0;i<MaxTab;i++)
        {
            cout << appB2[j][i];
        }
        cout << "" << endl;
    }
}

/////colpi giocatori
void shotNblowUp(int player)
{
    int i;
    int j;
    int ok;

    for(ok=0; ok!=1;)
    {
        cout << "Inserisci la riga:" << endl;
        do
        {
            cin >> i;
            if(i<0 || i>MaxTab)
            {
                cout << "Valore non valido, reinserire" << endl;
            }
        }
        while(i<0 || i>MaxTab);

        cout << "Inserisci la colonna:" << endl;
        do
        {
            cin >> j;
            if(j<0 || j>MaxTab)
            {
                cout << "Valore non valido, reinserire" << endl;
            }
        }
        while(j<0 || j>MaxTab);

//////controllo se colpito
////giocatore 1
        if(player==1)
        {
//////controllo tabella
            if(Board2[i][j]==4)
            {
                cout << "COLPITO!" << endl;
                appB2[i][j]=1;
                Board2[i][j]=0;
                ok=1;
            }
            else if(appB2[i][j]==1)
            {
                cout << "Hai gia' colpito li', ritenta" << endl;
            }
            else if(appB2[i][j]==0)
            {
                cout << "Acqua!" << endl;
                appB2[i][j]=2;
                ok=1;
            }
            else if(appB2[i][j]==2)
            {
                cout << "Hai gia' colpito li', ritenta" << endl;
                ok=1;
            }
        }
/////giocatore2
        else if(player==2)
        {
//////controllo tabella
            if(Board1[i][j]==4)
            {
                cout << "COLPITO!" << endl;
                appB1[i][j]=1;
                Board1[i][j]=0;
                ok=1;
            }
            else if(appB1[i][j]==1)
            {
                cout << "Hai gia' colpito li', ritenta" << endl;
            }
            else if(appB1[i][j]==0)
            {
                cout << "Acqua!" << endl;
                appB1[i][j]=2;
                ok=1;
            }
            else if(appB1[i][j]==2)
            {
                cout << "Hai gia' colpito li', ritenta" << endl;
                ok=1;
            }
        }

    }
}

////controllo navi rimaste
int controlBoard1()
{
    int i;
    int j;
    int endgame=1;

    for(j=0;j<MaxTab;j++)
    {
        for(i=0;i<MaxTab;i++)
        {
            if(Board1[j][i]==4)
            {
                endgame=0;
            }
        }
    }
    if(endgame==1)
    {
        cout << "Complimenti, il giocatore 2 ha vinto" << endl;
    }
    return endgame;
}

int controlBoard2()
{
    int i;
    int j;
    int endgame=1;

    for(j=0;j<MaxTab;j++)
    {
        for(i=0;i<MaxTab;i++)
        {
            if(Board2[j][i]==4)
            {
                endgame=0;
            }
        }
    }
    if(endgame==1)
    {
        cout << "Complimenti, il giocatore 2 ha vinto" << endl;
    }
    return endgame;
}

int main()
{

    int i;
    int j;
    int endgame1=0;
    int endgame2=0;

    srand(time(NULL));

////riempimento tabelle
////tabella 1
    for(i=0;i<MaxTab;i++)
    {
        for(j=0;j<MaxTab;j++)
        {
            Board1[i][j]=0;
        }
    }
////tabella 2
    for(i=0;i<MaxTab;i++)
    {
        for(j=0;j<MaxTab;j++)
        {
            Board2[i][j]=0;
        }
    }
////supporto tabella 1
    for(i=0;i<MaxTab;i++)
    {
        for(j=0;j<MaxTab;j++)
        {
            appB1[i][j]=0;
        }
    }
////supporto tabella 2
    for(i=0;i<MaxTab;i++)
    {
        for(j=0;j<MaxTab;j++)
        {
            appB2[i][j]=0;
        }
    }

//////creazione navi
    destroyer destr;
   // submarine sub;
   // battleship battship;
   // aircraftCarrier aircrcarr;





/////posizionamento navi nemiche
    destr.shipPosition(destr.getLong(), destr.getNumShip());
   // sub.shipPosition(sub.getLong(), sub.getNumShip());
   // battship.shipPosition(battship.getLong(), battship.getNumShip());
   // aircrcarr.shipPosition(aircrcarr.getLong(), aircrcarr.getNumShip());

/////posizionamento navi alleate
    allyposition(destr.getLong(), destr.getNumShip());
    //allyposition(sub.getLong(), sub.getNumShip());
    //allyposition(battship.getLong(), battship.getNumShip());
    //allyposition(aircrcarr.getLong(), aircrcarr.getNumShip());

////inizia lo scontro
    system("CLS");
    do
    {
        cout << "Ecco la tabella del giocatore 2, dove vuoi colpire?" << endl;
        showappB2();
        shotNblowUp(1);
        endgame1=controlBoard2();
        if(endgame1!=1)
        {
            system("PAUSE");
            system("CLS");
        cout << "Ecco la tabella del giocatore 1, dove vuoi colpire?" << endl;
        showappB1();
        shotNblowUp(2);
        endgame2=controlBoard1();
        system("PAUSE");
        system("CLS");
        }
    }
    while(endgame1==0 && endgame2==0);

    return 0;
}
