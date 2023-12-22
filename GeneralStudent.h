#ifndef GENERALSTUDENT_H
#define GENERALSTUDENT_H
#include "Course.h"
#include "Student.h"
#include<iostream>
#include<string>
using namespace std;
class GeneralProgramStudent : public Student
{
public:
    bool RegisterCourse(Course* course)
    {
        if (level >= course->getMinStudentLevel())
        {
            return true;
        }
        else
        {
            cout << "Error: You Cannot Register for this Course. Insufficient student level." << endl;
            return false;
        }
    }
    float CalculateExpenses()
    {
        return level * 1000;
    }

};

#endif 