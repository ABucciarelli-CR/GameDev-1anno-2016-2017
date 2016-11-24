#include <iostream>



int main()
{
    int leaderboard[10];
    int media;
    int i=0;

//////inserimento giuocatori
    i=0;
    std::cout << "Inserisci i punteggi de giocatori:" << std::endl;
    do
    {
        std::cout <<  "Giocatore " << i << std::endl;
        std::cin >> leaderboard[i];
        i++;
    }
    while(i<10);

/////stampa inversa giuocatori e punteggi
    std::cout << "Lista dei giocatori e punteggi inverso" << std::endl;
    i=9;
    do
    {
        std::cout <<  "Giocatore " << i << " :" << leaderboard[i] <<std::endl;
        i--;
    }
    while(i>=0);

///////media punteggi
    std::cout << "Media dei punteggi:" <<std::endl;
    media=0;
    for(i=0;i<10;i++)
    {
        media+=leaderboard[i];
    }

    media=media/10;
    std::cout << media <<std::endl;

    return 0;
}
