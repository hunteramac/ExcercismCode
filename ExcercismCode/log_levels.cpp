//https://exercism.org/tracks/cpp/exercises/log-levels

#include <string>

namespace log_line {
    const std::string LOG_LEVEL_LINE_DELIMITER_START = "[";
    const std::string LOG_LEVEL_LINE_DELIMITER_END = "]: ";

    std::string message(std::string line) {
        // return the message
        int Index_MessageStart = line.find(LOG_LEVEL_LINE_DELIMITER_END)+LOG_LEVEL_LINE_DELIMITER_END.size();
        return line.substr(Index_MessageStart, std::string::npos);
    }

    std::string log_level(std::string line) {
        // return the log level
        int Index_LogLevelStart = line.find(LOG_LEVEL_LINE_DELIMITER_START)+1;
        int Index_LogLevelEnd = line.find(LOG_LEVEL_LINE_DELIMITER_END)-1;
        return line.substr(Index_LogLevelStart,Index_LogLevelEnd);
    }

    std::string reformat(std::string line) {
        // return the reformatted message
        return "";
    }
}
