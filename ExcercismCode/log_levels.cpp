//https://exercism.org/tracks/cpp/exercises/log-levels

#include <string>

namespace log_line {
    std::string message(std::string line) {
        // return the message
        const std::string LINE_DELIMITER = "]: ";
        int Index_MessageStart = line.find(LINE_DELIMITER)+LINE_DELIMITER.size();
        return line.substr(Index_MessageStart, std::string::npos);
    }

    std::string log_level(std::string line) {
        // return the log level
        return "";
    }

    std::string reformat(std::string line) {
        // return the reformatted message
        return "";
    }
}
