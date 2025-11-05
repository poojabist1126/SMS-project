#include <iostream>
#include <string>
#include <vector>
#include "StudentClass.hpp"
#include "Functions.hpp"

using namespace std;

void Student::add() {
    cout << "Name: ";
    getline(cin, name);

    cout << "Address: ";
    getline(cin, address);
  



    cout << "Contact: ";
    getline(cin, contact);

    roll = string() + contact[0] + name[0] + contact[1] + name[1];

    if (writeFile("student.txt", { {name, address, roll, contact} })) {
        cout << "New Student added successfully." << endl;
    }
    else {
        cout << "Process failed." << endl;
    }
}
     


void Student::view() {
    vector<vector<string>> data = readFile("student.txt");
    printTable(data);
}

void Student::edit() {
    cout << "Enter student roll to edit: ";
    getline(cin, roll);

    cout << "Name: ";
    getline(cin, name);

    cout << "Address: ";
    getline(cin, address);

    cout << "Contact: ";
    getline(cin, contact);

    if (updateFile("student.txt", 2, roll, { name, address, "", contact })) {
        cout << "Student info updated successfully." << endl;
    }
    else
        cout << "Process failed." << endl;
}

void Student::del() {
    cout << "Enter student roll to edit: ";
    getline(cin, roll);

    if (deleteRowFile("student.txt", 2, roll)) {
        cout << "Student deleted successfully." << endl;
    }
    else {
        cout << "Process failed." << endl;
    }
}
