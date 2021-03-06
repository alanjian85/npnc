#include "filesystem.hpp"
using namespace npnc;

#include <stdexcept>

void filesystem::change_directory(path p) {
    auto& dir = at(p);
    if (dir.is_directory()) {
        current_directory_ = static_cast<const directory*>(&dir);
    } else {
        throw std::invalid_argument("Desired current path is not in a directory!");
    } 
    current_path_ = std::move(p);
}


const entry& filesystem::at(path p) const {
    auto res = static_cast<const entry*>(current_directory_);
    for (auto e : p) {
        if (e == "/") {
            res = &root_;
            continue;
        }
        if (res->is_directory()) {
            res = &static_cast<const directory*>(res)->at(e);
        } else {
            throw std::invalid_argument(std::string(e) + " is not in a directory!");
        }
    }
    return *res;
}


bool filesystem::exist(path p) const noexcept {
    auto res = static_cast<const entry*>(current_directory_);
    for (auto e : p) {
        if (!res) {
            return false;
        }
        if (e == "/") {
            res = &root_;
            continue;
        }
        if (res->is_directory()) {
            auto& dir = static_cast<const directory&>(*res);
            if (dir.exist(e)) {
                res = &dir.at(e);
            } else {
                return false;
            }
        } else {
            res = nullptr;
        }
    }

    return true;
}