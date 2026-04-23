/*Scenario: You are designing a software module for a Smart Coffee Machine. The user should be
able to make coffee without knowing the internal temperature of the water or the grinding speed of
the beans. This is the &quot;what&quot; versus the &quot;how&quot;.
Task:
 Create a class CoffeeMachine.
 Keep the waterLevel and coffeeBeans as private data members.
 Provide a public method makeCoffee().
 Logic: Inside makeCoffee(), add a condition: if waterLevel is less than 100ml, display
&quot;Insufficient water.&quot; Otherwise, decrease the water level and display &quot;Coffee is ready!&quot;*/

#include <iostream>
using namespace std;

class CoffeeMachine
{
    private:
       int waterlevel;
       
      public:
         CoffeeMachine(int water)
         {
             waterlevel = water;
         }
         
         void makeCoffee()
         {
             if(waterlevel<100)
             {
                 cout<<"Insufficient Water Level to Make Coffee\n";
             }
             else
             {
                 waterlevel -= 100;
                 cout<<"Coffee is prepared!\n";
             }
         }
         
         void showWater()
         {
             cout<<waterlevel<<" ml water left\n";
         }
};

int main()
{
    CoffeeMachine cm(300);
    
    cm.makeCoffee();
    cm.showWater();
    
    cm.makeCoffee();
    cm.showWater();
    
    cm.makeCoffee();
    cm.showWater();
    
    cm.makeCoffee();
    cm.showWater();

}
