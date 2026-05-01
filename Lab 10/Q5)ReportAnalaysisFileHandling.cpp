//Analyzer A content management system requires a tool to generate quality metrics for articles. Your
//program must read article.txt and perform a comprehensive analysis to count total characters,
//total words, total lines, and the number of punctuation marks. All these statistics must be
//formatted and saved into a new file named report.txt.
// Key concepts: Multiple counters, string parsing, istringstream, report generation

#include <iostream>
#include <cctype>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	ifstream article("article.txt");
	
	if(!article)
	{
		cout<<"ERROR! Cant Open File\n";
		return 1;
	}
	
	string line;
	int characters = 0,words = 0,lines= 0,punctuations=0;
	
	
	while(getline(article,line))
	{
		lines++;
		
		bool wordPresent =false ;
		
		for(int i = 0 ; i< line.length();i++)
		{
			char c = line[i];
			characters++;
			
			if(ispunct(c))
			{
				punctuations++;
			}
			
			//if  character is not a space
			if(!isspace(c))
			{
				if(!wordPresent)
				{
					words++;
					wordPresent = true;
				}
			}
			else
			{
				wordPresent = false;
				
			}
			
			
			
		}
	}
	
	article.close();
	
	ofstream report("report.txt");
	report<<"\n====ARTICLE ANALYSIS STATISTICS====\n";
	report<<"Total Lines: "<<lines<<endl;
	report<<"Total Words: "<<words<<endl;
	report<<"Total Characters: "<<characters<<endl;
	report<<"Total Punctuation Marks: "<<punctuations<<endl;
	
	report.close();
	
	cout<<"Report Generated Successfully and Saved!\n";
		return 0;	
}
