#pragma once
#include "array_list.h"
#include <cmath>

class MinHeap {
	ArrayList<int> list;
	int index = 0;

	void swap(int index1, int index2) {
		int temp = list.view(index1);
		list.insert(index1, list.view(index2));
		list.insert(index2, temp);
	}

	void upHeapify(int elementIndex) {
		int parentIndex = std::floor((elementIndex - 1) / 2);
		if (parentIndex < 0 || list.view(elementIndex) >= list.view(parentIndex))return;
		swap(parentIndex, elementIndex);
		upHeapify(parentIndex);
	}
	void downHeapify(int elementIndex) {
		int leftChild = elementIndex * 2 + 1;
		int rightChild = elementIndex * 2 + 2;

		if (leftChild >= index)return;
		else if (rightChild >= index) {
			if (list.view(leftChild) < list.view(elementIndex)) {
				swap(elementIndex, leftChild);
				downHeapify(leftChild);
			}
		}
		else {
			int min = rightChild;
			if (list.view(leftChild) < list.view(rightChild)) {
				min = leftChild;
			}
			if (list.view(min) < list.view(elementIndex)) {
				swap(elementIndex, min);
				downHeapify(min);
			}
		}
	}

	
public:

	void insert(int element) {
		list.insert(index, element);
		upHeapify(index);
		index++;
	}

	void pop() {
		if (index - 1 < 0 )return;
		index--;
		swap(0, index);
		list.remove(index);
		downHeapify(0);
	}

	int peek() {
		return list.view(0);
	}



};
