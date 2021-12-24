#include "mkdir.hpp"
using namespace npnc;

#include <iostream>

#include "node.hpp"

void mkdir::operator()(const std::vector<std::string>& args) {
    if (args.size() == 1) {
        target().fs().create_directory(args[0]);
    } else {
        std::cerr << "Usage: mkdir <dir>\n";
    }
}
