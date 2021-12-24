#include "rm.hpp"
using namespace npnc;

#include "node.hpp"

void rm::operator()(const std::vector<std::string>& args) {
    if (args.size() == 1) {
        target().fs().remove(args[0]);
    } else {
        throw std::invalid_argument("Usage: rmdir <dir>\n");
    }
}
