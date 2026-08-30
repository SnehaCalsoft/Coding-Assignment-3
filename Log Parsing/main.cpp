#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

bool isValidType(string type) {
    return type == "error" ||
           type == "warning" ||
           type == "info" ||
           type == "debug";
}

bool matchesType(string line, vector<string> types) {

    for (int i = 0; i < types.size(); i++) {

        if (types[i] == "error" && line.find("[ERROR]") == 0)
            return true;

        if (types[i] == "warning" && line.find("[WARNING]") == 0)
            return true;

        if (types[i] == "info" && line.find("[INFO]") == 0)
            return true;

        if (types[i] == "debug" && line.find("[DEBUG]") == 0)
            return true;
    }

    return false;
}

int main() {

    // File is in the same folder as main.cpp
    string filePath = "Q1_Log_19_10_17_11_42_01.log";

    // Default values
    int numberOfLines = 10;
    string typeInput = "error";

    // Convert comma-separated types into vector
    vector<string> types;
    string currentType = "";

    for (int i = 0; i <= typeInput.length(); i++) {

        if (i == typeInput.length() || typeInput[i] == ',') {

            if (!isValidType(currentType)) {
                cout << "Invalid log type!" << endl;
                return 1;
            }

            types.push_back(currentType);
            currentType = "";
        }
        else {
            currentType += typeInput[i];
        }
    }

    // Open log file
    ifstream file(filePath);

    if (!file) {
        cout << "Invalid file path!" << endl;
        return 1;
    }

    // Store all lines
    vector<string> lines;
    string line;

    while (getline(file, line)) {
        lines.push_back(line);
    }

    file.close();

    // Start from the end
    int count = 0;

    for (int i = lines.size() - 1;
         i >= 0 && count < numberOfLines;
         i--) {

        if (matchesType(lines[i], types)) {
            cout << lines[i] << endl;
            count++;
        }
    }

    return 0;
}