#include<iostream>
#include<fstream>
#include<cstring>


using namespace std;



class oladoc
{
protected:
	char username[50];
	char password[50];

public:

	oladoc()
	{
		
	}

	void setusername(string a)
	{
		strcpy_s(username, a.c_str());
	}

	void setpassword(string b)
	{
		strcpy_s(password, b.c_str());
	}

	string getusername()
	{
		return username;
	}

	string getpassword()
	{
		return password;
	}


};





//===============================================DOCTOR CLASS===============================================


class Doctor;

void Write_doctor(Doctor);
void Read_doctor(string);

class Doctor :public oladoc
{
protected:
	
	char cnic[50];
	char email[50];
	char name[50];
	int yof;
	char specialization[50];
	char hospital[50];
	int avaliable_from;
	int avaliable_till;
	int fip;
	int fvc;
	char city[50];
	int appointment_from;
	int appointment_till;


	
public:
	
	Doctor()
	{
			cnic[0] = '\0';
			email[0] = '\0';
			name[0] = '\0';
			yof = 0;
			specialization[0] = '\0';
			hospital[0] = '\0';
			avaliable_from = 0;
			avaliable_till = 0;
			fip = 0;
			fvc = 0;
			city[0] = '\0';
			appointment_from=0;
			appointment_till=0;
	}

	void registerDoctor(string c, string e, string name, string pass, int YOF, string s, string h, int af, int at,int fi,int fv, string ci)
	{
		
		strcpy_s(cnic, c.c_str());
		strcpy_s(email, e.c_str());
		setusername(name);
		setpassword(pass);
		yof = YOF;
		strcpy_s(specialization, s.c_str());
		strcpy_s(hospital, h.c_str());
		avaliable_from = af;
		avaliable_till = at;
		fip = fi;
		fvc = fv;
		strcpy_s(city, ci.c_str());

	}
	
	bool login(string user, string pass)
	{
		Doctor A;
		ifstream Login("Doctor.dat", ios::binary | ios::app);

		while (!Login.eof())
		{
			while (Login.read((char*)&A, sizeof(A)))
			{
				if (A.username == user && A.password==pass)
				{
					return true;
				}
			}
		}
		Login.close();
		return false;
	}

	void view_profile(string u, string p)
	{
		Doctor A;
		ifstream profile("Doctor.dat", ios::binary | ios::app);

		while (!profile.eof())
		{
			while (profile.read((char*)&A, sizeof(A)))
			{
				if (A.username == u && A.password == p)
				{
				cout << "\n\n               NAME                     :  " << A.username << endl;
					cout << "               PASSWORD                 :  " << A.password << endl;
					cout << "               CNIC                     :  " << A.cnic << endl;
					cout << "               EMAIL                    :  " << A.email << endl;
					cout << "               YEARS OF EXPERIENCE      :  " << A.yof << endl;
					cout << "               SPECIALIZATION AREA      :  " << A.specialization << endl;
					cout << "               HOSPITAL                 :  " << A.hospital << endl;
					cout << "               AVALIABILITY HOURS       :  " << A.avaliable_from << ":00 - " << A.avaliable_till << ":00 " << endl;
					cout << "               FEE(IN-PERSON)           :  " << A.fip << endl;
					cout << "               FEE(VIDEO CONSULTATION)  :  " << A.fvc << endl;
					cout << "               CITY                     :  " << A.city << endl;
				}
			}
		}
		profile.close();
	}


	void resetpassword(string pass,string newpass)
	{
		
		Doctor A;
		fstream reset("Doctor.dat", ios::out | ios::in | ios::binary );

		while (!reset.eof())
		{
			while (reset.read((char*)&A, sizeof(A)))
			{
				if (A.password==pass)
				{
					A.setpassword(newpass);
					int a = reset.tellg();
					int s = sizeof(Doctor);
					reset.seekp(a - s, ios::beg);
					reset.write((char*)&A, sizeof(A));
					break;
				}
			}
		}
		reset.close();
	}



	
	void editDetails(Doctor B,string city)
	{
		Doctor A;
		fstream reset("Doctor.dat", ios::out | ios::in | ios::binary);

			while (reset.read((char*)&A, sizeof(A)))
			{
				if (A.city == city)
				{
					
					A.setemail(B.email);
					A.setyof(B.yof);
					A.setspecialization(B.specialization);
					A.sethospital(B.hospital);
					A.setavaliability_from(B.avaliable_from);
					A.setavaliability_till(B.avaliable_from);
					A.setfip(B.fip);
					A.setfvc(B.fvc);
					A.setcity(B.city);

					int a = reset.tellg();
					int s = sizeof(A);
					reset.seekp(a - s, ios::beg);
					reset.write((char*)&A, sizeof(A));
					break;
				}
			}
		
		reset.close();
	}

	string helperfunc(string u, string p)
	{
		Doctor A;
		ifstream profile("Doctor.dat", ios::binary | ios::app);

		while (!profile.eof())
		{
			while (profile.read((char*)&A, sizeof(A)))
			{
				if (A.username == u && A.password == p)
				{

					return A.city;
				}
			}
		}
		profile.close();
	}

	
	void Writedoctor(Doctor A)
	{
		Write_doctor(A);
	}

	void Readdoctor(string a)
	{	
		Read_doctor(a);
	}

		
	void display()
	{
		cout << "-----------------------------------------------------------------------------";
	cout << "\n\n|               Name                      :  Dr."<<username << endl;
		cout << "|               CNIC                      :  " << cnic << endl;
		cout << "|               EMAIL                     :  " << email << endl;
		cout << "|               YEARS OF EXPERIENCE       :  " << yof << endl;
		cout << "|               SPECIALIZATION AREA       :  " << specialization << endl;
		cout << "|               HOSPITAL                  :  " << hospital << endl;
		cout << "|               AVALIABILITY HOURS        :  " << avaliable_from << ":00 - " << avaliable_till << ":00 " << endl;
		cout << "|               FEE(IN-PERSON)            :  Rs." << fip << endl;
		cout << "|               FEE(VIDEO CONSULTATIONS)  :  Rs." << fvc << endl;
		cout << "|               CITY                      :  " << city <<endl;
		cout << "-----------------------------------------------------------------------------" << endl << endl << endl;
		
	}

	void setcnic(string c)
	{
	strcpy_s(cnic, c.c_str());
	}
	void setemail(string e)
	{
	strcpy_s(email, e.c_str());
	}
	void setyof(int YOF)
	{
	yof = YOF;
	}
	void setspecialization(string s)
	{
	strcpy_s(specialization, s.c_str());
	}
	void sethospital(string h)
	{
	strcpy_s(hospital, h.c_str());
	}
	void setavaliability_from(int af)
	{
	avaliable_from = af;
	}
	void setavaliability_till(int at)
	{
	avaliable_till = at;
	}
	void setcity(string ci)
	{
	strcpy_s(city, ci.c_str());
	}
	void setfip(int fi)
	{
		fip = fi;
	}
	void setfvc(int fv)
	{
		fvc = fv;
	}


	string getcnic()
	{
		return cnic;
	}
	string getemail()
	{
		return email;
	}
	int getyof()
	{
		return yof;
	}
	string getspecialization()
	{
		return specialization;
	}
	string gethospital()
	{
		return hospital;
	}
	int getavaliability_from()
	{
		return avaliable_from;
	}
	int getavaliability_till()
	{
		return avaliable_till;
	}
	string getcity()
	{
		return city;
	}
	int getfip()
	{
		return fip;
	}
	int getfvc()
	{
		return fvc;
	}

};





//========================================================APPOINTMENT CLASS========================================================


class Appointment;

void Write_appointment(Appointment);
void Read_appointment(string);


class Appointment
{
protected:

	Doctor D;
	//Patient P;

	char doctor_name[100];
	char patient_name[100];
	char patient_cnic[100];
	int slot;
	char appointment_time[100];
	char mode[100];
	char status[100];
	char day[100];

	int* starting_slots;
	int* ending_slots;


public:


	Appointment()
	{
		doctor_name[0] = '\0';
		patient_name[0] = '\0';
		patient_cnic[0] = '\0';
		slot = 0;
		appointment_time[0] = '\0';
		mode[0] = '\0';
		status[0] = '\0';
		day[0] = '\0';


	}

	void all_avaliable_doctor()
	{
		system("CLS");
		int i = 1;
		ifstream fin("Doctor.dat", ios::binary | ios::app);
		cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "     NAME          AVALIABILITY      SPECIALIZATION       FEE(IP)    FEE(VC)          HOSPITAL          CITY           " << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------------" << endl << endl << endl;


		while (fin.read((char*)&D, sizeof(D)))
		{

			cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
			cout << i << ") Dr." << D.getusername() << "       " << D.getavaliability_from() << ":00 - " << D.getavaliability_till() << ":00 " << "      " << D.getspecialization() << "         " << D.getfip() << "         " << D.getfvc() << "             " << D.gethospital() << "              " << D.getcity() << endl;
			cout << "-----------------------------------------------------------------------------------------------------------------------" << endl << endl << endl;
			i++;
		}
		fin.close();

	}

	void find_doctor_name(string n)
	{
		system("CLS");
		int i = 1;
		ifstream fin("Doctor.dat", ios::binary | ios::app);
		cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "     NAME          AVALIABILITY      SPECIALIZATION       FEE(IP)    FEE(VC)          HOSPITAL          CITY           " << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------------" << endl << endl << endl;
		while (!fin.eof())
		{
			while (fin.read((char*)&D, sizeof(D)))
			{
				if (D.getusername() == n)
				{

					cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
					cout << i << ") Dr." << D.getusername() << "       " << D.getavaliability_from() << ":00 - " << D.getavaliability_till() << ":00 " << "      " << D.getspecialization() << "         " << D.getfip() << "         " << D.getfvc() << "             " << D.gethospital() << "              " << D.getcity() << endl;
					cout << "-----------------------------------------------------------------------------------------------------------------------" << endl << endl << endl;
					i++;
				}
			}
		}
		fin.close();
	}

	void find_doctor_specialization(string spec)
	{
		system("CLS");
		int i = 1;
		ifstream fin("Doctor.dat", ios::binary | ios::app);
		cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "     NAME          AVALIABILITY      SPECIALIZATION       FEE(IP)    FEE(VC)          HOSPITAL          CITY           " << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------------" << endl << endl << endl;
		while (!fin.eof())
		{
			while (fin.read((char*)&D, sizeof(D)))
			{
				if (D.getspecialization() == spec)
				{

					cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
					cout << i << ") Dr." << D.getusername() << "       " << D.getavaliability_from() << ":00 - " << D.getavaliability_till() << ":00 " << "      " << D.getspecialization() << "         " << D.getfip() << "         " << D.getfvc() << "             " << D.gethospital() << "              " << D.getcity() << endl;
					cout << "-----------------------------------------------------------------------------------------------------------------------" << endl << endl << endl;
					i++;
				}
			}
		}
		fin.close();
	}


	void find_doctor_hospital(string n)
	{
		system("CLS");
		int i = 1;
		ifstream fin("Doctor.dat", ios::binary | ios::app);
		cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "     NAME          AVALIABILITY      SPECIALIZATION       FEE(IP)    FEE(VC)          HOSPITAL          CITY           " << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------------" << endl << endl << endl;
		while (!fin.eof())
		{
			while (fin.read((char*)&D, sizeof(D)))
			{
				if (D.gethospital() == n)
				{

					cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
					cout << i << ") Dr." << D.getusername() << "       " << D.getavaliability_from() << ":00 - " << D.getavaliability_till() << ":00 " << "      " << D.getspecialization() << "         " << D.getfip() << "         " << D.getfvc() << "             " << D.gethospital() << "              " << D.getcity() << endl;
					cout << "-----------------------------------------------------------------------------------------------------------------------" << endl << endl << endl;
					i++;
				}
			}
		}
		fin.close();
	}

	void find_doctor_city(string n)
	{
		system("CLS");
		int i = 1;
		ifstream fin("Doctor.dat", ios::binary | ios::app);
		cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "     NAME          AVALIABILITY      SPECIALIZATION       FEE(IP)    FEE(VC)          HOSPITAL          CITY           " << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------------" << endl << endl << endl;
		while (!fin.eof())
		{
			while (fin.read((char*)&D, sizeof(D)))
			{
				if (D.getcity() == n)
				{

					cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
					cout << i << ") Dr." << D.getusername() << "       " << D.getavaliability_from() << ":00 - " << D.getavaliability_till() << ":00 " << "      " << D.getspecialization() << "         " << D.getfip() << "         " << D.getfvc() << "             " << D.gethospital() << "              " << D.getcity() << endl;
					cout << "-----------------------------------------------------------------------------------------------------------------------" << endl << endl << endl;
					i++;
				}
			}
		}
		fin.close();
	}



	void display_slots(string n)
	{
		int a;
		int b;
		int temp;

		ifstream fin("Doctor.dat", ios::binary | ios::app);
		while (!fin.eof())
		{
			while (fin.read((char*)&D, sizeof(D)))
			{
				if (D.getusername() == n)
				{
					a = D.getavaliability_from();
					b = D.getavaliability_till();
					temp = b - a;

					starting_slots = new int[temp];
					ending_slots = new int[temp];

					for (int i = 0; i < temp; i++)
					{
						starting_slots[i] = a;
						ending_slots[i] = a + 1;
						a++; 
					}
				}
			}
		}

		for (int i = 0; i < temp; i++)
		{
					cout << "                Slot" << i + 1 << ":      " << starting_slots[i] << ":00 - " << ending_slots[i] << ":00 " << endl;
				
		}
		fin.close();
	}

	void register_appointment(string dname, string pname, string pcnic,string d, int SLOT, string TIME, string MODE,string STATUS)
	{
		
			Appointment A;

			A.setdoctor_name(dname);
			A.setpatient_name(pname);
			A.setpatient_cnic(pcnic);
			A.setday(d);
			A.setslot(SLOT);
			A.setappointment_time(TIME);
			A.setmode(MODE);
			A.setstatus(STATUS);

			A.Writeappointment(A);
	}

	bool check_slot(string dname,string d,int slot)
	{
		Appointment A;
		ifstream profile("Appointment.dat", ios::binary | ios::app);

		while (!profile.eof())
		{
			while (profile.read((char*)&A, sizeof(A)))
			{
				if (A.doctor_name == dname && A.day==d && A.slot == slot)
				{
					return true;
				}
			}
		}
		profile.close();
		return false;
	}

	void patient_appointments(string pname)
	{
		Appointment A;
		ifstream profile("Appointment.dat", ios::binary | ios::app);
		int i = 1;
		while (!profile.eof())
		{
			while (profile.read((char*)&(A), sizeof(A)))
			{
				if (A.patient_name == pname)
				{
					cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
					cout << "Appointment: " << i << endl;
					cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
				    cout << "\n\n               DOCTOR'S NAME                  :  " << A.doctor_name << endl;
					cout << "               PATIENT'S NAME                 :  " << A.patient_name << endl;
					cout << "               PATIENT'S CNIC                 :  " << A.patient_cnic << endl;
					cout << "               APPOINTMENT DAY                :  " << A.day << endl;
					cout << "               TIME SLOT                      :  " << A.slot << endl;
					cout << "               TIME                           :  " << A.appointment_time << endl;
					cout << "               MODE                           :  " << A.mode << endl;
					cout << "               STATUS                         :  " << A.status << endl<<endl<<endl;
					i++;
				}
			}
		}
		profile.close();
	}


	bool completed_appointments(string pname,string stat)
	{
		Appointment A;
		ifstream profile("Appointment.dat", ios::binary | ios::app);
		int i = 1;
		while (!profile.eof())
		{
			while (profile.read((char*)&(A), sizeof(A)))
			{
				if (A.patient_name == pname && A.status == stat)
				{
					cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
					cout << "Appointment: " << i << endl;
					cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
					cout << "\n\n               DOCTOR'S NAME                  :  " << A.doctor_name << endl;
					cout << "               PATIENT'S NAME                 :  " << A.patient_name << endl;
					cout << "               PATIENT'S CNIC                 :  " << A.patient_cnic << endl;
					cout << "               APPOINTMENT DAY                :  " << A.day << endl;
					cout << "               TIME SLOT                      :  " << A.slot << endl;
					cout << "               TIME                           :  " << A.appointment_time << endl;
					cout << "               MODE                           :  " << A.mode << endl;
					cout << "               STATUS                         :  " << A.status << endl << endl << endl;
					i++;
					return true;
				}
			}
		}
		profile.close();
		return false;
	}



	void doctor_appointments(string dname)
	{
		Appointment A;
		ifstream profile("Appointment.dat", ios::binary | ios::app);
		int i = 1;
		while (!profile.eof())
		{
			while (profile.read((char*)&(A), sizeof(A)))
			{
				if (A.doctor_name == dname)
				{
					cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
					cout << "Appointment: " << i << endl;
					cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
					cout << "               PATIENT'S NAME                 :  " << A.getpatient_name() << endl;
					cout << "               PATIENT'S CNIC                 :  " << A.getpatient_cnic() << endl;
					cout << "               APPOINTMENT DAY                :  " << A.getday() << endl;
					cout << "               TIME SLOT                      :  " << A.getslot() << endl;
					cout << "               TIME                           :  " << A.getappointment_time() << endl;
					cout << "               MODE                           :  " << A.getmode() << endl;
					cout << "               STATUS                         :  " << A.getstatus() << endl << endl << endl;
					i++;
				}
			}
		}
		profile.close();
	}

	
	void update_appointments(string pname,string pcnic,string d,int SLOT,string STATUS)
	{
		Appointment A;
		fstream reset("Appointment.dat", ios::out | ios::in | ios::binary);

			while (reset.read((char*)&A, sizeof(A)))
			{
				
				if (A.patient_name == pname && A.patient_cnic==pcnic && A.day==d && A.slot==SLOT)
				{
					
					A.setstatus(STATUS);
					int a = reset.tellg();
					int s = sizeof(Appointment);
					reset.seekp(a - s, ios::beg);
					reset.write((char*)&A, sizeof(A));
					reset.close();
					break;
				}
			}
		
		reset.close();
	}
	

	bool check_approve(string dname, string pname, string d ,int SLOT,string stat)
	{
		Appointment A;
		ifstream profile("Appointment.dat", ios::binary | ios::app);
		
		while (!profile.eof())
		{
			while (profile.read((char*)&(A), sizeof(A)))
			{
				if (A.doctor_name == dname && A.patient_name && A.day==d && A.slot==SLOT && A.status==stat)
				{
					return true;
				}
			}
		}
		profile.close();
		return false;

	}
	void display()
	{
		cout << "                 Doctor's name    :  Dr." << doctor_name << endl;
		cout << "                 Patient's name   :  " << patient_name<< endl;
		cout << "                 Patient's cnic   :  " << patient_cnic << endl;
		cout << "                 Appointment day  :  " << day << endl;
		cout << "                 Time slot        :  " << slot << endl;
		cout << "                 Timing           :  " << appointment_time << endl;
		cout << "                 Mode             :  " << mode << endl;
		cout << "                 Status           :  " << status << endl;
	}



	void Writeappointment(Appointment A)
	{
		Write_appointment(A);
	}

	void Readappointment(string a)
	{
		Read_appointment(a);
	}



	void setdoctor_name(string n)
	{
		strcpy_s(doctor_name, n.c_str());
	}

	void setpatient_name(string n)
	{
		strcpy_s(patient_name, n.c_str());
	}



	void setpatient_cnic(string n)
	{
		strcpy_s(patient_cnic, n.c_str());
	}
	void setslot(int a)
	{
		slot = a;
	}

	void setmode(string mo)
	{
		strcpy_s(mode, mo.c_str());
	}

	void setappointment_time(string t)
	{
		strcpy_s(appointment_time, t.c_str());
	}

	void setstatus(string stat)
	{
		strcpy_s(status, stat.c_str());
	}

	void setday(string d)
	{
		strcpy_s(day, d.c_str());
	}


	string getdoctor_name()
	{
		return doctor_name;
	}

	string getpatient_name()
	{
		return patient_name;
	}



	string getpatient_cnic()
	{
		return patient_cnic;
	}

	string getmode()
	{
		return mode;
	}

	string getappointment_time()
	{
		return appointment_time;
	}

	int getslot()
	{
		return slot;
	}
	string getstatus()
	{
		return status;
	}

	string getday()
	{
		return day;
	}

};

//=========================================================================PAYMENT===================================================================

//class payment :public Doctor
//{
//public:
//
//	void paymenttransfer()
//	{
//		Appointment A;
//		ifstream profile("Appointment.dat", ios::binary | ios::app);
//
//		while (!profile.eof())
//		{
//			while (profile.read((char*)&A, sizeof(A)))
//			{
//				if (A.)
//				{
//
//					return A.city;
//				}
//			}
//		}
//		profile.close();
//	}
//};

//=========================================================================FEEDBACK==================================================================

class Feedback;

void Write_feedback(Feedback);
void Read_feedback(string);



class Feedback
{

	char doctor[100];
	char patient[100];
	int rating;
	char feedback[100];

public:

	void doctor_feedback(string dname,string pname, int r, string f)
	{
		Feedback A;

		A.setdoctor(dname);
		A.setpatient(pname);
		A.setrating(r);
		A.setfeedback(f);

		A.Writefeedback(A);

	}

	void viewfeedback(string a)
	{
		Feedback A;

		ifstream doc("Feedback.dat", ios::binary);

		while (doc.read((char*)&A, sizeof(A)))
		{
			if (A.doctor == a)
			{

				A.display();

			}
		}
		doc.close();

	}


	void display()
	{
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "         DOCTOR NAME           :  " << doctor <<endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "         PATIENT NAME          :  " << patient << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "         RATING                :  " << rating << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "         FEEDBACK              :  " << feedback << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------\n\n\n\n\n";
	}



	void Writefeedback(Feedback A)
	{
		Write_feedback(A);
	}

	void Readfeedback(string a)
	{
		Read_feedback(a);
	}


	//========setter/getter=========



	void setdoctor(string c)
	{
		strcpy_s(doctor, c.c_str());
	}
	void setpatient(string p)
	{
		strcpy_s(patient, p.c_str());
	}
	void setrating(int s)
	{
		rating = s;
	}
	void setfeedback(string a)
	{
		strcpy_s(feedback, a.c_str());
	}



	string getdoctor(string b)
	{
		return doctor;
	}
	string getpatient(string p)
	{
		return patient;
	}
	int getrating()
	{
		return rating;
	}
	string getfeedback(string b)
	{
		return feedback;
	}

};





//=================================================================PATIENT CLASS======================================================================


class Patient;

void Write_patient(Patient);
void Read_patient(string);

class Patient :public oladoc
{
private:

	char cnic[50];
	int age;
	char gender[50];
	int balance;


public:

	Patient()
	{
		cnic[0] = '\0';
		age = 0;
		gender[0] = '\0';
		balance = 3500;

	}

	void registerPatient(string NAME, string PASSWORD, string CNIC, int AGE,string GENDER,int  BALANCE)
	{
		setusername(NAME);
		setpassword(PASSWORD);
		strcpy_s(cnic, CNIC.c_str());
		age = AGE;
		strcpy_s(gender, GENDER.c_str());
		balance = BALANCE;
		
	}

	bool login(string user, string pass)
	{
		Patient A;
		ifstream Login("Patient.dat", ios::binary | ios::app);

		while (!Login.eof())
		{
			while (Login.read((char*)&A, sizeof(A)))
			{
				if (A.username == user && A.password == pass)
				{
					return true;
				}
			}
		}
		Login.close();
		return false;
	}

	void view_profile(string u, string p)
	{
		Patient A;
		ifstream profile("Patient.dat", ios::binary | ios::app);

		while (!profile.eof())
		{
			while (profile.read((char*)&A, sizeof(A)))
			{
				if (A.username == u && A.password == p)
				{
				cout << "\n\n               NAME                  :  " << A.username << endl;
					cout << "               PASSWORD              :  " << A.password << endl;
					cout << "               CNIC                  :  " << A.cnic << endl;
					cout << "               AGE                   :  " << A.age << endl;
					cout << "               GENDER                :  " << A.gender << endl;
					cout << "               BALANCE               :  " << A.balance << endl;
				}
			}
		}
		profile.close();
	}

	void resetpassword(string pass, string newpass)
	{

		Patient A;
		fstream reset("Patient.dat", ios::out | ios::in | ios::binary);

		while (!reset.eof())
		{
			while (reset.read((char*)&A, sizeof(A)))
			{
				if (A.password == pass)
				{
					A.setpassword(newpass);
					int a = reset.tellg();
					int s = sizeof(Patient);
					reset.seekp(a - s, ios::beg);
					reset.write((char*)&A, sizeof(A));
					break;
				}
			}
		}
		reset.close();
	}

	void recharge_account(string u,string p,int bal)
	{
		Patient A;
		fstream recharge("Patient.dat", ios::out | ios::in | ios::binary);
		int b = 0;

		while (!recharge.eof())
		{

			while (recharge.read((char*)&A, sizeof(A)))
			{
				if (A.username == u && A.password == p)
				{
					b = A.balance + bal;
					A.setbalance(b);
					int a = recharge.tellg();
					int s = sizeof(Patient);
					recharge.seekp(a - s, ios::beg);
					recharge.write((char*)&A, sizeof(A));
					break;

				}
			}
		}
        cout << "\n\n\                                   YOUR ACCOUNT HAS BEEN RECHARGED!!" << endl;
		cout << "                                     Your balance is : Rs." << b << endl;
		recharge.close();
	}

	void display_appointment(string NAME, string TIME, string MODE)
	{
		cout << "        Doctor's Name        :  Dr." << NAME;
		cout << "        Appointment time     :  " << TIME;
		cout << "        Mode                 :  " << MODE;
	}


	void setAppointment(string dname,string pname,string pcnic,string day,int slot, string app_time, string mode)
	{
		
		Appointment* A;
		A = new Appointment;

		(*A).register_appointment(dname, pname, pcnic,day, slot, app_time, mode,"PENDING");
	
    }

	void setfeedback(string dname, string pname, int rating, string feedback)
	{
		Feedback* A;
		A = new Feedback;

		(*A).doctor_feedback(dname,pname, rating, feedback);
	}

	void Writepatient(Patient A)
	{
		Write_patient(A);
	}

	void Readpatient(string a)
	{
		Read_patient(a);
	}

	void display()
	{
		cout << "-----------------------------------------------------------------------------"<<endl;
		cout << "|               PATIENT NAME          :  " << username << endl;
		cout << "|               CNIC                  :  " << cnic << endl;
		cout << "|               AGE                   :  " << age << endl;
		cout << "|               GENDER                :  " << gender << endl;
		cout << "|               BALANCE                :  " << gender << endl;
		cout << "-----------------------------------------------------------------------------" << endl << endl << endl;
	}

	void setcnic(string c)
	{
		strcpy_s(cnic, c.c_str());
	}
	void setage(int a)
	{
		age = a;
	}
	void setgender(string g)
	{
		strcpy_s(gender, g.c_str());
	}
	void setbalance(int b)
	{
		balance=b;
	}

	string getcnic()
	{
		return cnic;
	}

	int getage()
	{
		return age;
	}

	string getgender()
	{
		return gender;
	}

	int getbalance()
	{
		return balance;
	}
	
};




//===================================================================ADMIN CLASS===================================================================

class Admin : public oladoc {


public:

	bool login(string user, string pass)
	{
		Admin A;
		ifstream Login("Admin.dat", ios::binary | ios::app);

		while (!Login.eof())
		{
			while (Login.read((char*)&A, sizeof(A)))
			{
				if (A.username == user && A.password == pass)
				{
					return true;
				}
			}
		}
		Login.close();
		return false;
	}


	void Delete(string c)
	{

		Doctor A;

		ifstream f("Doctor.dat", ios::in | ios::binary);

		ofstream f2("temp.dat", ios::out | ios::binary);

		while (f.read((char*)&A, sizeof(A)))
		{

			if (A.getcnic() != c)
			{
				f2.write((char*)&A, sizeof(A));
			}
		}

		f.close();
		f2.close();

		remove("Doctor.dat");
		rename("temp.dat", "Doctor.dat");
		f.close();
		f2.close();

	}

};


//======================================================PAYMENT METHODS====================================================

class payment
{
protected:
	int easy_paisa;
	int jazz_cash;
	int pay_pak;
	int union_pay;

public:



};

class bank:public payment
{

protected:
	long IBAN;
	int acc_no;

public:


};


class e_trans :public payment
{

protected:
	long phone_no;

public:


};

class UnionPay :public bank
{
private:
	int balance_unionpay;

public:

};

class PayPak :public bank
{
private:
	int balance_paypak;
};

class JazzCash:public e_trans
{
private:
	int balance_jazzcash;

};

class easyPaisa :public e_trans
{
private:
	int balance_easypaisa;

};