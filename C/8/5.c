/*Да се напише програма која симулира селекциско сортирање. Селекциското сортирање го бара најмалиот елемент во низата и го заменува со
 * првиот елемент. Сега, на прво место сигурно ни се наоѓа најмалиот елемент во низата. Потоа, во остатокот од низата, од вториот до n-тиот
 * елемент, повторно го бараме новиот најмал елемент и му ја заменуваме вредноста со вториот елемент од низата итн. Ова сортирање има слични
 * процесирачки капацитети како сортирање со методот на меурче.
а) Да се напише итеративна верзија на функцијата selekcija која го врши селекциското сортирање.
б) Да се напише рекурзивна верзија на селекциското сортирање.
в) Да се одговори зошто процесирачките капацитети на ова сортирање се слични како оние со методот на меурче.
*/
#include <stdio.h>

void selekcija(int arr[], int size);
void selekcija_recursive(int arr[], int size, int start);

/*Процесирачките капацитети на ова сортирање се слични како оние со методот на меурче бидејќи имаат иста временска комплексност.*/
int main()
{
    int i, size;
    printf("Vnesi golemina na nizata:");
    scanf("%d", &size);
    int arr[size];
    for(i = 0; i < size; i++){
        printf("Vnesi element:");
        scanf("%d", &arr[i]);
    }
    selekcija(arr, size);
    selekcija_recursive(arr, size, 0);
    for(i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}

void selekcija(int arr[], int size){
    int i, j, tmp;
    for(i = 0; i < size - 1; i++){
        int min = i;
        for(j = i + 1; j < size; j++){
            if(arr[j] < arr[min])
                min = j;
        }
        tmp = arr[i];
        arr[i] = arr[min];
        arr[min] = tmp;
    }
}

void selekcija_recursive(int arr[], int size, int start){
    int i, tmp;
    if (start >= size - 1)
        return;
    int min = start;
    for (i = start + 1; i < size; i++) {
        if (arr[i] < arr[min]) {
            min = i;
        }
    }
    tmp = arr[start];
    arr[start] = arr[min];
    arr[min] = tmp;

    selekcija_recursive(arr, size, start + 1);
}
