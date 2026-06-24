#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include<vector>
#include "Student.h"

void saveToFile(const std::vector<Student>& students);
void loadFromFile(std::vector<Student>& students);
#endif