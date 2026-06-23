#include <Student.h>

// constructor
Student::Student (const std::string& n = "", float m = 0.0f, int r = 0)
    : name(n), marks(m), roll_number(r) {}

// member functions
void Student::updateMarks (float new_marks) {
    marks = new_marks;
}

void Student::editStudent (const std::string& n, float m, int r) {
    name = n;
    marks = m;
    roll_number = r;
}

// getters
const std::string& Student::getName() const {
    return name;
}
int Student::getRollNumber() const {
    return roll_number;
}
float Student::getMarks() const {
    return marks;
}

// Contains all member functions of Student Class.