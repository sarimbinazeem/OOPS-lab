//Create a backup program that accepts log messages from a user. Every time a message is appended
//to backup_log.txt, the program should immediately display the current size of the file in bytes to
//the console.
// Key concepts: tellp(), file size tracking, append mode.


#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	string log;
	
	ofstream	file("backup_log.txt",ios::app);
	
	if(!file)
	{
		cout<<"Error Opening FIle! \n";
		return 1;
	}
	
	cout<<"Enter Message: ";
	getline(cin,log);
	
	file<<log<<endl;
	
	long size = file.tellp(); //for size
	
	cout<<"File Size: "<<size<<" bytes\n";
	
	file.close();
	return 0;
	
	
	
}
