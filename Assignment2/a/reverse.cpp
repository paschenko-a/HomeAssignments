/*
* Pashchenko Alexey
* st141278@student.spbu.ru
* My project number two (a)
*/

#include "reverse.hpp"

#include <fstream>
#include <filesystem>
#include <algorithm>

void myproject::textReverse(std::string pathToFile) {
    int fileSize = std::filesystem::file_size(pathToFile);

    std::ifstream inputFile;
    inputFile.open(pathToFile, std::ios::binary | std::ios::in);

    char* dataArray = new char[fileSize];
    inputFile.read(dataArray, fileSize);
    inputFile.close();

    std::reverse(dataArray, dataArray + fileSize);

    std::ofstream outputFile("output_file.txt",std::ios::binary | std::ios::out);
    outputFile.write(dataArray, fileSize);
    outputFile.close();

    std::cout << "The data is written to the file 'output_file.txt'" << std::endl;
}
