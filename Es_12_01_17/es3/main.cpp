#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
char Board[8][8]=
{
    {' ','b',' ','b',' ','b',' ','b'},
    {'b',' ','b',' ','b',' ','b',' '},
    {' ','b',' ','b',' ','b',' ','b'},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {'w',' ','w',' ','w',' ','w',' '},
    {' ','w',' ','w',' ','w',' ','w'},
    {'w',' ','w',' ','w',' ','w',' '},
};

void boardStamp()
{
    int i;
    int j;
    cout << " ";
    for(i=0;i<8;i++)
    {
        cout << "   " << i;
    }
    cout << "" << endl;
    cout << "  -";
    for(j=0;j<8;j++)
    {
        cout << "----";
    }
    cout << "" << endl;
    for(i=0;i<8;i++)
    {
        cout << i << " | ";
        for(j=0;j<8;j++)
        {
            cout << Board[i][j] << " | ";
        }
        cout << "" << endl;
        cout << "  ";
        for(j=0;j<8;j++)
        {
            cout << "----";
        }
        cout << "-" << endl;
    }
}

int main()
{

    int i;
    int j;
    int x;
    int y;
    int ok;

    char moved;

    void boardStamp();

    boardStamp();
////player 1
    cout << "Giocatore 1(w), scegli un pezzo" << endl;
/////scelta pezzo
    for(ok=0;ok==0;)
    {
        cout << "Riga:" << endl;
        do
        {
            cin >> x;
            if(x<0 || x>7)
            {
                cout << "Valore non valido, reinserire" << endl;
            }
        }
        while(x<0 || x>7);
        cout << "Colonna:" << endl;
        do
        {
            cin >> y;
            if(y<0 || y>7)
            {
                cout << "Valore non valido, reinserire" << endl;
            }
        }
        while(y<0 || y>7);

////controllo validità del pezzo scelto
        if(Board[x][y]!='w' && Board[x][y]!='W')
        {
            cout << "Area non valida, reinserire" << endl;
        }
        else if((Board[x-1][y+1]!=' ' || Board[x+1][y+1]!=' ') && Board[x][y]=='w')
        {
            if(Board[x-2][y+2]!=' ' && Board[x+2][y+2]!=' ')
            {
                cout << "Area non valida, reinserire" << endl;
            }
            else if (Board[x-1][y+1]!='w' && Board[x-1][y+1]!='W' && Board[x+1][y+1]!='w' && Board[x+1][y+1]!='W')
            {
                ok=1;
            }
            else
            {
                cout << "Area non valida, reinserire" << endl;
            }
        }
        else if((Board[x+1][y-1]==' ' || Board[x-1][y-1]==' ') && Board[x][y]=='w')
        {
            ok=1;
        }
        else if((Board[x+1][y-1]!=' ' || Board[x-1][y-1]!=' ' || Board[x+1][y+1]!=' ' || Board[x-1][y+1]!=' ') && Board[x][y]=='W')
        {
            if(Board[x-2][y+2]!=' ' && Board[x+2][y+2]!=' ' && Board[x-2][y-2]!=' ' && Board[x+2][y-2]!=' ' )
            {
                cout << "Area non valida, reinserire" << endl;
            }
            else if (Board[x-1][y+1]!='w' && Board[x-1][y+1]!='W' && Board[x+1][y+1]!='w' && Board[x+1][y+1]!='W')
            {
                ok=1;
            }
            else
            {
                cout << "Area non valida, reinserire" << endl;
            }
        }
        else if((Board[x-1][y+1]==' ' || Board[x+1][y+1]==' ' || Board[x-1][y-1]==' ' || Board[x+1][y-1]==' ') && Board[x][y]=='W')
        {
            ok=1;
        }
    }
/////movimento del pezzo
    cout << "Dove vuoi muovere?" << endl;
    if(Board[x][y]=='w' || Board[x][y]=='W')
    {
        if(Board[x-1][y-1]==' ' || (Board[x-2][y-2]==' ' && (Board[x-1][y-1]=='b' || Board[x-1][y-1]=='B')))
        {
            cout << "Sinistra(S)" << endl;
        }
        if(Board[x-1][y+1]==' ' || (Board[x-2][y+2]==' ' && (Board[x-1][y+1]=='b' || Board[x-1][y+1]=='B')))//fatta
        {
            cout << "Destra(D)" << endl;
        }
        if(Board[x][y]=='W')
        {
            if(Board[x-1][y+1]==' ' || Board[x-2][y+2]==' ')
            {
                cout << "Basso a Destra(A)" << endl;
            }
            if(Board[x-1][y+1]==' ' || Board[x-2][y+2]==' ')
            {
                cout << "Basso a Sinistra(B)" << endl;
            }
        }
/////inserimento mossa
        do
        {
            cin >> moved;
            if(moved=='S' || moved=='s'){moved='S';}
            if(moved=='D' || moved=='d'){moved='D';}
            if(moved=='A' || moved=='a'){moved='A';}
            if(moved=='B' || moved=='b'){moved='B';}

            if(moved!='S' && moved!='D' && moved!='B' && moved!='A')
            {
                cout << "Valore non valido, reinserire" << endl;
            }
            if(moved=='S' && (Board[x-1][y-1]!=' ' || (Board[x-1][y-1]!='w' || Board[x-1][y-1]!='W')))
            {
                cout << "Valore non valido, reinserire" << endl;
                moved=' ';
            }
            if(moved=='D' && (Board[x+1][y-1]!=' ' || (Board[x+1][y-1]!='w' || Board[x+1][y-1]!='W')))
            {
                cout << "Valore non valido, reinserire" << endl;
                moved=' ';
            }
            if(Board[x][y]=='W')
            {
                if(moved=='B' && (Board[x-1][y+1]!=' ' || (Board[x-2][y+2]==' ' && (Board[x-1][y+1]!='w' || Board[x-1][y+1]!='W'))))
                {
                    cout << "Valore non valido, reinserire" << endl;
                    moved=' ';
                }
                if(moved=='A' && (Board[x+1][y+1]!=' ' || (Board[x+2][y+2]==' ' && (Board[x+1][y+1]!='w' || Board[x+1][y+1]!='W'))))
                {
                    cout << "Valore non valido, reinserire" << endl;
                    moved=' ';
                }
            }
        }
        while(moved!='S' || moved!='D' || moved!='A' || moved!='B');
    }
//////movimento
    if(moved=='S')
    {
        if(Board[x-1][y-1]==' ')
        {
            if(Board[x][y]=='w')
            {
                Board[x-1][y-1]='w';
            }
            else
            {
                Board[x-1][y-1]='W';
            }

        }
        else
        {
            if(Board[x][y]=='w')
            {
                Board[x-2][y-2]='w';
            }
            else
            {
                Board[x-2][y-2]='W';
            }
            Board[x-1][y-1]=' ';
/////controllo se posso rimangiare
            for(ok=0, i=3;ok!=1;i++)
            {
///////verso sx
                if(Board[x-i][y-i]=='b' || (Board[x][y]=='W' && Board[x-i][y-i]=='B'))
                {
                    if(Board[x-i-1][y-i-1]==' ')
                    {
                        if(Board[x][y]=='w')
                        {
                            Board[x-i-1][y-i-1]='w';
                        }
                        else
                        {
                            Board[x-i-1][y-i-1]='W';
                        }
                        Board[x-i][y-i]=' ';
                        Board[x-i+1][y-i+1]=' ';
                    }
                }
/////verso dx
                else if(Board[x+i][y-i]=='b' || (Board[x][y]=='W' && Board[x+i][y-i]=='B'))
                {
                    if(Board[x+i-1][y-i-1]==' ')
                    {
                        if(Board[x][y]=='w')
                        {
                            Board[x+i-1][y-i-1]='w';
                        }
                        else
                        {
                            Board[x+i-1][y-i-1]='W';
                        }
                        Board[x+i][y-i]=' ';
                        Board[x+i+1][y-i+1]=' ';
                    }
                }
/////controllo anche in basso a sx e dx se regina
                if(Board[x][y]=='W')
                {
///////verso sx
                    if(Board[x-i][y+i]=='b' || (Board[x][y]=='W' && Board[x-i][y+i]=='B'))
                    {
                        if(Board[x-i-1][y+i-1]==' ')
                        {
                            if(Board[x][y]=='w')
                            {
                                Board[x-i-1][y+i-1]='w';
                            }
                            else
                            {
                                Board[x-i-1][y+i-1]='W';
                            }
                            Board[x-i][y+i]=' ';
                            Board[x-i+1][y+i+1]=' ';
                        }
                    }
/////verso dx
                    else if(Board[x+i][y+i]=='b' || (Board[x][y]=='W' && Board[x+i][y+i]=='B'))
                    {
                        if(Board[x+i-1][y+i-1]==' ')
                        {
                            if(Board[x][y]=='w')
                            {
                                Board[x+i-1][y+i-1]='w';
                            }
                            else
                            {
                                Board[x+i-1][y+i-1]='W';
                            }
                            Board[x+i][y+i]=' ';
                            Board[x+i+1][y+i+1]=' ';
                        }
                    }
                }
//////controllo di fine possibilità
                if((Board[x-i][y-i]!='b' && Board[x-i][y-i]!='B') && (Board[x+i][y-i]=='b' && Board[x+i][y-i]=='B'))
                {
                    if(Board[x][y]=='w')
                    {
                        ok=1;
                    }
                }
                else if(Board[x-i-1][y-i-1]!=' ' && Board[x+i+1][y-i-1]==' ')
                {
                    if(Board[x][y]=='w')
                    {
                        ok=1;
                    }
                }
                if(Board[x][y]=='W')
                {
                    if((Board[x-i][y+i]!='b' && Board[x-i][y+i]!='B') && (Board[x+i][y+i]=='b' && Board[x+i][y+i]=='B'))
                    {
                        ok=1;
                    }
                    else if(Board[x-i-1][y+i-1]!=' ' && Board[x+i+1][y+i-1]==' ')
                    {
                        ok=1;
                    }
                }
            }
        }
    }
    else if(moved=='D')
    {

    }
    else if(moved=='A')
    {

    }
    else if(moved=='B')
    {

    }
    boardStamp();

    return 0;
}
