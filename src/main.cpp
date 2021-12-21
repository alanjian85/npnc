#include <iostream>

#include "directory.hpp"

using namespace npnc;

int main() {
    directory dir;
    dir.create_file("README.txt");
    dir.create_directory("foo");
    dir.create_directory("bar");
    for (auto [name, e] : dir) {
        std::cout << name << " - ";
        if (e.is_file()) {
            std::cout << "file\n";
        } else {
            std::cout << "directory\n";
        }
    }
    return 0;
}
