#include <iostream>
#include "BST.h"

bool BST::insert(int item) {
	Node* itemNode = new Node(item);
	if (size == 0) {
		root = itemNode;
		size++;
		return true;
	}
	Node* current = root;
	while (current->item != item) {
		if (item < current->item) {
			if (current->leftChild == nullptr) {
				current->leftChild = itemNode;
				itemNode->parent = current;
				size++;
				return true;
			}
			else {
				current = current->leftChild;
			}
		}
		else{
			if (current->rightChild == nullptr) {
				current->rightChild = itemNode;
				itemNode->parent = current;
				size++;
				return true;
			}
			else {
				current = current->rightChild;
			}
		}
	}
	return false;
}

bool BST::find(int item) {
	if (size == 0) {
		return false;
	}
	Node* current = root;
	while (current->item != item) {
		if (item < current->item) {
			current = current->leftChild;
		}
		else{
			current = current->rightChild;
		}
		if (current == nullptr)return false;
	}
	return true;
}

BST::Node* BST::getSuccessor(Node* node) {
	if (node->rightChild != nullptr) {
		node = node->rightChild;
		while (node->leftChild != nullptr) {
			node = node->leftChild;
		}
		return node;
	}
	else {
		Node* parent = node->parent;
		while (parent->leftChild != node && parent != nullptr) {
			node = parent;
			parent = parent->parent;
		}
		return parent;
	}
}

BST::Node* BST::getRoot() {
	return root;
}

void BST::sortedPrint(Node* node) {
	if (node == nullptr)return;
	sortedPrint(node->leftChild);
	std::cout << node->item << std::endl;
	sortedPrint(node->rightChild);
}

bool BST::remove(int item) {
	if (size == 0) {
		return false;
	}
	Node* current = root;
	while (current->item != item) {
		if (item < current->item) {
			current = current->leftChild;
		}
		else {
			current = current->rightChild;
		}
		if (current == nullptr)return false;
	}
	if (current->leftChild == nullptr && current->rightChild == nullptr) {
		Node* parent = current->parent;
		if (parent == nullptr)root = nullptr;
		else if (parent->leftChild == current) {
			parent->leftChild = nullptr;
		}
		else {
			parent->rightChild = nullptr;
		}
		delete current;
	}
	else if (current->leftChild == nullptr || current->rightChild == nullptr) {
		Node* parent = current->parent;
		Node* child;
		if (current->rightChild == nullptr) {
			child = current->leftChild;
		}
		else {
			child = current->rightChild;
		}
		if (parent == nullptr) {
			root = child;
		}
		else if (parent->leftChild == current) {
			parent->leftChild = child;
		}
		else {
			parent->rightChild = child;
		}
		child->parent = parent;
		delete current;
	}
	else {
		Node* successor = getSuccessor(current);
		int temp = current->item;
		current->item = successor->item;
		Node* successorParent = successor->parent;
		if (successorParent->leftChild == successor) {
			successorParent->leftChild = successor->rightChild;
		}
		else {
			successorParent->rightChild = successor->rightChild;
		}
		if(successor->rightChild != nullptr)(successor->rightChild)->parent = successorParent;
		delete successor;
	}
	size--;
	return true;
}

void testBST() {
	int choice = 0;
	int input;
	BST tree;
	while (choice != 4) {
		std::cout << "1.Insert\n2.View\n3.Remove\n4.Exit" << std::endl;
		std::cin >> choice;
		if (choice == 1) {
			std::cout << "Input number to be inserted: ";
			std::cin >> input;
			std::cout << tree.insert(input) << std::endl;
		}
		else if (choice == 2) {
			std::cout << "Input number to be view: ";
			std::cin >> input;
			std::cout << tree.find(input) << std::endl;
			tree.sortedPrint(tree.getRoot());
		}
		else if (choice == 3) {
			std::cout << "Input number to be remove: ";
			std::cin >> input;
			std::cout << tree.remove(input) << std::endl;
		}
	}
}

