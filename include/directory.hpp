#ifndef NPNC_DIRECTORY_HPP
#define NPNC_DIRECTORY_HPP

#include <string>
#include <vector>

#include "file.hpp"

namespace npnc {
    class directory {
    private:
        std::string name_;
        std::vector<directory> directories_;
        std::vector<file> files_;
    };
}

#endif
