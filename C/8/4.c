/*Да се напише програма која во главната функција внесува број на редици и колони на дводимензионална матрица. Во функцијата vnesiMatrica внесува
 * елементи, а преку функцијата pechatiMatrica ги печати елементите во табеларна форма.
а) Да се напишат итеративни верзии на двете функции.
б) Да се напишат рекурзивни верзии на двете функции.
*/
#include <stdio.h>

void vnesiMatrica(int matrix[50][50], int numberOfRows, int numberOfColumns);
void pechatiMatrica(int matrix[50][50], int numberOfRows, int numberOfColumns);
void vnesiMatrica_recursive(int matrix[50][50], int numberOfRows, int numberOfColumns, int currentRow, int currentColumn);
void pechatiMatrica_recursive(int matrix[50][50], int numberOfRows, int numberOfColumns, int currentRow, int currentColumn);

int main()
{
    int numberOfRows, numberOfColumns;
    printf("Vnesi broj na redici i broj na koloni:");
    scanf("%d %d", &numberOfRows, &numberOfColumns);
    int matrix[50][50];
    vnesiMatrica(matrix, numberOfRows, numberOfColumns);
    pechatiMatrica(matrix, numberOfRows, numberOfColumns);
    vnesiMatrica_recursive(matrix, numberOfRows, numberOfColumns, 0, 0);
    pechatiMatrica_recursive(matrix, numberOfRows, numberOfColumns, 0, 0);

    return 0;
}

void vnesiMatrica(int matrix[50][50], int numberOfRows, int numberOfColumns){
    int i, j;
    for(i = 0; i < numberOfRows; i++){
        for(j = 0; j < numberOfColumns; j++){
            printf("matrix[%d][%d]=", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}
void pechatiMatrica(int matrix[50][50], int numberOfRows, int numberOfColumns){
    int i, j;
    for(i = 0; i < numberOfRows; i++){
        for(j = 0; j < numberOfColumns; j++){
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}
void vnesiMatrica_recursive(int matrix[50][50], int numberOfRows, int numberOfColumns, int currentRow, int currentColumn){
    if(currentRow >= numberOfRows)
        return;

    printf("matrix[%d][%d]=", currentRow, currentColumn);
    scanf("%d", &matrix[currentRow][currentColumn]);

    if(currentColumn < numberOfColumns - 1){
        vnesiMatrica_recursive(matrix, numberOfRows, numberOfColumns, currentRow, currentColumn + 1);
    } else{
        vnesiMatrica_recursive(matrix, numberOfRows, numberOfColumns, currentRow + 1, 0);
    }
}
void pechatiMatrica_recursive(int matrix[50][50], int numberOfRows, int numberOfColumns, int currentRow, int currentColumn){
    if(currentRow >= numberOfRows)
        return;

    printf("%d\t", matrix[currentRow][currentColumn]);

    if(currentColumn < numberOfColumns - 1){
        pechatiMatrica_recursive(matrix, numberOfRows, numberOfColumns, currentRow, currentColumn + 1);
    } else{
        printf("\n");
        pechatiMatrica_recursive(matrix, numberOfRows, numberOfColumns, currentRow + 1, 0);
    }
}
