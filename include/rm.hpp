#ifndef NPNC_RM_HPP
#define NPNC_RM_HPP

#include "command.hpp"

namespace npnc {
    class rm : public command {
    public:
        using command::command;

        virtual void operator()(const std::vector<std::string>& args) override;
    };
}

#endif
