#include "execution.hpp"
using namespace npnc;

execution::execution(const std::string& str) {
    enum class parse_status {
        command,
        argument,
        delim
    };
    auto status = parse_status::command;

    for (auto c : str) {
        switch (status) {
        case parse_status::command:
            if (c == ' ') {
                status = parse_status::delim;
            } else {
                cmd.push_back(c);
            }
            break;
        case parse_status::argument:
            if (c == ' ') {
                status = parse_status::delim;
            } else {
                args.back().push_back(c);
            }
            break;
        case parse_status::delim:
            if (c != '/') {
                status = parse_status::argument;
                args.emplace_back(1, c);
            }
            break;
        }
    }
}
