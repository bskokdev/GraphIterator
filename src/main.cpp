#include <iostream>
#include "../include/Reader.h"
#include "../include/Application.h"

int main(int argc, char *argv[]) {
    // Check for valid args
    if(argc < 2) {
        std::cout << "Please provide a file path as an argument" << std::endl;
        return 1;
    }

    Reader reader(argv[1]);
    Application app(reader);
    app.run();
    return 0;
}
