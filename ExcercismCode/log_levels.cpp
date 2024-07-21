//https://exercism.org/tracks/cpp/exercises/log-levels

#include <string>

namespace log_line {
    // A log line is of format
    //[<LEVEL>]: <MESSAGE>
    // Where <LEVEL> can be one of three values
    //INFO
    //WARNING
    //ERROR
    const std::string LOG_LEVEL_LINE_DELIMITER_START = "[";
    const std::string LOG_LEVEL_LINE_DELIMITER_END = "]: ";

    /// <summary>
    /// Returns the message of a log line
    /// </summary>
    /// <param name="line"></param>
    /// <returns></returns>
    std::string message(std::string line) {
        // return the message
        int Index_MessageStart = line.find(LOG_LEVEL_LINE_DELIMITER_END)+LOG_LEVEL_LINE_DELIMITER_END.size();
        return line.substr(Index_MessageStart, std::string::npos);
    }

    /// <summary>
    /// Returns a log line's log level in upper case
    /// </summary>
    /// <param name="line"></param>
    /// <returns></returns>
    std::string log_level(std::string line) {
        // return the log level
        int Index_LogLevelStart = line.find(LOG_LEVEL_LINE_DELIMITER_START)+1;
        int Index_LogLevelEnd = line.find(LOG_LEVEL_LINE_DELIMITER_END)-1;
        return line.substr(Index_LogLevelStart,Index_LogLevelEnd);
    }

    /// <summary>
    /// Reformats the log line, putting the message first and the log level after it in parentheses
    /// </summary>
    /// <param name="line">Log line to proccess</param> 
    /// <returns>A string containing logs message, then the log level in parentheses</returns> 
    std::string reformat(std::string line) {
        // return the reformatted message
        return message(line) + " (" + log_level(line) + ")";
    }
}
