/*
Реализация алгоритма слияния двух упорядоченных массивов в один упорядоченный массив
*/

#include <iostream>
#include <vector>

void Merge(std::vector<int>* v, std::vector<int>* left, std::vector<int>* right) {
	int i = 0, j = 0;
	while (i < (*left).size() && j < (*right).size()) {
		if ((*left)[i] <= (*right)[j]) {
		   (*v).push_back((*left)[i]);
			++i;
		}
		else {
			(*v).push_back((*right)[j]);
			++j;
		}
	}
	while (i < (*left).size()) {
		(*v).push_back((*left)[i]);
		++i;
	}
	while (j < (*right).size()) {
		(*v).push_back((*right)[j]);
		++j;
	}
}

int main()
{
	std::vector<int> v;
	std::vector<int> v2;
	std::vector<int> result;
	int x = 0;
	int count = 0;
	std::cin >> count;
	if (count != 0) {
		for (size_t i = 0; i < count; ++i) {
			std::cin >> x;
			v.push_back(x);
		}
	}
	std::cin >> count;
	if (count != 0) {
		for (size_t i = 0; i < count; ++i) {
			std::cin >> x;
			v2.push_back(x);
		}
	}
	if (v.size() != 0 || v2.size() != 0) {
		Merge(&result, &v, &v2);
		for (size_t i = 0; i < result.size() - 1; ++i) {
			std::cout << result[i] << " ";
		}
		std::cout << result[result.size() - 1];
	}
	return 0;
}
