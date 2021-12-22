#include "ls.hpp"
using namespace npnc;

void ls::operator()(const std::vector<std::string>& args) {
    if (args.size() == 0) {
        for (auto [name, _] : static_cast<const directory&>(node().fs().current_directory())) {
            std::cout << name << '\n';
        }
    } else if (args.size() == 1) {
        auto& dir = node().fs()[args[0]];
        if (dir.is_directory()) {
            for (auto [name, _] : static_cast<const directory&>(dir)) {
                std::cout << name << '\n';
            }
        } else {
            std::cout << args[0] << '\n';
        }
    } else {
        std::cerr << "Usage: ls [path]\n";
    }
}
