#include <string>
#include <iostream>
#include "Employees.h"
#include "SingleLinkedList.cpp"

using namespace std;

int main() {
	Single_Linked_List<int> *intSLL = new Single_Linked_List<int>();

	int Sample[10] = {1,2,3,4,5,6,7,8,9,10};
	// Test push_front function
	for (int i = 4; i >= 0; i--) {
		intSLL->push_front(Sample[i]);
	}

	// Test push_back function.
	for (int i = 5; i < 10; i++) {
		intSLL->push_back(Sample[i]);
	}

	// Test pop_front fuction.


	// Print the current list.
	Node<int>* currNode = intSLL->front();
	for (int i = 0; i < intSLL->numItems; i++) {
		cout << currNode->content << endl;
		currNode = currNode->nextptr;
	}
	
	return 0;
}