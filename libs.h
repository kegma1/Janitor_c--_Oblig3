#ifndef LIBS_H
#define LIBS_H

#include <vector>
#include <iostream>

class Room
{
private:
    int x;
    int y;
public:
    Room(int x_arg, int y_arg) : x(x_arg), y(y_arg) {};

    virtual int area() const {
        return x * y;
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

    virtual int get_number_of_janitors() const {
        return  1 + (total_area() / 15);
    }
};

#endif 