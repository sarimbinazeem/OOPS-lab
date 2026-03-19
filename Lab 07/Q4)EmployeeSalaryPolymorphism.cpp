// A multinational corporation needs a payroll system that can handle different types of employees.
// The company has two main employee categories: Salaried Employees who receive a fixed
// monthly salary, and Commission Employees whose pay is calculated based on their sales
// performance.
// Design a payroll system where:
//  A base class Staff exists with a processSalary function
//  Two derived classes are created:
// o SalariedEmployee: Returns a fixed salary amount
// o CommissionEmployee: Calculates salary as a percentage of sales
//  The system must maintain a collection of Staff pointers to handle different employee
// types together
// When you call processSalary on any Staff pointer in your collection, the program must
// automatically execute the correct calculation logic based on the actual employee type.

#include <iostream>
using namespace std;

class Staff
{
    public:
        virtual double processSalary() =0;
        virtual void display() =0;
};

class SalariedEmployee: public Staff
{
    private:
        double salary;

    public:
        SalariedEmployee(double salary)
        {
            this->salary = salary;
        }

        double processSalary() override
        {
            return salary;
        }

        void display() override
        {
            cout<<"\n====Salaried  Employee====\n";
            cout<<"Salary: "<< processSalary() <<endl;
        }
        

};

class CommissionEmployee: public Staff
{
    private:
        double sales;
        double percentage;

    public:
        CommissionEmployee(double sales,double percentage)
        {
            this->sales = sales;
            this->percentage = percentage;

        }

        double processSalary() override
        {
            return sales*percentage;
        }

        void display() override
        {
            cout<<"\n====Commission  Employee====\n";
            cout<<"Salary: "<< processSalary() <<endl;
        }
        

};

int main()
{
    Staff** staff;
    staff = new Staff*[2];

    double salary,sales,percentage;

    cout<<"Enter Fixed Salary For Salaried Employee: ";
    cin>>salary;

    cout<<"Enter Sales Done By Commission Employee: ";
    cin>>sales;

    cout<<"Enter Percentage Comission Of Commission Employee ( 0.1 for 10%):: ";
    cin>>percentage;


    staff[0] = new SalariedEmployee(salary);
    staff[1] = new CommissionEmployee(sales,percentage);

    for(int i=0;i<2; i++)
    {
        staff[i]->display();
    }

    for(int i=0;i<2; i++)
    {
        delete staff[i];
    }

    delete[] staff;
    
    return 0;
}
