#ifndef ROOM_PARSER_H
#define ROOM_PARSER_H

#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <iostream>
#include <format>
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
        std::string building = token;


        if(buildings.find(building) == buildings.end()) {
            Building new_building = Building();
            buildings.insert({building, new_building});
        } 

        buildings[building].add_room(x, y);
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
            std::cout << "building: " << pair.first << ", janitors: " << pair.second.number_of_janitors() << std::endl;
        }
    }

    virtual void save_all() const {
        for(const auto& pair : buildings) {
            std::ofstream outfile(pair.first + ".txt");

            if(!outfile.is_open()) {
                std::cout << "Could not create file: " << pair.first << std::endl;
                return;
            }

            outfile << "Name: " << pair.first << std::endl;
            outfile << "Total area: " << pair.second.total_area() << std::endl;
            outfile << "Amount of rooms: " << pair.second.number_of_rooms() << std::endl;
            outfile << "Needed cleaning staff: " << pair.second.number_of_janitors() << std::endl << std::endl;
            outfile << "Rooms:" << std::endl;
            outfile << pair.second.get_all_rooms_as_strings();

            outfile.close();        
        }
    }

};

#endif
