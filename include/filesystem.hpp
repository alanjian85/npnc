#ifndef NPNC_FILESYSTEM_HPP
#define NPNC_FILESYSTEM_HPP

#include "directory.hpp"
#include "path.hpp"

namespace npnc {
    class filesystem {
    public:
        filesystem()
            : root_("root")
        {
        
        }

        const path& default_path() const noexcept {
            return default_path_;
        }

        void set_default_path(path p) noexcept {
            default_path_ = std::move(p);
        }

        const entry& at(path p) const {
            p = process_path(p);
            auto dir = &root_;
            for (auto i = p.cbegin(); i != p.cend(); ++i) {
                if (*i == "/")
                    continue;

                if (i + 1 == p.cend()) {
                    return (*dir)[*i];
                } else {
                    dir = dynamic_cast<const directory*>(&(*dir)[*i]);
                    if (!dir)
                        throw std::invalid_argument(*i + " is not a folder!");
                }
            }
            throw std::invalid_argument("Path is empty!");
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
        path process_path(const path& p) const noexcept {
            if (!p.empty() && *p.begin() == "/") {
                return p;
            } else {
                return default_path_ + p;
            }
        }

        directory root_;
        path default_path_;
    };
}

#endif
