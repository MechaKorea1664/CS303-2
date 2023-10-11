#pragma once
#include <string>
#include <iostream>

using namespace std;

template <typename Item_Type>
struct Node {
	Item_Type content;
	Node* nextptr;
	Node(const Item_Type& value) : content(value), nextptr(nullptr) {}
};

template <typename Item_Type>
class Single_Linked_List {
	protected:
		Node<Item_Type>* head;
		Node<Item_Type>* tail;
		size_t numItems;

	public:
		Single_Linked_List<Item_Type>();
		void push_front(Item_Type);
		void push_back(Item_Type);
		void pop_front();
		void pop_back();
		Node<Item_Type>* front();
		Node<Item_Type>* back();
		bool empty();
		void insert(size_t index, const Item_Type& item);
		bool remove(size_t index);
		size_t find(const Item_Type& item);
		size_t length();
};