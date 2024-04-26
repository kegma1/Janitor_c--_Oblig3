#include <iostream>
#include <string>
#include "libs.h"
#include "file_reader.h"
#include "room_parser.h"

int main() {
    std::string path;
    std::cout << "enter a filepath [default: 'Input_rom-1.txt']" << std::endl;
    std::getline(std::cin, path);
    if(path.empty()) 
        path = "Input_rom-1.txt";

    std::cout << "Reading " << path << "..." << std::endl;

    Parser p = Parser(path);
    p.parse_file();
    p.save_all();
    return 0;
}

