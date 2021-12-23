#ifndef NPNC_MKDIR_HPP
#define NPNC_MKDIR_HPP

#include <iostream>

#include "command.hpp"

namespace npnc {
    class mkdir : public command {
    public:
        using command::command;

        virtual void operator()(const std::vector<std::string>& args) override {
            if (args.size() == 1) {
                target().fs().create_directory(args[0]);
            } else {
                std::cerr << "Usage: mkdir <dir>\n";
            }
        }
    };
}

#endif
