
#include <iostream>

/*
Решение задачи поиска самого большого квадрата из единиц на поле. Максимальный размер поля - 1000 на 1000 
*/

unsigned int MinElement(unsigned int** arr, size_t i, size_t j) {
    unsigned int first = arr[i - 1][j], second = arr[i][j - 1], third = arr[i - 1][j - 1];
    unsigned int min = first;
    if (second <= first && second <= third) {
        min = second;
    }
    if (third <= first && third <= second) {
        min = third;
    }
    if (first <= second && first <= third) {
        min = first;
    }
    return min+1;
}

int main()
{
    unsigned int N = 0, M = 0;
    unsigned int result = 0;
    std::cin >> N >> M;
    unsigned int** arr = new unsigned int*[N];
    for (int i = 0; i < N; i++) {
        arr[i] = new unsigned int[M];
    }
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < M; ++j) {
            std::cin >> arr[i][j];
        }
    }
    for (size_t i = 1; i < N; ++i) {
        for (size_t j = 1; j < M; ++j) {
            if (arr[i][j] == 1) {
                arr[i][j] = MinElement(arr, i, j);
                if (arr[i][j] > result) {
                    result = arr[i][j];
                }
            }
        }
    }
    std::cout << "\n";
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < M; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << result;
    return 0;
}
