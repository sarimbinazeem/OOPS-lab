#include "Employee.h"
#include <iostream>
using namespace std;

void Employee::setEmployee(string n, int id,double sal, double hour)
{
	name = n;
	ID = id;
	salary = sal;
	hours = hour;
}

double Employee::calcRegularPay()
{
	if(hours<=40)
	{
		return hours*salary;
	}
	else
	{
		return 40*salary;
	}
}

double Employee::calcOvertimePay()
{
	if(hours>40)
	{
		return (hours-40)*salary*1.5;
	}
	else
	{
		return 0;
	}
}

double Employee::calcTotalSalary()
{
	return calcOvertimePay() + calcRegularPay();
}

double Employee::getTotalSalary() 
{
    return calcTotalSalary();
}

string Employee::getName() 
{
    return name;
}

void Employee::display()
{
	cout<<"Employee Name: "<<name<<endl;
	cout<<"Employee ID: "<<ID<<endl;
	cout<<"Employee Salary: "<<salary<<endl;
	cout<<"Hours Worked: "<<hours<<endl;
	cout<<"Regular Pay: "<<calcRegularPay()<<endl;
	cout<<"Overtime Pay: "<<calcOvertimePay()<<endl;
	cout<<"Total Salary: "<<getTotalSalary()<<endl;
}