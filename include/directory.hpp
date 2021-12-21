#ifndef NPNC_DIRECTORY_HPP
#define NPNC_DIRECTORY_HPP

#include <cstdlib>
#include <stdexcept>
#include <map>
#include <memory>
#include <utility>

#include "entry.hpp"
#include "file.hpp"

namespace npnc {
    class directory : public entry {
        using entries_type = std::map<std::string, std::unique_ptr<entry>>;
    public:
        using size_type = entries_type::size_type;
        
        class iterator {
            friend class directory;
            
            iterator(entries_type::iterator it)
                : iterator_(it)
            {
                
            }
        public:
            iterator& operator++() noexcept {
                ++iterator_;
                return *this;
            }

            std::pair<const std::string, entry&> operator*() const noexcept {
                auto& res = *iterator_;
                return {res.first, *res.second};
            }

            friend bool operator!=(iterator lhs, iterator rhs) noexcept {
                return lhs.iterator_ != rhs.iterator_;
            }
        private:
            entries_type::iterator iterator_;
        };
        
        class const_iterator {
            friend class directory;

            const_iterator(entries_type::const_iterator it)
                : iterator_(it)
            {
            
            }
        public:
            const_iterator& operator++() noexcept {
                ++iterator_;
                return *this;
            }

            std::pair<const std::string, const entry&> operator*() const noexcept {
                auto& res = *iterator_;
                return {res.first, *res.second};
            }

            friend bool operator!=(const_iterator lhs, const_iterator rhs) noexcept {
                return lhs.iterator_ != rhs.iterator_;
            }
        private:
            entries_type::const_iterator iterator_;
        };

        bool is_directory() const noexcept override {
            return true;
        }

        std::string::size_type space() const noexcept override {
            auto res = static_cast<std::size_t>(0);
            for (auto& e : entries_) {
                res += e.second->space();
            }
            return res;
        }

        bool exist(const std::string& name) const noexcept {
            return entries_.find(name) != entries_.cend(); 
        }

        bool create_file(std::string name) noexcept {
            return entries_.insert({std::move(name), std::make_unique<file>()}).second;
        }

        bool create_directory(std::string name) noexcept {
            return entries_.insert({std::move(name), std::make_unique<directory>()}).second;
        }

        bool remove(const std::string& name) {
            auto it = entries_.find(name);
            if (it != entries_.cend()) {
                entries_.erase(it);
                return true;
            }
            return false;
        }

        const entry& at(const std::string& name) const {
            auto it = entries_.find(name);
            if (it != entries_.cend()) {
                return *it->second;
            }
            throw std::out_of_range("Directory does not contain entry " + name + "!");
        }

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
            return entries_.size();
        }

        iterator begin() noexcept {
            return entries_.begin();
        }

        iterator end() noexcept {
            return entries_.end();
        }

        const_iterator begin() const noexcept {
            return entries_.begin();
        }

        const_iterator end() const noexcept {
            return entries_.end();
        }

        const_iterator cbegin() const noexcept {
            return entries_.begin();
        }

        const_iterator cend() const noexcept {
            return entries_.end();
        }
    private:
        entries_type entries_;
    };
}

#endif
