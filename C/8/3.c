/*Палиндроми се низи од букви што се читаат исто и оддесно на лево и одлево на десно. На пример зборот “radar” е палиндром. Да се напише програм
 * во кој внесуваме низа од карактери. Треба да имаме функција palindrom која враќа вредност 1 ако стрингот е палиндром или 0 инаку.*/
#include <stdio.h>

int palindrom(char str[], int size);

int main()
{
    int i, size = 0;
    char str[20];
    printf("Vnesi zbor:");
    scanf("%s", str);
    for(i = 0; str[i] != '\0'; i++){
        size++;
    }
    if(palindrom(str, size)){
        printf("Zborot %s e palindrom.", str);
    }else{
        printf("Zborot %s ne e palindrom.", str);
    }

    return 0;
}

int palindrom(char str[], int size){
    int i;

    for(i = 0; i < size / 2; i++){
        if(str[i] != str[size-i-1])
            return 0;
    }

    return 1;
}
