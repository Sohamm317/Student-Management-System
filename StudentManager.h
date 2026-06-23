// Contains declarations for all funcs that operate on students

#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include<vector>
#include<Student.h>

Student* searchStudent(std::vector<Student>& students, int roll_number);

const Student* searchStudent(const std::vector<Student>& students, int roll_number);

bool compareByName (const Student &a, const Student &b);
bool compareByMarks (const Student &a, const Student &b);

bool isValidMarks(float marks);
bool isRollNumberUnique(const std::vector<Student>& students,int roll);

void sortByNameAscending (std::vector<Student>& students);
void sortByMarksDescending (std::vector<Student>& students);

void displayStudent(const Student& s);
void displayStudents(const std::vector<Student>& students);

void addStudent(std::vector<Student>& students);

void deleteStudent(std::vector<Student>& students, int roll_num);

#endif