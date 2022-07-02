//
// Created by molumn on 22. 7. 2.
//

#include <devka-common/pch.hpp>

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <iomanip>

#include "log.hpp"

namespace dvk {

    std::unordered_map<int, Ref<spdlog::logger>> Log::i_loggers;

    void Log::create_logger(const std::string &name, int code, LogLevel level) {

        std::stringstream ss;

        auto time = std::time(nullptr);
        auto localtime = *std::localtime(&time);
        auto put_time = std::put_time(&localtime, "%Y:%m:%d---%H:%M:%S");

        ss << put_time;
        std::string time_string = ss.str();

        std::vector<spdlog::sink_ptr> sinks;
        sinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
        sinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>(name + ".log", true));
        sinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("STORE-" + time_string + ".log", true));

        sinks[0]->set_pattern("%^[%T] %n : %v%$");
        sinks[1]->set_pattern("[%T] [%l] %n : %v");
        sinks[2]->set_pattern("[%T] [%x - %l] %n : %v");

        i_loggers[code] = std::make_shared<spdlog::logger>(name, begin(sinks), end(sinks));
        auto& logger_ref = i_loggers[code];
        spdlog::register_logger(logger_ref);
        logger_ref->set_level((spdlog::level::level_enum)level);
        logger_ref->flush_on((spdlog::level::level_enum)level);

    }

    Ref<spdlog::logger> &Log::get_logger(int code) {
        return i_loggers[code];
    }


} // dvk