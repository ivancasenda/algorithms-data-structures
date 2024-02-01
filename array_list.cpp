#include <iostream>
#include "array_list.h"

using namespace std;

template <typename T>
bool ArrayList<T>::append(int index, T item) {
	if (index < 0 && index > this->lastIndex) {
		return false;
	}
	if (this->lastIndex == this->length) {
		std::cout << "Full" << std::endl;
		T* list2 = new int[2 * this->length];
		for (int i = 0; i < this->lastIndex; i++) {
			list2[i] = list1[i];
		}
		delete[] list1;
		list1 = list2;
		this->length *= 2;
	}
	if (index == lastIndex) {
		list1[index] = item;
	}
	else {
		for (int i = lastIndex; i > index; i--) {
			list1[i] = list1[i - 1];
		}
		list1[index] = item;
	}
	this->lastIndex++;
	return true;
}

template <typename T>
bool ArrayList<T>::insert(int index, T item ){
	if (index < 0 && index > this->lastIndex) {
		return false;
	}
	
	if (index == lastIndex) {
		if (this->lastIndex == this->length) {
			std::cout << "Full" << std::endl;
			T* list2 = new int[2 * this->length];
			for (int i = 0; i < this->lastIndex; i++) {
				list2[i] = list1[i];
			}
			delete[] list1;
			list1 = list2;
			this->length *= 2;
		}
		list1[index] = item;
		lastIndex++;
	}
	else {
		list1[index] = item;
	}
	return true;
}

template <typename T>
T ArrayList<T>::view(int index) {
	if (index > -1 && index < this->lastIndex) {
		return list1[index];
	}
	return -1;
}

template <typename T>
bool ArrayList<T>::remove(int index) {
	if (index < 0 && index >= this->lastIndex) {
		return false;
	}
	for (int i = index; i < this->lastIndex; i++) {
		list1[i] = list1[i + 1];
	}
	this->lastIndex--;
	return true;
}



int arrayListTest() {
	int choice = 0;
	int input;
	int index;
	ArrayList<int> list;
	while (choice != 4) {
		cout << "1.Insert\n2.View\n3.Remove\n4.Exit" << endl;
		cin >> choice;
		if (choice == 1) {
			cout << "Input number to be inserted: ";
			cin >> input;
			cin >> index;
			list.insert(index, input);
		}
		else if (choice == 2) {
			cout << "Input index to be view: ";
			cin >> input;
			cout << list.view(input) << endl;
		}
		else if (choice == 3) {
			cout << "Input index to be remove: ";
			cin >> input;
			cout << list.remove(input) << endl;
		}
	}
	return 0;
}

