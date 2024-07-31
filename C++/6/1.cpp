/*Создади класа Stedac во која ќе користиш статичка податочна членка kamata која ќе ја чува вредноста на годишната камата за сите штедачи и статична
 * податочна членка brojStedaci кој во секој момент кажува колку штедачи има во банката. Останатите податочни членки се lice, bilans и kredit. Името,
 * презимето, адресата и телефонот на секој објeкт од класата Stedac  се сместени во приватна податочна членка lice која е од класaта Covek. */
#include <iostream>

using namespace std;

#include "Covek.h"
#include "Stedac.h"

int main()
{
    string ime, prezime, adresa, telefon;
    int bilans, kredit;

    cout<<"Broj na stedaci: "<<Stedac::getBrojStedaci()<<endl;
    Stedac *stedac1 = new Stedac("Ana", "Anevska", "Partizanski Odredi br. 16", "078458965", 350, 652);
    Stedac *stedac2 = new Stedac("Petko", "Petkovski", "Marsal Tito br. 17", "071356455", 255, 365);
    Stedac *stedac3 = new Stedac("Hristijan", "Hristovski", "Rugjer Boskovikj br. 25", "075666985", 456, 3987);
    stedac1->pecatenje();
    stedac2->pecatenje();
    stedac3->pecatenje();
    cout<<"Broj na stedaci: "<<Stedac::getBrojStedaci()<<endl;
    cout<<"Godisna kamata: "<<Stedac::getKamata()<<"%"<<endl;
    delete stedac1;
	stedac1 = 0;
    cout<<"Broj na stedaci: "<<Stedac::getBrojStedaci()<<endl;
	delete stedac2;
	stedac2 = 0;
	delete stedac3;
	stedac3 = 0;
	cout<<"Broj na stedaci: "<<Stedac::getBrojStedaci()<<endl;

    return 0;
}
