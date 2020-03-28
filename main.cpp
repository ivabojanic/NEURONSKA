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
     bool procesiraj()
    {
        if(stanje == START || stanje == OPTIMIZACIJA)
        {
            if(zeljeniProcenatUspesnosti > nm.izracunajUspeh())
                stanje = PROCESIRANJE;
            else
            {
                stanje = KRAJ;
                cout<<"Test je uspesno zavrsen"<<endl;
            }
            return true;
        }
        else
            return false;
    }
    bool potrebnoOptimizovati()
    {
        if(stanje == PROCESIRANJE)
        {
            stanje = OPTIMIZACIJA;
            return true;
        }
        else
            return false;
    }
    bool optimizuj(TipOptimizacije opt)
    {
        if(stanje == OPTIMIZACIJA){
            if(opt == DODAJ_SLOJ)
                nm.dodajSkriveniSloj();
            else
                nm.dodajNeuron();
            return true;
        }
        else
            return false;
    }
    double izracunajUspeh()const
    {
        return nm.izracunajUspeh();
    }
    TipMreze getTipMrezeT()
    {
        return nm.getTipMreze();
    }
    StanjeTesta getStanje()const
    {
        return stanje;
    }
};
void ispisiTest( Test &t)
{
    cout<<"Test:"<<endl;
    cout<<"-----------------------"<<endl;
    if(t.getStanje() == START)
        cout<<"Start"<<endl;
    else if (t.getStanje() == KRAJ)
        cout<<"Kraj"<<endl;
    else if (t.getStanje() == PROCESIRANJE)
        cout<<"Procesiranje"<<endl;
    else
        cout<<"Optimizacija"<<endl;

    cout<<"-----------------------"<<endl;
    if(t.getTipMrezeT() == DUBOKA)
    {
        cout<<"DUBOKA"<<endl;
    }else
        cout<<"OBICNA"<<endl;
    cout<<"-----------------------"<<endl;
    cout<<t.izracunajUspeh()<<endl;

}
int meni()
{
    int op;
    cout<<"1. Procesiraj"<<endl;
    cout<<"2. Optimizovati"<<endl;
    cout<<"3. Optimizuj"<<endl;
    cout<<"4. Kraj"<<endl;
    cin>>op;
    return op;
}

int main()
{
    int opcija;
    Test T(0.90);
    bool prom;

    do
    {

    opcija = meni();

    switch(opcija)
    {
    case 1:
        prom = T.procesiraj();
        break;
    case 2:
        prom = T.potrebnoOptimizovati();
        break;
    case 3:
        if(T.getStanje() == OPTIMIZACIJA){
        cout<<"Tip optimizacije [1-dodaj sloj, 2-dodaj neuron]";
        char biraj;
        cin>>biraj;
        if(biraj == '1')
            prom = T.optimizuj(DODAJ_SLOJ);
        else
            prom = T.optimizuj(DODAJ_NEURON);
        break;
        }
    }
    if (opcija<1 || opcija>4)
        cout<<"Ne postoji opcija!"<<endl;
    else if(prom == true )
        ispisiTest(T);

    }while(opcija>=1 && opcija<=4);
    return 0;
}
