#ifndef NPNC_EXECUTION_HPP
#define NPNC_EXECUTION_HPP

#include <string>
#include <vector>

namespace npnc {
    struct execution {
        explicit execution(const std::string& str);

        std::string cmd;
        std::vector<std::string> args;
    };
}

#endif
