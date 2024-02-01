#pragma once

template <typename T>
class ArrayList {
	int length = 5;
	T* list1 = new T[5];
	int lastIndex = 0;

public:
	~ArrayList() {
		delete[] list1;
	}
	bool insert(int index, T item);
	bool append(int index, T item);
	bool remove(int index);
	T view(int index);
};

