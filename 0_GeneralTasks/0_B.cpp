/*
Решение задачи представления результата сложения двух дробей в виде несократимой дроби
*/

#include <iostream>
#include <vector>

int GCD(int a, int b) {
    if (b == 0)
        return a;

    return GCD(b, a % b);
}

std::vector<int> AddTwoFractions(int* a, int* b, int* c, int* d) {
	int numerator = (*a) * (*d) + (*b) * (*c);
	int denominator = (*b) * (*d);
	int gcd = GCD(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;
	return { numerator, denominator };
}

int main()
{
	int a = 0, b = 0, c = 0, d = 0;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	std::cin >> d;
	int start = 0, end = 0;
	std::vector<int> result = AddTwoFractions(&a, &b, &c, &d);
	std::cout << result[0] << " " << result[1];
	return 0;
}
