#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include<string>
#include "Course.h"
#include "NormalCourse.h"
using namespace std;
class Student
{
protected:
    Course *courseList[6];
    int noOfCourses;
    int level;
    double Grades[6];

public:
    // defult constructor
    Student()
    {
        noOfCourses = 0;
        level = 0;

        for(int i = 0 ; i < 6 ; i++)
        {
            courseList[i] = nullptr;
            Grades[i] = 0.0; // 0.0 Because double
        }
    }

    int getlevel()
    {
        return level;
    }
    void setLevel(int l)
    {
        level = l;
    }
    void setGrade(int index, double grade)
    {
            Grades[index] = grade;
    }
    // paramterized contsructor
    Student(int lvl)
    {
        level = lvl;
        noOfCourses = 0;
        for(int i = 0 ; i < 6 ; i++)
        {
            courseList[i] = nullptr;
            Grades[i] = 0.0; // 0.0 Because double
        }
    }
    // Destructor to deallocate memory
    ~Student()
    {
        for (int i = 0 ; i < noOfCourses ; i++)
        {
            delete courseList[i];
        }
    }
    void printRegisteredCourses()
    {

        for (int i = 0 ; i < noOfCourses ; i++)
        {
            cout<<"Course "<<i + 1<<" :"<<endl;
            cout<<*courseList[i]; //for the overloaded operator
            cout<<"Grade: "<<Grades[i]<<endl;
            cout<<"==========================\n";
        }
    }

    virtual float CalculateExpenses() = 0; // pure virtual
    bool RegisterCourse(Course* course)
    {
        if (course->getMinStudentLevel() <= level)
        {
            if (noOfCourses < 6)
            {
                // Make a copy of the course and store it in the courseList
                courseList[noOfCourses] = new Course(*course);
                noOfCourses++;
                return true;
            }
            else
            {
                cout << "Error: Maximum number of courses reached." << endl;
                return false;
            }
        }
        else
        {
            cout << "Error: You cannot register a course older than your level." << endl;
            return false;
        }
    }


    double getTotalGPA()
    {
        double totalgpa = 0;
        int totalcredithours = 0;
        for (int i = 0; i < noOfCourses; i++)
        {
            totalgpa += getCourseGPA(Grades[i]) * courseList[i]->getCreditHours();
            totalcredithours += courseList[i]->getCreditHours();
        }
        return totalgpa / totalcredithours;
    }
    double getCourseGPA(double grade)
    {
        if (grade >= 90)
            return 4.0;
        else if (grade >= 85)
            return 3.7;
        else if (grade >= 80)
            return 3.3;
        else if (grade >= 75)
            return 3.0;
        else if (grade >= 70)
            return 2.7;
        else if (grade >= 65)
            return 2.3;
        else if (grade >= 60)
            return 2.0;
        else if (grade >= 55)
            return 1.7;
        else if (grade >= 50)
            return 1.3;
        else
            return 0.0;
    }


};

#endif