#include "path.hpp"
using namespace npnc;

#include <cstdlib>
#include <stdexcept>

path::path(const char* text) {
    enum class parse_status {
        start,
        root,
        element,
        delim
    };
    auto status = parse_status::start;
    
    for (std::size_t i = 0; text[i] != '\0'; ++i) {
        switch (status) {
        case parse_status::start:
            if (text[i] == '/') {
                status = parse_status::root;
                elements_.push_back("/");
            } else {
                status = parse_status::element;
                elements_.emplace_back(1, text[i]);
            }
            break;
        case parse_status::root:
            status = parse_status::element;
            elements_.emplace_back(1, text[i]);
            break;
        case parse_status::element:
            if (text[i] == '/') {
                status = parse_status::delim;
            } else {
                elements_.back().push_back(text[i]);
            }
            break;
        case parse_status::delim:
            if (text[i] != '/') {
                status = parse_status::element;
                elements_.emplace_back(1, text[i]);
            }
            break;
        default:
            throw std::invalid_argument("Invalid path");
        }
    } 
}
