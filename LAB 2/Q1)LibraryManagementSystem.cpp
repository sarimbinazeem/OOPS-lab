//Question 1: 
// Create a book management system for a library. Each book has:
// ? Title
// ? Author
// ? Unique code
// ? Availability status (available or borrowed)
// The system must provide:
// 1. Book information management
// 2. Ability to borrow books (if available)
// 3. Ability to return borrowed books
// 4. Display book information with status
// 5. Search books by ISBN
// Write a program that:
// ? Stores information for multiple books
// ? Allows users to:
// o View all books
// o Borrow books by ISBN
// o Return books by ISBN
// ? Updates and displays book status after each operation

#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    int ISBN;

public:
    string title;
    string authour;
    bool status;
	
	int getCode()
	{
		return ISBN;	
	}
    void setInfo(string t, string auth, bool avail,int isbn) {
        title = t;
        authour= auth;
        status = avail;
        ISBN = isbn;
    }

    void borrow() {
        if(status) {
            status = false;
        } else {
            cout<<"Book Already Borrowed! \n";
        }
    }

    void returnBook() {
        if(!status) {
            status = true;
        } else {
            cout<<"Book Already Returned! \n";
        }
    }

    void display() {
        cout<<"Title: "<<title<<endl;
        cout<<"Authour: "<<authour<<endl;
        cout<<"Status: "<<(status? "Available":"Unavailable")<<endl;
        cout<<"ISBN: "<<ISBN<<endl;
    }
};


int main()
{
	int size,n,found;
	string t,auth;
	bool avail= true;
	int isbn;
	cout<<"Enter The Number Of Books To Add: ";
	cin>>size;
	
	Book *b;
	b = new Book[size];
	
	for(int i=0;i<size;i++)
	{
		cin.ignore();
		cout<<"\n---Book "<<i+1<<"---"<<endl;		
		cout<<"Enter Title: ";
		getline(cin,t);
		cout<<"Enter Authour: ";
		getline(cin,auth);
		cout<<"Enter ISBN: ";
		cin>>isbn;
		
		b[i].setInfo(t,auth,avail,isbn);
	}
	
	do
	{
		cout<<"\n=====Library Management System=====\n";
		cout<<"1.View Books\n";
		cout<<"2.Return Book\n";
		cout<<"3.Borrow Book\n";
		cout<<"0.Exit\n";
		cout<<"Which Operation To Perform? ";
		cin>>n;

		while(n<0 || n>3)
		{
			cout<<"Invalid Input! Enter Operation To Perform: ";
			cin>>n;
		}
		
		switch(n)
		{
			case 1:
				for(int i=0;i<size;i++)
				{
					cout<<"\n---Book "<<i+1<<"---"<<endl;
					b[i].display();
				}
				break;	
				
			case 2:
				cout<<"Enter ISBN of Book To Return: ";
				cin>>isbn;
				found =0;
				
				for(int i=0;i<size;i++)
				{
					if(b[i].getCode() == isbn)
					{
						b[i].returnBook();
						found =1;
						break;
					}
				}
				if(!found)
				{
					cout<<"Book Not Found! "<<endl;
				}
				break;	
				
				
			case 3:
				cout<<"Enter ISBN of Book To Borrow: ";
				cin>>isbn;
				found =0;
				
				for(int i=0;i<size;i++)
				{
					if(b[i].getCode() == isbn)
					{
						b[i].borrow();
						found =1;
						break;
					}
				}	
				if(!found)
				{
					cout<<"Book Not Found! "<<endl;
				}
				break;	
				
				
			case 0:
				cout<<"Exiting The Porgram...\n";	
				break;	
		}
	}while(n != 0);
		
	delete[] b;
	return 0;	
}