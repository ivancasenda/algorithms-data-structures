#pragma once



class BST {
	class Node {
	public:
		//Node() {}
		Node(int item): item(item) {}
		int item;
		Node* parent = nullptr;
		Node* leftChild = nullptr;
		Node* rightChild = nullptr;
	};

	Node* root = nullptr;
	int size = 0;
	Node* getSuccessor(Node* node);


public:
	bool find(int item);
	bool insert(int item);
	bool remove(int item);
	void sortedPrint(Node* node);
	Node* getRoot();

};

