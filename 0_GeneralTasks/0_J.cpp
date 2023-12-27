/*
Решение задачи возможности или не возможности разбиения n людей на группы, в которых могут быть от a до b человек
*/
#include <iostream>

int main()
{
    unsigned int count = 0, n = 0, a = 0, b = 0, groups = 0;
    std::cin >> count;
    for (size_t i = 0; i < count; ++i) {
        std::cin >> n >> a >> b;
        groups = n/a;
        if (n % a <= groups * (b - a)) {
            std::cout << "YES";
        }
        else {
            std::cout << "NO";
        }
        if (i != (count - 1)) {
            std::cout << "\n";
        }
    }
}

