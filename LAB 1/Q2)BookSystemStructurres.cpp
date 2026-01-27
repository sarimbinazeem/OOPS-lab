// Question 2:
//Scenario: You Are creating a simple system for a small library to track book information.
//Task: Write a C++ program using structures to:
//1. Create a Book structure with:
//? Book ID (integer)
//? Book Title (string)
//? Author Name (string)
//? Price (float)
//2. Take input for 3 books
//3. Display all book information
//4. Calculate and display the total price of all books

#include <iostream>
#include <string>
using namespace std;

typedef struct
{
    int ID;
    string title;
    string name;
    float price;
} Book;

int main()
{
    float sum = 0;
    Book b[3];

    cout << "Enter Details: " << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "=====Book " << i + 1 << "=======\n";
        cout << "Enter ID: ";
        cin >> b[i].ID;
        cin.ignore(); // clear buffer (getch() of c++)

        cout << "Enter Title: ";
        getline(cin, b[i].title);

        cout << "Enter Authour Name: ";
        getline(cin, b[i].name);

        cout << "Enter Price: ";
        cin >> b[i].price;
    }

    cout << "\nAll Books: \n" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "=====Book " << i + 1 << "=======\n";
        cout << "ID: " << b[i].ID << endl;
        cout << "Title: " << b[i].title << endl;
        cout << "Authour Name: " << b[i].name << endl;
        cout << "Enter Price: " << b[i].price << endl;
    }

    for (int i = 0; i < 3; i++)
    {
        sum += b[i].price;
    }

    cout << "Total Price Of The Books: " << sum << endl;

    return 0;
}
