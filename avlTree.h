#pragma once


class AVLTree {
	class Node {
		int max(int a, int b) {
			if (a > b) {
				return a;
			}
			else {
				return b;
			}
		}
	public:
		Node(int key) : key(key) {}
		int key;
		int height = 0;
		int balanceFactor = 0;
		Node* parent = nullptr;
		Node* leftChild = nullptr;
		Node* rightChild = nullptr;
		void update() {
			if (leftChild == nullptr && rightChild == nullptr) {
				height = 0;
				balanceFactor = 0;
			}
			else if (leftChild == nullptr || rightChild == nullptr) {
				if (leftChild == nullptr) {
					height = rightChild->height + 1;
					balanceFactor = rightChild->height + 1;
				}
				else {
					height = leftChild->height + 1;
					balanceFactor = leftChild->height + 1;
				}
			}
			else {
				height = max(leftChild->height, rightChild->height) + 1;
				balanceFactor = (rightChild->height + 1) - (leftChild->height + 1);
			}
		}
	};

	Node* root = nullptr;
	int size = 0;
	Node* getSuccessor(Node* node);
	void avlRight(Node* node);
	void avlLeft(Node* node);

public:
	bool find(int item);
	bool insert(int key);
	bool remove(int item);
	void sortedPrint(Node* node);
	Node* getRoot();

};