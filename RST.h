#pragma once

class RST {
	class Node {
	public:
		//Node() {}
		Node(int key, int priority) : key(key), priority(priority) {}
		int key;
		int priority;
		Node* parent = nullptr;
		Node* leftChild = nullptr;
		Node* rightChild = nullptr;
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
