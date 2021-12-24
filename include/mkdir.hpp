#ifndef NPNC_MKDIR_HPP
#define NPNC_MKDIR_HPP

#include "command.hpp"

namespace npnc {
    class mkdir : public command {
    public:
        using command::command;

        virtual void operator()(const std::vector<std::string>& args) override;
    };
}

#endif
