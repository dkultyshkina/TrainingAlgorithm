/*
Решение задачи по расстановке фигур на шахматной доске
*/

#include <iostream>
#include <string>

void Set(int** array, int& N, size_t row, size_t column) {
    for (size_t k = 1; k < N; ++k) {
        array[k][column] += 1;
        array[row][column] += 1;
        if ((row + column - k) >= 1 && (row + column - k) < N) {
            array[row + column - k][k] += 1;
        }
        if ((row - column + k) >= 1 && (row - column + k) < N) {
            array[row - column + k][k] += 1;
        }
    }
    array[row][column] = -1;
}

void Remove(int** array, int& N, size_t row, size_t column) {
    for (size_t k = 1; k < N; ++k) {
        array[k][column] -= 1;
        array[row][column] -= 1;
        if ((row + column - k) >= 1 && (row + column - k) < N) {
            array[row + column - k][k] -= 1;
        }
        if ((row - column + k) >= 1 && (row - column + k) < N) {
            array[row - column + k][k] -= 1;
        }
    }
    array[row][column] = 0;
}

void Solve(int** array, int& N, size_t row, int* sum) {
    for (size_t column = 1; column < N; ++column) {
        if (array[row][column] == 0) {
            Set(array, N, row, column);
            if (row == (N - 1)) {
                (*sum)++;
            }
            else {
                Solve(array, N, row + 1, sum);
            }
            Remove(array, N, row, column);
        }
    }
}


int main() {
    int N;
    std::cin >> N;
    N++;
    int** array = new int* [N];
    for (size_t i = 1; i < N; ++i) {
        array[i] = new int[N];
    }
    for (size_t row = 1; row < N; ++row) {
        for (size_t column = 1; column < N; ++column) {
            array[row][column] = 0;
        }
    }
    int sum = 0;
    Solve(array, N, 1, &sum);
    std::cout << sum;
}
