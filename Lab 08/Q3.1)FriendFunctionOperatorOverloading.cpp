/*TASK # 03
Question 1: Can a friend function be used to overload an operator that modifies the
invoking object?
Problem Statement:
Consider the += operator, which modifies the left-hand operand. Can a friend function be used
to overload this operator?
? If yes, how should it be implemented?
? If no, what alternative approach should be used?
Justify your answer with supporting C++ code.
*/


/* Explanation:
Yes, a friend function can be used to overload an operator that modifies the left-hand operand (invoking object).

A friend function is a non-member function so it lacks a "this" pointer. Therefore we need to explicitely mention invoking object as left hand operand

By passing the refrence of object, the friend function can directly modify it.

Implementation:
Left operand have invoking object
Right operand have const refrence
Return type should be of refrence to allow chaining

Limitations:
- Friend functions do not belong to the class, so they rely on explicitly defined parameters

*/

#include <iostream>
using namespace std;

class Counter
{
    private:
        int value;
        
    public:
        Counter(int v) : value(v) {}
        
        //Counter& as return type because if we want to perform chaining operation
        friend Counter& operator+= (Counter& n1,const  Counter n2 );
        
        void display() const
        {
            cout<<"Value: "<<value<<endl;
        }
        
};

Counter& operator+= (Counter& n1,const  Counter n2 )
{
    n1.value += n2.value;
    
    return n1;
}

int main()
{
    Counter n1(30),n2(37);
    
    cout<<"\n===Number 1===\n";
    n1.display();
    cout<<endl;
    
    cout<<"\n===Number 2===\n";
    n2.display();
    cout<<endl;
    
    cout<<"Performing Addition...\n";
    n1 += n2;
    
    cout<<"\n===Number 1===\n";
    n1.display();
    cout<<endl;
    
    cout<<"\n===Number 2===\n";
    n2.display();
    cout<<endl;
}
