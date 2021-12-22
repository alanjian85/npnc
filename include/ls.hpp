#ifndef NPNC_LS_HPP
#define NPNC_LS_HPP

#include <iostream>

#include "command.hpp"
#include "filesystem.hpp"

namespace npnc {
    class ls : public command {
    public:
        using command::command;

        virtual void operator()(const std::vector<std::string>& args) override;
    };
}

#endif
