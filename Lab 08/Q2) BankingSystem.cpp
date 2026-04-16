/*A Banking System manages accounts with different types of transactions. Each account has a
balance (double) and can perform deposits and withdrawals. To simplify operations, the system
allows:
1. Adding balances of two accounts (+ operator).
2. Transferring an amount from one account to another (-= operator).
3. Comparing two accounts to check which has a higher balance (&gt; operator).
4. Displaying account details using stream insertion (&lt;&lt; operator).
Attributes and Function Prototypes:
Attributes:
 accountNumber (string) → Unique identifier for the account.
 accountHolder (string) → Name of the account owner.
 balance (double) → Current account balance.
Function Prototypes and Their Purpose:
Account operator+(const Account &amp;); // Adds balances of two accounts.
Account &amp;operator-=(double amount); // Transfers amount from one account.
bool operator&gt;(const Account &amp;); // Compares two accounts&#39; balances.
friend ostream &amp;operator&lt;&lt;(ostream &amp;, const Account &amp;); // Displays account details.
Sample Input &amp; Expected Output:
Sample Input:
Account 1: John Doe, Balance: 5000
Account 2: Alice Smith, Balance: 3000
Performing:
1. Adding Account 1 and Account 2 balances.
2. Transferring 2000 from Account 1 to Account 2.
3. Checking which account has a higher balance.
4. Displaying final account details.

PROGRAMMING TASKS FOR LAB # 08

March 27, 2026

Lab 08 – Introduction to Friend Classes, Friend Functions, &amp;
Operator Overloading

Student Name: ___________________________ Roll No: ________________ Section: BCS-2E

1

Department of Computer Science
Miss Izzah Salam Lab 08: Introduction to Friend Classes, Friend
Functions, and Operator Overloading

Expected Output:
Total Balance (After Addition): 8000
After Transfer:
John Doe&#39;s New Balance: 3000
Alice Smith&#39;s New Balance: 5000
Comparison:
John Doe has less balance than Alice Smith.
Final Account Details:
Account Number: 101 | Holder: John Doe | Balance: $3000
Account Number: 102 | Holder: Alice Smith | Balance: $5000*/

#include <iostream>
using namespace std;

class BankingSystem
{
	private:
		string accountNumber;
		string accountHolder;
		double balance;
		
	public:
		BankingSystem(string num,string name, double bal) : accountNumber(num), accountHolder(name), balance(bal)
		{
			
		}
		
		BankingSystem operator+ (const BankingSystem &obj)
		{
			return BankingSystem("001","Combined Account",this->balance + obj.balance);
		}
		
		BankingSystem& operator -= (const double amount)
		{
			if(amount<= balance)
			{
				balance -= amount;
			}
			else
			{
				cout<<"Insufficient Balance!\n";
			}
			return *this;
		}
		
		bool operator > (const BankingSystem &other){
			return this->balance > other.balance;
		}
		
		friend ostream& operator <<(ostream &out, const BankingSystem&a);
		
		void deposit (double amount)
		{
			balance += amount;
		}
		
		string getName()
		{
			return accountHolder;
		}
		
		double getBalance()
		{
			return balance;
		}

};

ostream& operator <<(ostream &out, const BankingSystem&a)
{
	out<<"\n====Account Details====\n";
	out<<"Account Number: "<<a.accountNumber<<"| Holder: "<<a.accountHolder<<"|  Balance: "<<a.balance<<endl;
	
	return out;
	
}

int main()
{
	BankingSystem acc1("101", "John Doe",100000);
	BankingSystem acc2("102", "Alice Smith",5000000);
	
	cout<<"\n====Account 1 Details===\n";
	cout << acc1;
	cout<<endl;
	
	cout<<"\n====Account 2 Details===\n";
	cout << acc2;
	cout<<endl;
	
	BankingSystem total = acc1 + acc2;
	
	cout << "Total Balance (After Addition): " << total.getBalance() << endl;
	
	cout<<"\n====Transfering Money===\n";
	acc1 -= 2000;
	acc2.deposit(2000);
	
    cout << acc1.getName() <<" New Balance: " << acc1.getBalance() << endl;
    cout << acc2.getName() <<"  New Balance: " << acc2.getBalance() << endl;
    
    cout<<"Comparision: \n";
	if(acc1 > acc2)
	{
		cout<< acc1.getName() <<" has more balance than "<< acc2.getName() << endl;
	}
	else if ( acc2 > acc1)
	{
		
		cout<< acc2.getName() <<" has more balance than "<< acc1.getName() << endl;

	}
	else
	{
		cout<< acc1.getName() <<" has same balance as "<< acc2.getName() << endl;
	}
	
	cout<<"\n===Final Account Details===\n";
	cout<<acc1<<endl;
	cout<<acc2<<endl;
}
