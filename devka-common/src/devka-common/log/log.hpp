//
// Created by molumn on 22. 7. 2.
//

#ifndef DEVKA_LOG_HPP
#define DEVKA_LOG_HPP

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

#include <devka-common/utils/macro.hpp>

namespace dvk {

    enum class LogLevel : int {
        TRACE = SPDLOG_LEVEL_TRACE,
        DEBUG = SPDLOG_LEVEL_DEBUG,
        INFO = SPDLOG_LEVEL_INFO,
        WARNING = SPDLOG_LEVEL_WARN,
        ERROR = SPDLOG_LEVEL_ERROR,
        CRITICAL = SPDLOG_LEVEL_CRITICAL
    };

    /* static */ class Log {
    public:
        static void create_logger(const std::string& name, int code, LogLevel level);
        static Ref<spdlog::logger>& get_logger(int code);
    private:
        static std::unordered_map<int, Ref<spdlog::logger>> i_loggers;
    };


} // dvk

#endif //DEVKA_LOG_HPP
