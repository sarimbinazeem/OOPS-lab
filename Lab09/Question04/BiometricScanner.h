#ifndef BIOMETRICSCANNER_H
#define BIOMETRICSCANNER_H

#include "SystemSecurity.h"
#include <iostream>
using namespace std;


class BiometricScanner : public SecurityDevice
{
	private:
	    int attempts;
	
	public:
	    BiometricScanner();
	
	    void authenticate();
};

#endif
