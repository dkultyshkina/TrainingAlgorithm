/*
Реализация быстрого алгоритма Дейкстры для нахождения кратчайшего расстояния от одной вершины до другой на основе заданного ориентированного взвешенного графа
*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>

int main()
{
    const long long inf = 100000000000;
    int N = 0, K = 0, l = 0, a = 0, b = 0;
    std::cin >> N >> K;
    K++;
    N++;
    std::multimap<long long, std::pair<long long, long long>> m;
    for (size_t i = 1; i < K; ++i) {
        std::cin >> a >> b >> l;
        m.insert(std::make_pair(a, std::make_pair(b, l)));
        m.insert(std::make_pair(b, std::make_pair(a, l)));
    }
    int A = 0, B = 0;
    std::cin >> A >> B;
    int length = 0, top = 0;
    std::vector<long long> dist(N, inf);
    dist[A] = 0;
    std::priority_queue<std::pair<long long, long long>> pq;
    pq.push(std::make_pair(A, 0));
    while (!pq.empty()) {
        top = pq.top().first;
        length = pq.top().second;
        pq.pop();
        if (length <= dist[top]) {
            for (auto it = m.find(top); it != m.end(); ++it) {
                if (it->first != top) {
                    break;
                }
                length = it->second.second;
                if (length >= 0 && dist[it->second.first] > (dist[top] + length)) {
                    dist[it->second.first] = dist[top] + length;
                    pq.push(std::make_pair(it->second.first, dist[it->second.first]));
                }
            }
        }
    }
    if (dist[B] == inf) {
        std::cout << -1;
    }
    else std::cout << dist[B];
    return 0;
}
