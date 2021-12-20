#include <iostream>

#include "filesystem.hpp"

using namespace npnc;

int main() {
    filesystem fs;
    fs.set_default_path("/home");
    fs["test"];
    return 0;
}
