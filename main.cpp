#include <iostream>
#include <string>
#include "Student.h"
#include "SpecialStudent.h"
#include "GeneralStudent.h"
#include "Course.h"
#include "NormalCourse.h"
#include "SummerCourse.h"

Course* COURSES[] = {
        new NormalCourse("Math", 1, 2),
        new NormalCourse("Programming_1", 1, 3),
        new NormalCourse("Technical_Writing", 1, 3),
        new NormalCourse("Electronics", 2, 4),
        new NormalCourse("Data_Structures", 2, 3),
        new NormalCourse("OOP", 2, 3),
        new NormalCourse("Algorithms", 3, 2),
        new NormalCourse("Operating_Systems", 3, 3),
        new NormalCourse("Databases", 3, 3),
        new NormalCourse("Machine_Learning", 4, 3),
        new NormalCourse("Compilers", 4, 4),
        new NormalCourse("Programming_Concepts", 4, 4),
        new SummerCourse("Math", 1, 2),
        new SummerCourse("Compilers", 4, 4),
        new SummerCourse("Algorithms", 3, 2),
        new SummerCourse("OOP", 2, 3)
};


Course *searchCourse(string &code)
{
    for (int i = 0; i < sizeof(COURSES) / sizeof(Course *) ;i++)
    {
        if (COURSES[i]->getCode() == code)
        {
            return COURSES[i];
        }

    }
    return nullptr;
}

int main()
{
    int numStudents;

    cout<<"Enter the number of the students: ";
    cin>>numStudents;

    int StudentType; // Bool function 0 or 1
    string name;
    int Id;
    int Level;
    int numofcourse;



    for(int i = 0 ;i < numStudents ; i++)
    {
        cout<<"Enter Student Type ( 0 is for general and 1 for special): ";
        cin>>StudentType;

        cout<<"Enter the name of the student: ";
        cin.ignore();
        getline(cin,name);

        cout<<"Enter the Id of the student: ";
        cin>>Id;

        cout<<"Enter the level of the student: ";
        cin>>Level;

        cout<<"Enter the Number of registered Courses: ";
        cin>>numofcourse;
        Student *student;
        Course foundcourse;

        if(StudentType == 0)
        {
            student = new GeneralProgramStudent();
        }
        else if(StudentType == 1)
        {
            student = new SpecialProgramStudent();
        }
        foundcourse.setName(name);
        student->setLevel(Level);

        cout<<"Enter the courses you entered by the following questions"<<endl;

        for(int j = 0 ; j < numofcourse ; j++)
        {
            string code;
            bool courseFound = false;
            while (!courseFound)
            {
                cout<<endl;
                cout << "Course " << j + 1 << ":" << endl;
                cout << "Code: ";
                cin >> code;

                Course *foundcourse = searchCourse(code);
                if (foundcourse)
                {
                    bool Registered = student->RegisterCourse(foundcourse);
                    if (Registered)
                    {
                        double Grade;
                        cout<<"enter the grade of the course: "<<endl;
                        cin >> Grade;
                        cout<<"Grade:"<<Grade;
                        student->setGrade(j, Grade);
                        courseFound = true;
                    }
                    else
                    {
                        cout << "Error: You Cannot Register this Course" << endl;
                        cout << "Please enter a valid course code." << endl;
                    }
                }
                else
                {
                    cout << "Error: Course Not found!" << endl;
                    cout << "Please enter a valid course code." << endl;

                }

            }
        }
        cout<<endl;
        cout<<"Student Name: "<<name<<endl;
        cout<<"ID: "<<Id<<endl;
        cout<<"Level: "<<student->getlevel()<<endl;
        cout<<"Registered courses "<<endl;
        student->printRegisteredCourses();

        cout<<"Student expenses: "<<endl;
        cout<<student->CalculateExpenses()<<endl;
        cout<<"Student overall GPA: "<<endl;
        cout<<student->getTotalGPA()<<endl;
        delete student;
    }
    for(int i = 0 ; i < sizeof (COURSES) / sizeof(Course *); i++) // Changed the loop condition
    {
        delete  COURSES[i]; // Fixed array element deletion
    }


    return 0;
}