/*Напиши функција pecatiListaNanazad која рекурзивно ги печати елементите од листа наназад. Елементите на листата се состојат од едно целоборјно поле
 * broj и еден карактер кој се вика karakter.*/
#include <stdio.h>
#include <stdlib.h>

struct listNode {
    int broj;
    char karakter;
    struct listNode *next;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void insert(ListNodePtr *sPtr, int broj, char karakter);
void printList(ListNodePtr currentPtr);
void printListInReverseOrder(ListNodePtr currentPtr);

int main()
{
    ListNodePtr startPtr = NULL;
    int choice;
    int broj;
    char karakter;

    printf(" Vnesi izbor:\n1 - Vnesuvanje element vo lista.\n2 - Pechatenje na lista vo obraten redosled.\n3 - Kraj.\n" );
    scanf("%d", &choice);

    while (choice != 3) {
        switch (choice) {
        case 1:
            printf("Vnesi broj: \n");
            scanf("%d", &broj);
            printf("Vnesi karakter: \n");
            scanf(" %c", &karakter);
            insert(&startPtr, broj, karakter);
            printList(startPtr);
            break;
        case 2:
            printListInReverseOrder(startPtr);
            printf("\n");
            break;
        default:
            printf("Nevaliden izbor.\n");
            printf(" Vnesi izbor:\n1 - Vnesuvanje element vo lista.\n2 - Pechatenje na lista vo obraten redosled.\n3 - Kraj.\n" );
            break;
        }
        printf(" Vnesi izbor:\n1 - Vnesuvanje element vo lista.\n2 - Pechatenje na lista vo obraten redosled.\n3 - Kraj.\n" );
        scanf("%d", &choice);
    }

    return 0;
}

void insert(ListNodePtr *sPtr, int broj, char karakter)
{
    ListNodePtr newPtr;
    ListNodePtr previousPtr;
    ListNodePtr currentPtr;

    newPtr = malloc(sizeof(ListNode));

    if (newPtr != NULL) {
        newPtr->broj = broj;
        newPtr->karakter = karakter;
        newPtr->next = NULL;

        previousPtr = NULL;
        currentPtr = *sPtr;

        while (currentPtr != NULL) {
            previousPtr = currentPtr;
            currentPtr = currentPtr->next;
        }

        if (previousPtr == NULL) {
            newPtr->next = *sPtr;
            *sPtr = newPtr;
        }
        else {
            previousPtr->next = newPtr;
            newPtr->next = currentPtr;
        }
        }
    else {
        printf("Nema dovolno memorija.\n");
    }
}

void printList(ListNodePtr currentPtr)
{
    if (currentPtr == NULL) {
        printf("Listata e prazna.\n");
    }
    else {
        while (currentPtr != NULL) {
            printf("%d%c --> ", currentPtr->broj, currentPtr->karakter);
            currentPtr = currentPtr->next;
        }

        printf("NULL\n\n");
    }
}

void printListInReverseOrder(ListNodePtr currentPtr)
{
    if (currentPtr != NULL) {
        printListInReverseOrder(currentPtr->next);
        printf("%d%c --> ", currentPtr->broj, currentPtr->karakter);
    }
}
