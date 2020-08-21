#include <iostream>
#include <assert.h>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <regex>

using namespace std;

bool is_integer(const string &token) {
    return regex_match(token, regex("(\\+)?[[:digit:]]*"));
}

bool is_float(const string &token) {
    return regex_match(token, regex("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?"));
}

void print2DArray(float **arr, size_t row_count, size_t col_count) {
    cout << "\nArray output:" << endl;
    for (int i = 0; i < row_count; i++) {
        for (int j = 0; j < col_count; j++) {
            cout << setprecision(2) << fixed << arr[i][j] << '\t';
        }
        cout << endl;
    }
}

void printSpecialTask(int *arr, size_t row_count) {
    cout << "\nPrint special task output:" << endl;
    for (int i = 0; i < row_count; i++) {
        cout << arr[i] << '\t';
    }
}

float randomFloat(float min, float max) {
    float random = ((float) rand()) / (float) RAND_MAX;
    return (max - min) * random + min;
}

void randomFilling(float **arr, size_t row_count, size_t col_count) {
    for (int i = 0; i < row_count; i++) {
        for (int j = 0; j < col_count; j++) {
            arr[i][j] = randomFloat(-50, 50);
        }
    }
}

void manualFilling(float **arr, size_t row_count, size_t col_count) {
    string input_test;
    cout << "\nManual array filling:" << endl;

    for (int i = 0; i < row_count; i++) {
        for (int j = 0; j < col_count; j++) {
            cout << "Input row " << i + 1 << " ,column " << j + 1 << " value: ", cin >> input_test;
            cin.fail() || is_float(input_test) == 0 ? throw invalid_argument("Input error") :
                    arr[i][j] = static_cast<float>(stod(input_test));
        }
    }
    cin.clear();
    cin.ignore(32676, '\n');
}

void specialTask(float **array, int *arr, size_t row_count, size_t col_count) {
    for (int i = 0; i < row_count; i++) {
        int negNumCount = 0;
        for (int j = 0; j < col_count; j++)
            array[i][j] < 0 ? negNumCount++ : negNumCount;
        arr[i] = negNumCount;
    }
}

int main(int argc, char *argv[]) {
    cout << "Marks Fomins\n" << endl;

    string inputString;
    size_t rowC = 0;
    size_t columnC = 0;
    int input = 0;

    try {
        cout << "Input row count: ", cin >> inputString;
        if (is_integer(inputString)) {
            rowC = static_cast<size_t>(stod(inputString));
            input = static_cast<int>(rowC);
        }
        if (cin.fail() || input <= 0) {
            throw invalid_argument("Row count input error");
        }
        cout << "Input column count: ", cin >> inputString;
        if (is_integer(inputString)) {
            columnC = static_cast<size_t>(stod(inputString));
            input = static_cast<int>(columnC);
        }
        if (cin.fail() || input <= 0) {
            throw invalid_argument("Column count input error");
        }

        cin.clear();
        cin.ignore(32676, '\n');

        auto **my_array = new float *[rowC];
        for (int i = 0; i < rowC; i++) {
            my_array[i] = new float[columnC];
        }

        if (argc > 1) {
            if (string(argv[1]) == "-rand" || string(argv[1]) == "-RAND") {
                srand(static_cast<unsigned int>(time(nullptr)));
                randomFilling(my_array, rowC, columnC);
            }else{
                throw invalid_argument("\nIncorrect app parameter.");
            }
        } else {
            manualFilling(my_array, rowC, columnC);
        }

        print2DArray(my_array, rowC, columnC);

        auto *task_array = new int[rowC];
        specialTask(my_array, task_array, rowC, columnC);

        printSpecialTask(task_array, rowC);
        for (int i = 0; i < rowC; i++) {
            delete[] my_array[i];
        }
        delete[] my_array;
        delete[] task_array;
    } catch (invalid_argument &err) {
        cout << err.what() << endl;
    }
    return 0;
}