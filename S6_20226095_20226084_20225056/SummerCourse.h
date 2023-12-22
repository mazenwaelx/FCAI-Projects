#ifndef SUMMERCOURSE_H
#define SUMMERCOURSE_H
#include<iostream>
#include<string>
#include "Course.h"
using namespace std;
class SummerCourse : public Course
{
public:
    SummerCourse() : Course("", 0, 0)
    {
        Code = Name + "_S" + to_string(MinStudentLevel);
    }

    SummerCourse(string name, int lvl, int creditH) : Course(name, lvl, creditH)
    {
        Code = name + "_S" + to_string(lvl);
    }
};

#endif