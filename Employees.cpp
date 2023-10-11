#include <iostream>
#include "Employees.h"
using namespace std;

// Function definitions for Professional Employee.
ProEmployee::ProEmployee(int payrate, int workhours) {
	payRate = payrate;
	workHours = workhours;
}

double ProEmployee::findWeeklySalary() {
	return ((double) payRate * 40);
}

double ProEmployee::findHealthCareContribution() {
	return (findWeeklySalary() / 7);
}

double ProEmployee::findVacationHours() {
	return (workHours / 10);
}

void ProEmployee::setWorkHours(int input) {
	workHours = input;
}

void ProEmployee::setPayRate(int input) {
	payRate = input;
}

// Function definitions for General Employee.
GenEmployee::GenEmployee(int payrate, int workhours) {
	payRate = payrate;
	workHours = workhours;
}

double GenEmployee::findWeeklySalary() {
	return (workHours * (double) payRate);
}

double GenEmployee::findHealthCareContribution() {
	return (findWeeklySalary() / 14);
}

double GenEmployee::findVacationHours() {
	return (workHours / 20);
}

void GenEmployee::setWorkHours(int input) {
	workHours = input;
}

void GenEmployee::setPayRate(int input) {
	payRate = input;
}
