//
// Created by molumn on 22. 7. 2.
//

#ifndef DEVKA_FLOW_HPP
#define DEVKA_FLOW_HPP

#include <devka-common/log/log.hpp>


#ifdef DK_DEBUG
#
#   define DK_CREATE_LOGGER(code, name, level)      ::dvk::Log::create_logger(name, code, level)
#
#
#
#   define  DK_LOG_TRACE(code, ...)         ::dvk::Log::get_logger(code)->trace(__VA_ARGS__)
#   define  DK_LOG_INFO(code, ...)          ::dvk::Log::get_logger(code)->info(__VA_ARGS__)
#   define  DK_LOG_WARN(code, ...)          ::dvk::Log::get_logger(code)->warning(__VA_ARGS__)
#   define  DK_LOG_ERROR(code, ...)         ::dvk::Log::get_logger(code)->error(__VA_ARGS__)
#   define  DK_LOG_FATAL(code, ...)         ::dvk::Log::get_logger(code)->critical(__VA_ARGS__)
#   define  DK_LOG_DEBUG(code, ...)         ::dvk::Log::get_logger(code)->debug(__VA_ARGS__)
#
/**
 * additional format parameter :
 *      n + 1 : filename
 *      n + 2 : line number
 */
#   define DK_ASSERT(should_be_true, code, ...)   if ( !(should_be_true) ) { DK_LOG_FATAL(code, __VA_ARGS__, std::filesystem::path(__FILE__).filename().string(), __LINE__) }
#
#else
#
#   define DK_CREATE_LOGGER(code, name, level)      ::dvk::Log::create_logger(name, code, level)
#
#   define  DK_LOG_TRACE(code, ...)
#   define  DK_LOG_INFO(code, ...)
#   define  DK_LOG_WARN(code, ...)
#   define  DK_LOG_ERROR(code, ...)
#   define  DK_LOG_FATAL(code, ...)
#   define  DK_LOG_DEBUG(code, ...)
#
/**
 * additional format parameter :
 *      n + 1 : filename
 *      n + 2 : line number
 */
#   define DK_ASSERT()
#
#endif


#endif //DEVKA_FLOW_HPP
