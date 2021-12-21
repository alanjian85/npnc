#include <iostream>

#include "filesystem.hpp"
using namespace npnc;

int main() {
    filesystem fs;
    fs.create_directory("Document");
    fs.create_file("Document/test.txt");
    fs.create_directory("Desktop");
    fs.create_file("Desktop/icon.png");
    fs.create_file("readme.txt");
    for (auto [name, e] : fs.root()) {
        std::cout << name << '\n';
    }
    return 0;
}
