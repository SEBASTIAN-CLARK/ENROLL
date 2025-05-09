#include <iostream>
#include <string>
using namespace std;

const int maxHistory = 40;

struct OldStudentHistory {

    string name, payment, program, schedule;
    int year;
};

int main() {

    int choice, studentType, subjectChoice, paymentMethod, profileDone = 0, historyCount = 0;
    string name, selectedProgram = "";
    OldStudentHistory history[maxHistory];

    string programOptions[7] = {"BSEE", "BSME", "BSCE", "BSIE", "BSICE", "BSCpE", "BSMECHTRONICS",};
    string paymentOptions[3] = {"E-Wallet", "Cash", "Debit/Credit"};
    string subjectsNew[3] = {

        " 1. English 101 - Mon/Wed 10:00AM-11:30AM",
        " 2. Math 101 - Tue/Thu 1:00PM-2:30PM",
        " 3. CS 101 - Fri 9:00AM-12:00PM"
    };

    string year1Schedule[25] = {

        " Monday: ",

        " GE-ELEC2:     10:30 AM - 12:00 PM ",

        " PHYO1L:       3:00 PM - 4:30 PM ",

        " GEO3:         4:30 PM - 6:00 PM ",

        " Tuesday: ",

        " CPE02:        1:30 PM - 3:00 PM ",

        " GEO5:         3:00 PM - 4:30 PM ",
 
        " GEO7:         4:30 PM - 6:00 PM ",

        " Wednesday: ",  

        " CAL02:        12:00 PM - 1:30 PM ",

        " PHYO1:        1:30 PM - 3:00 PM ",

        " PE02:         5:00 PM - 7:00 PM ",

        " Thursday: ",

        " GE-ELEC2:     10:30 AM - 12:00 PM ",

        " PHYO1L:       3:00 PM - 4:30 PM ",

        " GEO5:         4:30 PM - 6:00 PM ",

        " Friday: ",

        " CPE02:        1:30 PM - 3:00 PM ", 

        " GEO5:         3:00 PM - 4:30 PM ",
       
        " GEO7:         4:30 PM - 6:00 PM ",

        " Saturday: ",

        " CAL02:        12:00 PM - 1:30 PM ",

        " PHYO1:        1:30 PM - 3:00 PM ", 
    
        " Sunday: ",

        " NSTP-CWTS2:   10:30 AM - 1:30 PM "
    };

    string year2Schedule[25] = {

        " Monday: ",

        " GE02:          10:30 AM - 12:00 PM ",

        " EE03:          1:30 PM - 3:00 PM ",

        " Tuesday: " ,

        " EE02:          9:00 AM - 10:30 AM ",

        " GE06:          1:30 PM - 3:00 PM ",

        " ECE01L:        3:00 PM - 5:00 PM ",
 
        " Wednesday: "

        " ME02:          10:30 AM - 12:00 PM ",

        " EMAG:          1:30 PM - 3:00 PM ",

        " MECH03:        3:00 PM - 4:30 PM ",

        " Thursday: ",

        " ECE01:         9:00 AM - 10:30 AM ",

        " EE02:          1:30 PM - 3:00 PM ",
 
        " GE06:          3:00 PM - 4:30 PM ",

        " Friday: ",

        " EE03:          10:30 AM - 12:00 PM ",

        " EMAG:          1:30 PM - 3:00 PM ",

        " ECE01:         3:00 PM - 4:30 PM ",

        " Saturday: ",

        " GE02:          9:00 AM - 10:30 AM ",

        " ME02:          12:00 PM - 1:30 PM ",

        " MECH03:        1:30 PM - 3:00 PM ",
  
        " Sunday: ",

        " EE03:          10:30 AM - 12:00 PM ",

        " ME02:          12:00 PM -1:30 PM "
    };

    string year3Schedule[25] = {

        " Monday: ",

        " GE02:          10:30 AM - 12:00 PM ",

        " EE03:          1:30 PM - 3:00 PM ",

        " Tuesday: ",

        " EE02:          9:00 AM - 10:30 AM ",

        " GE06:          1:30 PM - 3:00 PM ",

        " ECE01L:        3:00 PM - 5:00 PM ",
 
        " Wednesday: "

        " ME02:          10:30 AM - 12:00 PM ",

        " EMAG:          1:30 PM - 3:00 PM ",

        " MECH03:        3:00 PM - 4:30 PM ",

        " Thursday: ",

        " ECE01:         9:00 AM - 10:30 AM ",

        " EE02:          1:30 PM - 3:00 PM ",
 
        " GE06:          3:00 PM - 4:30 PM ",

        " Friday: ",

        " EE03:          10:30 AM - 12:00 PM ",

        " EMAG:          1:30 PM - 3:00 PM ",

        " ECE01:         3:00 PM - 4:30 PM ",

        " Saturday: ",

        " GE02:          9:00 AM - 10:30 AM ",

        " ME02:          12:00 PM - 1:30 PM ",

        " MECH03:        1:30 PM - 3:00 PM ",
  
        " Sunday: ",

        " EE03:          10:30 AM - 12:00 PM ",

        " ME02:          12:00 PM -1:30 PM "
    };

    string year4Schedule[25] = {

         " Monday: ",

        " EE10:          10:30 AM - 12:00 PM ",

        " EE11:          1:30 PM - 3:00 PM ",
 
        " EE12:          3:00 PM - 4:30 PM ",

        " Tuesday: ",

        " EE12L:         9:00 AM - 10:30 AM ",

        " EE13:          1:30 PM - 3:00 PM ",

        " EE14:          3:00 PM - 5:00 PM ",

        " Wednesday: ",

        " EEE01:         10:30 AM - 12:00 PM ",

        " IAC:           1:30 PM - 3:00 PM ",

        " IACL:          3:00 PM - 4:30 PM ",

        " Thursday: ",

        " TECHNO:        9:00 AM - 10:30 AM ",

        " EE10:          1:30 PM - 3:00 PM ",
 
        " EE11:          3:00 PM - 4:30 PM ",

        " Friday: ",

        " EE12:         10:30 AM - 12:00 PM ",

        " EE12L:        1:30 PM - 3:00 PM ",

        " EE13:         3:00 PM - 4:30 PM ",
 
        " Saturday: ",

        " EE14:         9:00 AM - 10:30 AM ",

        " EEE01:        12:00 PM - 1:30 PM ",

        " IAC:          1:30 PM - 3:00 PM ",

        " IACL:         10:30 AM - 1:30 PM ",
    };

    while (true) {

        cout << endl << "------ Enrollment System ------" << endl << endl;
        cout << " 1. New Student" << endl;
        cout << " 2. Old Student" << endl;
        cout << " 3. View Student History" << endl;
        cout << " 4. Exit" << endl << endl;
        cout << "Please select : ";
        cin >> choice;

        if (choice == 4) break;

        if (choice == 1) {
            cout << endl << "------- New student registration -------" << endl << endl;
            cout << " 1. Personal information" << endl;
            cout << " 2. List of course" << endl;
            cout << " 3. Payment" << endl << endl;
            cout << "Please select : ";
            cin >> studentType;

            if (studentType == 1) {

                cout << endl << "Enter full name : ";
                cin >> name;

                cout << endl << "Available programs :" << endl << endl;
                for (int j = 0; j < 7; j++) {
                    cout << " " << j + 1 << ". " << programOptions[j] << endl;
                }

                int programChoice;

                cout << endl << "Select program (1-7) : " ;
                cin >> programChoice;

                if (programChoice < 1 || programChoice > 7) {
                    cout << "Invalid program selected." << endl;
                    continue;
                }

                selectedProgram = programOptions[programChoice - 1];
                profileDone = 1;
                cout << endl << "Information saved." << endl;

            } else if (studentType == 2) {

                if (profileDone == 0) {
                    cout << "Please set up your profile first." << endl;
                    continue;
                }

                int yearLevel;
                cout << endl << "Enter your year level (2 for 2nd year, 3 for 3rd year, 4 for 4th year) : ";
                cin >> yearLevel;

                string* selectedSchedule = nullptr;

                if (yearLevel == 1) {
                    selectedSchedule = year1Schedule;
                } else if (yearLevel == 2) {
                    selectedSchedule = year2Schedule;
                } else if (yearLevel == 3) {
                    selectedSchedule = year3Schedule;
                } else if (yearLevel == 4){
                    selectedSchedule = year4Schedule;
                } else {
                    cout << "Invalid year level." << endl;
                    continue;
                }

                cout << endl << "------- Your Schedule -------" << endl;
                for (int i = 0; i < 3; i++) {
                    cout << selectedSchedule[i] << endl;
                }

                cout << endl << "Select a schedule (1-25): ";
                cin >> subjectChoice;

                if (subjectChoice < 1 || subjectChoice > 25) {
                    cout << "Invalid choice. Please select a valid schedule." << endl;
                    continue;
                }

                cout << endl << "You selected: " << selectedSchedule[subjectChoice - 1] << endl;

            } else if (studentType == 3) {

                if (profileDone == 0) {
                    cout << "Please set up your profile first." << endl;
                    continue;
                }

                cout << endl << "------- Payment options -------" << endl;

                for (int i = 0; i < 3; i++) {
                    cout << i + 1 << ". " << paymentOptions[i] << endl;
                }

                cout << endl << "Select payment method : ";
                cin >> paymentMethod;

                if (paymentMethod < 1 || paymentMethod > 3) {
                    cout << "Invalid payment method." << endl;
                    continue;
                }

                cout << endl << "Payment Successful." << endl << endl;
                cout << "WELCOME TO PERLDS TECHNOLOGICAL UNIVERSITY" << endl;
            }

        } else if (choice == 2) {

            int year;

            cout << endl << "------- Old student login -------" << endl << endl;

            cout << "Enter full name : ";
            cin >> name;

            cout << "Enter year level (press 2 for 2nd, 3 for 3rd, 4 for 4th): ";
            cin >> year;

            string* selectedSchedule = nullptr;

            if (year == 1) {
                selectedSchedule = year1Schedule;
            } else if (year == 2) {
                selectedSchedule = year2Schedule;
            } else if (year == 3) {
                selectedSchedule = year3Schedule;
            } else if (year == 4) {
                selectedSchedule = year4Schedule;
            } else {
                cout << "Invalid year level." << endl;
                continue;
            }

            cout << endl << "------- Your Schedule -------" << endl << endl;

            for (int i = 0; i < 25; i++) {
                cout << selectedSchedule[i] << endl;
            }

            cout << endl << "------- Payment options -------" << endl << endl;

            for (int i = 0; i < 3; i++) {
                cout << " " << i + 1 << ". " << paymentOptions[i] << endl;
            }

            cout << endl << "Select payment method : ";
            cin >> paymentMethod;

            if (paymentMethod < 1 || paymentMethod > 3) {
                cout << "Invalid payment method." << endl;
                continue;
            }

            cout << endl << "Payment Successful." << endl << endl;
            cout << "WELCOME TO PERLDS TECHNOLOGICAL UNIVERSITY." << endl;

            // Save history
            if (historyCount < maxHistory) {
                
                string fullSchedule = "";
                for (int i = 0; i < 3; i++) {
                    fullSchedule += selectedSchedule[i] + "\n";
                }

                history[historyCount].name = name;
                history[historyCount].year = year;
                history[historyCount].program = selectedProgram;
                history[historyCount].payment = paymentOptions[paymentMethod - 1];
                history[historyCount].schedule = fullSchedule;
                historyCount++;
            } else {
                cout << "History storage is full!" << endl;
            }

        } else if (choice == 3) {
            cout << endl << "------ Old student history ------" << endl << endl;

            if (historyCount == 0) {
                cout << "No history available yet." << endl;
            } else {
                for (int i = 0; i < historyCount; i++) {
                    cout << endl << "Student # " << i + 1 << endl << endl;
                    cout << " PERLDS TECHNOLOGICAL UNIVERSITY " << endl;
                    cout << "  REGISTRATION/ASSESSMENT FORM " << endl;
                    cout << "----------------------------------------" << endl << endl;
                    cout << " Student No.  : 2025-270518" << endl;
                    cout << " Name         : " << history[i].name << endl;
                    cout << " Year Level   : " << history[i].year << endl;
                    cout << " Program      : " << history[i].program << endl;
                    cout << " Payment Used : " << history[i].payment << endl;
                    cout << "---------------------------------------" << endl;
                    cout << " Subject code             Schedule" << endl;
                    cout << "---------------------------------------" << endl;
                    cout << endl << history[i].schedule << endl;
                    cout << endl <<"-------------------------------" << endl;
                }
            }
        }
    }

    cout << endl << "Thank you for using the Enrollment System." << endl;

    return 0;
}