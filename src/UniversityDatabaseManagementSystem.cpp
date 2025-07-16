#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <sstream>
#include <limits>
#define RESET   "\033[0m"
#define RED     "\033[31m"      
#define GREEN   "\033[32m"      
#define YELLOW  "\033[33m"              
#define CYAN    "\033[36m"        
using namespace std;

string intToString(int number) {
    stringstream ss;
    ss << number;
    return ss.str();
}

//For students
class student
{
public:
 string fname; // first name
 string lname; // last name
 int Registration; // Registration Number
 string course; // Course
 string classes; // Class info
 string phone_no; // Phone number
 string address; // Address
} studentData; // Variable of student type

//For teachers
class teacher
{
public:
 string fst_name; // first name
 string lst_name; // last name 
 string qualification; // Qualification 
 string exp; // Experience 
 string pay; // Pay 
 string subj; // subject 
 string lec; // Lecture per Week
 string addrs; // Address of teacher home
 string cel_no; // Phone number 
 string blod_grp; // Blood Group 
 string serves; // Number of serves 
} tech[150]; // Variable of teacher type

// Main function
int main()
{
    int login();
    login();

    int i = 0, j;
    char choice; // for getting choice
    string find;
    string srch;

    while (1) // outer loop
    { 
        system("cls"); // Clear screen

        cout << "\n\n\n\n\n\n\n\t\t\t\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\";
        cout << "\n\n";
        cout << CYAN << "\t\t\t\t\t\t   UNIVERSITY DATA MANAGEMENT\n\n" << RESET;
        cout << "\t\t\t\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\";
        cout << "\n\n";
        cout << "\t\t\t\t\t\t\t:MAIN SCREEN:\n\n";
        cout << GREEN << "\t\t\t\t\t\t 1. Students' Information" << RESET << endl;
        cout << YELLOW << "\t\t\t\t\t\t 2. Faculty Information" << RESET << endl;
        cout << RED << "\t\t\t\t\t\t 3. Exit Program" << RESET << endl;
        cout << "\n";
        cout << "\t\t\t\t\t\t Make your pick: ";
        cin >> choice;

        system("cls"); // Clear screen

        switch (choice) // First switch
        {
            case '1': // Student
            { 
                while (1) // inner loop-1
                { 
                    system("cls"); // Clear screen
                    // Level-2 display
                    cout << "\n\n\n\n\n\n\n\t\t\t\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\";
                    cout << GREEN << "\n\n\t\t\t\t\tSTUDENTS' PORTRAITS AND PERSONAL DETAILS HUB\n\n" << RESET;
                    cout << "\t\t\t\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n\n";
                    cout << "\t\t\t\t\t\t1. Create new entry\n";
                    cout << "\t\t\t\t\t\t2. Find and display entry\n";
                    cout << "\t\t\t\t\t\t3. Students in a Course\n";
                    cout << "\t\t\t\t\t\t4. Jump to main\n";
                    cout << "\n\t\t\t\t\t\tMake your pick: ";

                    cin >> choice;

                    switch (choice) // Second switch
                    {
                        case '1': // Insert data
                        {  
                            ofstream f1("data/student.txt", ios::app);

                            for (i = 0; choice != 'n' && choice != 'N'; i++)
                            {
                                if ((choice == 'y') || (choice == 'Y') || (choice == '1'))
                                {
                                    system("CLS");
                                    cout << "\t\t\tNEW ENTRY\n\n";
                                    cout << "\t\t\tEnter First Name: ";
                                    cin >> studentData.fname;
                                    cout << "\n\t\t\tEnter Last Name: ";
                                    cin >> studentData.lname;
                                    cout << "\n\t\t\tEnter Registration Number: ";
                                    while (!(cin >> studentData.Registration)) {
                                        cin.clear(); // Clear the error flag
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                                        cout << "\n\t\t\tInvalid input. Please ensure you enter an integer value for the registration number:  ";
                                    }
                                    cout << "\n\t\t\tEnter Course: ";
                                    cin >> studentData.course;
                                    cout << "\n\t\t\tEnter Class: ";
                                    cin >> studentData.classes;
                                    cout << "\n\t\t\tEnter Phone Number: ";
                                    cin >> studentData.phone_no;
                                    cout << "\n\t\t\tEnter Address: ";
                                    cin >> studentData.address;

                                    f1 << studentData.fname << endl << studentData.lname << endl << studentData.Registration << endl << studentData.course << endl << studentData.classes << endl << studentData.phone_no << endl << studentData.address << endl;
                                    cout << "\n\n\t\t\tDo you want to enter another data?";
                                    cout << "\n\t\t\tEnter (Y/y) to Continue or (N/n) to Finish:  ";
                                    cin >> choice;
                                }
                            } 
                            f1.close();
                        }
                        continue; // control back to inner loop -1
                        case '2': // Display data
                        {
                            ifstream f2("data/student.txt");
                            system("CLS");
                            cout << "\n\t\t\tDISPLAY STUDENT'S ENTRY\n";
                            cout << "\n\t\t\tEnter Registration no. of the Student: ";
                            int findReg;
                            cin >> findReg;
                            cout << endl;
                            int notFound = 1; // Initialize notFound to 1

                            while (f2 >> studentData.fname >> studentData.lname >> studentData.Registration >> studentData.course >> studentData.classes >> studentData.phone_no >> studentData.address) {
                                // Check if the registration number matches
                                if (findReg == studentData.Registration) {
                                    notFound = 0; // Set notFound to 0
                                    cout << "\n\t\t\tRegistration Number: " << studentData.Registration << endl;
                                    cout << "\n\t\t\tFirst Name: " << studentData.fname << endl;
                                    cout << "\n\t\t\tLast Name: " << studentData.lname << endl;
                                    cout << "\n\t\t\tCourse: " << studentData.course << endl;
                                    cout << "\n\t\t\tClass: " << studentData.classes << endl;
                                    cout << "\n\t\t\tPhone Number: " << studentData.phone_no << endl;
                                    cout << "\n\t\t\tAddress: " << studentData.address << endl;
                                    break; // Exit the loop once data is found
                                }
                            }

                            if (notFound) {
                                cout << RED << "\n\t\t\tNo Record Found!!!" << RESET << endl;
                            }

                            f2.close(); 
                            cout << "\n\t\t\tPress any key to proceed...";
                            getch();
                        }
                        continue;
                        case '3': // Enlist students by course
                        {
                            ifstream f3("data/student.txt");
                            system("CLS");
                            cout << "\n\t\t\tENLIST STUDENTS BY COURSE\n";
                            cout << "\n\t\t\tEnter the course name: ";
                            string courseToFind;
                            cin >> courseToFind;
                            cout << endl;
                            int notFound = 1; // Initialize notFound to 1

                            cout << "\n\t\t\tStudents enrolled in " << courseToFind << ":\n";
                            while (f3 >> studentData.fname >> studentData.lname >> studentData.Registration >> studentData.course >> studentData.classes >> studentData.phone_no >> studentData.address) {
                                // Check if the course matches
                                if (courseToFind == studentData.course) {
                                    notFound = 0; // Set notFound to 0
                                    cout << "\n\t\t\tRegistration Number: " << studentData.Registration << endl;
                                    cout << "\n\t\t\tName: " << studentData.fname << " " << studentData.lname << endl << endl;
                                }
                            }

                            if (notFound) {
                                cout << RED << "\n\t\t\tNo Record Found for the Specified Course!" << RESET << endl;
                            }

                            f3.close();
                            cout << "\n\t\t\tPress any key to proceed...";
                            getch();
                        }
                        continue;
                        case '4': // Jump to main
                        {
                            break; // inner switch breaking
                        }
                    }

                    break; // inner loop-1 breaking
                }
                continue; // Control pass to 1st loop    
            }

            case '2': // Teachers biodata
            { 
                while (1) // inner loop-2
                { 
                    system("cls"); // Clear screen
                    cout << "\n\n\n\n\n\n\n\t\t\t\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\";
                    cout << YELLOW << "\n\n\t\t\t\t\t   FACULTY INFORMATION AND BIODATA SECTION\n\n" << RESET;
                    cout << "\t\t\t\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n\n";
                    cout << "\t\t\t\t\t\t1. Create new entry\n";
                    cout << "\t\t\t\t\t\t2. Find and display\n";
                    cout << "\t\t\t\t\t\t3. Jump to main\n";
                    cout << "\n\t\t\t\t\t\tMake your pick: ";
                    cin >> choice;

                    switch (choice) // Third switch
                    {
                        case '1': // Insert data
                        { 
                            ofstream t1("data/teacher.txt", ios::app);

                            for (i = 0; choice != 'n' && choice != 'N'; i++)
                            {
                                if ((choice == 'y') || (choice == 'Y') || (choice == '1'))
                                {
                                    system("CLS");
                                    cout << "\t\t\tNEW ENTRY\n\n";
                                    cout << "\t\t\tEnter First name: ";
                                    cin >> tech[i].fst_name;
                                    cout << "\n\t\t\tEnter Last name: ";
                                    cin >> tech[i].lst_name;
                                    cout << "\n\t\t\tEnter Qualification: ";
                                    cin >> tech[i].qualification;
                                    cout << "\n\t\t\tEnter Experience(year): ";
                                    cin >> tech[i].exp;
                                    cout << "\n\t\t\tEnter Years in this University: ";
                                    cin >> tech[i].serves;
                                    cout << "\n\t\t\tEnter Subject: ";
                                    cin >> tech[i].subj;
                                    cout << "\n\t\t\tEnter Lecture(per Week): ";
                                    cin >> tech[i].lec;
                                    cout << "\n\t\t\tEnter Pay: ";
                                    cin >> tech[i].pay;
                                    cout << "\n\t\t\tEnter Address: ";
                                    cin >> tech[i].addrs;
                                    cout << "\n\t\t\tEnter Phone Number: ";
                                    cin >> tech[i].cel_no;
                                    cout << "\n\t\t\tEnter Blood Group: ";
                                    cin >> tech[i].blod_grp;

                                    t1 << tech[i].fst_name << endl << tech[i].lst_name << endl 
                                        << tech[i].qualification << endl << tech[i].exp << endl
                                        << tech[i].serves << endl << tech[i].subj << endl << tech[i].lec
                                        << endl << tech[i].pay << endl << tech[i].addrs << endl << tech[i].cel_no << endl << tech[i].blod_grp << endl;
                                    cout << "\n\n\t\t\tDo you want to enter another data??? ";
                                    cout << "\n\t\t\tEnter (Y/y) to Continue or (N/n) to Finish:  ";
                                    cin >> choice;
                                }
                            }

                            system("cls");
                            t1.close();
                        } // case 1

                        continue;

                        case '2': // Display data
                        { 
                            ifstream t2("data/teacher.txt"); 
                            system("CLS");
                            cout << "\n\t\t\tDISPLAY FACULTY'S ENTRY\n";
                            cout << "\n\t\t\tEnter name of the Faculty Member: ";
                            cin >> find;

                            cout << endl;
                            int notFound = 0;
                            for (j = 0; ((j < i) || (!t2.eof())); j++)
                            { 
                                getline(t2, tech[j].fst_name);
                                if (tech[j].fst_name == find)
                                {
                                    notFound = 1;
                                    cout << "\n\t\t\tFirst name: " << tech[j].fst_name << endl;
                                    getline(t2, tech[j].lst_name);
                                    cout << "\n\t\t\tLast name: " << tech[j].lst_name << endl;
                                    getline(t2, tech[j].qualification);
                                    cout << "\n\t\t\tQualification: " << tech[j].qualification << endl;
                                    getline(t2, tech[j].exp);
                                    cout << "\n\t\t\tExperience: " << tech[j].exp << endl;

                                    getline(t2, tech[j].serves);
                                    cout << "\n\t\t\tYear in this School: " << tech[j].serves << endl;

                                    getline(t2, tech[j].subj);
                                    cout << "\n\t\t\tSubject: " << tech[j].subj << endl;

                                    getline(t2, tech[j].lec);
                                    cout << "\n\t\t\tLecture (per Week): " << tech[j].lec << endl;
                                    getline(t2, tech[j].pay);
                                    cout << "\n\t\t\tPay: " << tech[j].pay << endl;

                                    getline(t2, tech[j].addrs);
                                    cout << "\n\t\t\tAddress: " << tech[j].addrs << endl;

                                    getline(t2, tech[j].cel_no);
                                    cout << "\n\t\t\tPhone Number: " << tech[j].cel_no << endl;

                                    getline(t2, tech[j].blod_grp);
                                    cout << "\n\t\t\tBlood Group: " << tech[j].blod_grp << endl;
                                }
                            }
                            t2.close();
                            if (notFound == 0) {
                                cout << RED << "\n\t\tNo Record Found!!!" << RESET << endl;
                            }
                            cout << "\n\t\t\t\tPress any key to proceed...";
                            getch();
                        }

                        continue;

                        case '3': // Jump to main 
                        {
                            break;
                        }
                    }

                    break;
                }

                continue;
            }

            case '3':
            {
                cout << "\n\n\n\n";
                cout << "\t\t\t\t\t\t  -------------------------------";
                cout << "\n\t\t\t\t\t\t\tCreated By: Khushi Arora\n";
                cout << "\t\t\t\t\t\t  --------------------------------\n\n\n\n";
                break;
            }
        }   
        break;
    }
}

int login() {
    string pass = "";
    char ch;
    cout << "\n\n\n\n\n\n\n\t\t\t\t\t\tUNIVERSITY MANAGEMENT SYSTEM \n\n";
    cout << "\t\t\t\t\t\t------------------------------";
    cout << "\n\t\t\t\t\t\t\t     LOGIN \n";
    cout << "\t\t\t\t\t\t------------------------------\n\n";
    cout << "\t\t\t\t\t\tEnter Password to Login: ";
    ch = _getch();
    while (ch != 13) { // character 13 is enter
        pass.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    if (pass == "pbl2") {
        cout << "\n\n\n\t\t\t\t\t\tAccess Granted... \n";
        system("PAUSE");
        system("CLS");
    } else {
        cout << "\n\n\t\t\t\t\t\tAccess Aborted!!!\n\t\t\t\t\t\tPlease Try Again...\n\n";
        system("PAUSE");
        system("CLS");
        login();
    }
}