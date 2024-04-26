#include <iostream>
#include <string>
#include "libs.h"
#include "file_reader.h"
#include "room_parser.h"

int main() {
    Parser p = Parser("Input_rom-1.txt");
    p.parse_file();
    p.print_raw();
    return 0;
}

