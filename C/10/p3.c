/*Да се направи програма во која ќе се сместат оцени на студенти по предмети (дводимензионална низа во која во редици се студентите,
 * а во колони се нивните оцени по 5 предмети). Програмата треба да го нуди следниот кориснички посредник:
Vnesi izbor:
0 Ispechati ja nizata so oceni
1 Najdi ja maksimalnat aocena
2 Najdi ja minimalnata ocena
3 Ispecati ja prosechnata ocena za sekoj student
4 Kraj
Програмата да се реши со користење на покажувачи до функциите max, min, pecatiNiza, рrosek. Покажувачите кон четирите функции да се сместат во низата
obrabotiOceni, а како индекс за повикување на секоја од функкциите да се користи изборот од корисничкото мени.
Забелешка: Една рестрикција при користење на покажувачи кон функции е што сите функции мора да се од ист тип. Покажувачите мора да се со иста
повратна вредност и да примаат аргументи од ист тип. Наједноставно би било кога ниту една од функциите нема да враќа вредност, но ќе печати
вредности, а како аргумент би се предавале оцени за еден студент.
*/
#include <stdio.h>

void max(int oceni[5][5]);
void min(int oceni[5][5]);
void pecatiNiza(int oceni[5][5]);
void prosek(int oceni[5][5]);

int main()
{
    int izbor;
    int oceni[5][5] = {{10, 10, 10, 10, 10}, {10, 9, 9, 7, 8}, {6, 6, 8, 9, 7}, {7, 7, 9, 8, 9}, {6, 8, 8, 8, 7}};
    void (*obrabotiOceni[4])(int [5][5])={pecatiNiza, max, min, prosek};
    printf("Vnesi izbor:\n 0 Ispechati ja nizata so oceni\n 1 Najdi ja maksimalnata ocena\n 2 Najdi ja minimalnata ocena\n 3 Ispecati ja prosechnata ocena za sekoj student\n 4 Kraj\n");
    scanf("%d", &izbor);
    while(izbor >= 0 && izbor < 4)
    {
        (*obrabotiOceni[izbor])(oceni);
        printf("Vnesi izbor:\n 0 Ispechati ja nizata so oceni\n 1 Najdi ja maksimalnata ocena\n 2 Najdi ja minimalnata ocena\n 3 Ispecati ja prosechnata ocena za sekoj student\n 4 Kraj\n");
        scanf("%d", &izbor);
    }
    return 0;
}

void max(int oceni[5][5]){
    int i, brojNaIndeks, maxOcenka=6;
    printf("Vnesi broj na indeks:\n");
    scanf("%d", &brojNaIndeks);
    for(i = 0; i < 5; i++)
    {
        if(oceni[brojNaIndeks][i]>maxOcenka)
        {
            maxOcenka=oceni[brojNaIndeks][i];
        }
    }
    printf("Najgolemata ocenka e %d\n", maxOcenka);
}

void min(int oceni[5][5]){
    int i, brojNaIndeks, minOcenka=10;
    printf("Vnesi broj na indeks:\n");
    scanf("%d", &brojNaIndeks);
    for(i = 0; i < 5; i++)
    {
        if(oceni[brojNaIndeks][i]<minOcenka)
        {
            minOcenka=oceni[brojNaIndeks][i];
        }
    }
    printf("Najmalata ocenka e %d\n", minOcenka);
}

void pecatiNiza(int oceni[5][5]){
    int i, brojNaIndeks;
    printf("Vnesi broj na indeks:\n");
    scanf("%d", &brojNaIndeks);
    for(i = 0; i < 5; i++)
    {
        printf("%d ", oceni[brojNaIndeks][i]);
    }
    printf("\n");
}

void prosek(int oceni[5][5]){
    int i,j;
    float prosek=0.0;
    for(i = 0; i < 5; i++)
    {
        prosek=0.0;
        for(j = 0; j < 5; j++)
        {
            prosek += oceni[i][j];
        }
        printf("Prosek na studentot so broj na indeks %d e %.2f\n",i, prosek / 5);
    }
}
