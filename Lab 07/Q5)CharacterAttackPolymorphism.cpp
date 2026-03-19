// You are developing a fantasy game where different characters have unique attack behaviors. The
// game currently has Warriors, Mages, and Healers, but the development team plans to add many
// more character types in future expansions (Archers, Rogues, Paladins, etc.).
// Design a combat system where:
//  A base class Character exists with a performAttack function
//  Derived classes Warrior, Mage, and Healer each implement their own attack
// behavior:
// o Warrior performs a Sword Slash
// o Mage casts a Fireball
// o Healer performs a Healing Strike

// The system must be designed so that you can use a single Character pointer to refer to any
// character type. When attacks are triggered during gameplay, the program must identify the
// specific character type at runtime and execute the correct attack behavior. This decision must
// happen at the moment of execution (late binding), not during compilation.
// Additionally, the design should allow new character types to be added in the future without
// modifying existing game engine code.


#include <iostream>
using namespace std;

class Character
{
    public:
        virtual void performAttack() =0;
};

class Warrior : public Character
{
    public:
        void performAttack() override
        {
            cout<<"Sword Slash!\n";
        }

        
};
 

class Mage: public Character
{
    public:
        void performAttack() override
        {
            cout<<"FireBall!\n";
        }

        
};

class Healer : public Character
{
    public:
        void performAttack() override
        {
            cout<<"Healing Strike!\n";
        }

        
};

int main()
{
    Character **party;

    party = new Character*[3];

    party[0] = new Warrior();
    party[1] = new Mage();
    party[2] = new Healer();

    for(int i=0;i<3;i++)
    {
        party[i]->performAttack();
    }

    for(int i=0;i<3;i++)
    {
        delete party[i];
    }

    delete[] party;
    
    return 0;
}
