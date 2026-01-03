#include <stdio.h>

int LINES = 7, COLUMNS = 11;

void display_matrix(int lines, int columns, int matrix[lines][columns]) {
    for (int i=0; i<lines; ++i) {
        for (int j=0; j<columns; ++j) {
            printf("%5d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void sum_matrices(int lines, 
                  int columns, 
                  int A[lines][columns],
                  int B[lines][columns],
                  int C[lines][columns]) {
    for (int i=0; i<lines; ++i) {
        for (int j=0; j<columns; ++j) {
           C[i][j] = A[i][j] + B[i][j];
        }
    }
}

int main() {
    int matrixA[LINES][COLUMNS], matrixB[LINES][COLUMNS], matrixC[LINES][COLUMNS];

    for (int i=0; i<LINES; ++i) {
        for (int j=0; j<COLUMNS; j++) {
            matrixA[i][j] = i + j;
        }
    }

    for (int i=0; i<LINES; ++i) {
        for (int j=0; j<COLUMNS; j++) {
            matrixB[i][j] = i*j;
        }
    }

    printf("\nMATRIX A\n");
    display_matrix(LINES, COLUMNS, matrixA);

    printf("\nMATRIX B\n");
    display_matrix(LINES, COLUMNS, matrixB);

    sum_matrices(LINES, COLUMNS, matrixA, matrixB, matrixC);
    printf("\nMatrix A + Matrix B:\n");
    display_matrix(LINES, COLUMNS, matrixC);

    return 0;
}