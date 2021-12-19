#ifndef NPNC_ENTRY_HPP
#define NPNC_ENTRY_HPP

#include <string>

namespace npnc {
    class entry {
    public:
        entry() = default;
        entry(std::string name)
            : name_(std::move(name))
        {
        
        }

        const std::string& name() const noexcept {
            return name_;
        }

        void rename(std::string name) noexcept {
            name = std::move(name);
        }
    
        virtual bool is_directory() const noexcept {
            return false;
        }
        
        virtual bool is_file() const noexcept { 
            return false;
        }
    private:
        std::string name_;
    };

    inline bool operator==(const entry& lhs, const std::string& rhs) noexcept {
        return lhs.name() == rhs;
    }
}

#endif
