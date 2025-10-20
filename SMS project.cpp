// SMS project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

bool writeTxtFile(
    const string& filename,
    const vector<vector<string>>& data
) {
    ofstream outputFile;

    outputFile.open(filename, ios::out | ios::app);

    if (outputFile.is_open()) {
        for (const auto& row : data) {
            for (size_t i = 0; i < row.size(); ++i) {
                outputFile << row[i];
                if (i < row.size() - 1) {
                    outputFile << "|"; // column separator
                }
            }
            outputFile << "\n";
        }
        outputFile.close();
        return true;
    }
    else
        return false;
}

vector<vector<string>> readTxtFile(const string& filename, int colNumber = -1, const string& colValue = "") {
    vector<vector<string>> data;

    ifstream inputFile(filename);

    if (!inputFile) {
        cerr << "Error: Unable to open file." << endl;
        return data;
    }

    string line;
    while (getline(inputFile, line)) {
        vector<string> row;
        stringstream ss(line);
        string field;

        while (getline(ss, field, '|')) row.push_back(field);

        if (colNumber == -1 || (colNumber >= 0 && colNumber < row.size() && row[colNumber] == colValue)) {
            data.push_back(row);
        }
    }
    return data;
}

void printTable(const vector<vector<string>>& data) {
    if (data.empty()) {
        cout << "No data to display." << endl;
        return;
    }

    
    vector<size_t> colWidths(data[0].size(), 0);
    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            if (i >= colWidths.size()) colWidths.push_back(0);
            colWidths[i] = max(colWidths[i], row[i].length());
        }
    }

    
    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            cout << left << setw(colWidths[i] + 2) << row[i]; 
        }
        cout << endl;
    }
}

class Student {
public:
    string name;
    string roll;
    string address;
    string contact;

    void add() {
        cout << "Name: ";
        getline(cin, name);

        cout << "Address: ";
        getline(cin, address);

        cout << "Contact: ";
        getline(cin, contact);

        roll = string() + contact[0] + name[0] + contact[1] + name[1];

        if (writeTxtFile("student.txt", { {name, address, roll, contact} })) {
            cout << "New Student added successfully." << endl;
        }
        else {
            cout << "Process failed." << endl;
        }
    }

    void view() {
        vector<vector<string>> data = readTxtFile("student.txt");
        printTable(data);
    }

    void edit() {

    }

    void del() {

    }
};


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