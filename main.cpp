#include <string>
#include <iostream>
#include "Employees.h"
#include "SingleLinkedList.cpp"

using namespace std;

int main() {
	cout << "==========[Single Linked List]==============================\n\n";
	cout << "The items being added to the Single Linked List <int> are: " << endl;
	cout << "{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}" << endl;
	Single_Linked_List<int> *intSLL = new Single_Linked_List<int>();
	int Sample[10] = {1,2,3,4,5,6,7,8,9,10};

	// Test push_front function (going backwards to keep numbers in order).
	for (int i = 4; i >= 0; i--) {
		intSLL->push_front(Sample[i]);
	}

	// Test push_back function.
	for (int i = 5; i < 10; i++) {
		intSLL->push_back(Sample[i]);
	}

	// Printing after push_front and push_back functions.
	cout << endl << "Single Linked List after push_front() and push_back():" << endl;
	Node<int>* currNode = intSLL->front();
	for (int i = 0; i < intSLL->length(); i++) {
		if (i > 0) cout << " -> ";
		cout << currNode->content;
		currNode = currNode->nextptr;
	}

	// Test pop_front fuction.
	intSLL->pop_front();

	// Test pop_back function.
	intSLL->pop_back();

	// Printing after pop_front and pop_back functions.
	cout << endl << endl << "Single Linked List after pop_front() and pop_back():" << endl;
	currNode = intSLL->front();
	for (int i = 0; i < intSLL->length(); i++) {
		if (i > 0) cout << " -> ";
		cout << currNode->content;
		currNode = currNode->nextptr;
	}

	// Testing front and back.
	cout << "\n\nTesting front():\n";
	cout << intSLL->front()->content << endl;
	cout << "\nTesting back():\n";
	cout << intSLL->back()->content << endl;
	
	// Testing empty
	cout << "\nTesting empty(): (0: false, 1: true)\n";
	cout << intSLL->empty() << endl << endl;

	// Testing insert
	cout << "Testing insert(), adding 1 to position 0." << endl;
	intSLL->insert(0, 1);
	cout << "Single Linked List after insert():" << endl;
	currNode = intSLL->front();
	for (int i = 0; i < intSLL->length(); i++) {
		if (i > 0) cout << " -> ";
		cout << currNode->content;
		currNode = currNode->nextptr;
	}

	// Testing remove
	cout << "\n\nTesting remove(), removing element at index 8." << endl;
	bool removeSuccess = intSLL->remove(8);
	cout << "Single Linked List after remove():" << endl;
	currNode = intSLL->front();
	for (int i = 0; i < intSLL->length(); i++) {
		if (i > 0) cout << " -> ";
		cout << currNode->content;
		currNode = currNode->nextptr;
	}
	cout << "\nremove() returned: " << removeSuccess << " (0: false, 1: true)" << endl;

	// Testing find
	cout << "\nFinding 5 from Single Linked List. Result: " << intSLL->find(5);
	cout << "\nFinding 11 from Single Linked List. Result: " << intSLL->find(11) << endl;

	// Employee classes testing.
	cout << "\n\n==========[Employee Classes]============================================\n\n";

	// Testing nonprofessional employee, hourly rate $25/h, worked hours 40h.
	cout << "Employee 1: Nonprofessional Employee.";
	cout << "\nHourly Rate: $25/h\tWork Hours: 40h.\n";
	cout << "________________________________________________________________________\n";
	GenEmployee* nonProfEmp = new GenEmployee(25, 40);
	cout << "Weekly Salary: \t\t\t" << nonProfEmp->findWeeklySalary();
	cout << "\nHealth Care Contributions: \t" << nonProfEmp->findHealthCareContribution() << " \t(Weekly Salary / 14)";
	cout << "\nVacation Hours: \t\t" << nonProfEmp->findVacationHours() << "h ("<<nonProfEmp->findVacationHours()/24<<"d)\t(Work Hours / 20)";

	// Testing nonprofessional employee, monthly rate $5500/mo, worked hours 40h.
	cout << "\n\nEmployee 2: Nonprofessional Employee.";
	cout << "\nMonthly Rate: $5500/mo\tWork Hours: 40h.\n";
	cout << "________________________________________________________________________\n";
	ProEmployee* proEmp = new ProEmployee(5500, 40);
	cout << "Weekly Salary: \t\t\t" << proEmp->findWeeklySalary();
	cout << "\nHealth Care Contributions: \t" << proEmp->findHealthCareContribution() << " \t(Weekly Salary / 7)";
	cout << "\nVacation Hours: \t\t" << proEmp->findVacationHours() << "h (" << proEmp->findVacationHours() / 24 << "d)\t(Work Hours / 10)\n";
	return 0;
}