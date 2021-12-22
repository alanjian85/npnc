#ifndef NPNC_LS_HPP
#define NPNC_LS_HPP

#include <iostream>

#include "command.hpp"
#include "filesystem.hpp"

namespace npnc {
    class ls : public command {
    public:
        ls(const filesystem& fs)
            : filesystem_(fs)
        {
        
        }

        void operator()(const std::vector<std::string>& args) override {
            if (args.size() == 0) {
                for (auto [name, _] : static_cast<const directory&>(filesystem_.current_directory())) {
                    std::cout << name << '\n';        
                }
            } else if (args.size() == 1) {
                auto& dir = filesystem_[args[0]];
                if (dir.is_directory()) {
                    for (auto [name, _] : static_cast<const directory&>(dir)) {
                        std::cout << name << '\n';
                    }
                } else {
                    std::cout << args[0] << '\n';
                }
            } else {
                std::cerr << "Usage: ls [path]\n";
            }
        }
    private:
        const filesystem& filesystem_;
    };
}

#endif
