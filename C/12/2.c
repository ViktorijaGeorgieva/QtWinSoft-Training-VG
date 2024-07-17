/*Напиши програм кој го превртува редоследот на битовите на целобројна unsigned вредност. Програмот треба да вчита вредност од корисникот и да ја
 * повика функцијата prevtriBitovi за да се испечатат битовите во обратен редослед. Вредностите на битовите да се испечатат и пред и после
 * превртувањето.*/
#include <stdio.h>

unsigned int prevrtiBitovi(unsigned int broj);
void pecatiBitovi(unsigned int broj);

int main() {
    unsigned int broj;

    printf("Vnesi broj: \n");
    scanf("%u", &broj);

    printf("Pred prevrtuvanje: ");
    pecatiBitovi(broj);
    printf("\n");

    unsigned int prevrtenBroj = prevrtiBitovi(broj);

    printf("Posle prevrtuvanje: ");
    pecatiBitovi(prevrtenBroj);
    printf("\n");

    return 0;
}

unsigned int prevrtiBitovi(unsigned int broj) {
    int i, bitovi;
    unsigned int prevrtenBroj = 0;
    bitovi = sizeof(unsigned int) * 8;
    for (i = 0; i < bitovi; i++) {
        if (broj & (1 << i)) {
            prevrtenBroj |= 1 << ((bitovi - 1) - i);
        }
    }

    return prevrtenBroj;
}

void pecatiBitovi(unsigned int broj) {
    int i, bitovi;
    bitovi = sizeof(unsigned int) * 8;
    for (i = bitovi - 1; i >= 0; i--) {
        printf("%u", (broj >> i) & 1);
    }
}
