#include <iostream>
#include <malloc.h>
#include <stdlib.h>

using namespace std;

bool chooseArr() {
    cout << "If you want to insert random array, insert 'y': ";
    char decision;
    cin >> decision;
    return decision == 'y';
}

void arrayOutput(int rows, int columns, double **arr) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void changedArrayWithMaxNumber(int rows, int columns, double **arr, double maxNumber, int rowOfMax, int columnOfMax) {
    double firstNumber = arr[0][0];
    arr[0][0] = maxNumber;
    arr[rowOfMax][columnOfMax] = firstNumber;

    cout << endl;
    cout << "New array:" << endl;

    arrayOutput(rows, columns, arr);
}

void maxNumber(int rows, int columns, double **arr) {
    double maxNumber = 0;
    int rowOfMax = 0;
    int columnOfMax = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (arr[i][j] > maxNumber) {
                maxNumber = arr[i][j];
                if (maxNumber) {
                    rowOfMax = i;
                    columnOfMax = j;
                }
            }
        }
    }
    cout << endl;
    cout << "Max number: " << maxNumber << endl;
    cout << "Max number row: " << rowOfMax << endl;
    cout << "Max number column: " << columnOfMax << endl;

    changedArrayWithMaxNumber(rows, columns, arr, maxNumber, rowOfMax, columnOfMax);

}

void arr(int rows, int columns) {
    double **arr;
    arr = (double **) malloc(sizeof(double *) * rows);
    for (int i = 0; i < rows; i++) {
        arr[i] = (double *) malloc(sizeof(double) * columns);
    }
    srand(time(NULL));
    if (chooseArr()) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                arr[i][j] = (rand() % 10000 - 5000) / 100.0;
            }
            cout << endl;
        }
    } else {
        cout << "Insert by rows:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cin >> arr[i][j];
            }
            cout << endl;
        }
    }
    cout << "Your array:" << endl;
    arrayOutput(rows, columns, arr);
    maxNumber(rows, columns, arr);

    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
}

int main() {
    int row;
    int column;
    cout << "Insert row number: ";
    cin >> row;
    cout << "Insert column number: ";
    cin >> column;
    cout << endl;

    arr(row, column);
}
