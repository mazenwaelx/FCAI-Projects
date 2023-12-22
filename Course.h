#ifndef COURSE_H
#define COURSE_H
#include<iostream>
#include<string>
using namespace std;
class Course
{
protected:
    string Name;
    string Code;
    int MinStudentLevel;
    int CreditHours;

public:
    Course() : Name(""), MinStudentLevel(0), CreditHours(0) {}

    Course(string name, int lvl, int creditH) : Name(name), MinStudentLevel(lvl), CreditHours(creditH) {}

    void setName(string name)
    {
        name = Name;
    }
    string getName()
    {
        return Name;
    }
    void setCode(string code)
    {
        Code = code;
    }
    string getCode()
    {
        return Code;
    }
    int getCreditHours()
    {
        return CreditHours;
    }
    int getMinStudentLevel()
    {
        return MinStudentLevel;
    }


    friend ostream &operator<<(ostream &os, Course &course);

};

ostream &operator<<(ostream &os, Course &course)
{
    os << "Course Name is: " << course.Name << endl;
    os << "Course code is: " << course.Code << endl;
    os << "Min Student Level: " << course.MinStudentLevel << endl;
    os << "Credit Hours: " << course.CreditHours << endl;
    return os;
}

#endif