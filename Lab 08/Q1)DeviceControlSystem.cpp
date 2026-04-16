//TASK # 01
//In a modern smart home, different devices such as lights, fans, air conditioners, and security
//systems are controlled through a central automation hub. The system must manage various
//electronic appliances, allowing authorized users to monitor and control their power consumption,
//adjust settings, and schedule automated tasks.
//However, sensitive security system controls should not be accessible to regular users and must
//only be accessed by authorized maintenance staff via a special diagnostic tool. The system
//should also be capable of calculating the power consumption of each appliance based on usage
//duration and device type.
//Attributes &amp; Functionality Requirements
//1. Device Management
//Each device should have:
// Device ID (string) – A unique identifier for each appliance.
// Device Type (string) – Specifies if it is a light, fan, AC, or security system.
// Power Rating (double) – Power consumption per hour in watts.
// Status (bool) – Whether the device is ON or OFF.
// A function void turnOn() to turn the device ON.
// A function void turnOff() to turn the device OFF.
// A function double calculatePowerUsage(int hours) to compute energy consumption:
//o Lights consume energy based on simple multiplication: powerRating * hours.
//o Fans have variable speed settings affecting power consumption (powerRating *
//hours * speedFactor).
//o Air Conditioners adjust power dynamically based on room temperature
//(powerRating * hours * (1 - (currentTemp - desiredTemp) / 100)).
//o Security Systems have fixed power consumption, but should include a security
//status check in power calculation.
//
//2. User Management
//Each user should have:
// User ID (string) – A unique identifier for each person.
// User Role (string) – Defines if the user is a Regular User or Maintenance Staff.
// Access Level (int) – Determines whether they can view/edit security devices.
// A function void viewAccessibleDevices() – Displays only the devices they are allowed to
//control.
//
//PROGRAMMING TASKS FOR LAB # 08
//
//March 27, 2026
//
//Lab 08 – Introduction to Friend Classes, Friend Functions, &amp;
//Operator Overloading
//
//Student Name: ___________________________ Roll No: ________________ Section: BCS-2E
//
//1
//
//Department of Computer Science
//Miss Izzah Salam Lab 08: Introduction to Friend Classes, Friend
//Functions, and Operator Overloading
//
//3. Special Security Controls
// Security system details (such as camera status and intrusion alerts) should not be
//accessible to regular users.
// Only maintenance staff should have access through a friend function:
//o void accessSecurityLogs() – Allows authorized personnel to check security
//status.
//
//Function Prototypes and Overriding Requirements
//1. void turnOn() and void turnOff() should be present in all devices but should:
//o Lights &amp; Fans: Simple ON/OFF state change.
//o ACs: Also adjust the temperature settings.
//o Security Systems: Require authorization check before turning OFF.
//2. double calculatePowerUsage(int hours) should be overridden:
//o Lights: powerRating * hours.
//o Fans: powerRating * hours * speedFactor.
//o ACs: powerRating * hours * (1 - (currentTemp - desiredTemp) / 100).
//o Security Systems: Fixed consumption + log security status.
//3. Friend Function: void accessSecurityLogs()
//o Allows only maintenance staff to view logs and system diagnostics.
//o Regular users cannot see logs even if they try.
//4. Friend Class: MaintenanceTool
//o Friend of Security Systems, allowing maintenance personnel to reset security
//alerts.
//
//Sample Input &amp; Expected Output
//Input:
//// User Setup
//User user1(&quot;U001&quot;, &quot;Regular User&quot;, 1);
//User user2(&quot;U002&quot;, &quot;Maintenance Staff&quot;, 2);
//// Devices Setup
//Light light1(&quot;L001&quot;, &quot;LED Light&quot;, 10);
//Fan fan1(&quot;F001&quot;, &quot;Ceiling Fan&quot;, 75, 3);
//AirConditioner ac1(&quot;AC001&quot;, &quot;Split AC&quot;, 1500, 25);
//SecuritySystem secSys1(&quot;S001&quot;, &quot;Home Alarm&quot;, 100);
//// Device Operations
//
//PROGRAMMING TASKS FOR LAB # 08
//
//March 27, 2026
//
//Lab 08 – Introduction to Friend Classes, Friend Functions, &amp;
//Operator Overloading
//
//Student Name: ___________________________ Roll No: ________________ Section: BCS-2E
//
//1
//
//Department of Computer Science
//Miss Izzah Salam Lab 08: Introduction to Friend Classes, Friend
//Functions, and Operator Overloading
//
//light1.turnOn();
//fan1.turnOn();
//ac1.turnOn();
//secSys1.turnOn();
//// Power Consumption Calculation
//cout &lt;&lt; light1.calculatePowerUsage(5) &lt;&lt; endl; // 50 Watts
//cout &lt;&lt; fan1.calculatePowerUsage(3) &lt;&lt; endl; // Based on speed factor
//cout &lt;&lt; ac1.calculatePowerUsage(6) &lt;&lt; endl; // Adjusted for temp
//cout &lt;&lt; secSys1.calculatePowerUsage(24) &lt;&lt; endl; // Fixed consumption
//// Attempting to access security logs
//user1.viewAccessibleDevices(); // Can see lights, fans, ACs, but NOT security systems
//user2.accessSecurityLogs(); // Allowed to view security logs
//Expected Output:
//LED Light [ID: L001] turned ON.
//Ceiling Fan [ID: F001] turned ON at Speed 3.
//Split AC [ID: AC001] turned ON. Cooling to 25°C.
//Home Alarm [ID: S001] activated.
//Power Consumption:
//LED Light: 50 Watts
//Ceiling Fan: 225 Watts
//Split AC: 7200 Watts
//Security System: 2400 Watts (Includes security checks)
//User: U001 - Accessible Devices:
//- LED Light
//- Ceiling Fan
//- Split AC
//User: U002 - Security Logs Accessed:
//- Intrusion Detected at 3:00 AM
//- System Reset Required

#include <iostream>
using namespace std;

class MaintenanceTool;
class User;

class Device
{
	protected:
		string deviceID;
		string deviceType;
		double powerRating;
		bool status;
		
	public:
		Device(string id, string type, double rating): deviceID(id), deviceType(type), powerRating(rating), status(false)
		{
			
		}
		
		//Virtual Functions
		virtual void turnOn()
		{
			status = true;
		}
		
		virtual void turnOff()
		{
			status = false;
		}
		
		//Pure vIRTUAL fUNCTIon
		virtual double calculatePowerUsage(int hours) = 0;
		
		//Getters
		string getID()
		{
			return deviceID;
		}
		
		string getType()
		{
			return deviceType;
		}
		
		double getRating()
		{
			return powerRating;
		}
		
		bool getStatus()
		{
			return status;
		}
		
		virtual bool isSecurityDevice()
		{
			return false;
		}
		
		//Virtual Destrcutor
		virtual ~Device()
		{
			
		}
};

class Light: public Device
{
	public:
		Light(string id, string type, double rating): Device(id,type,rating)
		{
			
		}
		
		void turnOn() override
		{
			status = true;
			cout<<deviceType<<" ["<<deviceID<<"] turned ON \n";
		}
		
		void turnOff() override
		{
			status = false;
			cout<<deviceID<<": Light Turned Off! \n";
		}
		
		double calculatePowerUsage(int hours) override
		{
			return hours*powerRating;
		}
		
		 bool isSecurityDevice()
		{
			return false;
		}		
};

class Fan: public Device
{
	private:
		double speed;
		
	public:
		Fan(string id, string type, double rating,double speed): Device(id,type,rating)
		{
			this->speed = speed;
		}
		
		void turnOn() override
		{
			status = true;
			
			cout<<deviceType<<" ["<<deviceID<<"] turned ON at Speed "<<speed<<endl;
		}
		
		void turnOff() override
		{
			status = false;
			cout<<deviceID<<": Fan Turned Off! \n";
		}
		
		double calculatePowerUsage(int hours) override
		{
			return hours*powerRating *speed;
		}
		 bool isSecurityDevice()
		{
			return false;
		}		
};

class AirConditioner: public Device
{
	private:
		double currentTemp;
		double requiredTemp;
		
		
	public:
		AirConditioner(string id, string type, double rating,double requiredTemp): Device(id,type,rating) , currentTemp(30)
		{
			this->requiredTemp = requiredTemp;
		}
		
		void turnOn() override
		{
			status = true;
			currentTemp = requiredTemp;
			cout<<deviceType<<" ["<<deviceID<<"] turned ON. Cooling to "<<requiredTemp<<endl;
		}
		
		void turnOff() override
		{
			status = false;
			currentTemp = 30; //Room Temperature
			cout<<deviceID<<": AC Turned Off! \n";
		}
		
		double calculatePowerUsage(int hours) override
		{
			return hours * powerRating * (1- (currentTemp-requiredTemp)/100);
		}
		 bool isSecurityDevice()
		{
			return false;
		}		
};

class SecuritySystem: public Device
{
	private:
		string securityLog;
		
		
	public:
		SecuritySystem(string id, string type, double rating): Device(id,type,rating)
		{
			securityLog = "- Intrusion Detected at 3:00 AM\n- System Reset Required";
		}
		
		void turnOn() override
		{
			status = true;
			cout<<deviceType<<" ["<<deviceID<<"] Activated \n";
		}
		
		void turnOff(User u);

		 bool isSecurityDevice()
		{
			return true;
		}	
			
		double calculatePowerUsage(int hours) override
		{
			cout<<"Performing Security Check...\n";
			
			if(status)
			{
				cout<<"System Active! \n";
			}
			else
			{
				cout<<"System Inactive! \n";
			}
			
			cout<<"Security Log: "<<securityLog<<endl;
			
			return hours * powerRating; //FIXED POWER CALCULATION!
		}
		
		friend void accessSecurityLogs(User u, SecuritySystem s);
		friend class MaintenanceTool;
		
};

class User
{
	private:
		string userID;
		string userRole;
		int accessLevel;
		
	public:
		User(string id, string role, int access): userID(id), userRole(role), accessLevel(access)
		{
			
		}
		
		void viewAccessibleDevices(Device *devices[], int size)
		{
			cout<<"User ("<<userRole<<"): " <<userID<<" Accessible Devices: \n";
			
			//Regular User Cant Access Security System
			for(int i=0; i<size; i++)
			{
				if(userRole== "Regular User" && devices[i]->isSecurityDevice())
				{
					//skip this
					continue;
				}
				
				cout<<"-"<<devices[i]->getType()<<endl;
			}
		}
		
		inline string getRole()
		{
			return userRole;
		}
		
		friend void accessSecurityLogs(User u, SecuritySystem s);
};

void SecuritySystem::turnOff(User u)
{
	if(u.getRole() == "Maintenance Staff")
	{
		status = false;
		cout<<"Authoritization Successfull! \n";
		cout<<deviceID<<": Security System Deactivated \n";
	}
	else
	{
		cout<<"Access Denied! Unauthorized User Cant Turn ON and OFF The Security Systems.\n";
	}
}

void accessSecurityLogs(User u, SecuritySystem s)
{
    if(u.userRole == "Maintenance Staff")
    {
        cout<<"User: "<<u.userID<<" - Security Logs Accessed:\n";
        cout<<s.securityLog <<endl;
    }
    else
    {
        cout<<"Access Denied! Authorization Failed\n";
    }
}

class MaintenanceTool
{
	public:
		void resetSystem(SecuritySystem &s)
		{
			cout<<"Resetting Security System...\n";
			s.securityLog = "System Reset Successfully!";
		}
};

int main()
{
	//User Setup
	User user1("U001","Regular User",1);
	User user2("U002","Maintenance Staff",1);
	
	//Devices Setup

    Light light1("L001", "LED Light", 10);
    Fan fan1("F001", "Ceiling Fan", 75, 3);
    AirConditioner ac1("AC001", "Split AC", 1500, 25);
    SecuritySystem secSys1("S001","Security System",100);
    
    //Device Operation
    light1.turnOn();
    cout << endl;
	fan1.turnOn();
    cout << endl;
	ac1.turnOn();
    cout << endl;
	secSys1.turnOn();    
    cout << endl;
	
	//Base Pointer Array
	Device* devices[4] = {&light1, &fan1, &ac1, &secSys1};
	
	cout<<"\n====Power Consumption====\n";
	//Power Consumption Calculation
	cout<<light1.getType()<<": "<<light1.calculatePowerUsage(5)<< " Watts"<<endl;
    cout << endl;
	cout<<fan1.getType()<<": "<<fan1.calculatePowerUsage(3)<< " Watts"<<endl;
    cout << endl;
	cout<<ac1.getType()<<": "<<ac1.calculatePowerUsage(6) << " Watts"<<endl;
    cout << endl;
	cout<<secSys1.getType()<<": "<<secSys1.calculatePowerUsage(24)<<" Watts (Includes security checks)"<<endl;
    cout << endl;
	
	//Attempting to access security logs
    user1.viewAccessibleDevices(devices, 4);
    cout << endl;

    accessSecurityLogs(user2, secSys1);

    cout << endl;
	
	//Friend Class
    MaintenanceTool tool;
    tool.resetSystem(secSys1);

    cout << endl;
    accessSecurityLogs(user2, secSys1);

    cout << endl;

    // Test authorization of user 
    secSys1.turnOff(user1); 
    secSys1.turnOff(user2); 
}
