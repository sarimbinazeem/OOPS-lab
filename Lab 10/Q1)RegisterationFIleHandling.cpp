//A university needs to maintain a continuous list of workshop attendees. Write a program that
//prompts the user for a name and email address and saves this data into a file named signup.txt.
//You must ensure that every time the program runs, it does not delete previous registrations but adds
//the new ones to the end of the file.

#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

int main()
{
	string name, email;

	cout<<"Enter Name: ";
	getline(cin,name);
	
	cout<<"Enter Email: ";
	getline(cin,email);
	
	//Open file in append mode so we can error handle
	ofstream file("signup.txt",ios::app);
	
	if(!file)
	{
		cout<<"Error in Opening File!"<<endl;
		return 1;
	}
	
	file<<"Name: "<<name<<",Email: "<<email<<endl;
	file.close();
	
	cout<<"Registered Saved Successfully!\n";
	
	return 0;
}
