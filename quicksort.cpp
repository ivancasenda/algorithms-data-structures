#include <vector>
#include <iostream>

/*void quicksort(int unsorted[], int l, int r) {
	
	if (l < r) {
		std::vector<int> smaller;
		std::vector<int> greater;
		int pivot = unsorted[r];
		for (int i = l; i < r; i++) {
			if (unsorted[i] < pivot) {
				smaller.push_back(unsorted[i]);
			}
			else {
				greater.push_back(unsorted[i]);
			}
		}
		int index = l;
		if (smaller.size() != 0) {
			for (auto i = smaller.begin(); i != smaller.end(); i++) {
				unsorted[index] = *i;
				index++;
			}
			quicksort(unsorted, l, index - 1);
		}
		int m = index;
		unsorted[m] = pivot;
		index++;
		if (greater.size() != 0) {
			for (auto i = greater.begin(); i != greater.end(); i++) {
				unsorted[index] = *i;
				index++;
			}
			quicksort(unsorted, m + 1, r);
		}
	}
}*/


void quicksort(int unsorted[], int l, int r) {
	if (l < r) {
		int pivot = unsorted[r];
		int left = l;
		int right = r;

		while (left < right) {
			while (unsorted[left] < pivot) {
				left++;
			}
			while (unsorted[right] > pivot) {
				right--;
			}

			if (left < right) {
				int temp = unsorted[left];
				unsorted[left] = unsorted[right];
				unsorted[right] = temp;

				left++;
				right--;
				
			}
		}

		quicksort(unsorted, l, left - 1);
		quicksort(unsorted, left, r);

	}

	
}

void testQuickSort() {
	int list[] = { 2,1,3,5,4 };
	quicksort(list, 0, 4);
	for (int  i = 0; i < 5; i++) {
		std::cout << list[i] << std::endl;
	}
}


