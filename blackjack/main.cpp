#include <iostream>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

/////classi
class card
{
public:
    enum Rank {ASSO=1, DUE, TRE, QUATTRO, CINQUE, SEI, SETTE, OTTO, NOVE, DIECI, GOBBO, DONNA, RE};
    enum Suit {DENARI, CUORI, FIORI, PICCHE};
    int _getValue()const;
    void flip();
    void printCard();

    card();

private:
    Rank _rank;
    Suit _suit;
    bool _isFaceUp;
};

class hand
{

public:
    hand();


protected:
    vector<card *> _cards;
};

class game
{

public:
    game();
};

class deck : public hand
{

public:
    deck();
};

class GenericPlayer : public hand
{

public:
    GenericPlayer();
};

class player : public GenericPlayer
{

public:
    player();
};

class house : public GenericPlayer
{

public:
    house();
};

/////costruttori
card::card()
{
    Rank _rank;
    Suit _suit;
    _isFaceUp = true;
}

hand::hand()
{

}

game::game()
{

}

deck::deck()
{

}

GenericPlayer::GenericPlayer()
{

}

player::player()
{

}

house::house()
{

}

void card::flip()
{
    _isFaceUp = !_isFaceUp;
}

void card::printCard()
{

}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
