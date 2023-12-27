/*
Реализация поразрядной сортировки
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>

void PrintBucket(std::vector<std::string>* v, int j, int len_number) {
    std::cout << "Phase " << len_number << "\n";
    int m = 0, k = 48;
    for (size_t i = 0; i < (*v).size();) {
        if ((*v)[i][j] == k) {
            std::cout << "Bucket " << (*v)[i][j] << ": " << (*v)[i];
            m = i + 1;
            while (m < (*v).size() && (*v)[i][j] == (*v)[m][j]) {
                ++i;
                std::cout << ", " << (*v)[i];
                ++m;
            }
            if ((*v)[i][j] != 57) {
                std::cout << "\n";
            }
            ++i;
        }
        else {
            std::cout << "Bucket " << char(k) << ": empty";
            if (char(k) != (*v).size() - 1) {
                std::cout << "\n";
            }
        }
        ++k;
    }
    if (k < 58) {
        while (k != 58) {
            std::cout << "Bucket " << char(k) << ": empty";
            if (k != 57) {
                std::cout << "\n";
            }
            ++k;
        }
    }
    std::cout << "\n**********\n";
}

void CountSort(std::vector<std::string>* v, size_t j, size_t len_number) {
    std::multimap<std::string, std::string> sort;
    std::pair<std::string, std::string> p;
    for (size_t i = 0; i < (*v).size(); ++i) {
        p = std::make_pair((*v)[i][j], (*v)[i]);
        sort.insert(p);
    }
    size_t i = 0;
    for (auto& it : sort) {
        (*v)[i] = it.second;
        ++i;
    }
    PrintBucket(v, j, len_number - j);
}


void RadixSort(std::vector<std::string>* v, int count) {
    size_t len_number = (*v)[0].length();
    for (size_t j = len_number - 1; j != -1; j--) {
        CountSort(v, j, len_number);
    }
}


int main()
{
    int count = 0;
    std::cin >> count;
    std::vector<std::string> v;
    if (count != 0) {
        std::string x;
        for (size_t i = 0; i < count; ++i) {
            std::cin >> x;
            v.push_back(x);
        }
        std::cout << "Initial array:\n";
        for (size_t i = 0; i < count - 1; ++i) {
            std::cout << v[i] << ", ";
        }
        std::cout << v[count - 1];
        std::cout << "\n**********\n";
        RadixSort(&v, count);
        std::cout << "Sorted array:\n";
        for (size_t i = 0; i < count - 1; ++i) {
            std::cout << v[i] << ", ";
        }
        std::cout << v[count - 1];
    }
}