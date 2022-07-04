//
// Created by molumn on 22. 7. 2.
//

#ifndef DEVKA_PRESET_HPP
#define DEVKA_PRESET_HPP


#ifdef DK_DEBUG
#   if defined(DK_PLATFORM_WINDOWS)
#       define  DK_DEBUG_BREAK()     __debugbreak()
#   elif defined(DK_PLATFORM_LINUX)
#       include <signal.h>
#       define  DK_DEBUG_BREAK()     raise(SIGTRAP)
#   else
#       define  DK_DEBUG_BREAK()
#   endif
#
#   define  DK_ENABLE_ASSERTS true
#else
#   define  DK_ENABLE_ASSERTS false
#   define  DK_DEBUG_BREAK()
#endif


#endif //DEVKA_PRESET_HPP
