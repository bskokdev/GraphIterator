#include <iostream>
#include "io/Reader.h"
#include "Application/Application.h"

/**
 * @brief gets the file path from the arguments
 * @param argv input file path
 * @return input file path as string
 */
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
