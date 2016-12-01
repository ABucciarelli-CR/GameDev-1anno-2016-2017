#include <iostream>
#include <ctime>
#include <cstdlib>

///////variabili globali
char table[3][3]={0,0,0,0,0,0,0,0,0};
int endGame=0;
int moves=0;
int victory=0;
int win=0;
int defeat=0;
int magicDraw=0;

////////funzioni
void crossTable();
void displaysTable();
void victoryCheck();
void artificialDeficenza(int);

int main()
{
    int start=0;
    int retry=0;

///////spiegazione generale
    std::cout << "Salve, benvenuto sul trissss avanzatooooo" << std::endl;
    std::cout << "Le caselle sono numerate come segue:" << std::endl;
    std::cout << "  A B C" << std::endl;
    std::cout << "1  | | " << std::endl;
    std::cout << "  -----" << std::endl;
    std::cout << "2  | | " << std::endl;
    std::cout << "  -----" << std::endl;
    std::cout << "3  | | " << std::endl;
    do
    {

////////scelta di chi inizia
        std::cout << "Vuoi iniziare tu o lasci fare al computere?(1 tu/2 computer)" << std::endl;
        do
        {
            std::cin >> start;
            if(start<=0 || start>2)
            {
                std::cout << "Risposta non valida, reinserire" << std::endl;
            }
        }
        while(start<=0 || start>2);
///////inizio giuocatore
        if(start==1)
        {
            crossTable();
        }
///////vizualizzazione tabellone se inizia giocatore
        if(start==1)
        {
            displaysTable();
        }

        do
        {
/////start Deficenza Artificiale
            std::cout << "Sta al computere" << std::endl;
            artificialDeficenza(win);
            displaysTable();
            victoryCheck();
            if(endGame==0)
            {
/////////giocatore
                crossTable();
//////visualizzazione del tabellone e controllo di vincita
                displaysTable();
                victoryCheck();
            }
        }
        while(endGame==0);
        do
        {
            if(win==1)
            {
                std::cout << "Vuoi riprovare la modalita' difficile?(0 no/1 si)" << std::endl;
            }
            else
            {
                std::cout << "Vuoi riprovare?(0 no/1 si)" << std::endl;
            }
            std::cin >> retry;
            if(retry<0 || retry>1)
            {
                std::cout << "Non vale, riprova" << std::endl;
            }
        }
        while(retry<0 || retry>1);
////////svuotamento vettore in caso di rivincita
        int i;
        int j;
        for(j=0;j<3;j++)
        {
            for(i=0;i<3;i++)
            {
                table[j][i]=0;
            }
        }

        system("CLS");
        displaysTable();

        endGame=0;
        moves=0;

    }
    while(retry==1);

    std::cout << "Risultati:" << std::endl;
    std::cout << "Vittorie: " << victory << std::endl;
    std::cout << "Sconfitte: " << defeat << std::endl;
    std::cout << "Pareggi: " << magicDraw << std::endl;
    return 0;
}

///////mettere croce
void crossTable()
{
    int row;
    char column;
    int correct=0;

    do
    {
//////inserimento colonna
        std::cout << "Dimmi la colonna:" << std::endl;
        do
        {
           std::cin >> column;
           if(column != 'a' && column != 'A' && column != 'b' && column != 'B' && column != 'c' && column != 'C')
           {
               std::cout << "Mossa errata, reinserisci" << std::endl;
           }
        }
        while(column != 'a' && column != 'A' && column != 'b' && column != 'B' && column != 'c' && column != 'C');

///////inserimento riga
        std::cout << "Dimmi la riga:" << std::endl;
        do
        {
            std::cin >> row;
            if(row<1 || row>3)
            {
                std::cout << "Mossa errata, reinserisci" << std::endl;
            }
        }
        while(row<1 || row>3);
/////////inserimento nelle righe/colonne
        if((column == 'A' && row == 1) || (column == 'a' && row == 1))
        {
            if(table[0][0]==0)
            {
                table[0][0]='X';
                ++moves;
                correct=1;
            }
            else
            {
                std::cout << "Non si puo', reinserisci" << std::endl;
            }
        }

        else if((column == 'B' && row == 1) || (column == 'b' && row == 1))
        {
            if(table[0][1]==0)
            {
                table[0][1]='X';
                ++moves;
                correct=1;
            }
            else
            {
                    std::cout << "Non si puo', reinserisci" << std::endl;
            }
        }

        else if((column == 'C' && row == 1) || (column == 'c' && row == 1))
        {
            if(table[0][2]==0)
            {
                table[0][2]='X';
                ++moves;
                correct=1;
            }
            else
            {
                std::cout << "Non si puo', reinserisci" << std::endl;
            }
        }

        else if((column == 'A' && row == 2) || (column == 'a' && row == 2))
        {
            if(table[1][0]==0)
            {
                table[1][0]='X';
                ++moves;
                correct=1;
            }
            else
            {
                std::cout << "Non si puo', reinserisci" << std::endl;
            }
        }

        else if((column == 'B' && row == 2) || (column == 'b' && row == 2))
        {
            if(table[1][1]==0)
            {
                table[1][1]='X';
                ++moves;
                correct=1;
            }
            else
            {
                std::cout << "Non si puo', reinserisci" << std::endl;
            }
        }

        else if((column == 'C' && row == 2) || (column == 'c' && row == 2))
        {
            if(table[1][2]==0)
            {
                table[1][2]='X';
                ++moves;
                correct=1;
            }
            else
            {
                std::cout << "Non si puo', reinserisci" << std::endl;
            }
        }

        else if((column == 'A' && row == 3) || (column == 'a' && row == 3))
        {
            if(table[2][0]==0)
            {
                table[2][0]='X';
                ++moves;
                correct=1;
            }
            else
            {
                std::cout << "Non si puo', reinserisci" << std::endl;
            }
        }

        else if((column == 'B' && row == 3) || (column == 'b' && row == 3))
        {
            if(table[2][1]==0)
            {
                table[2][1]='X';
                ++moves;
                correct=1;
            }
            else
            {
                std::cout << "Non si puo', reinserisci" << std::endl;
            }
        }

        else if((column == 'C' && row == 3) || (column == 'c' && row == 3))
        {
            if(table[2][2]==0)
            {
                table[2][2]='X';
                ++moves;
                correct=1;
            }
            else
            {
                std::cout << "Non si puo', reinserisci" << std::endl;
            }
        }
    }
    while(correct==0);
}

void victoryCheck()
{
////controllo prima riga
    if((table[0][0] == table[0][1] && table[0][1] == table[0][2]) && (table[0][0] == 'X' || table[0][0] == 'O'))
    {
        if(table[0][0]=='X')
        {
            std::cout <<"Complimenti! Hai vinto!" << std::endl;
            win=1;
            ++victory;
            endGame=1;
        }
        else if(table[0][0]=='O')
        {
            std::cout <<"Vince il computer!!" << std::endl;
            ++defeat;
            endGame=1;
        }
    }
////controllo seconda riga
    else if((table[1][0] == table[1][1] && table[1][1] == table[1][2]) && (table[1][0] == 'X' || table[1][0] == 'O'))
    {
        if(table[1][0]=='X')
        {
            std::cout <<"Complimenti! Hai vinto!" << std::endl;
            win=1;
            ++victory;
            endGame=1;
        }
        else if(table[1][0]=='O')
        {
            std::cout <<"Vince il computer!!" << std::endl;
            ++defeat;
            endGame=1;
        }
    }
/////controllo terza riga
    else if((table[2][0] == table[2][1] && table[2][1] == table[2][2]) && (table[2][0] == 'X' || table[2][0] == 'O'))
    {
        if(table[2][0]=='X')
        {
            std::cout <<"Complimenti! Hai vinto!" << std::endl;
            win=1;
            ++victory;
            endGame=1;
        }
        else if(table[2][0]=='O')
        {
            std::cout <<"Vince il computer!!" << std::endl;
            ++defeat;
            endGame=1;
        }
    }
//////controllo diagonali
    else if(((table[0][0] == table[1][1] && table[1][1]  == table[2][2] ) || (table[0][2]  == table[1][1] && table[1][1] == table[2][0])) && (table[1][1] == 'X' || table[1][1] == 'O'))
    {
        if(table[1][1]=='X')
        {
            std::cout <<"Complimenti! Hai vinto!" << std::endl;
            win=1;
            ++victory;
            endGame=1;
        }
        else if(table[1][1]=='O')
        {
            std::cout <<"Vince il computer!!" << std::endl;
            ++defeat;
            endGame=1;
        }
    }
/////controllo prima colonna
    else if((table[0][0] == table[1][0] && table[1][0] == table[2][0]) && (table[0][0] == 'X' || table[0][0] == 'O'))
    {
        if(table[0][0]=='X')
        {
            std::cout <<"Complimenti! Hai vinto!" << std::endl;
            win=1;
            ++victory;
            endGame=1;
        }
        else if(table[0][0]=='O')
        {
            std::cout <<"Vince il computer!!" << std::endl;
            ++defeat;
            endGame=1;
        }
    }
/////controllo seconda colonna
    else if((table[0][1] == table[1][1] && table[1][1] == table[2][1]) && (table[0][1] == 'X' || table[0][1] == 'O'))
    {
        if(table[0][1]=='X')
        {
            std::cout <<"Complimenti! Hai vinto!" << std::endl;
            win=1;
            ++victory;
            endGame=1;
        }
        else if(table[0][1]=='O')
        {
            std::cout <<"Vince il computer!!" << std::endl;
            ++defeat;
            endGame=1;
        }
    }
//////controllo terza colonna
    else if((table[0][2] == table[1][2] && table[1][2] == table[2][2]) && (table[0][2] == 'X' || table[0][2] == 'O'))
    {
        if(table[0][2]=='X')
        {
            std::cout <<"Complimenti! Hai vinto!" << std::endl;
            win=1;
            ++victory;
            endGame=1;
        }
        else if(table[0][2]=='O')
        {
            std::cout <<"Vince il computer!!" << std::endl;
            ++defeat;
            endGame=1;
        }
    }
///////pareggio
    else if(moves==9 && endGame==0)
    {
        std::cout <<"PAREGGIOOOO!!" << std::endl;
        ++magicDraw;
        endGame=1;
    }
}

//////creazione deficenza artificiale
void artificialDeficenza(int winn)
{
    int var=0;
    int var2=0;
    int OK=0;
    int nope=0;
    srand(time(0));
//////mette la O
//////diventa cattivo
    if(winn==1)
    {
////controllo prima riga
        nope=0;
        if((((table[0][0] == table[0][1]) && table[0][2]==0) && (table[0][0]=='O' || table[0][0]=='X') && (table[0][1]=='O' || table[0][1]=='X')) && nope==0)
        {
            table[0][2]='O';
            nope=1;
            ++moves;
        }
        else if((((table[0][1] == table[0][2]) && table[0][0]==0) && (table[0][1]=='O' || table[0][1]=='X') && (table[0][2]=='O' || table[0][2]=='X')) && nope==0)
        {
            table[0][0]='O';
            nope=1;
            ++moves;
        }
/////controllo seconda riga
        if((((table[1][0] == table[1][1]) && table[1][2]==0) && (table[1][0]=='O' || table[1][0]=='X') && (table[1][1]=='O' || table[1][1]=='X')) && nope==0)
        {
            table[1][2]='O';
            nope=1;
            ++moves;
        }
        else if((((table[1][1] == table[1][2]) && table[1][0]==0) && (table[1][1]=='O' || table[1][1]=='X') && (table[1][2]=='O' || table[1][2]=='X')) && nope==0)
        {
            table[1][0]='O';
            nope=1;
            ++moves;
        }
///////controllo terza riga
        if((((table[2][0] == table[2][1]) && table[2][2]==0) && (table[2][0]=='O' || table[2][0]=='X') && (table[2][1]=='O' || table[2][1]=='X')) && nope==0)
        {
            table[2][2]='O';
            nope=1;
            ++moves;
        }
        else if((((table[2][1] == table[2][2]) && table[2][0]==0) && (table[2][1]=='O' || table[2][1]=='X') && (table[2][2]=='O' || table[2][2]=='X')) && nope==0)
        {
            table[2][0]='O';
            nope=1;
            ++moves;
        }
///////controllo prima colonna
        if((((table[0][0] == table[1][0]) && table[2][0]==0) && (table[0][0]=='O' || table[0][0]=='X') && (table[1][0]=='O' || table[1][0]=='X')) && nope==0)
        {
            table[2][0]='O';
            nope=1;
            ++moves;
        }
        else if((((table[1][0] == table[2][0]) && table[0][0]==0) && (table[1][0]=='O' || table[1][0]=='X') && (table[2][0]=='O' || table[2][0]=='X')) && nope==0)
        {
            table[0][0]='O';
            nope=1;
            ++moves;
        }
///////controllo seconda colonna
        if((((table[0][1] == table[1][1]) && table[2][1]==0) && (table[0][1]=='O' || table[0][1]=='X') && (table[1][1]=='O' || table[1][1]=='X')) && nope==0)
        {
            table[2][1]='O';
            nope=1;
            ++moves;
        }
        else if((((table[1][1] == table[2][1]) && table[0][1]==0) && (table[1][1]=='O' || table[1][1]=='X') && (table[2][1]=='O' || table[2][1]=='X')) && nope==0)
        {
            table[0][1]='O';
            nope=1;
            ++moves;
        }
///////controllo terza colonna
        if((((table[0][2] == table[1][2]) && table[2][2]==0) && (table[0][2]=='O' || table[0][2]=='X') && (table[1][2]=='O' || table[1][2]=='X')) && nope==0)
        {
            table[2][2]='O';
            nope=1;
            ++moves;
        }
        else if((((table[1][2] == table[2][2]) && table[0][2]==0) && (table[1][2]=='O' || table[1][2]=='X') && (table[2][2]=='O' || table[2][2]=='X')) && nope==0)
        {
            table[0][2]='O';
            nope=1;
            ++moves;
        }
////////controllo diagonale da sx a dx
        if((((table[0][0] == table[1][1]) && table[2][2]==0) && (table[0][0]=='O' || table[0][0]=='X') && (table[1][1]=='O' || table[1][1]=='X')) && nope==0)
        {
            table[2][2]='O';
            nope=1;
            ++moves;
        }
        else if((((table[1][1] == table[2][2]) && table[0][0]==0) && (table[1][1]=='O' || table[1][1]=='X') && (table[2][2]=='O' || table[2][2]=='X')) && nope==0)
        {
            table[0][0]='O';
            nope=1;
            ++moves;
        }
////////controllo diagonale da dx a sx
        if((((table[0][2] == table[1][1]) && table[2][0]==0) && (table[0][2]=='O' || table[0][2]=='X') && (table[1][1]=='O' || table[1][1]=='X')) && nope==0)
        {
            table[2][0]='O';
            nope=1;
            ++moves;
        }
        else if((((table[2][0] == table[1][1]) && table[0][2]==0) && (table[2][0]=='O' || table[2][0]=='X') && (table[1][1]=='O' || table[1][1]=='X')) && nope==0)
        {
            table[0][2]='O';
            nope=1;
            ++moves;
        }
/////////mette a caso
        if(nope==0)
        {
            do
            {
                var=rand()%3;
                var2=rand()%3;

                if(table[var][var2]==0)
                {
                    table[var][var2]='O';
                    ++moves;
                    OK=1;
                }
            }
            while(OK==0);
        }
    }
//////è deficente
    else
    {
        do
        {
            var=rand()%3;
            var2=rand()%3;

            if(table[var][var2]==0)
            {
                table[var][var2]='O';
                ++moves;
                OK=1;
            }
        }
        while(OK==0);
    }
}

////////visualizzazione tabella
void displaysTable()
{
    system("PAUSE");
    system("CLS");
    std::cout << "\n\n" << std::endl;
    std::cout << "  A B C" << std::endl;
    std::cout << "1 " << table[0][0] << "|" << table[0][1] << "|" << table[0][2] << std::endl;
    std::cout << "  -----" << std::endl;
    std::cout << "2 " << table[1][0] << "|" << table[1][1] << "|" << table[1][2] << std::endl;
    std::cout << "  -----" << std::endl;
    std::cout << "3 " << table[2][0] << "|" << table[2][1] << "|" << table[2][2] << std::endl;
    std::cout << "\n\n" << std::endl;
}
