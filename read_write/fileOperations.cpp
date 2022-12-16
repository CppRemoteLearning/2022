#include "fileOperations.h"
#include <iostream>

std::string readStringFromFile(std::string filePath) {
    std::ifstream file;
    std::string fileContents;
    file.open(filePath); // read mode
    if (file.fail()) {
       std::cout << "File failed to open." << std::endl;  
    } 
    else {
        std::stringstream buffer;
        buffer << file.rdbuf();
        fileContents = buffer.str() + "\n";
    }
    file.close();
    return fileContents;
}

void writeStringToFile(std::string stringToWrite, std::string filePath) {
    std::fstream file;
    file.open(filePath, std::ios::out); // write mode
    if(file.fail()) {
       std::cout << "File failed to open." << std::endl; 
    }
    else {
       file << stringToWrite;
    }
    file.close();
}