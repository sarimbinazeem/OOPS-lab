//Create a base class Bank with an interest function, and two derived classes SavingsAccount
//and ;CurrentAccount that define their own interest rates (Savings: 5%, Current: 2%). In your
//main function, make the program execute the savings account interest logic when working with
//a SavingsAccount object through a Bank type reference.

#include <iostream>
using namespace std;

class Bank
{
	protected:
		double interest;
		
	public:
		Bank()
		{
			interest = 0;
		}
		
		virtual  void calcInterest(double amount)=0;
		virtual void display() =0 ;
};

class SavingAccount : public Bank
{
	public:
		SavingAccount() : Bank()
		{
			
		}
		
		void calcInterest(double amount)
		{
			interest = amount * 0.05;
		}
		
		void display()
		{
			cout<<"Savings Account Interest (5%): "<<interest<<endl;
		}
};

class CurrentAccount : public Bank
{
	public:
		CurrentAccount() :Bank()
		{
			
		}
		
		void calcInterest(double amount)
		{
			interest = amount * 0.02;
		}
				
		void display()
		{
			cout<<"Current Account Interest (2%): "<<interest<<endl;
		}		
		
};

int main()
{
	Bank *b;
	SavingAccount s;
	CurrentAccount c;
	
	b = &s;
	b->calcInterest(500);
	b->display();
	
	b = &c;
	b->calcInterest(100);
	b->display();
	
	
	
	return 0;
}
