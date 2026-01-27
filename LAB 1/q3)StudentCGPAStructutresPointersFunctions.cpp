// Scenario: A college wants to analyze student performance across multiple semesters.
// Task: Write a C++ program that:
// 1. Uses a structure Student containing:
// ? Roll Number
// ? Name
// ? Marks in 3 subjects (array of 3 integers)
// ? CGPA (float)
// 2. Uses dynamic memory allocation to create an array of Student structures
//    (ask user how many students to enter)
// 3. Write functions for:
// ? Input student details
// ? Calculate CGPA (Assume: CGPA = total marks/30)
// ? Display all students with CGPA = 3.0
// ? Find and display top performer
// 4. Use pointers to manipulate the student array
// 5. Properly deallocate memory at the end

#include <iostream>
#include <string>

using namespace std;

typedef struct
{
    int roll;
    string name;
    int marks[3];
    float CGPA;

} Student;

void input(Student *s)
{
    cout<<"Enter Roll Number: ";
    cin>>s->roll;
    
    cout<<"Enter Name: ";
    cin.ignore();
    getline(cin, s->name);
    
    for(int i=0;i<3;i++)
    {
    	cout << "Enter marks of subject " << i + 1 << ": ";
    	cin>>s->marks[i];
	}
}

void gpaCalc(Student *s)
{
	int sum=0;
	for(int i=0;i<3;i++)
    {
    	sum += s->marks[i];
	}
	s->CGPA=sum/30.0;
	
}

void display(Student *s, int n)
{
	cout<<"Students With More Than 3.0 GPA"<<endl;
	for(int i=0;i<n;i++)
    {
    	if(s[i].CGPA>=3.0)
    	{
    		cout<<"Roll Number: "<<s[i].roll<<endl;
    		cout<<"Name: "<<s[i].name<<endl;
    		cout<<"CGPA Calculated: "<<s[i].CGPA<<endl;
		}
	}
	
	
}

void topPerformer(Student *s, int n)
{
	int top=0;
	
	for(int i=1;i<n;i++)
	{
		if(s[i].CGPA > s[top].CGPA)
		{
			top = i;
		}
	}
	
	cout<<"\n Top Performer is: "<<endl;
	cout<<"Roll Number: "<<s[top].roll<<endl;
	cout<<"Name: "<<s[top].name<<endl;
	cout<<"CGPA: "<<s[top].CGPA<<endl;
}

int main()
{
    int n;

    cout << "How Many Users To Enter: ";
    cin >> n;

    Student *s = new Student[n];

	for(int i=0;i<n;i++)
	{
		cout<<"Enter Details For Student "<<i+1<<": "<<endl;
   		 input(&s[i]);	
		 gpaCalc(&s[i]);		
	}

	display(s,n);
	topPerformer(s,n);
	
	delete[] s;
    return 0;
}
