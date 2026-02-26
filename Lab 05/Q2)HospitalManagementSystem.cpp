//General Hospital has a digital system for patient records. When a new patient &quot;Lily Smith&quot; is
//admitted, a PatientRecord object is created.
//During her stay:
// Doctor gives medication → creates MedicationEntry (drug, dose, time)
// Nurse checks vitals → creates VitalSignsCheck (temperature, heart rate)
// Doctor writes diagnosis → creates DiagnosisNote (summary text)
//All these entries are stored inside Lily&#39;s PatientRecord.
//Your Task:
//Write the code showing Relation between PatientRecord and its medical entries.
//Simple Requirements:
//1. PatientRecord Class:
//o Properties: patientId, name, dob
//o Has one MedicationEntry, one VitalSignsCheck, one DiagnosisNote
//o Constructor creates all three entries
//o Destructor deletes all three entries
//o Method: displayRecord() - shows all patient data
//2. MedicationEntry Class:
//o Properties: drugName, dose, timeGiven
//3. VitalSignsCheck Class:
//o Properties: temperature, heartRate, timeChecked
//4. DiagnosisNote Class:
//o Properties: noteText, doctorName, date
//
//Key Points Your Code Must Show:
// Medical entries are created inside PatientRecord constructor
// Medical entries are deleted inside PatientRecord destructor
// Medical entries cannot exist without PatientRecord
// If PatientRecord is deleted, all entries are also deleted

#include <iostream>
using namespace std;

class MedicationEntry
{
	private:
		string drugName;
		double dose;
		int timeGiven;	
		
	public:
		MedicationEntry()
		{
			
		}
		
		void setMedication(string drugName, double dose, int timeGiven)
		{
			this->drugName = drugName;
			this->dose = dose;
			this->timeGiven = timeGiven;
		}
		
		void display()
		{
			cout<<"Drug Name: "<<drugName<<endl;
			cout<<"Doses: "<<dose<<endl;
			cout<<"Time Given: "<<timeGiven<<endl;
		}
};

class VitalSignsCheck
{
	private:
		double temprature;
		double heartRate;
		int timeChecked;
		
		
	public:
   		VitalSignsCheck()
		{
			
		}
		void setVital(double temprature,double heartRate,int timeChecked)
		{
			this->temprature= temprature;
			this->heartRate= heartRate;
			this->timeChecked= timeChecked;
			
		}
		
		void display()
		{
			cout<<"Temperature: "<<temprature<<endl;
			cout<<"Heart Rate: "<<heartRate<<endl;
			cout<<"Time Checked: "<<timeChecked<<endl;
		}
};

class DiagnosisNote
{
	private:
		string noteText;
		string doctorName;
		int date;
		
   	public:
   		DiagnosisNote()
		{
			
		}
   		
		void setDiagnosis(string noteText,string doctorName,int date)
		{
			this->noteText= noteText;
			this->doctorName= doctorName;
			this->date= date;
			
		}
		
		void display()
		{
			cout<<"Note Text: "<<noteText<<endl;
			cout<<"Doctor Name: "<<doctorName<<endl;
			cout<<"Date: "<<date<<endl;
		}
};

class PatientRecord
{
	private:
		int patientID;
		string name;
		string dob;
		MedicationEntry m;
		VitalSignsCheck v;
		DiagnosisNote d;
		
	public:
		PatientRecord(int patientID,string name, string dob, string drugName, double dose, int timeGiven, double temperature, double heartRate,int timeChecked, string noteText, string  doctorName, int date )
		{
			this->patientID = patientID;
			this->name = name;
			this->dob = dob;
			
			m.setMedication(drugName,dose,timeGiven);
			v.setVital(temperature,heartRate,timeChecked);
			d.setDiagnosis(noteText,doctorName,date);
		}
		
		void displayRecord()
		{
			cout<<"\n===Patient Details===\n";
			cout<<"Patient ID: "<<patientID<<endl;
			cout<<"Patient name: "<<name<<endl;
			cout<<"Patient Date Of Birth: "<<dob<<endl;
			cout<<"\n===Medication Details===\n";
			m.display();
			cout<<"\n===Vitals Details===\n";
			v.display();
			cout<<"\n===Diagonosis Details===\n";
			d.display();
			
		}
		
		~PatientRecord()
		{
			cout<<"\nPatientRecord destroyed -> All medical entries automatically destroyed (Composition).Deleting This Class Deletes Its Attributes\n";
		}
};

int main()
{
	PatientRecord p(101,"Sarim Azeem","05 November 2007","Dopamine",5.5,3,27.3,0.1,2,"For Inflammation, keep it away from 3 years old","Izzah Salam",7);
	
	p.displayRecord();
	
	
	cout<<"\n===Reasoning===\n";
	cout<<"We cant access the properties of Medication Entry, Vital Signs, Diagonosis Notes classes without Patient Record CLASS\n";
	cout<<"BECAUSE: Those classes are composed within Patient Record. When Patient Record is created then It HAS-A those three classes. Without creating Patient Record those three classes doesnt exist\n";
	cout<<"BECAUSE: OF Composition\n";
	cout<<endl;

}
