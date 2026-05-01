////Develop a security tool that analyzes an encrypted file named secret.txt. The program should read
//the file character-by-character and count only the uppercase letters, which represent hidden
//signals. It must ignore all spaces and punctuation marks during the scan.

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdlib>
using namespace std;


int main()
{
	char c;
	int upper = 0;
	
	ifstream file("secret.txt";
	if(!file)
	{
		cout<<"Error in opening file\n";
		return 1;
	}
	
	//until eof
	while(file.get(c))
	{
			if(isupper(c))
			{
				upper++;
			}
	}	
	
	file.close();
	
	cout<<"Total Upper Case letters: "<<upper<<endl;
	
}

