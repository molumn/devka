//
// Created by molumn on 22. 7. 2.
//

#ifndef DEVKA_FLOW_HPP
#define DEVKA_FLOW_HPP

#include <devka-common/log/log.hpp>


#define     DK_CORE_LOG_CODE        0x00
#define     DK_CLIENT_LOG_CODE      0x01
#define     DK_UTIL_LOG_CODE        0x02
#define     DK_PHYSICS_LOG_CODE     0x03
#define     DK_GRAPHIC_LOG_CODE     0x04
#define     DK_ENGINE_LOG_CODE      0x05


#define     DK_GAME_LOG_CODE                0x06
#define     DK_GAME_SERVER_LOG_CODE         0x07
#define     DK_GAME_CLIENT_LOG_CODE         0x08


#define     DK_RUNTIME_LOG_CODE     0x10


#ifdef DK_DEBUG
#
#   define DK_CREATE_LOGGER(name, code, level)      ::dvk::Log::create_logger(name, code, level)
#
#
#
#   define  DK_LOG_TRACE(code, ...)         ::dvk::Log::get_logger(code)->trace(__VA_ARGS__)
#   define  DK_LOG_INFO(code, ...)          ::dvk::Log::get_logger(code)->info(__VA_ARGS__)
#   define  DK_LOG_WARN(code, ...)          ::dvk::Log::get_logger(code)->warn(__VA_ARGS__)
#   define  DK_LOG_ERROR(code, ...)         ::dvk::Log::get_logger(code)->error(__VA_ARGS__)
#   define  DK_LOG_FATAL(code, ...)         ::dvk::Log::get_logger(code)->critical(__VA_ARGS__)
#   define  DK_LOG_DEBUG(code, ...)         ::dvk::Log::get_logger(code)->debug(__VA_ARGS__)
#
#
#
/**
 * additional format parameter :
 *      n + 1 : filename
 *      n + 2 : line number
 */
#   include <filesystem>
#   define DK_ASSERT(should_be_true, code, ...)   if ( !(should_be_true) ) { DK_LOG_FATAL(code, __VA_ARGS__, std::filesystem::path(__FILE__).filename().string(), __LINE__); }
#
#else
#
#   define DK_CREATE_LOGGER(code, name, level)
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
#   define DK_ASSERT(should_be_true, code, ...)
#
#endif


#endif //DEVKA_FLOW_HPP
