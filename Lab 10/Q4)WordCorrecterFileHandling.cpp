//A professional editing tool needs to fix a specific recurring typo: &quot;teh&quot; instead of &quot;the&quot;. Write a
//program that opens draft.txt and searches for the first instance of &quot;teh&quot;. Instead of rewriting the
//whole file, use random access pointers (seekp()) to replace the typo with &quot;the&quot; directly in its
//original position, ensuring the rest of the file remains untouched.
// Key concepts: seekp(), in-place file modification, file pointer navigation.

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	//fstream class object so we can perform both operation of ifstream and ofstream
	fstream file("draft.txt",ios::in | ios::out);
	
	if(!file)
	{
        cout << "Error opening file!\n";
        return 1;		
	}
	
	string word;
	long pos;
	
	//read word by word
	while(file>>word)
	{
		if(word == "teh")
		{
			//Current postion after reading word
			pos = file.tellg();
			
			//takes curosour to this point
			file.seekp(pos - 3); //teh is 3 chracters
			
			//overwrite
			file << "the";
			
			cout<<"Word Corrected!\n";
			break;
			
		}
	}
	
	file.close();
}
