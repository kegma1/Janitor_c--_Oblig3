#ifndef FILE_READER_H
#define FILE_READER_H

#include <iostream>
#include <fstream>
#include <string>

class FileReader
{
private:
    std::ifstream file;
    std::string line;
public:
    FileReader(std::string path) {
        file.open(path);

        if (!file.is_open()) {
            std::cout << "Unable to open file\n";
            return;
        }
    }

    ~FileReader() {
        file.close();
    }

    virtual int next_line() {
        if(std::getline(file, line)){
            return 1;
        }
        return 0;
    }

    virtual std::string current_line() const {
        return line;
    }
};

#endif
