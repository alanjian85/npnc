#ifndef NPNC_PATH_HPP
#define NPNC_PATH_HPP

#include <string>
#include <vector>

namespace npnc {
    class path {
    public:
        using iterator = std::vector<std::string>::iterator;
        using const_iterator = std::vector<std::string>::const_iterator;

        path(const char* text);
        path(const std::string& text)
            : path(text.c_str())
        {
        
        }
        
        iterator begin() noexcept {
            return elements_.begin();
        }

        const_iterator begin() const noexcept {
            return elements_.begin();
        }

        iterator end() noexcept {
            return elements_.end();
        }

        const_iterator end() const noexcept {
            return elements_.end();
        }
    private:
        std::vector<std::string> elements_;
    };
}

#endif
