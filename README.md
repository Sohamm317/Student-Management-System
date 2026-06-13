# Student Management System (C++)

A simple Student Management System built using C++ and Object-Oriented Programming principles. This project allows storing, displaying, searching, editing, and sorting student records.

## Features

* Add new students
* Display all student records
* Edit student details
* Update student marks
* Search students by roll number
* Delete students
* Sort students by name (A-Z)
* Sort students by marks (highest to lowest)
* Track total number of student objects
* Menu-driven interface (planned)
* File storage support (planned)

## Concepts Used

This project was built to practice core C++ concepts:

* Classes and Objects
* Constructors and Destructors
* Encapsulation
* Static Data Members
* STL Vector
* Iterators
* STL Sort Algorithm
* Comparator Functions
* Function Design
* Modular Programming

## Project Structure

```text
StudentManagementSystem/
│
├── main.cpp
├── Student.h          (planned)
├── Student.cpp        (planned)
└── README.md
```

## Sample Student Class

```cpp
class Student
{
private:
    string name;
    float marks;
    int roll_number;

    static int count;

public:
    Student(string n = "", float m = 0.0f, int r = 0);

    void update_marks(float new_marks);
    void edit_student(string n, float m, int r);

    string get_name() const;
    float get_marks() const;
    int get_roll_number() const;

    static int get_count();
};
```

## Sorting Implementation

### Sort by Name

```cpp
bool compare_by_name(const Student& a, const Student& b)
{
    return a.get_name() < b.get_name();
}
```

### Sort by Marks

```cpp
bool compare_by_marks(const Student& a, const Student& b)
{
    return a.get_marks() > b.get_marks();
}
```

## Future Improvements

* Menu-driven interface
* File handling (save/load records)
* Duplicate roll number validation
* Student statistics

  * Highest marks
  * Lowest marks
  * Average marks
* GUI version using Qt
* Database support using SQLite

## Learning Outcomes

By completing this project, I learned:

* How to design classes in C++
* How STL vectors work
* How iterators are used with algorithms
* How comparator functions are used with `std::sort`
* Basic project organization and clean code practices

## Build and Run

### Using g++

```bash
g++ main.cpp -o student_management
./student_management
```

### Using VS Code

1. Open the project folder.
2. Compile using g++.
3. Run the generated executable.

## Author

Sohamm

B.Tech Computer Science Engineering Student
IIIT Pune
