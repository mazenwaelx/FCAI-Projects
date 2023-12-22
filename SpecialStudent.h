#ifndef SPECIALSTUDENT_H
#define SPECIALSTUDENT_H

#include<iostream>
#include<string>
#include "Student.h"
using namespace std;
class SpecialProgramStudent : public Student
{
public:
    bool RegisterCourse(Course* course)
    {
        return true;
    }
    float CalculateExpenses()
    {
        int totalCreditHours = 0;
        for (int i = 0; i < noOfCourses; i++)
        {
            totalCreditHours += courseList[i]->getCreditHours();
        }
        return totalCreditHours * 500;
    }
};

#endif 
