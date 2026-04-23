/*
Scenario: You are developing a payment gateway. Different payment methods (Credit Card,
PayPal) process transactions differently, but they all must have a processPayment feature.
Task:
 Create an abstract class Payment with a pure virtual function processPayment(double
amount).
 Create two derived classes: CreditCard and PayPal.
 Logic:
o For CreditCard, add a 2% service fee to the amount before printing &quot;Processing
Credit Card payment of $X&quot;.
o For PayPal, check if the amount is greater than $500; if so, apply a $10 discount
before processing. */

#include <iostream>
using namespace std;


class Payment
{
    public:
    virtual void processPayment(double amount) = 0;

    virtual ~Payment() {}
};


class CreditCard : public Payment
{
public:
    void processPayment(double amount)
    {
        double final = amount + (amount * 0.02); 
        cout << "Credit Card Payment: $" << final << endl;
    }
};


class PayPal : public Payment
{
public:
    void processPayment(double amount)
    {
        if (amount > 500)
        {
            amount -= 10; 
        }
        cout << "PayPal Payment: $" << amount << endl;
    }
};

int main()
{
    Payment* p;

    CreditCard cc;
    PayPal pp;

    p = &cc;
    p->processPayment(1000);
    
    p = &pp;
    p->processPayment(1000); 

    return 0;
}
