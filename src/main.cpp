#include <iostream>

#include "node.hpp"
#include "execution.hpp"
using namespace npnc;

int main() {
    node n;
    for (;;) {
        std::cout << "> ";
        std::string l;
        std::getline(std::cin, l);
        
        execution e(l);
        n.execute(e.cmd, e.args);
    }
    return 0;
}
