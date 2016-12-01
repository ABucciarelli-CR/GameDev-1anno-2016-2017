#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

void stampa(vector<string>& stiva);
void evento2(vector<string>& stiva);
void evento3(vector<string>& stiva);
void evento4(vector<string>& stiva);
void evento5(vector<string>& stiva);
void evento6(vector<string>& stiva);
void evento7(vector<string>& stiva);
void evento8(vector<string>& stiva);
void evento9(vector<string>& stiva);

int main()
{
//////evento1
    vector <string> stiva_mercantile;
////evento2
    evento2(stiva_mercantile);
    stampa(stiva_mercantile);
//////evento3
    evento3(stiva_mercantile);
    stampa(stiva_mercantile);
//////evento4
    evento4(stiva_mercantile);
    stampa(stiva_mercantile);
//////evento5
    evento5(stiva_mercantile);
    stampa(stiva_mercantile);
//////evento6
    evento6(stiva_mercantile);
    stampa(stiva_mercantile);
/////evento7
    evento7(stiva_mercantile);
    stampa(stiva_mercantile);
//////evento8
    evento8(stiva_mercantile);
    stampa(stiva_mercantile);
///////evento9
    evento9(stiva_mercantile);
    stampa(stiva_mercantile);

    return 0;
}
///////faccio la stampa
void stampa(vector<string>& stiva)
{
    int grand_stiva;

    grand_stiva=stiva.size();

    cout << "E'/Sono presente/i:" << endl;
    for(int i=0;i<grand_stiva;i++)
    {
        cout << stiva[i] << endl;
    }
}
/////faccio l'evento2
void evento2(vector<string>& stiva)
{
    stiva.push_back("vino");
    stiva.push_back("lana");
    stiva.push_back("avorio");
    stiva.push_back("legno");
}
//////faccio l'evento3
void evento3(vector<string>& stiva)
{
    stiva.pop_back();
}
/////faccio evento4
void evento4(vector<string>& stiva)
{
    stiva.push_back("Te'");
}
//////faccio evento5
void evento5(vector<string>& stiva)
{
    vector<string>::iterator iter;

    iter=find(stiva.begin(), stiva.end(), "lana");
    *iter="frumento";
}
///////faccio evento6
void evento6(vector<string>& stiva)
{
    stiva.erase(stiva.begin());
}
///////faccio evento7
void evento7(vector<string>& stiva)
{
    sort(stiva.begin(),stiva.end());
}
//////faccio evento8
void evento8(vector<string>& stiva)
{
    srand(time(NULL));
    random_shuffle(stiva.begin(),stiva.end());
}
//////faccio evento9
void evento9(vector<string>& stiva)
{
    stiva.clear();
    stiva.push_back("ORO");
}
