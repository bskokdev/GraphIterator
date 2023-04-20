#include "../../include/Reader.h"

Reader::Reader(std::string filePath) {
    this->filePath = std::move(filePath);
}

std::vector<std::string> Reader::readLines() {
    std::vector<std::string> lines;
    std::ifstream file(filePath);

    // read file line by line and add to vector
    // if file is not found, return empty vector and print error message
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
    } else {
        std::cout << "Unable to open file: " << filePath << std::endl;
    }
    return lines;
}

std::vector<std::string> Reader::tokenize(std::string &str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}