#include <iostream>

#include "filesystem.hpp"
using namespace npnc;

int main() {
    filesystem fs;
    fs.root_.create_directory("home");
    static_cast<directory&>(fs.root_["home"]).create_directory("hello.txt");
    auto& e = fs["home/hello.txt"];
    if (e.is_file()) {
        std::cout << "hello.txt is a file!\n";
    } else {
        std::cout << "hello.txt is a directory!\n";
    }
    return 0;
}
