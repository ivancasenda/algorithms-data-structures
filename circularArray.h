#pragma once
#include <iostream>

template <typename T>
class CircularArray {
private:
	T* list;
	int head = 1;
	int tail = 0;
	int total = 0;
	int size;

	void doubleSize() {
		T* newList = new T[size * 2];
		for (int i = 0; i < total; i++) {
			newList[i] = list[(head + i) % size];
		}
		head = 0;
		tail = total - 1;
		size = size * 2;
		delete[] list;
		list = newList;
	}
public:
	CircularArray(int size = 5): size(size) {
		if (size <= 0)size = 5;
		list = new T[size];
	}
	~CircularArray() {
		delete[] list;
	}

	void insertFront(T data) {
		if (total == 0) {
			head = 1;
			tail = 0;
		}
		if (total == size) {
			doubleSize();
		}
		head -= 1;
		if (head == -1) {
			head = size - 1;
		}
		list[head] = data;
		total++;
	}

	void insertBack(T data) {
		if (total == 0) {
			head = 1;
			tail = 0;
		}
		if (total == size) {
			doubleSize();
		}
		tail += 1;
		if (tail == size) {
			tail = 0;
		}
		list[tail] = data;
		total++;
	}

	void insertIndex(T data, int index) {
		if (total == 0)insertBack(data);
		else if (index >= total || index < 0)return;
		else {
			if (total == size) {
				doubleSize();
			}
			for (int i = total - 1; i >= index; i--) {
				list[(head + i + 1) % size] = list[(head + i) % size];
			}
			list[(head + index) % size] = data;
			total++;
		}
		
	}
	
	void removeFront() {
		if (total == 0)return;
		head += 1;
		if (head == size) {
			head = 0;
		}
		total--;
	}

	void removeBack() {
		if (total == 0)return;
		tail -= 1;
		if (tail == -1) {
			tail = size -1;
		}
		total--;
	}



	void view() {
		for (int i = 0; i < total; i++) {
			std::cout << list[(head + i) % size] << std::endl;
		}
	}


};