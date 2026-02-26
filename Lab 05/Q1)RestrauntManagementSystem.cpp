//Question 1:
//Youre building a simple food delivery app. The app has Customer and Restaurant. They connect
//through Order.
//Your Task:
//Write the code for Customer, Restaurant, and Order classes showing their relationship.
//Simple Requirements:
//1. Customer Class:
//o Properties: name
//o Method: placeOrder(Restaurant* r, string food) - creates an order
//2. Restaurant Class:
//o Properties: name
//o Method: takeOrder(Order* o) - receives an order
//3. Order Class:
//o Properties: id, customer, restaurant, foodItem
//o Method: show() - prints order details
//o
//
//What Your Code Must Show:
//Customers and Restaurants created first (before any orders)
//Order connects them (stores customer and restaurant names)


#include <iostream>
using namespace std;

class Restraunt;
class Customer;

class Order
{
private:
    int id;
    Customer *c;
    Restraunt *r;
    string food;

public:
    Order(int id, Customer *c, Restraunt *r,string food)
    {
        this->id = id;
        this->c = c;
        this->r = r;
        this->food = food;
    }


    string getFood()
    {
        return food;
    }

    void orderGone();


    void show();
};

class Restraunt
{
private:
    string name;
    
public:
    Restraunt(string name)
    {
        this->name = name;
    }

    void takeOrder(Order *o);

    string getRestraunt()
    {
        return name;
    }
};

class Customer
{
private:
    string name; 

public:
    Customer(string name)
    {
        this->name = name;
    }

    Order* placeOrder(int id,Restraunt *r, string food)
    {
        
        cout << name << " placed order at " << r->getRestraunt() << endl;
        
        Order* o = new Order(id,this,r,food);

        return o;
    }

    string getCustomer()
    {
        return name;
    }
};




void Restraunt::takeOrder(Order *o)
{
   
	cout << name << " making: " << o->getFood() << endl;

}

void Order::orderGone()
{
    
    cout << "Customer Still Exist: " << c->getCustomer() << endl;
	cout << "Restraunt  Still Exist: " << r->getRestraunt() << endl;
}

void Order::show()
{
	
    cout << "Order #" << id << ": " << food << " for "
             << c->getCustomer() << " from " << r->getRestraunt() << endl;
}
int main()
{
    Customer c1("Alice");
    Customer c2("Bob");

    Restraunt r1("Pizza Heaven");
    Restraunt r2("Taco Fiesta");
	
	cout<<"\n=====Placing Orders=====\n";
    Order *o1 = c1.placeOrder(1001,&r1, "Pepproni Pizza");
    Order *o2 = c2.placeOrder(1002,&r2, "Burrito");
    Order *o3 = c2.placeOrder(1003,&r2, "Burrito");
	
	cout<<"\n=====Restraunt Details=====\n";
	r1.takeOrder(o1);
	r2.takeOrder(o2);
	r2.takeOrder(o3);
	
	
	cout<<"\n=====Order Details=====\n";
	o1->show();
	o2->show();
	o3->show();
	
	cout<<"\n=====When Orders Are Gone=====\n";
	o1->orderGone();
	
	return 0;
	
}
