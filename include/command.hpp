#ifndef NPNC_COMMAND_HPP
#define NPNC_COMMAND_HPP

#include <string>
#include <vector>

namespace npnc {
    class command {
    public:
        virtual ~command() {
        
        }

        virtual void operator()(const std::vector<std::string>& args) {

        }
    };
}

#endif
