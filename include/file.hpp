#ifndef NPNC_FILE_HPP
#define NPNC_FILE_HPP

#include <string>

#include "entry.hpp"

namespace npnc {
    class file : public entry {
    public:
        bool is_file() const noexcept override {
            return true;
        }

        size_type size() const override {
            return content.size();
        }

        std::string content;
    };
}

#endif
