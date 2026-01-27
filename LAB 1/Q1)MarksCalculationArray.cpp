//Question 1:
//Scenario: You&#39;re developing a simple grade calculator for a school. The teacher wants to input
//marks for 5 subjects and see the total and average marks.
//Task: Write a C++ program that:
//1. Asks the teacher to enter marks for 5 subjects (out of 100)
//2. Stores these marks in an array
//3. Calculates and displays:
//▪ Total marks
//▪ Average marks
//▪ Whether the student passed (average ≥ 50)

#include <iostream>
using namespace std;

int main()
{
	int marks[5];
	int sum = 0;
	
	cout<<"Enter marks for 5 subjects: "<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<"Subject "<<i+1<<": ";
		cin>>marks[i];
	}
	
	for(int i=0;i<5;i++)
	{
		sum += marks[i];
	}
	
	double average = static_cast<double>(sum)/5;
	
	
	
	cout<<"=========Report Card========\n";
	cout<<"Total Marks: "<<sum<<endl;
	cout<<"Average: "<< average<<endl;
	if(average>=50)
	{
		cout<<"Result: PASS"<<endl;		
	}
	else
	{
		cout<<"Result: FAIL"<<endl;	
	}

    return 0;
}