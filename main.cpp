#include <iostream>
#include <cmath>

using namespace std;

enum TipMreze {DUBOKA,OBICNA};

class NeuronskaMreza
{
private:
    int brSkrivenoihSlojeva;
    int brNeuronaPoSloju;
public:

    NeuronskaMreza(int br1, int br2)
    {
        if(br1>0)
            brSkrivenoihSlojeva = br1;
        else
            brSkrivenoihSlojeva = 0;

        if(br2>0)
            brNeuronaPoSloju = br2;
        else
            brNeuronaPoSloju = 0;
    }

    void dodajSkriveniSloj()
    {
        brSkrivenoihSlojeva += 1;
        cout<<brSkrivenoihSlojeva<<endl;
    }
    void dodajNeuron()
    {
        brNeuronaPoSloju += 1;
        cout<<brNeuronaPoSloju<<endl;
    }
    
    TipMreze getTipMreze()
    {
        if((brSkrivenoihSlojeva * brNeuronaPoSloju)+2 >= 1000)
            return DUBOKA;
        else
            return OBICNA;
    }
};

enum StanjeTesta {START,KRAJ,PROCESIRANJE,OPTIMIZACIJA};
enum TipOptimizacije {DODAJ_SLOJ,DODAJ_NEURON};

class Test
{
private:
    NeuronskaMreza nm;
    double zeljeniProcenatUspesnosti;
    int brOptimizacija;
    StanjeTesta stanje;
public:
    Test(double t) : nm (3,200)
    {
        if(t >= 0 && t <= 1)
            zeljeniProcenatUspesnosti = t;
        else
            zeljeniProcenatUspesnosti = 0.85;
        stanje = START;
        brOptimizacija = 0;
    }
    
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
