#ifndef NPNC_NODE_HPP
#define NPNC_NODE_HPP

#include "filesystem.hpp"

namespace npnc {
    class node {
    public:
        const filesystem& fs() const noexcept {
            return fs_;
        }

        filesystem& fs() noexcept {
            return fs_;
        }
    private:
        filesystem fs_;
    };
}

#endif
