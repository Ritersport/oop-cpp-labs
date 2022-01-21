#include <iostream>
#include "CSVParser.h"
#include "print_tuple.h"




int main(int argc, char* argv[]) {
    std::ifstream inputFile;
    //inputFile.open("test.csv", std::ios::binary);
    
    try {
        if (argc > 1) {
            inputFile.open(argv[1], std::ios::binary);
            if (!inputFile.is_open()) {
                throw std::runtime_error("Can not open file");
            }
        }
        else
            throw std::runtime_error("Enter file name");


        int skipLines = 0;
        if (argc > 2) {
            skipLines = std::stoi(argv[2]);
        }
        CSVParser<std::string, char, double, int> parser(inputFile, skipLines);
        for (auto& rs : parser) {
            std::cout << rs << std::endl;
        }
    }
    catch (std::exception& exeption) {
        std::cout << exeption.what() << std::endl;
    }
    return 0;
}