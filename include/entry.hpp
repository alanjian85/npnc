#ifndef NPNC_ENTRY_HPP
#define NPNC_ENTRY_HPP

#include <cstdlib>
#include <string>

namespace npnc {
    class entry {
    public:
        using size_type = std::size_t;

        virtual ~entry() noexcept = default;

        virtual bool is_directory() const {
            return false;
        }
        
        virtual bool is_file() const { 
            return false;
        }

        virtual size_type size() const = 0;
    private:
        std::string name_;
    };
}

#endif
