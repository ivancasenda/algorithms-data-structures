#pragma once

#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <iostream>

template <typename T>
class Node {
	
	int height;
public:
	T data;
	int *next;
	Node(T data) : data(data) {}
	Node() {}
	~Node() {
		delete[] next;
	}
	T getData() {
		return data;
	}
	int getHeight() {
		return this->height;
	}
	void setHeight(int height) {
		this->height = height;
		next = new int[height] {NULL};
	}
};

template <typename T>
class SkipList {
	Node<T>* head;
	int nodeTotal = 0;
	int estimatedTotal;
	int maxHeight;
	double probability;

public:
	SkipList(int estimatedTotal): estimatedTotal(estimatedTotal) {
		probability = 0.4;
		maxHeight = std::floor(std::log(estimatedTotal) / std::log(1 / probability));
		head = new Node<int>(0);
		head->setHeight(maxHeight);
	}
	bool insert(Node<T>* node) {
		Node<T>* current = head;
		int layer = head->getHeight() - 1;
		int* toFix = new int[maxHeight];
		while (layer >= 0) {
			Node<T>* node1 = (Node<T>*) (current->next[layer]);
			if (node1 == NULL) {
				toFix[layer] = (int) current;
				layer -= 1;
			}
			else if(node1->getData() > node->getData()) {
				toFix[layer] = (int)current;
				layer -= 1;
			}
			else {
				current = (Node<T>*) current->next[layer];
			}
			if (current->getData() == node->getData())return true;
		}
		
		int newHeight = 0;
		srand(time(NULL));
		while (newHeight < maxHeight - 1) {
			double random = (double)rand() / RAND_MAX;
			if (random <= probability) {
				newHeight++;
			}
			else {
				break;
			}
		}
		node->setHeight(newHeight);
		
		for (int i = 0; i <= newHeight; i++) {
			Node<T>* node2 = (Node<T>*) toFix[i];
			node->next[i] = node2->next[i];
			node2->next[i] = (int) node;

			Node<T>* node3 = (Node<T>*) node2->next[i];
			std::cout << node3->getData() << std::endl;
		}
		delete[] toFix;
		nodeTotal++;
		return true;
	}
	void view() {
		Node<T>* current = this->head;
		int layer = head->getHeight() -1;
		while (layer >= 0) {
			std::cout << current->getData() << std::endl;
			Node<T>* node1 = (Node<T>*) (current->next[layer]);
			if ( node1 == NULL) {
				layer -= 1;
			}
			else {
				current = (Node<T>*) current->next[layer];
			}
		}
	}
	/*bool remove(int index) {
		if ((index < 0 && index > nodeTotal - 1) || nodeTotal == 0) {
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
	}*/
};