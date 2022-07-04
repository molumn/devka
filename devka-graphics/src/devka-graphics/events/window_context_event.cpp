//
// Created by molumn on 22. 7. 4.
//
#include <devka-common/pch.hpp>

#include "window_context_event.hpp"

namespace dvk::graphics {

    std::string WindowContextEvent::toString() const {
        std::stringstream ss;
        ss << "WindowContextEvent [window_context: " << (int64)window_context << "]";
        return ss.str();
    }

    std::string WindowContextLoadEvent::toString() const {
        std::stringstream ss;
        ss << "WindowContextLoadEvent [window_context: " << (int64)window_context << "]";
        return ss.str();
    }

    std::string WindowContextStartEvent::toString() const {
        std::stringstream ss;
        ss << "WindowContextStartEvent [window_context: " << (int64)window_context << "]";
        return ss.str();
    }

    std::string WindowContextPreRunEvent::toString() const {
        std::stringstream ss;
        ss << "WindowContextPreRuntEvent [window_context: " << (int64)window_context << "]";
        return ss.str();
    }

    std::string WindowContextPostRunEvent::toString() const {
        std::stringstream ss;
        ss << "WindowContextPostRuntEvent [window_context: " << (int64)window_context << "]";
        return ss.str();
    }

    std::string WindowContextCloseEvent::toString() const {
        std::stringstream ss;
        ss << "WindowContextCloseEvent [window_context: " << (int64)window_context << "]";
        return ss.str();
    }

    std::string WindowContextMoveEvent::toString() const {
        std::stringstream ss;
        ss << "WindowContextMoveEvent [window_context: " << (int64)window_context << "; x: " << x << "; y:" << y << "]";
        return ss.str();
    }

    std::string WindowContextFocusEvent::toString() const {
        std::stringstream ss;
        ss << "WindowContextFocusEvent [window_context: " << (int64)window_context << "; focus: " << focus << "]";
        return ss.str();
    }

    std::string WindowContextResizeEvent::toString() const {
        std::stringstream ss;
        ss << "WindowContextResizeEvent [window_context: " << (int64)window_context << "; width: " << width << "; height:" << height << "]";
        return ss.str();
    }


}
