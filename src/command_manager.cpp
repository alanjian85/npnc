#include "command_manager.hpp"
using namespace npnc;

#include "ls.hpp"
#include "mkdir.hpp"
#include "rm.hpp"

command_manager::command_manager(node& target) {
    commands_["ls"] = std::make_unique<ls>(target);
    commands_["mkdir"] = std::make_unique<mkdir>(target);
    commands_["rm"] = std::make_unique<rm>(target);
}
