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

        std::size_t space() const noexcept override {
            return static_cast<std::size_t>(content_.size());
        }
    private:
        std::string content_;
    };
}

#endif
