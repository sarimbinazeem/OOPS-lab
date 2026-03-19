// A company needs a payroll system to process salaries for different types of staff members. The
// company has Contractors who are paid based on hours worked, and FullTimeEmployees
// who receive a fixed monthly salary plus a bonus. You must manage all staff members in a single
// unified container. When the payroll runs, the system must automatically apply the correct salary
// calculation for each individual without manually checking their job title or using conditional
// statements.
// 1. Create a base class Staff with a calculateSalary function
// 2. Create two derived classes:
// o Contractor: Accepts hours worked and hourly rate, returns hours × rate
// o FullTimeEmployee: Accepts base salary and bonus, returns base + bonus
// 3. In the main function:
// o Create a single collection of Staff pointers
// o Add at least one Contractor and one FullTimeEmployee
// o Loop through the collection and call calculateSalary for each
// o Display each staff member&#39 v;s calculated salary


#include <iostream>
using namespace std;

class Staff
{
	public:
		virtual double calculateSalary() = 0;
		virtual void display() = 0;
		
};

class Contractor : public Staff
{
	private:
		double hours;
		double rate;
	
	public:
		Contractor(double hours , double rate)
		{
			this->hours = hours;
			this->rate = rate;
		}
		
		double calculateSalary() override
		{
			return hours * rate;
		}
		
		void display() override
		{
			cout<<"\n========Contractor========\n";
			cout<<"Salary: "<< calculateSalary()<<endl;
		}
};

class FullTimeEmployee : public Staff
{
	private:
		double base;
		double bonus;
	
	public:
		FullTimeEmployee(double base , double bonus)
		{
			this->base = base;
			this->bonus = bonus;
		}
		
		double calculateSalary() override
		{
			return base + bonus;
		}
		
		void display() override
		{
			cout<<"\n========Full Time Employee========\n";
			cout<<"Salary: "<< calculateSalary()<<endl;
		}
};


int main()
{
	Staff **staff;
	
	staff = new Staff*[2];

	double base,bonus,rate,hours;

	cout<<"Enter Base Salary Of Full Time Employee: ";
	cin>>base;

	cout<<"Enter Bonus Salary Of Full Time Employee: "; 
	cin>>bonus;

	cout<<"Enter Hourly Rate Of Contractor: ";
	cin>>rate;

	cout<<"Enter Hours Worked By Contractor: ";
	cin>>hours;

	staff[0] = new Contractor(hours,rate);
	staff[1] = new FullTimeEmployee(base,bonus);

	for(int i=0;i<2;i++)
	{
		staff[i]->display();
	}

	for(int i=0;i<2;i++)
	{
		delete staff[i];
	}

	delete[] staff;

	return 0;
}
