#ifndef LIBS_H
#define LIBS_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>


class Room
{
private:
    const int x;
    const int y;
public:
    Room(int x_arg, int y_arg) : x(x_arg), y(y_arg) {};

    virtual int area() const {
        return x * y;
    }

    virtual std::string to_string() const {
        return "L: " + std::to_string(x) + ", W: " + std::to_string(y);
    }
};


class Building
{
private:
    std::vector<Room> rooms;
public:

    virtual void add_room(int x, int y) {
        rooms.push_back(Room(x, y));
    }

    virtual int total_area() const {
        int room_count = rooms.size();

        int total_area = 0;

        for(const Room& room : rooms) {
            total_area += room.area();
        }

        return total_area;
    }

    virtual int number_of_rooms() const {
        return rooms.size();
    }

    virtual int number_of_janitors() const {
        int janitors_by_area = total_area() / 15;

        if(total_area() % 15 != 0) {
            janitors_by_area++;
        }

        int janitors_by_rooms = number_of_rooms() / 2;

        if(number_of_rooms() % 2 != 0) {
            janitors_by_rooms++;
        }

        return std::max(janitors_by_area, janitors_by_rooms);
    }

    virtual std::string get_all_rooms_as_strings() const {
        std::string s = "";
        for(const Room& room : rooms) {
            s += room.to_string() + "\n";
        }
        return s;
    }
};

#endif 