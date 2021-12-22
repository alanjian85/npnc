#include <iostream>

#include "filesystem.hpp"
#include "ls.hpp"
using namespace npnc;

int main() {
    filesystem fs;
    fs.create_directory("Document");
    fs.create_file("Document/README.txt");
    fs.create_file("test");
    ls l(fs);
    l({"Document"});
    return 0;
}
