#include <iostream>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 3
#define MaxHHeal 100
#define MaxHVol 100
#define MaxHAtk 10
#define MaxHIntim 10


using namespace std;

//////creazione classi
class creature
{
protected:
    int health;
    int volition;
    int attack;
    int intimidation;
    int live;

public:
///////visualizzazioni
    void showHealth(){ cout << health << " di vita, ";};
    void showVolition(){ cout << volition << " di volonta'" << endl;};
    void showAttack(){ cout << attack << " di attacco";};
    void showIntimdation(){ cout << intimidation << " di intimidazione";};

///////acquisizioni
    int getHealth(){return health;}
    int getVolition(){return volition;}
    int getAttack(){return attack;}
    int getIntimidation(){return intimidation;}
    int getLive(){return live;}

//////settaggi
    void setHealth(int c_health){health=c_health;}
    void setVolition(int c_volition){volition=c_volition;}
    void setLive(int c_live){live=c_live;};

/////costruttore
    creature();
};

////eroe
class Hero : public creature
{
    int bossChance;
    int Win;

public:
    int getBChance(){return bossChance;}
    int getWin(){return Win;}

    void setWin(int h_win){Win=h_win;}
    void setBChance(int h_bchance){bossChance=h_bchance;}

    void combatSpectre();
    void combatServant();
    void combatBoss();

    void hunt(int bsschance);
    void rest();

    ////costruttore
    Hero();
};

class heroes : public Hero
{};

/////boss
class Boss : public creature
{
public:
    ////costruttore
    Boss();
};

////servitore
class servant : public creature
{
public:
    /////costruttore
    servant();
};

/////spettro
class spectre : public creature
{
public:
    //////costruttore
    spectre();
};


/////costruttori
/////creatura
creature::creature()
{
    health=0;
    volition=0;
    attack=0;
    intimidation=0;
    live=1;
}

////eroe
Hero::Hero()
{
    health=MaxHHeal;
    volition=MaxHVol;
    attack=MaxHAtk;
    intimidation=MaxHIntim;
    bossChance=0;
    Win=0;
}

////boss
Boss::Boss()
{
    health=50;
    volition=50;
    attack=20;
    intimidation=20;
}

////servitore
servant::servant()
{
   health=12;
    volition=30;
    attack=12;
    intimidation=10;
}

////spettro
spectre::spectre()
{
    health=100;
    volition=12;
    attack=2;
    intimidation=20;
}

/////combattimenti
////servitore
void Hero::combatServant()
{
    int i;
    int x;
    int xtraDamage;
    int alldead;

    servant Serv[MAX];
    do
    {
        if(Hero::getLive()==1)
        {
///////stampe delle statistiche
            cout << "Hellsing ha:" << endl;
            Hero::showHealth();
            Hero::showVolition();
/////stampa dei nemici
////controllo nemici in vita
            for(x=0, i=0;i<MAX;i++)
            {
                if(Serv[i].getLive()==1)
                {
                    x++;
                }
            }
            cout << "Ci sono " << x << "servitori" << endl;
            for(i=0;i<MAX;i++)
            {
                if(Serv[i].getLive()==1)
                {
                    cout << "Il servitore " << i << " ha:" << endl;
                    Serv[i].showHealth();
                    Serv[i].showVolition();
                }
            }

///////turno dell'eroe
            cout << "Cosa vuoi fare?" << endl;
            cout << "1) Attaccare" << endl;
            cout << "2) Intimidire" << endl;
            do
            {
                cin >> x;
                if(x!=1 && x!=2)
                {
                    cout << "Valore non valido, reinserire" << endl;
                }
            }
            while(x!=1 && x!=2);
///////attacco
            xtraDamage=rand()%6;
            if(x==1)
            {
                for(i=0;i<MAX;i++)
                {
                    Serv[i].setHealth(Serv[i].getHealth()-(Hero::getAttack()+xtraDamage));
                    if(Serv[i].getHealth()<=0)
                    {
                        cout << "Il servitore numero " << i << " e' morto" << endl;
                        Serv[i].setLive(0);
                    }
                }
            }
//////intimidazione
            else
            {
                for(i=0;i<MAX;i++)
                {
                    Serv[i].setVolition(Serv[i].getVolition()-(Hero::getIntimidation()+xtraDamage));
                    if(Serv[i].getVolition()<=0)
                    {
                        cout << "Il servitore numero " << i << " e' fuggito" << endl;
                        Serv[i].setLive(0);
                    }
                }
            }
/////turno servitori
            for(i=0;i<MAX;i++)
            {
                if(Serv[i].getLive()==1)
                {
                    if(rand()%10<5)
                    {
/////////////////attacco
                        Hero::setHealth(Hero::getHealth()-(Serv[i].getAttack()+rand()%6));
                        if(Hero::getHealth()<=0)
                        {
                            cout << "Van Hellsing e' morto, il mondo sprofondera' nel caos, almeno fino al sequel" << endl;
                            Hero::setLive(0);
                        }
                    }
                    else
                    {
///////////intimidazione
                        Hero::setVolition(Hero::getVolition()-(Serv[i].getIntimidation()+rand()%6));
                        if(Hero::getVolition()<=0)
                        {
                            cout << "Van Hellsing e' fuggito, il mondo sprofondera' nel caos, almeno fino al sequel" << endl;
                            Hero::setLive(0);
                        }
                    }
                }
            }
        }
        for(alldead=1, i=0;i<MAX;i++)
        {
            if(Serv[i].getLive()==1)
            {
                alldead=0;
            }
        }
    }
    while(alldead==0 && Hero::getLive()==1);
}

/////spettro
void Hero::combatSpectre()
{
    int i;
    int x;
    int xtraDamage;
    int alldead;

    spectre Spectr[MAX];

    do
    {
        if(Hero::getLive()==1)
        {
                    ///////stampe delle statistiche
                    cout << "Hellsing ha:" << endl;
                    Hero::showHealth();
                    Hero::showVolition();
/////stampa dei nemici
////controllo nemici in vita
                    for(x=0, i=0;i<MAX;i++)
                    {
                        if(Spectr[i].getLive()==1)
                        {
                            x++;
                        }
                    }
                    cout << "Ci sono " << x << " spettri" << endl;
                    for(i=0;i<MAX;i++)
                    {
                        if(Spectr[i].getLive()==1)
                        {
                            cout << "Il servitore " << i << " ha:" << endl;
                            Spectr[i].showHealth();
                            Spectr[i].showVolition();
                        }
                    }

///////turno dell'eroe
                    cout << "ci sono " << MAX << " spettri, cosa fare?" << endl;
                    cout << "1) Attaccare" << endl;
                    cout << "2) Intimidire" << endl;
                    do
                    {
                        cin >> x;
                        if(x!=1 && x!=2)
                        {
                            cout << "Valore non valido, reinserire" << endl;
                        }
                    }
                    while(x!=1 && x!=2);
///////attacco
                    xtraDamage=rand()%6;
                    if(x==1)
                    {
                        for(i=0;i<MAX;i++)
                        {
                            Spectr[i].setHealth(Spectr[i].getHealth()-(Hero::getAttack()+xtraDamage));
                            if(Spectr[i].getHealth()<=0)
                            {
                                cout << "Il servitore numero " << i << " e' morto" << endl;
                                Spectr[i].setLive(0);
                            }
                        }
                    }
//////intimidazione
                    else
                    {
                        for(i=0;i<MAX;i++)
                        {
                            Spectr[i].setVolition(Spectr[i].getVolition()-(Hero::getIntimidation()+xtraDamage));
                            if(Spectr[i].getVolition()<=0)
                            {
                                cout << "Il servitore numero " << i << " e' fuggito" << endl;
                                Spectr[i].setLive(0);
                            }
                        }
                    }
/////turno spettri
                    for(i=0;i<MAX;i++)
                    {
                        if(Spectr[i].getLive()==1)
                        {
                            if(rand()%10<5)
                            {
/////////////////attacco
                                Hero::setHealth(Hero::getHealth()-(Spectr[i].getAttack()+rand()%6));
                                if(Hero::getHealth()<=0)
                                {
                                    cout << "Van Hellsing e' morto, il mondo sprofondera' in un profondo caos, almeno fino al sequel" << endl;
                                    Hero::setLive(0);
                                }
                            }
                            else
                            {
///////////intimidazione
                                Hero::setVolition(Hero::getVolition()-(Spectr[i].getIntimidation()+rand()%6));
                                if(Hero::getVolition()<=0)
                                {
                                    cout << "Van Hellsing e' fuggito, il mondo sprofondera' in un profondo caos, almeno fino al sequel" << endl;
                                    Hero::setLive(0);
                                }
                            }
                        }
                    }
                }
                for(alldead=1, i=0;i<MAX;i++)
                {
                    if(Spectr[i].getLive()==1)
                    {
                        alldead=0;
                    }
                }
            }
            while(alldead==0 && Hero::getLive()==1);
}

////boss
void Hero::combatBoss()
{
    int x;

    Boss bos;


/////scontro col boss

        cout << "Hai incontrato il CONTE DRACCULAHHHHH" << endl;
        do
        {
///////stampe delle statistiche
            cout << "Hellsing ha:" << endl;
            Hero::showHealth();
            Hero::showVolition();
//////stampa statistiche di Dracula
            cout << "Dracula ha:" << endl;
            bos.showHealth();
            bos.showVolition();

            cout << "Cosa vuoi fare?" << endl;
            cout << "1) Attaccare" << endl;
            cout << "2) Intimidire" << endl;
            do
            {
                cin >> x;
                if(x!=1 && x!=2)
                {
                    cout << "Valore non valido, reinserire" << endl;
                }
            }
            while(x!=1 && x!=2);
///////attacco
            if(x==1)
            {

                bos.setHealth(bos.getHealth()-(Hero::getAttack()+rand()%6));
                if(bos.getHealth()<=0)
                {
                    cout << "Dracula e' morto,  il mondo e' finalmente salvo dalla tirannia dei pipistrelli!" << endl;
                    bos.setLive(0);
                    Hero::setWin(1);
                }
            }
//////intimidazione
            else
            {
                bos.setVolition(bos.getVolition()-(Hero::getIntimidation()+rand()%6));
                if(bos.getVolition()<=0)
                {
                    cout << "Dracula e' fuggito, il mondo e' finalmente salvo dalla tirannia dei pipistrelli!" << endl;
                    bos.setLive(0);
                    Hero::setWin(1);
                }
            }
///////turno del boss

            if(rand()%10<5)
            {
///////////attacco
                Hero::setHealth(Hero::getHealth()-(bos.getAttack()+rand()%6));
                if(Hero::getHealth()<=0)
                {
                    cout << "Van Hellsing e' morto, il mondo sprofondera' nel caos, almeno fino al sequel" << endl;
                    Hero::setLive(0);
                }
            }
            else
            {
///////////intimidazione
                Hero::setVolition(Hero::getVolition()-(bos.getIntimidation()+rand()%6));
                if(Hero::getVolition()<=0)
                {
                    cout << "Van Hellsing e' fuggito, il mondo sprofondera' nel caos, almeno fino al sequel" << endl;
                    Hero::setLive(0);
                }
            }

        }
        while(Hero::getLive()==1 && bos.getLive()==1);
}

////caccia e riposo
void Hero::hunt(int bsschance)
{

    int serv_spectr;

    if(bsschance<=Hero::bossChance)
    {
        Hero::combatBoss();
    }
    else
    {
////scontro normale
        serv_spectr=rand()%100;
/////controllo se incontra spettro o servitore
        if(serv_spectr<50)
        {
            serv_spectr=0;
        }
        else
        {
            serv_spectr=1;
        }
/////scontro
        if(serv_spectr==0)
        {
/////scontro con servitore
            Hero::bossChance=Hero::bossChance+10;
            Hero::combatServant();
        }
        else
        {
////scontro con spettro
            Hero::bossChance=Hero::bossChance+10;
            Hero::combatSpectre();
        }
    }

}

void Hero::rest()
{
    int serv_spectr;
    int heal;

//////riposo/combattimento
    if(rand()%10<=7)
    {
/////riposo, cure fino al massimo della vita
        heal=rand()%5+5;
        Hero::setHealth(Hero::getHealth()+heal);
//////controllo se fullato la vita
        if(Hero::getHealth()>MaxHHeal)
        {
            Hero::setHealth(MaxHHeal);
        }
        Hero::setVolition(Hero::getVolition()+heal);
/////controllo se fullato la volontà
        if(Hero::getVolition()>MaxHVol)
        {
            Hero::setVolition(MaxHVol);
        }
    }
    else
    {
/////combattimento
        serv_spectr=rand()%100;
/////controllo se incontra spettro o servitore
        if(serv_spectr<50)
        {
            serv_spectr=0;
        }
        else
        {
            serv_spectr=1;
        }
/////scontro
        if(serv_spectr==0)
        {
/////scontro con servitore
            Hero::combatServant();
        }
        else
        {
////scontro con spettro
            Hero::combatSpectre();
        }
    }
}



int main()
{
    srand(time(NULL));

    Hero* pHero = new heroes();


    int x;
    int endGame=0;
    int bossChance=0;

    cout << "Salve, ora sei Van Helsing e darai la caccia al conte DRACCULAHHH" << endl;

    do
    {
        cout << "Cosa vuoi fare?" << endl;
        cout << "1)Prosegui la caccia" << endl;
        cout << "2)Riposare" << endl;
        do
        {
           cin >> x;
           if(x!=1 && x!=2)
           {
               cout << "Valore non valido, reinserire" << endl;
           }
        }
        while(x!=1 && x!=2);
        if(x==1)
        {
            bossChance=rand()%100;
            pHero->hunt(bossChance);
        }
        else
        {
            pHero->rest();
        }

        if(pHero->getLive()==0 || pHero->getWin()==1)
        {
            endGame=1;
        }

    }
    while(endGame==0);


    return 0;
}
