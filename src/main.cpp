#include <iostream>

#include "path.hpp"

using namespace npnc;

int main() {
    path p = "/hello/world/test.txt";
    for (auto& e : p) {
        std::cout << e << " | ";
    }
    std::cout << '\n';
    return 0;
}
