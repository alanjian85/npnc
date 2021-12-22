#ifndef NPNC_FILESYSTEM_HPP
#define NPNC_FILESYSTEM_HPP

#include <stdexcept>

#include "directory.hpp"
#include "path.hpp"

namespace npnc {
    class filesystem {
    public:
        filesystem() {
            current_directory_ = &root_;
        }

        const path& current_path() const noexcept {
            return current_path_;
        }

        void set_current_path(path p) {
            current_directory_ = &root_;
            auto& dir = at(p);
            if (dir.is_directory()) {
                current_directory_ = static_cast<const directory*>(&dir);
            } else {
                throw std::invalid_argument("Desired current path is not in a directory!");
            }
            current_path_ = std::move(p);
        }

        const entry& at(path p) const {
            auto res = current_directory_;
            if (!p.empty() && *p.cbegin() == "/") {
                res = &root_;
            }

            for (auto& e : p) {
                if (res->is_directory()) {
                    res = &static_cast<const directory*>(res)->at(e);
                } else {
                    throw std::invalid_argument(e + " is not in a directory!");
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

        bool exist(path p) const noexcept {
            auto res = current_directory_;
            if (!p.empty() && *p.cbegin() == "/") {
                res = &root_;
            }

            for (auto& e : p) {
                if (!res) {
                    return false;
                }

                if (res->is_directory()) {
                    auto dir = static_cast<const directory&>(*res);
                    if (dir.exist(e)) {
                        res = &dir.at(e);
                    } else {
                        return false;
                    }
                } else {
                    res = nullptr;
                }
            }

            return true;
        }

        bool create_file(path p) {
            auto res = const_cast<entry*>(current_directory_);
            for (auto i = p.cbegin(); i != p.cend() - 1; ++i) {
                res = &static_cast<directory*>(res)->at(*i);
                if (!res->is_directory()) {
                    throw std::invalid_argument(*i + " is not a directory!");
                }
            }
            return static_cast<directory*>(res)->create_file(*(p.cend() - 1));
        }

        bool create_directory(path p) {
            auto res = const_cast<entry*>(current_directory_);
            for (auto i = p.cbegin(); i != p.cend() - 1; ++i) {
                res = &static_cast<directory*>(res)->at(*i);
                if (!res->is_directory()) {
                    throw std::invalid_argument(*i + " is not a directory!");
                }
            }
            return static_cast<directory*>(res)->create_directory(*(p.cend() - 1));
        }

        const directory& root() const noexcept {
            return root_;
        }
    private:
        directory root_;
        path current_path_;
        const entry* current_directory_;
    };
}

#endif
