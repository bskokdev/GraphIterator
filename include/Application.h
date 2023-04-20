#ifndef TRANSACTIONDISCOUNTS_APPLICATION_H
#define TRANSACTIONDISCOUNTS_APPLICATION_H


#include "Reader.h"
#include "Graph.h"

/**
 * @brief Class for running the application
 * @details Depends on the Reader class
 */
class Application {
private:
    Reader reader;
public:
    Application() = default;

    /**
     * @brief Construct a new Application object
     * @param reader Reader object
     */
    explicit Application(Reader reader);

    /**
     * @brief Run the application
     * @details Reads the file and prints the result
     */
    void run();
};


#endif //TRANSACTIONDISCOUNTS_APPLICATION_H
