#ifndef DROPKI_H
#define DROPKI_H

class Dropki {
public:
    Dropki(int = 0, int = 1);
    int getBroitel(){
        return broitel;
    }
    int getImenitel(){
        return imenitel;
    }
    void setVrednostiNaDropka(int, int);
    void sobiranje(Dropki dropka);
    void odzemanje(Dropki dropka);
    void mnozenje(Dropki dropka);
    void delenje(Dropki dropka);
    void pecatenje();
    float pecatenjeVoFormaNaRealenBroj();
private:
    int broitel;
    int imenitel;
};

#endif
