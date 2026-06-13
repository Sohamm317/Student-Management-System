#include<bits/stdc++.h>

using namespace std;

class Student {
private:
    string name;
    float marks;
    int roll_number;

    static int count;
public:
    Student (string n = "", float m = 0.0f, int r = 0) : name(n), marks(m), roll_number(r) {
        count++;
    }
    ~Student() {
        count--;
    }

    void update_marks (float new_marks) {
        marks = new_marks;
    }

    void edit_student (string n, float m, int r) {
        name = n; marks = m; roll_number = r;
    }

    string get_name() const {
        return name;
    }
    int get_roll_number() const {
        return roll_number;
    }
    float get_marks() const {
        return marks;
    }

    static int get_count() {
        return count;
    }
};

int Student::count = 0;

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

void display(const vector<Student>& students) {
    if(students.empty()) {
        cout << endl << "No Students Found" << endl;
        return;
    }

    cout << endl << "Student Records:" << endl;

    for(const Student& s : students) {
        cout << "Name        : " << s.get_name() << endl;
        cout << "Roll Number : " << s.get_roll_number() << endl;
        cout << "Marks       : " << s.get_marks() << endl << endl;
    }
}

int main()
{
    
    return 0;
}