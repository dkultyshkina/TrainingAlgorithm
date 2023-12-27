/*
Решение задачи равенства подстрок с помощью нахождения хэшей строк
*/

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

bool EqualOrNot(std::vector<long long> &x, std::vector<long long> &h, int &L, int &A, int &B, int &p) {
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
    int x_ = 257, p = pow(10,9)+7;
    for (size_t i = 1; i < a.length(); ++i) {
        h.push_back((h[i-1]*x_ + a[i])%p);
        x.push_back((x[i-1] * x_) % p);
    }
    int n = 0, L = 0, A = 0, B = 0;
    std::cin >> n;
    bool result = true;
    for (size_t i = 0; i < n; ++i) {
        std::cin >> L >> A >> B;
        ++A;
        ++B;
        result = EqualOrNot(x, h, L, A, B, p);
        if (result == true) {
            std::cout << "yes";
        }
        else {
            std::cout << "no";
        }
        if (i != n - 1) {
            std::cout << "\n";
        }
    } 
    return 0;
}
