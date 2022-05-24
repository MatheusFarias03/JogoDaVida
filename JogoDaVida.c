// JogoDaVida.c : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>

void printMatrix(char** myMatrix, int matrixSize) {
    
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            if (i == 0 || i == matrixSize - 1)
                printf("===");
            else if (j == 0)
                printf("|  ");
            else if (j == matrixSize - 1)
                printf("  |");
            else
                printf(" %c ", myMatrix[i][j]);
        }
        printf("\n");
    }
}

void inputMatrix(char** myMatrix, int inputSize) {
    
    int i = 1;
    int j = 1;
    int cellCount = 0;

    while (i > 0 && j > 0) {
        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif

        // Print the data 
        printf("Cell count : %d", cellCount);
        printf("\nCells positions :");
        for (int i = 0; i <= inputSize; i++) {
            for (int j = 0; j <= inputSize; j++) {
                if (myMatrix[i][j] == 'O')
                printf(" (%d, %d) ", i, j);
            }
        }

        // Input row
        printf("\nType the row of the desired living cell (1 - %d) : ", inputSize);
        scanf_s("%d", &i);
        while (i > inputSize) {
            printf("List Index Out of Bounds. Try a number between 1 and %d : ", inputSize);
            scanf_s("%d", &i);
        }
        if (i <= 0)
            break;

        // Input column
        printf("Type the column of the desired living cell (1 - %d) : ", inputSize);
        scanf_s("%d", &j);
        while (j > inputSize) {
            printf("List Index Out of Bounds. Try a number between 1 and %d", inputSize);
            scanf_s("%d", &j);
        }
        if (j <= 0)
            break;

        // Add cell according to coordinates
        myMatrix[i][j] = 'O';
        cellCount ++;
    }

}

int main()
{
    // User input for matrix size
    int inputSize;
    int matrixSize;
    printf("Type the size (n) of the matrix (n x n): ");
    scanf_s("%d", &inputSize);
    matrixSize = inputSize + 2; // Create borders (+2)

    // Creating matrix
    char** myMatrix = malloc(sizeof(char*) * matrixSize);
    for (int i = 0; i < matrixSize; i++) {
        myMatrix[i] = malloc(sizeof(char) * matrixSize);
        for (int j = 0; j < matrixSize; j++) {
            myMatrix[i][j] = ' ';
        }
    }

    inputMatrix(myMatrix, inputSize);
    printMatrix(myMatrix, matrixSize);



    free(myMatrix);
    return 0;
}

