//
// Created by molumn on 22. 7. 4.
//
#include <devka-common/pch.hpp>

#include "key_event.hpp"

namespace dvk::graphics {

    std::string KeyEvent::toString() const {
        std::stringstream ss;
        ss << "KeyEvent [keycode: " << keycode << "; modifiers: " << mods << "]";
        return ss.str();
    }

    std::string KeyPressEvent::toString() const {
        std::stringstream ss;
        ss << "KeyPressEvent [keycode: " << keycode << "; modifiers: " << mods << "; repeat: " << repeat <<  "]";
        return ss.str();
    }

    std::string KeyReleaseEvent::toString() const {
        std::stringstream ss;
        ss << "KeyReleaseEvent [keycode: " << keycode << "; modifiers: " << mods << "]";
        return ss.str();
    }

    std::string CharModsEvent::toString() const {
        std::stringstream ss;
        ss << "KeyReleaseEvent [codepoint: " << character << "; modifiers: " << mods << "]";
        return ss.str();
    }



}
