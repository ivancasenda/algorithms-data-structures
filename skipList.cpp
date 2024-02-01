#include <iostream>
#include "skipList.h"

using namespace std;

int skipListTest() {
	int choice = 0;
	int input;
	SkipList<int> list(100);
	while (choice != 4) {
		cout << "1.Insert\n2.View\n3.Remove\n4.Exit" << endl;
		cin >> choice;
		if (choice == 1) {
			cout << "Input number to be inserted: ";
			cin >> input;
			Node<int>* node = new Node<int>(input);
			cout << list.insert(node);
		}
		else if (choice == 2) {
			list.view();
		}

		/*else if (choice == 2) {
			cout << "Input index to be view: ";
			cin >> input;
			cout << list.view(input) << endl;
		}
		else if (choice == 3) {
			cout << "Input index to be remove: ";
			cin >> input;
			cout << list.remove(input) << endl;
		}*/
	}
	return 0;
}