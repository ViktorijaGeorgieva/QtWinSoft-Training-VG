/*Да се најдат сите пилести поднизи во низата броеви [ai]n. (Пилеста подни¬за е онаа во која претходниот и следниот елемент на секој елемент се
 * помали (поголеми) од него.)*/
#include <stdio.h>

void pilestiPodnizi(int broevi[], int n);

int main()
{
    int i, n;
    printf("Vnesi golemina na nizata:");
    scanf("%d", &n);
    int broevi[n];
    for(i = 0; i < n; i++){
        printf("Vnesi element:");
        scanf("%d", &broevi[i]);
    }
    pilestiPodnizi(broevi, n);
    return 0;
}

void pilestiPodnizi(int broevi[], int n){
    int i, proverka = 0;

    printf("Pilesti podnizi se: \n");

    for(i = 1; i < n - 1; ++i)
    {
        if((broevi[i - 1] > broevi[i] && broevi[i + 1] > broevi[i]) || (broevi[i - 1] < broevi[i] && broevi[i + 1] < broevi[i]))
        {
            proverka = 1;
            printf("%d ", broevi[i - 1]);
        }
        else
        {
            if(proverka == 1)
            {
                printf("%d %d \n", broevi[i - 1], broevi[i]);
                proverka = 0;
            }
        }
    }
    if(proverka == 1) printf("%d %d ", broevi[n - 2], broevi[n - 1]);
}
