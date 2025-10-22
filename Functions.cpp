
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Functions.hpp"

using namespace std;

bool writeFile(
    const string& filename,
    const vector<vector<string>>& data,
    bool append
) {
    ofstream outputFile;

    if (append) {
        outputFile.open(filename, ios::out | ios::app);
    }
    else {
        outputFile.open(filename, ios::out | ios::trunc); // overwrite
    }

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

vector<vector<string>> readFile(const string& filename, int colNumber, const string& colValue) {
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

bool updateFile(
    const string& filename,
    size_t matchColumnIndex,
    const string& matchValue,
    const vector<string>& newRow
) {
    auto data = readFile(filename);
    bool found = false;

    for (auto& row : data) {
        if (row.size() > matchColumnIndex && row[matchColumnIndex] == matchValue) {
            if (row.size() < newRow.size()) {
                row.resize(newRow.size());
            }

            for (size_t i = 0; i < newRow.size(); ++i) {
                if (newRow[i] != "")
                    row[i] = newRow[i];
            }

            found = true;
            break;
        }
    }

    if (found) {
        return writeFile(filename, data, false);
    }
    else {
        return false;
    }
}

bool deleteRowFile(
    const string& filename,
    size_t matchColumnIndex,
    const string& matchValue
) {
    auto data = readFile(filename);
    bool found = false;
    vector<vector<string>> updatedData;

    for (const auto& row : data) {
        if (row.size() > matchColumnIndex && row[matchColumnIndex] == matchValue) {
            found = true; // skip this row
            continue;
        }
        updatedData.push_back(row);
    }

    if (found) {
        return writeFile(filename, updatedData, false);
    }
    else {
        return false;
    }
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