// SMS project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "StudentClass.hpp"
#include "CourseClass.hpp"
#include "Functions.hpp"
#include "GradeClass.hpp"

using namespace std;

void report_generation() {
    string roll;
    cout << "Enter roll number: ";
    getline(cin, roll);

    vector<vector<string>> grade = readFile("grade.txt", 0, roll);
    vector<vector<string>> student = readFile("student.txt", 2, roll);

    if (student.size() == 0) {
        cout << "Student is not registered." << endl;
        return;
    }

    if (grade.size() == 0) {
        cout << "Grade is not added." << endl;
        return;
    }

    vector<vector<string>> course = readFile("course.txt", 0, grade[0][1]);

    cout << "Pokeno South Primary School" << endl;
    cout << "Report Certificate" << endl;
    cout << "Name: " << student[0][0] << endl;
    cout << "Adress: " << student[0][1] << endl;
    cout << "Roll number: " << student[0][2] << endl;

    printTable({ {"Course Name", "Grade"}, { course[0][1], grade[0][2] } });
}

int main()
{
    Student s;
    Course c;
    Grade g;
    string commands;

    cout << "POKENOHE SCHOOL" << endl;
    cout << "Student Management System" << endl;

    while (true) {
        cout << "-- ";
        getline(cin, commands);

        if (commands == "add student") {
            s.add();
        }
        else if (commands == "view student") {
            s.view();
        }
        else if (commands == "edit student") {
            s.edit();
        }
        else if (commands == "del student") {
            s.del();
        }
        else if (commands == "add course") {
            c.add();
        }
        else if (commands == "view course") {
            c.view();
        }
        else if (commands == "edit course") {
            c.edit();
        }
        else if (commands == "del course") {
            c.del();
        }
        else if (commands == "add grade") {
            g.add();
        }
        else if (commands == "view grade") {
            g.view();
        }
        else if (commands == "edit grade") {
            g.edit();
        }
        else if (commands == "del grade") {
            g.del();
        }
        else if (commands == "view report") {
            report_generation();
        }
        else {
            cout << "Command not found." << endl;
        }
    }
}