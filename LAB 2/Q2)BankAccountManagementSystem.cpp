// Create a banking system that manages accounts with:
// ? Account number
// ? Account holder name
// ? Current balance
// The system must support these operations:
// 1. Deposit money into account
// 2. Withdraw money from account
// 3. Check current balance
// 4. Display account information
// 5. Validate all transactions (no negative deposits, no overdrafts)
// Rules:
// ? Account balance cannot go negative
// ? Withdrawal amount must be = current balance
// ? Deposit amount must be positive

// Write a program that:
// ? Creates a bank account with initial details
// ? Performs multiple transactions (deposits and withdrawals)
// ? Displays results of each transaction
// ? Shows final account status

#include <iostream>
#include <string>
using namespace std;

class Account
{
private:
    int accNum;
    string accName;
    double balance;

public:
    void setAccount(int num, string name, double money)
    {
        accNum = num;
        accName = name;
        balance = money;
    }

    void deposit(double money)
    {
        if (money > 0)
        {
            balance += money;
        }
        else
        {
            cout << "Invalid Money Deposited! \n";
        }
    }

	void withdraw(double money)
	{
	    if (money <= 0)
   		 {
        	cout << "Invalid Withdrawal Amount!\n";
    	}
    	else if (money > balance)
    	{
        	cout << "Money Exceeded Balance!\n";
    	}
    	else
    	{
       		 balance -= money;
    	}
}

    void checkBalance()
    {
        cout << "Current Balance: " << balance << endl;
    }

    void display()
    {
        cout <<"Account Number: "<<accNum<<endl;
        cout <<"Account Holder Name: "<<accName<<endl;
        cout << "Current Balance: " << balance << endl;
    }
};

int main()
{
	Account a;
	string name;
	int number,operation,n;
	double money,bal;
	
	cout<<"Enter Account Holder Name: ";
	getline(cin,name);
	
	cout<<"Enter Account Number: ";
	cin>>number;
	
	cout<<"Enter Initial Balance: ";
	cin>>money;
	
	a.setAccount(number,name,money);


	do
	{

		cout<<"\n=====Bank Account====\n";
		cout<<"1.Deposit\n";
		cout<<"2.Withdraw\n";
		cout<<"0.Exit\n";
		cout<<"Which Operation To Perform? ";
		cin>>n;

		while(n<0 || n>2)
		{
			cout<<"Invalid Input! Enter Operation To Perform: ";
			cin>>n;
		}
		
		switch(n)
		{
			case 1:

				cout<<"Enter Money To Deposit: ";
				cin>>bal;
				a.deposit(bal);
				a.checkBalance();
				break;
				
				
			case 2:
				cout<<"Enter Money To Withdraw: ";
				cin>>bal;
				a.withdraw(bal);
				a.checkBalance();	
				break;
				
				
			case 0:
				cout<<"Exiting...\n";	
				break;	
		}
	}while(n != 0);
	
	cout<<"\n=====Final Account Summary====="<<endl;
	a.display();
    return 0;
}
