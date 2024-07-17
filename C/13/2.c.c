/*Напиши програма која внесува елементи со функцијата vnesi несортирано, на крајот на листата, ја користи функцијата sortOpagjanje која сортира
 * елементи во опаѓачки редослед, функцијата sortRastenje која ги сортира елемнтите во растечки редослед, brisi која брише елемент со дадена содржина.
 * Елементите на листата се целобројни елементи.*/
#include <stdio.h>
#include <stdlib.h>

struct listNode {
    int broj;
    struct listNode *next;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void vnesi(ListNodePtr *sPtr, int broj);
void pecati(ListNodePtr currentPtr);
void sortOpagjanje(ListNodePtr currentPtr);
void sortRastenje(ListNodePtr currentPtr);
void brisi(ListNodePtr *currentPtr, int number);

int main() {
    ListNodePtr startPtr = NULL;
    int choice, broj;
    printf("Vnesi izbor:\n1 - Vnesuvanje element vo lista.\n2 - Sortiranje na lista vo opagjacki redosled.\n3 - Sortiranje na lista vo rastecki redosled.\n4 - Brisenje na element vo lista.\n5 - Kraj.\n");
    scanf("%d", &choice);

    while (choice != 5) {
        switch (choice) {
        case 1:
            printf("Vnesi broj: \n");
            scanf("%d", &broj);
            vnesi(&startPtr, broj);
            pecati(startPtr);
            break;
        case 2:
            sortOpagjanje(startPtr);
            break;
        case 3:
            sortRastenje(startPtr);
            break;
        case 4:
            printf("Vnesi element: ");
            scanf("%d", &broj);
            brisi(&startPtr, broj);
            pecati(startPtr);
            break;
        default:
            printf("Nevaliden izbor.\n");
            printf("Vnesi izbor:\n1 - Vnesuvanje element vo lista.\n2 - Sortiranje na lista vo opagjacki redosled.\n3 - Sortiranje na lista vo rastecki redosled.\n4 - Brisenje na element vo lista.\n5 - Kraj.\n");
            break;
        }
        printf("Vnesi izbor:\n1 - Vnesuvanje element vo lista.\n2 - Sortiranje na lista vo opagjacki redosled.\n3 - Sortiranje na lista vo rastecki redosled.\n4 - Brisenje na element vo lista.\n5 - Kraj.\n");
        scanf("%d", &choice);
    }

    return 0;
}

void vnesi(ListNodePtr *sPtr, int broj) {
    ListNodePtr newPtr = malloc(sizeof(ListNode));
    if (newPtr != NULL) {
        newPtr->broj = broj;
        newPtr->next = NULL;

        ListNodePtr previousPtr = NULL;
        ListNodePtr currentPtr = *sPtr;

        while (currentPtr != NULL) {
            previousPtr = currentPtr;
            currentPtr = currentPtr->next;
        }

        if (previousPtr == NULL) {
            *sPtr = newPtr;
        } else {
            previousPtr->next = newPtr;
        }
    } else {
        printf("Nema dovolno memorija.\n");
    }
}

void pecati(ListNodePtr currentPtr) {
    if (currentPtr == NULL) {
        printf("Listata e prazna.\n");
    } else {
        while (currentPtr != NULL) {
            printf("%d --> ", currentPtr->broj);
            currentPtr = currentPtr->next;
        }
        printf("NULL\n");
    }
}

void sortOpagjanje(ListNodePtr currentPtr) {
    if (currentPtr == NULL) {
        printf("Listata e prazna.\n");
        return;
    }

    ListNodePtr newPtr;
    ListNodePtr strPtr = currentPtr;
    while (strPtr->next != NULL) {
        newPtr = strPtr->next;
        while (newPtr != NULL) {
            if (strPtr->broj < newPtr->broj) {
                int tempValue = strPtr->broj;
                strPtr->broj = newPtr->broj;
                newPtr->broj = tempValue;
            }
            newPtr = newPtr->next;
        }
        strPtr = strPtr->next;
    }
    pecati(currentPtr);
}

void sortRastenje(ListNodePtr currentPtr) {
    if (currentPtr == NULL) {
        printf("Listata e prazna.\n");
        return;
    }

    ListNodePtr newPtr;
    ListNodePtr strPtr = currentPtr;
    while (strPtr->next != NULL) {
        newPtr = strPtr->next;
        while (newPtr != NULL) {
            if (strPtr->broj > newPtr->broj) {
                int tempValue = strPtr->broj;
                strPtr->broj = newPtr->broj;
                newPtr->broj = tempValue;
            }
            newPtr = newPtr->next;
        }
        strPtr = strPtr->next;
    }
    pecati(currentPtr);
}

void brisi(ListNodePtr *sPtr, int number) {
    if (*sPtr == NULL) {
        printf("Listata e prazna.\n");
        return;
    }

    ListNodePtr previousPtr = NULL;
    ListNodePtr currentPtr = *sPtr;
    ListNodePtr tempPtr;

    if (number == (*sPtr)->broj) {
        tempPtr = *sPtr;
        *sPtr = (*sPtr)->next;
        free(tempPtr);
    } else {
        while (currentPtr != NULL && currentPtr->broj != number) {
            previousPtr = currentPtr;
            currentPtr = currentPtr->next;
        }

        if (currentPtr != NULL) {
            tempPtr = currentPtr;
            previousPtr->next = currentPtr->next;
            free(tempPtr);
        } else {
            printf("Elementot %d ne postoi vo listata.\n", number);
        }
    }
}
