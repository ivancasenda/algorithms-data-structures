#include <iostream>
#include <cmath>

void countingSort(int unsorted[], int size, int digit);

void testCountingSort() {
	int numbers[] = { 2,3,1,4,5,3,6,8,7,7,9,0 };
	int size = sizeof(numbers) / sizeof(numbers[0]);
	for (int i = 0; i < size; i++) {
		std::cout << numbers[i] << std::endl;
	}
	std::cout << "\n" << std::endl;
	countingSort(numbers,size, 1);
	for (int i = 0; i < size; i++) {
		std::cout << numbers[i] << std::endl;
	}
}



void countingSort(int unsorted[], int size, int digit) {

	int numberCount[] = { 0,0,0,0,0,0,0,0,0,0 };
	
	int sizeCount = sizeof(numberCount) / sizeof(numberCount[0]);

	double num = (double)digit;

	for (int i = 0; i < size; i++) {
		int numberDigit = std::floor((unsorted[i] % (int)pow(10.0, num))/pow(10,digit-1));
		numberCount[numberDigit]++;
	}
	
	for (int i = 1; i < sizeCount; i++) {
		numberCount[i] = numberCount[i] + numberCount[i - 1];
	}

	int* sorted = new int[size];

	for (int i = size - 1; i > -1; i--) {
		int numberDigit = std::floor((unsorted[i] % (int)pow(10.0, num)) / pow(10, digit - 1));
		int index = numberCount[numberDigit];
		sorted[index - 1] = unsorted[i];
		numberCount[numberDigit]--;
	}

	for (int i = 0; i < size; i++) {
		unsorted[i] = sorted[i];
	}

	delete [] sorted;

}
