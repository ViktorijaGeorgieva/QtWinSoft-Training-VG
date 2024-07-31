#ifndef DROPKI_H
#define DROPKI_H

class Dropki{
public:
    Dropki(int = 0, int = 1);
    int getBroitel() const{
        return broitel;
    }
    int getImenitel() const{
        return imenitel;
    }
    void setVrednostiNaDropka(int, int);
    Dropki operator+(Dropki dropka);
    Dropki operator+(int broj);
    Dropki operator-(Dropki dropka);
    Dropki operator-(int broj);
    Dropki operator*(Dropki dropka);
    Dropki operator*(int broj);
    Dropki operator/(Dropki dropka);
    Dropki operator/(int broj);
    void pecatenje();
    float pecatenjeVoFormaNaRealenBroj();
private:
    int broitel;
    int imenitel;
};

#endif
