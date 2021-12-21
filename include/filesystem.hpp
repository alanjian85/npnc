#ifndef NPNC_FILESYSTEM_HPP
#define NPNC_FILESYSTEM_HPP

#include <stdexcept>

#include "directory.hpp"
#include "path.hpp"

namespace npnc {
    class filesystem {
    public:
        const path& current_path() const noexcept {
            return current_path_;
        }

        void set_current_path(path p) noexcept {
            current_path_ = std::move(p);
        }

        const entry& at(path p) const {
            p = current_path_ + p;
            auto res = static_cast<const entry*>(&root_);
            for (auto& e : p) {
                if (e == "/") {
                    res = &root_;
                    continue;
                }

                if (res->is_directory()) {
                    res = &static_cast<const directory*>(res)->at(e);
                } else {
                    throw std::out_of_range(e + " is not in a directory");
                }
            }
            return *res;
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

        bool create_file(path p) {
            p = current_path_ + p;
            auto dir = &root_;
            for (auto i = p.cbegin(); i != p.cend() - 1; ++i) {
                if (*i == "/") {
                    dir = &root_;
                    continue;
                }

                dir = dynamic_cast<directory*>(&dir->at(*i));
                if (!dir) {
                    return false;
                }
            }
            dir->create_file(*(p.cend() - 1));
            return true;
        }

        bool create_directory(path p) {
            p = current_path_ + p;
            auto dir = &root_;
            for (auto i = p.cbegin(); i != p.cend() - 1; ++i) {
                if (*i == "/") {
                    dir = &root_;
                    continue;
                }

                dir = dynamic_cast<directory*>(&dir->at(*i));
                if (!dir) {
                    return false;
                }
            }
            dir->create_directory(*(p.cend() - 1));
            return true;
        }

        const directory& root() const noexcept {
            return root_;
        }
    private:
        directory root_;
        path current_path_;
    };
}

#endif
