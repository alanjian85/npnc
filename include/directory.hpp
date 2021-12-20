#ifndef NPNC_DIRECTORY_HPP
#define NPNC_DIRECTORY_HPP

#include <algorithm>
#include <cstdlib>
#include <functional>
#include <stdexcept>
#include <vector>
#include <numeric>

#include "entry.hpp"
#include "file.hpp"

namespace npnc {
    class directory : public entry {
    public:
        using size_type = std::size_t;
        
        class iterator {
            friend class directory;
        
            iterator(directory& dir, std::size_t index)
                : directory_(dir),
                  index_(index)
            {
                
            }
        public:
            entry& operator*() const noexcept {
                if (index_ < directory_.files_.size()) {
                    return directory_.files_[index_];
                } else {
                    return directory_.directories_[index_ - directory_.files_.size()];
                }
            }

            iterator& operator++() noexcept {
                ++index_;
                return *this;
            }

            friend inline bool operator!=(iterator lhs, iterator rhs) noexcept {
                return &lhs.directory_ != &rhs.directory_ || lhs.index_ != rhs.index_;
            }
        private:
            directory& directory_;
            std::size_t index_;
        };

        class const_iterator {
            friend class directory;

            const_iterator(const directory& dir, std::size_t index)
                : directory_(dir),
                  index_(index)
            {
            
            }
        public:
            const entry& operator*() const noexcept {
                if (index_ < directory_.files_.size()) {
                    return directory_.files_[index_];
                } else {
                    return directory_.directories_[index_ - directory_.files_.size()];
                }
            }

            const_iterator& operator++() noexcept {
                ++index_;
                return *this;
            }

            const_iterator operator++(int) noexcept {
                auto it = *this;
                ++index_;
                return it;
            }

            friend inline bool operator!=(const_iterator lhs, const_iterator rhs) noexcept {
                return &lhs.directory_ != &rhs.directory_ || lhs.index_ != rhs.index_;
            }
       private:
            const directory& directory_;
            std::size_t index_;
        };

        using entry::entry;

        bool is_directory() const noexcept override {
            return true;
        }

        std::string::size_type space() const noexcept {
            auto res = static_cast<std::string::size_type>(0);
            for (auto& f : files_) {
                res += f.space();
            }
            for (auto& dir : directories_) {
                res += dir.space();
            }
            return res;
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
            return const_cast<file&>(static_cast<const directory*>(this)->get_file(name));
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
            return const_cast<directory&>(static_cast<const directory*>(this)->get_directory(name));
        }

        const entry& at(const std::string& name) const;

        entry& at(const std::string& name) {
            return const_cast<entry&>(static_cast<const directory*>(this)->at(name));
        }

        const entry& operator[](const std::string& name) const {
            return at(name);
        }
 
        entry& operator[](const std::string& name) {
            return at(name);
        }

        size_type size() const noexcept {
            return files_.size() + directories_.size();
        }

        iterator begin() noexcept {
            return {*this, 0};
        }

        const_iterator begin() const noexcept {
            return {*this, 0};
        }

        iterator end() noexcept {
            return {*this, files_.size() + directories_.size()};
        }

        const_iterator end() const noexcept {
            return {*this, files_.size() + directories_.size()};
        }

        const_iterator cbegin() const noexcept {
            return begin();
        }

        const_iterator cend() const noexcept {
            return end();
        }
    private:
        std::string name_;
        std::vector<file> files_;
        std::vector<directory> directories_;
    };
}

#endif
