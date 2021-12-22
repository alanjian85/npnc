#ifndef NPNC_COMMAND_HPP
#define NPNC_COMMAND_HPP

#include <string>
#include <vector>

#include "node.hpp"

namespace npnc {
    class command {
    public:
        command(node& target) 
            : target_(target)
        {
        
        }

        node& target() const noexcept {
            return target_;
        }

        virtual ~command() {
        
        }

        virtual void operator()(const std::vector<std::string>& args) = 0;
    private:
        node& target_;
    };
}

#endif
