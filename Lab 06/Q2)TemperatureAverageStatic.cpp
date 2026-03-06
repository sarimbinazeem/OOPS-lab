#include <iostream>
using namespace std;

 class WeatherStats
 {
 	public:
 		static double calculateAverageTemperature(double temp[],int size)
 		{
 			double sum = 0.0;
 			
 			for(int i=0;i<size; i++)
 			{
 				sum += temp[i];
			 }
			 
			 return sum/size;
		 }
		 
		 static double getTemperatureFluctuation(double temp[],int size)
		 {
		 	double highest = temp[0];
		 	double lowest = temp[0];
		 	
		 	for(int i= 0 ;i< size; i++)
		 	{
		 		if(temp[i]>highest)
		 		{
		 			highest = temp[i];
				 }
				 
				 if(temp[i] < lowest)
				 {
				 	lowest = temp[i];
				 }
			 }
			 
			 return highest - lowest;
		 }
 };
 
 int main()
 {
 	double temperature[] = {32.5,45.0,76.2,90.2};
 	
 	int size = 4;
 	
 	double average = WeatherStats::calculateAverageTemperature(temperature,size);
 	double fluctuation = WeatherStats::getTemperatureFluctuation(temperature,size);
 	
 	cout<<"Average Temperature: "<<average<<endl;
 	cout<<" Fluctuation: "<<fluctuation<<endl;
 }