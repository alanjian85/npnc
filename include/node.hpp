#ifndef NPNC_NODE_HPP
#define NPNC_NODE_HPP

#include <string>

#include "command_manager.hpp"
#include "filesystem.hpp"

namespace npnc {
    class node {
    public:
        node()
            : commands_(*this)
        {
            
        }

        const filesystem& fs() const noexcept {
            return fs_;
        }

        filesystem& fs() noexcept {
            return fs_;
        }

        void execute(const std::string& cmd, const std::vector<std::string>& args) const {
            commands_[cmd](args);
        }
    private:
        filesystem fs_;
        command_manager commands_;;
    };
}

#endif
