#include <iostream>
#include <cmath>


void countingSort(int unsorted[], int size, int digit);
void radixSort(int unsorted[], int size);

void testRadixSort() {
	int numbers[] = { 23,32,1,24,5,143,67,8,78,75,94,10 };
	int size = sizeof(numbers) / sizeof(numbers[0]);
	for (int i = 0; i < size; i++) {
		std::cout << numbers[i] << std::endl;
	}
	std::cout << "\n" << std::endl;
	radixSort(numbers, size);
	for (int i = 0; i < size; i++) {
		std::cout << numbers[i] << std::endl;
	}
}


void radixSort(int unsorted[], int size) {


	int max = 0;
	for (int i = 0; i < size; i++) {
		if (unsorted[i] > max) {
			max = unsorted[i];
		}
	}

	int totalDigits = std::floor(std::log10(max) + 1);


	for (int i = 1; i <= totalDigits; i++) {
		countingSort(unsorted, size, i);
		for (int i = 0; i < size; i++) {
			std::cout << unsorted[i] << std::endl;
		}
		std::cout << "\nT\n" << std::endl;
	}
}

