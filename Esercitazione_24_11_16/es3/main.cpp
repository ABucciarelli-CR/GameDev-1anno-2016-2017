#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define SEED 50

int matrix[10][10];
void matrixStamp();
void near_fire(int, int, int, int);

///////esercizio con SEED fisso
int main()
{
    srand(SEED);
    int victory=0;
    int quit=1;
    int shipi,shipj;
    int i,j;

    do
    {

////////riempimento matrice
        for(j=0;j<10;j++)
        {
            for(i=0;i<10;i++)
            {
                matrix[j][i]=0;
            }
        }

///////posizionamento nave malvagia
        shipi=rand()%10;
        shipj=rand()%10;
//////////inizio gioco
        do
        {
            do
            {
//////////////////inserimento valori di X ed Y
                matrixStamp();
                std::cout << "Casella X dove vuoi colpire:" << std::endl;
                std::cin >> i;
                std::cout << "Casella Y dove vuoi colpire:" << std::endl;
                std::cin >> j;
                if(i<0 || i>9 || j<0 || j>9 || matrix[j][i]==2)
                {
                    std::cout << "valore/i non valido/i, reinserire" << std::endl;
                }
            }
            while(i<0 || i>9 || j<0 || j>9);

//////////////controllo affondamento nave malvagia
            if(i==shipi && j==shipj)
            {
                system("PAUSE");
                system("CLS");
                matrix[j][i]=1;
                matrixStamp();
                victory=1;
                std::cout << "Grandeeeee, hai vinto :D" << std::endl;
                std::cout << "Vuoi ricominciare?(1 si/0 no)" << std::endl;
                do
                {
                    std::cin >> quit;
                    if(quit<0 || quit>1)
                    {
                        std::cout << "Valore errato, reinserire" << std::endl;
                    }
                }
                while(quit<0 || quit>1);
            }
            else
            {
                near_fire(i, j, shipi, shipj);
                matrix[j][i]=2;
            }
            system("PAUSE");
            system("CLS");
        }
        while(victory==0);
    }
    while(quit==1);

    return 0;
}

//////creazione stampa della matrice
void matrixStamp()
{
    int i,j;
    std::cout << "    0 1 2 3 4 5 6 7 8 9" << std::endl;
    std::cout << "  - - - - - - - - - - - -X" << std::endl;
    for(j=0;j<10;j++)
    {
        std::cout <<  j << " |";
        for(i=0;i<10;i++)
        {
           std::cout << " " << matrix[j][i];
        }
        std::cout <<"|" << std::endl;
    }
    std::cout << "  | - - - - - - - - - -" << std::endl;
    std::cout << "  Y" << std::endl;
}

void near_fire(int x, int y, int shipx, int shipy)
{
    if(((shipx-x)<=1 && (shipx-x)>=-1) && ((shipy-y)<=1 && (shipy-y)>=-1))
    {
        std::cout << "Fuoco" << std::endl;
    }
    else if(((shipx-x)<=2 && (shipx-x)>=-2) && ((shipy-y)<=2 && (shipy-y)>=-2))
    {
        std::cout << "Fuochino" << std::endl;
    }
    else
    {
        std::cout << "Acqua" << std::endl;
    }
}
