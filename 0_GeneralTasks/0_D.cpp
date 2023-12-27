/*
Решение задачи, которая проверяет является ли одна строка анаграммой другой
*/
#include <iostream>
#include <map>
#include <string>

int main()
{
    std::string first, second;
    std::cin >> first >> second;
    std::map<char, int> sort;
    std::map<char, int> sort2;
    std::pair<char, int> p;
    for (size_t i = 0; i < first.length(); ++i) {
        auto it = sort.find(first[i]);
        if (it != sort.end()) {
            sort[first[i]]++;
        }
        else {
            p = std::make_pair(first[i], 1);
            sort.insert(p);
        }
    }
    for (size_t i = 0; i < second.length(); ++i) {
        auto it = sort2.find(second[i]);
        if (it != sort2.end()) {
            sort2[second[i]]++;
        } else {
            p = std::make_pair(second[i], 1);
            sort2.insert(p);
        }
    }
    auto iter = sort2.begin();
    for (auto& it : sort) {
        if (it.second != iter->second || it.first != iter->first) {
            std::cout << "NO";
            return 0;
        }
        iter++;
    }
    std::cout << "YES";
    return 0;
}