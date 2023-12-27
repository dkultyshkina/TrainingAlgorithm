/*
Реализация сортировки слиянием
*/

#include <iostream>
#include <vector>

void Merge(std::vector<int>* v, std::vector<int>* left, std::vector<int>* right, int start) {
	int i = 0, j = 0, k = start;
	while (i < (*left).size() && j < (*right).size()) {
		if ((*left)[i] <= (*right)[j]) {
			(*v)[k] = (*left)[i];
			++i;
		}
		else {
			(*v)[k] = (*right)[j];
			++j;
		}
		k++;
	}
	while (i < (*left).size()) {
		(*v)[k] = (*left)[i];
		++k;
		++i;
	}
	while (j < (*right).size()) {
		(*v)[k] = (*right)[j];
		++k;
		++j;
	}
}

void MergeSort(std::vector<int>* v, int start, int end) {
	if (start >= end) {
		return;
	}
	int middle = start + (end - start) / 2;
	MergeSort(v, start, middle);
	MergeSort(v, middle + 1, end);
	std::vector<int> left, right;
	for (int i = 0; i <= middle - start; i++) {
		left.push_back((*v)[start + i]);
	}
	for (int i = 0; i < end - middle; i++) {
		right.push_back((*v)[middle + i + 1]);
	}
	Merge(v, &left, &right, start);
}


int main()
{
	std::vector<int> v;
	int x = 0;
	int count = 0;
	std::cin >> count;
	if (count != 0) {
		for (size_t i = 0; i < count; ++i) {
			std::cin >> x;
			v.push_back(x);
		}
	}
	if (v.size() != 0) {
		MergeSort(&v, 0, v.size() - 1);
		for (size_t i = 0; i < v.size() - 1; ++i) {
			std::cout << v[i] << " ";
		}
		std::cout << v[v.size() - 1];
	}
	return 0;
}