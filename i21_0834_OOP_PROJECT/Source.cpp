#include<iostream>
#include<fstream>
#include<string>
#include"../OOP_PROJECT/Header..h"
using namespace std;

void Write_admin(Admin obj)
{
	ofstream fout("Admin.dat", ios::binary | ios::app);
	fout.write((char*)&obj, sizeof(obj));
	fout.close();
}

void Write_doctor(Doctor obj)
{
	ofstream fout("Doctor.dat", ios::binary | ios::app);
	fout.write((char*)&obj, sizeof(obj));
	fout.close();
}

void Read_doctor(string file_name)
{
	
	Doctor A;
	int i = 1;
	ifstream fin(file_name, ios::binary | ios::app);
	while (fin.read((char*)&A, sizeof(A)))
	{
		cout << "DOCTOR " << i << " :" << endl;
		A.display();
		i++;
	}
	fin.close();
}

void Write_patient(Patient obj)
{
	ofstream fout("Patient.dat", ios::binary | ios::app);
	fout.write((char*)&obj, sizeof(obj));
	fout.close();
}

void Read_patient(string file_name)
{

	Patient A;
	int i = 1;
	ifstream fin(file_name, ios::binary | ios::app);
	while (fin.read((char*)&A, sizeof(A)))
	{  
		cout << "PATIENT " << i << " :" << endl;
		A.display();
		i++;
	}
	fin.close();
}

void Write_appointment(Appointment obj)
{
	ofstream fout("Appointment.dat", ios::binary | ios::app);
	fout.write((char*)&obj, sizeof(obj));
	fout.close();
}

void Read_appointment(string file_name)
{

	Appointment A;
	int i = 1;
	ifstream fin(file_name, ios::binary | ios::app);
	while (fin.read((char*)&A, sizeof(A)))
	{
		cout << "APPOINTMENT " << i << " :" << endl;
		A.display();
		i++;
	}
	fin.close();
}



void Write_feedback(Feedback obj)
{
	ofstream fout("Feedback.dat", ios::binary | ios::app);
	fout.write((char*)&obj, sizeof(obj));
	fout.close();
}

void Read_feedback(string file_name)
{

	Feedback A;
	int i = 1;
	ifstream fin(file_name, ios::binary | ios::app);
	while (fin.read((char*)&A, sizeof(A)))
	{
		cout << "--------------------------------------------------------FEEDBACK "<<i<<"------------------------------------------------------" << endl;
		A.display();
		i++;
	}
	fin.close();
}

//==========================================================MAIN FUNCTION==============================================================
int main()
{
	cout << "                                                                                                " << endl;
	cout << "                                                                                                " << endl;
	cout << "                                                                                                " << endl;
	cout << "                                                                                                " << endl;
	cout << "                                                                                                " << endl;
	cout << "                                                                                                " << endl;
	cout << "                                                                                                " << endl;
	cout << "                                                                                                " << endl;
	cout << "                                                                                                " << endl;
	cout << "                         _______________________________________________________________________" << endl;
	cout << "                         |   ********   *          ********   ********   ********   ********   |" << endl;
	cout << "                         |   *      *   *          *      *   *      *   *      *   *          |" << endl;
	cout << "                         |   *      *   *          *      *   *      *   *      *   *          |" << endl;
	cout << "                         |   *      *   *          *      *   *      *   *      *   *          |" << endl;
	cout << "                         |   *      *   *          ********   *      *   *      *   *          |" << endl;
	cout << "                         |   *      *   *          *      *   *      *   *      *   *          |" << endl;
	cout << "                         |   *      *   *          *      *   *      *   *      *   *          |" << endl;
	cout << "                         |   *      *   *          *      *   *      *   *      *   *          |" << endl;
	cout << "                         |   ********   ********   *      *   ********   ********   ********   |" << endl;
	cout << "                         |_____________________________________________________________________|" << endl;
	cout << "                                                                                                " << endl;
	cout << "                                                                                                " << endl;
	cout << "                                                                                                " << endl;
	cout << "                                                                                                " << endl;
	cout << "                                                                                                " << endl;
	cout << "                                                                                                " << endl;
	cout << "                                                                                                " << endl;
	system("PAUSE");

	system("CLS");


	char loop1 = 'n';
	char loop2 = 'y';
	char loop3 = 'n';

	while (loop1 == 'n' || loop1 == 'N')
	{
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl; 
		cout << "                                                       O L A D O C                                                    "<<endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl; 
		int option1;
		cout << "\n\n\n\n\n\n\n\n                                                        1. Admin" << endl<<endl;
		cout << "                                                        2. Doctor" << endl<<endl;
		cout << "                                                        3. Patient" << endl<<endl;
		cin >> option1;


		if (option1 == 1)
		{

				Admin A;
				string u, p;

				

					system("CLS");
					cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
					cout << "                                                      LOGIN PANEL                                                      " << endl;
					cout << "-----------------------------------------------------------------------------------------------------------------------\n\n\n\n\n\n\n\n\n\n" << endl;
					cout << "                                                 USERNAME: ";
					cin >> u;
					cout << "\n                                                 PASSWORD: ";
					cin >> p;
					cout << endl;
					string defaultname = "Admin";
					string defaultpassword = "Admin@30";

					if (u == defaultname && p == defaultpassword)
					{
						
							cout << "                                          YOU HAVE SUCCESSFULLY LOGGED IN!\n\n\n\n" << endl << endl;
							system("PAUSE");
							system("CLS");
						while (loop3 == 'n' || loop3 == 'N')
						{
							int option2;
							cout << "                                                  **CHOOSE AN OPERATION** \n\n\n" << endl;
							cout << "                                                1. Show All Doctors" << endl;
							cout << "                                                2. Show all Patients" << endl;
							cout << "                                                3. Show all Appointments" << endl;
							cout << "                                                4. Delete doctor" << endl;
							cout << "                                                5. Add doctor" << endl;
							cout << "                                                6. Show feedbacks" << endl;
							cout << "                                                7. Update Appointment's status" << endl;

							cin >> option2;


							if (option2 == 1)
							{
								Doctor D;
								system("CLS");
								D.Readdoctor("Doctor.dat");
							}
							else if (option2 == 2)
							{
								Patient P;
								system("CLS");
								P.Readpatient("Patient.dat");
							}
							else if (option2 == 3)
							{
								Appointment A;
								system("CLS");
								A.Readappointment("Appointment.dat");
							}
							else if (option2 == 4)
							{
								string CNIC;
								int temp = 0;
								cout << "Enter CNIC(13 digit): ";
								temp = 0;
								while (temp != 13)
								{
									cin >> CNIC;
									for (int i = 0; CNIC[i] != '\0'; i++)
									{
										temp++;
									}
									if (temp != 13)
									{
										temp = 0;
										cout << "PLEASE ENTER A VALID 13 DIGIT CNIC!!" << endl;
									}
								}

								Admin A;
								A.Delete(CNIC);

								cout << "\n\n                                          DOCTOR WITH CNIC \"" << CNIC << "\" IS DELETED!!" << endl;

							}
							else if (option2 == 5)
							{
								string name;
								string cnic;
								string email;
								string pass;
								int yof;
								string specialization;
								string hospital;
								int avaliable_from;
								int avaliable_till;
								int fip;
								int fvc;
								string city;

								cout << "Enter name:";
								cin >> name;


								int temp = 0;
								cout << "Enter CNIC(13 digit): ";
								temp = 0;
								while (temp != 13)
								{
									cin >> cnic;
									for (int i = 0; cnic[i] != '\0'; i++)
									{
										temp++;
									}
									if (temp != 13)
									{
										temp = 0;
										cout << "PLEASE ENTER A VALID 13 DIGIT CNIC!!" << endl;
									}
								}

								cout << "Enter email id: ";
								cin >> email;

								cout << "Enter password: " << endl;
								cin >> pass;

								cout << "Years of experience: ";
								cin >> yof;

								cout << "Specialization Area: ";
								cin >> specialization;

								cout << "Hospital name:";
								cin >> hospital;

								cout << "Avaliabe from:";
								cin >> avaliable_from;

								cout << "Avaliabe till:";
								cin >> avaliable_till;

								cout << "Fee(In-Person):";
								cin >> fip;

								cout << "Fee(video consultation):";
								cin >> fvc;

								cout << "City:";
								cin >> city;


								Doctor D2;
								D2.registerDoctor(cnic, email, name, pass, yof, specialization, hospital, avaliable_from, avaliable_till, fip, fvc, city);
								D2.Writedoctor(D2);
							
							}

							else if (option2 == 6)
							{
								Feedback A;
								A.Readfeedback("Feedback.dat");

							}
							else if (option2 == 7)
							{
								Appointment D;

								D.Readappointment("Appointment.dat");

								string patient;
								string patientcnic;
								cout << "Enter the name of the patient:	 ";
								cin >> patient;


								int temp = 0;
								cout << "Enter CNIC(13 digit): ";
								temp = 0;
								while (temp != 13)
								{
									cin >> patientcnic;
									for (int i = 0; patientcnic[i] != '\0'; i++)
									{
										temp++;
									}
									if (temp != 13)
									{
										temp = 0;
										cout << "PLEASE ENTER A VALID 13 DIGIT CNIC!!" << endl;
									}
								}

								string day;
								cout << "Enter day:";
								cin >> day;

								int slot;
								cout << "Enter Slot # ";
								cin >> slot;

								int a;
								cout << "Choose an option:" << endl;
								cout << "      1. Approve" << endl;
								cout << "      2. Cancel" << endl;
								cin >> a;

								string statuss;

								if (a == 1)
								{
									statuss = "APPROVED";
									D.update_appointments(patient, patientcnic, day, slot, statuss);
								}
								else
								{
									statuss = "CANCELLED";
									D.update_appointments(patient, patientcnic, day, slot, statuss);
								}
							}

							cout << "Do you want to logout?(Y/N)" << endl;
							cin >> loop3;
						}
						
					}
					else
					{
						cout << "\n\n\n                                        **INVALID USERNAME OR PASSWORD**\n\n\n\n\n\n\n\n\n";
					}



				
		}

		else if (option1 == 2)
		{
		system("CLS");
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "                                                       O L A D O C                                                    " << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		int option2;
		cout << "\n\n\n\n\n\n\n\n                                                        1. Login" << endl << endl;
		cout << "                                                        2. Register" << endl << endl;
		cin >> option2;

				if (option2 == 1)
				{
					string u, p;
					system("CLS");
					cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
					cout << "                                                      LOGIN PANEL                                                      " << endl;
					cout << "-----------------------------------------------------------------------------------------------------------------------\n\n\n\n\n\n\n\n\n\n" << endl;
					cout << "                                                 USERNAME: ";
					cin >> u;
					cout << "\n                                                 PASSWORD: ";
					cin >> p;
					cout << endl;

					Doctor A;
					if (A.login(u, p) == true)
					{
						cout << "                                          YOU HAVE SUCCESSFULLY LOGGED IN!\n\n\n\n" << endl << endl;
						system("PAUSE");
						system("CLS");
					}
					else
					{
						cout << "                                                  <<USER NOT FOUND>>" << endl << endl;
					}

					if (A.login(u, p) == true)
					{
						while (loop3 == 'n' || loop3 == 'N')
						{
							int option3;
							
							cout << "                                                  1. View Profile"<<endl;
							cout << "                                                  2. Reset Password"<<endl;
							cout << "                                                  3. Update Profile" <<endl;
							cout << "                                                  4. See all appointments"<<endl;
							cout << "                                                  5. Check feedbacks" << endl;

							cin >> option3;

							if (option3 == 1)
							{

								system("CLS");
								Doctor P;
								P.view_profile(u, p);
							}
							else if (option3 == 2)
							{
								string pass;
								int count = 0;
								while (count != 8)
								{
									cout << "Enter password(8 characters)" << endl;
									cin >> pass;


									for (int i = 0; pass[i] != '\0'; i++)
									{
										count++;
									}
									if (count != 8)
									{
										count = 0;
										cout << "PLEASE ENTER A VALID PASSWORD" << endl;
									}

									if (count == 8)
									{

										bool check1 = false;
										bool check2 = false;
										bool check3 = false;
										bool check4 = false;

										for (int j = 0; j < 8; j++)
										{
											if (pass[j] >= 65 && pass[j] <= 90)
											{
												check1 = true;
											}
											if (pass[j] >= 97 && pass[j] <= 122)
											{
												check2 = true;
											}
											if (pass[j] >= '0' && pass[j] <= '9')
											{
												check3 = true;
											}
											if (pass[j] >= 33 && pass[j] <= 47 || pass[j] >= 58 && pass[j] <= 64 || pass[j] >= 91 && pass[j] <= 96 || pass[j] >= 123 && pass[j] <= 126)
											{
												check4 = true;
											}
										}

										if (check1 == true && check2 == true && check3 == true && check4 == true)
										{
											string confirmpass;
											while (confirmpass != pass)
											{
												cout << "Re-enter password to confirm: " << endl;
												cin >> confirmpass;
											}
										}
										else
										{
											count = 0;
											cout << "PLEASE ENTER A VALID PASSWORD!!" << endl;
										}

									}

								}

								Doctor P;
								P.resetpassword(p, pass);
							}
							else if (option3 == 3)
							{
							
								string email;
								int yof;
								string specialization;
								string hospital;
								int avaliable_from;
								int avaliable_till;
								int fip;
								int fvc;
								string city;

								Doctor D1;


								cout << "Enter email id: ";
								cin >> email;
								D1.setemail(email);


								cout << "Years of experience: ";
								cin >> yof;
								D1.setyof(yof);

								cout << "Specialization Area: ";
								cin >> specialization;
								D1.setspecialization(specialization);

								cout << "Hospital name:";
								cin >> hospital;
								D1.sethospital(hospital);

								cout << "Avaliabe from:";
								cin >> avaliable_from;
								D1.setavaliability_from(avaliable_from);

								cout << "Avaliabe till:";
								cin >> avaliable_till;
								D1.setavaliability_till(avaliable_till);

								cout << "Enter Fee(in person):";
								cin >> fip;
								D1.setfip(fip);

								cout << "Enter Fee(video consultation):";
								cin >> fvc;
								D1.setfvc(fvc);

								cout << "City:";
								cin >> city;
								D1.setcity(city);


								Doctor D2;
								D2.editDetails(D1, D1.helperfunc(u, p));
								cout << "            YOUR PROFILE HAVE BEEN SUCCESSFULLY UPDATED!!" << endl << endl;

								cout << "------------------------------------UPDATED PROFILE------------------------------------" << endl;
								D2.view_profile(u, p);
							}
							else if (option3 == 4)
							{
								
								Appointment D;

								D.doctor_appointments(u);

								string patient;
								string patientcnic;
								cout << "Enter the name of the patient: ";
								cin >> patient;

								int temp = 0;
								cout << "Enter CNIC(13 digit): ";
								temp = 0;
								while (temp != 13)
								{
									cin >> patientcnic;
									for (int i = 0; patientcnic[i] != '\0'; i++)
									{
										temp++;
									}
									if (temp != 13)
									{
										temp = 0;
										cout << "PLEASE ENTER A VALID 13 DIGIT CNIC!!" << endl;
									}
								}
								
								string day;
								cout << "Enter day:";
								cin >> day;
								
								int slot;
								cout << "Enter Slot # ";
								cin >> slot;
								
								int a;
								cout << "Choose an option:"<<endl;
								cout << "      1. Approve"<<endl;
								cout << "      2. Cancel" << endl;
								cin >> a;
								
								string statuss;
								if (a == 1)
								{
									statuss = "APPROVED";
									D.update_appointments(patient, patientcnic, day, slot, statuss);
								}
								else
								{
									statuss = "CANCELLED";
									D.update_appointments(patient, patientcnic, day, slot, statuss);
								}
							}
							else if (option3 == 5)
							{
													string id;
													Feedback f;
													f.viewfeedback(u);
						    }

							    cout << "Do you want to logout?(Y/N)";
								cin >> loop3;
						}
					}
				}


				else if (option2 == 2)
				{

					string name;
					string cnic;
					string email;
					string pass;
					int yof;
					string specialization;
					string hospital;
					int avaliable_from;
					int avaliable_till;
					int fip;
					int fvc;
					string city;

					cout << "Enter name:";
					cin >> name;

					int temp = 0;
					cout << "Enter CNIC(13 digit): ";
					temp = 0;
					while (temp != 13)
					{
						cin >> cnic;
						for (int i = 0; cnic[i] != '\0'; i++)
						{
							temp++;
						}
						if (temp != 13)
						{
							temp = 0;
							cout << "PLEASE ENTER A VALID 13 DIGIT CNIC!!" << endl;
						}
					}

					cout << "Enter email id: ";
					cin >> email;
					
					int count = 0;
					while (count != 8)
					{
						cout << "Enter password(8 characters)" << endl;
						cin >> pass;


						for (int i = 0; pass[i] != '\0'; i++)
						{
							count++;
						}
						if (count != 8)
						{
							count = 0;
							cout << "PLEASE ENTER A VALID PASSWORD" << endl;
						}

						if (count == 8)
						{

							bool check1 = false;
							bool check2 = false;
							bool check3 = false;
							bool check4 = false;

							for (int j = 0; j < 8; j++)
							{
								if (pass[j] >= 65 && pass[j] <= 90)
								{
									check1 = true;
								}
								if (pass[j] >= 97 && pass[j] <= 122)
								{
									check2 = true;
								}
								if (pass[j] >= '0' && pass[j] <= '9')
								{
									check3 = true;
								}
								if (pass[j] >= 33 && pass[j] <= 47 || pass[j] >= 58 && pass[j] <= 64 || pass[j] >= 91 && pass[j] <= 96 || pass[j] >= 123 && pass[j] <= 126)
								{
									check4 = true;
								}
							}

							if (check1 == true && check2 == true && check3 == true && check4 == true)
							{
								string confirmpass;
								while (confirmpass != pass)
								{
									cout << "Re-enter password to confirm: " << endl;
									cin >> confirmpass;
								}
							}
							else
							{
								count = 0;
								cout << "PLEASE ENTER A VALID PASSWORD!!" << endl;
							}

						}

					}

					cout << "Years of experience: ";
					cin >> yof;

					cout << "Specialization Area: ";
					cin >> specialization;

					cout << "Hospital name:";
					cin >> hospital;

					cout << "Avaliabe from:";
					cin >> avaliable_from;

					cout << "Avaliabe till:";
					cin >> avaliable_till;

					cout << "Fee(In-Person):";
					cin >> fip;

					cout << "Fee(video consultation):";
					cin >> fvc;

					cout << "City:";
					cin >> city;


					Doctor D2;
					D2.registerDoctor(cnic, email, name, pass, yof, specialization, hospital, avaliable_from, avaliable_till, fip, fvc, city);
					D2.Writedoctor(D2);
				}
		}



		else if (option1 == 3)
		{
			
		system("CLS");
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "                                                       O L A D O C                                                    " << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		int option2;
		cout << "\n\n\n\n\n\n\n\n                                                        1. Login" << endl << endl;
		cout << "                                                        2. Register" << endl << endl;
		cin >> option2;

				if (option2 == 1)
				{
					string u, p;
					system("CLS");
					cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
					cout << "                                                      LOGIN PANEL                                                      " << endl;
					cout << "-----------------------------------------------------------------------------------------------------------------------\n\n\n\n\n\n\n\n\n\n" << endl;
					cout << "                                                 USERNAME: ";
					cin >> u;
					cout << "\n                                                 PASSWORD: ";
					cin >> p;
					cout << endl;

					Patient P;
					Appointment A;
					if (P.login(u, p) == true)
					{
						cout << "                                          YOU HAVE SUCCESSFULLY LOGGED IN!\n\n\n\n" << endl << endl;
						system("PAUSE");
						system("CLS");
					}
					else
					{
						cout << "                                                  <<USER NOT FOUND>>" << endl << endl;
					}

					if (P.login(u, p) == true)
					{
						P.setusername(u);
						P.setpassword(p);

						while (loop3 == 'n' || loop3 == 'N')
						{
							
							int option3;
							cout << "CHOOSE AN OPTION:";
							cout << "    1. View Profile";
							cout << "    2. Reset Password";
							cout << "    3. Find a doctor";
							cout << "    4. Recharge account";
							cout << "    5. See all avaliable doctors";
							cout << "    6. Check appointments";
							cout << "    7. Give feedbacks";

							cin >> option3;
							string pname;
							string pcnic;
							if (option3 == 1)
							{
								system("CLS");

								P.view_profile(u, p);
							}
							else if (option3 == 2)
							{
								string np;
								cout << "Enter your new password:";
								cin >> np;

								P.resetpassword(p, np);
							}

							else if (option3 == 3)
							{
								int option4;
								cout << "Find a doctor by:"<<endl;
								cout << "     1.Name" << endl;
								cout << "     2.Specialization"<<endl;
								cout << "     3.Hospital" << endl;
								cout << "     4.City" << endl;
								cin >> option4;

								if (option4 == 1)
								{
									string n;
									cout << "Enter Doctor's Name: ";
									cin >> n;
									A.find_doctor_name(n);
								}
								else if (option4 == 2)
								{
									string spec;
									cout << "Enter specialization: ";
									cin >> spec;
									A.find_doctor_specialization(spec);
								}
								else if (option4 == 3)
								{
									string n;
									cout << "Enter Hospital's Name: ";
									cin >> n;
									A.find_doctor_hospital(n);
								}
								else if (option4 == 4)
								{
									string n;
									cout << "Enter City: ";
									cin >> n;
									A.find_doctor_city(n);
								}
								string dname;
								
								int start_slot;
								int end_slot;
								string mode;


								Appointment Z;


								cout << "Enter Doctor's name:";
								cin >> dname;


								cout << "Enter Your Name:  ";
								cin >> pname;
							

								int temp = 0;
								cout << "Enter CNIC(13 digit): ";
								temp = 0;
								while (temp != 13)
								{
									cin >> pcnic;
									for (int i = 0; pcnic[i] != '\0'; i++)
									{
										temp++;
									}
									if (temp != 13)
									{
										temp = 0;
										cout << "PLEASE ENTER A VALID 13 DIGIT CNIC!!" << endl;
									}
								}
								
								string day;
								cout << "Enter the day: ";
								cin >> day;

								A.display_slots(dname);
								int slot;
								cout << "Enter The Time Slot : ";
								cin >> slot;

								

								while (A.check_slot(dname,day,slot) == true)
								{
									cout << "                      ****THIS SLOT IS ALREADY BOOKED,PLEASE CHOOSE ANOTHER SLOT***" << endl;
									cin >> slot;
								}
								

								cout << "\n\n                ENTER STARTING TIME OF YOUR SLOT :";
								cin >> start_slot;

								cout << "                ENTER ENDING TIME OF YOUR SLOT :";
								cin >> end_slot;
								
								string x = to_string(start_slot);
								string y = to_string(end_slot);
								string appointment_time = x + ":00 - " + y + ":00";


								cout << "\nEnter mode of appointment:" << endl;
								cout << "        1. In-Person" << endl;
								cout << "        2. Video consultation" << endl;
								cin >> mode;

								Doctor D;
								
								if (mode == "1")
								{

									mode = "In - Person";

								}
								else
								{
									mode = "Video consultation";;
								}

								P.setAppointment(dname, pname, pcnic,day, slot, appointment_time, mode);
								

								cout << "                    Your appointment has been booked!!"<<endl<<endl;
							}
							else if (option3 == 4)
							{
								int recharge;
								cout << "Enter the amount:  Rs.";
								cin >> recharge;
								P.recharge_account(u,p,recharge);
							}
							else if (option3 == 5)
							{
								string option4;
								Appointment A;
								A.all_avaliable_doctor();
								cout << "                              Enter the name of the doctor:  Dr.";
								cin >> option4;

							}
							else if (option3 == 6)
							{
							     A.patient_appointments(u);		
							}
							else if (option3 == 7)
						    {

							Feedback B;
							string doctor;

							string stat = "APPROVED";

							if (A.completed_appointments(u, stat) == true)
							{

								cout << "Enter doctor's name: ";
								cin >> doctor;

								string cnic;
								int temp = 0;
								cout << "Enter CNIC(13 digit): ";
								temp = 0;
								while (temp != 13)
								{
									cin >> cnic;
									for (int i = 0; cnic[i] != '\0'; i++)
									{
										temp++;
									}
									if (temp != 13)
									{
										temp = 0;
										cout << "PLEASE ENTER A VALID 13 DIGIT CNIC!!" << endl;
									}
								}



								string day;
								cout << "Enter day:";
								cin >> day;

								int slot;
								cout << "Enter Slot:";
								cin >> slot;

								int rating;
								cout << "Rate doctor:";
								cin >> rating;

								string feedback;
								cout << "Kindly give us the feedback: ";
								cin >> feedback;

								Patient P;
								Appointment D;

								if (A.check_approve(doctor, u, day,slot, stat) == true)
								{
									P.setfeedback(doctor, u, rating, feedback);
									D.update_appointments(u, cnic, day, slot, "COMPLETED");
									cout << "          THANK YOU FOR YOUR FEEDBACK    ~Management" << endl;
								}
							}
							else
							{
								cout << "\n\n\n                                                             NO APPROVED APPOINTMENTS FOUND!!\n\n\n" << endl;
							}
							}

						cout << "Do you want to logout?(Y/N)";
						cin >> loop3;
						}
					}
				}

				else if (option2 == 2)
				{

					string name;
					string cnic;
					int age;
					string gender;

					cout << "Enter name:";
					cin >> name;


					int temp = 0;
					cout << "Enter CNIC(13 digit): ";
					temp = 0;
					while (temp != 13)
					{
						cin >> cnic;
						for (int i = 0; cnic[i] != '\0'; i++)
						{
							temp++;
						}
						if (temp != 13)
						{
							temp = 0;
							cout << "PLEASE ENTER A VALID 13 DIGIT CNIC!!" << endl;
						}
					}


					int count = 0;
					string pass;
					while (count != 8)
					{
						cout << "Enter password(8 characters)" << endl;
						cin >> pass;


						for (int i = 0; pass[i] != '\0'; i++)
						{
							count++;
						}
						if (count != 8)
						{
							count = 0;
							cout << "PLEASE ENTER A VALID PASSWORD" << endl;
						}

						if (count == 8)
						{

							bool check1 = false;
							bool check2 = false;
							bool check3 = false;
							bool check4 = false;

							for (int j = 0; j < 8; j++)
							{
								if (pass[j] >= 65 && pass[j] <= 90)
								{
									check1 = true;
								}
								if (pass[j] >= 97 && pass[j] <= 122)
								{
									check2 = true;
								}
								if (pass[j] >= '0' && pass[j] <= '9')
								{
									check3 = true;
								}
								if (pass[j] >= 33 && pass[j] <= 47 || pass[j] >= 58 && pass[j] <= 64 || pass[j] >= 91 && pass[j] <= 96 || pass[j] >= 123 && pass[j] <= 126)
								{
									check4 = true;
								}
							}

							if (check1 == true && check2 == true && check3 == true && check4 == true)
							{
								string confirmpass;
								while (confirmpass != pass)
								{
									cout << "Re-enter password to confirm: " << endl;
									cin >> confirmpass;
								}
								
							}
							else
							{
								count = 0;
								cout << "PLEASE ENTER A VALID PASSWORD!!" << endl;
							}

						}

					}

					cout << "Age: " ;
					cin >> age;

					cout << "Gender(MALE/FEMALE): " ;
					cin >> gender;

					Patient P2;
					P2.registerPatient(name, pass, cnic, age, gender,3500);
					P2.Writepatient(P2);


				}
				
		}
			cout << "Do you want to exit the system?(Y/N)";
			cin >> loop1;
	}
}

