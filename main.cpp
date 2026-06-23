#include<iostream>
#include<vector>
#include<limits>

#include "Student.h"
#include "StudentManager.h"

using namespace std;

int main() {
    int choice;
    vector<Student> students; 

    do {
        cout << endl << "Student Management System" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display Students" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Delete Student" << endl;
        cout << "5. Sort by Name" << endl;
        cout << "6. Sort by Marks" << endl;
        cout << "7. Edit Student" << endl;
        cout << "8. Display Student Count" << endl;
        cout << "9. Update Marks" << endl;
        cout << "10. Exit" << endl;

        cout << endl << "Enter Choice : ";
        cin >> choice;

        switch(choice) {
            case 1:
                addStudent(students);
                break;

            case 2:
                displayStudents(students);
                break;

            case 3:
            {
                int roll;
                cout << "Enter Roll Number: ";
                cin >> roll;

                const Student* s = searchStudent(students, roll);

                if(s)
                {
                    cout << endl << "Student Found" << endl;
                    displayStudent(*s);
                    
                } else {
                    cout << "Student Not Found" << endl;
                }

                break;
            }

            case 4:
            {
                int roll;
                cout << "Enter Roll Number: ";
                cin >> roll;

                deleteStudent(students, roll);

                break;
            }
            
            case 5:
                sortByNameAscending(students);
                cout << "Students Sorted by Name" << endl << endl;
                break;
            
            case 6:
                sortByMarksDescending(students);
                cout << "Students Sorted by Marks" << endl << endl;
                break;
            
            case 7:
            {
                int roll;
                cout << "Enter Roll Number" << endl;
                cin >> roll;
                Student* s = searchStudent(students, roll);

                if(!s) {
                    cout << "Student Not Found" << endl;
                    break;
                }

                string new_name; float new_marks; int new_rollnumber;
                cout << "Enter Updated Details: " << endl;
                
                cout << "Enter Name: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, new_name);

                cout << "Enter Marks: ";
                cin >> new_marks;

                if(!isValidMarks(new_marks)) {
                    cout << "Invalid Marks" << endl;
                    break;
                }
                
                cout << "Enter Roll Number: ";
                cin >> new_rollnumber;

                Student* check = searchStudent(students, new_rollnumber);
                
                if(check && check != s) {
                    cout << "Roll Number already exists\nEnter new Roll Number." << endl;
                    break;
                }

                s->editStudent(new_name, new_marks, new_rollnumber);
                
                cout << "Student Edited Successfully" << endl;
                break;
            }
            
            case 8:
                cout << "Number of Students: " << students.size() << endl;
                break;
            
            case 9:
            {
                int roll; float new_marks;
                cout << "Enter Roll Number: ";
                cin >> roll;
                
                Student* s = searchStudent(students, roll);

                if(!s) {
                    cout << "No Student Record" << endl;
                    break;
                }
                
                cout << "Enter new marks: ";
                cin >> new_marks;
                
                if(!isValidMarks(new_marks)) {
                    cout << "Invalid Marks" << endl;
                    break;
                }
                
                s->updateMarks(new_marks);
                
                cout << "Marks Updated Successfully" << endl;
                break;
            }
            
            case 10:
                cout << "Exit" << endl;
                break;
            
            default:
                cout << "Invalid Choice" << endl;
        };
    } while (choice != 10);

    return 0;
}