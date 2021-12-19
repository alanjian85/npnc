#include <iostream>

#include "directory.hpp"

using namespace npnc;

int main() {
    std::cout << std::boolalpha; 
    directory d;
    
    d.create_file("foo");
    std::cout << "Create file foo\n";

    std::cout << "foo exist: " << d.exist("foo") << '\n';

    d.remove("foo");
    std::cout << "Remove foo\n";
    
    std::cout << "foo exist: " << d.exist("foo") << '\n';

    d.create_file("bar");
    std::cout << "Create file bar\n";
    if (d.create_directory("bar")) {
        std::cout << "Create directory bar: SUCCESS\n";
    } else {
        std::cout << "Create directory bar: FAILED\n";
    }

    std::cout << "bar exist: " << d.exist("bar") << '\n';

    return 0;
}
