/*Task:
 Create an abstract class Package with a private weight and a pure virtual function
calculateCost().
 Create derived classes LocalPackage and InternationalPackage.
 Logic:
Department of Computer Science
Miss Izzah Salam Lab 08: Introduction to Friend Classes, Friend
Functions, and Operator Overloading
o LocalPackage: Cost = weight * 5. If weight is over 20kg, add a &quot;Heavy Load&quot; flat
fee of $15.
o InternationalPackage: Cost = weight * 15. Add a fixed &quot;Customs Duty&quot; of $25.
 The main() function should use a base class pointer to call the correct cost calculation for
different objects.
*/


#include <iostream>
using namespace std;


class Package
{
	private:
	    double weight;
	
	public:
	    Package(double w)
	    {
	        weight = w;
	    }
	
	    double getWeight()
	    {
	        return weight;
	    }
	
	    virtual double calculateCost() = 0; 
};



class LocalPackage : public Package
{
	public:
	    LocalPackage(double w) : Package(w) 
		{
		}
	
	    double calculateCost()
	    {
	        double cost = getWeight() * 5;
	
	        if(getWeight() > 20)
	        {
	            cost += 15; 
	        }
	
	        return cost;
	    }
};


class InternationalPackage : public Package
{
	public:
	    InternationalPackage(double w) : Package(w) {}
	
	    double calculateCost()
	    {
	    	double cost = getWeight() * 15;
	        return cost + 25;
	    }
};


int main()
{
    Package* p;

    LocalPackage l(25);
    p = &l;
    cout<<"Local Package Cost: $"<<p->calculateCost()<<endl;
    
    InternationalPackage i(42);
    p = &i;
    cout<<"International Package Cost: $"<<p->calculateCost()<<endl;

    return 0;
}
