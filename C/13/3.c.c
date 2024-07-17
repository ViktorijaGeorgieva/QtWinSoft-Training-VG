/*Напиши програм кој внесува линија текст и користи стек за да се испечати текстот во обратен редослед. Текстот да содржи и празни места.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stackNode {
    char data;
    struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void push(StackNodePtr *topPtr, char data);
char pop(StackNodePtr *topPtr);

int main()
{
    StackNodePtr stackPtr = NULL;
    char tekst[100];
    int i;

    printf("Vnesi tekst: ");
    fgets(tekst, sizeof(tekst), stdin);
    size_t length = strlen(tekst);
    for(i = 0; i < strlen(tekst); ++i) {
        push(&stackPtr, tekst[i]);
    }
    while (stackPtr != NULL) {
        printf("%c", pop(&stackPtr));
    }
    printf("\n");

    return 0;
}

void push(StackNodePtr *topPtr, char data)
{
    StackNodePtr newPtr;

    newPtr = malloc(sizeof(StackNode));
    if (newPtr != NULL) {
        newPtr->data = data;
        newPtr->nextPtr = *topPtr;
        *topPtr = newPtr;
    } else {
        printf("Nema dovolno memorija\n");
    }
}

char pop(StackNodePtr *topPtr)
{
    StackNodePtr tempPtr;
    char popValue;

    tempPtr = *topPtr;
    popValue = (*topPtr)->data;
    *topPtr = (*topPtr)->nextPtr;
    free(tempPtr);

    return popValue;
}
