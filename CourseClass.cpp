#include <iostream>
#include <string>
#include <vector>
#include "CourseClass.hpp"
#include "Functions.hpp"

using namespace std;

void Course::add() {
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



void Course::view() {
    vector<vector<string>> data = readFile("course.txt");
    printTable(data);
}

void Course::edit() {
    cout << "Enter course code to edit:";
    getline(cin, courseCode);

    cout << "Title:";
    getline(cin, title);

    cout << "Description:";
    getline(cin, descp);

    cout << "Teacher Assigned:";
    getline(cin, teacher);

    if (updateFile("course.txt", 0, courseCode, { courseCode, title,descp, teacher })) {
        cout << "Course updated sucessfully." << endl;

    }
    else
        cout << "Process failed." << endl;
}

void Course::del() {
    
    cout << "Enter course code to edit:";
    getline(cin, courseCode);

    if (deleteRowFile("course.txt", 0, courseCode)) {
        cout << "courseCode deleted successfully." << endl;
    }
    else {
        cout << "Process failed." << endl;
    }

}
