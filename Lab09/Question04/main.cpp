/*Scenario: You are building a security system. The interface (the functions available to the user)
should be separated from the complex internal implementation to keep the code organized and
secure.
Task:
 Create a header file SecuritySystem.h that defines an abstract class SecurityDevice.
 Define a pure virtual function virtual void authenticate() = 0;.
 Create a derived class BiometricScanner.
 Logic:
o The BiometricScanner should have a private variable attempts.
o In the authenticate() implementation, ask the user for a &quot;fingerprint ID&quot; (integer).
o If the ID is 1234, print &quot;Access Granted.&quot;
o If the user fails 3 times, print &quot;System Locked!&quot; and prevent further attempts.
 Ensure the implementation is in a separate .cpp file and */

#include "SystemSecurity.h"
#include "BiometricScanner.h"

int main()
{
    SecurityDevice* device;

    BiometricScanner scanner;

    device = &scanner;

    device->authenticate();

    return 0;
}
