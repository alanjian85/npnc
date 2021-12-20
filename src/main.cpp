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

    d.create_directory("Desktop");
    std::cout << "Create directory Desktop\n";

    d.create_file("bar");
    std::cout << "Create file bar\n";
    if (d.create_directory("bar")) {
        std::cout << "Create directory bar: SUCCESS\n";
    } else {
        std::cout << "Create directory bar: FAILED\n";
    }

    if (auto p = dynamic_cast<file*>(&d["bar"])) {
        std::cout << "bar is a file\n";
    } else if (auto p = dynamic_cast<directory*>(&d["bar"])) {
        std::cout << "bar is a directory\n";        
    }

    std::cout << "bar exist: " << d.exist("bar") << '\n';

    std::cout << "List:\n";
    for (auto& e : d) {
        if (e.is_file())
            std::cout << '\t' << e.name() << " - file\n";
        else
            std::cout << '\t' << e.name() << " - directory\n";
    }

    return 0;
}
