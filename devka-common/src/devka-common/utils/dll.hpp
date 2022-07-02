//
// Created by molumn on 22. 7. 2.
//

#ifndef DEVKA_DLL_HPP
#define DEVKA_DLL_HPP

#ifdef DK_DLL
#   if defined(_MSC_VER)
#       define DK_API __declspec(dllexport)
#   elif defined(__GNUC__)
#       define DK_API __attribute__((visibility("default")))
#   else
#       error "unknown or unsupported c++ dialect"
#   endif
#else
#   if defined(_MSC_VER)
#       define DK_API __declspec(dllImport)
#   elif defined(__GNUC__)
#       define DK_API
#   else
#       error "unknown or unsupported c++ dialect"
#   endif
#endif

#endif //DEVKA_DLL_HPP
