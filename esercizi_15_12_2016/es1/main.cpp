#include <iostream>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

using namespace std;


/////creazione squadra Tiger
class tigerSquad
{

    int health;
    int fuel;
    int ammo;
    int life;

    public:

        void showHealth();
        void showFuel();
        void showAmmo();

        int getHealth(){return health;};
        int getFuel(){return fuel;};
        int getAmmo(){return ammo;};
        int getLife(){return life;};

        void setHealth(int t_Health){health=t_Health;};
        void setFuel(int t_Fuel){fuel=t_Fuel;};
        void setAmmo(int t_Ammo){ammo=t_Ammo;};
        void setLife(int t_Life){life=t_Life;};

        void mission1(int x);
        void mission2(int x);
        void mission3(int x);

        void resetsquad();

        tigerSquad();
};

/////costruttore
tigerSquad::tigerSquad()
{
    health=100;
    fuel=100;
    ammo=100;
    life=1;
}

////visualizzazioni varie
void tigerSquad::showHealth()
{
    cout << "Salute: " << tigerSquad::health << endl;
}

void tigerSquad::showFuel()
{
    cout << "Carburante: " << tigerSquad::fuel << endl;
}

void tigerSquad::showAmmo()
{
    cout << "Munizioni: " << tigerSquad::ammo << endl;
}

////missioni
////missione1
void tigerSquad::mission1(int x)
{
    int distance=x;
    int t_health=getHealth();
    int t_fuel=getFuel();
    int t_ammo=getAmmo();

    t_health-=(distance*2);
    t_fuel-=(distance*8);
    t_ammo-=(distance*2);

    setHealth(t_health);
    setFuel(t_fuel);
    setAmmo(t_ammo);

    if(t_health<=0 || t_fuel<=0 || t_ammo<=0)
    {
        setLife(0);
    }

}

////missione2
void tigerSquad::mission2(int x)
{

    int enemyPower=x;

    int t_health=getHealth();
    int t_fuel=getFuel();
    int t_ammo=getAmmo();

    t_health-=(enemyPower*7);
    t_fuel-=(enemyPower*3);
    t_ammo-=(enemyPower*7);

    setHealth(t_health);
    setFuel(t_fuel);
    setAmmo(t_ammo);

    if(t_health<=0 || t_fuel<=0 || t_ammo<=0)
    {
        setLife(0);
    }
}

/////missione3
void tigerSquad::mission3(int x)
{

    int supplies=x;

    int t_health=getHealth();
    int t_fuel=getFuel();
    int t_ammo=getAmmo();

    t_health+=(supplies*5);
    if(t_health>100)
    {
        t_health=100;
    }
    t_fuel+=(supplies*5);
    if(t_fuel>100)
    {
        t_fuel=100;
    }
    t_ammo+=(supplies*5);
    if(t_ammo>100)
    {
        t_ammo=100;
    }

    setHealth(t_health);
    setFuel(t_fuel);
    setAmmo(t_ammo);
}

////reset della squadra
void tigerSquad::resetsquad()
{
    int t_health=getHealth();
    int t_fuel=getFuel();
    int t_ammo=getAmmo();
    int t_life=getLife();

    t_health=100;
    t_fuel=100;
    t_ammo=100;
    t_life=1;

    setHealth(t_health);
    setFuel(t_fuel);
    setAmmo(t_ammo);
    setLife(t_life);
}


int main()
{


    srand(time(NULL));
    int restart=0;
    int TheEnd=0;
    int mission=0;
    int wrongmission=0;
    int rand_num=0;
    int i;
    int Valore=0;

/////creo i 5 carretti
    tigerSquad Tiger[MAX];

    do
    {
        do
        {
            do
            {
///////scelta missione
                wrongmission=0;
                cout << "Scegli la missione:" << endl;
                cout << "Missione 1: Pattugliamento" << endl;
                cout << "Missione 2: Attacco a postazione nemica" << endl;
                cout << "Missione 3: Rifornimento e riparazione" << endl;
                cin >> mission;
                if(mission==1)
                {

                    for(i=0;i<MAX;i++)
                    {
                        rand_num=rand()%2+3;
                        if(Tiger[i].getLife()==1)
                        {
                           Tiger[i].mission1(rand_num);
                           if(Tiger[i].getLife()==1)
                           {
                               Valore++;
                           }
                           else
                           {
                               cout << "Carro " << i << "perso" << endl;
                           }
                        }
                    }
                    wrongmission=1;
                }
                else if(mission==2)
                {
                    for(i=0;i<MAX;i++)
                    {
                      if(Tiger[i].getLife()==1)
                        {
                           rand_num=rand()%2+3;
                           Tiger[i].mission2(rand_num);
                           if(Tiger[i].getLife()==1)
                           {
                               Valore+=2;
                           }
                           else
                           {
                               cout << "Carro " << i << "perso" << endl;
                           }
                        }
                    }
                    wrongmission=1;
                }
                else if(mission==3)
                {
                    for(i=0;i<MAX;i++)
                    {
                        rand_num=rand()%2+3;
                        Tiger[i].mission3(rand_num);
                    }
                    Valore-=5;
                    wrongmission=1;
                }
            }
            while(wrongmission==0);

/////visualizzazione informazioni dei carri
            i=0;
            do
            {
                if(Tiger[i].getLife()==1)
                {
                   cout << "Carro " << i << endl;
                    Tiger[i].showHealth();
                    Tiger[i].showFuel();
                    Tiger[i].showAmmo();
                    cout << "" << endl;
                }

                i++;
            }
            while (i<MAX);
/////controllo fine gioco
            if(Tiger[0].getLife()==0 && Tiger[1].getLife()==0 && Tiger[2].getLife()==0 && Tiger[3].getLife()==0 && Tiger[4].getLife()==0)
            {
                TheEnd=1;
            }
            if(TheEnd==1)
            {
                cout << "Complimenti, hai fatto " << Valore << " punti" << endl;
                cout << "Vuoi riprovare? (1 yes/0 no)" << endl;
                do
                {
                    cin >> i;
                    if(i!=0 && i!=1)
                    {
                        cout << "Valore non valido, reinserire" << endl;
                    }
                }
                while(i!=0 && i!=1);
                if(i==1)
                {
                   restart=1;
                   TheEnd=0;
                }
                else
                {
                    restart=0;
                }
            }
        }
        while(TheEnd==0);
/////risettaggio valori iniziali(lo so, è parecchio macchinoso questo passaggio...)
        if(restart==1)
        {
            for(i=0;i<MAX;i++)
            {
                Tiger[i].resetsquad();
            }

            Valore=0;
        }

    }
    while(restart==1);

    return 0;
}
