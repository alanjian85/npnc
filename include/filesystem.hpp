#ifndef NPNC_FILESYSTEM_HPP
#define NPNC_FILESYSTEM_HPP

#include <stdexcept>

#include "directory.hpp"
#include "path.hpp"

namespace npnc {
    class filesystem {
    public:
        const path& default_path() const noexcept {
            return default_path_;
        }

        void set_default_path(path p) noexcept {
            default_path_ = std::move(p);
        }

        const entry& at(path p) const {
            p = default_path_ + p;
            auto dir = &root_;
            for (auto i = p.cbegin(); i != p.cend() - 1; ++i) {
                if (*i == "/") {
                    dir = &root_;
                    continue;
                }

                dir = dynamic_cast<const directory*>(&dir->at(*i));
                if (!dir)
                    throw std::out_of_range(*i + " is not a directory!");
            }
            return dir->at(*(p.cend() - 1));
        }

        entry& at(const path& p) {
            return const_cast<entry&>(static_cast<const filesystem*>(this)->at(p));
        }

        const entry& operator[](const path& p) const {
            return at(p);
        }

        entry& operator[](const path& p) {
            return at(p);
        }
    private:
        directory root_;
        path default_path_;
    };
}

#endif
