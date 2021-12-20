#include "directory.hpp"
using namespace npnc;

#include <stdexcept>

const entry& directory::at(const std::string& name) const {
    for (auto& f : files_) {
        if (f == name) {
            return f;
        }
    }

    for (auto& dir : directories_) {
        if (dir == name) {
            return dir;
        }
    }

    throw std::out_of_range("Directory " + this->name() + " doesn't contain entry " + name);
}
