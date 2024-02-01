#include <iostream>
#include "minHeap.h"

using namespace std;

void testMinHeap() {
	int choice = 0;
	int input;
	MinHeap list;
	while (choice != 4) {
		cout << "1.Insert\n2.View\n3.Remove\n4.Exit" << endl;
		cin >> choice;
		if (choice == 1) {
			cout << "Input number to be inserted: ";
			cin >> input;
			list.insert(input);
		}
		else if (choice == 2) {
			cout << list.peek() << endl;
		}
		else if (choice == 3) {
			list.pop();
		}
	}
}