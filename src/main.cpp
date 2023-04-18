#include <iostream>
#include "graph/Graph.h"
#include "io/Reader.h"
#include "Application/Application.h"

std::string getFilePathFromArgs(char **argv) {
    std::string filePath = argv[1];
    if (filePath.empty()) {
        std::cout << "Please provide a file path as an argument" << std::endl;
        exit(1);
    }
    return filePath;
}

int main(int argc, char *argv[]) {
    Reader reader(getFilePathFromArgs(argv));
    Application app(reader);

    app.run();
    return 0;
}
