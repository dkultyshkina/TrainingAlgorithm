/*
Решение задачи нахождения среднего уровня недовольства по каждому студенту из рейтинга (входные данные), представленного по возрастанию.
Само недовольство вычисляется как модуль разницы рейтинга студентов.
*/
#include <iostream>
#include <vector>

int main()
{
    int count = 0, x = 0, sum = 0, sum_before = 0, sum_after = 0;
    std::cin >> count;
    std::vector<int> v;
    for (int i = 0; i < count; ++i) {
        std::cin >> x;
        v.push_back(x);
    }
    for (int i = 0; i < count; ++i) {
        sum_after += v[i];
    }
    for (int i = 0; i < count; ++i) {
        sum_before += v[i];
        sum_after -= v[i];
        std::cout << ((i + 1) * v[i] - sum_before) + abs(((count - 1 - i) * v[i]) - sum_after);
        if (i != count - 1) {
            std::cout << " ";
        }
    }
}
