//
// Created by molumn on 22. 7. 4.
//
#include <devka-common/pch.hpp>

#include "mouse_event.hpp"

namespace dvk::graphics {

    std::string MouseEvent::toString() const {
        std::stringstream ss;
        ss << "MouseEvent [mouse_code: " << mouse_code << "; modifiers: " << mods << "]";
        return ss.str();
    }

    std::string MouseClickEvent::toString() const {
        std::stringstream ss;
        ss << "MouseClickEvent [mouse_code: " << mouse_code << "; modifiers: " << mods << "]";
        return ss.str();
    }

    std::string MouseReleaseEvent::toString() const {
        std::stringstream ss;
        ss << "MouseReleaseEvent [mouse_code: " << mouse_code << "; modifiers: " << mods << "]";
        return ss.str();
    }

    std::string ScrollEvent::toString() const {
        std::stringstream ss;
        ss << "ScrollEvent [x_offset: " << x_offset << "; y_offset: " << y_offset << "]";
        return ss.str();
    }

    std::string MouseMoveEvent::toString() const {
        std::stringstream ss;
        ss << "MouseMoveEvent [x: " << x << "; y: " << y << "]";
        return ss.str();
    }

    std::string CursorEnterEvent::toString() const {
        std::stringstream ss;
        ss << "CursorEnterEvent [enter_code: " << entered << "]";
        return ss.str();
    }

}

#include "mouse_event.hpp"
