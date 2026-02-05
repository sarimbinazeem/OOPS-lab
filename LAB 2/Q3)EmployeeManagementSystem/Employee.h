#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
using namespace std;

class Employee
{
    private:
	  	double salary;
      	double hours;
   	   	string name;
    	int ID;
    	
    public:   
       void setEmployee(string n, int id, double sal, double hour);
       double calcRegularPay();
       double calcOvertimePay();
       double calcTotalSalary();
       void display();
       double getTotalSalary();
       string getName();
};

#endif