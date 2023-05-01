#ifndef TRANSACTIONDISCOUNTS_READER_H
#define TRANSACTIONDISCOUNTS_READER_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

class Reader {
private:
    string filePath;
public:
    Reader() = default;

    explicit Reader(string filePath);

    vector<string> readLines();
};

#endif //TRANSACTIONDISCOUNTS_READER_H
