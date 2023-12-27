/*
Реализация базового алгоритма partition для быстрой сортировки
*/

#include <iostream>
#include <vector>

int main()
{
	int count = 0;
	std::cin >> count;
	std::vector<int> v;
	int x = 0;
	for (size_t i = 0; i < count; ++i) {
		std::cin >> x;
		v.push_back(x);
	}
	std::cin >> x;
	int E = 0, G = 0, temp = 0;
	for (size_t N = 0; N < count; ++N) {
		if (v[N] < x) {
			temp = v[N];
			v[N] = v[G];
			v[G] = v[E];
			v[E] = temp;
			E++;
			G++;
		}
		else if (v[N] == x) {
			temp = v[N];
			v[N] = v[G];
			v[G] = temp;
			G++;
		}
	}
	std::cout << E << "\n";
	std::cout << count - E;
	return 0;
}
