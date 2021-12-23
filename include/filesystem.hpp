#ifndef NPNC_FILESYSTEM_HPP
#define NPNC_FILESYSTEM_HPP

#include "directory.hpp"
#include "path.hpp"

namespace npnc {
    class filesystem {
    public:
        filesystem() {
            current_directory_ = &root_;
        }

        const directory& current_directory() const noexcept {
            return *current_directory_;
        }

        const path& current_path() const noexcept {
            return current_path_;
        }

        void change_directory(path p);

        const directory& root() const noexcept {
            return root_;
        }

        const entry& at(path p) const; 

        entry& at(const path& p) {
            return const_cast<entry&>(static_cast<const filesystem*>(this)->at(p));
        }

        const entry& operator[](const path& p) const {
            return at(p);
        }

        entry& operator[](const path& p) {
            return at(p);
        }

        bool exist(path p) const noexcept; 
        bool create_file(path p); 
        bool create_directory(path p);
    private:    
        const directory* current_directory_;
        path current_path_;
        directory root_;
    };
}

#endif
