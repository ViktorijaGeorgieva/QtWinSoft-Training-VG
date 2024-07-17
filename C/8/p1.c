/*Проект1:
Да се напише програма која за дадена низа од n (n<100) елементи, пресметува средна вредност, медијана, најфреквентна вредност во низата и дава
хистограм со бројот на појавувања на секоја од вредностите во низата. Сите пресметки и испишувањето на хистограмот треба да се направат во посебни
функции.
Под медијана се подразбира среден елемент на сортирана низа. Ако низата има парен број елементи, медијана е средната вредност од двата елемента кои
се на средината на сортираната низа.
*/
#include <stdio.h>

void srednaVrednost(int niza[], int n);
void medijana(int niza[], int n);
void najfrekventnaVrednost(int niza[], int n);
void histogram(int niza[], int pom[], int n);
void sortiraj(int niza[], int n);

int main()
{
    int i, n;
    printf("Vnesi n:");
    scanf("%d", &n);
    int niza[100];
    for(i = 0; i < n; i++){
        printf("Vnesi element:");
        scanf("%d", &niza[i]);
    }
    srednaVrednost(niza, n);
    medijana(niza, n);
    najfrekventnaVrednost(niza, n);
    return 0;
}

void srednaVrednost(int niza[], int n){
    int i, suma = 0;
    for(i = 0; i < n; i++){
        suma += niza[i];
    }
    printf("Sredna vrednost: %.2f\n", (float) (suma / n));
}
void medijana(int niza[], int n){
    sortiraj(niza, n);
    if(n % 2 == 0){
        printf("Medijana: %.2f\n", (float) (niza[n / 2 - 1] + niza[n / 2]) / 2);
    } else{
        printf("Medijana: %d\n", niza[n / 2]);
    }
}
void najfrekventnaVrednost(int niza[], int n){
    int i, j, tmp;
    int pom[100];
    for(i = 0; i < n; i++){
        tmp = 1;
        for(j = i + 1; j < n; j++){
            if(niza[i] == niza[j])
            {
                tmp++;
                pom[j] = 0;
            }
        }
        if(pom[i] != 0)
        {
            pom[i] = tmp;
        }
    }
    int max = 0, indeks = 0;
    for(i = 0; i < n; i++)
    {
        if(pom[i] > max)
        {
            max=pom[i];
            indeks=i;
        }
    }
    printf("Najfrekventen element: %d\n", niza[indeks]);
    histogram(niza, pom, n);
    return;
}
void histogram(int niza[], int pom[], int n){
    int i, j;
    for(i = 0; i < n; i++){
        if(pom[i] != 0){
            printf("%d ", niza[i]);
            for(j = 0; j < pom[i]; j++){
                printf("*");
            }
            printf("\n");
        }
    }
}
void sortiraj(int niza[], int n){
    int i, tmp;
    if(n > 0){
        for(i = 0; i < n - 1; i++){
            if(niza[i] > niza[i + 1]){
                tmp = niza[i + 1];
                niza[i + 1] = niza[i];
                niza[i] = tmp;
            }
        }
        sortiraj(niza, n - 1);
    } else{
        return;
    }
}
