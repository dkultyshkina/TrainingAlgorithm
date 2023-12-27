/*
Решение задачи о перестановках чисел по заданной длине в лексикографическом порядке
*/
#include <iostream>
#include <vector>

void ReverseStr(std::vector<int>& v, int start, int end) {
    while (start < end) {
        std::swap(v[start], v[end]);
        start++;
        end--;
    }
}

int FindIndex(std::vector<int>& v, int& element, int start, int end)
{ 
    int index = start;
    for (size_t i = start + 1; i <= end; ++i) {
        if (v[i] > element && v[i] < v[index]) {
            index = i;
        }
    }
    return index;
}

void PrintVector(std::vector<int>& v) {
    auto i = v.begin();
    ++i;
    for (; i < v.end(); ++i) {
        std::cout << *i;
    }
}

void Sort(std::vector<int>& v)
{
    int len = v.size();
    bool metka = true;
    while (metka)
    {
        PrintVector(v);
        size_t i = 0;
        for (i = (len - 2); i > 0; --i) {
            if (v[i] < v[i + 1]) {
                break;
            }
        }
        if (i == 0) {
            metka = false;
        } else {
           int index = FindIndex(v, v[i], i + 1, len - 1);
           std::swap(v[i], v[index]);
           ReverseStr(v, i + 1, len - 1);
           std::cout << "\n";
        }
    }
}

int main()
{
    int N = 0;
    std::cin >> N;
    N++;
    std::vector<int> v;
    v.push_back(0);
    for (size_t i = 1; i < N; ++i) {
        v.push_back(i);
    }
    Sort(v);
    return 0;
}
