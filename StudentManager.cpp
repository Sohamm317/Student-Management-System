// contains all the functions

#include"StudentManager.h"

#include<iostream>
#include<algorithm>
#include<limits>

using namespace std;

Student* searchStudent(vector<Student>& students, int roll_number) {
    for(Student& s : students) {
        if(s.getRollNumber() == roll_number)
            return &s;
    }
    return nullptr;
}

const Student* searchStudent(const vector<Student>& students, int roll_number) {
    for(const Student& s : students) {
        if(s.getRollNumber() == roll_number)
            return &s;
    }
    return nullptr;
}

bool compareByName (const Student &a, const Student &b) {
    return a.getName() < b.getName();
}

bool compareByMarks (const Student &a, const Student &b) {
    return a.getMarks() > b.getMarks();
}

bool isValidMarks(float marks) {
    return (marks >= 0 && marks <= 100);
}

bool isRollNumberUnique(const vector<Student>& students,int roll) {
    return !searchStudent(students, roll);
}

void sortByNameAscending (vector<Student>& students) {
    sort(students.begin(), students.end(), compareByName);
}

void sortByMarksDescending (vector<Student>& students) {
    sort(students.begin(), students.end(), compareByMarks);
}

void displayStudent(const Student& s)
{
    cout << "\n-----------------------------\n";
    cout << "Name        : " << s.getName() << endl;
    cout << "Roll Number : " << s.getRollNumber() << endl;
    cout << "Marks       : " << s.getMarks() << endl;
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

void addStudent(vector<Student>& students) {
    string name;
    float marks;
    int roll_number;

    cout << "Enter Name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);

    cout << "Enter Marks: ";
    cin >> marks;

    if(!isValidMarks(marks)) {
        cout << "Invalid Marks" << endl;
        return;
    }

    cout << "Enter Roll Number: ";
    cin >> roll_number;

    if(!isRollNumberUnique(students, roll_number)) {
        cout << "Roll Number already exists\nTry again with new details." << endl;
        return;
    }

    students.emplace_back(name, marks, roll_number);

    cout << "Student Added Successfully" << endl;
}

void deleteStudent(vector<Student>& students, int roll_num) {
    for(auto it = students.begin(); it != students.end(); ++it) {
        if(it->getRollNumber() == roll_num) {
            students.erase(it);
            cout << "Student Deleted Successfully" << endl;
            return;
        }
    }
    cout << "Student Not Found" << endl;
}
