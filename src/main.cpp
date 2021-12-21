#include <iostream>

#include "directory.hpp"

using namespace npnc;

int main() {
    directory dir;
    dir.create_file("test");
    dir.create_directory("home");
    for (auto& e : dir) {
        std::cout << e.first << " - ";
        if (e.second->is_file()) {
            std::cout << "file\n";
        } else {
            std::cout << "directory\n";
        }
    }
    return 0;
}
