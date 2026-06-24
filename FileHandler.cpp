#include"FileHandler.h"

#include<fstream>
#include<iostream>
#include<sstream>

using namespace std;

void saveToFile(const vector<Student>& students) {
    ofstream file("students.txt");

    if(!file) {
        cout << "Error opening file for writing\n";
        return;
    }

    for(const Student& s : students) {
        file << s.getName() << "," << s.getRollNumber() << "," << s.getMarks() << "\n";
    }

    file.close();
}

void loadFromFile(vector<Student>& students) {
    ifstream file("students.txt");

    if(!file) {
        return;
    }

    string line;

    while(getline(file,line)) {
        stringstream ss(line);

        string name, rollStr, marksStr;

        getline(ss, name, ',');
        getline(ss, rollStr, ',');
        getline(ss, marksStr);

        float marks = stof(marksStr);
        int roll = stoi(rollStr);

        students.emplace_back(name, marks, roll);
    }
    file.close();
}