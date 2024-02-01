#include "circularArray.h"

using namespace std;



void testCircularArray() {
	int choice = 0;
	int input;
	CircularArray<int> list;
	while (choice != 4) {
		cout << "1.Insert\n2.View\n3.Remove\n4.Exit" << endl;
		cin >> choice;
		if (choice == 1) {
			cout << "Input number to be inserted: ";
			cin >> input;
			cout << "Input index: ";
			int index;
			cin >> index;
			list.insertIndex(input, index);
		}
		else if (choice == 2) {
			list.view();
		}
		else if (choice == 3) {
			list.removeFront();
		}
	}
}

