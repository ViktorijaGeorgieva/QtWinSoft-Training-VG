/*Напиши програм кој врши бришење од дрво, така да структурата на дрвото не се губи. Секоја од користените функции да се објасни. (помош: користете
 * web решенија за binary tree delete)*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct treeNode {
    int data;
    struct treeNode *leftPtr;
    struct treeNode *rightPtr;
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

void insertNode(TreeNodePtr *treePtr, int value);
void inOrder(TreeNodePtr treePtr);
TreeNodePtr minNode(TreeNodePtr node);
TreeNodePtr deleteNode(TreeNodePtr root, int key);

int main()
{
    int i, item, deleteValue;
    TreeNodePtr rootPtr = NULL;

    srand(time(NULL));

    for (i = 1; i <= 10; i++) {
        item = rand() % 15;
        printf("%3d", item);
        insertNode(&rootPtr, item);
    }
    printf("\nPominuvanje vo inOrder:\n");
    inOrder(rootPtr);

    printf("\nVnesi element za brishenje:\n");
    scanf("%d", &deleteValue);
    rootPtr = deleteNode(rootPtr, deleteValue);

    printf(" Pominuvanje vo inOrder po brishenjeto na elementot %d:\n", deleteValue);
    inOrder(rootPtr);
    printf("\n");

    return 0;

}

//Se vmetnuva nov jazol vo drvoto
void insertNode(TreeNodePtr *treePtr, int value)
{
    if (*treePtr == NULL) {
        *treePtr = malloc(sizeof(TreeNode));

        if (*treePtr != NULL) {
            (*treePtr)->data = value;
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
        }
        else {
            printf("Nema dovolno memorija.\n", value);
        }

        }
    else {
        if (value < (*treePtr)->data) {
            insertNode(&((*treePtr)->leftPtr), value);
        }

        if (value > (*treePtr)->data) {
            insertNode(&((*treePtr)->rightPtr), value);
        }
    }
}

//inOrder pominuvanje na drvoto
void inOrder(TreeNodePtr treePtr)
{
    if (treePtr != NULL) {
        inOrder(treePtr->leftPtr);
        printf("%3d", treePtr->data);
        inOrder(treePtr->rightPtr);
    }
}

//Se naogja jazolot so minimalna vrednost
TreeNodePtr minNode(TreeNodePtr node)
{
    TreeNodePtr current = node;

    while (current && current->leftPtr != NULL)
        current = current->leftPtr;

    return current;
}

//Se brise jazol od drvoto
TreeNodePtr deleteNode(TreeNodePtr root, int key)
{
    if (root == NULL) return root;

    if (key < root->data)
        root->leftPtr = deleteNode(root->leftPtr, key);

    else if (key > root->data)
        root->rightPtr = deleteNode(root->rightPtr, key);

    else
    {
        if (root->leftPtr == NULL)
        {
            TreeNodePtr temp = root->rightPtr;
            free(root);
            return temp;
        }
        else if (root->rightPtr == NULL)
        {
            TreeNodePtr temp = root->leftPtr;
            free(root);
            return temp;
        }

        TreeNodePtr temp = minNode(root->rightPtr);

        root->data = temp->data;

        root->rightPtr = deleteNode(root->rightPtr, temp->data);
    }
    return root;
}
