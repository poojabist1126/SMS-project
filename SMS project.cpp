// SMS project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "StudentClass.hpp"
#include "Functions.hpp"

using namespace std;

class Course {
private:
    string courseCode;
    string title;
    string descp;
    string teacher;

public:
    void add() {
        cout << "Enter Course Code: ";
        getline(cin, courseCode);

        cout << "Enter Title: ";
        getline(cin, title);

        cout << "Enter Description: ";
        getline(cin, descp);

        cout << "Enter Assigned Teacher: ";
        getline(cin, teacher);
            
        if (writeFile("course.txt", { {courseCode, title, descp, teacher} })) {
            cout << "New course added successfully." << endl;
        }
        else {
            cout << "Process failed." << endl;
        }
    }
};

int main()
{
    Student s;
    Course c;
    string commands;

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
    }
}