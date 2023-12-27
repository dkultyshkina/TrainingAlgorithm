/*
Решение через вычисление хэшей для посчёта z-функции
*/

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

bool EqualOrNot(std::vector<long long>& x, std::vector<long long>& h, int& L, int& A, int& B, int& p) {
    int L_start = L;
    if (h.size() - 1 < A + L) {
        L = h.size() - A;
    }
    else {
        L = L_start;
    }
    int A_result = ((h[A + L - 1] + h[B - 1] * x[L]) % p);
    L = L_start;
    if (h.size() - 1 < B + L) {
        L = h.size() - B;
    }
    else {
        L = L_start;
    }
    int B_result = ((h[B + L - 1] + h[A - 1] * x[L]) % p);
    return (A_result == B_result);
}

int main()
{
    std::string a;
    std::cin >> a;
    auto i = a.begin();
    a.insert(i, ' ');
    std::vector<long long> h;
    h.push_back(0);
    std::vector<long long> x;
    x.push_back(1);
    int x_ = 257, p = pow(10, 9) + 7;
    for (size_t i = 1; i < a.length(); ++i) {
        h.push_back((h[i - 1] * x_ + a[i]) % p);
        x.push_back((x[i - 1] * x_) % p);
    }
    std::vector<long long> z(a.length(), 0);
    size_t n = a.length();
    int A = 1, B = n - 1, middle = 0, ref = 1;
    for (int i = 2; i < n; i++) {
        A = 1, B = n - i;
        while (A <= B) {
            middle = (A + B) / 2;
            if (EqualOrNot(x, h, middle, ref, i, p)) {
                z[i] = middle;
                A = middle + 1;
            }
            else {
                B = middle - 1;
            }
        }
    }
    for (size_t i = 1; i < n; ++i) {
        std::cout << z[i];
        if (i != a.length()) {
            std::cout << " ";
        }
    }
    return 0;
}
