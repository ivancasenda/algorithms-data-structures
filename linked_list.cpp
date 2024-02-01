#include <iostream>
#include "linked_list.h"

using namespace std;

int linkedListTest() {
	int choice = 0;
	int input;
	int index;
	LinkedList<int> list;
	while (choice != 4) {
		cout << "1.Insert\n2.View\n3.Remove\n4.Exit" << endl;
		cin >> choice;
		if (choice == 1) {
			cout << "Input number to be inserted: ";
			cin >> input;
			cin >> index;
			Node<int>* node = new Node<int>(input);
			cout << list.insert(node,index);
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

