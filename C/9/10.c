/*Да се најдат сите растечки поднизи во низата броеви [ai]n. (Растечка подни¬за е онаа во која секој елемент е поголем од претходниот.)*/
#include <stdio.h>

void rastechkiPodnizi(int broevi[], int n);

int main()
{
    int i, n;
    printf("Vnesi golemina na nizata:");
    scanf("%d", &n);
    int broevi[n];
    for(i = 0; i < n; i++){
        printf("Vnesete broj:");
        scanf("%d", &broevi[i]);
    }
    rastechkiPodnizi(broevi, n);
    return 0;
}

void rastechkiPodnizi(int broevi[], int n){
    int i, br = 0;
    printf("Rastechki podnizi se:\n");
    for(i = 1; i < n; i++){
        if(broevi[i] > broevi[i - 1]){
            br++;
            if(br > 0)
                printf("%d ", broevi[i - 1]);
        }
        else{
            if(br > 0)
                printf("%d\n", broevi[i - 1]);
            br = 0;
        }
    }
    if(br > 0)
        printf("%d ", broevi[n - 1]);
}
