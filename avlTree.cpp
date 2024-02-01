#include <iostream>
#include "avlTree.h"


bool AVLTree::find(int key) {
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

AVLTree::Node* AVLTree::getSuccessor(Node* node) {
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

AVLTree::Node* AVLTree::getRoot() {
	return root;
}

void AVLTree::sortedPrint(Node* node) {
	if (node == nullptr)return;
	sortedPrint(node->leftChild);
	std::cout << node->key << std::endl;
	sortedPrint(node->rightChild);
}

void AVLTree::avlRight(Node* node) {
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

void AVLTree::avlLeft(Node* node) {
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

bool AVLTree::insert(int key) {
	Node* keyNode = new Node(key);
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
				Node* previous = keyNode;
				bool knik = false;
				bool left = true;
				do {
					current->update();
					if (current->leftChild == previous && left == false) {
						knik = true;
						left = true;
					}
					else if (current->rightChild == previous && left == true) {
						knik = true;
						left = false;
					}
					if (current->balanceFactor < -1 || current->balanceFactor > 1) {
						if (!knik) {
							if (left)avlRight(current);
							else avlLeft(current);
						}
						else {
							current = keyNode->parent;
							if (keyNode->parent->leftChild == keyNode) {
								avlRight(keyNode->parent);
							}
							else {
								avlLeft(keyNode->parent);
							}
						}
						current->update();
					}
					previous = current;
					current = current->parent;
				} while (current != nullptr);
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
				Node* previous = keyNode;
				bool knik = false;
				bool left = false;
				do {
					current->update();
					if (current->leftChild == previous && left == false) {
						knik = true;
						left = true;
					}
					else if (current->rightChild == previous && left == true) {
						knik = true;
						left = false;
					}
					if (current->balanceFactor < -1 || current->balanceFactor > 1) {
						if (!knik) {
							if (left)avlRight(current);
							else avlLeft(current);
						}
						else {
							current = keyNode->parent;
							if (keyNode->parent->leftChild == keyNode) {
								avlRight(keyNode->parent);
							}
							else {
								avlLeft(keyNode->parent);
							}
						}
						current->update();
					}
					previous = current;
					current = current->parent;
				} while (current != nullptr);
				return true;
			}
			else {
				current = current->rightChild;
			}
		}
	}
	return false;
}

bool AVLTree::remove(int key) {
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
		bool left;
		if (parent == nullptr)root = nullptr;
		else if (parent->leftChild == current) {
			parent->leftChild = nullptr;
			left = true;
		}
		else {
			parent->rightChild = nullptr;
			left = false;
		}
		delete current;
		Node* previous = nullptr;
		current = parent;
		while(current != nullptr) {
			current->update();
			if (current->balanceFactor < -1 || current->balanceFactor > 1) {
				if (!left)avlRight(current);
				else avlLeft(current);
				current->update();
			}
			previous = current;
			current = current->parent;
		}
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
		Node* previous = nullptr;
		current = parent;
		while (current != nullptr) {
			current->update();
			if (current->balanceFactor < -1 || current->balanceFactor > 1) {
				if (current->leftChild == previous)avlRight(current);
				else avlLeft(current);
				current->update();
			}
			previous = current;
			current = current->parent;
		}
	}
	else {
		Node* successor = getSuccessor(current);
		int temp = current->key;
		current->key = successor->key;
		Node* successorParent = successor->parent;
		if (successorParent->leftChild == successor) {
			successorParent->leftChild = successor->rightChild;
		}
		else {
			successorParent->rightChild = successor->rightChild;
		}
		if (successor->rightChild != nullptr)(successor->rightChild)->parent = successorParent;
		delete successor;
		Node* previous = nullptr;
		current = successorParent;
		while (current != nullptr) {
			current->update();
			if (current->balanceFactor < -1 || current->balanceFactor > 1) {
				if (current->leftChild == previous)avlRight(current);
				else avlLeft(current);
				current->update();
			}
			previous = current;
			current = current->parent;
		}
	}
	size--;

	return true;
}

void testAVLTree() {
	int choice = 0;
	int input;
	AVLTree tree;
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