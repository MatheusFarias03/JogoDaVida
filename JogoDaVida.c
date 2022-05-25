// JogoDaVida.c : This file contains the 'main' function. Program execution begins and ends there.
// Leonardo Pinheiro de Souza - TIA : 32127391
// Matheus Farias de Oliveira Matsumoto - TIA : 32138271 

#include <stdio.h>
#include <stdlib.h>

void clear() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

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
        
        clear();

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

void countNeighbor(char** myMatrix, int inputSize, int** countNeighborMatrix) {

    int count = 0;

    for (int i = 1; i < inputSize; i++) {
        for (int j = 1; j < inputSize; j++) {
            
            count = 0;
            
            if (myMatrix[i - 1][j - 1] == 'O')
                count++;
            if (myMatrix[i - 1][j] == 'O')
                count++;
            if (myMatrix[i - 1][j + 1] == 'O')
                count++;
            if (myMatrix[i][j - 1] == 'O')
                count++;
            if (myMatrix[i][j + 1] == 'O')
                count++;
            if (myMatrix[i + 1][j - 1] == 'O')
                count++;
            if (myMatrix[i + 1][j] == 'O')
                count++;
            if (myMatrix[i + 1][j + 1] == 'O')
                count++;

            countNeighborMatrix[i-1][j-1] = count;
        }
    }

}

void updateMatrix(char** myMatrix, int** countNeighborMatrix, int inputSize) {
    for (int i = 0; i < inputSize; i++) {
        for (int j = 0; j < inputSize; j++) {
            if (myMatrix[i + 1][j + 1] == ' ' && countNeighborMatrix[i][j] == 3)
                myMatrix[i + 1][j + 1] = 'O';
            else if (myMatrix[i + 1][j + 1] == 'O' && countNeighborMatrix[i][j] == 2 || countNeighborMatrix[i][j] == 3)
                myMatrix[i + 1][j + 1] = 'O';
            else
                myMatrix[i + 1][j + 1] = ' ';
        }
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

    // Creating char matrix
    char** myMatrix = malloc(sizeof(char*) * matrixSize);
    for (int i = 0; i < matrixSize; i++) {
        myMatrix[i] = malloc(sizeof(char) * matrixSize);
        for (int j = 0; j < matrixSize; j++) {
            myMatrix[i][j] = ' ';
        }
    }

    // Creating int matrix
    int** countNeighborMatrix = malloc(sizeof(int*) * inputSize);
        for (int i = 0; i < inputSize; i++) {
            countNeighborMatrix[i] = malloc(sizeof(int) * inputSize);
            for (int j = 0; j < inputSize; j++) {
                myMatrix[i][j] = 0;
            }
        }

    inputMatrix(myMatrix, inputSize);

    // Game running
    int intInput = 2;
    while (intInput > 0) {
        printMatrix(myMatrix, matrixSize);
        countNeighbor(myMatrix, inputSize, countNeighborMatrix);
        updateMatrix(myMatrix, countNeighborMatrix, inputSize);
        printf("\nType a number different from 0 to see the next output: ");
        scanf_s("%d", &intInput);
        clear();
    }

    // Remove matrix from memory
    for (int i = 0; i < matrixSize; i++) {
        free(myMatrix[i]);
    }
    free(myMatrix);

    for (int i = 0; i < inputSize; i++) {
        free(countNeighborMatrix[i]);
    }
    free(countNeighborMatrix);

    return 0;
}

