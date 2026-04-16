/*TASK # 03
Question 2: Is it possible to overload an operator using a friend function if one of the
operands is a primitive data type?
Problem Statement:
Suppose we want to overload the + operator to allow addition between an object and a primitive
type (e.g., object + int).
? Can a friend function handle this case?
? If yes, how would it be implemented?
? If no, what limitations exist?
Justify your answer with supporting C++ code.
*/


/* Explanation:
Yes!

In fact Friend functions operator overloading main usage is this that we add class's object  with any primitive data type (like int float)

A friend function allows access to private members of the class and enables operator overloading for both cases:
1. object + primitive
2. primitive + object

The limitations are as follows:
Friend functions exists as non-member function to a class 
They musut be declared as  a friend 
Overuusing friend function violates encapsulation ( less usage of setters and getters)

*/

#include <iostream>
using namespace std;

class Number
{
    private:
        int value;
        
    public:
        Number(int v) : value(v) {}
        
        //number + int
        friend Number operator+ (const Number& n1,int num);
        
        //int + num
        friend Number operator+ (int num,const Number& n1);
        
        void display() const
        {
            cout<<"Value: "<<value<<endl;
        }
        
};
 //number + int
 Number operator+ (const Number& n1,int num)
 {
     return Number(n1.value + num);
 }
 //int + num
 Number operator+ (int num,const Number& n1)
{
    return Number(num + n1.value);
}
int main()
{
    Number n1(22);
    
    Number n2 = n1 + 45;
    Number n3 = 45 + n1;
    
    cout<<"\n===Number 1===\n";
    n1.display();
    cout<<endl;
    
    cout<<"\n===Number 2 (n1 + 45)===\n";
    n2.display();
    cout<<endl;
    
    cout<<"\n===Number 3 (45 + n1)===\n";
    n3.display();
    cout<<endl;
    
    return 0;
    

}
