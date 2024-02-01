#include <iostream>


void merge(int arr[], int lo, int mi, int hi) {
	int* temp = new int[hi - lo + 1];//temporary merger array
	int i = lo, j = mi + 1;//i is for left-hand,j is for right-hand
	int k = 0;//k is for the temporary array
	while (i <= mi && j <= hi) {
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	//rest elements of left-half
	while (i <= mi)
		temp[k++] = arr[i++];
	//rest elements of right-half
	while (j <= hi)
		temp[k++] = arr[j++];
	//copy the mergered temporary array to the original array
	for (k = 0, i = lo; i <= hi; ++i, ++k)
		arr[i] = temp[k];

	delete[] temp; 
}

void mergesort(int unsorted[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		mergesort(unsorted, l, m );
		mergesort(unsorted, m + 1, r);

		merge(unsorted, l, m, r);
	}
}


void mergesortTest() {
	int list[] = { 3,2,1,5,7,6,8,10,9,4 };
	mergesort(list, 0, 9);
	for (int i = 0; i < 10; i++) {
		std::cout << list[i] << std::endl;
	}
}

