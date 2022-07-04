//
// Created by molumn on 22. 7. 4.
//
#include <devka-common/pch.hpp>

#include "window.hpp"

namespace dvk {

    Window::Window(const std::string &name, int32 width, int32 height, b1 vsync) {
        context = graphics::WindowContext::createContext(graphics::WindowContextInfo(name, width, height, vsync));
    }

    void Window::init() {
        context->init();
    }

    void Window::run() {
        context->run();
    }

    void Window::destroy() {
        context->destroy();
    }

    void Window::setEventCallback(const EventCallbackStdFn &event_callback) {
        context->updateEventCallbackFn(event_callback);
    }

    b1 Window::isRunning() const {
        return context->isRunning();
    }

    void Window::setRunning(b1 is_running) {
        context->setRunning(is_running);
    }


} // dvk