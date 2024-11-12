#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

// Function to read a file
std::string readFile(const std::string& filePath) {
    std::ifstream inputFile(filePath, std::ios::in);
    if (!inputFile) {
        throw std::runtime_error("Error: Cannot open the file '" + filePath + "'.");
    }
    std::string content((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    inputFile.close();
    return content;
}

// Function to write to a file
void writeFile(const std::string& filePath, const std::string& content) {
    std::ofstream outputFile(filePath, std::ios::out | std::ios::trunc);
    if (!outputFile) {
        throw std::runtime_error("Error: Cannot create the file '" + filePath + "'.");
    }
    outputFile << content;
    outputFile.close();
}

#endif // FILEUTILS_H

