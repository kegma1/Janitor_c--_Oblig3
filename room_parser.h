#ifndef ROOM_PARSER_H
#define ROOM_PARSER_H

#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <iostream>
#include "file_reader.h"
#include "libs.h"

class Parser
{
private:
    FileReader reader;
    std::map<std::string, Building> buildings;

public:
    Parser(std::string path): reader(path) {};

    virtual int parse_line() {
        std::string line = reader.current_line();
        std::istringstream iss(line);
        std::string token;

        std::getline(iss, token, ' ');
        int x = std::stoi(token);
        std::getline(iss, token, ' ');
        int y = std::stoi(token);
        std::getline(iss, token, ' ');
        std::string buinding = token;


        if(buildings.find(buinding) == buildings.end()) {
            buildings.insert({buinding, Building()});
        } 

        buildings[buinding].add_room(x, y);
        return 0;
    }

    virtual int parse_file() {
        while (reader.next_line()){
            parse_line();
        }

        return 0;
    }

    virtual void print_raw() const {
        for(const auto& pair : buildings) {
            std::cout << "building: " << pair.first << ", janitors: " << pair.second.get_number_of_janitors() << std::endl;
        }
    }

};

#endif
