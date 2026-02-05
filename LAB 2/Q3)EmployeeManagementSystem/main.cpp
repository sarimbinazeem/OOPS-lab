//Question 3:
// Design an employee payroll system using separate files. Each employee has:
//  Name
//  Employee ID
//  Base salary
//  Hours worked
// The system calculates:
// 1. Regular pay (based on base salary)
// 2. Overtime pay (if hours &gt; 40, at 1.5× rate)
// 3. Total salary
// 4. Employee information display
// Requirements:
//  Implement using header file and separate implementation file
//  Calculate overtime correctly
//  Compare employee salaries
//  Display comprehensive payroll information

// #include <iostream>
#include "Employee.h"
using namespace std;

int main()
{
	Employee e1,e2;
	
	e1.setEmployee("Sarim Bin Azeem",1234,12000,10);
	e2.setEmployee("Khizar Sheikh",5678,1000,50);
	
	cout<<"\n==========Employees Information==========\n";
	e1.display();
	cout<<endl;
	e2.display();
	cout<<endl;
	
	
	if(e1.getTotalSalary()>e2.getTotalSalary())
	{
		cout<<e1.getName()<<" has higher salary than " <<e2.getName()<<endl;
	}
	else if(e2.getTotalSalary()>e1.getTotalSalary())
	{
		cout<<e2.getName()<<" has higher salary than " <<e1.getName()<<endl;		
	}
	else
	{
		cout<<e1.getName()<<" and "<<e2.getName()<<" has same salary"<<endl;				
	}
}