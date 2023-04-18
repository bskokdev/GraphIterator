#ifndef TRANSACTIONDISCOUNTS_READER_H
#define TRANSACTIONDISCOUNTS_READER_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

/**
 * @brief Class for reading lines from a file
 */
class Reader {
private:
    std::string filePath;
public:
    Reader() = default;

    /**
     * @brief Construct a new Reader object
     * @param filePath
     */
    explicit Reader(std::string filePath);

    /**
     * @brief Read all lines from file and return them as a vector
     * @details If the file is not found empty vector is returned and error message is printed
     * @return std::vector<std::string>
     */
    std::vector<std::string> readLines();

    /**
     * @brief Tokenize the given string by the given delimiter
     * @param str String to tokenize
     * @return vector of tokens
     */
    static std::vector<std::string> tokenize(std::string &str, char delimiter);
};


#endif //TRANSACTIONDISCOUNTS_READER_H
