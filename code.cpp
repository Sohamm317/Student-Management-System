#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<limits>

using namespace std;

class Student {
private:
    string name;
    float marks;
    int roll_number;

public:
    Student (const string& n = "", float m = 0.0f, int r = 0) : name(n), marks(m), roll_number(r) {}
    ~Student() = default;

    void updateMarks (float new_marks) {
        marks = new_marks;
    }

    void editStudent (const string& n, float m, int r) {
        name = n;
        marks = m;
        roll_number = r;
    }

    const string& get_name() const {
        return name;
    }
    int get_roll_number() const {
        return roll_number;
    }
    float get_marks() const {
        return marks;
    }

};

bool compare_by_name (const Student &a, const Student &b) {
    return a.get_name() < b.get_name();
}

bool compare_by_marks (const Student &a, const Student &b) {
    return a.get_marks() > b.get_marks();
}

void sortByNameAscending (vector<Student>& students) {
    sort(students.begin(), students.end(), compare_by_name);
}

void sortByMarksDescending (vector<Student>& students) {
    sort(students.begin(), students.end(), compare_by_marks);
}

void displayStudent(const Student& s)
{
    cout << "\n-----------------------------\n";
    cout << "Name        : " << s.get_name() << endl;
    cout << "Roll Number : " << s.get_roll_number() << endl;
    cout << "Marks       : " << s.get_marks() << endl;
}

void displayStudents(const vector<Student>& students) {
    if(students.empty()) {
        cout << endl << "No Students Found" << endl;
        return;
    }

    cout << endl << "Student Records:" << endl;

    for(const Student& s : students) {
        displayStudent(s);
    }
}

Student* searchStudent(vector<Student>& students, int roll_number) {
    for(Student& s : students) {
        if(s.get_roll_number() == roll_number)
            return &s;
    }
    return nullptr;
}

const Student* searchStudent(const vector<Student>& students, int roll_number) {
    for(const Student& s : students) {
        if(s.get_roll_number() == roll_number)
            return &s;
    }
    return nullptr;
}

void addStudent(vector<Student>& students) {
    string name;
    float marks;
    int roll_number;

    cout << "Enter Name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);

    cout << "Enter Marks: ";
    cin >> marks;

    if(marks < 0 || marks > 100) {
        cout << "Invalid Marks" << endl;
        return;
    }

    cout << "Enter Roll Number: ";
    cin >> roll_number;

    Student* s = searchStudent(students, roll_number);
    if(s) {
        cout << "Roll Number already exists\nTry again with new details." << endl;
        return;
    }

    students.emplace_back(name, marks, roll_number);

    cout << "Student Added Successfully" << endl;
}

void deleteStudent(vector<Student>& students, int roll_num) {
    for(auto it = students.begin(); it != students.end(); ++it) {
        if(it->get_roll_number() == roll_num) {
            students.erase(it);
            cout << "Student Deleted Successfully" << endl;
            return;
        }
    }
    cout << "Student Not Found" << endl;
}


int main()
{
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

                if(new_marks < 0 || new_marks > 100) {
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
                
                if(new_marks < 0 || new_marks > 100) {
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