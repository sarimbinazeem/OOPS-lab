/* Task3 
Question 3: Can a friend function access private and protected members of a class without
using an object of that class?
Problem Statement:
A friend function is granted access to private and protected members of a class.
? Does it always need an object to access these members?
? Can a friend function access them directly without an object?
? Under what conditions might it fail?
Justify your answer with supporting C++ code.
*/

/* Explanation:

A friend function can access private and protected members of a class.

1) It doesnt alwasy need an objejct to access these members

2. It can access only static members directly using the class name and scope resolution operator. However, for non-static  members, an object is required.

3. It Fails when we try to access non static members without an object.

*/

#include <iostream>
using namespace std;

class Number
{
	private:
		int value;	
		static int count;	
		
	public:
		Number(int val): value(val) {
			count++;
		}
		
		friend void show(Number num);
		
		//Exception Case Where Object Is Not Required
		friend void show();
		
};

int Number::count = 100;

void show(Number num)
{
	cout<<"Number: "<<num.value<<endl;
	
	/*Not possible Without Object
	cout<<"Number: "<<value<<endl;
	*/
}

void show()
{
	cout<<"Number Count: "<<Number::count<<endl;
	
	/*Not possible Without Object
	cout<<"Number: "<<value<<endl;
	*/
}

int main()
{
	Number n1(10);
	
	cout<<"\n===Friend Function With Object===\n";
	show(n1);
	cout<<endl;
	
	cout<<"\n===Friend Function Without Object===\n";
	show();
	cout<<endl;
	
	
}
