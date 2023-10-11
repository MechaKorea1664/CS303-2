#pragma once
#include <iostream>
using namespace std;

class Employee {
protected:
	int workHours;
	int payRate; // Monthly salary or hourly pay rate. Depends on employee type.
	int vacationHour;
	int healthCareContribution;
	virtual double findWeeklySalary() = 0;
	virtual double findHealthCareContribution() = 0;
	virtual double findVacationHours() = 0;
	virtual void setWorkHours(int) = 0;
	virtual void setPayRate(int) = 0;
};

class ProEmployee:public Employee {
public:
	ProEmployee(int, int);
	double findWeeklySalary() override;
	double findHealthCareContribution() override;
	double findVacationHours() override;
	void setWorkHours(int) override;
	void setPayRate(int) override;
};

class GenEmployee:public Employee {
public:
	GenEmployee(int, int);
	double findWeeklySalary() override;
	double findHealthCareContribution() override;
	double findVacationHours() override;
	void setWorkHours(int) override;
	void setPayRate(int) override;
};