/*
Реализация алгоритма Дейкстры для нахождения кратчайшего расстояния от одной вершины до другой на основе заданного ориентированного взвешенного графа
*/

#include <iostream>
#include <vector>
#include <queue>

int main()
{
    const int inf = 100000;
    int N = 0, S = 0, F = 0;
    std::cin >> N >> S >> F;
    if (S == F) {
        std::cout << 0;
        return 0;
    }
    N++;
    int** arr = new int* [N];
    for (int i = 1; i < N; i++) {
        arr[i] = new int[N];
    }
    for (size_t i = 1; i < N; ++i) {
        for (size_t j = 1; j < N; ++j) {
            std::cin >> arr[i][j];
        }
    }
    int length = 0, top = 0;
    std::vector<int> dist(N, inf);
    dist[S] = 0;
    std::priority_queue<std::pair<int, int>> pq;
    pq.push(std::make_pair(S, 0));
    while (!pq.empty()) {
        top = pq.top().first;
        length = pq.top().second;
        pq.pop();
        if (length <= dist[top]) {
            for (size_t j = 1; j < N; ++j) {
                length = arr[top][j];
                if (length >= 0 && dist[j] > (dist[top] + length)) {
                    dist[j] = dist[top] + length;
                    pq.push(std::make_pair(j, dist[j]));
                }
            }
        }
    }
    if (dist[F] == inf) {
        std::cout << -1;
    }
    else std::cout << dist[F];
    return 0;
}
