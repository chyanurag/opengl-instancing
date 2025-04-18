#ifndef UTIL_H
#define UTIL_H
#include <string>
#include <fstream>

std::string read_file(std::string filepath) {
    std::ifstream file(filepath);
    if (file.is_open()) {
        std::string buff, line;
        while (getline(file, line)) {
            buff += line;
            buff += '\n';
        }
        file.close();
        return buff;
    }
    file.close();
    return std::string("");
}
#endif
