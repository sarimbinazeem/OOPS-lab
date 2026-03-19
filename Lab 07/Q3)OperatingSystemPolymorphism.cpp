// You are building an Operating System simulator that needs to manage various system plugins.
// The OS should be able to load and execute different types of plugins without knowing their
// specific implementation details. Currently, the system requires two plugin types: an ;Antivirus;
// plugin that scans for threats, and an ;Updater; plugin that checks for system updates. However,
// the architecture should support countless future plugins.
// Design a plugin management system where:
//  A base class ;Plugin; exists with an execute function
//  Two derived classes are created:
// o Antivirus: Performs system scan functionality
// o Updater: Performs update check functionality
//  The system maintains a collection of Plugin pointers to manage all plugins uniformly
// When you iterate through your plugin collection and call execute, each plugin must perform its
// own specialized task automatically.

#include <iostream>
using namespace std;

class Plugin
{
    public:
        virtual void execute() = 0;
};

class Antivirus : public Plugin
{
    public:
        void execute() override
        {
            cout<<"Antivirus: Scanning system for viruses..."<<endl;
        }
};

class Updater  : public Plugin
{
    public:
        void execute() override
        {
            cout<<"Updater: Checking system for updates..."<<endl;
        }
};


int main()
{
    Plugin **plugins;

    plugins = new Plugin*[2];

    plugins[0] = new Antivirus();
    plugins[1] = new Updater();

    for(int i=0;i<2; i++)
    {
        plugins[i]->execute();
    }

    for(int i=0;i<2;i++)
    {
        delete plugins[i];
    }

    delete[] plugins;


    return 0;
}
