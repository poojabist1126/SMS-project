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

int main()
{
    Student s;
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
    }
}