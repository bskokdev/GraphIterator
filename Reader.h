#ifndef GRAPHITERATOR_READER_H
#define GRAPHITERATOR_READER_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <utility>

using namespace std;

class Reader {
private:
    string filePath;
public:
    Reader() = default;

    explicit Reader(string filePath);

    vector<string> readLines();
};

#endif
