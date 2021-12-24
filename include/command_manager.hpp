#ifndef NPNC_COMMAND_MANAGER_HPP
#define NPNC_COMMAND_MANAGER_HPP

#include <map>
#include <memory>
#include <stdexcept>
#include <string>

#include "command.hpp"

namespace npnc {
    class command_manager {
    public:
        command_manager(node& target);
    
        command& operator[](const std::string& cmd) const {
            auto it = commands_.find(cmd);
            if (it != commands_.cend()) {
                return *it->second; 
            } else {
                throw std::out_of_range("Unknown command: " + cmd);
            }
        }
    private:
        std::map<std::string, std::unique_ptr<command>> commands_;
    };
}

#endif
