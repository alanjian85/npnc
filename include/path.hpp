#ifndef NPNC_PATH_HPP
#define NPNC_PATH_HPP

#include <string>
#include <vector>

namespace npnc {
    class path {
        friend path operator+(const path& lhs, const path& rhs) noexcept;
    public:
        using iterator = std::vector<std::string>::iterator;
        using const_iterator = std::vector<std::string>::const_iterator;

        path() = default;
        path(const char* text);
        path(const std::string& text)
            : path(text.c_str())
        {
        
        }

        bool empty() const noexcept {
            return elements_.empty();
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
    
        const_iterator cbegin() const noexcept {
            return begin();
        }

        const_iterator cend() const noexcept {
            return end();
        }
    private:
        std::vector<std::string> elements_;
    };

    inline path operator+(const path& lhs, const path& rhs) noexcept {
        if (!rhs.empty() && *rhs.begin() == "/") {
            return rhs;
        } else {
            auto res = lhs;
            res.elements_.insert(res.elements_.cend(), rhs.elements_.cbegin(), rhs.elements_.cend());
            return res; 
        }
    }
}

#endif
