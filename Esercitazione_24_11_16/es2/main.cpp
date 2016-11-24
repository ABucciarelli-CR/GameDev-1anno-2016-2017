#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>



int main()
{
    srand(time(NULL));
    int matrix[10][10];
    int victory=0;
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
        matrix[shipj][shipi]=1;

//////////inizio gioco
        do
        {
            std::cout << "Casella X dove vuoi colpire:" << std::endl;
            std::cin >> i;
            std::cout << "Casella Y dove vuoi colpire:" << std::endl;
            std::cin >> j;
            if(i<1 || i>10 || j<1 || j<10 || matrix[j][i]==2)
            {
                std::cout << "valore/i non valido/i, reinserire" << std::endl;
            }
        }
        while(i<1 || i>10 || j<1 || j<10);

        if(i==shipi && j==shipj)
        {
            std::cout << "Grandeeeee, hai vinto :D" << std::endl;
            std::cout << "Vuoi ricominciare?(1 si/0 no)" << std::endl;
            do
            {
                std::cin >> victory;
                if(victory<0 || victory>1)
                {
                    std::cout << "Valore errato, reinserire" << std::endl;
                }
            }
            while(victory<0 || victory>1);
        }
        else
        {
            matrix[j][i]=2;
        }
    }
    while(victory==0);

    return 0;
}
