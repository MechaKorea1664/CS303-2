#include "SingleLinkedList.h"
#include <string>
#include <iostream>

using namespace std;

template <typename Item_Type>
Single_Linked_List<Item_Type>::Single_Linked_List() {
	head = nullptr;
	tail = nullptr;
	numItems = 0;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(Item_Type newContent) {
	Node<Item_Type>* node = new Node<Item_Type>(newContent);
	if (head == nullptr) {
		head = node;
		tail = node;
	}
	else {
		node->nextptr = head;
		head = node;
	}
	numItems++;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(Item_Type newContent) {
	Node<Item_Type>* node = new Node<Item_Type>(newContent);
	if (head == nullptr) {
		head = node;
		tail = node;
	}
	else {
		tail->nextptr = node;
		tail = node;
	}
	numItems++;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_front() {
	if (head == nullptr) {
		return;
	}
	else {
		Node<Item_Type>* tempNode = head;
		if (head->nextptr != nullptr) {
			head = head->nextptr;
		}
		else {
			head = nullptr;
			tail = nullptr;
		}
		delete tempNode;
		numItems--;
	}
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_back() {
	if (head == nullptr) {
		return;
	}
	else {
		if (head == tail) {
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		else {
			Node<Item_Type>* nextNode = head;
			while (nextNode->nextptr != tail) {
				nextNode = nextNode->nextptr;
			}
			Node<Item_Type>* tempNode = tail;
			tail = nextNode;
			delete tempNode;
		}
		numItems--;
	}
}

template <typename Item_Type>
Node<Item_Type>* Single_Linked_List<Item_Type>::front() {
	return head;
}

template <typename Item_Type>
Node<Item_Type>* Single_Linked_List<Item_Type>::back() {
	return tail;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type& item) {
	Node<Item_Type> *node = new Node<Item_Type>(item);
	if (index >= numItems) {
		cout << "Index out of range." << endl;
		return;
	}
	else if (index == 0) {
		node->nextptr = head;
		head = node;
		numItems++;
	}
	else if (index < numItems) {
		Node<Item_Type>* currNode = head;
		for (int i = 1; i < index; i++) {
			currNode = currNode->nextptr;
		}
		Node<Item_Type>* tempNode = currNode->nextptr;
		currNode->nextptr = node;
		node->nextptr = tempNode;
		tempNode = nullptr;
		numItems++;
	}
}
template <typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index) {
	if (index >= numItems) {
		cout << "Index out of range." << endl;
		return false;
	}
	else if (index == 0) {
		Node<Item_Type>* tempNode = head;
		head = head->nextptr;
		delete tempNode;
		numItems--;
	}
	else {
		Node<Item_Type>* nextNode = head;
		for (int i = 1; i < index; i++) {
			nextNode = nextNode->nextptr;
		}
		Node<Item_Type>* tempNode = nextNode->nextptr;
		nextNode->nextptr = tempNode->nextptr;
		delete tempNode;
		numItems--;
	}
	return true;
}
template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) {
	Node<Item_Type>* currNode = head;
	for (int i = 0; i < numItems; i++) {
		if (currNode->content == item) return i;
		if (currNode->nextptr != nullptr) currNode = currNode->nextptr;
	}
	return string::npos;
}