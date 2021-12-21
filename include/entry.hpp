#ifndef NPNC_ENTRY_HPP
#define NPNC_ENTRY_HPP

#include <cstdlib>

namespace npnc {
    class entry {
    public: 
        virtual ~entry() {}        

        virtual bool is_directory() const noexcept {
            return false;
        }
        
        virtual bool is_file() const noexcept { 
            return false;
        }

        virtual std::size_t space() const noexcept = 0;
    };
}

#endif
