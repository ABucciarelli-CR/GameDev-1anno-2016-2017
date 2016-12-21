#include <iostream>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
/************************************************************************************************************************************
* ho interpretato lo Shell upgrade (incremento di bravery raddoppiati) come un raddoppiamento del punteggio che viene dato al carro *
************************************************************************************************************************************/

using namespace std;


/////creazione squadra Tiger
class tigerSquad
{

    int health;
    int fuel;
    int ammo;
    int life;
    int upg_engine;
    int upg_armor;
    int upg_shell;

    public:

        void showHealth();
        void showFuel();
        void showAmmo();
        void showEngine();
        void showArmor();
        void showShell();

        int getEngine(){return upg_engine;};
        int getArmor(){return upg_armor;};
        int getShell(){return upg_shell;};

        int getHealth(){return health;};
        int getFuel(){return fuel;};
        int getAmmo(){return ammo;};
        int getLife(){return life;};

        void setEngine(int t_Engine){upg_engine=t_Engine;};
        void setArmor(int t_Armor){upg_armor=t_Armor;};
        void setShell(int t_Shell){upg_shell=t_Shell;};

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
    upg_engine=0;
    upg_armor=0;
    upg_shell=0;
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

void tigerSquad::showEngine()
{
    if(tigerSquad::getEngine()==1)
    {
        cout << "E ";
    }
}

void tigerSquad::showArmor()
{
    if(tigerSquad::getArmor()==1)
    {
        cout << "A ";
    }
}

void tigerSquad::showShell()
{
    if(tigerSquad::getShell()==1)
    {
        cout << "S ";
    }
}

////missioni
////missione1
void tigerSquad::mission1(int x)
{
    int distance=x;
    int t_health=getHealth();
    int t_fuel=getFuel();
    int t_ammo=getAmmo();
    int t_engine=getEngine();
    int t_armor=getArmor();

////controllo con i vari upgrade
    if(t_armor==1)
    {
        t_health-=((distance*2)/2);
    }
    else
    {
        t_health-=(distance*2);
    }

    if(t_engine==1)
    {
        t_fuel-=((distance*8)/2);
    }
    else
    {
        t_fuel-=(distance*8);
    }

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
    int t_engine=getEngine();
    int t_armor=getArmor();

    ////controllo con i vari upgrade
    if(t_armor==1)
    {
        t_health-=((enemyPower*7)/2);
    }
    else
    {
        t_health-=(enemyPower*7);
    }

    if(t_engine==1)
    {
        t_fuel-=((enemyPower*3)/2);
    }
    else
    {
        t_fuel-=(enemyPower*3);
    }

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
    int t_engine=getEngine();
    int t_armor=getArmor();
    int t_shell=getShell();

    t_health=100;
    t_fuel=100;
    t_ammo=100;
    t_life=1;
    t_engine=0;
    t_armor=0;
    t_shell=0;

    setHealth(t_health);
    setFuel(t_fuel);
    setAmmo(t_ammo);
    setLife(t_life);
    setEngine(t_engine);
    setArmor(t_armor);
    setShell(t_shell);
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
    int x;
    int t_atLeast;
    int eng_nix=0;
    int arm_nix=0;
    int she_nix=0;
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
/////missione 1
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
                               if(Tiger[i].getShell()==1)
                               {
                                   Valore+=2;
                               }
                               else
                               {
                                   Valore++;
                               }
                           }
                           else
                           {
                               cout << "Carro " << i << "perso" << endl;
                           }
                        }
                    }
                    wrongmission=1;
                }
//////missione 2
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
                               if(Tiger[i].getShell()==1)
                               {
                                   Valore+=4;
                               }
                               else
                               {
                                   Valore+=2;
                               }
                           }
                           else
                           {
                               cout << "Carro " << i << "perso" << endl;
                           }
                        }
                    }
                    wrongmission=1;
                }
///////missione 3
                else if(mission==3)
                {
                    for(i=0;i<MAX;i++)
                    {
                        rand_num=rand()%2+3;
                        Tiger[i].mission3(rand_num);
                        if(Tiger[i].getLife()==1)
                        {
                            Valore--;
                        }
                    }
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
//////upgrade se almeno 1 è vivo
            for(t_atLeast=0, i=0;i<MAX;i++)
            {
                if(Tiger[i].getLife()==1)
                {
                    t_atLeast=1;
                }
            }
            if(t_atLeast==1)
            {

                ////////controllo se tutti i carri sono stati potenziati
///////controllo Engine
                    for(t_atLeast=0, i=0;i<MAX;i++)
                    {
                        if(Tiger[i].getEngine()==0)
                        {
                            t_atLeast=1;
                        }
                    }
                    if(t_atLeast==0)
                    {
                        eng_nix=1;
                    }

    ///////controllo Armor
                    for(t_atLeast=0, i=0;i<MAX;i++)
                    {
                        if(Tiger[i].getArmor()==0)
                        {
                            t_atLeast=1;
                        }
                    }
                    if(t_atLeast==0)
                    {
                        arm_nix=1;
                    }

    //////controllo Shell
                    for(t_atLeast=0, i=0;i<MAX;i++)
                    {
                        if(Tiger[i].getShell()==0)
                        {
                            t_atLeast=1;
                        }
                    }
                    if(t_atLeast==0)
                    {
                        she_nix=1;
                    }
                if(eng_nix==0 || arm_nix==0 || she_nix==0)
                {
                    if(eng_nix==0)
                    {
                        cout << "4) Engine Upgrade (Costo 10)" << endl;
                    }
                    if(arm_nix==0)
                    {
                        cout << "5) Armor Upgrade (Costo 20)" << endl;
                    }
                    if(she_nix==0)
                    {
                        cout << "6) Shell Upgrade (Costo 30)" << endl;
                    }

                    cout << "Allora, hai a disposizione sti Upgrade" << endl;
////////inizio scelta e altra serie di controlli...
                    cout << "Hai a disposizione " << Valore << " soldi" << endl;
                    cout << "Vuoi fare acquisti? (1 yes/ 0 no)" << endl;
                    do
                    {
                        cin >> x;
                        if(x!=0 && x!=1)
                        {
                            cout << "Valore errato, reinserire" << endl;
                        }
                    }
                    while(x!=0 && x!=1);
                    if(x==1 && Valore<10)
                    {
                        cout << "Un tunn'hai sordi!" << endl;
                    }
                    else if(eng_nix==1 && x==1 && Valore<20)
                    {
                        cout << "Un tunn'hai sordi!" << endl;
                    }
                    else if(eng_nix==1 && arm_nix==1 && x==1 && Valore<30)
                    {
                        cout << "Un tunn'hai sordi!" << endl;
                    }
                    else if(x==1)
                    {
                        cout << "Quale upgrade vuoi fare?" << endl;
                        do
                        {
                            cin >> x;
///////controllo valore
                            if(x!=4 && x!=5 && x!=6)
                            {
                                cout << "Valore errato, reinserire" << endl;
                            }
//////controllo soldi
                            if(x==5 && Valore<20)
                            {
                                cout << "Un tunn'hai sordi!" << endl;
                                x=0;
                            }
                            if(x==6 && Valore<30)
                            {
                                cout << "Un tunn'hai sordi!" << endl;
                                x=0;
                            }
//////controllo termine scorte
                            if(eng_nix==1 && x==4)
                            {
                                cout << "Potenziamenti del tipo 4 terminati, reinserire" << endl;
                                x=0;
                            }
                            if(arm_nix==1 && x==5)
                            {
                                cout << "Potenziamenti del tipo 5 terminati, reinserire" << endl;
                                x=0;
                            }
                            if(she_nix==1 && x==6)
                            {
                                cout << "Potenziamenti del tipo 6 terminati, reinserire" << endl;
                                x=0;
                            }
                        }
                        while(x!=4 && x!=5 && x!=6);
                        for(i=0;i<MAX;i++)
                        {
                            if(Tiger[i].getLife()==1)
                            {
                                if(x==4 && Tiger[i].getEngine()==0)
                                {
                                    Tiger[i].setEngine(1);
                                    Valore-=10;
                                    i=MAX+1;
                                }
                                if(x==5 && Tiger[i].getArmor()==0)
                                {
                                    Tiger[i].setArmor(1);
                                    Valore-=20;
                                    i=MAX+1;
                                }
                                if(x==6 && Tiger[i].getShell()==0)
                                {
                                    Tiger[i].setShell(1);
                                    Valore-=30;
                                    i=MAX+1;
                                }
                            }
                        }
                        cout << "Ecco i tuoi carri potenziati" << endl;
                        for(i=0;i<MAX;i++)
                        {
                            if(Tiger[i].getLife()==1)
                            {
                                cout << "Carro " << i << ": ";
                                Tiger[i].showEngine();
                                Tiger[i].showArmor();
                                Tiger[i].showShell();
                                cout << "" <<endl;
                            }
                        }

                    }
                }
                else
                {
                    cout << "Non ci sono piu' aggiornamenti disponobili" <<endl;
                }

            }
/////controllo fine gioco + fine gioco
            else
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
