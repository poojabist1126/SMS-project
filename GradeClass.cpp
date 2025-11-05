#include <iostream>
#include <string>
#include <vector>
#include "GradeClass.hpp"
#include "Functions.hpp"

using namespace std;

void Grade::add() {
    cout << "Enter student roll: ";
    getline(cin, roll);

    vector<vector<string>> data = readFile("student.txt", 2, roll);

    if (data.size() <= 0) {
        cout << "Student is not registered." << endl;
        return;
    }

    cout << "Enter Course Code: ";
    getline(cin, courseCode);

    data = readFile("course.txt", 0, courseCode);

    if (data.size() <= 0) {
        cout << "Course is not registered." << endl;
        return;
    }

    cout << "Enter marks:";
    getline(cin, marks);

    if (writeFile("grade.txt", { {roll, courseCode, marks} })) {
        cout << "Marks added successfully." << endl;
    }
    else
        cout << "Process failed." << endl;
}



void Grade::view() {
    vector<vector<string>> data = readFile("grade.txt");
    printTable(data);
}

void Grade::edit() {

    cout << "Enter student roll to edit: ";
    getline(cin, roll);

    vector<vector<string>> data = readFile("student.txt", 2, roll);

    if (data.size() <= 0) {
        cout << "Student is not registered." << endl;
        return;
    }

    cout << "courseCode:";
    getline(cin, courseCode);

    data = readFile("course.txt", 0, courseCode);

    if (data.size() <= 0) {
        cout << "Course is not registered." << endl;
        return;
    }

    cout << "Marks:";
    getline(cin, marks);

    if (updateFile("grade.txt", 0, roll, { "",courseCode,marks })) {
        cout << "Student info updated successfully." << endl;
    }
    else
        cout << "Process failed." << endl;
}

void Grade::del() {

    cout << "Enter student roll to edit:";
    getline(cin, roll);

    if (deleteRowFile("grade.txt", 0, roll)) {
        cout << "Grade deleted successfully." << endl;

    }
    else {
        cout << "Process failed." << endl;
    }
}
