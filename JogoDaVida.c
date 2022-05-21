// JogoDaVida.c : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>

void printMatrix(char** myMatrix, int matrixSize) {
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            printf("|_%c_|", myMatrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // User input for matrix size
    int matrixSize;
    printf("Type the size (n) of the matrix (n x n): ");
    scanf_s("%d", &matrixSize);

    // Creating matrix
    char** myMatrix = malloc(sizeof(char*) * matrixSize);
    for (int i = 0; i < matrixSize; i++) {
        myMatrix[i] = malloc(sizeof(char) * matrixSize);
        for (int j = 0; j < matrixSize; j++) {
            myMatrix[i][j] = ' ';
        }
    }

    printMatrix(myMatrix, matrixSize);

    free(myMatrix);
    return 0;
}

