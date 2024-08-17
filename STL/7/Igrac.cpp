#include <iostream>

using namespace std;

#include "Igrac.h"

Igrac::Igrac()
{
    counter = 0;
}

void Igrac::vnesiKarta(Karta karta)
{
    karti[counter++] = karta;
}

int Igrac::suma(int tipIgra)
{
    int sum = 0;
    if(tipIgra == 1)
    {
        for(int i = 0; i < counter; i++)
            sum += karti[i].getBroj();
    }
    else
    {
        for(int i = 0; i < counter; i++)
        {
            if(karti[i].getBoja() == "Srce")
                sum += (karti[i].getBroj() * 2);
            else
                sum += karti[i].getBroj();
        }
    }
    return sum;
}

void Igrac::pecatenje() const
{
    for(int i = 0; i < counter; i++)
    {
        cout<<karti[i]<<endl;
    }
}
