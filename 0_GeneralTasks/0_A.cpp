/*
Задача поиска любого не минимума на заданных отрезках из последовательности
*/

#include <iostream>
#include <vector>
#include <algorithm>

void FindNotMinimum(std::vector<int>* sort, int start, int end) {
	int min = 0, max = 0;
	std::vector<int> find;
	for (size_t i = start; i <= end; ++i) {
		find.push_back((*sort)[i]);
	}
    max = *max_element(find.begin(), find.end());
	min = *min_element(find.begin(), find.end());
	if (min == max) {
		std::cout << "NOT FOUND";
	}
	else {
		std::cout << max;
	}
};

int main()
{
	int len = 0, count = 0, x = 0;
	std::cin >> len;
	std::cin >> count;
	std::vector<int> sort;
	for (size_t i = 0; i < len; ++i) {
		std::cin >> x;
		sort.push_back(x);
	}
	int start = 0, end = 0;
	for (size_t i = 0; i < count; ++i) {
		std::cin >> start >> end;
		FindNotMinimum(&sort, start, end);
		if (i != count - 1) {
			std::cout << "\n";
		}
	}
	return 0;
}
