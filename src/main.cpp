#include <iostream>

#include "node.hpp"
#include "command_manager.hpp"
using namespace npnc;

int main() {
    node computer;
    auto& fs = computer.fs();
    fs.create_directory("Document");
    fs.create_file("Document/README.txt");
    fs.create_file("test");
    fs.change_directory("Document");
    computer.execute("mkdir", {"temp"});
    computer.execute("ls", {});
    return 0;
}
