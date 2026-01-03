#include <iostream>
using namespace std;

const int LINES = 7;
const int COLUMNS = 11;

void display_matrix(int matrix[LINES][COLUMNS]) {
    for (int i = 0; i < LINES; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << '\n';
    }
}

void sum_matrices(int A[LINES][COLUMNS],
                  int B[LINES][COLUMNS],
                  int C[LINES][COLUMNS]) {
    for (int i = 0; i < LINES; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

int main() {
    int matrixA[LINES][COLUMNS];
    int matrixB[LINES][COLUMNS];
    int matrixC[LINES][COLUMNS];

    for (int i = 0; i < LINES; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            matrixA[i][j] = i + j;
        }
    }

    for (int i = 0; i < LINES; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            matrixB[i][j] = i * j;
        }
    }

    cout << "\nMATRIX A\n";
    display_matrix(matrixA);

    cout << "\nMATRIX B\n";
    display_matrix(matrixB);

    sum_matrices(matrixA, matrixB, matrixC);

    cout << "\nMatrix A + Matrix B\n";
    display_matrix(matrixC);

    return 0;
}
