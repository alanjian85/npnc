#ifndef NPNC_DIRECTORY_HPP
#define NPNC_DIRECTORY_HPP

#include <algorithm>
#include <functional>
#include <stdexcept>
#include <vector>
#include <numeric>

#include "entry.hpp"
#include "file.hpp"

namespace npnc {
    class directory : public entry {
    public:
        using entry::entry;

        bool is_directory() const noexcept override {
            return true;
        }

        std::string::size_type size() const noexcept {
            auto fs = static_cast<std::string::size_type>(0);
            for (auto& f : files_) {
                fs += f.size();
            }
            auto ds = static_cast<std::string::size_type>(0);
            for (auto& dir : directories_) {
                ds += dir.size();
            }
            return fs + ds;
        }

        bool file_exist(const std::string& name) const noexcept {
            for (auto& f : files_) {
                if (f == name) {
                    return true;
                }
            }
            return false;
        }

        bool directory_exist(const std::string& name) const noexcept {
            for (auto& dir : directories_) {
                if (dir == name) {
                    return true;
                }
            }
            return false;
        }

        bool exist(const std::string& name) const noexcept {
            return file_exist(name) || directory_exist(name); 
        }

        bool create_file(std::string name) noexcept {
            if (!file_exist(name) && !directory_exist(name)) {
                files_.push_back(std::move(name));
                return true;
            }
            return false;
        }

        bool create_directory(std::string name) noexcept {
            if (!directory_exist(name) && !file_exist(name)) {
                directories_.push_back(std::move(name));
                return true;
            }
            return false;
        }

        bool remove_file(const std::string& name) noexcept {
            auto it = std::find_if(files_.cbegin(), files_.cend(),
                [&name](const file& f) noexcept {
                    return f == name;
                });
            if (it != files_.cend()) {
                files_.erase(it);
            }
            return false;
        }

        bool remove_directory(const std::string& name) noexcept {
            auto it = std::find_if(directories_.cbegin(), directories_.cend(),
                [&name](const directory& dir) noexcept {
                    return dir == name;
                });
            if (it != directories_.cend()) {
                directories_.erase(it);
            }
            return false;
        }

        bool remove(const std::string& name) {
            return remove_file(name) || remove_directory(name);
        }

        const file& get_file(const std::string& name) const {
            for (auto& f : files_) {
                if (f == name) {
                    return f;
                }
            }
            throw std::out_of_range("Directory does not contain file " + name);
        }

        file& get_file(const std::string& name) {
            return const_cast<file&>(get_file(name));
        }

        const directory& get_directory(const std::string& name) const {
            for (auto& dir : directories_) {
                if (dir == name) {
                    return dir;
                }
            }
            throw std::out_of_range("Directory does not contain sub-directory " + name);
        }

        directory& get_directory(const std::string& name) {
            return const_cast<directory&>(get_directory(name));
        }

        const entry& at(const std::string& name) const;

        entry& at(const std::string& name) {
            return const_cast<entry&>(at(name));
        }

        const entry& operator[](const std::string& name) const {
            return at(name);
        }
 
        entry& operator[](const std::string& name) {
            return at(name);
        }
   private:
        std::string name_;
        std::vector<file> files_;
        std::vector<directory> directories_;
    };
}

#endif
