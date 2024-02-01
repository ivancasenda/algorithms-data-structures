#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "RST.h"

bool RST::insert(int key) {
	srand(time(NULL));
	int priority = rand();
	Node* keyNode = new Node(key, priority);
	if (size == 0) {
		root = keyNode;
		size++;
		return true;
	}
	Node* current = root;
	while (current->key != key) {
		if (key < current->key) {
			if (current->leftChild == nullptr) {
				current->leftChild = keyNode;
				keyNode->parent = current;
				size++;
				while (keyNode != root && keyNode->priority > keyNode->parent->priority) {
					if (keyNode->parent->leftChild == keyNode) {
						avlRight(keyNode->parent);
					}
					else {
						avlLeft(keyNode->parent);
					}
				}
				return true;
			}
			else {
				current = current->leftChild;
			}
		}
		else {
			if (current->rightChild == nullptr) {
				current->rightChild = keyNode;
				keyNode->parent = current;
				size++;
				while (keyNode != root && keyNode->priority > keyNode->parent->priority) {
					if (keyNode->parent->leftChild == keyNode) {
						avlRight(keyNode->parent);
					}
					else {
						avlLeft(keyNode->parent);
					}
				}
				return true;
			}
			else {
				current = current->rightChild;
			}
		}
	}
	return false;
}

bool RST::find(int key) {
	if (size == 0) {
		return false;
	}
	Node* current = root;
	while (current->key != key) {
		if (key < current->key) {
			current = current->leftChild;
		}
		else {
			current = current->rightChild;
		}
		if (current == nullptr)return false;
	}
	return true;
}

RST::Node* RST::getSuccessor(Node* node) {
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

RST::Node* RST::getRoot() {
	return root;
}

void RST::sortedPrint(Node* node) {
	if (node == nullptr)return;
	sortedPrint(node->leftChild);
	std::cout << node->key << std::endl;
	sortedPrint(node->rightChild);
}

bool RST::remove(int key) {
	if (size == 0) {
		return false;
	}
	Node* current = root;
	while (current->key != key) {
		if (key < current->key) {
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
		int temp = current->key;
		current->key = successor->key;
		current->priority = successor->priority;
		Node* successorParent = successor->parent;
		if (successorParent->leftChild == successor) {
			successorParent->leftChild = successor->rightChild;
		}
		else {
			successorParent->rightChild = successor->rightChild;
		}
		if (successor->rightChild != nullptr)(successor->rightChild)->parent = successorParent;
		delete successor;
		
		while ((current->leftChild != nullptr || current->rightChild != nullptr)) {
			if (current->leftChild == nullptr) {
				if (current->priority > current->rightChild->priority)break;
				avlLeft(current);
			}
			else if (current->rightChild == nullptr) {
				if (current->priority > current->leftChild->priority)break;
				avlRight(current);
			}
			else {
				if (current->priority > current->rightChild->priority && current->priority > current->leftChild->priority)break;
				if (current->leftChild->priority < current->rightChild->priority) {
					avlLeft(current);
				}
				else {
					avlRight(current);
				}
			}
		}
	}
	size--;

	return true;
}

void RST::avlRight(Node* node) {
	Node* a = node->leftChild;
	Node* y = a->rightChild;
	Node* p = node->parent;
	if (p != nullptr && p->rightChild == node) {
		p->rightChild = a;
	}
	else if (p != nullptr && p->leftChild == node) {
		p->leftChild = a;
	}
	a->parent = p;
	if (a->parent == nullptr)root = a;
	a->rightChild = node;
	node->parent = a;
	if (y != nullptr)y->parent = node;
	node->leftChild = y;
}

void RST::avlLeft(Node* node) {
	Node* a = node->rightChild;
	Node* y = a->leftChild;
	Node* p = node->parent;
	if (p != nullptr && p->rightChild == node) {
		p->rightChild = a;
	}
	else if (p != nullptr && p->leftChild == node) {
		p->leftChild = a;
	}
	a->parent = p;
	if (a->parent == nullptr)root = a;
	a->leftChild = node;
	node->parent = a;
	if (y != nullptr)y->parent = node;
	node->rightChild = y;
}

void testRST() {
	int choice = 0;
	int input;
	RST tree;
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