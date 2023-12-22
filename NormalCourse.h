#ifndef NORMALCOURSE_H
#define NORMALCOURSE_H
#include "Course.h"
#include<iostream>
#include<string>
using namespace std;
class NormalCourse : public Course
{
public:
    NormalCourse() : Course("", 0, 0)
    {
        Code = Name + "_N" + to_string(MinStudentLevel);
    }

    NormalCourse(string name, int lvl, int creditH) : Course(name, lvl, creditH)
    {
        Code = name + "_N" + to_string(lvl);
    }
};

#endif