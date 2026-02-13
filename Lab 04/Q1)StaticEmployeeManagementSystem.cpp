	#include <iostream>
	using namespace std;
	
	class Employee
	{
		private:
			int ID=1001;
			string name;
			double salary;
			static int count;
			
		public:
			Employee(string name,double salary)
			{
				this->name = name;
				this->salary = salary;
				ID = 1001+count;
				count++;
			}
			
			 void display()
			{
				cout<<"Name: "<<name<<endl;
				cout<<"ID: "<<ID<<endl;
				cout<<"Salary: "<<salary<<endl;
			}
			
			static void countDisplay()
			{
				cout<<count<<" Objects Created So Far..."<<endl;
			}
	};
	
	int Employee::count=0;
	
	int main()
	{
		Employee e1("Sarim Bin Azeem",100000);
		Employee e2("Khizar Sheikh",50000);
		Employee e3("Vainkut Kumar",20000);
		Employee e4("Devish Kumar",1000);
		
		cout<<"\n======Employee Details======\n";
		cout<<"=====Employee 1=====\n";
		e1.display();
		cout<<endl;
		
		cout<<"=====Employee 2=====\n";
		e2.display();
		cout<<endl;
		
		cout<<"=====Employee 3=====\n";
		e3.display();
		cout<<endl;
		
		cout<<"=====Employee 4=====\n";
		e4.display();
		cout<<endl;
		
		Employee::countDisplay();
		cout<<endl;
		
		cout<<"Creating Object...\n";
		Employee e5("Izzah Salam",1000000);
		
		cout<<"=====Employee 5=====\n";
		e5.display();
		
		Employee::countDisplay();
		cout<<endl;
		
		return 0;
	}
