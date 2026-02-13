#include <iostream>
using namespace std;

class Satellite
{
	private:
		const int ID;
		const string launch;
		double radius;
		static int counter;
		
	public:
		Satellite(const int id, const string date, double r ) : ID(id),launch(date), radius(r)
		{
			
		}
		
		void calibrate(double r)
		{
			radius += r;
		}
		
		void viewReport() const
		{
			cout<<"ID: "<<ID<<endl;
			cout<<"Launch Date: "<<launch<<endl;
			cout<<"Orbital Radius: "<<radius<<endl;
			
			counter++;
			cout<<"Times Satellite Viewed: "<<counter<<endl;			
		}
		
};


int Satellite::counter =0;

int main()
{
	Satellite s(1234,"06 January 2027",5);
	
	cout<<"\n===Satellite Information===\n";
	s.viewReport();
	
	cout<<"\n Changing Radius...\n";
	s.calibrate(7);
	
	cout<<"\n===Satellite Information===\n";
	s.viewReport();
	
	
	
	return 0;
}
