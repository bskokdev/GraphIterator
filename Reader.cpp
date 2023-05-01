#include "Reader.h"

Reader::Reader(std::string filePath) {
    this->filePath = std::move(filePath);
}

vector<string> Reader::readLines() {
    vector<std::string> lines;
    ifstream file(filePath);

    // read file line by line and add to vector
    // if file is not found, return empty vector and print error message
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
    } else {
        cout << "Unable to open file: " << filePath << endl;
    }
    return lines;
}
