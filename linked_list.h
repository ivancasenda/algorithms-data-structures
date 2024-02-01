#pragma once

template <typename T>
class Node {
public:
	T data;
	Node* next = NULL;
	Node* prev = NULL;
	Node(T data) : data(data){}
};

template <typename T>
class LinkedList {
	Node<T>* head;
	Node<T>* tail;
	int nodeTotal = 0;
	
public:
	bool insert(Node<T>* node, int index) {
		if (index < 0 || index > nodeTotal) {
			return false;
		}
		else if (nodeTotal == 0) {
			head = node;
			tail = node;
		}
		else if (index == 0) {
			node->next = head;
			head->prev = node;
			head = node;
		}
		else if (index == nodeTotal) {
			node->prev = tail;
			tail->next = node;
			tail = node;
		}
		else {
			Node<T>* curr = head;
			for (int i = 0; i < index; i++) {
				curr = curr->next;
			}
			node->next = curr;
			node->prev = curr->prev;
			(curr->prev)->next = node;
			curr->prev = node;
		}
		nodeTotal++;
		return true;
	}
	bool remove(int index) {
		if ((index < 0 && index > nodeTotal - 1 ) || nodeTotal == 0) {
			return false;
		}
		else if (nodeTotal == 1) {
			delete head;
		}
		else if (index == 0) {
			head = head->next;
			delete head->prev;
			head->prev = NULL;
		}
		else if (index == nodeTotal - 1) {
			tail = tail->prev;
			delete tail->next;
			tail->next = NULL;
		}
		else {
			Node<T>* curr = head;
			for (int i = 0; i < index; i++) {
				curr = curr->next;
			}
			(curr->prev)->next = curr->next;
			(curr->next)->prev = curr->prev;
			delete curr;
		}
		nodeTotal--;
		return true;
	}
	T view(int index) {
		if (index > -1 && index < nodeTotal) {
			Node<T>* curr = head;
			for (int i = 0; i < index; i++) {
				curr = curr->next;
			}
			return curr->data;
		}
		return -1;	
	}

	void push(T data) {
		Node<T>* node = new Node<T>(data);
		insert(node, 0);
	}

	T pop() {
		T data = view(nodeTotal);
		remove(nodeTotal);
		return data;
	}

	int size() {
		return nodeTotal;
	}

};
