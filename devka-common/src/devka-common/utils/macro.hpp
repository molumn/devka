//
// Created by molumn on 22. 7. 2.
//

#ifndef DEVKA_MACRO_HPP
#define DEVKA_MACRO_HPP

#include <memory>

#define BIT(x)  1 << x
#define POW2(x) 1 << x

#define SEPARATE_VA_ARGS(args)    std::forward<decltype(args)>(args)...

#define BIND_CLAZZ_FN(fn) [this](auto&&.. args) -> decltype(auto) { return this->fn(SEPARATE_VA_ARGS(args)); }

namespace dvk {

    template<typename T>
    using Scope = std::unique_ptr<T>;
    template<typename T, typename ... Args>
    constexpr Scope<T> createScope(Args&& ... args) {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    template<typename T>
    using Ref = std::shared_ptr<T>;
    template<typename T, typename ... Args>
    constexpr Ref<T> createRef(Args&& ... args) {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }

}


#endif //DEVKA_MACRO_HPP
