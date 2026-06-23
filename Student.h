#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    std::string name;
    float marks;
    int roll_number;

public:
    Student (const std::string& n = "", float m = 0.0f, int r = 0);
    ~Student() = default;

    void updateMarks (float new_marks);
    void editStudent (const std::string& n, float m, int r);

    const std::string& getName() const;
    int getRollNumber() const;
    float getMarks() const;
};

#endif

// Contains the Student Class and function declarations