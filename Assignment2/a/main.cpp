/*
* Pashchenko Alexey
* st141278@student.spbu.ru
* My project number two (a)
*/

#include "reverse.hpp"

int main() {
    std::cout << "Enter the path to the file\n";
    std::cout << "or write 'default' (the default 'input_file.txt' will be used)\n";
    std::string pathToFile;
    std::cin >> pathToFile;
    if (pathToFile == "default") {
        pathToFile = "input_file.txt";
    }

    myproject::textReverse(pathToFile);
    return 0;
}
