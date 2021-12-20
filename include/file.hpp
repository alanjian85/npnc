#ifndef NPNC_FILE_HPP
#define NPNC_FILE_HPP

#include "entry.hpp"

namespace npnc {
    class file : public entry {
    public:
        using entry::entry;

        bool is_file() const noexcept override {
            return true;
        }

        std::string::size_type space() const noexcept {
            return content_.size();
        }
    private:
        std::string content_;
    };
}

#endif
