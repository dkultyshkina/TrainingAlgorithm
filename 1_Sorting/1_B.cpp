/*
Реализация быстрой сортировки, с использованием алгоритма partition.
*/

#include <iostream>
#include <vector>

std::vector<int> partition(int* v, int start, int end) {
	int x = v[rand() % (end - start) + start];
	int E = start, G = start, temp = start;
	for (size_t N = start; N < end; ++N) {
		if (v[N] < x) {
			temp = v[N];
			v[N] = v[G];
			v[G] = v[E];
			v[E] = temp;
			++E;
			++G;
		}
		else if (v[N] == x) {
			temp = v[N];
			v[N] = v[G];
			v[G] = temp;
			++G;
		}
	}
	return { E, G };
}

void quicksort(int* v, int start, int end) {
	if (start >= end) {
		return;
	}
	std::vector<int> pivot = partition(v, start, end);
	quicksort(v, start, pivot[0]);
	quicksort(v, pivot[1], end);
}

int main()
{
	int count = 0;
	std::cin >> count;
	int* array = new int[count];
	int x = 0;
	for (size_t i = 0; i < count; ++i) {
		std::cin >> array[i];
	}
	if (count == 0) {
		return 0;
	}
	if (count == 1) {
		std::cout << array[0];
		return 0;
	}
	quicksort(array, 0, count);
	for (size_t i = 0; i < count - 1; ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << array[count - 1];
	return 0;
}
