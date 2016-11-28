#include <iostream>
#include <stdlib.h>
#include <string>

void exploration();
void defense();
void escort();

int ammo=50;
int fuel=100;
int supply=100;

int main()
{
    std::string choise;
    do
    {
////////////inizio gioco
        std::cout << "Hai a disposizione "<< ammo << " munizioni, " << fuel << " carburante, " << supply << " scorte."<< std::endl;
        std::cout << "Che missione vuoi fare?(Attenzione: e' case sensitive)" << std::endl;
        std::cout << "exploration: Explore a planet with your friends(-20 fuel, -20 supply)" << std::endl;
        std::cout << "defense: Defend your planet with a powerful weapon(-5 fuel, -5 supply, -20 ammo)" << std::endl;
        std::cout << "escort: Helps Berlusconi... *cof cof* a group of researchers(-10 fuel, -10 supply, -10 ammo)" << std::endl;
        std::cin >> choise;
//////////controllo scelta e invio alle varie operazioni inerenti ad essa
        if(choise!="exploration" && choise!="defense" && choise!="escort")
        {
            std::cout << "errore di inserimento, ritenta" << std::endl;
        }
        if(choise=="exploration")
        {
            exploration();
        }
        else if(choise=="defense")
        {
            defense();
        }
        else if(choise=="escort")
        {
            escort();
        }
        system("PAUSE");
        system("CLS");
    }
    while(ammo>0 && fuel>0 && supply>0);

////////stampa di ciò che è stato finito
    std::cout << "Hai finito:" << std::endl;
    if(ammo<=0)
    {
        std::cout << "munizioni=" << ammo << std::endl;
    }
    if(fuel<=0)
    {
        std::cout << "carburante=" << fuel << std::endl;
    }
    if(supply<=0)
    {
        std::cout << "scorte=" << supply<< std::endl;
    }

    return 0;
}

//////funzione di esplorazione
void exploration()
{
    if(fuel>=20 && supply>=20)
    {
        fuel-=20;
        supply-=20;
    }
    else
    {
        std::cout << "Mission not available" << std::endl;
    }
}

//////funzione di difesa della terra
void defense()
{
    if(fuel>=5 && supply>=5 && ammo>=20)
    {
        fuel-=5;
        supply-=5;
        ammo-=20;
    }
    else
    {
        std::cout << "Mission not available" << std::endl;
    }
}

////////funzione di Berlusconi.... di scorta ai ricercatori...
void escort()
{
    if(fuel>=10 && supply>=10 && ammo>=10)
    {
        fuel-=10;
        supply-=10;
        ammo-=10;
    }
    else
    {
        std::cout << "Mission not available" << std::endl;
    }
}
