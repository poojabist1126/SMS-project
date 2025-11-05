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



int main()
{
    Student s;
    Course c;
    Grade g;
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
    }
}