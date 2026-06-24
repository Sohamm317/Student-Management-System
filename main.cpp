#include<iostream>
#include<vector>
#include<limits>

#include "Student.h"
#include "StudentManager.h"
#include "FileHandler.h"

using namespace std;

int main() {
    int choice;

    vector<Student> students; 

    loadFromFile(students);

    do {
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Sort by Name\n";
        cout << "6. Sort by Marks\n";
        cout << "7. Edit Student\n";
        cout << "8. Display Student Count\n";
        cout << "9. Update Marks\n";
        cout << "10. Exit\n";

        cout << "\nEnter Choice : ";
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
                    cout << "\nStudent Found\n";
                    displayStudent(*s);
                    
                } else {
                    cout << "Student Not Found\n";
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
                cout << "Students Sorted by Name\n";
                break;
            
            case 6:
                sortByMarksDescending(students);
                cout << "Students Sorted by Marks\n";
                break;
            
            case 7:
            {
                int roll;
                cout << "Enter Roll Number\n";
                cin >> roll;
                Student* s = searchStudent(students, roll);

                if(!s) {
                    cout << "Student Not Found\n";
                    break;
                }

                string new_name; float new_marks; int new_rollnumber;
                cout << "Enter Updated Details: \n";
                
                cout << "Enter Name: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, new_name);

                cout << "Enter Marks: ";
                cin >> new_marks;

                if(!isValidMarks(new_marks)) {
                    cout << "Invalid Marks\n";
                    break;
                }
                
                cout << "Enter Roll Number: ";
                cin >> new_rollnumber;

                Student* check = searchStudent(students, new_rollnumber);
                
                if(check && check != s) {
                    cout << "Roll Number already exists\nEnter new Roll Number.\n";
                    break;
                }

                s->editStudent(new_name, new_marks, new_rollnumber);
                
                cout << "Student Edited Successfully\n";
                break;
            }
            
            case 8:
                cout << "Number of Students: " << students.size() << "\n";
                break;
            
            case 9:
            {
                int roll; float new_marks;
                cout << "Enter Roll Number: ";
                cin >> roll;
                
                Student* s = searchStudent(students, roll);

                if(!s) {
                    cout << "No Student Record\n";
                    break;
                }
                
                cout << "Enter new marks: ";
                cin >> new_marks;
                
                if(!isValidMarks(new_marks)) {
                    cout << "Invalid Marks\n";
                    break;
                }
                
                s->updateMarks(new_marks);
                
                cout << "Marks Updated Successfully\n";
                break;
            }
            
            case 10:
                saveToFile(students);
                cout << "Data Saved Succesfully\n";
                cout << "Exit\n";
                break;
            
            default:
                cout << "Invalid Choice\n";
        };
    } while (choice != 10);

    return 0;
}