#include <iostream>

#include "node.hpp"
#include "ls.hpp"
using namespace npnc;

int main() {
    node computer;
    auto& fs = computer.fs();
    fs.create_directory("Document");
    fs.create_file("Document/README.txt");
    fs.create_file("test");
    fs.change_directory("Document");
    ls l(computer);
    l({});
    return 0;
}
