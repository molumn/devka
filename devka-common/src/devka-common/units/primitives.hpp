//
// Created by molumn on 22. 7. 2.
//

#ifndef DEVKA_PRIMITIVES_HPP
#define DEVKA_PRIMITIVES_HPP

#include <cstring>
#include <functional>

#include <devka-common/utils/preset.hpp>

#define     b1          bool

#define     int8        signed char
#define     int16       signed short
#define     int32       signed int
#define     int64       signed long long

#define     uint8       unsigned char
#define     uint16      unsigned short
#define     uint32      unsigned int
#define     uint64      unsigned long long

#define     f32         float
#define     f64         double


namespace dvk {

    template<typename Output, typename ... Args>
    using Fn = std::function<Output(Args...)>;

    template<typename T>
    class LazyVal {
    public:
        LazyVal(T _default) : lazy(true) {
            content = (T*)calloc(1, sizeof(T));
            *content = _default;
        }
        LazyVal() : content((T*)calloc(1, sizeof(T))), lazy(true) {}

        virtual ~LazyVal() = default;


        operator const T() const {
            if(lazy) DK_DEBUG_BREAK();  // lazyVal is null or didn't initialize content
            return *content;
        }

        operator T() {
            if(lazy) DK_DEBUG_BREAK();  // lazyVal is null or didn't initialize content
            return *content;
        }

        const T get() const {
            if(lazy) DK_DEBUG_BREAK();  // lazyVal is null or didn't initialize content
            return *content;
        }

        void set(T value) {
            if(lazy) {
                *content = value;
                lazy = false;
            } else {
                DK_DEBUG_BREAK();       // lazyVal cannot set twice (no change will happen in release mode)
            }
        }

    private:
        bool lazy;
        T* content;
    };

    template<typename T>
    using lazy = LazyVal<T>;


    template<typename T>
    class Nullable {
    public:
        Nullable() : variable((T*)calloc(1, sizeof(T))), _null(true) {}
        Nullable(T variable) : variable((T*)calloc(1, sizeof(T))), _null(false) {
            set(variable);
        }

        virtual ~Nullable() = default;


        void null() {
            memset(variable, 0, sizeof(T));
            _null = true;
        }

        void set(T value) {
            *variable = value;
            _null = false;
        }

        operator const T() const {
            if(_null) DK_DEBUG_BREAK();         // value is null!!
            return *variable;
        }

        operator T() {
            if(_null) DK_DEBUG_BREAK();         // value is null!!
            return *variable;
        }

        const T get() const {
            if(_null) DK_DEBUG_BREAK();         // value is null!!
            return *variable;
        }

        T get() {
            if(_null) DK_DEBUG_BREAK();         // value is null!!
            return *variable;
        }

    private:
        bool _null;
        T* variable;
    };

    template<typename T>
    using nullable = Nullable<T>;


    /**
     * @tparam SIZE size of flags
     */
    template<int SIZE>
    class BoolFlags {
    public:
        BoolFlags(bool _default = false) {
            flags = (bool[])calloc(SIZE, sizeof(bool));
            memset(flags, (int)_default, SIZE * sizeof(bool));
        }
        BoolFlags(bool* value_ptr) {
            flags = (bool[])calloc(SIZE, sizeof(bool));
            memcpy(flags, value_ptr, SIZE * sizeof(bool));
        }

        virtual ~BoolFlags() = default;

        operator bool() {
            for(int i = 0; i < SIZE; i++) if(flags[i]) return true;
            return false;
        }

        bool operator&(BoolFlags<SIZE> other) {
            for(int i = 0; i < SIZE; i++) if(flags[i] && flags[i] == other.flags[i]) return true;
            return false;
        }

        bool operator|(BoolFlags<SIZE> other) {
            for(int i = 0; i < SIZE; i++) if(flags[i] || other.flags[i]) return true;
            return false;
        }

        bool get(int i) {
            return flags[i];
        }

        void set(int i, bool value) {
            flags[i] = value;
        }

        BoolFlags<SIZE> operator&&(BoolFlags<SIZE> other) {
            bool content[SIZE] = (bool[])calloc(SIZE, sizeof(bool));
            for(int i = 0; i < SIZE; i++) {
                content[i] = flags[i] && other.flags[i];
            }
            return content;
        }

        BoolFlags<SIZE> operator||(BoolFlags<SIZE> other) {
            bool content[SIZE] = (bool[])calloc(SIZE, sizeof(bool));
            for(int i = 0; i < SIZE; i++) {
                content[i] = flags[i] || other.flags[i];
            }
            return content;
        }

        void operator&=(BoolFlags<SIZE> other) {
            for(int i = 0; i < SIZE; i++) {
                flags[i] &= other.flags[i];
            }
        }

        void operator|=(BoolFlags<SIZE> other) {
            for(int i = 0; i < SIZE; i++) {
                flags[i] |= other.flags[i];
            }
        }

    private:
        bool    flags[SIZE];
    };

    template<int SIZE>
    using bools = BoolFlags<SIZE>;



#define     b8      bools<8>
#define     b16     bools<16>
#define     b32     bools<32>
#define     b64     bools<64>



}


#endif //DEVKA_PRIMITIVES_HPP
